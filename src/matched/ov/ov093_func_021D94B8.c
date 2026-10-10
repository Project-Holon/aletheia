/*
 * function: func_021D94B8
 * address: 0x021D94B8
 * packet: pkt_ov093_021D94B8
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
 *   d_021F0C4C 0x021F0C4C data ov093 a4
 */

int *func_021D94B8(int *p);

/* 021D94C4  shape F5: out-param store of func_021D9648(..., 5) */
extern int d_021F0C4C[];

/*
 * interfaces: named the callee's boolean return; the tail jump forwards it unchanged.
 */
int *func_021D94B8(int *p)
{
    *p = 5;
    return d_021F0C4C;
}
