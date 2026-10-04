/*
 * function: func_021A14CC
 * address:  0x021A14CC
 * packet:   pkt_ov021_021A14CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02034AC4  0x02034AC4  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_021EFEC0  0x021EFEC0  thumb  ov034
 *   abs_id_22      0x00000022  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_22[];
extern int func_02034AC4(signed int);
extern void *func_02188C80(void *p);
extern void *func_021EFEC0(int a0, int a1);

void func_021A14CC(u32 *p)
{
    func_02034AC4((int)abs_id_22);
    p[8] = (u32)func_021EFEC0((int)func_02188C80((void *)p[5]), ((u16 *)p)[6]);
}
