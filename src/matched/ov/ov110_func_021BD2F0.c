/*
 * function: PMSIV_MENU_LoadBlendColors
 * address: 0x021BD2F0
 * packet: pkt_ov110_021BD2F0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021BD342.
 * symbols:
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22376.h"
#include "../include/Obj22377.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(const void *, void *, unsigned int);
extern u32 func_020307B0(void *p);
void PMSIV_MENU_LoadBlendColors(u8 *p) {
    void *obj;
    void *handle;
    u8 *data;
    handle = ARC_UTIL_LoadPaletteBlockFromArchive(43, 7, (u32)(&obj), 42);
    data = *(u8 * *)&((struct Obj22377 *)obj)->fC;
    MI_CpuCopy8(data + 0x96, p + 0x98, 10);
    MI_CpuCopy8(data + 0x76, p + 0xa2, 10);
    func_020307B0(handle);
    MI_CpuCopy8(p + 0x98, p + 0xac, 10);
    ((struct Obj22376 *)p)->fB8 = 0;
}
