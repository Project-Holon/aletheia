/*
 * function: func_021D97B4
 * address:  0x021D97B4
 * packet:   pkt_021D97B4
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D9864  0x021D9864  thumb
 *   func_021D98E8  0x021D98E8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021D9864(void *);
extern void func_021D98E8(void *);

void func_021D97B4(void *a, u8 *q)
{
    func_021D9864(q);
    func_021D98E8(q + 4);
}
