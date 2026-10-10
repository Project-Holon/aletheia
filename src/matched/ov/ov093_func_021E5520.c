/*
 * function: func_021E5520
 * address: 0x021E5520
 * packet: pkt_ov093_021E5520
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E54EC.c and filed here.
 *
 * symbols:
 *   d_021F2DF8 0x021F2DF8 data ov093 a4
 */

int *func_021E5520(int *p);
extern int d_021F2DF8[];

/*
 * volatile: 0x04000060 reread at 021E552E, 021E553E, 021E554A, 021E5556; 0x04000008 display register; 0x04000580 hardware store at 021E557A.
 */
int *func_021E5520(int *p)
{
    *p = 4;
    return d_021F2DF8;
}
