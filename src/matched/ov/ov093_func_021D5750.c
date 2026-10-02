/*
 * function: func_021D5750
 * address: 0x021D5750
 * packet: pkt_ov093_021D5750
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
int func_021D5750(u8 *p, u16 id)
{ u32 i; for(i=0;i<4;i++) if(id == *(u16 *)((u32)p + i * 14 + 0x10a)) return 1; return 0; }
