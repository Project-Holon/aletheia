/*
 * function: func_021B9BD4
 * address:  0x021B9BD4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021B9C08  0x021B9C08  arm  ov114
 *
 *
 * Seeds a work record at +0x18, registers it, then arms the +0x2c timer.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021B9C08(int);
extern void func_02085710(void *);

void func_021B9BD4(int a, u8 *p)
{
    *(u32 *)(p + 0x18) = 1;
    func_021B9C08(a);
    func_02085710((char *)a + 0x2c);
}
