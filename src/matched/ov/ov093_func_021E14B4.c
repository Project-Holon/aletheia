/*
 * function: func_021E14B4
 * address: 0x021E14B4
 * packet: pkt_ov093_021E14B4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E1478.c and filed here.
 *
 * symbols:
 *   d_021F26EC 0x021F26EC data ov093 a4
 */

int *func_021E14B4(int *p);

/* 021E14C0  shape F1: gate on func_021D775C(3) */
extern int d_021F26EC[];

int *func_021E14B4(int *p)
{
    *p = 1;
    return d_021F26EC;
}
