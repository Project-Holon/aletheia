/*
 * function: func_021895AC
 * address: 0x021895AC
 * packet: pkt_ov096_021895AC
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02011290 0x02011290 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02011290(u8 *);
int func_021895AC(u8 *a, u8 *b)
{
    b[0x44] |= 1; func_02011290(a); return 1;
}
