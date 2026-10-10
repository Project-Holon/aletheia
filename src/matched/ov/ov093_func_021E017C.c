/*
 * function: func_021E017C
 * address: 0x021E017C
 * packet: pkt_ov093_021E017C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFCE8.c and filed here.
 *
 * symbols:
 *   d_021F19F4 0x021F19F4 data ov093 a4
 */

int *func_021E017C(int *p);

/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, r4, lr}; sub sp, #4; movs r4, #8; str r4, [sp]; bl func_021E0284; add sp, #4; pop {r3, r4, pc}.
 */
extern int d_021F19F4[];

int *func_021E017C(int *p)
{
    *p = 3;
    return d_021F19F4;
}
