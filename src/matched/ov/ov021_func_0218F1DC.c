/*
 * function: FIELD_CAMERA_ApplyEyeArea
 * address:  0x0218F1DC
 * packet:   pkt_ov021_0218F1DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gFieldCameraAreaFuncs  0x021DDA18  data  ov021  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef void (*Handler)(void *a, u32 b, u32 c);
extern Handler gFieldCameraAreaFuncs[];

void FIELD_CAMERA_ApplyEyeArea(u32 *a, u32 b)
{
    if (a[1] == 1) {
        Handler fp = gFieldCameraAreaFuncs[a[0]];
        if (fp != 0)
            fp(a, b, b);
    }
}
