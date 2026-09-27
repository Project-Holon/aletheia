/*
 * function: func_021BA2BC
 * address:  0x021BA2BC
 * packet:   pkt_ov217_021BA2BC
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  each arm must be emitted as its own complete call+return
 *           sequence (case 0 at +0x10, case 1 at +0x1e), while the natural
 *           if/else shares one tail. Original holds the 5th/6th call
 *           arguments in r0/r5. Tried if/else and local args; both tail-merge.
 *
 * symbols:
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 */

extern void func_020413B0(int, int, int, int, int, int);
extern void func_020409B4(int);

void func_021BA2BC(int sel)
{
    if (sel == 0) {
        func_020413B0(2, 3, 5, 0x1a, 5, 5);
        func_020409B4(2);
    } else if (sel == 1) {
        func_020413B0(2, 3, 0xc, 0x1a, 5, 6);
        func_020409B4(2);
    }
}
