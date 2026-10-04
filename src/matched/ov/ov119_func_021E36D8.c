/*
 * function: func_021E36D8
 * address:  0x021E36D8
 * packet:   pkt_ov119_021E36D8
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02015EA0  0x02015EA0  thumb
 *   func_02015BA4  0x02015BA4  thumb
 *
 * Teardown of one slot of the 0x844 vector: releases it through
 * func_02015EA0, hands (the shared 0x840 handle, the slot value) to
 * func_02015BA4, then clears the slot.
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00001.h"

typedef unsigned int u32;

extern void func_02015EA0(void *p);
extern void func_02015BA4(void *sys, void *obj);

void func_021E36D8(void *p, int idx)
{
    u32 v = ((u32 *)((char *)p + 0x844))[idx];

    if (v != 0) {
        func_02015EA0((void *)v);
        func_02015BA4((void *)(*(u32 *)&((struct Obj00001 *)p)->f840), (void *)(((u32 *)((char *)p + 0x844))[idx]));
        ((u32 *)((char *)p + 0x844))[idx] = 0;
    }
}
