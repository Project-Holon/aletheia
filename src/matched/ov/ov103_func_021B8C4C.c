/*
 * function: func_021B8C4C
 * address: 0x021B8C4C
 * packet: pkt_ov103_021B8C4C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B7F04 0x021B7F04 thumb ov103
 *   func_021B7F78 0x021B7F78 thumb ov103
 *   func_021B7F4C 0x021B7F4C thumb ov103
 *   func_020061E4 0x020061E4 thumb
 */
typedef unsigned char u8;
extern void func_021B7F04(u8 *);
extern unsigned int func_021B7F78(u8 *);
extern unsigned int func_021B7F4C(u8 *);
extern void func_020061E4(int);
void func_021B8C4C(u8 **p) {
 int i;
 for(i=0;i<2;i++)func_021B7F04(p[i]);
 if(func_021B7F78(p[0]) && func_021B7F4C(p[0]))func_020061E4(0x651);
 if(func_021B7F78(p[1]) && func_021B7F4C(p[1]))func_020061E4(0x656);
}
