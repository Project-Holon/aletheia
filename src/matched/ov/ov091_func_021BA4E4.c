/*
 * function: func_021BA4E4
 * address: 0x021BA4E4
 * packet: pkt_ov091_021BA4E4
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB7A4 0x021BB7A4 thumb ov091
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BB7A4(void *p, u32 *s);
void func_021BA4E4(u8 *p) { func_021BB7A4(p, (u32 *)(*(unsigned int *)(p+0x150))); p[12]=14; }
