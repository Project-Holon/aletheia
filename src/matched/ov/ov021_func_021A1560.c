/*
 * function: func_021A1560
 * address:  0x021A1560
 * packet:   pkt_ov021_021A1560
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021EFEC0  0x021EFEC0  thumb  ov035
 *   abs_id_23      0x00000023  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_23[];
extern int func_02034AC4(int);
extern void *func_02188C80(void *p);
extern void *func_021EFEC0(int a0, int a1, int a2);

void func_021A1560(u32 *p)
{
    func_02034AC4((int)abs_id_23);
    p[8] = (u32)func_021EFEC0((int)p, (int)func_02188C80((void *)p[5]), 0x70);
}
