/*
 * function: func_021D6C60
 * address: 0x021D6C60
 * packet: pkt_ov121_021D6C60
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj22852.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void CLACT_TransferPalette(void *,void *,int);
extern u32 func_020307B0(void *p);
void func_021D6C60(u8 *p,int heap)
{
    void *out;
    void *raw;
    raw=ARC_UTIL_LoadPaletteBlockFromArchive(34,8,(u32)(&out),heap);
    CLACT_TransferPalette(((struct Obj22852 *)p)->f0,out,7);
    func_020307B0(raw);
}
