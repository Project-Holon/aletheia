/*
 * function: func_021FA528
 * address: 0x021FA528
 * packet: pkt_ov132_021FA528
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02005728 0x02005728 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern unsigned func_02005728(unsigned);
void func_021FA528(char *p)
{
    u8 i;
    for (i = 0; i < 60; i++) {
        char *q = p + i * 8;
        *(u8 *)(q + 0x205) = func_02005728(60) + 1;
        *(u8 *)(q + 0x204) = 255;
    }
}
