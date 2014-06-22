#include "arrow.h"

void Tick(){
  angle = atan2(vy,vx);

  //handle inputs

}

void Draw(){
  Resize();
  //draw things
}

void Resize(){
  p1x = arm_offset*cos(angle);
  p1y = arm_offset*sin(angle);
  p2x = p1x + arm_length*cos(angle+arm_angle/2+PI);
  p2y = p1y + arm_length*sin(angle+arm_angle/2+PI);
  p3x = p1x + arm_length*cos(angle-arm_angle/2+PI);
  p3y = p1y + arm_length*sin(angle-arm_angle/2+PI);
}


