/*
 * function: func_021FB7B0
 * address: 0x021FB7B0
 * packet: pkt_ov186_021FB7B0
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D38 0x02200D38 data a1
 */
extern char d_02200D38[];
extern void func_02034714(void *,int,void *);
int func_021FB7B0(void *p,int i) { if(i>=12)func_02034714(d_02200D38,0,d_02200D38);return *(unsigned short *)((unsigned)p+i*2); }
