/*
 * function: func_021B6790
 * address:  0x021B6790
 * packet:   pkt_ov071_021B6790
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0203101C  0x0203101C  arm
 *   func_0201D7EC  0x0201D7EC  thumb
 *   func_0201C440  0x0201C440  thumb
 *   func_0201EC64  0x0201EC64  thumb
 *   func_02045B38  0x02045B38  arm
 */

void func_021B6790(int *p)
{
    void func_0201DD78(int, int, int);
    int func_0203101C(int, int, int, int);
    int func_0201D7EC(int, int, int, int, int);
    int func_0201C440(int);
    int func_0201EC64(int);
    int func_02045B38(int, int, int, int);

    func_0201DD78(0xf, 2, 0);
    p[6] = func_0203101C(0x61, 0x61, 4, 0x20);
    p[3] = func_0201D7EC(0x17, 0, 0, 0, 0x61);
    p[2] = func_0201C440(0x61);
    p[4] = func_0201EC64(0x61);
    p[7] = func_02045B38(0, 2, 0x43, 0x61);
    p[8] = func_02045B38(0, 2, 0xa0, 0x61);
    p[9] = func_02045B38(0, 2, 0xa1, 0x61);
    p[10] = func_02045B38(0, 2, 0x45, 0x61);
}
