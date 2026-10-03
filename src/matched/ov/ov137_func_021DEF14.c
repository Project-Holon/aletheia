/*
 * function: func_021DEF14
 * address: 0x021DEF14
 * packet: pkt_ov137_021DEF14
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing bytes of zero alignment padding.
 * symbols:
 *   func_02039338 0x02039338 arm
 */
typedef unsigned short u16;
extern u16 func_02039338(void);
int func_021DEF14(char *p) {if(++*(int *)(p+12)>30){*(int *)(p+12)=0;if(func_02039338()==0)*(int *)p=20;else *(int *)p=21;}return 0;}
