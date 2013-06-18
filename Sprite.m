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
axis equal
axis off


bg=imread('resources\Sprites\Background.jpg');
% bg=imread('resources\bg.png');
% bg=imresize(bg, 0.5);
bcg=imshow(bg); hold on
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
%% Fruit generation

[fr.spr.apple map fr.spr.applealpha] = imread('resources\Sprites\apple uncut.png');
[fr.spr.apple1 map fr.spr.apple1alpha] = imread('resources\Sprites\apple cut 1.png');
[fr.spr.apple2 map fr.spr.apple2alpha] = imread('resources\Sprites\apple cut 2.png');

[fr.spr.banana map fr.spr.bananaalpha] = imread('resources\Sprites\banana uncut.png');
[fr.spr.banana1 map fr.spr.banana1alpha] = imread('resources\Sprites\banana cut 1.png');
[fr.spr.banana2 map fr.spr.banana2alpha] = imread('resources\Sprites\banana cut 2.png');

[fr.spr.watermelon map fr.spr.watermelonalpha] = imread('resources\Sprites\watermelon uncut.png');
[fr.spr.watermelon1 map fr.spr.watermelon1alpha] = imread('resources\Sprites\watermelon cut 1.png');
[fr.spr.watermelon2 map fr.spr.watermelon2alpha] = imread('resources\Sprites\watermelon cut 2.png');

[fr.spr.bomb map fr.spr.bombalpha] = imread('resources\Sprites\bomb.png');


%% Throwing motion
score=10;
dt=0.01;
over=0;
maxfruit=5;
gameover=0;


mX=[];
mY=[];

while ~gameover %Main loop
    title(['Score: ' num2str(score)]);
    
    [start side] = startposition();
    [fr fruit alpha] = fruitgenerator2(fr,start);
    [fr] = Motiongenerator(side,fr);
    
    multiplier=4*rand;
    while 1 %Motion loop
        fr.speed=fr.speed + fr.accel.*dt;
        fr.speedcomp=[-multiplier.*fr.speed(1) fr.speed(2)+50];
        fr.positionc=fr.positionc + fr.speed.*dt;
        set(fruit,'Xdata',[fr.positionc(1) fr.positionc(1)+50],'Ydata',[fr.positionc(2) fr.positionc(2)+50],'AlphaData',alpha);
        mX=[mX mouseLoc(1,1)];
        mY=[mY mouseLoc(1,2)];
        set(p,'xdata',mX,'ydata',mY,'LineWidth',3);
        
        if length(mX)==15 %Draw trail
            mX=mX(2:end);
            mY=mY(2:end);
        end
        
        if over==1
            fr.speedcomp=fr.speedcomp + fr.accelcomp.*dt;
            fr.positionccomp=fr.positionc + fr.speedcomp.*dt;
            set(fruitcomp,'Xdata',[fr.positionc(1) fr.positionc(1)+50],'Ydata',[fr.positionc(2) fr.positionc(2)+50],'AlphaData',alpha2);
        end
        
        title(['Score: ' num2str(score)]);
        pause(dt);
        
        if norm([mouseLoc(1,1) mouseLoc(1,2)] -fr.positionc)<30 %Mouse detection
            while ~over
                [fr fruit fruitcomp alpha alpha2]=fruitcutter2(fr,fruit);
                score=score+1;
                over=1;
                if strcmp(fr.type,'bomb')
                    bombexplode(aw,ah)
                    score=score-11;
                end
            end
        end
        
        if fr.positionc(2)<=(ah(1)-40) %|| fr.positionc(2)<=(ah(2)-150)
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
                %                 set(fruitcomp,'Visible','off');
                delete(fruitcomp);
            end
            %             set(fruit,'Visible','off');
            delete(fruit);
            clear fruit
            over=0;
            break
        end
    end
end