/*
 * function: func_021FB760
 * address: 0x021FB760
 * packet: pkt_ov186_021FB760
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02034714 0x02034714 arm
 *   d_02200D38 0x02200D38 data a1
 *   d_022007F0 0x022007F0 data a4
 */
typedef struct {unsigned short count,unused;void *records;int unknown;} Descriptor;
extern const Descriptor d_022007F0[];
extern char d_02200D38[];
extern void func_02034714(void *,int,void *);
unsigned short func_021FB760(void *p,int i) { if(i>=12)func_02034714(d_02200D38,0,d_02200D38);return d_022007F0[i].count; }
