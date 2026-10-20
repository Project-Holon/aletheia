#ifndef GAME_ARM9_BUTTON_MAN_H
#define GAME_ARM9_BUTTON_MAN_H

#include "../types.h"
#include "../sdk_fx.h"

/* Segment p0 -> dir with a capsule radius. */
typedef struct ButtonSegment {
    VecFx32 p0;
    VecFx32 dir;
    s32  radius;
} ButtonSegment;

typedef struct ButtonSphere {
    VecFx32 c;
    s32  r;
} ButtonSphere;

/* Result block of the segment-versus-sphere test. */
typedef struct ButtonHitInfo {
    u32  hit;
    VecFx32 n;
    s32  d;
} ButtonHitInfo;

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of button_man.c, prototypes copied from their definitions. */

struct ButtonMan;
struct ButtonSlot;

#include "../types.h"
#include "../sdk_fx.h"

struct ButtonMan *BUTTON_MAN_Create(u8 *rects, void (*cb)(s32, s32, s32), s32 arg, int heap);
void BUTTON_MAN_ClearSlot(struct ButtonSlot *slot);
void BUTTON_MAN_Delete(struct ButtonMan *bm);
s32 BUTTON_MAN_UpdateSlots(struct ButtonMan *c);
int BUTTON_MAN_SlotHandlerIdle(struct ButtonSlot *p, int a, int b);
int BUTTON_MAN_SlotHandlerPressed(struct ButtonSlot *p, u32 x);
void BUTTON_MAN_SlotSetKind(struct ButtonSlot *p, int a);
void BUTTON_MAN_RotScaleMtx22(MtxFx22 *mtx, u32 ang, long scaleX, long scaleY, u8 mode);
void BUTTON_MAN_InitSphere(ButtonSphere *dst, VecFx32 *src, unsigned radius);
u32 BUTTON_MAN_SegmentSphereTest(ButtonSegment *seg, ButtonSphere *b, ButtonHitInfo *out);
void BUTTON_MAN_InitSegment(ButtonSegment *p, VecFx32 *q, VecFx32 *r, u32 v);
void BUTTON_MAN_ScaleVec(const VecFx32 *v, int s, VecFx32 *dst);
void BUTTON_MAN_MakeRotMtxXYZ(int ax, int ay, int az, MtxFx33 *dst);
void BUTTON_MAN_MakeLookAtMtx(const VecFx32 *v, MtxFx33 *dst);
void BUTTON_MAN_ConvertUcs2ToSjis(u8 *a, u8 *b, u32 n);
int BUTTON_MAN_Ucs2CharToSjis(u16 *src, char *dst, u32 *stop);
/* END mkheaders: generated region */

#endif
