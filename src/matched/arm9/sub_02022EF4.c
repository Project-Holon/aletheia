/*
 * function: func_02022EF4
 * address:  0x02022EF4
 * packet:   pkt_02022EA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02022F34 0x02022F34  thumb
 *   sub_020056A0  0x020056A0  thumb
 */

typedef unsigned int u32;

struct WipeSubElem;
extern void func_02022F34(void *p, struct WipeSubElem *elems);
extern u32 sub_020056A0(void *callback, void *arg, u32 mask);

u32 func_02022EF4(void *arg)
{
    return sub_020056A0(func_02022F34, arg, 0x3FF);
}
