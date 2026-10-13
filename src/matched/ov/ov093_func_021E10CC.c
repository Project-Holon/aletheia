/*
 * function: HAND_WAZA_GetTriAttackHandlers
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
 *   gTriAttackHandlers 0x021F263C data ov093 a4
 */

int *HAND_WAZA_GetTriAttackHandlers(int *p);
extern int gTriAttackHandlers[];

/*
 * sdk:      DWC_GdbInitialize (libdwcgdb.TWL.HYB.a(dwc_gdb.o))
 */
int *HAND_WAZA_GetTriAttackHandlers(int *p)
{
    *p = 1;
    return gTriAttackHandlers;
}
