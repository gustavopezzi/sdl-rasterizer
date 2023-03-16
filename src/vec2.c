#include <math.h>
#include "vec2.h"

vec2_t vec2_new(float x, float y) {
  vec2_t result = { x, y };
  return result;
}

vec2_t vec2_add(vec2_t* a, vec2_t* b) {
  vec2_t result = {
    .x = a->x + b->x,
    .y = a->y + b->y
  };
  return result;
}

vec2_t vec2_sub(vec2_t* a, vec2_t* b) {
  vec2_t result = {
    .x = a->x - b->x,
    .y = a->y - b->y
  };
  return result;
}

vec2_t vec2_mul(vec2_t* v, float factor) {
  vec2_t result = {
    .x = v->x * factor,
    .y = v->y * factor
  };
  return result;
}

vec2_t vec2_div(vec2_t* v, float factor) {
  vec2_t result = {
    .x = v->x / factor,
    .y = v->y / factor
  };
  return result;
}

float vec2_length(vec2_t* v) {
  return sqrt(v->x * v->x + v->y * v->y);
}

float vec2_dot(vec2_t* a, vec2_t* b) {
  return (a->x * b->x) + (a->y * b->y);
}

float vec2_cross(vec2_t* a, vec2_t* b) {
  return a->x * b->y - a->y * b->x;
}

void vec2_normalize(vec2_t* v) {
  float length = vec2_length(v);
  v->x /= length;
  v->y /= length;
}

vec2_t vec2_rotate(vec2_t v, vec2_t center, float angle) {
  vec2_t rot;
  v.x -= center.x;
  v.y -= center.y;
  rot.x = v.x * cos(angle) - v.y * sin(angle);
  rot.y = v.x * sin(angle) + v.y * cos(angle);
  rot.x += center.x;
  rot.y += center.y;
  return rot;
}
