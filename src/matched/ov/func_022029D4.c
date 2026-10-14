/*
 * function: WORLDTRADE_ADAPTER_ExitMessageSystem
 * address:  0x022029D4
 * packet:   pkt_022029D4
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   MSGDATA_Delete  0x02045C04  arm  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *

 *
 * Release every buffer the object owns, then the object itself.
 */
#include "../include/Obj07259.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct PrintSys;
struct Rec;
struct WordSet;
extern u32 func_0201ED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
extern u32 func_020307B0(void *p);

void WORLDTRADE_ADAPTER_ExitMessageSystem(u8 *p)
{
    func_0201ED04((struct WordSet *)(((struct Obj07259 *)p)->f8));
    MSGDATA_Delete((struct Rec *)(((struct Obj07259 *)p)->fC));
    PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj07259 *)p)->f4));
    GF_FONT_Delete((void *)(((struct Obj07259 *)p)->f0));
    func_020307B0((void *)((u32)p));
}
