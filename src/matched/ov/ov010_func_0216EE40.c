/*
 * function: func_0216EE40
 * address:  0x0216EE40
 * packet:   pkt_ov010_0216EE40
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reports the species of the first party member to one of three
 * notifiers.
 *
 * MATCH, first draft (2026-09-28 tree_ov010_4): the one wildcard is arm9
 * 0x0201313C, an unlabelled Thumb leaf (`lsls r1, #2; adds r0, r1;
 * ldr r0, [r0, #0x24]; bx lr`) inside the listing's ARM data run.
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 func_0201313C (matched file exists, no shard yet); integrator shard resolves it.
 *
 * symbols:
 *   func_0201313C  0x0201313C  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0216505C  0x0216505C  thumb  ov010
 *   func_02165078  0x02165078  thumb  ov010
 *   func_021653F4  0x021653F4  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0201313C(void *p, u32 a);
extern void *func_0201AB28(void *party, int i);
extern u32 func_02017E1C(void *mon, u32 id, void *arg);
extern void func_0216505C(u16 species);
extern void func_02165078(u16 species);
extern void func_021653F4(u16 species);

void func_0216EE40(void *p, int which)
{
    u16 species;

    species = func_02017E1C(func_0201AB28(func_0201313C(p, 1), 0), 5, 0);
    switch (which) {
    case 0:
        func_0216505C(species);
        break;
    case 1:
        func_02165078(species);
        break;
    case 2:
        func_021653F4(species);
        break;
    }
}
