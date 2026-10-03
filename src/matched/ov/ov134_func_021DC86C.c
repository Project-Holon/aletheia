/*
 * function: func_021DC86C
 * address: 0x021DC86C
 * packet: pkt_ov134_021DC86C
 * region: ov134
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding; early return keeps the final unused compare.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020399A8(void);
extern u32 func_0203D1A4(void *);
void func_021DC86C(u32 value,u32 a,u32 b,u32 c,void *expected) { if(expected==func_020399A8()) { if(value!=func_0203D1A4(func_020399A8())) return; } }
