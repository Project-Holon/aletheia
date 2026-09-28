/*
 * function: func_021C16C4
 * address:  0x021C16C4
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Count the u32 at +0x18 down to zero, clearing the u32 at +0x14 when it reaches it.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C16C4(void *p)
{
    u32 v;
    if (*(u32 *)((char *)p + 0x14) == 0)
        return;
    if (*(u32 *)((char *)p + 0x18) == 0)
        return;
    v = *(u32 *)((char *)p + 0x18) - 1;
    *(u32 *)((char *)p + 0x18) = v;
    if (v == 0)
        *(u32 *)((char *)p + 0x14) = 0;
}
