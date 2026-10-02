/*
 * function: func_02175184
 * address: 0x02175184
 * packet: pkt_ov011_02175184
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
int func_02175184(u8 *a, u8 *b)
{
    if (*(u16 *)a == *(u16 *)b) return 0;
    if (a[2] != b[2] && a[3] == b[3]) return 1;
    return 2;
}
