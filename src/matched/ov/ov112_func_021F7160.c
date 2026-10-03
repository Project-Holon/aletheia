/*
 * function: func_021F7160
 * address: 0x021F7160
 * packet: pkt_ov112_021F7160
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow code.
 * symbols:
 *   func_021F7204 0x021F7204 thumb ov112
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F7204(u8 *,u8 *);
void func_021F7160(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) func_021F7204(p,p+20+i*264); }
