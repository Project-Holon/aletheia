/*
 * function: func_021BBA20
 * address:  0x021BBA20
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021C3B30  0x021C3B30  data
 *   func_021BAC24  0x021BAC24  thumb  ov099
 *   data_021C3B34  0x021C3B34  data
 *   data_021C3A18  0x021C3A18  data
 *
 * Writes the two halfwords at 0x021C3B44 and runs the script pair with 3 / 3 / 0x14.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern u8 data_021C3B30[];
extern void func_021BAC24(int a, void *b, void *c, int d, int e, int f);

void func_021BBA20(int a)
{
    u16 *r = (u16 *)data_021C3B30;

    r[0xA] = 3;
    r[0xB] = 3;
    func_021BAC24(a, (void *)0x021C3B34, (void *)0x021C3A18, 3, 3, 0x14);
}
