/*
 * function: func_021E10CC
 * address: 0x021E10CC
 * packet: pkt_ov093_021E10CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0F50.c and filed here.
 *
 * symbols:
 *   d_021F263C 0x021F263C data ov093 a4
 */

int *func_021E10CC(int *p);
extern int d_021F263C[];

/*
 * sdk:      DWC_GdbInitialize (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 */
int *func_021E10CC(int *p)
{
    *p = 1;
    return d_021F263C;
}
