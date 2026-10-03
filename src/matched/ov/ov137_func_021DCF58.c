/*
 * function: func_021DCF58
 * address: 0x021DCF58
 * packet: pkt_ov137_021DCF58
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
extern int func_02039338(void);
extern int func_021DCBC4(void *,int,void *,int);
void func_021DCF58(int a,int b,u8 *p) {u8 v;if(func_02039338()==0) {v=a;func_021DCBC4(*(void **)(p+16),10240,&v,1);}}
