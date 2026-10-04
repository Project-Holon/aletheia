/*
 * function: func_0218768C
 * address: 0x0218768C
 * packet: pkt_ov020_0218768C
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: capture the base in a local before filling the stack pair, preserving the original r3 load.
 * symbols:
 *   func_021876B0 0x021876B0 thumb ov020
 */
#include "../include/Obj07404.h"
typedef struct { int index; char *base; } Pair;
extern void func_021876B0(Pair *p, int tick);
void func_0218768C(char *p)
{
    Pair pair;
    char *base;
    (((struct Obj07404 *)p)->f18)++;
    base = *(char * *)&((struct Obj07404 *)p)->f14;
    if (base != (char *)-1) {
        pair.index = ((struct Obj07404 *)p)->fC;
        pair.base = base;
        func_021876B0(&pair, ((struct Obj07404 *)p)->f18);
    }
}
