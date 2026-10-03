/*
 * function: func_021BAFAC
 * address: 0x021BAFAC
 * packet: pkt_ov110_021BAFAC
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
int func_021BAFAC(u32 p) { if (*(u8 *)(p+0xaf0)==0) return 0; if (*(u16 *)(p+0xaec)==255) --*(u8 *)(p+0xaf0); *(u16 *)(p+*(u8 *)(p+0xaf0)*2+0xad4)=255; return 1; }
