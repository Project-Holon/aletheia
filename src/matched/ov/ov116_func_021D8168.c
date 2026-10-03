/*
 * function: func_021D8168
 * address: 0x021D8168
 * packet: pkt_ov116_021D8168
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201FEBC 0x0201FEBC thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_0201FEBC(u8 *);
u32 func_021D8168(u8 *p) { u32 result=-2; if(*(u8 **)(p+0x980)!=0) { result=func_0201FEBC(*(u8 **)(p+0x980)); if(result!=-1) *(u32 *)(p+0x980)=0; } return result; }
