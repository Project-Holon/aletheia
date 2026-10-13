/*
 * function: HAND_WAZA_GetTelekinesisHandlers
 * address: 0x021E7F10
 * packet: pkt_ov093_021E7F10
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E7E58.c and filed here.
 *
 * symbols:
 *   gTelekinesisHandlers 0x021F29A8 data ov093 a4
 */

int *HAND_WAZA_GetTelekinesisHandlers(int *p);
extern int gTelekinesisHandlers[];

int *HAND_WAZA_GetTelekinesisHandlers(int *p)
{
    *p = 2;
    return gTelekinesisHandlers;
}
