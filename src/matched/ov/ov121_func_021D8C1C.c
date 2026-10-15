/*
 * function: MYSTERY_InitCardView
 * address: 0x021D8C1C
 * packet: pkt_ov121_021D8C1C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware reads/writes at 021D8C4E..021D8C8A: DISPCNT, WININ, WINOUT, WIN0H/V.
 * symbols:
 *   MYSTERY_CardViewAnimReveal 0x021D8EA4 thumb ov121
 *   MYSTERY_CardViewAnimScroll 0x021D8D1C thumb ov121
 *   MYSTERY_CardViewAnimFade 0x021D9138 thumb ov121
 */
#include "../include/Obj04491.h"
#include "../include/Obj22867.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_CardViewAnimReveal(u8 *p);
extern void MYSTERY_CardViewAnimScroll(u8 *p);
extern void MYSTERY_CardViewAnimFade(u8 *p);
static inline void GX_SetVisibleWnd(int window)
{
    *(volatile u32 *)0x04000000=(*(volatile u32 *)0x04000000&~0xe000)|(window<<13);
}
static inline void G2_SetWnd0InsidePlane(int wnd,int effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x04000048&~0x3f)|(u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x04000048=(u16)tmp;
}
static inline void G2_SetWndOutsidePlane(int wnd,int effect)
{
    u32 tmp;
    tmp=(*(volatile u16 *)0x0400004a&~0x3f)|(u32)wnd;
    if (effect) tmp|=0x20;
    *(volatile u16 *)0x0400004a=(u16)tmp;
}
static inline void G2_SetWnd0Position(int x1,int y1,int x2,int y2)
{
    *(volatile u16 *)0x04000040=(u16)(((x1<<8)&0xff00)|(x2&0xff));
    *(volatile u16 *)0x04000044=(u16)(((y1<<8)&0xff00)|(y2&0xff));
}
void MYSTERY_InitCardView(u8 *p,int mode)
{
    ((struct Obj04491 *)p)->f8=0;
    ((struct Obj04491 *)p)->f20=0;
    ((struct Obj04491 *)p)->f18=0;
    switch(mode) {
    case 0:
        if (((struct Obj22867 *)(*(u8 * *)&((struct Obj04491 *)p)->f114))->f2CA) *(void (**)(void *))(p+44)=(void (*)(void *))MYSTERY_CardViewAnimReveal;
        else *(void (**)(void *))(p+44)=(void (*)(void *))MYSTERY_CardViewAnimScroll;
        break;
    case 1:
        *(void (**)(void *))(p+44)=(void (*)(void *))MYSTERY_CardViewAnimFade;
        break;
    }
    GX_SetVisibleWnd(1);
    G2_SetWnd0InsidePlane(15,1);
    G2_SetWndOutsidePlane(31,1);
    G2_SetWnd0Position(0,168,255,192);
}
