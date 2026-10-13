/*
 * function: SCRCMD_SHOP_PrepareFieldCamera
 * address:  0x021B30C8
 * packet:   pkt_ov021_021B30C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_GetAreasEnabled  0x0218F1B4  thumb
 *   FIELD_CAMERA_SetAreasEnabled  0x0218F1AC  thumb
 *   FIELD_CAMERA_PushStateConstrained  0x0218F848  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb
 *   FIELD_CAMERA_GetEyeRaw  0x0218ECE4  thumb
 *   FIELD_CAMERA_GetTargetRaw  0x0218ECB4  thumb
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb
 *   FIELD_CAMERA_StartMoveConstrained  0x0218F918  thumb
 *   d_021D9708     0x021D9708  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct { s32 x, y, z; } Vec3;

typedef struct {
    Vec3 a;
    Vec3 b;
    Vec3 c;
    Vec3 d;
    s32 e[5];
    s32 f;
} Param;

extern u8 FIELD_CAMERA_GetAreasEnabled(u8 *p);
extern void FIELD_CAMERA_SetAreasEnabled(u8 *p, u32 v);
extern void FIELD_CAMERA_PushStateConstrained(u8 *a);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern void FIELD_CAMERA_GetEyeRaw(void *h, Vec3 *out);
extern void FIELD_CAMERA_GetTargetRaw(void *h, Vec3 *out);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_CAMERA_StartMoveConstrained(void *h, Param *p, int n);

extern Vec3 d_021D9708[];

void SCRCMD_SHOP_PrepareFieldCamera(u32 *p, u32 b, void *h)
{
    Param s;
    int i;

    p[1] = FIELD_CAMERA_GetAreasEnabled(h);
    FIELD_CAMERA_SetAreasEnabled(h, 0);
    FIELD_CAMERA_PushStateConstrained(h);
    i = FIELD_PLAYER_GetDirDisp(FIELDMAP_GetFieldPlayer((void *)b));
    FIELD_CAMERA_GetEyeRaw(h, &s.a);
    FIELD_CAMERA_GetTargetRaw(h, &s.b);
    FIELD_CAMERA_StopTargetTrace(h);
    s.b.x += d_021D9708[i].x;
    s.b.y += d_021D9708[i].y;
    s.b.z += d_021D9708[i].z;
    s.e[0] = 0;
    s.e[1] = 0;
    s.e[2] = 0;
    s.e[3] = 0;
    s.e[4] = 0;
    s.f = 1;
    FIELD_CAMERA_StartMoveConstrained(h, &s, 10);
}
