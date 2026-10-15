/*
 * function: MONOLITH_TOOL_MENU_IsMessageDone
 * address:  0x021B8434
 * packet:   pkt_ov071_021B8434
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled tail-call stub called by MONOLITH_TOOL_MENU_Update.
 *
 * symbols:
 *   PRINTSYS_CTRL_Update  0x02028484  thumb
 */
#include "../include/Obj20725.h"

typedef unsigned char u8;
typedef unsigned int u32;

typedef signed int     s32;
struct Blk;
extern s32 PRINTSYS_CTRL_Update(struct Blk *blk, void *h);

int MONOLITH_TOOL_MENU_IsMessageDone(u8 *p, u8 *q)
{
    return PRINTSYS_CTRL_Update((struct Blk *)(p + 0x38), (void *)(((struct Obj20725 *)q)->f40));
}
