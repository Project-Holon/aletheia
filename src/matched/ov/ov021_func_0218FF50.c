/*
 * function: FIELD_CAMERA_ANIME_Init
 * address:  0x0218FF50
 * packet:   pkt_ov021_0218FF50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void MI_CpuFill8(void *dst, int val, u32 size);
extern void *FIELDMAP_GetCamera(void *p);

void FIELD_CAMERA_ANIME_Init(u32 *o, void *a)
{
    MI_CpuFill8(o, 0, 0x20);
    o[0] = (u32)a;
    o[1] = (u32)FIELDMAP_GetCamera(a);
    o[2] = 0;
    o[3] = 0;
    o[5] = 0;
    o[6] = 0;
    o[7] = 0;
}
