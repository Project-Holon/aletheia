/*
 * function: UN_SELECT_ScrollFrameList
 * address: 0x021B9CDC
 * packet: pkt_ov218_021B9CDC
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   FRAME_LIST_GetScrollBarTop 0x021B8AB8 thumb ov067
 *   UN_SELECT_SetActorX 0x021BA680 thumb ov218
 *   FRAME_LIST_GetSelectedIndex 0x021B93A4 thumb ov067
 *   FRAME_LIST_GetCursor 0x021B93B0 thumb ov067
 *   UN_SELECT_SetActorY 0x021BA6BC thumb ov218
 */
#include "../include/Obj03959.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern int FRAME_LIST_GetScrollBarTop(u8 *);
extern void UN_SELECT_SetActorX(char *p, int v);
extern int FRAME_LIST_GetSelectedIndex(char *);
extern int FRAME_LIST_GetCursor(char *);
extern void UN_SELECT_SetActorY(char *p, int y);
void UN_SELECT_ScrollFrameList(u8 *p)
{
    int selected;
    s16 y;
    y=FRAME_LIST_GetScrollBarTop(*(u8 * *)&((struct Obj03959 *)p)->f2C);
    UN_SELECT_SetActorX((char *)p,y);
    selected=FRAME_LIST_GetSelectedIndex(*(char * *)&((struct Obj03959 *)p)->f2C);
    UN_SELECT_SetActorY((char *)p,(int)(((u32)selected-(u32)FRAME_LIST_GetCursor(*(char * *)&((struct Obj03959 *)p)->f2C))*2+92));
}
