/*
 * function: func_021B7714
 * address: 0x021B7714
 * packet: pkt_ov172_021B7714
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
void func_021B7714(void *a, char *b, int c)
{
    *(u8 *)(b + 0x10) |= (u8)(1 << c);
}
