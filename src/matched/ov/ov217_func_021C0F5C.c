/*
 * function: func_021C0F5C
 * address:  0x021C0F5C
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
 *   func_021C0F78  0x021C0F78  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26005.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_020307B0();
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct U16Vec;
extern void func_021C0F78(u8 *p, struct U16Vec *text);
u32 func_021C0F5C(u32 a0, u32 a1)
{
    u32 v1 = (u32)func_02045EC0((struct MsgBank *)(((struct Obj26005 *)(((u8*)a0)))->f14), a1);
    func_021C0F78((u8 *)a0, (void *)v1);
    return func_020307B0(v1);
}

