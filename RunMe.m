clear all
close all
clc

figure
bg = imread('resources\title.jpg');
image(bg, 'xdata', [-120 120], 'ydata', [100 -100]); hold on
set(gca, 'visible', 'off', 'position', [0, 0, 1, 1], 'YDir','normal');

% text(-100,80, 'Shooting Range', 'color', 'k', 'fontsize', 45, 'fontname', 'jokerman');

text(70,-93,'© hYN', 'color', 'k', 'fontsize', 22, 'fontname', 'Eras Bold ITC');
text(-70,70,'Kinect', 'color', 'k', 'fontsize', 40, 'fontname', 'Aardvark Cafe');

%%
lev = uibuttongroup('Position',[.65 .5 .3 .3]);

txt = uicontrol(lev,'Style','text','String','Arcade mode','fontname', 'Rockwell Extra Bold',...
    'FontSize',20,'Units','normalized','Position',[.05 .75 .9 .2]);

k1 = uicontrol(lev,'Style','PushButton','String','Kinect 1Player','fontname', 'Rockwell Extra Bold',...
    'FontSize',10, 'Units','normalized', 'Position',[.05 .5 .9 .2],'Callback','PLAYKinectmultiple');
% set(e,'Callback', 'level=1');

k2 = uicontrol(lev,'Style','PushButton','String','Kinect 2Player','fontname', 'Rockwell Extra Bold',...
    'FontSize',10, 'Units','normalized', 'Position',[.05 .3 .9 .2],'Callback','PLAY2Kinectmultiple');
% set(m,'Callback', 'level=2');

m1 = uicontrol(lev,'Style','PushButton','String','Use mouse','fontname', 'Rockwell Extra Bold',...
    'FontSize',10, 'Units','normalized', 'Position',[.05 .1 .9 .2],'Callback','PLAYMousemultiple');
% set(h,'Callback', 'level=3');

other = uibuttongroup('Position',[.65 0.2 .3 .2]);

txt = uicontrol(lev,'Style','text','String','Avoid the bomb','fontname', 'Rockwell Extra Bold',...
    'FontSize',11,'Units','normalized','Position',[.05 -.6 .9 .2]);

a1 = uicontrol(lev,'Style','PushButton','String','Kinect','fontname', 'Rockwell Extra Bold',...
    'FontSize',10, 'Units','normalized', 'Position',[.05 -.75 .9 .2],'Callback','PLAYBOMBKinectmultiple');

a2 = uicontrol(lev,'Style','PushButton','String','Mouse','fontname', 'Rockwell Extra Bold',...
    'FontSize',10, 'Units','normalized', 'Position',[.05 -.95 .9 .2],'Callback','PLAYBOMBMousemultiple');d