/*
 * function: func_021B9D34
 * address: 0x021B9D34
 * packet: pkt_ov181_021B9D34
 * region: ov181
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Padding: two zero bytes at 0x021B9DAE, then the next function.
 * symbols:
 *   func_02045088 0x02045088 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
extern void func_02045088(unsigned short);
extern unsigned func_020450F0(unsigned, unsigned, unsigned, unsigned, unsigned char, unsigned char, unsigned char);
extern void func_02045334(unsigned);
extern void func_02045374(unsigned);
extern unsigned char func_02045730(unsigned);
extern void func_020409B4(unsigned);
void func_021B9D34(char *p)
{
    unsigned h;
    func_02045088(0x8E);
    *(unsigned *)(p + 0x2BC) = func_020450F0(1, 0, 0, 0x20, 0x19, 0xF, 1);
    *(unsigned *)(p + 0x2C4) = func_020450F0(5, 0, 0, 0x20, 0x1C, 0xF, 1);
    h = *(unsigned *)(p + 0x2BC);
    func_02045334(h);
    func_02045374(h);
    func_020409B4(func_02045730(h));
    h = *(unsigned *)(p + 0x2C4);
    func_02045334(h);
    func_02045374(h);
    func_020409B4(func_02045730(h));
}
