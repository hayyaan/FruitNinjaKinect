function [ start side ] = startposition()
%STARTPOSITION Summary of this function goes here
%   Detailed explanation goes here
ax=[640 480];

if rand <0.6
    side='down';
else
    side='up';
end

if strcmp(side,'down')
    x=150+0.6*ax(1).*rand;
    y=0;
end
if strcmp(side,'up')
    x=150+0.6*ax(1).*rand;
    y=ax(2);
end
start=[x y];
end

