/*
 * function: func_022110F8
 * address: 0x022110F8
 * packet: pkt_ov198_022110F8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;

void func_022110F8(u8 *p, int a, int b)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        u8 *q = p + i * 4;
        if (*(u16 *)(q + 0x249c) == 0xff) {
            *(u16 *)(q + 0x249c) = a;
            *(u16 *)(q + 0x249e) = b;
            return;
        }
    }
}
