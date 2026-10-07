/*
 * function: func_021A117C
 * address:  0x021A117C
 * packet:   pkt_ov021_021A117C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021E0118  0x021F0118  thumb  ov030
 *   func_02034A5C  0x02034A5C  arm
 *   abs_id_1e      0x0000001E  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern unsigned char abs_id_1e[];
extern void func_021E0118(char *p);
extern void func_02034A5C(int);

void func_021A117C(u32 *p)
{
    func_021E0118((char *)p[8]);
    func_02034A5C((int)abs_id_1e);
}
