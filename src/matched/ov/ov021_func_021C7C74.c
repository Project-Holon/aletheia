/*
 * function: FIELD_TASK_UpdateCameraLerp
 * address:  0x021C7C74
 * packet:   pkt_ov021_021C7C74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetMode  0x0218E138  thumb  ov021
 *   FIELD_CAMERA_SetMode  0x0218E13C  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   VEC_MultAdd  0x0207CEE4  arm
 *   _ffltu         0x0209BE04  arm
 *   _fdiv          0x0209CE10  arm
 *   _fmul          0x0209C77C  arm
 *   _ffix          0x0209C494  arm
 *   _fsub          0x0209CB8C  arm
 *   _fadd          0x0209C95C  arm
 *   _fgr           0x0209BBB0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct {
    u8 f0;
    u8 pad1[3];
    int f4;
    u16 f8;
    u16 fA;
    Vec fC;
    Vec f18;
    Vec f24;
    int f30;
} Obj;

extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetMode(u8 *p);
extern void FIELD_CAMERA_SetMode(u8 *a, u32 s);
extern void FIELD_CAMERA_SetTarget(int, Vec *);
extern void VEC_MultAdd(int, Vec *, Vec *, Vec *);

int FIELD_TASK_UpdateCameraLerp(Obj *p)
{
    int h;
    int n;
    float t;
    Vec v;

    h = (int)FIELDMAP_GetCamera((void *)p->f4);
    switch (p->f0) {
    case 0:
        p->f30 = FIELD_CAMERA_GetMode((u8 *)h);
        FIELD_CAMERA_SetMode((u8 *)h, 0);
        p->f0 = p->f0 + 1;
        break;
    case 1:
        p->f8 = p->f8 + 1;
        t = (float)(u32)p->f8 / (float)(u32)p->fA;
        if (t > 0.0f) {
            n = (int)(4096.0f * t + 0.5f);
        } else {
            n = (int)(4096.0f * t - 0.5f);
        }
        VEC_MultAdd(n, &p->f24, &p->fC, &v);
        FIELD_CAMERA_SetTarget(h, &v);
        if (p->fA <= p->f8) {
            FIELD_CAMERA_SetMode((u8 *)h, p->f30);
            return 1;
        }
        break;
    }
    return 0;
}
