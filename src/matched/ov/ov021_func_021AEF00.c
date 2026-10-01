/*
 * function: func_021AEF00
 * address:  0x021AEF00
 * packet:   pkt_ov021_021AEF00
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AEEE0  0x021AEEE0  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void func_020113D0(u32 a, void (*cb)(void));
extern void func_021AEEE0(void);

int func_021AEF00(u32 a)
{
    func_020113D0(a, func_021AEEE0);
    return 1;
}
