/*
 * file:     unit_0689A76C.c
 * function: func_0689A76C
 * address:  0x0689A76C
 * packet:   pkt_ov095_0689A76C
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D8414  0x021D8414  thumb
 *   func_021F81EC  0x021F81EC  thumb
 *   func_021F8A78  0x021F8A78  thumb
 *   func_0220270C  0x0220270C  thumb
 *   func_02202DC4  0x02202DC4  thumb
 *   func_022033CC  0x022033CC  thumb
 *   d_0689D8D4     0x0689D8D4  data   ov095
 *   d_0689DF64     0x0689DF64  data   ov095
 *   d_0689D828     0x0689D828  data   ov095
 */
#include "../../matched/include/Obj06337.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02202DC4(u32 h, void *a, void *b);
extern void func_021D8414(u32 x);
extern void func_0220270C(u32 h, int a, int b);
extern void func_021F81EC(int a);
extern void func_021F8A78(void);
extern int func_022033CC(u32 h);
extern char d_0689D8D4[];
extern char d_0689DF64[];
extern u8 d_0689D828[];

int func_0689A76C(int *st, u8 *s)
{
    int i;
    u32 v;

    switch (*st) {
    case 0:
        i = func_02202DC4(((struct Obj06337 *)s)->fB0, d_0689D8D4, d_0689DF64);
        if (i == -1)
            break;
        v = d_0689D828[i];
        ((struct Obj06337 *)s)->f98 = v;
        if (v == 4) {
            func_021D8414(((struct Obj06337 *)s)->f70);
            func_0220270C(((struct Obj06337 *)s)->fB0, 0, 0);
            func_021F81EC(8);
            func_021F8A78();
            *st = *st + 1;
            break;
        }
        return 1;
    case 1:
        if (func_022033CC(((struct Obj06337 *)s)->fB0) == 0)
            return 1;
        break;
    }
    return 0;
}
