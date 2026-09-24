/*
 * function: func_021C256C
 * address:  0x021C256C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Initialise the container and clear its 0x1a 0x18-byte records.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021C256C(void *p, u16 v)
{
    int i;
    *(u16 *)p = v;
    *(u32 *)((char *)p + 0x20) = 0;
    *(u32 *)((char *)p + 0x24) = 0;
    *(u8 *)((char *)p + 0x298) = 0;
    *(u32 *)((char *)p + 4) = 0;
    for (i = 0; i < 0x1a; i++) {
        u8 *e = (u8 *)p + i * 0x18;
        *(u32 *)(e + 0x28) = 0;
        *(u16 *)(e + 0x2c) = 0;
        *(u32 *)(e + 0x30) = 0;
        *(u16 *)(e + 0x34) = 0;
        *(u8 *)(e + 0x36) = 0;
        *(u8 *)(e + 0x37) = 0;
        *(u32 *)(e + 0x3c) = 0;
    }
}
