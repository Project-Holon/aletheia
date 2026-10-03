/*
 * function: func_021B7980
 * address: 0x021B7980
 * packet: pkt_ov104_021B7980
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow compiled code.
 * symbols:
 *   func_021B7B24 0x021B7B24 thumb ov104
 *   func_021B7D14 0x021B7D14 thumb ov104
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B7B24(void *);
extern void func_021B7D14(void *);
void func_021B7980(u32 unused,u8 *p) { func_021B7B24(p); func_021B7D14(p+4); }
