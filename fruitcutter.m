function [fr fruit fruit2] = fruitcutter(fr,fruit)
%FRUITCUTTER Summary of this function goes here
%   Detailed explanation goes here
% axis([-100 100 -50 50])

start = get(fruit,'Position');
start = start(1:2);
delete(fruit);
if strcmp(fr.type,'apple')
    fruit=rectangle('Position',[start 10 10],'Curvature',[1 0.5],'facecolor',[0.7 0.15 0.15]);
    fruit2=rectangle('Position',[start 10 10],'Curvature',[1 0.5],'facecolor',[0.7 0.15 0.15]);
end
if strcmp(fr.type,'banana')
    fruit=rectangle('Position',[start 8 8],'Curvature',[1 0.8],'facecolor','y');
    fruit2=rectangle('Position',[start 8 8],'Curvature',[1 0.8],'facecolor','y');
end
if strcmp(fr.type,'watermelon')
    fruit=rectangle('Position',[start 10 10],'Curvature',[0.8 0.5],'facecolor',[0 0.4 0]);
    fruit2=rectangle('Position',[start 10 10],'Curvature',[0.8 0.5],'facecolor',[0 0.4 0]);
end
if strcmp(fr.type, 'mango')
    fruit=rectangle('Position',[start 8 8],'Curvature',[0.9 1],'facecolor',[0.96 0.72 0]);
    fruit2=rectangle('Position',[start 8 8],'Curvature',[0.9 1],'facecolor',[0.96 0.72 0]);
end
if strcmp(fr.type,'grape')
    fruit=rectangle('Position',[start 5 5],'Curvature',[1 1],'facecolor',[0.75 0.4 0.4]);
    fruit2=rectangle('Position',[start 5 5],'Curvature',[1 1],'facecolor',[0.75 0.4 0.4]);
end
if strcmp(fr.type,'bomb')
    fruit=rectangle('Position',[start 1 1],'facecolor','r','Curvature',[1 1]);
    fruit2=rectangle('Position',[start 1 1],'facecolor','r','Curvature',[1 1]);
end

fr.position = get(fruit,'Position');
fr.positionc = fr.position(1:2);
radius=fr.position(3:4);
fr.positionc = fr.positionc + (1/2).*(radius);

end

