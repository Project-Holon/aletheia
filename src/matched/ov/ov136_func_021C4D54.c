/*
 * function: func_021C4D54
 * address: 0x021C4D54
 * packet: pkt_ov136_021C4D54
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 *   CLACT_CreateUnit 0x0204B100 arm
 *   PMS_DRAW_SetNullColorPalette 0x0202DE5C thumb
 *   PMS_DRAW_Create  0x0202DB0C  thumb  arm9
 */
#include "../include/Obj00160.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 PRINTSYS_QUE_Create(void *p);
struct Bank;
struct PmsDraw;
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern struct PmsDraw *PMS_DRAW_Create(u32 a, u32 b, u32 c, u32 d, u8 e0, u8 e1, u16 heap);
extern void PMS_DRAW_SetNullColorPalette(struct PmsDraw *p, u8 v);
void func_021C4D54(u8 *p)
{
    ((struct Obj00160 *)p)->f158 = (void *)PRINTSYS_QUE_Create((void *)((u16)((struct Obj00160 *)p)->f0));
    ((struct Obj00160 *)p)->f154 = CLACT_CreateUnit(8, 1, (u16)((struct Obj00160 *)p)->f0);
    ((struct Obj00160 *)p)->f148 = PMS_DRAW_Create(*(u32 *)&((struct Obj00160 *)p)->f154, 0, *(u32 *)&((struct Obj00160 *)p)->f158, *(u32 *)&((struct Obj00160 *)p)->f24, 0, 4, (u16)((struct Obj00160 *)p)->f0);
    PMS_DRAW_SetNullColorPalette(((struct Obj00160 *)p)->f148, 0);
}
