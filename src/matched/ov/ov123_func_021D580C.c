/*
 * function: func_021D580C
 * address: 0x021D580C
 * packet: pkt_ov123_021D580C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 */
#include "../include/Obj04496.h"
struct Ctx;
struct Rec3;
extern void func_020286C4(struct Ctx *ctx, void *p, void *cell);
typedef signed int     s32;
struct Blk;
extern s32 func_02028484(struct Blk *blk, void *h);
extern void func_0201CE48(struct Rec3 *p);
int func_021D580C(char *p)
{
    if (((struct Obj04496 *)p)->f80) {
        func_020286C4(((struct Obj04496 *)p)->f40, ((struct Obj04496 *)p)->f80, ((struct Obj04496 *)p)->f44);
        if (!func_02028484((struct Blk *)(p+0xa8), ((struct Obj04496 *)p)->f80)) return 0;
        func_0201CE48(((struct Obj04496 *)p)->f80);
        ((struct Obj04496 *)p)->f80=0;
    }
    return 1;
}
