/*
 * function: func_021E11E4
 * address:  0x021E11E4
 * packet:   pkt_021E11E4
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EAC  0x02030EAC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_02030EAC(void *);

void func_021E11E4(u8 *p)
{
    func_02030EAC(*(void **)(p + 0xd88));
}
