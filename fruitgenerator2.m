function [ fr fruit alpha] = fruitgenerator2(fr,start)
%FRUITGENERATOR Function randomly generates fruits
%   Options include Apples, Bananas, Watermelons


fr.types ={'apple', 'banana', 'watermelon', 'bomb'}; %Define all types of fruit available

if rand>0.8
    selection=4;
else
selection=randi(3); %Selecting a random type
end

fr.type=fr.types{selection};

if strcmp(fr.type,'apple')
    fruit=imshow(fr.spr.apple);
    alpha=fr.spr.applealpha;
end
if strcmp(fr.type,'banana')
    fruit=imshow(fr.spr.banana);
    alpha=fr.spr.bananaalpha;
end
if strcmp(fr.type,'watermelon')
    fruit=imshow(fr.spr.watermelon);
    alpha=fr.spr.watermelonalpha;
end
if strcmp(fr.type,'bomb')
    fruit=imshow(fr.spr.bomb);
    alpha=fr.spr.bombalpha;
end

% fr.position = get(fruit,'Position');
fr.positionc = start;

end

