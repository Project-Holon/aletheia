/*
 * function: func_021AF2E4
 * address:  0x021AF2E4
 * packet:   pkt_ov021_021AF2E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AF2CC  0x021AF2CC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void func_020113D0(u32 a, void (*cb)(void));
extern void func_021AF2CC(void);

int func_021AF2E4(u32 a)
{
    func_020113D0(a, func_021AF2CC);
    return 1;
}
