/*
 * function: ZUKAN_LIST_UpdateScrollBarActor
 * address: 0x021BE588
 * packet: pkt_ov209_021BE588
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ZUKAN_LIST_GetActorPos 0x021BD958 thumb ov209
 *   FRAME_LIST_ClampToScrollBar 0x021B8AE4 thumb ov067
 *   ZUKAN_LIST_AddActorPos 0x021BD934 thumb ov209
 */
#include "../include/Obj00088.h"
typedef unsigned short u16;
struct S;
typedef signed short   s16;
typedef unsigned int   u32;
extern void ZUKAN_LIST_GetActorPos(char *p, u32 idx, s16 *x, s16 *y, u16 space);
extern int FRAME_LIST_ClampToScrollBar(struct S *s, unsigned int v);
extern void ZUKAN_LIST_AddActorPos(char *p, int idx, short a, short b, unsigned short c);
void ZUKAN_LIST_UpdateScrollBarActor(char *p)
{
    short pos[2];
    unsigned value;
    ZUKAN_LIST_GetActorPos(p,0,&pos[1],&pos[0],0);
    value=FRAME_LIST_ClampToScrollBar(*(struct S * *)&((struct Obj00088 *)p)->fC2C,pos[0]);
    if(value<12)value=12;else if(value>156)value=156;
    ZUKAN_LIST_AddActorPos(p,0,(short)252,(short)value,0);
}
