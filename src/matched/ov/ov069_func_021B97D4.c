/*
 * function: func_021B97D4
 * address: 0x021B97D4
 * packet: pkt_ov069_021B97D4
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * volatile: 0x021B97E0 reads and 0x021B97E4 writes hardware 0x04000304.
 * symbols:
 *   func_020433E0 0x020433E0 arm
 *   d_021BA620 0x021BA620 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_020433E0(const void *p);
extern const u32 d_021BA620[];
void func_021B97D4(void) { func_020433E0(d_021BA620); *(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000); }
