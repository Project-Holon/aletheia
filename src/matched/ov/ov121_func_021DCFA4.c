/*
 * function: func_021DCFA4
 * address: 0x021DCFA4
 * packet: pkt_ov121_021DCFA4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021DAB50 0x021DAB50 thumb ov121
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021DAB50(void *a, u16 *p, u16 angle, int bank, const u16 *first, const u16 *last);
void func_021DCFA4(u8 *p,int b,int c,u16 d) {func_021DAB50((void *)b,(u16 *)p,d,c,(const u16 *)(p+32),(const u16 *)(p+64));}
