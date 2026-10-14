/*
 * function: HALL_OF_FAME_LoadUiPalette
 * address: 0x021B7750
 * packet: pkt_ov180_021B7750
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_LoadPaletteBlockFromHandle 0x02049F78 arm
 *   CLACT_TransferPalette 0x0204ADEC arm
 *   func_020307B0 0x020307B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   gHallOfFameTrainerPaletteIds 0x021B82D4 data a4
 */
#include "../include/Obj00547.h"
typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u32 heap);
extern void *ARC_UTIL_LoadPaletteBlockFromHandle(void *a0, u32 a1, u32 a2, u32 a3);
extern void CLACT_TransferPalette(int,void *,int);
extern u32 func_020307B0(void *p);
extern void ARC_TOOL_DeleteHandle(unsigned char *);
extern unsigned gHallOfFameTrainerPaletteIds[];
void HALL_OF_FAME_LoadUiPalette(char *p) {
    void *out;
    unsigned char *bank;
    void *buffer;
    bank=func_020490F4(216,0x808d);
    buffer=ARC_UTIL_LoadPaletteBlockFromHandle(bank,gHallOfFameTrainerPaletteIds[((struct Obj00547 *)p)->f915A],(u32)(&out),141);
    CLACT_TransferPalette(*(int *)&((struct Obj00547 *)p)->f90EC,out,1);
    func_020307B0(buffer);
    ARC_TOOL_DeleteHandle(bank);
}
