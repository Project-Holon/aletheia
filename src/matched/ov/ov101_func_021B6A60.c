/*
 * function: func_021B6A60
 * address: 0x021B6A60
 * packet: pkt_ov101_021B6A60
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021B6A44 0x021B6A44 thumb ov101
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B6A44(u8 *);
void func_021B6A60(u8 *p,u16 *state) { switch(*state) { case 0: *state=1; break; case 1: func_021B6A44(p); break; } }
