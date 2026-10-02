/*
 * function: func_02179024
 * address: 0x02179024
 * packet: pkt_ov014_02179024
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   g_021797A8 0x021797A8 data a4
 *   func_02178138 0x02178138 thumb ov014
 *   func_02179050 0x02179050 thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *g_021797A8;
extern void func_02178138(int);
extern int func_02179050(u16);
u16 func_02179024(void) {
 func_02178138(1);
 *(u16 *)(g_021797A8 + 0x1EAC) = func_02179050(*(u16 *)(g_021797A8 + 0x1EB0));
 return *(u16 *)(g_021797A8 + 0x1EAC);
}
