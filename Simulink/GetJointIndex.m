function JointIndex = GetJointIndex(JointName)
%#codegen
if (strcmp(JointName,'SKELETON_HEAD') ~= 0)
    JointIndex = 1;    
elseif (strcmp(JointName,'SKELETON_NECK') ~= 0)
    JointIndex = 2;
elseif (strcmp(JointName,'SKELETON_TORSO') ~= 0)
    JointIndex = 3;
elseif (strcmp(JointName,'SKELETON_LEFT_SHOULDER') ~= 0)
    JointIndex = 4;
elseif (strcmp(JointName,'SKELETON_LEFT_ELBOW') ~= 0)
    JointIndex = 5;    
elseif (strcmp(JointName,'SKELETON_LEFT_HAND') ~= 0)
    JointIndex = 6;
elseif (strcmp(JointName,'SKELETON_RIGHT_SHOULDER') ~= 0)
    JointIndex = 7;
elseif (strcmp(JointName,'SKELETON_RIGHT_ELBOW') ~= 0)
    JointIndex = 8;
elseif (strcmp(JointName,'SKELETON_RIGHT_HAND') ~= 0)
    JointIndex = 9;    
elseif (strcmp(JointName,'SKELETON_LEFT_THIGH') ~= 0)
    JointIndex = 10;      
elseif (strcmp(JointName,'SKELETON_LEFT_KNEE') ~= 0)
    JointIndex = 11;        
elseif (strcmp(JointName,'SKELETON_LEFT_FOOT') ~= 0)
    JointIndex = 12;
elseif (strcmp(JointName,'SKELETON_RIGHT_THIGH') ~= 0)
    JointIndex = 13;
elseif (strcmp(JointName,'SKELETON_RIGHT_KNEE') ~= 0)
    JointIndex = 14;
elseif (strcmp(JointName,'SKELETON_RIGHT_FOOT') ~= 0)
    JointIndex = 15;    
else
    JointIndex = -1;
end
