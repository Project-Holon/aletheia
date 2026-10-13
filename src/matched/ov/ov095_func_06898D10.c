/*
 * function: HAND_SIDE_Remove
 * address: 0x06898D10
 * packet: pkt_ov095_06898D10
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gHandSideEffectSlots 0x0689E7E0 data a4
 *   func_06898D44 0x06898D44 thumb ov095
 */

#include "../include/G_Row.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Node Node;
extern struct Row gHandSideEffectSlots;
extern void func_06898D44(Node *n);
int HAND_SIDE_Remove(u32 a, u32 b)
{
    u32 *p;
    p = (u32 *)((u32)((u8 *)&gHandSideEffectSlots) + a * 224 + b * 16);
    if (p[0] != 0) {
        func_06898D44((Node *)p[0]);
        p[0] = 0;
        p[3] = 0;
        p[1] &= ~7;
        return 1;
    }
    return 0;
}
