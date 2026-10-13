/*
 * function: FIELD_G3D_MAPPER_GetWindowStartWrapped
 * address:  0x0218D980
 * packet:   pkt_ov021_0218D980
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FX_ModS32  0x0207C994  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0207C768(u32 a, u32 b);
extern int FX_ModS32(int a, int b);

int FIELD_G3D_MAPPER_GetWindowStartWrapped(u32 a, int b, int c)
{
    int r = ((int)func_0207C768((int)c, (int)b) >> 12) - (a >> 1);
    if ((a & 1) == 0) {
        int m = FX_ModS32(c, b);
        if ((int)func_0207C768((int)b, (int)0x2000) < m)
            r++;
    }
    return r;
}
