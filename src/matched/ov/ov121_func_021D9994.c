/*
 * function: func_021D9994
 * address:  0x021D9994
 * packet:   pkt_021D9994
 * region:   ov121
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_SYSTEM_DrawEnd  0x02047970  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void G3D_SYSTEM_DrawEnd(void);

void func_021D9994(void **p)
{
    if (p[1])
        G3D_SYSTEM_DrawEnd();
}
