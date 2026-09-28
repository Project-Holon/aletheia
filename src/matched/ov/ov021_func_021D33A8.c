/*
 * function: func_021D33A8
 * address:  0x021D33A8
 * packet:   pkt_ov021_021D33A8
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: target named by the parked ov021 func_021881D8
 * (+0110 region) and part of the field_palace_sys.c tree
 * (layout/file_anchors.txt row 021D33DC -> 0x021DE6D4).  Allocates a 0xc-byte
 * record through the debug allocator, fills two words and a zero, and hands
 * it to func_021D33FC.
 *
 * symbols:
 *   sub_02030734    0x02030734  arm
 *   func_021D33FC   0x021D33FC  thumb  ov021
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *sub_02030734(u32, u32, int, const char *, u32);
extern void func_021D33FC(void *, int, int);

void *func_021D33A8(u32 heapId, void *a1, void *a2, int a3)
{
    void *p = sub_02030734(heapId, 0xc, 1, (const char *)0x021DE6D4, 0x43);

    *(u32 *)p = (u32)a1;
    *(u32 *)((char *)p + 4) = (u32)a2;
    *(u32 *)((char *)p + 8) = 0;
    func_021D33FC(p, a3, heapId);
    return p;
}
