/*
 * function: func_02189ED0
 * address: 0x02189ED0
 * packet: pkt_ov096_02189ED0
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_0218A160 0x0218A160 thumb ov096
 *   func_0218A2FC 0x0218A2FC thumb ov096
 *   func_021D59B4 0x021D59B4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201134C(u8 *);
extern u8 func_0218A160(u8 *,int);
extern u8 *func_0218A2FC(u8 *,int);
extern int func_021D59B4(u8 *,int);
int func_02189ED0(u8 *a, u8 *b)
{
    int t; t = func_0201134C(a); t = func_0218A160(b,t); *(int *)(b + 0x38) = func_021D59B4(func_0218A2FC(b,t),17); return *(int *)(b + 0xc4);
}
