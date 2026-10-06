/*
 * function: func_021FEE24
 * address: 0x021FEE24
 * packet: pkt_ov186_021FEE24
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x021FEE4A follow; no follower.
 * symbols:
 *   func_021FF028 0x021FF028 thumb ov186
 *   func_021FF038 0x021FF038 thumb ov186
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021FF028(u32 *p); extern void func_021FF038(char *,u32);
void func_021FEE24(char *p) { int i; for(i=0;i<12;i++) if(func_021FF028((u32 *)((u32)p+i*0x4c))) func_021FF038((char *)((u32)p+i*0x4c),1); }
