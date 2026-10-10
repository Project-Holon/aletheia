/*
 * function: func_021D9538
 * address: 0x021D9538
 * packet: pkt_ov093_021D9538
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
 *   d_021F0C9C 0x021F0C9C data ov093 a4
 */

int *func_021D9538(int *p);

/* 021D9544  shape F5: out-param store of func_021D9648(..., 6) */
extern int d_021F0C9C[];

int *func_021D9538(int *p)
{
    *p = 5;
    return d_021F0C9C;
}
