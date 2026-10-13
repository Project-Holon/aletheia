/*
 * file:     unit_021DDC84.c
 * function: func_021DDC84, func_021DDC98
 * address:  0x021DDC84
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F183C     0x021F183C  data   ov093  a4
 *   func_021DDC84   0x021DDC84  thumb
 *   func_021DDCD8   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0x10; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
#include "unit_021DDC44_types.h"

extern int func_021DDCD8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity);
extern int d_021F183C[];

void func_021DDC84(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *func_021DDC98(int *handlerCount);

/* Colbur Berry: halves a Dark-type hit that is super effective. */
void func_021DDC84(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    func_021DDCD8(factor, flow, pokeId, work, POKETYPE_DARK, 0);
}

/* Handler table getter of Babiri Berry. */
int *func_021DDC98(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F183C;
}
