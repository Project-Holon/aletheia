/*
 * function: func_021BEC0C
 * address:  0x021BEC0C
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Swap the u32 pairs at +0x2bc and +0x2c4.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

void func_021BEC0C(void *p)
{
    int i;
    for (i = 0; i < 2; i++) {
        u32 t = *(u32 *)((char *)p + i * 4 + 0x2bc);
        *(u32 *)((char *)p + i * 4 + 0x2bc) = *(u32 *)((char *)p + i * 4 + 0x2c4);
        *(u32 *)((char *)p + i * 4 + 0x2c4) = t;
    }
}
