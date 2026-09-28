/*
 * function: func_021BAB20
 * address:  0x021BAB20
 * packet:   pkt_ov088_021BAB20
 * region:   ov088
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent runs two bytes long; the follower at 0x021BAB62 is
 * an unlabelled leaf (no lr save) that disasm.py did not label.
 *
 * symbols:
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 */

extern void func_020434DC(int, int);
extern void func_02043598(int, int);
extern void func_020403F4(int);
extern void func_0203F9B4(void);

void func_021BAB20(void)
{
    func_020434DC(0xf, 0);
    func_02043598(7, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}
