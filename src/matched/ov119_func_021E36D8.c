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

typedef unsigned int u32;

extern void func_02015EA0(u32);
extern void func_02015BA4(u32, u32);

void func_021E36D8(void *p, int idx)
{
    u32 v = ((u32 *)((char *)p + 0x844))[idx];

    if (v != 0) {
        func_02015EA0(v);
        func_02015BA4(*(u32 *)((char *)p + 0x840), ((u32 *)((char *)p + 0x844))[idx]);
        ((u32 *)((char *)p + 0x844))[idx] = 0;
    }
}
