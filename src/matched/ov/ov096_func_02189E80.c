/*
 * function: func_02189E80
 * address: 0x02189E80
 * packet: pkt_ov096_02189E80
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189E90 0x02189E90 thumb ov096
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02189E90(u8 *,u8 *,int);
int func_02189E80(u8 *a, u8 *b)
{
    func_02189E90(a,b,3); return *(int *)(b + 0xc4);
}
