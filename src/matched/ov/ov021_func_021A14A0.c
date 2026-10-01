/*
 * function: func_021A14A0
 * address:  0x021A14A0
 * packet:   pkt_ov021_021A14A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02210124  0x021F0124  thumb  ov033
 *   func_02034A5C  0x02034A5C  arm
 *   abs_id_21      0x00000021  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_21[];
extern void func_02210124(u32);
extern void func_02034A5C(const void *);

void func_021A14A0(u32 *p)
{
    func_02210124(p[8]);
    func_02034A5C(abs_id_21);
}
