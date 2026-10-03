/*
 * function: func_021B9064
 * address: 0x021B9064
 * packet: pkt_ov093_021B9064
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8B9C 0x021B8B9C thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021B8B9C(unsigned char *p, unsigned char k);
u32 func_021B9064(u8 *p,u8 k,int x) { u8 m; k &= 1; k ^= 1; if(x) { m=k+((x&1)<<1); if(func_021B8B9C(p,m)) k=m; } return k; }
