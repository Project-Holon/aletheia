/*
 * function: func_021D9234
 * address: 0x021D9234
 * packet: pkt_ov093_021D9234
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
 *   d_021F0890 0x021F0890 data ov093 a4
 */

int *func_021D9234(int *p);

/* 021D9240  shifted 4-arg wrapper -> func_021D928C(..., 0x6) */
extern int d_021F0890[];

int *func_021D9234(int *p)
{
    *p = 2;
    return d_021F0890;
}
