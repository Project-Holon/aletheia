/*
 * function: func_021BF5B8
 * address: 0x021BF5B8
 * packet: pkt_ov208_021BF5B8
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_LoadPaletteBlockFromArchive 0x02049F34 arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02061CA4 0x02061CA4 arm
 */
#include "../include/Obj25493.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Pltt { u32 pad0[3]; u8 *data; };
extern void *ARC_UTIL_LoadPaletteBlockFromArchive(u32 a0, u32 a1, u32 a2, u32 a3);
extern void MI_CpuCopy8(void *, void *, u32);
extern u32 func_020307B0(void *p);
extern int func_02061CA4(void *, u32, u32, int);
void func_021BF5B8(u16 *heap, u8 *p, int *ctx)
{
    struct Ov208Pltt *pltt;
    u32 file;
    u8 *data;
    file = (u32)ARC_UTIL_LoadPaletteBlockFromArchive(159, 3, (u32)(&pltt), *heap);
    data = pltt->data;
    MI_CpuCopy8(data + 0x20, p + 0xa8, 32);
    MI_CpuCopy8(data + 0x60, p + 0xc8, 32);
    func_020307B0((void *)file);
    ((struct Obj25493 *)p)->f108 = 0;
    MI_CpuCopy8(p + 0xa8, p + 0xe8, 32);
    func_02061CA4((void *)14, 192, (u32)(p + 0xe8), 32);
}
