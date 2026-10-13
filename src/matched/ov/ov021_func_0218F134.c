/*
 * function: FIELD_CAMERA_ClearAreas
 * address:  0x0218F134
 * packet:   pkt_ov021_0218F134
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void MI_CpuFill8(void *dst, int val, u32 size);

void FIELD_CAMERA_ClearAreas(u8 *a)
{
    MI_CpuFill8(a + 0x88, 0, 0x60);
    *(a + 0xe8) = 0;
}
