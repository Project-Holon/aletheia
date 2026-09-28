/*
 * function: func_021B69BC
 * address:  0x021B69BC
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Record the new value and raise the pending flag when it changes.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021B69BC(void *p, u32 v)
{
    if (*(u32 *)((char *)p + 0x2c) == v) {
        return;
    }
    if (*(u32 *)((char *)p + 0x20) != 0) {
        return;
    }
    *(u32 *)((char *)p + 0x2c) = v;
    *(u32 *)((char *)p + 0x20) = 1;
}
