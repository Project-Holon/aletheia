/*
 * function: func_021BA228
 * address:  0x021BA228
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
 *   func_021BA284  0x021BA284  thumb  ov217
 *   func_021BA2BC  0x021BA2BC  thumb  ov217
 *   func_021BA388  0x021BA388  thumb  ov217
 *   func_021BA3E8  0x021BA3E8  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00511.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_020061E4(u32 a);
extern void func_021BA284(int sel);
extern void func_021BA2BC(int sel);
extern void func_021BA388(char *self, int d);
extern u32 func_021BA3E8();
u32 func_021BA228(u32 a0)
{
    func_021BA2BC(((struct Obj00511 *)(((u8*)a0)))->f28);
    func_021BA388((char *)a0, 1);
    func_021BA284(((struct Obj00511 *)(((u8*)a0)))->f28);
    func_020061E4(1352);
    return func_021BA3E8(a0, 1);
}

