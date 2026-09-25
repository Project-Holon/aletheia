/*
 * function: func_021E71F0
 * address:  0x021E71F0
 * packet:   pkt_021E71F0
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_021E7220  0x021E7220  thumb  ov119
 *
 * MATCH: byte-correct (24 bytes). func_020056BC (0x020056BC, ARM9) has no
 * witness outside this range; it belongs to the ARM9 lane.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_020056BC(void *);
extern void func_02030DA8(u32, void (*)(void), int, int);
extern void func_021E7220(void);

void func_021E71F0(void *p, int a)
{
    func_02030DA8(func_020056BC(p), func_021E7220, a, 0xa);
}
