/*
 * function: MONOLITH_TOOL_LIST_IsMessageDone
 * address: 0x021B98B4
 * packet: pkt_ov071_021B98B4
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: unlabelled tail stub called by MONOLITH_TOOL_LIST_Main; parent confirmed unowned.
 * symbols:
 *   PRINTSYS_CTRL_Update 0x02028484 thumb
 */
#include "../include/Obj20751.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int     s32;
struct Blk;
extern s32 PRINTSYS_CTRL_Update(struct Blk *blk, void *h);
int MONOLITH_TOOL_LIST_IsMessageDone(u8 *a,u8 *b)
{
    return PRINTSYS_CTRL_Update((struct Blk *)(a+0x38),(void *)(((struct Obj20751 *)b)->f294));
}
