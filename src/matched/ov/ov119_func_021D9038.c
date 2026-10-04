/*
 * function: func_021D9038
 * address: 0x021D9038
 * packet: pkt_ov119_021D9038
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02017E1C 0x02017E1C thumb
 *   func_021DD380 0x021DD380 thumb ov119
 *   func_021E6334 0x021E6334 thumb ov119
 *   func_021DF918 0x021DF918 thumb ov119
 */
typedef unsigned char u8;
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D1A4(int);
extern unsigned int func_02017E1C(void *,unsigned int,unsigned int);
extern void func_021DD380(void *,int,int);
extern void func_021E6334(void *,int,int,int,int,int);
extern void func_021DF918(void *,int,void *);
void func_021D9038(int a,int b,int c,u8 *p,int e,int f) { int z;if(e==(int)func_020399A8()) { if(a!=func_0203D1A4((int)func_020399A8())) {z=0;if(func_02017E1C((void *)*(int *)(p+0x1064+a*4),169,0)) {func_021DD380(p,f,*(int *)(p+0x1064+a*4));func_021E6334(p,1,f,*(int *)(p+0x1064+a*4),1,z);func_021DF918(p,1,*(void **)(p+0x1064+a*4));}p[0x11fb]=(p[0x11fb]&~240)|16;} } }
