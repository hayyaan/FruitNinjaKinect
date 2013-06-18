
clear all
clc

axis equal
p=line(0,0);
axis([0 1000 0 1000]);

mouseLoc = [200 200];
a=[];
% set(gcf, 'WindowButtonMotionFcn', 'mouseLoc = get(gca, ''CurrentPoint'');');


X=[];
Y=[];

% a=[];
for k=1:1000
%     set(gcf, 'WindowButtonDownFcn', 'a = get(gca, ''CurrentPoint'');');
    does= isempty(a);
    pause(0.001)
    while does==0
        % mouseLoc = [1 1];
        set(gcf, 'WindowButtonMotionFcn', 'mouseLoc = get(gca, ''CurrentPoint'');');
        tic
        for i=1:0.1:10
            X=[X mouseLoc(1,1)];
            Y=[Y mouseLoc(1,2)];
            set(p,'xdata',X,'ydata',Y,'LineWidth',3);
            pause(0.01)
%             if toc >10
            if length(X)==15
                X=X(2:end);
                Y=Y(2:end);
%                 a=[];
                break
            end
        end
     does=isempty(a);   
    end
end
