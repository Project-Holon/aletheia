/*
 * function: func_021B9E44
 * address: 0x021B9E44
 * packet: pkt_ov069_021B9E44
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BA860 0x021BA860 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Callback)(u8 *);
extern Callback d_021BA860[];
int func_021B9E44(u8 *p) { return d_021BA860[*(int *)(p+0x158)](p); }
