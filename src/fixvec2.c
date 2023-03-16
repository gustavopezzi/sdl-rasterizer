#include "fixvec2.h"

fixvec2_t fixvec2_new(fix16_t x, fix16_t y) {
  fixvec2_t result = { x, y };
  return result;
}

fixvec2_t fixvec2_add(fixvec2_t* a, fixvec2_t* b) {
  fixvec2_t result = {
    .x = fix16_add(a->x, b->x),
    .y = fix16_add(a->y, b->y)
  };
  return result;
}

fixvec2_t fixvec2_sub(fixvec2_t* a, fixvec2_t* b) {
  fixvec2_t result = {
    .x = fix16_sub(a->x, b->x),
    .y = fix16_sub(a->y, b->y)
  };
  return result;
}

fixvec2_t fixvec2_mul(fixvec2_t* v, fix16_t factor) {
  fixvec2_t result = {
    .x = fix16_mul(v->x, factor),
    .y = fix16_mul(v->y, factor)
  };
  return result;
}

fixvec2_t fixvec2_div(fixvec2_t* v, fix16_t factor) {
  fixvec2_t result = {
    .x = fix16_div(v->x, factor),
    .y = fix16_div(v->y, factor)
  };
  return result;
}

fixvec2_t fixvec2_rotate(fixvec2_t v, fixvec2_t center, fix16_t angle) {
  fix16_t cosangle = fix16_cos(angle);
  fix16_t sinangle = fix16_sin(angle);

  fixvec2_t centered;
  centered.x = fix16_sub(v.x, center.x);
  centered.y = fix16_sub(v.y, center.y);
  
  fixvec2_t rot;
  rot.x = fix16_add(fix16_mul(cosangle, centered.x), fix16_mul(-sinangle, centered.y));
  rot.y = fix16_add(fix16_mul(sinangle, centered.x), fix16_mul(cosangle, centered.y));
  
  rot.x = fix16_add(rot.x, center.x);
  rot.y = fix16_add(rot.y, center.y);
  
  return rot;
}