/*
 * function: func_021BAFE4
 * address: 0x021BAFE4
 * packet: pkt_ov110_021BAFE4
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
void func_021BAFE4(u32 p) { int i; for(i=0;i<13;i++) *(u16 *)(p+i*2+0xad4)=255; *(u8 *)(p+0xaf0)=0; *(u8 *)(p+0xaf1)=0; }
