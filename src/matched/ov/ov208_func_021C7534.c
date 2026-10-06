/*
 * function: ov208_func_021C7534
 * address:  0x021C7534
 * packet:   pkt_ov208_021C7534
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ov208_func_021C7FF8  0x021C7FF8  thumb
 *   func_02015C48        0x02015C48  thumb
 */
#include "../include/Obj03369.h"

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} VecFx32;

struct Ov208Mdl {
    u32 obj;
};

extern void ov208_func_021C7FF8(struct Ov208Mdl *m, int i, VecFx32 *out);
extern void func_02015C48(void *p, u32 *src);

void ov208_func_021C7534(void *unused, u8 *p)
{
    VecFx32 v;

    if (((struct Obj03369 *)p)->f6C8 == 0) {
        v.x = -0x40000;
        v.y = -0xde66;
        v.z = 0;
        if (((struct Ov208Mdl *)(p + 0x94))->obj != 0) {
            ov208_func_021C7FF8((struct Ov208Mdl *)(p + 0x94), 1, &v);
            func_02015C48((void *)(((struct Ov208Mdl *)(p + 0x94))->obj), (u32 *)(&v));
        }
        if (((struct Ov208Mdl *)(p + 0xd8))->obj != 0) {
            ov208_func_021C7FF8((struct Ov208Mdl *)(p + 0xd8), 1, &v);
            func_02015C48((void *)(((struct Ov208Mdl *)(p + 0xd8))->obj), (u32 *)(&v));
        }
    } else {
        v.x = 0x40000;
        v.y = -0xde66;
        v.z = 0;
        if (((struct Ov208Mdl *)(p + 0x94))->obj != 0) {
            ov208_func_021C7FF8((struct Ov208Mdl *)(p + 0x94), 2, &v);
            func_02015C48((void *)(((struct Ov208Mdl *)(p + 0x94))->obj), (u32 *)(&v));
        }
        if (((struct Ov208Mdl *)(p + 0xd8))->obj != 0) {
            ov208_func_021C7FF8((struct Ov208Mdl *)(p + 0xd8), 2, &v);
            func_02015C48((void *)(((struct Ov208Mdl *)(p + 0xd8))->obj), (u32 *)(&v));
        }
    }
}
