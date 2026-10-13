/*
 * function: HAND_WAZA_AddMirrorCoat
 * address: 0x021E1970
 * packet: pkt_ov093_021E1970
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E18EC.c and filed here.
 *
 * symbols:
 *   gMirrorCoatHandlers 0x021F2C18 data ov093 a4
 */

int *HAND_WAZA_AddMirrorCoat(int *p);

/* 021E197C  shifted 4-arg wrapper -> HAND_WAZA_RetaliateOnMoveFailCheck(..., 0x2) */
extern int gMirrorCoatHandlers[];

int *HAND_WAZA_AddMirrorCoat(int *p)
{
    *p = 3;
    return gMirrorCoatHandlers;
}
