/*
 * function: func_021E71F0
 * address:  0x021E71F0
 * packet:   pkt_021E71F0
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E7220  0x021E7220  thumb  ov119
 *   func_020056BC  0x020056BC  thumb
 *
 * func_020056BC (ARM9, unlabelled Thumb leaf) was filed EXACT by the
 * dependency-tree lane and now attests this call through `matched`.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 func_020056BC(void);
extern void func_02030DA8(u32, void (*)(void), int, int);
extern void func_021E7220(void *p, int a);

void func_021E71F0(void *p, int a)
{
    func_02030DA8(func_020056BC(), (void (*)(void))func_021E7220, a, 0xa);
}
