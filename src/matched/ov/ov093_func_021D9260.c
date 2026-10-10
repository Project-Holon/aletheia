/*
 * function: func_021D9260
 * address: 0x021D9260
 * packet: pkt_ov093_021D9260
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D9118.c and filed here.
 *
 * symbols:
 *   d_021F08A0 0x021F08A0 data ov093 a4
 */

int *func_021D9260(int *p);

/* 021D926C  shifted 4-arg wrapper -> func_021D928C(..., 0x8) */
extern int d_021F08A0[];

int *func_021D9260(int *p)
{
    *p = 2;
    return d_021F08A0;
}
