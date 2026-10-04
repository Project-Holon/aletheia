/*
 * function: func_021F4698
 * address:  0x021F4698
 * packet:   pkt_ov048_021F4698
 * region:   ov048
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   d_021F523C     0x021F523C  data  a1
 */
#include "../include/Obj02414.h"
#include "../include/Obj02415.h"

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
struct GfFont;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern const char d_021F523C[];

void *func_021F4698(unsigned char *p)
{
    int i;
    unsigned char *r5;

    r5 = func_02030734(((struct Obj02414 *)p)->f0, 0x1c, 0, d_021F523C, 0x60);
    i = 0;
    ((struct Obj02415 *)r5)->f0 = ((struct Obj02414 *)p)->f0;
    r5[2] = i;
    r5[3] = p[2];
    r5[4] = p[3];
    r5[5] = p[4];
    ((struct Obj02415 *)r5)->f10 = ((struct Obj02414 *)p)->f8;
    ((struct Obj02415 *)r5)->f18 = i;
    ((struct Obj02415 *)r5)->f8 = (int)func_02030734(((struct Obj02414 *)p)->f0, p[2] * 4, 0, d_021F523C, 0x6d);
    ((struct Obj02415 *)r5)->fC = (int)func_02030734(((struct Obj02414 *)p)->f0, p[2] * 4, 0, d_021F523C, 0x6f);
    for (i = 0; i < p[2]; i++) {
        (*(int **)(r5 + 8))[i] = 0;
        (*(int **)(r5 + 0xc))[i] = 0;
    }
    (*(int **)(r5 + 0xc))[0] = 1;
    ((struct Obj02415 *)r5)->f14 = (int)func_0201D7EC(0x17, 0, 0, 0, ((struct Obj02415 *)r5)->f0);
    return r5;
}
