/*
 * function: HAND_WAZA_AddStoredPower
 * address: 0x021E7074
 * packet: pkt_ov093_021E7074
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov093/unit_021E700C.c and filed here.
 *
 * symbols:
 *   d_021F267C 0x021F267C data ov093 a4
 */

int *HAND_WAZA_AddStoredPower(int *p);

/*
 * note:     the bonus is a compound add onto the fetched value
 *           (`t = get(0x30); t += sum * 0x14; set(0x30, t);`): it copies sum
 *           into r1 and multiplies by 0x14 held in r0 like the image; every
 *           single-expression spelling (`t + sum * 0x14`, an inline helper,
 *           a narrow or enum multiplier local) multiplies in the constant's
 *           register and is 4 bytes short.  HAND_WAZA_AddHeavySlam is the unlabelled
 *           12-byte store-and-return leaf after the pool (twin of
 *           ov093_func_021E7164.c's HAND_WAZA_AddEchoedVoice).
 */
extern int d_021F267C[];

int *HAND_WAZA_AddStoredPower(int *p)
{
    *p = 1;
    return d_021F267C;
}
