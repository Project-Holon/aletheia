/*
 * function: func_021B95A0
 * address:  0x021B95A0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021B985C  0x021B985C  thumb  ov217
 *   func_021B9874  0x021B9874  thumb  ov217
 *   func_021B9894  0x021B9894  thumb  ov217
 *   func_021B98B8  0x021B98B8  thumb  ov217
 *   func_021B9920  0x021B9920  thumb  ov217
 *   func_021B9A24  0x021B9A24  thumb  ov217
 *   PROCSYS_AllocProcWork  0x0203159C  arm  arm9
 *   BG_SYS_SetVramBanks  0x020433E0  arm  arm9
 *   BG_SYS_SetLcdSwap  0x0204363C  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj01438.h"
#include "../include/Obj10952.h"
#include "../include/Obj25801.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct DispVram;
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void BG_SYS_SetVramBanks(const struct DispVram *c);
extern void BG_SYS_SetLcdSwap(u32 swap);
extern void func_021B985C(void *p, u32 value);
extern void func_021B9874(u32 a0);
extern void func_021B9894(u32 a0);
extern void func_021B98B8(unsigned short heapId);
extern void func_021B9920(u32 heap);
extern void func_021B9A24(u32 heap);
u32 func_021B95A0(u32 a0, u32 a1, u8 *a2, u32 a3)
{
    switch (((struct Obj10952 *)((u8*)a1))->f0) {
    case 0:
    PROCSYS_AllocProcWork((struct Obj0203159C *)a0, 32, 1);
    ((struct Obj10952 *)((u8*)a1))->f0 = (u32)(((struct Obj10952 *)((u8*)a1))->f0 + 1);
    break;
    case 1:
    func_021B985C((void *)a3, ((struct Obj25801 *)((u8*)a2))->f0);
    BG_SYS_SetVramBanks((const struct DispVram *)0x21C2EA0);
    BG_SYS_SetLcdSwap(0);
    func_021B98B8(((struct Obj01438 *)((u8*)a3))->f0);
    func_021B9A24(((struct Obj01438 *)((u8*)a3))->f0);
    func_021B9920(((struct Obj01438 *)((u8*)a3))->f0);
    func_021B9874(a3);
    func_021B9894(a3);
    return 1;
    }
    return 0;
}

