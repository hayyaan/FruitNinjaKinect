function [] = bombexplode(aw,ah)
%BOMBEXPLODE Summary of this function goes here
%   Detailed explanation goes here

move=[-5 -10 -5 0 5 10 5 0];
tic
while 1
for i=1:8
    axis([aw+move(i) ah+move(i)]);
    pause(0.05)
if toc>=2
    return
end
end
end

end

