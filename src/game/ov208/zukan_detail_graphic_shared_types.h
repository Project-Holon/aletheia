#ifndef ZUKAN_DETAIL_GRAPHIC_SHARED_TYPES_H
#define ZUKAN_DETAIL_GRAPHIC_SHARED_TYPES_H

#include "zukan_detail_procsys_shared_types.h"

struct BgTemplate;

struct Cfg;

struct Bank;

struct Vec3;

typedef struct {u32 bg,tmpl[8],type,on;} BgEntry;

typedef struct {int x,y,z;} Vec3;

struct BgTemplate {
    u32 w[8];
};

struct BgEntry {
    u32 bg;
    struct BgTemplate tmpl;
    u32 type;
    u32 on;
};

#endif
