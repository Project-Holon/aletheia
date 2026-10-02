/*
 * function: func_021B841C
 * address: 0x021B841C
 * packet: pkt_ov067_021B841C
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
int func_021B841C(u8 *p, int n)
{
    if (n < 0) return *(s16 *)(p + 0x62);
    return *(u16 *)(p + 0x64) - *(s16 *)(p + 0x62);
}
