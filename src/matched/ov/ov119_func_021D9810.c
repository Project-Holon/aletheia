/*
 * function: func_021D9810
 * address: 0x021D9810
 * packet: pkt_ov119_021D9810
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02040588 0x02040588 arm
 *   func_021E1CE8 0x021E1CE8 thumb ov119
 *   func_021E3E80 0x021E3E80 thumb ov119
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_021D8B38 0x021D8B38 thumb ov119
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9AD8 0x021D9AD8 thumb ov119
 */
typedef unsigned short u16;
extern int func_020221A4(void);
extern void func_02040588(int,int);
extern void func_021E1CE8(void *,int);
extern void func_021E3E80(void *);
extern void func_021E3208(void *,int);
extern void func_02041B6C(int);
extern int func_021D8FA4(void *,int);
extern void func_021D9468(void *,int,int);
extern void func_021D8B38(void *);
extern void func_0202208C(int,int,int,int,int,int,int);
extern void func_021D8E84(void *,int);
extern void func_021D9AD8(void *);
void func_021D9810(char *p) { int z,one; if(func_020221A4()) {z=0;func_02040588(3,0);one=1;func_021E1CE8(p,1);func_02040588(4,0);func_021E3E80(p);func_021E3208(p,0);func_02041B6C(3);*(u16 *)0x04000050=z;func_021D9468(p,0,func_021D8FA4(p,0));func_021D9468(p,1,func_021D8FA4(p,1));func_021D8B38(p);func_0202208C(3,1,1,0,6,one,*(u16 *)(p+0x5f4));func_021D8E84(p,(int)func_021D9AD8); } }
