/*
 * function: func_02091200
 * address:  0x02091200
 * packet:   pkt_020911D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  +001A THM_CALL func_02091220       -> unresolved: 02091220 (thumb, from header) has no witness outside 02091200..02091220
 *
 * symbols:
 *   func_02085D88    0x02085D88  arm
 *   func_02088234    0x02088234  arm
 *   func_02091220    0x02091220  thumb
 *
 * Three-argument flavour of func_020911D8.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02091200.c \
 *       --func func_02091200 --addr 0x02091200 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

extern u32  func_02085D88(void);
extern void func_02088234(void);
extern void func_02091220(u32 a, u32 b, u32 c);

void func_02091200(u32 a, u32 b, u32 c)
{
    if (func_02085D88() == 0) {
        func_02088234();
    }
    func_02091220(a, b, c);
}
