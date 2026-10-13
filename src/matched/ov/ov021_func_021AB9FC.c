/*
 * function: FLD_SCENEAREA_LOADER_ApplyFixedCamera
 * address:  0x021AB9FC
 * packet:   pkt_ov021_021AB9FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLD_SCENEAREA_GetCamera  0x021AB760  thumb
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb
 *   FIELD_CAMERA_SetEyeRaw  0x0218ECF4  thumb
 *
 * Lever: `const S *` together with the inline set3 helper gives the y, x, z
 * load order of the two 12-byte vector fills (as in ov021_func_021AB890.c).
 */

typedef struct {
    int x;
    int y;
    int z;
} V;

typedef struct {
    int pad[9];
    V f24;
    V f30;
} S;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FLD_SCENEAREA_GetCamera(u8 *p);
extern void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
extern void FIELD_CAMERA_SetTarget(int h, V *v);
extern void FIELD_CAMERA_SetEyeRaw(int h, V *v);


static inline void set3(V *d, int x, int y, int z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}

void FLD_SCENEAREA_LOADER_ApplyFixedCamera(int a, const S *s)
{
    int h = FLD_SCENEAREA_GetCamera((u8 *)a);
    V v1;
    V v0;

    FIELD_CAMERA_EnterMode((u8 *)h, 2);
    set3(&v1, s->f24.x, s->f24.y, s->f24.z);
    set3(&v0, s->f30.x, s->f30.y, s->f30.z);
    FIELD_CAMERA_SetTarget(h, &v1);
    FIELD_CAMERA_SetEyeRaw(h, &v0);
}
