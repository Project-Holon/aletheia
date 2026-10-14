/*
 * function: ZUKAN_LIST_FrameListSelectCallback
 * address: 0x021BCBE0
 * packet: pkt_ov209_021BCBE0
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FRAME_LIST_GetItemValue 0x021B9398 thumb ov067
 *   FRAME_LIST_GetScrollPos 0x021B93B8 thumb ov067
 *   ZUKAN_LIST_LoadSpeciesIcon 0x021BDD7C thumb ov209
 *   ZUKAN_LIST_MoveCursorActor 0x021BE51C thumb ov209
 */
#include "../include/Obj14667.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 FRAME_LIST_GetItemValue(char *p, int index);
extern int FRAME_LIST_GetScrollPos(char *);
extern void ZUKAN_LIST_LoadSpeciesIcon(char *, u16);
extern void ZUKAN_LIST_MoveCursorActor(char *, int);
void ZUKAN_LIST_FrameListSelectCallback(char *p, int index)
{
    u32 v;
    v = FRAME_LIST_GetItemValue(((struct Obj14667 *)p)->fC2C, index);
    if ((v & 0xF0000000) >> 28) ZUKAN_LIST_LoadSpeciesIcon(p, v & 0x0FFFFFFF);
    else ZUKAN_LIST_LoadSpeciesIcon(p, 0);
    ZUKAN_LIST_MoveCursorActor(p, index - FRAME_LIST_GetScrollPos(*(char * *)&((struct Obj14667 *)p)->fC2C));
}
