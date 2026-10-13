/*
 * function: FIELD_TASK_CreateCameraYawTween
 * address:  0x021C701C
 * packet:   pkt_ov021_021C701C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELD_TASK_Create  0x021C6C70  thumb  ov021
 *   FIELD_TASK_GetWork  0x021C6CCC  thumb  ov021
 *   FIELD_TASK_UpdateCameraAngleTween  0x021C71A4  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Q Q;
typedef struct { u32 f0; u32 f4; u32 f8; u8 fC; u8 fD; u16 fE; u16 f10; u16 f12; u32 f14; u32 f18; } W;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELDMAP_GetCamera(void *p);
extern Q *FIELD_TASK_Create(u32 heap, u32 size, void *fn);
extern u32 FIELD_TASK_GetWork(u8 *p);
extern int FIELD_TASK_UpdateCameraAngleTween(W *w);
Q *FIELD_TASK_CreateCameraYawTween(u32 a, u16 b, u32 c)
{
    Q *q = FIELD_TASK_Create(FIELDMAP_GetHeapId((u8 *)a), 0x1c, FIELD_TASK_UpdateCameraAngleTween);
    W *w = (W *)FIELD_TASK_GetWork((u8 *)q);
    w->f0 = a;
    w->f4 = (u32)FIELDMAP_GetCamera((void *)a);
    w->fC = 0;
    w->f8 = 0;
    w->fE = 0;
    w->f10 = b;
    w->f18 = c;
    return q;
}
