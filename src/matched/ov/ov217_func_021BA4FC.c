/*
 * function: func_021BA4FC
 * address:  0x021BA4FC
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call veneer: branch to func_020307B0.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u32 func_020307B0(void *p);

u32 func_021BA4FC(void *a0)
{
    return func_020307B0(a0);
}
