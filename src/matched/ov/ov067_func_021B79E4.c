/*
 * function: FRAME_LIST_AddItem
 * address: 0x021B79E4
 * packet: pkt_ov067_021B79E4
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: 8-byte Pair records preserve the second store at record+4; flat word indexing added two bytes.
 * leaf: parent-cleared sole blocker of ov210 021C04CC; paired ov067 constructor 021B7754 and getter 021B93B8 identify region. Foreign ov021 body is unrelated.
 */
#include "../include/Obj20620.h"
typedef struct Pair { unsigned first, second; } Pair;
void FRAME_LIST_AddItem(char *ctx, unsigned first, unsigned second)
{
    (*(Pair **)(ctx + 0x28))[*(unsigned short *)(ctx + 0x4c)].first = first;
    (*(Pair **)(ctx + 0x28))[*(unsigned short *)(ctx + 0x4c)].second = second;
    (((struct Obj20620 *)ctx)->f4C)++;
}
