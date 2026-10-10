/*
 * function: func_021DCE90
 * address: 0x021DCE90
 * packet: pkt_ov093_021DCE90
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DCAE8.c and filed here.
 *
 * symbols:
 *   d_021F0760 0x021F0760 data ov093 a4
 */

int *func_021DCE90(int *p);

/*
 * lever: u8 result local reproduces 021DCEA6/021DCEA8 truncation in r0,
 * then shift-copy to r1; inline narrowing produced an extra register copy.
 */
extern int d_021F0760[];

int *func_021DCE90(int *p)
{
    *p = 1;
    return d_021F0760;
}
