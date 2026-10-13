/*
 * function: HAND_TOKUSEI_AddShellArmor
 * address: 0x021D9BBC
 * packet: pkt_ov093_021D9BBC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021D9ADC.c and filed here.
 *
 * symbols:
 *   d_021F0868 0x021F0868 data ov093 a4
 */

int *HAND_TOKUSEI_AddShellArmor(int *p);
extern int d_021F0868[];

int *HAND_TOKUSEI_AddShellArmor(int *p)
{
    *p = 1;
    return d_021F0868;
}
