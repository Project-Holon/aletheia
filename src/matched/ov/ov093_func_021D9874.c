/*
 * function: func_021D9874
 * address: 0x021D9874
 * packet: pkt_ov093_021D9874
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
 *   d_021F0670 0x021F0670 data ov093 a4
 */

int *func_021D9874(int *p);
extern int d_021F0670[];

/*
 * tail: 021D98B6..021D98B8 is two zero alignment bytes.
 */
int *func_021D9874(int *p)
{
    *p = 1;
    return d_021F0670;
}
