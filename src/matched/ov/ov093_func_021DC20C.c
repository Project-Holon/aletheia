/*
 * function: func_021DC20C
 * address: 0x021DC20C
 * packet: pkt_ov093_021DC20C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DC13C.c and filed here.
 *
 * symbols:
 *   gHealerHandlers 0x021F0778 data ov093 a4
 */

int *func_021DC20C(int *p);
extern int gHealerHandlers[];

int *func_021DC20C(int *p)
{
    *p = 1;
    return gHealerHandlers;
}
