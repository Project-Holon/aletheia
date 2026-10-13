/*
 * function: BTL_HANDLER_TOKUSEI_AddImposter
 * address: 0x021DCDB8
 * packet: pkt_ov093_021DCDB8
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
 *   gHandlerTableImposter 0x021F0750 data ov093 a4
 */

int *BTL_HANDLER_TOKUSEI_AddImposter(int *p);
extern int gHandlerTableImposter[];

/*
 * Allocate 76 bytes, keep the handle, then configure it.
 */
int *BTL_HANDLER_TOKUSEI_AddImposter(int *p)
{
    *p = 1;
    return gHandlerTableImposter;
}
