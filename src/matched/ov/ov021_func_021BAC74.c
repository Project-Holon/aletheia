/*
 * function: FIELD_RAIL_CAMERA_FixedAngleShiftAtFocus
 * address:  0x021BAC74
 * packet:   pkt_ov021_021BAC74
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FIELD_CAMERA_SetTarget  0x0218EC90  thumb  ov021
 *   FIELD_CAMERA_RestartDelay  0x0218F05C  thumb  ov021
 *   FIELD_RAIL_GetFocusPos  0x021B79D4  thumb  ov021
 *   FIELD_RAIL_GetFieldCamera  0x021B821C  thumb  ov021
 *   FIELD_RAIL_CAMERA_FixedAngleShift  0x021BAC04  thumb  ov021
 */

typedef unsigned int u32;
typedef struct { u32 x, y, z; } V;

typedef unsigned char  u8;
extern u32 FIELD_RAIL_GetFieldCamera(u8 *p);
extern void FIELD_RAIL_CAMERA_FixedAngleShift(u32 p);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern void FIELD_RAIL_GetFocusPos(void **o, void *out);
extern void FIELD_CAMERA_SetTarget(u32 h, V *v);
extern void FIELD_CAMERA_RestartDelay(unsigned char *a);

void FIELD_RAIL_CAMERA_FixedAngleShiftAtFocus(u32 p)
{
    V v;
    u32 h = FIELD_RAIL_GetFieldCamera((u8 *)p);

    FIELD_RAIL_CAMERA_FixedAngleShift(p);
    FIELD_CAMERA_StopTargetTrace((u8 *)h);
    FIELD_RAIL_GetFocusPos((void **)p, &v);
    FIELD_CAMERA_SetTarget(h, &v);
    FIELD_CAMERA_RestartDelay((unsigned char *)h);
}
