%
clear
close all
clc

%%
f = figure('Position',[400 200 600 400]);
hold on;

%%

h1 = uicontrol(f,'Style','PushButton','Units','normalized',...
               'String','MOUSE multiple','Position',[.75 .7 .1 .15],'Callback','PLAYMousemultiple');
% set(h1,'callback');           
           
      

         
axis off

