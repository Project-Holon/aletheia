/*
 * function: func_021C25B0
 * address:  0x021C25B0
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Store the result of functional call func_0204B100(0x1a, 0, p->h0) into p->w4.
 *
 * symbols:
 *   func_021C25B0  0x021C25B0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0204B100(u32, u32, u32);
void func_021C25B0(u8 *p)
{
    *(u32*)(p + 4) = func_0204B100(0x1a, 0, *(u16*)p);
}

