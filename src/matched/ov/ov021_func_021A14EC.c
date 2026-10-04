/*
 * function: func_021A14EC
 * address:  0x021A14EC
 * packet:   pkt_ov021_021A14EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EFF34  0x021EFF34  thumb  ov034
 *   func_02034A5C  0x02034A5C  arm
 *   abs_id_22      0x00000022  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_22[];
extern void func_021EFF34(char *p);
extern void func_02034A5C(int);

void func_021A14EC(u32 *p)
{
    func_021EFF34((char *)p[8]);
    func_02034A5C((int)abs_id_22);
}
