/*
 * function: func_021DF2B8
 * address: 0x021DF2B8
 * packet: pkt_ov137_021DF2B8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_02039338 0x02039338 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Link;
extern struct Link *func_020399A8(void);
extern u32 func_02039CB4(struct Link *,u32,u32);
extern int func_02039338(void);
int func_021DF2B8(int *p) { if(func_02039CB4(func_020399A8(),204,40)) { if(func_02039338()==0) *p=33; else *p=34; } return 0; }
