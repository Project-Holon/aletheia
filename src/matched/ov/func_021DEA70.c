/*
 * function: func_021DEA70
 * address:  0x021DEA70
 * packet:   pkt_021DEA70
 * region:   ov137
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E0130  0x021E0130  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void func_021E0130(void *, int);

int func_021DEA70(u8 *p)
{
    func_021E0130(p, 0);
    *(u32 *)p = 1;
    return 0;
}
