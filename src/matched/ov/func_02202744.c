/*
 * function: WORLDTRADE_ADAPTER_ExitPrinter
 * address:  0x02202744
 * packet:   pkt_02202744
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   TCBL_Destroy  0x02031140  arm  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 *

 *
 * Free every buffer the object owns and blank the 0x13c-byte tail.
 */
#include "../include/Obj07257.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
extern int APP_KEYCURSOR_Delete(int a0);
struct PrintSys;
struct S02031140;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern void MI_CpuFill8(u32 p, u32 v, u32 n);

void WORLDTRADE_ADAPTER_ExitPrinter(u8 *p)
{
    APP_KEYCURSOR_Delete(((struct Obj07257 *)p)->f138);
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj07257 *)p)->fC));
    GF_FONT_Delete((void *)(((struct Obj07257 *)p)->f0));
    TCBL_Destroy((struct S02031140 *)(((struct Obj07257 *)p)->f4));
    MI_CpuFill8((u32)p, 0, 0x13c);
}
