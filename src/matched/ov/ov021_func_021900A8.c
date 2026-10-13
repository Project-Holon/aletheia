/*
 * function: FIELD_CAMERA_ANIME_SetTargetFromCurrent
 * address:  0x021900A8
 * packet:   pkt_ov021_021900A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_GetTarget  0x0218F18C  thumb
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

typedef struct { u32 a, b, c; } Vec3;

extern void FIELD_CAMERA_GetTarget(void *a, Vec3 *out);
extern void FIELD_CAMERA_SetTarget(void *a, const Vec3 *p);

void FIELD_CAMERA_ANIME_SetTargetFromCurrent(void *a)
{
    Vec3 t;
    FIELD_CAMERA_GetTarget(a, &t);
    FIELD_CAMERA_SetTarget(a, &t);
}
