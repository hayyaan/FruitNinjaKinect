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

% mousePos =[50 50];
% while 1
%     mousePos = [mousePos mouseLoc];
%     plot(mousePos)
% end
% track=line([0 10], [0 10]);
p=line(0,0);
axis off
%% Throwing motion
score=2;
dt=0.01;
over=0;
maxfruit=5;
gameover=0;

mX=[];
mY=[];
% a=[];

while ~gameover %Main loop
    %     title(['Score: ' num2str(score)]);
    
    [start side] = startposition();
    [fr fruit] = fruitgenerator(start);
    [fr] = Motiongenerator(side,fr);
    
    while 1 %Motion loop
        fr.speed=fr.speed + fr.accel.*dt;
        fr.speedcomp=[-fr.speed(1) fr.speed(2)+5];
        fr.positionc=fr.positionc + fr.speed.*dt;
        set(fruit,'Position',[fr.positionc fr.position(3:4)])
        
        mX=[mX mouseLoc(1,1)];
        mY=[mY mouseLoc(1,2)];
        set(p,'xdata',mX,'ydata',mY,'LineWidth',2.5,'Color',[0.9 0.9 0.9]);
        
        if length(mX)==15
            mX=mX(2:end);
            mY=mY(2:end);
        end
        %         draw=isempty(a); %% Plot command not working
        %                     if draw==0
        %                         drawline(a)
        %                     end
        if over==1
            fr.speedcomp=fr.speedcomp + fr.accelcomp.*dt;
            frcomp=get(fruitcomp,'Position');
            fr.positionccomp=[frcomp(1) frcomp(2)];
            fr.positionccomp=fr.positionccomp + fr.speedcomp.*dt;
            set(fruitcomp,'Position',[fr.positionccomp fr.position(3:4)])
        end
        title(['Score: ' num2str(score)]);
        
        
        if norm([mouseLoc(1,1) mouseLoc(1,2)] -fr.positionc)<30 %Mouse detection
            while ~over
                %                 set(fruit,'Visible','off');
                %                 delete(fruit);
                [fr fruit fruitcomp]=fruitcutter(fr,fruit);
                score=score+1;
                over=1;
                if strcmp(fr.type,'bomb')
                    bombexplode(aw,ah)
                    score=score-11;
                end
            end
        end
        pause(dt);
        
        if fr.positionc(2)<=(ah(1)-40) %|| fr.positionc(1)<=(aw(2)+40)
            if over==0
                if ~strcmp(fr.type,'bomb')
                    score=score-1;
                end
            end
            if score==0 || score<0
                title('Game Over');
                gameover=1;
                break
            end
            if over==1
                delete(fruitcomp);
                %                 set(fruitcomp,'Visible','off');
            end
            delete(fruit);
            clear fruit
            %             set(fruit,'Visible','off');
            over=0;
            break
        end
    end
end