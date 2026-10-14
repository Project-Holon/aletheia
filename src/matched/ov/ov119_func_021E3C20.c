/*
 * function: POKETRADE_3D_CreateTouchbar
 * address: 0x021E3C20
 * packet: pkt_ov119_021E3C20
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   TOUCHBAR_Create 0x021B62E0 thumb ov067
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   TOUCHBAR_SetAllButtonsPriority 0x021B6520 thumb ov067
 *   d_021E7C0C 0x021E7C0C data a4
 */
#include "../include/Obj00252.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 f0, f4; u16 f8, fA, fC, fE, f10, f12; u32 f14, f18, f1C; } Element;
typedef struct { Element e[4]; } Template;
typedef struct { void *f0; u32 f4; int f8; u32 fC, f10, f14; int f18, f1C; } Config;
extern const Template d_021E7C0C;
extern void MI_CpuFill8(void *, int, int);
extern void *TOUCHBAR_Create(Config *, int);
typedef unsigned char  u8;
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void TOUCHBAR_SetAllButtonsPriority(u8 *p, u32 v);
void POKETRADE_3D_CreateTouchbar(char *p)
{
    Template t = d_021E7C0C;
    Config c;
    u16 a, b, d;
    MI_CpuFill8(&c, 0, 32);
    c.f0 = &t;
    c.f4 = 4;
    c.f8 = *(int *)&((struct Obj00252 *)p)->f9C4;
    c.fC = 4;
    c.f1C = 1;
    c.f10 = 7;
    c.f14 = 0;
    c.f18 = 2;
    a = *(u32 *)&((struct Obj00252 *)p)->f894;
    t.e[1].f8 = a;
    b = *(u32 *)&((struct Obj00252 *)p)->f880;
    t.e[1].fA = b;
    d = *(u32 *)&((struct Obj00252 *)p)->f8B0;
    t.e[1].fC = d;
    t.e[1].fE = 6; t.e[1].f10 = 5; t.e[1].f12 = 4;
    t.e[1].f18 = 0; t.e[1].f1C = 0x54C;
    t.e[2].f8 = a; t.e[2].fA = b; t.e[2].fC = d;
    t.e[2].fE = 9; t.e[2].f10 = 8; t.e[2].f12 = 7;
    t.e[2].f18 = 8; t.e[2].f1C = 0x54C;
    t.e[3].f8 = a; t.e[3].fA = b; t.e[3].fC = d;
    t.e[3].fE = 22; t.e[3].f10 = 21; t.e[3].f12 = 20;
    t.e[3].f18 = 48; t.e[3].f1C = 0x54C;
    ((struct Obj00252 *)p)->f9C0 = TOUCHBAR_Create(&c, ((struct Obj00252 *)p)->f5F4);
    TOUCHBAR_SetButtonVisible(((struct Obj00252 *)p)->f9C0, 9, 0);
    TOUCHBAR_SetButtonVisible(((struct Obj00252 *)p)->f9C0, 8, 0);
    TOUCHBAR_SetAllButtonsPriority(((struct Obj00252 *)p)->f9C0, 2);
}
