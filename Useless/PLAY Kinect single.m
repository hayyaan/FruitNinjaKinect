%% Initializations
clear all
close all
clc

%% Background

figure
% figure('units','normalized','outerposition',[0 0 1 1])
% figure('Name','Display','NumberTitle','off','MenuBar','none','Units','normalized','Position',[0 0 1 1]);
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

%% Variables
score=100;
dt=0.01;
over=0;
maxfruit=5;
gameover=0;

mX=[];
mY=[];
% a=[];

[s1.y s1.fs]=wavread('resources\sabersound.wav');
aud1=audioplayer(s1.y,s1.fs);
[s2.y s2.fs]=wavread('resources\fruitvoice.wav');
aud2=audioplayer(s2.y,s2.fs);

%% Kinect
addpath('Mex')
SAMPLE_XML_PATH='Config/SamplesConfig.xml';
KinectHandles=mxNiCreateContext(SAMPLE_XML_PATH);
Pos= mxNiSkeleton(KinectHandles);
lol=line(0,0);
lol2=line(0,0);
rhandx=[];
rhandy=[];
lhandx=[];
lhandy=[];
while(Pos(1)==0);
    mxNiUpdateContext(KinectHandles);
    Pos= mxNiSkeleton(KinectHandles);
end


%% Main loop

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
        
        mxNiUpdateContext(KinectHandles);
        Pos= mxNiSkeleton(KinectHandles,1);
        y=Pos(1:15,7);
        x=Pos(1:15,6);
        y=480-y;
        
%         mX=[mX mouseLoc(1,1)];
%         mY=[mY mouseLoc(1,2)];
%         set(p,'xdata',mX,'ydata',mY,'LineWidth',2.5,'Color',[0.9 0.9 0.9]);
%         
%         if norm([mX(1) mY(1)]-[mX(end) mY(end)])>200
%             %             play(aud1)
%             % beep
%         end
%         
%         if length(mX)==15
%             mX=mX(2:end);
%             mY=mY(2:end);
%         end
%         
        rhandx=[rhandx x(8)];
        rhandy=[rhandy y(8)];
        
        lhandx=[lhandx x(5)];
        lhandy=[lhandy y(5)];
        
        if length(rhandx)>10
            rhandx=rhandx(2:end);
            rhandy=rhandy(2:end);
            lhandx=lhandx(2:end);
            lhandy=lhandy(2:end);
        end
        
        set(lol,'Xdata',rhandx,'Ydata',rhandy,'LineWidth',5,'Color',[0.9 0.9 0.9])
        set(lol2,'Xdata',lhandx,'Ydata',lhandy,'LineWidth',5,'Color',[0.9 0.9 0.9])
        
        if over==1
            fr.speedcomp=fr.speedcomp + fr.accelcomp.*dt;
            frcomp=get(fruitcomp,'Position');
            fr.positionccomp=[frcomp(1) frcomp(2)];
            fr.positionccomp=fr.positionccomp + fr.speedcomp.*dt;
            set(fruitcomp,'Position',[fr.positionccomp fr.position(3:4)])
        end
        title(['Score: ' num2str(score)]);
        
        
        %         if norm([mouseLoc(1,1) mouseLoc(1,2)] -fr.positionc)<30 %Mouse detection
        if norm([x(8) y(8)] -fr.positionc)<30 || norm([x(5) y(5)] -fr.positionc)<30
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