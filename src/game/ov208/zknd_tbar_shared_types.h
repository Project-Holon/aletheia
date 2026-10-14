#ifndef ZKND_TBAR_SHARED_TYPES_H
#define ZKND_TBAR_SHARED_TYPES_H

#include "zukan_detail_procsys_shared_types.h"

struct Obj;

struct Vec2;

struct Actor;

struct Pt { u16 x,y; };

struct Actor { char pad[0xc]; struct Pt pos; };

#endif
