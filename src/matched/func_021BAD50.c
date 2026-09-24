/*
 * function: func_021BAD50
 * address:  0x021BAD50
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021C3B00  0x021C3B00  data
 *   func_021BAC24  0x021BAC24  thumb  ov099
 *   data_021C3A50  0x021C3A50  data
 *
 * Runs the second script pair with 5 / 4 / 0x11.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 data_021C3B00[];
extern void func_021BAC24(int a, void *b, void *c, int d, int e, int f);

void func_021BAD50(int a)
{
    func_021BAC24(a, data_021C3B00, (void *)0x021C3A50, 5, 4, 0x11);
}
