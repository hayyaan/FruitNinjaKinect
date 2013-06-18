function [ fr fruit ] = fruitgenerator(start)
%FRUITGENERATOR Function randomly generates fruits
%   Options include Apples, Bananas, Watermelons


fr.types ={'apple', 'banana', 'watermelon','mango','grape', 'bomb'}; %Define all types of fruit available

if rand>0.8
    selection=6;
else
selection=randi(5); %Selecting a random type
end

fr.type=fr.types{selection};

if strcmp(fr.type,'apple')
    fruit=rectangle('Position',[start 35 35],'Curvature',[0.8 0.8],'facecolor',[0.7 0.15 0.15]);
end
if strcmp(fr.type,'banana')
    fruit=rectangle('Position',[start 15 45],'Curvature',[1 0.8],'facecolor','y');
end
if strcmp(fr.type,'watermelon')
    fruit=rectangle('Position',[start 60 30],'Curvature',[0.8 0.8],'facecolor',[0 0.4 0]);
end
if strcmp(fr.type,'mango')
    fruit=rectangle('Position',[start 35 50],'Curvature',[0.9 1],'facecolor',[0.96 0.72 0]);
end
if strcmp(fr.type,'grape')
    fruit=rectangle('Position',[start 40 40],'Curvature',[1 1],'facecolor',[0.75 0.4 0.4]);
end
if strcmp(fr.type,'bomb')
    fruit=rectangle('Position',[start 40 40],'Curvature',[1 1],'facecolor','k');
end

fr.position = get(fruit,'Position');
fr.positionc = fr.position(1:2);
radius=fr.position(3:4);
fr.positionc = fr.positionc + (1/2).*(radius);

end

