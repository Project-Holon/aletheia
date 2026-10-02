/*
 * function: func_021CE044
 * address: 0x021CE044
 * packet: pkt_ov093_021CE044
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CDFE4 0x021CDFE4 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021CDFE4(u32);
void func_021CE044(u8 *p) { p[0xc4]=func_021CDFE4(p[0xc4]); *(u8 **)(p+0xd8)=p+0xc4; *(u32 *)(p+0xdc)=1; }
