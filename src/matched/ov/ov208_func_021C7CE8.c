/*
 * function: ZUKAN_DETAIL_FORM_RebuildSideItems
 * address: 0x021C7CE8
 * packet: pkt_ov208_021C7CE8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: MCSS_SetTaskSystem witness filed as src/matched/arm9/MCSS_SetTaskSystem.c (2026-10-02), shard pending from the integrator; EXACT after that
 *   typedef unsigned int u32;
 *   void MCSS_SetTaskSystem(char *p, u32 value) { *(u32 *)(p + 8) = value; }
 * symbols:
 *   ZUKAN_DETAIL_FORM_DestroyModelItem 0x021C51A0 thumb ov208
 *   ZUKAN_DETAIL_FORM_InitAnimState 0x021C51C8 thumb ov208
 *   ZUKAN_DETAIL_FORM_PlaceModelItem 0x021C569C thumb ov208
 *   MCSS_SetTaskSystem 0x02014CEC thumb
 */
#include "../include/Obj00147.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void ZUKAN_DETAIL_FORM_DestroyModelItem(char *p, int a);
extern void ZUKAN_DETAIL_FORM_InitAnimState(u32, int, u8 *);
extern void ZUKAN_DETAIL_FORM_PlaceModelItem(u16 *, u8 *, int, int, int, int, u16);
extern void MCSS_SetTaskSystem(u8 *p, u32 value);
void ZUKAN_DETAIL_FORM_RebuildSideItems(u16 *a0, u8 *p, int key)
{
    int a;
    int b;
    if (((struct Obj00147 *)p)->f6B8 != 0) return;
    ZUKAN_DETAIL_FORM_DestroyModelItem((char *)(p + 0x94), ((struct Obj00147 *)p)->f8);
    ZUKAN_DETAIL_FORM_DestroyModelItem((char *)(p + 0xD8), ((struct Obj00147 *)p)->f8);
    MCSS_SetTaskSystem((u8 *)(((struct Obj00147 *)p)->f8), 0);
    a = ((struct Obj00147 *)p)->f124 != 0 ? 2 : 4;
    b = ((struct Obj00147 *)p)->f124 != 0 ? 4 : 3;
    ZUKAN_DETAIL_FORM_PlaceModelItem(a0, p, key, a, b, 2, ((struct Obj00147 *)p)->f550);
    if (a != 4) ZUKAN_DETAIL_FORM_InitAnimState(((struct Obj00147 *)p)->f98, 2, p);
    if (b != 4) ZUKAN_DETAIL_FORM_InitAnimState(((struct Obj00147 *)p)->fDC, 3, p);
    MCSS_SetTaskSystem((u8 *)(((struct Obj00147 *)p)->f8), ((struct Obj00147 *)p)->f120);
}
