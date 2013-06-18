
clear
close all
clc

figure
hold on
% axis equal
axis([0 200 0 200])
[sp.apple map alpha] = imread('apple uncut.png');
app = imshow(sp.apple);


% imshow(apple);
[start side] = startposition();
[sp] = Motiongenerator(side,sp);
dt=0.01
while 1
    sp.speed=sp.speed + sp.accel.*dt;
    sp.positionc=sp.positionc + sp.speed.*dt;
set(app,'Xdata',[sp.positionc(1) sp.positionc(1)+20],'Ydata',[sp.positionc(2) sp.positionc(2)+20],'AlphaData',alpha);
pause(0.5)
end