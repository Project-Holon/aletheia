/*
 * function: func_021E0C78
 * address: 0x021E0C78
 * packet: pkt_ov119_021E0C78
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0CC0 0x021E0CC0 thumb ov119
 */
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_021D8E84(void *,int);
extern void func_021E0CC0(char *p);
void func_021E0C78(char *p) {int z;func_0202208C(0,0,0,0,6,1,*(u16 *)(p+0x5f4));z=0;*(int *)(p+0xf2c)=z;p[0x11f7]=z;func_021D8E84(p,(int)func_021E0CC0);}
