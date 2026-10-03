/*
 * function: func_021FA1DC
 * address: 0x021FA1DC
 * packet: pkt_ov186_021FA1DC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D18 0x02200D18 data a1
 */
extern void func_02034714(const char *,unsigned,const char *);
extern char d_02200D18[];
void func_021FA1DC(char *p,int x,int y) { if(*(unsigned *)(p+0x18)>=6)func_02034714(d_02200D18,0,d_02200D18);*(unsigned short *)((unsigned)p+*(unsigned *)(p+0x18)*4)=x;*(unsigned short *)((unsigned)p+*(unsigned *)(p+0x18)*4+2)=y;(*(unsigned *)(p+0x18))++; }
