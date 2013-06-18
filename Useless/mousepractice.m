axis equal
w=[0 100];
h=[0 100];
axis([w h])

rect=rectangle('Position',[50 50 20 20],'facecolor','r');

move=[-5 -10 -5 0 5 10 5 0];
tic
while 1
for i=1:8
    axis([w+move(i) h+move(i)]);
    pause(0.05)
end
if toc>=2
    break
end
end