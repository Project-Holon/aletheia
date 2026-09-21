/*
 * function: func_0209125C
 * address:  0x0209125C
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocker:  +0022 THM_CALL func_02091284       -> unresolved: 02091284 (arm, from header) has no witness outside 0209125C..02091284
 *
 * symbols:
 *   func_02085D88    0x02085D88  arm
 *   func_02088234    0x02088234  arm
 *   func_02091284    0x02091284  arm
 *
 * Five-argument flavour: the fifth parameter is spilled back to [sp] for the
 * ARM-side callee, which is why the frame carries one extra word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0209125C.c \
 *       --func func_0209125C --addr 0x0209125C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32  func_02085D88(void);
extern void func_02088234(void);
extern void func_02091284(u32 a, u32 b, u32 c, u32 d, u32 e);

void func_0209125C(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    if (func_02085D88() == 0) {
        func_02088234();
    }
    func_02091284(a, b, c, d, e);
}
