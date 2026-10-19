/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x0202C470
 * packet:   pkt_0202C3A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: ISS_SWITCH_SET_UpdateSwitches
 *
 * symbols:
 *   sub_0202C510  0x0202C510  thumb
 *   sub_0202C580  0x0202C580  thumb
 *
 * One of the six blocked callers of the trampoline run at 0x0202C548.
 * The window-frame set has nine slots, held as a u32 array at offset 0x18
 * reached through sub_0202C510 (src/matched/unit_0202C510.c), and this is
 * the broadcast of one operation across all nine.
 *
 * What closed it: sub_0202C580 is one of the seven trampolines of
 * src/matched/unit_0202C558.c, whose `function:` list covers this address,
 * so the `matched` class witnesses the site. Before that file promoted
 * there was no witness at all, because a trampoline is never the target of
 * a second `bl`.
 *
 * The loop counter is signed: the bound test is `blt`, not `blo`, so `i`
 * cannot be the `u32` that sub_0202C510's index parameter is elsewhere,
 * and writing it unsigned is one byte wrong and nothing else.
 *
 * Matched as a one-function unit because the two bytes of `00 00` at
 * 0x0202C48A are the linker's inter-section fill before 0x0202C48C, so
 * `one` would report EXACT* for a padding gap rather than for an
 * unlabelled follower.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202C470.c \
 *       --addr 0x0202C470 --thumb
 */

typedef signed int s32;

struct Arr0202C510;
extern unsigned int sub_0202C510(struct Arr0202C510 *p, unsigned int idx);
typedef unsigned int   u32;
extern u32 sub_0202C580(void *p);

void ISS_SWITCH_SET_UpdateSwitches(void *p)
{
    s32 i;

    for (i = 0; i < 9; i++) {
        sub_0202C580((void *)sub_0202C510(p, i));
    }
}
