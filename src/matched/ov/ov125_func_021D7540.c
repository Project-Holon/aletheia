/*
 * unit: yes
 * function: func_021D7540, func_021D75C0
 * address: 0x021D7540
 * packet: pkt_ov125_021D7540
 * region: ov125
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_0214616C 0x0214616C data a4
 *   func_0203F1FC 0x0203F1FC arm
 */
typedef unsigned short u16;
extern char *d_0214616C;
extern int func_0203F1FC(void *, int);
extern void func_0200B908(void *, int, unsigned int);
extern int func_0200B67C(int, void *, int, int, u16);
int func_021D7540(int a, int x, int mode, u16 *state, int b, u16 c)
{
    unsigned int value;
    switch (*state) {
    case 0:
        if (mode == 1) {
            *(unsigned char *)(d_0214616C + 0xaa) = mode;
            *(u16 *)(d_0214616C + 0xa8) = 57985;
            *(u16 *)(d_0214616C + 0xc0) = func_0203F1FC(d_0214616C + 0x80, 56);
        }
        value = *(u16 *)(d_0214616C + 0x18a0);
        func_0200B908(d_0214616C + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
        ++*state;
        break;
    case 1:
        return func_0200B67C(a, d_0214616C, x, b, c);
    }
    return 0;
}
void func_021D75C0(void)
{
    unsigned int value;
    value = *(u16 *)(d_0214616C + 0x18a0);
    func_0200B908(d_0214616C + 0xc4, 0x17dc, value + ((value ^ 0xffff) << 16));
}
