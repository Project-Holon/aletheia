/*
 * function: func_021DEC38
 * address: 0x021DEC38
 * packet: pkt_ov137_021DEC38
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021DCBC4 0x021DCBC4 thumb ov137
 */
typedef unsigned short u16;
extern int func_021DCBC4(void *,int,void *,int);
int func_021DEC38(char *p) {if(func_021DCBC4(*(void **)(p+220),0x2806,0,0)==1){*(int *)p=9;*(int *)(p+16)=0;return 0;}return 0;}
