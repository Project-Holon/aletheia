/*
 * function: func_02189F58
 * address: 0x02189F58
 * packet: pkt_ov096_02189F58
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189F98 0x02189F98 thumb ov096
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02189F98(u8 *,u8 *,int);
int func_02189F58(u8 *a, u8 *b)
{
    func_02189F98(a,b,0); return *(int *)(b + 0xc4);
}
