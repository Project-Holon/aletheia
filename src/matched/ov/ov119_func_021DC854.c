/*
 * function: func_021DC854
 * address: 0x021DC854
 * packet: pkt_ov119_021DC854
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030678 0x02030678 arm
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   d_021E8560 0x021E8560 data a4
 */
extern void func_02030678(void *,int,int);
extern void func_0203064C(int,int,int);
extern void *func_0203159C(void *,int,int);
extern void func_02082BCC(void *,int,int);
extern char d_021E8560[];
void *func_021DC854(void *a,int t) {
 void *p;
 func_02030678(d_021E8560,0xc000,0x91);
 func_0203064C(1,31,t);
 p=func_0203159C(a,0x1d54,0x91);
 func_02082BCC(p,0,0x1d54);
 return p;
}
