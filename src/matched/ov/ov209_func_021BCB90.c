/*
 * function: ZUKAN_LIST_FrameListMoveCallback
 * address: 0x021BCB90
 * packet: pkt_ov209_021BCB90
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: u16 fourth parameter pins its spill ahead of the index copy
 * symbols:
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   ZUKAN_LIST_PrintListRow 0x021BD75C thumb ov209
 *   ZUKAN_LIST_ShowSpeciesActor 0x021BE29C thumb ov209
 */
#include "../include/Obj02924.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 FRAME_LIST_GetItemValue(char *p, int index);
extern void ZUKAN_LIST_PrintListRow(char *p, unsigned char *dest, unsigned text0, unsigned index);
extern void ZUKAN_LIST_ShowSpeciesActor(char *, u16, int, int);
void ZUKAN_LIST_FrameListMoveCallback(char *p, int index, int a, u16 b, int c)
{
    u32 v;
    u32 low;
    v = FRAME_LIST_GetItemValue(((struct Obj02924 *)p)->fC2C, index);
    low = v & 0x0FFFFFFF;
    ZUKAN_LIST_PrintListRow(p, (unsigned char *)a, *(u32 *)(p + index * 4 + 0x4C), low);
    if ((v & 0xF0000000) >> 28) ZUKAN_LIST_ShowSpeciesActor(p, low, b, c);
}
