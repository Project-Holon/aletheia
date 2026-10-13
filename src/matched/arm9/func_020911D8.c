/*
 * function: func_020911D8
 * address:  0x020911D8
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  +0012 THM_CALL func_020911F0       -> unresolved: 020911F0 (thumb, from header) has no witness outside 020911D8..020911F0
 *
 * symbols:
 *   OSi_IsRunOnTwl    0x02085D88  arm
 *   OS_Terminate    0x02088234  arm
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

extern int OSi_IsRunOnTwl(void);
extern void OS_Terminate(void);
extern void func_020911F0(u32 a);

void func_020911D8(u32 a)
{
    if (OSi_IsRunOnTwl() == 0) {
        OS_Terminate();
    }
    func_020911F0(a);
}
