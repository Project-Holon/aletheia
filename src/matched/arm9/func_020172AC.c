/*
 * function: func_020172AC
 * address:  0x020172AC
 * packet:   pkt_020172AC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02014CF0  0x02014CF0  thumb
 *
 * A four-instruction tail call: the second argument is replaced by a function
 * pointer (the pool word 0x020172BD, the Thumb bit set), the first and third
 * pass through, and the target is loaded from the pool and branched to with
 * `bx r3`.  The callee is the label-less Thumb leaf src/matched/sub_02014CF0.c.
 *
 * The `symbols:` line is load-bearing.  Without it the name `func_02014CF0`
 * carries the address but the naming convention can only guess the ISA, and
 * an address no `func_` label was traced at is guessed ARM -- so the site
 * was reported as "02014CF0 (arm, from name) has no witness" and the file sat
 * at MATCH, because sub_02014CF0 is a Thumb manifest entry and the `matched`
 * class refuses an ISA that does not agree with it.  Declaring the ISA
 * explicitly (origin "header") resolves the word to 0x02014CF1, which is what
 * the image holds.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020172AC.c \
 *       --func func_020172AC --addr 0x020172AC --cc 1.1p1 --thumb
 */

extern void sub_02014CF0(int a0, int a1, int a2);
extern void func_020172BC(void);

void func_020172AC(int a0, int a1)
{
    sub_02014CF0(a0, (int)func_020172BC, a1);
}
