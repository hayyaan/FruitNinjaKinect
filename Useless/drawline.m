function [] = drawline(a)
%DRAWLINE Summary of this function goes here
%   Detailed explanation goes here

p=line(0,0);
mouseLoc = [200 200];

X=[];
Y=[];
% a=[];

while 1
    set(gcf, 'WindowButtonMotionFcn', 'mouseLoc = get(gca, ''CurrentPoint'');');
    tic
    for i=1:0.1:10
        X=[X mouseLoc(1,1)];
        Y=[Y mouseLoc(1,2)];
        set(p,'xdata',X,'ydata',Y,'LineWidth',3);
        pause(0.001)
        if length(X)==30
            X=X(2:end);
            Y=[];
            a=[];
            return
        end
    end
end
end

