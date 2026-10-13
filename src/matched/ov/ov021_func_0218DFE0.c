/*
 * function: FIELD_G3D_MAPPER_GetDrawSlot
 * address:  0x0218DFE0
 * packet:   pkt_ov021_0218DFE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

int FIELD_G3D_MAPPER_GetDrawSlot(u8 *a, u32 idx, int flag, u32 *out)
{
    u32 v = (*(u8 **)(a + 0x44))[idx];
    if (v == 0xff)
        return 0;
    *out = v;
    if (flag == 0) {
        if (idx < *(a + 0x4c))
            return 1;
    } else {
        if (idx >= *(a + 0x4c))
            return 1;
    }
    return 0;
}
