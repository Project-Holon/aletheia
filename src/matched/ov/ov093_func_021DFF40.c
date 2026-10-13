/*
 * function: HAND_ITEM_GetElectricGemHandlers
 * address: 0x021DFF40
 * packet: pkt_ov093_021DFF40
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021DFCE8.c and filed here.
 *
 * symbols:
 *   gHandItemElectricGemHandlers 0x021F1874 data ov093 a4
 */

int *HAND_ITEM_GetElectricGemHandlers(int *p);

/* 021DFF4C  stack-arg wrapper: HAND_ITEM_GemMovePower(a, b, c, d, 0xc) */
extern int gHandItemElectricGemHandlers[];

/*
 * 2026-10-02: the 02045CAC/0201F250/021E0FF4 statements are repeated in both arms of
 *  the 0x11EE test (the compiler tail-merges them), which keeps the 0x834 and 0x724
 *  constants live into the merged tail.
 */
int *HAND_ITEM_GetElectricGemHandlers(int *p)
{
    *p = 3;
    return gHandItemElectricGemHandlers;
}
