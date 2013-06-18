function [bb bomb] = bombgenerator()
%BOMBGENERATOR Summary of this function goes here
%   Detailed explanation goes here

start = [randi(30) 0];
bomb=rectangle('Position',[start 10 10],'Curvature',[0.9 0.9],'facecolor','k');

bb.position = get(bomb,'Position');
bb.positionc = bb.position(1:2);
radius=bb.position(3:4);
bb.positionc = bb.positionc + (1/2).*(radius);


end

