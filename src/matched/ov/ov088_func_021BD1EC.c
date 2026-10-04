/*
 * function: func_021BD1EC
 * address:  0x021BD1EC
 * packet:   pkt_ov088_021BD1EC
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201FDA0  0x0201FDA0  thumb
 */
#include "../include/Obj00578.h"

typedef struct {
    unsigned char a;
    unsigned char b;
    unsigned char c;
    unsigned char d;
    unsigned short e;
} Rect6;

extern void *func_0201FDA0(Rect6 *, int, int, int, int);

void func_021BD1EC(unsigned char *p)
{
    Rect6 r;
    r.a = 0;
    r.b = 0x18;
    r.c = 0x0D;
    r.d = 0x0F;
    r.e = 0;
    ((struct Obj00578 *)p)->f20 = func_0201FDA0(&r, 1, 0x0E, 1, 0x81);
}
