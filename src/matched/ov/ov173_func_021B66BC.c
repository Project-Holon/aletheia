/*
 * function: POKE_SUMMARY_MAIN_CreateMsgWindows
 * address:  0x021B66BC
 * packet:   pkt_021B66BC
 * region:   ov173
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   ARC_UTIL_LoadPaletteDataFromHandle  0x02049EF4  arm
 *   func_02049B40  0x02049B40  arm
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb
 */
#include "../include/Obj00180.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadPaletteDataFromHandle(void *p, u32 a, u32 b, void **out, u16 d);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);

void POKE_SUMMARY_MAIN_CreateMsgWindows(u8 *p, u8 *q)
{
    u32 v = 1 << 0xb;
    void *t;

    func_02049658(q, 1, 3, 0, 0, 0, 0x4f);
    func_020498F4(q, 4, 3, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 0, 0, 0, 0x4f);
    func_02049658(q, 1, 7, 0, 0, 0, 0x4f);
    func_020498F4(q, 2, 7, 0, v, 0, 0x4f);
    func_02049B68(q, 0, 4, 0, 0, 0x4f);
    t = ARC_UTIL_LoadPaletteDataFromHandle(q, 3, 0, (void **)(p + 0x1c4), 0x4f);
    ((struct Obj00180 *)p)->f1C0 = t;
    func_02049B40(0x17, 5, 4, 0x1c0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 0, 0x1e0, 0x20, 0x4f);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4f);
    BMP_MENUWORK_LoadCharAndPltt(4, 1, 0xd, 0, 0x4f);
}
