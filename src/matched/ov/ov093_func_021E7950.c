/*
 * function: func_021E7950
 * address: 0x021E7950
 * packet: pkt_ov093_021E7950
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E7924.c and filed here.
 *
 * symbols:
 *   d_021F2998 0x021F2998 data ov093 a4
 */

int *func_021E7950(int *p);

/*
 * Leaf with no calls and no pool; 10 instructions, 24 bytes: push {r4, lr}; movs r0, #3; adds r4, r2, #0; bl func_021D775C; cmp r4, r0; bne loc_021E7972; movs r0, #0x51; movs r1, #1; bl func_021D76BC; pop {r4, pc}.
 */
extern int d_021F2998[];

int *func_021E7950(int *p)
{
    *p = 2;
    return d_021F2998;
}
