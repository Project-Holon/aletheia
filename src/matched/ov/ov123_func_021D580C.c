/*
 * function: GSYNC_MESSAGE_UpdateStream
 * address: 0x021D580C
 * packet: pkt_ov123_021D580C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 *
 * symbols:
 *   APP_KEYCURSOR_Update  0x020286C4  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   PRINTSYS_CTRL_Update  0x02028484  thumb  arm9
 */
#include "../include/Obj04496.h"
struct Ctx;
struct Rec3;
extern void APP_KEYCURSOR_Update(struct Ctx *ctx, void *p, void *cell);
typedef signed int     s32;
struct Blk;
extern s32 PRINTSYS_CTRL_Update(struct Blk *blk, void *h);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
int GSYNC_MESSAGE_UpdateStream(char *p)
{
    if (((struct Obj04496 *)p)->f80) {
        APP_KEYCURSOR_Update(((struct Obj04496 *)p)->f40, ((struct Obj04496 *)p)->f80, ((struct Obj04496 *)p)->f44);
        if (!PRINTSYS_CTRL_Update((struct Blk *)(p+0xa8), ((struct Obj04496 *)p)->f80)) return 0;
        PRINTSYS_PrintStreamDelete(((struct Obj04496 *)p)->f80);
        ((struct Obj04496 *)p)->f80=0;
    }
    return 1;
}
