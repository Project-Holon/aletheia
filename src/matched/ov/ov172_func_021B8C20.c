/*
 * function: func_021B8C20
 * address:  0x021B8C20
 * packet:   pkt_ov172_021B8C20
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

u32 func_021B8C20(void *c, u8 *x)
{
    if (*(u16 *)(x + 0x3d0) == 0)
        return 1;
    return 0;
}
