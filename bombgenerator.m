function [ fr fruit] = bombgenerator( start )
%BOMBGENERATOR Summary of this function goes here
%   Detailed explanation goes here
fr.types ={'apple', 'banana', 'watermelon','mango','grape', 'bomb'}; %Define all types of fruit available

selection=6;
fr.type=fr.types{selection};

if strcmp(fr.type,'bomb')
    fruit=rectangle('Position',[start 40 40],'Curvature',[1 1],'facecolor','k');
end

fr.position = get(fruit,'Position');
fr.positionc = fr.position(1:2);
radius=fr.position(3:4);
fr.positionc = fr.positionc + (1/2).*(radius);


end

