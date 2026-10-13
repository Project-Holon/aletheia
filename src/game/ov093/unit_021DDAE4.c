/*
 * file:     unit_021DDAE4.c
 * function: func_021DDAE4, func_021DDAF8
 * address:  0x021DDAE4
 * packet:   pkt_021D8684
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021F178C     0x021F178C  data   ov093  a4
 *   func_021DDAE4   0x021DDAE4  thumb
 *   func_021DDCD8   0x021DDCD8  thumb
 * Leaf with no calls and no pool; 9 instructions, 20 bytes: push {r4, lr}; sub sp, #8; movs r4, #0xa; str r4, [sp]; movs r4, #0; str r4, [sp, #4]; bl func_021DDCD8; add sp, #8; pop {r4, pc}.
 */
#include "unit_021DD588_types.h"

extern int func_021DDCD8(struct BtlEventFactor *factor, void *server, int pokeId, int *work, int moveType, int ignoreAffinity);

extern int d_021F178C[];

void func_021DDAE4(struct BtlEventFactor *factor, void *server, int pokeId, int *work);
int *func_021DDAF8(int *handlerCount);

void func_021DDAE4(struct BtlEventFactor *factor, void *server, int pokeId, int *work)
{
    func_021DDCD8(factor, server, pokeId, work, POKETYPE_WATER, 0);
}

int *func_021DDAF8(int *handlerCount)
{
    *handlerCount = 2;
    return d_021F178C;
}
