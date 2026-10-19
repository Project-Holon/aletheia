/*
 * function: POKETRADE_2D_LoadSummaryBackground
 * address: 0x021E40EC
 * packet: pkt_ov119_021E40EC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadBgPaletteAddFromHandle 0x02049990 arm
 *   BG_SYS_ChangeScrollImmediate 0x02040618 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   func_02040588 0x02040588 arm
 *   gSummaryBgTable 0x021E7DD0 data a4
 */
#include "../include/Obj00001.h"
typedef struct { unsigned int w[2]; } Tbl2;
typedef unsigned short u16;

extern const Tbl2 gSummaryBgTable;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void BG_SYS_ChangeScrollImmediate(u32 layer, u32 a, u32 b);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, unsigned int v);
extern void ARC_TOOL_DeleteHandle(void *);
extern void func_02040588(unsigned char which, unsigned char enable);
void POKETRADE_2D_LoadSummaryBackground(char *p, int a1, int a2)
{
    Tbl2 tbl = gSummaryBgTable;
    void *v;
    v = func_020490F4(0x66, ((struct Obj00001 *)p)->f5F4);
    ARC_UTIL_UploadBgPaletteAddFromHandle(v, tbl.w[a2], 4, 0, (unsigned short)((struct Obj00001 *)p)->f870, 0, 0, ((struct Obj00001 *)p)->f5F4);
    if (a1 != 0) {
        BG_SYS_ChangeScrollImmediate(4, 0, 0x80);
    } else {
        BG_SYS_ChangeScrollImmediate(4, 0, 0);
    }
    CLACT_SetActorDrawEnable((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04, 0);
    ARC_TOOL_DeleteHandle(v);
    func_02040588(4, 1);
}
