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
extern int func_02159B10(void *,void *);
extern void *func_0215A5E4(void *);
extern void *func_02012F44(void *);
extern u8 *func_0200A750(void *,u8);
int func_0215DADC(void *a,void *b)
{
 int i = func_02159B10(a,b);
 u8 *p = func_0200A750(func_02012F44(func_0215A5E4(b)), i);
 p[1] = 0;
 return 0;
}
