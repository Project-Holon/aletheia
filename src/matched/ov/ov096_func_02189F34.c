/*
 * function: func_02189F34
 * address: 0x02189F34
 * packet: pkt_ov096_02189F34
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D5444 0x021D5444 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(u8 *);
extern u8 func_0218A160(u8 *p, int k);
extern u8 *func_0218A2FC(u8 *p, u8 i);
extern u16 func_021D5444(u8 *);
int func_02189F34(u8 *a, u8 *b)
{
    int t; u8 s; t = func_0201134C(a); s = func_0218A160(b,t); *(int *)(b + 0x38) = func_021D5444(func_0218A2FC(b,s)); return *(int *)(b + 0xc4);
}
