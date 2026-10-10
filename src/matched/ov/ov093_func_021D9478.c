/*
 * function: func_021D9478
 * address: 0x021D9478
 * packet: pkt_ov093_021D9478
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D93D8.c and filed here.
 *
 * symbols:
 *   d_021F0D3C 0x021F0D3C data ov093 a4
 */

int *func_021D9478(int *p);

/* 021D9484  shape F5: out-param store of func_021D9648(..., 3) */
extern int d_021F0D3C[];

int *func_021D9478(int *p)
{
    *p = 6;
    return d_021F0D3C;
}
