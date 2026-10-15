/*
 * function: WF2DMAP_SCENE_CreateButtons
 * address: 0x021D9490
 * packet: pkt_ov129_021D9490
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021DA798 0x021DA798 data a2
 *   WF2DMAP_SCENE_HandleButton 0x021D958C thumb ov129
 *   BUTTON_MAN_Create 0x02051B84 arm
 */
#include "../include/Obj14055.h"
typedef unsigned char u8;
typedef short s16;
typedef struct { s16 a,b,c,d; } Rect;
typedef struct { Rect rows[12]; } Rects;
extern const Rects d_021DA798;
typedef unsigned int   u32;
extern void WF2DMAP_SCENE_HandleButton(u32 n, int touch, char *p);
extern void *BUTTON_MAN_Create(u8 *,int,int,int);
void WF2DMAP_SCENE_CreateButtons(char *p)
{
    int i;
    Rects t;
    for(i=0;i<12;i++) *(void **)(p+i*28+16)=p+0x298+i*4;
    t=d_021DA798;
    for(;i<24;i++) {
        *(u8 *)(p+i*4+0x298)=t.rows[i-12].b-t.rows[i-12].d;
        *(u8 *)(p+i*4+0x29a)=t.rows[i-12].a-t.rows[i-12].c;
        *(u8 *)(p+i*4+0x299)=t.rows[i-12].b+t.rows[i-12].d;
        *(u8 *)(p+i*4+0x29b)=t.rows[i-12].a+t.rows[i-12].c;
    }
    ((struct Obj14055 *)p)->f2F8=255;
    ((struct Obj14055 *)p)->f294=BUTTON_MAN_Create((u8 *)(p+0x298),(int)WF2DMAP_SCENE_HandleButton,(int)p,50);
}
