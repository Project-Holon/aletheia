/*
 * function: func_021D9610
 * address: 0x021D9610
 * packet: pkt_ov119_021D9610
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021D8F20 0x021D8F20 thumb ov119
 *   func_02017E1C 0x02017E1C thumb
 *   func_0202136C 0x0202136C thumb
 */
typedef unsigned short u16;
extern int func_021D8AA8(void *);
extern void *func_021D8FA4(void *,int);
extern int func_021D8F20(void *,int);
extern int func_02017E1C(void *,int,int);
extern int func_0202136C(u16);
int func_021D9610(unsigned char *p) { void *v; int w; if(func_021D8AA8(p)==0) {v=func_021D8FA4(p,0); w=func_021D8F20(p,1);} else {v=func_021D8FA4(p,1); w=func_021D8F20(p,0);} if(func_0202136C(func_02017E1C(v,6,0)) && p[0x11f4]!=0 && w==0) return 1; return 0; }
