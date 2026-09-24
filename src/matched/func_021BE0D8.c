/*
 * function: func_021BE0D8
 * address:  0x021BE0D8
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Test word 1 of the object behind +0x1f8 against 3.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

int func_021BE0D8(void *p)
{
    void *q = *(void **)((char *)p + 0x1f8);
    if (*(u32 *)((char *)q + 4) == 3) {
        return 1;
    }
    return 0;
}
