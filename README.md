# Delta_Control
Delta机器人运动反解
# MATLAB代码
`
function [theta1,theta2,theta3] = DeltaInversekinematic(x,y,z)
R=90;
r=41.57;
L=85;
l=140;
z=-z;
m=x^2+y^2+z^2+(R-r)^2+L^2-l^2;
A=[(m-2*x*(R-r))/(2*L)-(R-r-x)
   (m+(R-r)*(x-sqrt(3)*y))/(L)-2*(R-r)-(x-sqrt(3)*y)
   (m+(R-r)*(x+sqrt(3)*y))/(L)-2*(R-r)-(x+sqrt(3)*y)];
B=[2*z
   4*z
   4*z];
C=[(m-2*x*(R-r))/(2*L)+(R-r-x)
   (m+(R-r)*(x-sqrt(3)*y))/(L)+2*(R-r)+(x-sqrt(3)*y)
   (m+(R-r)*(x+sqrt(3)*y))/(L)+2*(R-r)+(x+sqrt(3)*y)];
theta1=2*atan((-B(1)-sqrt(B(1)^2-4*A(1)*C(1)))/(2*A(1)));
theta2=2*atan((-B(2)-sqrt(B(2)^2-4*A(2)*C(2)))/(2*A(2)));
theta3=2*atan((-B(3)-sqrt(B(3)^2-4*A(3)*C(3)))/(2*A(3)));
end
`
