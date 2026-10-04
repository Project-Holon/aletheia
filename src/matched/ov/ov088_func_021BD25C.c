/*
 * function: func_021BD25C
 * address:  0x021BD25C
 * packet:   pkt_ov088_021BD25C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * func_020351F8 (arm) resolves through the matched entry
 * src/matched/arm9/sub_020351F8.c.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_020071EC  0x020071EC  thumb
 *   func_020351F8  0x020351F8  arm
 *   d_021BDA0C     0x021BDA0C  data  ov088  a4
 *   d_021BD3B9     0x021BD3B9  data  ov088  a1
 */
#include "../include/Obj13237.h"

extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
struct Sub020071E4Ctrl;
extern unsigned char func_020071EC(const struct Sub020071E4Ctrl *);
typedef unsigned int   u32;
extern void func_020351F8(u32 a, u32 b);

void *func_021BD25C(int a, int b)
{
    char *r4 = (char *)func_02030734(a, 0x10, 1, (const char *)0x021BDA0C, 0x45);
    ((struct Obj13237 *)r4)->f0 = b;
    if (func_020071EC((const struct Sub020071E4Ctrl *)b) == 1) {
        r4[7] = 1;
    } else {
        func_020351F8(0x021BD3B9, (int)r4);
    }
    return r4;
}
