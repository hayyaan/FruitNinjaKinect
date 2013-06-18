function Coordinates = GetJointCoordinates(JointName,Joints)
%#codegen
index = GetJointIndex(JointName);
Coordinates = Joints(:,index);