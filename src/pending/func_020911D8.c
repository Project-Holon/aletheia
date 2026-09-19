/*
 * function: func_020911D8
 * address:  0x020911D8
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  +0012 THM_CALL func_020911F0       -> unresolved: 020911F0 (thumb, from header) has no witness outside 020911D8..020911F0
 *
 * symbols:
 *   func_02085D88    0x02085D88  arm
 *   func_02088234    0x02088234  arm
 *   func_020911F0    0x020911F0  thumb
 *
 * Thumb wrapper over the ARM-side entry: aborts when the check fails, then
 * hands the argument across the Thumb/ARM stub at 0x020911F0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020911D8.c \
 *       --func func_020911D8 --addr 0x020911D8 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32  func_02085D88(void);
extern void func_02088234(void);
extern void func_020911F0(u32 a);

void func_020911D8(u32 a)
{
    if (func_02085D88() == 0) {
        func_02088234();
    }
    func_020911F0(a);
}
