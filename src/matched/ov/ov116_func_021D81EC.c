/*
 * function: func_021D81EC
 * address: 0x021D81EC
 * packet: pkt_ov116_021D81EC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012DD0 0x02012DD0 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_02012DD0(u8 *);
int func_021D81EC(u8 *p) { if(*(u16 *)(p+0xb6a)==0) return 1; if(func_02012DD0(*(u8 **)(p+0x1844))==2) { *(u16 *)(p+0xb6a)=0; return 1; } return 0; }
