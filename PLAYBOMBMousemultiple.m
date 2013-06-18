%% Initializations
clear all
close all
clc

%% Background

figure
axis equal
aw=[0 640];
ah=[0 480];
axis([aw ah]) % CHANGE AXIS BACK TO 1k
% axis equal
% axis off


bg=imread('resources\Sprites\Background.png');
% bg=imresize(bg, 0.5);
bcg=image(bg);
% imshow('resources\bg.jpg')
set(gca,'YDir','normal')
% axis off

% Insert code for background picture here

%% Mouse tracking
mouseLoc = [200 200];
a=[];
set(gcf, 'WindowButtonMotionFcn', 'mouseLoc = get(gca, ''CurrentPoint'');');
% set(gcf, 'WindowButtonDownFcn', 'a = get(gca, ''CurrentPoint'');');

p=line(0,0);
axis off
%% Throwing motion
score=30;
dt=0.01;
gameover=0;

mX=[];
mY=[];
% a=[];

maxfruits=10;
for i=1:maxfruits
    over{i}=0;
    regen(i)=0;
end

while ~gameover %Main loop
    
    %     title(['Score: ' num2str(score)]);
    %     numberfruits=randi(maxfruits);
    numberfruits=maxfruits;
    title(['Score: ' num2str(numberfruits)])
    for i=1:numberfruits;
        [start side] = startposition();
        [fr{i} fruit{i}] = bombgenerator(start);
        [fr{i}] = Motiongenerator(side,fr{i});
    end
    while 1 %Motion loop
        for i=1:numberfruits;
            if regen(i)==1;
                [start side] = startposition();
                [fr{i} fruit{i}] = fruitgenerator(start);
                [fr{i}] = Motiongenerator(side,fr{i});
                regen(i)=0;
            end
        end
        
        
        for i=1:numberfruits;
            fr{i}.speed=fr{i}.speed + fr{i}.accel.*dt;
            fr{i}.speedcomp=[-fr{i}.speed(1) fr{i}.speed(2)+5];
            fr{i}.positionc=fr{i}.positionc + fr{i}.speed.*dt;
            set(fruit{i},'Position',[fr{i}.positionc fr{i}.position(3:4)])
        end
        pause(dt)
        
        mX=[mX mouseLoc(1,1)];
        mY=[mY mouseLoc(1,2)];
        set(p,'xdata',mX,'ydata',mY,'LineWidth',2,'Color',[0.9 0.9 0.9]);
        
        if length(mX)==15
            mX=mX(2:end);
            mY=mY(2:end);
        end
        
        title(['Score: ' num2str(score)]);
        
        
        for i=1:numberfruits
            if over{i}==1
                fr{i}.speedcomp=fr{i}.speedcomp + fr{i}.accelcomp.*dt;
                frcomp{i}=get(fruitcomp{i},'Position');
                fr{i}.positionccomp=[frcomp{i}(1) frcomp{i}(2)];
                fr{i}.positionccomp=fr{i}.positionccomp + fr{i}.speedcomp.*dt;
                set(fruitcomp{i},'Position',[fr{i}.positionccomp fr{i}.position(3:4)])
            end
        end
        for i=1:numberfruits
            if norm([mouseLoc(1,1) mouseLoc(1,2)] -fr{i}.positionc)<30 %Mouse detection
                while ~over{i}
                    %                 set(fruit,'Visible','off');
                    %                 delete(fruit);
                    [fr{i} fruit{i} fruitcomp{i}]=fruitcutter(fr{i},fruit{i});
                    score=score+1;
                    over{i}=1;
                    if strcmp(fr{i}.type,'bomb')
                        bombexplode(aw,ah)
                        score=score-11;
                    end
                end
            end
        end
        pause(dt);
        if gameover==1;
            title('Game Over');
            break
        end
        for i=1:numberfruits
            if fr{i}.positionc(2)<=(ah(1)-40) %|| fr.positionc(1)<=(aw(2)+40)
                if over{i}==0
                    if ~strcmp(fr{i}.type,'bomb')
                        score=score-1;
                    end
                end
                if score==0 || score<0
                    title('Game Over');
                    gameover=1;
%                     break
                end
                if over{i}==1
                    delete(fruitcomp{i});
                    clear fruitcomp{i}
                    %                 set(fruitcomp,'Visible','off');
                end
                delete(fruit{i});
                %                             set(fruit{i},'Visible','off');
                over{i}=0;
                clear fruit{i}
                regen(i)=1;
                %                 break
            end
        end
    end
end