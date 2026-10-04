/*
 * function: func_021AF448
 * address:  0x021AF448
 * packet:   pkt_ov021_021AF448
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021AF430  0x021AF430  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void func_020113D0(char *p, int val);
extern int func_021AF430(u32 a, u32 b, u32 c, u32 d);

int func_021AF448(u32 a)
{
    func_020113D0((char *)a, (int)func_021AF430);
    return 1;
}
