/*
 * function: func_021D7154
 * address: 0x021D7154
 * packet: pkt_ov125_021D7154
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D7700 0x021D7700 thumb ov125
 */
#include "../include/Obj22999.h"
typedef unsigned short u16;
extern char *func_021D7700(int);
extern void func_0200B784(u16, int *, int *);
int func_021D7154(int a, int index, int *outer, int *inner)
{
    char *p;
    int n, other;
    int i;
    i = 0;
    p = func_021D7700(a);
    func_0200B784(((struct Obj22999 *)p)->fA6, &n, &other);
    for (*outer = 0; *outer < n; ++*outer) {
        for (*inner = 0; *inner < *(u16 *)(p + *outer * 676 + 0xcfe); ++*inner) {
            if (i == index) return 1;
            ++i;
        }
    }
    return 0;
}
