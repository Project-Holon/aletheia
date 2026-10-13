/*
 * function: HAND_WAZA_GetTrickRoomHandlers
 * address: 0x021E05A4
 * packet: pkt_ov093_021E05A4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E0518.c and filed here.
 *
 * symbols:
 *   gTrickRoomHandlers 0x021F26F4 data ov093 a4
 */

int *HAND_WAZA_GetTrickRoomHandlers(int *p);
extern int gTrickRoomHandlers[];

int *HAND_WAZA_GetTrickRoomHandlers(int *p)
{
    *p = 1;
    return gTrickRoomHandlers;
}
