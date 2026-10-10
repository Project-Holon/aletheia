/*
 * function: func_021E192C
 * address: 0x021E192C
 * packet: pkt_ov093_021E192C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E18EC.c and filed here.
 *
 * symbols:
 *   d_021F2C00 0x021F2C00 data ov093 a4
 */

int *func_021E192C(int *p);

/*
 * Leaf with no calls and no pool; 7 instructions, 16 bytes: push {r3, lr}; adds r0, r1, #0; adds r1, r2, #0; adds r2, r3, #0; movs r3, #1; bl func_021E19F8; pop {r3, pc}.
 */
extern int d_021F2C00[];

int *func_021E192C(int *p)
{
    *p = 3;
    return d_021F2C00;
}
