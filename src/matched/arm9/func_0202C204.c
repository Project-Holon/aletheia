/*
 * function: ISS_SWITCH_SYS_TurnOff
 * address:  0x0202C204
 * packet:   pkt_0202C148
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Clears the object's first word when it is non-zero.  Unlabelled in the
 * listing (no lr save) and absent from the worklist; filed from the bytes.
 * It is the tail-call target of the thunk at 0x0202C0C0, which is what
 * src/pending/ISS_SYS_UpdateSwitch.c is blocked on.
 *
 * symbols:
 *   sub_0202C2D8  0x0202C2D8  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_TurnOff.c \
 *       --func ISS_SWITCH_SYS_TurnOff --addr 0x0202C204 --thumb --cc 1.1p1
 */

typedef unsigned int u32;

extern u32 sub_0202C2D8(u32 *p);

void ISS_SWITCH_SYS_TurnOff(u32 *p)
{
    if (sub_0202C2D8(p) != 0) {
        *p = 0;
    }
}
