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
score=100;
dt=0.01;
gameover=0;

mX=[];
mY=[];
% a=[];

maxfruits=15;
for i=1:maxfruits
    over{i}=0;
    regen(i)=0;
end
%% Kinect
addpath('Mex')
SAMPLE_XML_PATH='Config/SamplesConfig.xml';
KinectHandles=mxNiCreateContext(SAMPLE_XML_PATH);
Pos= mxNiSkeleton(KinectHandles);
lol=line(0,0);
lol2=line(0,0);
lol3=line(0,0);
lol4=line(0,0);

rhandx=[];
rhandy=[];
lhandx=[];
lhandy=[];
r2handx=[];
r2handy=[];
l2handx=[];
l2handy=[];

while(Pos(1)==0);
    mxNiUpdateContext(KinectHandles);
    Pos= mxNiSkeleton(KinectHandles);
end
%% Main loop
while ~gameover %Main loop
    
    %     title(['Score: ' num2str(score)]);
    %     numberfruits=randi(maxfruits);
    numberfruits=maxfruits;
    title(['Score: ' num2str(numberfruits)])
    for i=1:numberfruits;
        [start side] = startposition();
        [fr{i} fruit{i}] = fruitgenerator(start);
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
        mxNiUpdateContext(KinectHandles);
        Pos= mxNiSkeleton(KinectHandles,1);
        y=Pos(1:15,7);
        x=Pos(1:15,6);
        y2=Pos(16:30,7);
        x2=Pos(16:30,6);
        y=480-y;
        y2=480-y2;
        %
        %         mX=[mX mouseLoc(1,1)];
        %         mY=[mY mouseLoc(1,2)];
        %         set(p,'xdata',mX,'ydata',mY,'LineWidth',2,'Color',[0.9 0.9 0.9]);
        %
        %         if length(mX)==15
        %             mX=mX(2:end);
        %             mY=mY(2:end);
        %         end
        rhandx=[rhandx x(8)];
        rhandy=[rhandy y(8)];
        
        lhandx=[lhandx x(5)];
        lhandy=[lhandy y(5)];
        
        r2handx=[r2handx x2(8)];
        r2handy=[r2handy y2(8)];
        
        l2handx=[l2handx x2(5)];
        l2handy=[l2handy y2(5)];
        
        if length(rhandx)>10
            rhandx=rhandx(2:end);
            rhandy=rhandy(2:end);
            lhandx=lhandx(2:end);
            lhandy=lhandy(2:end);
        end
        
        if length(r2handx)>10
            r2handx=r2handx(2:end);
            r2handy=r2handy(2:end);
            l2handx=l2handx(2:end);
            l2handy=l2handy(2:end);
        end
        
        
        set(lol,'Xdata',rhandx,'Ydata',rhandy,'LineWidth',5,'Color',[0.9 0.9 0.9])
        set(lol2,'Xdata',lhandx,'Ydata',lhandy,'LineWidth',5,'Color',[0.9 0.9 0.9])
        set(lol3,'Xdata',r2handx,'Ydata',r2handy,'LineWidth',5,'Color','r')
        set(lol4,'Xdata',l2handx,'Ydata',l2handy,'LineWidth',5,'Color','r')
        
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
            %             if norm([mouseLoc(1,1) mouseLoc(1,2)] -fr{i}.positionc)<30 %Mouse detection
            if norm([x(8) y(8)] -fr{i}.positionc)<30 || norm([x(5) y(5)] -fr{i}.positionc)<30 || norm([x2(8) y2(8)] -fr{i}.positionc)<30 || norm([x2(5) y2(5)] -fr{i}.positionc)<30
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