/*
 * function: FIELD_G3D_MAPPER_GetCellPos
 * address:  0x0218DDA4
 * packet:   pkt_ov021_0218DDA4
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

typedef struct { u32 a, b, c; } Vec3;

void FIELD_G3D_MAPPER_GetCellPos(u8 *a, Vec3 *b)
{
    *b = *(Vec3 *)(a + 4);
}
