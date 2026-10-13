/*
 * function: func_021BC610
 * address:  0x021BC610
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Reconstructed from the listing.
 *
 * symbols:
 *   func_021BC610  0x021BC610  thumb  ov217
 *   PALANM_TransferPalettes  0x02021D50  thumb  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj25865.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);
extern void func_020419E4();
extern void func_0204A648();
void func_021BC610(u32 a0, u32 a1)
{
    func_020419E4();
    func_0204A648();
    PALANM_TransferPalettes((struct S02021D50 *)(((struct Obj25865 *)((u8*)a1 + 0))->f98));
}

