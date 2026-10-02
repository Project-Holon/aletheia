/*
 * function: func_0215A5EC
 * address:  0x0215A5EC
 * packet:   pkt_0215A5EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Getter: word at +0xc of the object whose pointer sits at +0x20.
 *
 * symbols:
 *   (none)
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
void *func_0215A5EC(void *p)
{
    return *(void **)(*(u8 **)((u8 *)p + 0x20) + 0xc);
}
