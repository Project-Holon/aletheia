/*
 * function: MSL_C_LIB_TwlCall2
 * address:  0x02091230
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  +0016 THM_CALL func_0209124C       -> unresolved: 0209124C (thumb, from header) has no witness outside 02091230..0209124C
 *
 * symbols:
 *   OSi_IsRunOnTwl    0x02085D88  arm
 *   OS_Terminate    0x02088234  arm
 *   func_0209124C    0x0209124C  thumb
 *
 * Two-argument flavour of MSL_C_LIB_TwlCall1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_TwlCall2.c \
 *       --func MSL_C_LIB_TwlCall2 --addr 0x02091230 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern int OSi_IsRunOnTwl(void);
extern void OS_Terminate(void);
extern void func_0209124C(u32 a, u32 b);

void MSL_C_LIB_TwlCall2(u32 a, u32 b)
{
    if (OSi_IsRunOnTwl() == 0) {
        OS_Terminate();
    }
    func_0209124C(a, b);
}
