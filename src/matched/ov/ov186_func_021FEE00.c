/*
 * function: func_021FEE00
 * address: 0x021FEE00
 * packet: pkt_ov186_021FEE00
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FF028 0x021FF028 thumb ov186
 *   func_021FF01C 0x021FF01C thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021FF028(char *); extern void func_021FF01C(char *);
void func_021FEE00(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((char *)((u32)p+i*0x4c))) func_021FF01C((char *)((u32)p+i*0x4c)); }
