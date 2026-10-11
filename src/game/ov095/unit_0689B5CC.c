/*
 * file:     unit_0689B5CC.c
 * function: func_0689B5CC
 * address:  0x0689B5CC
 * packet:   pkt_ov095_0689B5CC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0220270C  0x0220270C  thumb
 *   func_02202DC4  0x02202DC4  thumb
 *   func_022033CC  0x022033CC  thumb
 *   d_0689D88C     0x0689D88C  data   ov095
 *   d_0689DC48     0x0689DC48  data   ov095
 */
#include "../../matched/include/Obj03726.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02202DC4(u32 h, void *a, void *b);
extern void func_0220270C(u32 h, int a, int b);
extern int func_022033CC(u32 h);
extern char d_0689D88C[];
extern char d_0689DC48[];

int func_0689B5CC(u8 *s, u32 *out)
{
    int i;

    switch (s[0x93]) {
    case 0:
        i = func_02202DC4(((struct Obj03726 *)s)->fB0, d_0689D88C, d_0689DC48);
        if (i == -1)
            break;
        *(int *)&((struct Obj03726 *)s)->f94 = i;
        func_0220270C(((struct Obj03726 *)s)->fB0, 0, 0);
        s[0x93] = s[0x93] + 1;
        break;
    case 1:
        if (func_022033CC(((struct Obj03726 *)s)->fB0) == 0) {
            *out = ((struct Obj03726 *)s)->f94;
            return 1;
        }
        break;
    }
    return 0;
}
