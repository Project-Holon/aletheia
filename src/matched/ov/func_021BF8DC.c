/*
 * function: func_021BF8DC
 * address:  0x021BF8DC
 * packet:   pkt_021BF8DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Pattern-generated from the ov021 family.
 *
 * symbols:
 *   func_021BF874  0x021BF874  thumb  ov021
 *   func_021BF7F8  0x021BF7F8  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern int func_021BF874(void **a);
extern void func_021BF7F8(void *p);

void func_021BF8DC(u8 *p)
{
    func_021BF874((void **)p);
    func_021BF7F8(p);
}
