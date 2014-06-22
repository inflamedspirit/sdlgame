#ifndef OBJECT_H
#define OBJECT_H

class Object {
 public:
  float x;
  float y;
  float vx;
  float vy;
  float r;
  virtual void Tick();
  virtual void Draw();
};


#endif
