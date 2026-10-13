/*
 * function: HAND_WAZA_AddWonderRoom
 * address: 0x021E798C
 * packet: pkt_ov093_021E798C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E7924.c and filed here.
 *
 * symbols:
 *   d_021F269C 0x021F269C data ov093 a4
 */

int *HAND_WAZA_AddWonderRoom(int *p);

/*
 * BTLV_CORE_MakeSlotKind2Index returns a one-word struct: that is the `push {r3,..}; sub sp, #4`
 * frame word (docs/idioms/an-unused-frame-word-is-a-callee-returning-a-one-word-struct.md).
 */
extern int d_021F269C[];

int *HAND_WAZA_AddWonderRoom(int *p)
{
    *p = 1;
    return d_021F269C;
}
