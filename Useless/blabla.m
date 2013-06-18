
clear
close all
clc

figure
hold on
axis equal
axis([0 640 0 480])
start=[200 200];

fruit=rectangle('Position',[start 25 60],'Curvature',[1 0.8],'facecolor',[1 1 0.4])

% set(gca,'YDir','normal')
% 
% [fr.spr.apple map fr.spr.applealpha] = imread('resources\Sprites\apple uncut.png');
% [fr.spr.banana map fr.spr.bananaalpha] = imread('resources\Sprites\banana uncut.png');
% [fr.spr.watermelon map fr.spr.watermelonalpha] = imread('resources\Sprites\watermelon uncut.png');
% [fr.spr.bomb map fr.spr.bombalpha] = imread('resources\Sprites\bomb.png');
% 
% % fruit = imshow(fr.spr.apple);
% % imshow(apple);
% 
% [start side] = startposition();
% [fr fruit alpha] = fruitgenerator2(fr,start);
% [fr] = Motiongenerator(side,fr);
% 
% dt=0.01;
% % sp.positionc=start;
% while 1
%     fr.speed=fr.speed + fr.accel.*dt;
%     fr.positionc=fr.positionc + fr.speed.*dt;
% set(fruit,'Xdata',[fr.positionc(1) fr.positionc(1)+50],'Ydata',[fr.positionc(2) fr.positionc(2)+20],'AlphaData',alpha);
% pause(dt)
% end