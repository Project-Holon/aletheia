/*
 * function: FIELD_G3D_MAPPER_GetWindowStartEven
 * address:  0x0218D934
 * packet:   pkt_ov021_0218D934
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0207C768(u32 a, u32 b);

int FIELD_G3D_MAPPER_GetWindowStartEven(u32 a, int b, int c)
{
    int r = -(int)((a >> 1) - 1);
    int q = c / b;
    if (c % b < (int)func_0207C768((int)b, (int)0x2000))
        r += q - 1;
    else
        r += q;
    return r;
}
