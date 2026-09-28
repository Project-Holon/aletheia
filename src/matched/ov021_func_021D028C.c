/*
 * function: func_021D028C
 * address:  0x021D028C
 * packet:   pkt_ov021_021D028C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores v at +1 of the object's state.
 *
 * symbols:
 *   func_021AC1E0  0x021AC1E0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *func_021AC1E0(void *obj);

void func_021D028C(void *obj, u8 v)
{
    if (obj != 0)
        func_021AC1E0(obj)[1] = v;
}
