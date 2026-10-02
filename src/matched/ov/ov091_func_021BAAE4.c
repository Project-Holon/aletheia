/*
 * function: func_021BAAE4
 * address: 0x021BAAE4
 * packet: pkt_ov091_021BAAE4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BAB04 0x021BAB04 thumb ov091
 *   func_021BAE94 0x021BAE94 thumb ov091
 *   func_021BAF28 0x021BAF28 thumb ov091
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void func_021BAB04(u8 *,u8 *,int);
extern void func_021BAE94(u8 *,u8 *);
extern void func_021BAF28(u8 *,u8 *);
void func_021BAAE4(u8 *a,u8 *s,int k) { if(*(u32 *)(s+12)==0) {func_021BAB04(a,s,k);func_021BAE94(a,s);} else func_021BAF28(a,s); }
