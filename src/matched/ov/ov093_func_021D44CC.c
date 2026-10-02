/*
 * function: func_021D44CC
 * address: 0x021D44CC
 * packet: pkt_ov093_021D44CC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 *   func_021D4330 0x021D4330 thumb ov093
 */
typedef unsigned int u32;
typedef unsigned char u8;
extern u8 *d_021F3B88;
extern u8 func_021D4330(int);
int func_021D44CC(void) { int i; for(i=0;i<4;i++) if(func_021D4330(i) && *(u32 *)(d_021F3B88+i*4+0x3af4)==0) return 0; return 1; }
