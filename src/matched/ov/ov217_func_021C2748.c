/*
 * function: func_021C2748
 * address:  0x021C2748
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C28A4  0x021C28A4  thumb  ov217
 *   func_021C28BC  0x021C28BC  thumb  ov217
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm  arm9
 *
 * Pushes the +0x10 body through CLACT_SetActorDrawEnable, then the +0x14 body when
 * func_021C28BC() is busy, the +0x18 body when either query fires, and the
 * +0x1c body unconditionally.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj08445.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *, unsigned int);
extern u8 func_021C28A4(char *p);
extern u8 func_021C28BC(char *p);
void func_021C2748(u32 a0, u32 a1)
{
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f10, a1);
    if (func_021C28BC((char *)a0) != 0) {
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f14, a1);
    }
    if (func_021C28BC((char *)a0) != 0 || func_021C28A4((char *)a0) != 0) {
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f18, a1);
    }
    CLACT_SetActorDrawEnable((struct Obj *)((struct Obj08445 *)(((u8*)a0)))->f1C, a1);
}
