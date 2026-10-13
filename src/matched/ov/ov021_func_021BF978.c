/*
 * function: EVENT_APPEAR_StartZoomOutAlt
 * address:  0x021BF978
 * packet:   pkt_ov021_021BF978
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetCamera 0x02188C58 thumb ov021
 *   FIELD_CAMERA_ANIME_Create 0x0218FE80 thumb ov021
 *   FIELD_CAMERA_ANIME_SetData 0x0218FEA0 thumb ov021
 *   FIELD_CAMERA_ANIME_Setup 0x0218FEA4 thumb ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam 0x0218FE78 thumb ov021
 *   FIELD_CAMERA_ANIME_ApplyStartParam 0x0218FEC0 thumb ov021
 *   FIELD_CAMERA_ANIME_Start 0x0218FF00 thumb ov021
 */

typedef struct {
    int w[8];
} V8;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    V8 v10;
    V8 v30;
    int f50;
    int f54;
    int f58;
} Q;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *FIELDMAP_GetCamera(void *p);
extern void *FIELD_CAMERA_ANIME_Create(void *a);
extern void FIELD_CAMERA_ANIME_SetData(u8 *p, u32 v);
extern void FIELD_CAMERA_ANIME_Setup(int);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(int, V8 *);
extern void FIELD_CAMERA_ANIME_ApplyStartParam(u8 *o);
extern int FIELD_CAMERA_ANIME_Start(u32 a);

void EVENT_APPEAR_StartZoomOutAlt(Q *q)
{
    int r4;
    int r0;

    r4 = (int)FIELDMAP_GetCamera((void *)q->f4);
    r0 = (int)FIELD_CAMERA_ANIME_Create((void *)q->f4);
    q->fc = 60;
    q->f50 = 1;
    q->f54 = 1;
    q->f58 = r0;
    FIELD_CAMERA_ANIME_SetData((u8 *)r0, (u32)(&q->fc));
    FIELD_CAMERA_ANIME_Setup(q->f58);
    FIELD_CAMERA_ANIME_GetCurrentParam(r4, &q->v30);
    q->v10 = q->v30;
    q->v10.w[1] = q->v10.w[1] - 0x64000;
    FIELD_CAMERA_ANIME_ApplyStartParam((u8 *)q->f58);
    FIELD_CAMERA_ANIME_Start(q->f58);
}
