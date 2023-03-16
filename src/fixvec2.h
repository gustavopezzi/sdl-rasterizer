#ifndef FIXVEC2_H
#define FIXVEC2_H

#include "../lib/libfixmath/fix16.h"

typedef struct {
  fix16_t x, y;
} fixvec2_t;

fixvec2_t fixvec2_new(fix16_t x, fix16_t y);
fixvec2_t fixvec2_add(fixvec2_t* a, fixvec2_t* b);
fixvec2_t fixvec2_sub(fixvec2_t* a, fixvec2_t* b);
fixvec2_t fixvec2_mul(fixvec2_t* v, fix16_t factor);
fixvec2_t fixvec2_div(fixvec2_t* v, fix16_t factor);
fixvec2_t fixvec2_rotate(fixvec2_t v, fixvec2_t center, fix16_t angle);

#endif