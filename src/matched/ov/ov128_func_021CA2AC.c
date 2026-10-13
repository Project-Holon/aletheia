/*
 * function: func_021CA2AC
 * address:  0x021CA2AC
 * packet:   pkt_021CA2AC
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021CA25C  0x021CA25C  thumb
 *   BLINK_PALANM_ResetPhase  0x0202EB04  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14051.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct CodeIn;
extern void func_021CA25C(u32 a, u32 b);
extern void BLINK_PALANM_ResetPhase(struct CodeIn *p);

void func_021CA2AC(u8 *p, int a)
{
    func_021CA25C(a, 3);
    BLINK_PALANM_ResetPhase(((struct Obj14051 *)p)->f184);
}
