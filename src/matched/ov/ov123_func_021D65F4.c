/*
 * function: GSYNC_DISP_StartPaletteWave
 * address: 0x021D65F4
 * packet: pkt_ov123_021D65F4
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02005624 0x02005624 thumb
 *   GSYNC_DISP_PaletteWaveTask 0x021D6548 thumb ov123
 *   PMSI_PARAM_MakeSineTable 0x02024230 thumb
 */
#include "../include/Obj08108.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u32 heap);
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void ARC_TOOL_DeleteHandle(void *);
extern void GSYNC_DISP_PaletteWaveTask(void *, u8 *);
typedef signed short   s16;
typedef signed int     s32;
extern void *func_02005624(u32 a, u32 b, u32 c);
extern void PMSI_PARAM_MakeSineTable(s16 *out, u32 count, u16 step, s32 amp);
void GSYNC_DISP_StartPaletteWave(u8 *p)
{
    void *h;
    h = func_020490F4(143, ((struct Obj08108 *)p)->f43C4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(h, 22, 3, 0, (u16)((struct Obj08108 *)p)->f4, 0, 0, ((struct Obj08108 *)p)->f43C4);
    ARC_TOOL_DeleteHandle(h);
    ((struct Obj08108 *)p)->f14 = func_02005624((u32)GSYNC_DISP_PaletteWaveTask, (u32)p, 0);
    PMSI_PARAM_MakeSineTable((s16 *)(p + 0x43c8), 192, 0x5b0, 0x1800);
}
