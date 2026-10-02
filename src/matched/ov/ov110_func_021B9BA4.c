/*
 * function: func_021B9BA4
 * address:  0x021B9BA4
 * packet:   pkt_ov110_021B9BA4
 * region:   ov110
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void *func_020056A0(void (*fn)(void *, u8 *), u8 *p, int n);
void *func_021B9BA4(void (*fn)(void *, u8 *), u8 *p, int n) { return func_020056A0(fn, p, n); }
