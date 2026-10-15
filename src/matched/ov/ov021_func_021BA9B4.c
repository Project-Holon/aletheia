/*
 * function: FIELD_RAIL_CAMERA_YawFromPoint
 * address:  0x021BA9B4
 * packet:   pkt_ov021_021BA9B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetCamera  0x021B830C  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_RAIL_GetFocusPos  0x021B79D4  thumb  ov021
 *   FIELD_CAMERA_EnterMode  0x0218E124  thumb  ov021
 *   FIELD_CAMERA_ResumeTargetTrace  0x0218EC60  thumb  ov021
 *   VEC_Subtract  0x0207CA00  arm
 *   VEC_Normalize  0x0207CCA4  arm
 *   func_0207CFB8  0x0207CFB8  arm
 *   FIELD_CAMERA_SetPitch  0x0218ED34  thumb  ov021
 *   FIELD_CAMERA_SetDistance  0x0218ED58  thumb  ov021
 *   FIELD_CAMERA_SetYaw  0x0218ED48  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07529.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } V;

u32 FIELD_RAIL_GetFocusWork(u8 *p);
u8 *FIELD_RAIL_WORK_GetCamera(void);
u32 FIELD_RAIL_GetFieldCamera(u8 *p);
void FIELD_RAIL_GetFocusPos(void **o, void *out);
void FIELD_CAMERA_EnterMode(u8 *a, u32 s);
int FIELD_CAMERA_ResumeTargetTrace(u32 a);
void VEC_Subtract(const V *a, const V *b, V *c);
void VEC_Normalize(const V *a, V *b);
int func_0207CFB8(int a, int b);
void FIELD_CAMERA_SetPitch(u8 *p, u16 v);
void FIELD_CAMERA_SetDistance(u8 *p, u32 v);
void FIELD_CAMERA_SetYaw(u8 *p, u32 v);

void FIELD_RAIL_CAMERA_YawFromPoint(u8 *p)
{
    V w;
    V v;
    u8 *q;
    u32 o;
    int h;

    FIELD_RAIL_GetFocusWork(p);
    q = FIELD_RAIL_WORK_GetCamera();
    o = FIELD_RAIL_GetFieldCamera(p);
    FIELD_CAMERA_EnterMode((u8 *)o, 0);
    FIELD_CAMERA_ResumeTargetTrace(FIELD_RAIL_GetFieldCamera(p));
    FIELD_RAIL_GetFocusPos((void **)p, &v);
    v.y = 0;
    w.x = ((struct Obj07529 *)q)->fC;
    w.y = 0;
    w.z = ((struct Obj07529 *)q)->f10;
    VEC_Subtract(&v, &w, &v);
    VEC_Normalize(&v, &v);
    h = func_0207CFB8(v.x, v.z);
    FIELD_CAMERA_SetPitch((u8 *)o, ((struct Obj07529 *)q)->f4);
    FIELD_CAMERA_SetDistance((u8 *)o, ((struct Obj07529 *)q)->f8);
    FIELD_CAMERA_SetYaw((u8 *)o, h);
}
