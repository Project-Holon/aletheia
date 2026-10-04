/*
 * function: func_021B678C
 * address: 0x021B678C
 * packet: pkt_ov101_021B678C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B6494 0x021B6494 thumb ov101
 */
typedef unsigned int   u32;
extern int func_021B6494(u32 p, u32 a, u32 b, u32 c);
int func_021B678C(int *p,int a,int b) { p[5]=a; p[4]=b; return func_021B6494((u32)((int *)p[0]),0x1000,8,(u32)(p+4))!=0; }
