/*
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
 *   func_0689A7EC  0x0689A7EC  thumb  ov095
 *   func_0689A7FC  0x0689A7FC  thumb  ov095
 *   func_0689A80C  0x0689A80C  thumb  ov095
 *   func_0689A81C  0x0689A81C  thumb  ov095
 *   func_0689A82C  0x0689A82C  thumb  ov095
 *   func_0689A83C  0x0689A83C  thumb  ov095
 *   d_0689D8D4     0x0689D8D4  data   ov095
 *   d_0689DF64     0x0689DF64  data   ov095
 *   d_0689D828     0x0689D828  data   ov095
 */
#include "../../../matched/include/Obj06337.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0689A7EC(u32 h, void *a, void *b);
extern void func_0689A7FC(u32 x);
extern void func_0689A80C(u32 h, int a, int b);
extern void func_0689A81C(int a);
extern void func_0689A82C(void);
extern int func_0689A83C(u32 h);
extern char d_0689D8D4[];
extern char d_0689DF64[];
extern u8 d_0689D828[];

int func_0689A76C(int *st, u8 *s)
{
    int i;
    u32 v;

    switch (*st) {
    case 0:
        i = func_0689A7EC(((struct Obj06337 *)s)->fB0, d_0689D8D4, d_0689DF64);
        if (i == -1)
            break;
        v = d_0689D828[i];
        ((struct Obj06337 *)s)->f98 = v;
        if (v == 4) {
            func_0689A7FC(((struct Obj06337 *)s)->f70);
            func_0689A80C(((struct Obj06337 *)s)->fB0, 0, 0);
            func_0689A81C(8);
            func_0689A82C();
            *st = *st + 1;
            break;
        }
        return 1;
    case 1:
        if (func_0689A83C(((struct Obj06337 *)s)->fB0) == 0)
            return 1;
        break;
    }
    return 0;
}
