/*
 * function: func_021BC318
 * address:  0x021BC318
 * packet:   pkt_021BC318
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC33C  0x021BC33C  thumb  ov210
 * unblocked: func_021BC33C (ov210, unlabelled leaf) matched bottom-up and
 *   filed as pkt_021BC33C; the ABS32 site then attests as `matched, overlay`.
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02005624(void (*)(void), u8 *, u32);
extern void func_021BC33C(void);

void func_021BC318(u8 *p)
{
    *(u32 *)(p + 8) = func_02005624(func_021BC33C, p, 0);
}
