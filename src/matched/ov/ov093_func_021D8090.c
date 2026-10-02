/*
 * function: func_021D8090
 * address: 0x021D8090
 * packet: pkt_ov093_021D8090
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021D8090(u32 v,u8 *p) { u32 i; for(i=0;i<6;i++) { p[i]=v&31; v>>=5; } }
