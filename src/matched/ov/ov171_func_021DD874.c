/*
 * function: DENDOU_VIEW_InitWindows
 * address: 0x021DD874
 * packet: pkt_ov171_021DD874
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: the first creation call passes 3 in r0, shared with its stack argument.
 * symbols:
 *   BMP_WIN_Init 0x02045088 arm
 *   BMP_WIN_Create 0x020450F0 arm
 */
#include "../include/Obj03850.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BMP_WIN_Init(u16 heapId);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
void DENDOU_VIEW_InitWindows(char *p)
{
    BMP_WIN_Init(0x8c);
    ((struct Obj03850 *)p)->fB48 = BMP_WIN_Create(3, 1, 0, 30, 2, 3, 1);
    ((struct Obj03850 *)p)->fB50 = BMP_WIN_Create(5, 4, 7, 24, 15, 1, 1);
}
