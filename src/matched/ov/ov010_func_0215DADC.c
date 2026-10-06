/*
 * function: func_0215DADC
 * address: 0x0215DADC
 * packet: pkt_ov010_0215DADC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_0215A5E4 0x0215A5E4 thumb ov010
 *   func_02012F44 0x02012F44 thumb
 *   func_0200A750 0x0200A750 thumb
 */
typedef unsigned char u8;
extern unsigned int func_02159B10(void *a0, void *a1);
extern void *func_0215A5E4(void *a0);
extern void *func_02012F44(void *);
typedef unsigned int   u32;
struct Big;
struct BigSub4;
extern struct BigSub4 *func_0200A750(struct Big *p, u32 index);
int func_0215DADC(void *a,void *b)
{
 int i = func_02159B10(a,b);
 u8 *p = (u8 *)func_0200A750(func_02012F44(func_0215A5E4(b)), (u8)i);
 p[1] = 0;
 return 0;
}
