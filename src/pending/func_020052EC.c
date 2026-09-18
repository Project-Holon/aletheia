/*
 * function: func_020052EC
 * address:  0x020052EC
 * packet:   pkt_0200520C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker:  02023FD8, 0200F734, 02026728 and 02010DCC (all arm) each reached only by the `bl` inside this function, so `label` has no witness outside the compared range; all 32 concrete bytes are right
 *
 * symbols:
 *   func_02023FD8  0x02023FD8  thumb
 *   func_02022174  0x02022174  thumb
 *   func_0200F734  0x0200F734  thumb
 *   func_02005BC0  0x02005BC0  thumb
 *   func_020065FC  0x020065FC  thumb
 *   func_02026728  0x02026728  thumb
 *   func_02010DCC  0x02010DCC  thumb
 *
 * Seven unconditional calls in a row, no arguments and no return value: the
 * tail of the boot sequence, run immediately after func_0200520C.  Every
 * callee is an ordinary Thumb `bl` (the second halfword's bit 12 is set in
 * all seven encodings, so none of them is a BLX to ARM code).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020052EC.c \
 *       --func func_020052EC --addr 0x020052EC --cc 1.1p1 --thumb
 */

extern void func_02023FD8(void);
extern void func_02022174(void);
extern void func_0200F734(void);
extern void func_02005BC0(void);
extern void func_020065FC(void);
extern void func_02026728(void);
extern void func_02010DCC(void);

void func_020052EC(void)
{
    func_02023FD8();
    func_02022174();
    func_0200F734();
    func_02005BC0();
    func_020065FC();
    func_02026728();
    func_02010DCC();
}
