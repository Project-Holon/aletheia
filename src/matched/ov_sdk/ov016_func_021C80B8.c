/*
 * function: func_021C80B8
 * address:  0x021C80B8
 * packet:   pkt_ov016_021C80B8
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      procInit (libdwcutil.TWL.HYB.a sceneseterror.o)
 *
 * symbols:
 *   func_021D55A4  0x021D55A4  arm  ov016
 *   func_021D603C  0x021D603C  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C80F4  0x021C80F4  arm  ov016
 */

extern void func_021D55A4();
extern void func_021D603C(int lcd, int plane);
extern void func_021C0E40();
extern void func_021C80F4();

void func_021C80B8(void)
{
    func_021D55A4(2, 0, 0x15, 8);
    func_021D603C(0, 0x15);
    func_021C0E40(func_021C80F4);
}
