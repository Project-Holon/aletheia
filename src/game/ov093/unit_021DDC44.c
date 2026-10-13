/*
 * file:     unit_021DDC44.c
 * function: func_021DDC44, func_021DDC58
 * address:  0x021DDC44
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F181C     0x021F181C  data   ov093  a4
 *   func_021DDC44   0x021DDC44  thumb
 *   func_021DDCD8   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #7; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
#include "unit_021DDC44_types.h"

extern int func_021DDCD8(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work, u8 moveType, int ignoreAffinity);
extern int d_021F181C[];

void func_021DDC44(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work);
int *func_021DDC58(int *handlerCount);

/* Kasib Berry: halves a Ghost hit that is super effective. */
void func_021DDC44(struct BtlEventFactor *factor, struct BtlSvFlow *flow, int pokeId, int *work)
{
    func_021DDCD8(factor, flow, pokeId, work, POKETYPE_GHOST, 0);
}

/* Handler table getter of Haban Berry. */
int *func_021DDC58(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F181C;
}
