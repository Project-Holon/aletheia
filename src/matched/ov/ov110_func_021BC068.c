/*
 * function: PMSIV_EDIT_LoadPalette
 * address: 0x021BC068
 * packet: pkt_ov110_021BC068
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_02049B68 0x02049B68 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   MIi_CpuCopy16 0x02082A60 arm
 *   DC_FlushRange 0x020862F0 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22369.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void MIi_CpuCopy16(const void *, void *, int);
extern void DC_FlushRange(void *, unsigned);
extern u32 func_020307B0(void *p);
void PMSIV_EDIT_LoadPalette(u8 *p, void *a)
{
    u8 *data;
    void *handle;
    func_02049B68(a, 3, 0, 0, 448, 42);
    func_02049B68(a, 4, 4, 0, 160, 42);
    handle = ARC_UTIL_LoadPaletteBlockFromHandle(a, 6, (u32)((void **)&data), 42);
    MIi_CpuCopy16(((struct Obj22369 *)data)->fC, p + 0x58, 320);
    DC_FlushRange(p + 0x58, 320);
    func_020307B0(handle);
}
