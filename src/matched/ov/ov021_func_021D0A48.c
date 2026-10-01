/*
 * function: func_021D0A48
 * address:  0x021D0A48
 * packet:   pkt_ov021_021D0A48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020307B0(void *);

void func_021D0A48(void *a, u8 **pp)
{
    if (*pp != 0) {
        func_020307B0(*(void **)(*pp + 0x14c));
        func_020307B0(*(void **)(*pp + 0x128));
        func_020307B0(*pp);
        *pp = 0;
    }
}
