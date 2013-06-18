addpath('Mex')
SAMPLE_XML_PATH='Config/SamplesConfig.xml';

% Start the Kinect Process
% filename='Example/SkelShort.oni';
% KinectHandles=mxNiCreateContext(SAMPLE_XML_PATH,filename);

% To use the Kinect hardware use :
KinectHandles=mxNiCreateContext(SAMPLE_XML_PATH);

figure,
axis([0 640 0 480])
Pos= mxNiSkeleton(KinectHandles); 
I=mxNiPhoto(KinectHandles); I=permute(I,[3 2 1]);
h=imshow(I);
  lol=line(0,0);  
  lol2=line(0,0);
  lol3=line(0,0);
  lol4=line(0,0);
  
  rhandx=[];
  rhandy=[];
  lhandx=[];
  lhandy=[];
  
  r2handx=[];
  r2handy=[];
  l2handx=[];
  l2handy=[];
  
while(Pos(1)==0);
    mxNiUpdateContext(KinectHandles);
    I=mxNiPhoto(KinectHandles); I=permute(I,[3 2 1]);
    Pos= mxNiSkeleton(KinectHandles); 
    set(h,'Cdata',I); drawnow;

end

hh=zeros(1,9);
hhh=zeros(1,9);
while(Pos(1)>0)
    mxNiUpdateContext(KinectHandles);
    I=mxNiPhoto(KinectHandles); I=permute(I,[3 2 1]);
    set(h,'Cdata',I); drawnow;
    Pos= mxNiSkeleton(KinectHandles,1); 
    
    if(hh(1)>0);
        for i=1:9, delete(hh(i)); end
    end
    if(hhh(1)>0);
        for i=1:9, delete(hhh(i)); end
    end
    
    hold on
    y=Pos(1:15,7);
    x=Pos(1:15,6);
    y2=Pos(16:30,7);
    x2=Pos(16:30,6);
    
%     y=480-y;
%     y2=480-y2;
    
    rhandx=[rhandx x(8)];
    rhandy=[rhandy y(8)];
    
    lhandx=[lhandx x(5)];
    lhandy=[lhandy y(5)];
    
    r2handx=[r2handx x2(8)];
    r2handy=[r2handy y2(8)];
    
    l2handx=[l2handx x2(5)];
    l2handy=[l2handy y2(5)];
    
    if length(rhandx)>10
        rhandx=rhandx(2:end);
        rhandy=rhandy(2:end);
        lhandx=lhandx(2:end);
        lhandy=lhandy(2:end);
    end
    
    pause(0.01)
        if length(r2handx)>10
        r2handx=r2handx(2:end);
        r2handy=r2handy(2:end);
        l2handx=l2handx(2:end);
        l2handy=l2handy(2:end);
        end
    
%     pause(0.01)

    hh(1)=plot(x,y,'r.');
    hh(2)=plot(x([13 14 15]),y([13 14 15]),'g');
    hh(3)=plot(x([10 11 12]),y([10 11 12]),'g');
    hh(4)=plot(x([9 10]),y([9 10]),'m');
    hh(5)=plot(x([9 13]),y([9 13]),'m');
    hh(6)=plot(x([2 3 4 5]),y([2 3 4 5]),'b');
    hh(7)=plot(x([2 6 7 8]),y([2 6 7 8]),'b');
    hh(8)=plot(x([1 2]),y([1 2]),'c');
    hh(9)=plot(x([2 9]),y([2 9]),'c');
    drawnow
    
    hhh(1)=plot(x2,y2,'r.');
    hhh(2)=plot(x2([13 14 15]),y2([13 14 15]),'g');
    hhh(3)=plot(x2([10 11 12]),y2([10 11 12]),'g');
    hhh(4)=plot(x2([9 10]),y2([9 10]),'m');
    hhh(5)=plot(x2([9 13]),y2([9 13]),'m');
    hhh(6)=plot(x2([2 3 4 5]),y2([2 3 4 5]),'b');
    hhh(7)=plot(x2([2 6 7 8]),y2([2 6 7 8]),'b');
    hhh(8)=plot(x2([1 2]),y2([1 2]),'c');
    hhh(9)=plot(x2([2 9]),y2([2 9]),'c');
    drawnow
    
    set(lol,'Xdata',rhandx,'Ydata',rhandy,'LineWidth',5)
    set(lol2,'Xdata',lhandx,'Ydata',lhandy,'LineWidth',5)
    set(lol3,'Xdata',r2handx,'Ydata',r2handy,'LineWidth',5,'Color','r')
    set(lol4,'Xdata',l2handx,'Ydata',l2handy,'LineWidth',5,'Color','r')
    drawnow
end            

mxNiDeleteContext(KinectHandles);
  


    