function [ fr ] = Motiongenerator(side,fr)
%MOTIONGENERATOR Summary of this function goes here
%   Detailed explanation goes here
ddx=50*rand;
ddy=-150-200*rand;
fr.accel=[ddx ddy];
fr.accelcomp=[-ddx ddy];

dx=((-1)^(round(rand)))*.60+30*rand;
dy=200+160*rand;
fr.speed=[dx dy];
if strcmp(side,'up')
    fr.speed=[dx -dy];
    fr.accel=[ddx ddy];
end

end

