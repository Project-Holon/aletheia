/*
 * function: func_0218C9E8
 * address:  0x0218C9E8
 * packet:   pkt_ov021_0218C9E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DD9EC     0x021DD9EC  data  ov021  a4
 *   func_0218B754  0x0218B754  thumb
 *   func_021938AC  0x021938AC  thumb ov021
 *   func_021C05D4  0x021C05D4  thumb ov021
 */
#include "../include/Obj01115.h"

typedef unsigned char  u8;
typedef unsigned short u16;

extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern int d_021DD9EC;
extern int func_0218B754(int a, void *p, int b);
typedef unsigned int   u32;
extern void *func_021938AC(u32 heap);
extern int func_021C05D4(int a, int b);

char *func_0218C9E8(int heap, int b)
{
    char *p = func_02030734(heap, 0x74, 1, (const char *)&d_021DD9EC, 0xf9);
    int z = 0;
    ((struct Obj01115 *)p)->f0 = heap;
    ((struct Obj01115 *)p)->f34 = z;
    ((struct Obj01115 *)p)->f38 = z;
    ((struct Obj01115 *)p)->f3C = z;
    ((struct Obj01115 *)p)->f14 = z;
    ((struct Obj01115 *)p)->f16 = z;
    ((struct Obj01115 *)p)->f18 = z;
    ((struct Obj01115 *)p)->f1C = z;
    ((struct Obj01115 *)p)->f4 = z;
    ((struct Obj01115 *)p)->f8 = z;
    ((struct Obj01115 *)p)->fC = 1;
    ((struct Obj01115 *)p)->f10 = -1;
    ((struct Obj01115 *)p)->f40 = z;
    ((struct Obj01115 *)p)->f68 = z;
    ((struct Obj01115 *)p)->f64 = func_0218B754(((struct Obj01115 *)p)->f0, p, b);
    ((struct Obj01115 *)p)->f6C = (int)func_021938AC(heap);
    ((struct Obj01115 *)p)->f70 = func_021C05D4(0x10, (u8)heap);
    return p;
}
