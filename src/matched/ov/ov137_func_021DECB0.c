/*
 * function: func_021DECB0
 * address: 0x021DECB0
 * packet: pkt_ov137_021DECB0
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 */
typedef unsigned short u16;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
int func_021DECB0(char *p) {if(func_02039CB4((struct Link *)func_020399A8(),202,40))*(int *)p=12;return 0;}
