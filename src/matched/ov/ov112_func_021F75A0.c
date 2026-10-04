/*
 * function: func_021F75A0
 * address: 0x021F75A0
 * packet: pkt_ov112_021F75A0
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow code.
 * symbols:
 *   func_021F8120 0x021F8120 thumb ov112
 *   func_021F75D8 0x021F75D8 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F8120(int a, u8 *p);
extern void func_021F75D8(u8 *,u8 *);
void func_021F75A0(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) { if(func_021F8120((int)p,p+20+i*264)==1) func_021F75D8(p,p+20+i*264); } }
