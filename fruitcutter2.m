function [fr fruit fruit2 alpha alpha2] = fruitcutter2(fr,fruit)
%FRUITCUTTER Summary of this function goes here
%   Detailed explanation goes here
% axis([-100 100 -50 50])

start = fr.positionc;
delete(fruit);

if strcmp(fr.type,'apple')
    fruit=imshow(fr.spr.apple1);
    fruit2=imshow(fr.spr.apple2);
    alpha=fr.spr.apple1alpha;
    alpha2=fr.spr.apple2alpha;
end
if strcmp(fr.type,'banana')
    fruit=imshow(fr.spr.banana1);
    fruit2=imshow(fr.spr.banana2);
    alpha=fr.spr.banana1alpha;
    alpha2=fr.spr.banana2alpha;
end
if strcmp(fr.type,'watermelon')
    fruit=imshow(fr.spr.watermelon1);
    fruit2=imshow(fr.spr.watermelon2);
    alpha=fr.spr.watermelon1alpha;
    alpha2=fr.spr.watermelon2alpha;
end
if strcmp(fr.type,'bomb')
    fruit=imshow(fr.spr.bomb);
    fruit2=imshow(fr.spr.bomb);
    alpha=fr.spr.bombalpha;
    alpha2=fr.spr.bombalpha;
end

end

