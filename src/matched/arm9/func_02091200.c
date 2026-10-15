/*
 * function: MSL_C_LIB_TwlCall3
 * address:  0x02091200
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  +001A THM_CALL func_02091220       -> unresolved: 02091220 (thumb, from header) has no witness outside 02091200..02091220
 *
 * symbols:
 *   OSi_IsRunOnTwl    0x02085D88  arm
 *   OS_Terminate    0x02088234  arm
 *   func_02091220    0x02091220  thumb
 *
 * Three-argument flavour of MSL_C_LIB_TwlCall1.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/MSL_C_LIB_TwlCall3.c \
 *       --func MSL_C_LIB_TwlCall3 --addr 0x02091200 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern int OSi_IsRunOnTwl(void);
extern void OS_Terminate(void);
extern void func_02091220(u32 a, u32 b, u32 c);

void MSL_C_LIB_TwlCall3(u32 a, u32 b, u32 c)
{
    if (OSi_IsRunOnTwl() == 0) {
        OS_Terminate();
    }
    func_02091220(a, b, c);
}
