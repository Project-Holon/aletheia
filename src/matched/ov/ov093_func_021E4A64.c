/*
 * function: func_021E4A64
 * address: 0x021E4A64
 * packet: pkt_ov093_021E4A64
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E492C.c and filed here.
 *
 * symbols:
 *   d_021F2744 0x021F2744 data ov093 a4
 */

int *func_021E4A64(int *p);
extern int d_021F2744[];

/*
 * Sibling of src/matched/ov170_func_021E2650.c and ov170_func_021E376C.c.
 * The image computes r + 0x1E
 * separately for func_021DEFEC and for the call after it; the (int) cast on
 * the first keeps the two expressions apart so they are not CSEd.
 */
int *func_021E4A64(int *p)
{
    *p = 1;
    return d_021F2744;
}
