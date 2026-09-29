/*
 * function: func_021B64D0
 * address:  0x021B64D0
 * packet:   pkt_ov071_021B64D0
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020433E0  0x020433E0  arm
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_02082A7C  0x02082A7C  arm
 *   d_021BA7D4     0x021BA7D4  data  ov071  a4
 *   d_021BA764     0x021BA764  data  a4
 */

extern char d_021BA7D4;
extern char d_021BA764;

void func_021B64D0(void)
{
    void func_020433E0(void *);
    void func_0203F8F4(int);
    void func_0203FC28(void *);
    void func_02082A7C(int, int, int);

    func_020433E0(&d_021BA7D4);
    func_0203F8F4(0x61);
    func_0203FC28(&d_021BA764);
    func_02082A7C(0, 0x06000000, 0x80000);
    func_02082A7C(0, 0x06200000, 0x20000);
    func_02082A7C(0, 0x06400000, 0x40000);
    func_02082A7C(0, 0x06600000, 0x20000);
}
