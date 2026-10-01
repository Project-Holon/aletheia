/*
 * function: func_021AF370
 * address:  0x021AF370
 * packet:   pkt_ov021_021AF370
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AF324  0x021AF324  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void func_020113D0(u32 a, void (*cb)(void));
extern void func_021AF324(void);

int func_021AF370(u32 a)
{
    func_020113D0(a, func_021AF324);
    return 1;
}
