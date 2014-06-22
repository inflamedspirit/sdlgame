#ifndef ARROW_H
#define ARROW_H

class Arrow : public Object {
 public:
  float angle;
  float arm_offset;
  float arm_length;
  float arm_angle;
  float p1x,p1y;
  float p2x,p2y;
  float p3x,p3y;

  bool gravity;
  bool orbiting;
  
  Object orbit;
  Input input;

  void Resize();

};

#endif
