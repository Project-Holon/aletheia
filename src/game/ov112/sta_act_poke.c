/*
 * file:     sta_act_poke.c
 * unit:     yes
 * function: STA_ACT_LIGHT_AddBillboardImage, STA_ACT_LIGHT_DeleteBillboardImage, STA_ACT_LIGHT_UpdateBillboard, STA_ACT_LIGHT_UpdateSprite, STA_ACT_LIGHT_CalcSpriteXform, STA_ACT_LIGHT_SetSpritePos, STA_ACT_LIGHT_UpdateElem, STA_ACT_LIGHT_CopyElemB, STA_ACT_LIGHT_SetElemFrame, STA_ACT_LIGHT_AddPokemonElem, STA_ACT_LIGHT_FreeElem, STA_ACT_LIGHT_SetupElem, STA_ACT_LIGHT_HandleElemAnim, STA_ACT_LIGHT_IsElemActive, STA_ACT_LIGHT_AnimNone, STA_ACT_LIGHT_StopSe, STA_ACT_LIGHT_AnimA, STA_ACT_LIGHT_AnimB, STA_ACT_LIGHT_AnimC, STA_ACT_LIGHT_AnimD, STA_ACT_LIGHT_AnimE, STA_ACT_LIGHT_AnimF, STA_ACT_LIGHT_AnimG, STA_ACT_LIGHT_AnimH, STA_ACT_LIGHT_CopyActorPos, STA_ACT_LIGHT_SetActorPos, STA_ACT_LIGHT_SetActorAngle, STA_ACT_LIGHT_SetActorOffset, STA_ACT_LIGHT_StartRenderAnim, STA_ACT_LIGHT_ResetRenderAnim, STA_ACT_LIGHT_SetRenderAnim, STA_ACT_LIGHT_SetSlotVisible, STA_ACT_LIGHT_IsRenderVisible, STA_ACT_LIGHT_SetActorFlagB, STA_ACT_LIGHT_SetActorVisible, STA_ACT_LIGHT_SetElemValue
 * address:  0x021F709C
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from sta_act_light.c by tools/splitfile.py.
 *
 * symbols:
 *   BILLBOARD_SetElemVisible 0x0204F720 arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_HEAP_Free 0x020307B0 arm
 *   STA_ACTING_GetActor 0x021F9DA4 thumb ov132
 *   BILLBOARD_AddImageFromArchive 0x0204EFC8 arm
 *   d_021F8464 0x021F8464 data a1
 *   BILLBOARD_DeleteImage 0x0204F150 arm
 *   STA_ACTING_GetElapsedTicks 0x021F9E44 thumb ov132
 *   MUSICAL_MCSS_UpdateObject 0x021F4990 thumb ov112
 *   MUSICAL_MCSS_GetRenderFlags 0x021F545C thumb ov112
 *   MUSICAL_MCSS_GetRenderMatrix 0x021F5464 thumb ov112
 *   VEC_Add 0x0207C9D0 arm
 *   MTX_RotZ33_ 0x0207AF38 thumb
 *   MTX_MultVec33 0x0207B51C arm
 *   VEC_Subtract 0x0207CA00 arm
 *   MUSICAL_MCSS_SetRenderPos 0x021F5350 thumb ov112
 *   MUSICAL_MCSS_SetRenderFrame 0x021F5368 thumb ov112
 *   MUSICAL_MCSS_SetRenderScale 0x021F535C thumb ov112
 *   MUSICAL_MCSS_SetRenderDrawOffset 0x021F5424 thumb ov112
 *   GFL_USE_GetRandom 0x020056EC thumb
 *   FX_SinCosTable_ 0x020A1B38 data a2
 *   MUSICAL_MCSS_GetRenderElem 0x021F5450 thumb ov112
 *   MUSICAL_MCSS_ElemKeepsFlippedHeight 0x021F4B30 thumb ov112
 *   MUSICAL_MCSS_ElemHasAltDepth 0x021F4B24 thumb ov112
 *   MUSICAL_MCSS_SetElemPos 0x021F4E8C thumb ov112
 *   MUSICAL_MCSS_SetElemField 0x021F4ED4 thumb ov112
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   MUSICAL_MCSS_SetElemVisible 0x021F4E6C thumb ov112
 *   BILLBOARD_SetElemPos 0x0204F638 arm
 *   MUSICAL_MCSS_SetupRenderObj 0x021F5204 thumb ov112
 *   POKE_PERSONAL_Create 0x0201ADE4 thumb
 *   POKE_PERSONAL_GetParam 0x0201AE1C thumb
 *   POKE_PERSONAL_Delete 0x0201AE14 thumb
 *   MUSICAL_MCSS_CreateResourceArc 0x021F4B3C thumb ov112
 *   MUSICAL_MCSS_AddImage 0x021F4B88 thumb ov112
 *   BILLBOARD_AddElem 0x0204F428 arm
 *   BILLBOARD_FreeElem 0x0204F5A8 arm
 *   MUSICAL_MCSS_FreeElem 0x021F4D40 thumb ov112
 *   MUSICAL_MCSS_FreeResourceArc 0x021F4B4C thumb ov112
 *   MUSICAL_MCSS_FreeRenderObj 0x021F5330 thumb ov112
 *   MUSICAL_MCSS_GetActorPoolResource 0x021F4F10 thumb ov112
 *   MUSICAL_MCSS_GetElemB 0x021F514C thumb ov112
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   d_021F832C 0x021F832C data a4
 *   STA_ACTING_GetEffectSystem 0x021F9DC0 thumb ov132
 *   STA_ACT_EFFECT_StartSystem 0x021F9EDC thumb ov132
 *   STA_ACT_EFFECT_StartEffect 0x021F9F74 thumb ov132
 *   MUSICAL_MCSS_SetElemScale 0x021F4EA4 thumb ov112
 *   STA_ACT_EFFECT_SetEmitterPos 0x021F9FD0 thumb ov132
 *   STA_ACT_EFFECT_KillEffect 0x021F9FB4 thumb ov132
 *   STA_ACT_EFFECT_KillSystem 0x021F9F58 thumb ov132
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   MUSICAL_MCSS_SetElemRot 0x021F4EC4 thumb ov112
 *   MUSICAL_MCSS_ResumeRenderAnim 0x021F539C thumb ov112
 *   MUSICAL_MCSS_PauseRenderAnim 0x021F53B4 thumb ov112
 *   MUSICAL_MCSS_SetRenderAnim 0x021F53CC thumb ov112
 *   MUSICAL_MCSS_SetRenderVisible 0x021F5374 thumb ov112
 *   MUSICAL_MCSS_IsRenderVisible 0x021F5388 thumb ov112
 *   MUSICAL_MCSS_ResetRender2 0x021F5414 thumb ov112
 *   _fadd                        0x0209C95C  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _fsub                        0x0209CB8C  arm
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "sta_act_types.h"
#include "sta_act_light_shared_types.h"
#include "sta_act_bg_shared_types.h"

#define FXR(x) ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

struct Trip;

struct Personal;

struct Board;

#include "../types.h"


typedef struct { u8 pad_00[8]; u16 monsNo; u8 pad_0A; u8 form; } MonInput;

typedef struct { int pad[5]; int flag; } StaActPokeRecord;

typedef struct { int m[9]; } Mtx;

typedef struct { short y,x; } Scale;

/* MCSS render element, one 0x38-byte slot of a render object
   (MUSICAL_MCSS_GetRenderElem returns renderObj + 0x14 + index * 0x38).
   Same object as ov133's DupFittingRenderElem. */
typedef struct {
    int active;          /* 0x00 */
    int x;               /* 0x04 */
    int y;               /* 0x08 */
    u8 pad_0C[4];        /* 0x0C */
    int offsetX;         /* 0x10 */
    int offsetY;         /* 0x14 */
    int offsetZ;         /* 0x18 */
    int height;          /* 0x1C */
    int rotZ;            /* 0x20 */
    u8 pad_24[4];        /* 0x24 */
    int anchorX;         /* 0x28 */
    int anchorY;         /* 0x2C */
    int anchorZ;         /* 0x30 */
    u16 angleA;          /* 0x34 */
    u16 angleB;          /* 0x36 */
} MssRenderElem;
struct BbBoard;

#include "../arm9/billboard.h"

#include "../arm9/gfl_heap_wrap.h"




#include "../ov132/sta_act_effect.h"
struct McssActorPool;

#include "mus_item_draw.h"

#include "mus_poke_draw.h"


#include "../arm9/fx_vec.h"

#include "../arm9/fx_mtx33.h"







#include "../arm9/gfl_use.h"



struct McssActorElem;






struct PersonalData;

#include "../arm9/poke_personal.h"











#include "mus_item_data.h"



#include "../ov132/sta_acting.h"














StaActBillboardImage *STA_ACT_LIGHT_AddBillboardImage(u16 heap, void *b, void *c, void *d, void *e);

void STA_ACT_LIGHT_DeleteBillboardImage(StaActBillboardImage *p);

void STA_ACT_LIGHT_UpdateBillboard(StaActBillboardImage *p);

void STA_ACT_LIGHT_UpdateSprite(StaActBillboardImage *p);

void STA_ACT_LIGHT_CalcSpriteXform(StaActBillboardImage *p,StaActPokeElem *elem);

void STA_ACT_LIGHT_SetSpritePos(StaActBillboardImage *self, StaActPokeElem *q);

void STA_ACT_LIGHT_UpdateElem(StaActBillboardImage *p);

void STA_ACT_LIGHT_CopyElemB(StaActBillboardImage *unused, StaActPokeElem *elem);

void STA_ACT_LIGHT_SetElemFrame(StaActBillboardImage *p, u16 v);

StaActPokeElem *STA_ACT_LIGHT_AddPokemonElem(StaActBillboardImage *image,u8 *input);

void STA_ACT_LIGHT_FreeElem(StaActBillboardImage *image, StaActPokeElem *elem);

void STA_ACT_LIGHT_SetupElem(StaActBillboardImage *unused, StaActPokeElem *elem, u32 v);

void STA_ACT_LIGHT_HandleElemAnim(StaActBillboardImage *image,StaActPokeElem *elem,int index);

int STA_ACT_LIGHT_IsElemActive(StaActBillboardImage *p,StaActPokeElem *elem);

void STA_ACT_LIGHT_AnimNone(StaActBillboardImage *p,StaActPokeElem *q);

void STA_ACT_LIGHT_StopSe(StaActBillboardImage *image, StaActPokeElem *elem);

void STA_ACT_LIGHT_AnimA(StaActBillboardImage *image, StaActPokeElem *elem);

void STA_ACT_LIGHT_AnimB(StaActBillboardImage *image,StaActPokeElem *elem);

void STA_ACT_LIGHT_AnimC(StaActBillboardImage *image, StaActPokeElem *elem);

void STA_ACT_LIGHT_AnimD(StaActBillboardImage *p,StaActPokeElem *elem);

void STA_ACT_LIGHT_AnimE(StaActBillboardImage *image, StaActPokeElem *elem);

void STA_ACT_LIGHT_AnimF(StaActBillboardImage *image,StaActPokeElem *elem);

void STA_ACT_LIGHT_AnimG(StaActBillboardImage *unused0, StaActPokeElem *unused1);

void STA_ACT_LIGHT_AnimH(StaActBillboardImage *image, StaActPokeElem *elem);

void STA_ACT_LIGHT_CopyActorPos(void *unused,StaActPokeElem *p,u32 *q);

void STA_ACT_LIGHT_SetActorPos(void *unused,StaActPokeElem *p,const u32 *q);

void STA_ACT_LIGHT_SetActorAngle(int self, StaActPokeElem *elem, u16 v);

void STA_ACT_LIGHT_SetActorOffset(void *unused,StaActPokeElem *p,const u32 *q);

void STA_ACT_LIGHT_StartRenderAnim(int unused,StaActPokeElem *elem);

void STA_ACT_LIGHT_ResetRenderAnim(void *unused, StaActPokeElem *elem);

void STA_ACT_LIGHT_SetRenderAnim(int unused, StaActPokeElem *elem, unsigned int anim);

void STA_ACT_LIGHT_SetSlotVisible(StaActBillboardImage *p, StaActPokeElem *q, int v);

int STA_ACT_LIGHT_IsRenderVisible(StaActBillboardImage *a,StaActPokeElem *elem);

int STA_ACT_LIGHT_SetActorFlagB(int unused, StaActPokeElem *p, int flag);

void STA_ACT_LIGHT_SetActorVisible(int unused,StaActPokeElem *elem,int visible);

extern char d_021F8464[];

extern s16 FX_SinCosTable_[];

extern void *d_021F832C[];

StaActBillboardImage *STA_ACT_LIGHT_AddBillboardImage(u16 heap, void *b, void *c, void *d, void *e)
{
    u8 i = 0;
    StaActBillboardImage *p;
    p = GFL_HEAP_Alloc(heap, sizeof(StaActBillboardImage), 0, d_021F8464, 0x93);
    p->heap = heap;
    p->b = b;
    p->renderObj = c;
    p->actorPool = d;
    p->frame = i;
    p->board = e;
    p->count = i;
    for (i = 0; i < 4; i++) {
        p->elems[i].value = 0;
        p->elems[i].dirty = 0;
    }
    p->image = BILLBOARD_AddImageFromArchive(p->board, 0x2f, 0x1d, 3, 0x33, 0x40, 0x40);
    return p;
}

void STA_ACT_LIGHT_DeleteBillboardImage(StaActBillboardImage *p) {
    int i;
    for (i = 0; i < 4; i++) {
        if (p->elems[i].value == 1)
            STA_ACT_LIGHT_FreeElem(p, &p->elems[i]);
    }
    BILLBOARD_DeleteImage((struct BbBoard *)p->board, p->image);
    GFL_HEAP_Free(p);
}

void STA_ACT_LIGHT_UpdateBillboard(StaActBillboardImage *p) { int i; for(i=0;i<4;i++) if(p->elems[i].value==1) STA_ACT_LIGHT_CalcSpriteXform(p,&p->elems[i]); }

/*
 * extent: two-byte zero padding before 021F7204.
 */
void STA_ACT_LIGHT_UpdateSprite(StaActBillboardImage *p) {
    int i;
    unsigned j;
    for (i = 0; i < 4; i++) {
        if (p->elems[i].value == 1) {
            STA_ACT_LIGHT_SetSpritePos(p, &p->elems[i]);
            if (p->b != 0) {
                for (j = 0; j < STA_ACTING_GetElapsedTicks((u8 *)(p->b)); j++) {
                    if (p->elems[i].handler.animFunc != 0)
                        p->elems[i].handler.animFunc(p, &p->elems[i]);
                }
            }
        }
    }
    MUSICAL_MCSS_UpdateObject((struct McssActorPool *)p->actorPool);
}

/*
 * ABI: 5350/535C/5368 forward r1 to6234/624C/6264; complete targets read vector/u16 despite legacy wrapper declarations omitting it.
 * original: delta.z stack slot is untouched before the RotZ multiplication and subtraction, which cancel its contribution; retain original stores only.
 */
void STA_ACT_LIGHT_CalcSpriteXform(StaActBillboardImage *p,StaActPokeElem *elem)
{
    StaActLightVec3 pos;
    StaActLightVec3 scale;
    StaActLightVec3 delta;
    Mtx matrix;
    StaActLightVec3 *a;
    StaActLightVec3 *b;
    int angle;
    a=(StaActLightVec3 *)MUSICAL_MCSS_GetRenderFlags(elem->renderElem);
    b=(StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix(elem->renderElem);
    VEC_Add((const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)&elem->x)), (const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)&elem->offsetX)), (VecFx32 *)&pos);
    angle=elem->angle;
    delta.x=0;
    delta.y=b->y;
    MTX_RotZ33_((MtxFx33 *)&matrix,-FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
    MTX_MultVec33((const VecFx32 *)&delta, (const MtxFx33 *)&matrix, (VecFx32 *)((StaActLightVec3 *)&elem->pivotShiftX));
    VEC_Subtract((const VecFx32 *)&delta, (const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)&elem->pivotShiftX)), (VecFx32 *)((StaActLightVec3 *)&elem->pivotShiftX));
    pos.x=(pos.x-a->x-elem->pivotShiftX)/16;
    pos.y=(0xc0000-(pos.y-a->y+elem->pivotShiftY))/16;
    MUSICAL_MCSS_SetRenderPos(elem->renderElem,(int *)(&pos));
    MUSICAL_MCSS_SetRenderFrame(elem->renderElem,elem->angle);
    scale.x=elem->scaleX<<4;
    scale.y=elem->scaleY<<4;
    scale.z=elem->scaleZ<<4;
    if(elem->flipX==1) scale.x*=-1;
    MUSICAL_MCSS_SetRenderScale(elem->renderElem,(int *)(&scale));
    elem->dirty=0;
    if(elem->renderAnimActive==1) {
        elem->animTimer+=(u16)GFL_USE_GetRandom(2);
        if(elem->animTimer>120) MUSICAL_MCSS_SetRenderDrawOffset(elem->renderElem,1);
        else MUSICAL_MCSS_SetRenderDrawOffset(elem->renderElem,0);
        if(elem->animTimer>125) elem->animTimer=GFL_USE_GetRandom(120)/3U;
    }
}

/*
 * note 2026-10-05 (wD7 lane15): closed. The else arm of MUSICAL_MCSS_ElemHasAltDepth writes the whole v3.z store in
 *   each arm of the k - 7 test (q+0x20 plus 0xA000 or 0x5000, minus EA[4] << 11). The zz local that
 *   merged at the join was what swapped off (r4) and t (r6); tail merging rebuilds the shared add.
 */
void STA_ACT_LIGHT_SetSpritePos(StaActBillboardImage *self, StaActPokeElem *q)
{
    StaActLightVec3 elemPos;
    Mtx mtx;
    StaActLightVec3 anchorShift;
    StaActLightVec3 rotatedOffset;
    int i;
    int off;
    int k;
    int ang2;
    int z;
    int ang0;
    int neg;
    MssRenderElem *t;
    u16 h;

    for (i = 0; i < 9; i++) {
        k = i;
        if (q->flipX == 1) {
            if (i == 7) {
                k = 8;
            } else if (i == 8) {
                k = 7;
            } else if (i == 0) {
                k = 1;
            } else if (i == 1) {
                k = 0;
            }
        }
        off = i * 4;
        if (q->slotImage[i] != 0 && q->slotActive[i] == 1) {
            if (q->elemValue == 1 && q->flag == 1) {
                t = (MssRenderElem *)MUSICAL_MCSS_GetRenderElem(q->renderElem, k);
                if (t->active == 1) {
                    neg = (t->height < 0) ? 1 : 0;
                    ang0 = (u16)(0x10000 - t->angleA);
                    ang2 = (u16)((0x10000 + t->angleB + ((s16 *)q->slotRecord[i])[1]) % 0x10000);
                    MUSICAL_MCSS_GetRenderFlags(q->renderElem);
                    z = t->height;
                    MTX_RotZ33_((MtxFx33 *)&mtx, -FX_SinCosTable_[(ang0 >> 4) * 2], FX_SinCosTable_[(ang0 >> 4) * 2 + 1]);
                    MTX_MultVec33((const VecFx32 *)&t->offsetX, (const MtxFx33 *)&mtx, (VecFx32 *)&rotatedOffset);
                    if (neg == 1) {
                        ang2 = (u16)(0x10000 - ang2);
                    }
                    if (MUSICAL_MCSS_ElemKeepsFlippedHeight(q->slotImage[i]) == 0 && neg == 1) {
                        z = -z;
                    }
                    MTX_MultVec33((const VecFx32 *)&t->anchorX, (const MtxFx33 *)&mtx, (VecFx32 *)&anchorShift);
                    VEC_Subtract((const VecFx32 *)&t->anchorX, (const VecFx32 *)&anchorShift, (VecFx32 *)&anchorShift);
                    h = self->frame;
                    elemPos.x = t->x + rotatedOffset.x + 0x80000 + FXR(h);
                    elemPos.y = t->y + rotatedOffset.y + 0x60000;
                    if (MUSICAL_MCSS_ElemHasAltDepth(q->slotImage[i]) == 1) {
                        elemPos.z = q->z - 0x14000;
                    } else {
                        if (k - 7 <= 1u) {
                            elemPos.z = q->z + 0xA000 - (((u8 *)q->slotRecord[i])[4] << 11);
                        } else {
                            elemPos.z = q->z + 0x5000 - (((u8 *)q->slotRecord[i])[4] << 11);
                        }
                    }
                    MUSICAL_MCSS_SetElemPos(self->actorPool, (struct McssActorElem *)q->slotImage[i], (s32 *)&elemPos);
                    MUSICAL_MCSS_SetElemField(self->actorPool, q->slotImage[i], (u16)(ang2 - ang0));
                    MUSICAL_MCSS_SetElemRotZ(self->actorPool, q->slotImage[i], (s16)(z / 16 / 4), (s16)(t->rotZ / 16 / 4));
                    MUSICAL_MCSS_SetElemVisible(self->actorPool, q->slotImage[i], 1);
                }
            } else {
                MUSICAL_MCSS_SetElemVisible(self->actorPool, q->slotImage[i], 0);
            }
        }
    }
    MUSICAL_MCSS_GetRenderFlags(q->renderElem);
    elemPos.x = q->x / 16;
    elemPos.y = (0xC0000 - q->y) / 16;
    elemPos.z = 0x32;
    BILLBOARD_SetElemPos((struct BbBoard *)self->board, q->billboardIdx, (VecFx32 *)((struct Trip *)(&elemPos)));
}

void STA_ACT_LIGHT_UpdateElem(StaActBillboardImage *p) { int i; for(i=0;i<4;i++) if(p->elems[i].value==1) { if(STA_ACT_LIGHT_IsRenderVisible(p,&p->elems[i])==1) STA_ACT_LIGHT_CopyElemB(p,&p->elems[i]); } }

void STA_ACT_LIGHT_CopyElemB(StaActBillboardImage *unused, StaActPokeElem *elem) { }

void STA_ACT_LIGHT_SetElemFrame(StaActBillboardImage *p, u16 v)
{
    u8 i;
    p->frame = v;
#ifdef __MWERKS__
    for (i = 0; i < 9; i++) {
        if (p->elems[i].value == 1) p->elems[i].dirty = 1;
    }
#else
    for (i = 0; i < 4; i++) {
        if (p->elems[i].value == 1) p->elems[i].dirty = 1;
    }
#ifndef BUGFIX
    /* The DS loop reads slot 4 past the elems array: its value is frame and pad_436, its dirty flag is image. */
    if (p->frame == 1 && p->pad_436 == 0) p->image = 1;
#endif
#endif
}

/*
 * ABI: 4B3C forwards full r0 to4AA8(int); its extern remains int despite superseded i5 narrow score.
 * lever: split records/record pointer steps, expand immutable position at4B88, record/id declaration swap (permuter183).
 */
StaActPokeElem *STA_ACT_LIGHT_AddPokemonElem(StaActBillboardImage *image,u8 *input)
{
    u8 i;
    void *personal;
    int *position;
    u8 *records;
    StaActPokeElem *q;
    u8 *row;
    u32 id;
    int scale;
    u8 *record;
    u32 flag;
    McssMon *mon=(McssMon *)input;
    for(i=0;i<9;i++) {
        if(image->elems[i].value==0) break;
    }
    q=&image->elems[i];
    q->value=1;
    q->dirty=1;
    q->flag=1;
    q->elemValue=0;
    q->keepUpright=0;
    q->noFlip=0;
    q->handler.active=0;
    q->renderElem=MUSICAL_MCSS_SetupRenderObj(image->renderObj,input,1);
    personal=POKE_PERSONAL_Create((u32)mon->species,(u32)mon->form,(u32)image->heap);
    if(POKE_PERSONAL_GetParam(personal,16)==1) q->keepUpright=1;
    if(POKE_PERSONAL_GetParam(personal,34)==1) q->noFlip=1;
    POKE_PERSONAL_Delete(personal);
    q->x=0;
    q->y=0;
    q->z=0;
    q->offsetX=0;
    q->offsetY=0;
    q->offsetZ=0;
    q->scaleX=4096;
    q->scaleY=4096;
    q->scaleZ=4096;
    STA_ACT_LIGHT_SetupElem(image,q,mon->species);
    q->angle=0;
    position=&q->x;
    scale=1024;
    records=input;
    records=records+20;
    for(i=0;i<9;i++) {
        id=mon->slots[i][0];
        record=records;
        record=record+6*i;
        row=(u8 *)&q->slotArc[i];
        q->slotRecord[i]=record;
        if(id!=255) {
            q->slotActive[i]=1;
            q->slotArc[i]=MUSICAL_MCSS_CreateResourceArc(id);
            q->slotImage[i]=MUSICAL_MCSS_AddImage(image->actorPool,id,(struct G3dResource *)q->slotArc[i],&q->x);
            MUSICAL_MCSS_SetElemRotZ(image->actorPool,q->slotImage[i],scale,scale);
            MUSICAL_MCSS_SetElemVisible((u8 *)image->actorPool,(u8 *)q->slotImage[i],0);
        } else {
            q->slotActive[i]=0;
            q->slotArc[i]=0;
            q->slotImage[i]=0;
        }
    }
    q->billboardIdx=BILLBOARD_AddElem((struct BbBoard *)(image->board),image->image,1024,768,(VecFx32 *)((StaActLightVec3 *)&q->x),30,0,0);
    flag=1;
    BILLBOARD_SetElemVisible(image->board,q->billboardIdx,&flag);
    q->animTimer=GFL_USE_GetRandom(150)>>1;
    q->renderAnimActive=1;
    return q;
}

/*
 * extent: trailing two-byte zero padding before 021F77EC.
 */
void STA_ACT_LIGHT_FreeElem(StaActBillboardImage *image, StaActPokeElem *elem) {
    u8 i;
    BILLBOARD_FreeElem(image->board, elem->billboardIdx);
    for (i = 0; i < 9; i++) {
        if (elem->slotImage[i] != 0) {
            MUSICAL_MCSS_FreeElem((u8 *)image->actorPool, (u8 *)elem->slotImage[i]);
            MUSICAL_MCSS_FreeResourceArc(elem->slotArc[i]);
            elem->slotArc[i] = 0;
            elem->slotImage[i] = 0;
        }
    }
    MUSICAL_MCSS_FreeRenderObj(image->renderObj, elem->renderElem);
    elem->value = 0;
}

/*
 * Addresses are Black-image addresses.
 */
void STA_ACT_LIGHT_SetupElem(StaActBillboardImage *unused, StaActPokeElem *elem, u32 v)
{
    if (v == 0xe8) { elem->scaleX = 0xfb3; return; }
    if (v == 0x184 || v == 0x1fc) { elem->scaleX = 0xfc0; return; }
    if (v == 0x4b || v == 0xcd || v == 0xf5) { elem->scaleX = 0xfcc; return; }
    if (v == 0x2d || v == 0x142) { elem->scaleX = 0x1040; return; }

    if (v == 9 || v == 0x21 || v == 0x3d || v == 0x41 || v == 0x4c ||
        v == 0x7a || v == 0x7b || v == 0x8d || v == 0xd6 || v == 0xeb ||
        v == 0xfd || v == 0x100 || v == 0x108 || v == 0x115 || v == 0x11e ||
        v == 0x13b || v == 0x15b || v == 0x1b2 || v == 0x1bc || v == 0x276) {
        elem->scaleY = 0xfcc;
        return;
    }
    if (v == 0x25 || v == 0xd7 || v == 0xdb || v == 0x16a || v == 0x250 ||
        v == 0x264) {
        elem->scaleY = 0xfd9;
        return;
    }
    if (v == 0x12 || v == 0x35 || v == 0x7e || v == 0x80 || v == 0x9c ||
        v == 0x9d || v == 0xb5 || v == 0xd0 || v == 0xf6 || v == 0xf8 ||
        v == 0x134 || v == 0x162 || v == 0x17a || v == 0x189 || v == 0x18e ||
        v == 0x1a3 || v == 0x1cc || v == 0x222 || v == 0x231 || v == 0x26f ||
        v == 0x283) {
        elem->scaleY = 0xfe6;
        return;
    }
    if (v == 0x26 || v == 0x120) { elem->scaleY = 0xff3; return; }

    if (v == 0x1c1) {
        elem->scaleX = 0x1040;
        elem->scaleY = 0xfcc;
        return;
    }
    if (v == 0x26e) {
        elem->scaleX = 0xfc0;
        elem->scaleY = 0xfcc;
        return;
    }
}

/*
 * extent: Thumb followers7A80 (18 code+2 zero padding7A92) and7A94 (BX LR+2 zero padding7A96), parent-cleared.
 * ABI: 514C retains caller's explicitly loaded r1 halfword although its own legacy body ignores that input.
 */
void STA_ACT_LIGHT_HandleElemAnim(StaActBillboardImage *image,StaActPokeElem *elem,int index)
{
    u32 v;
    if(elem->slotImage[index]==0 || elem->handler.active!=0) return;
    v=MUSICAL_MCSS_GetElemB(MUSICAL_MCSS_GetActorPoolResource(image->actorPool),**(u16 **)&elem->slotRecord[index]);
    elem->tail.anim.count=0;
    elem->tail.anim.index=index;
    elem->tail.anim.a=0;
    GFL_USE_PlaySeInSlot((uptr)d_021F832C[v],2);
    image->count+=1;
    switch(v) {
    case 0: STA_ACT_LIGHT_AnimNone(image,elem); elem->handler.animFunc=STA_ACT_LIGHT_StopSe; break;
    case 1: STA_ACT_LIGHT_AnimA(image,elem); elem->handler.animFunc=STA_ACT_LIGHT_AnimB; break;
    case 2: STA_ACT_LIGHT_AnimC(image,elem); elem->handler.animFunc=STA_ACT_LIGHT_AnimD; break;
    case 3: STA_ACT_LIGHT_AnimE(image,elem); elem->handler.animFunc=STA_ACT_LIGHT_AnimF; break;
    case 4: STA_ACT_LIGHT_AnimG(image,elem); elem->handler.animFunc=STA_ACT_LIGHT_AnimH; break;
    }
}

int STA_ACT_LIGHT_IsElemActive(StaActBillboardImage *p,StaActPokeElem *elem)
{
    if(elem->handler.active!=0) return 1;
    return 0;
}

void STA_ACT_LIGHT_AnimNone(StaActBillboardImage *p,StaActPokeElem *q)
{
}

void STA_ACT_LIGHT_StopSe(StaActBillboardImage *image, StaActPokeElem *elem) {
    ElemTail *tail = &elem->tail.anim;
    s16 *v = (s16 *)elem->slotRecord[tail->index];
    v[1] += 0x1000;
    tail->count += 1;
    if (tail->count >= 0xc0) {
        elem->handler.active = 0;
        image->count -= 1;
        if (image->count == 0) GFL_USE_StopSeSlot(2);
    }
}

/*
 * extent: two-byte zero padding before 021F7BA8.
 */
void STA_ACT_LIGHT_AnimA(StaActBillboardImage *image, StaActPokeElem *elem) {
    ElemTailSigned *t = &elem->tail.animSigned;
    char *a = STA_ACTING_GetEffectSystem((void *)(image->b));
    char *r = (char *)MUSICAL_MCSS_GetRenderElem(elem->renderElem, elem->tail.anim.index);
    StaActLightVec3 v;
    t->a = STA_ACT_EFFECT_StartSystem(a, 0x35);
    if (elem->flag == 1 && ((MssRenderElem *)r)->active == 1) {
        MUSICAL_MCSS_SetElemScale((uptr)image->actorPool, ((struct McssActorElem *)elem->slotImage[t->index]), (&v));
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z += 0x1000;
    } else {
        VEC_Add((const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)&elem->x)), (const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix(elem->renderElem))), (VecFx32 *)&v);
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z -= 0x1c000;
    }
    STA_ACT_EFFECT_StartEffect(t->a, 0, (StaActingVec *)&v);
}

void STA_ACT_LIGHT_AnimB(StaActBillboardImage *image,StaActPokeElem *elem)
{
    ElemTail *t=&elem->tail.anim;
    u8 *r=(u8 *)MUSICAL_MCSS_GetRenderElem(elem->renderElem, elem->tail.anim.index);
    StaActLightVec3 v;
    void *a;
    if(elem->flag==1 && ((MssRenderElem *)r)->active==1) {
        MUSICAL_MCSS_SetElemScale((uptr)image->actorPool,((struct McssActorElem *)elem->slotImage[t->index]), (&v));
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z+=0x1000;
    } else {
        VEC_Add((const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)&elem->x)), (const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix(elem->renderElem))), (VecFx32 *)&v);
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z-=0x1c000;
    }
    STA_ACT_EFFECT_SetEmitterPos(t->a,0,(struct VecFx32 *)&v);
    t->count++;
    if(t->count>=180) {
        a=STA_ACTING_GetEffectSystem((void *)(image->b));
        STA_ACT_EFFECT_KillEffect(t->a,0);
        STA_ACT_EFFECT_KillSystem((u8 *)a,(u8 *)t->a);
        elem->handler.active=0;
        image->count-=1;
        if(image->count==0) GFL_USE_StopSeSlot(2);
    }
}

void STA_ACT_LIGHT_AnimC(StaActBillboardImage *image, StaActPokeElem *elem) {
    ElemTailSigned *t = &elem->tail.animSigned;
    char *r = (char *)MUSICAL_MCSS_GetRenderElem(elem->renderElem, elem->tail.anim.index);
    StaActLightVec3 v;
    elem->slotActive[elem->tail.anim.index] = 0;
    if (elem->flag == 0 || ((MssRenderElem *)r)->active == 0) {
        VEC_Add((const VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)&elem->x)), (const VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix(elem->renderElem))), (VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)&v)));
        v.z -= 0x1c000;
        MUSICAL_MCSS_SetElemPos(image->actorPool, (struct McssActorElem *)elem->slotImage[t->index], (s32 *)((StaActLightVec3 *)&v));
    }
    MUSICAL_MCSS_SetElemVisible((u8 *)image->actorPool, (u8 *)elem->slotImage[t->index], 1);
    MUSICAL_MCSS_SetElemField(image->actorPool, (u8 *)elem->slotImage[t->index], 0);
    MUSICAL_MCSS_SetElemRotZ(image->actorPool, (u8 *)elem->slotImage[t->index], 1024, 1024);
}

static inline long fxmul(long a,long b)
{
    return (long)(((s64)a*b+2048)>>12);
}

/*
 * lever: inline signed-long FX multiply takes the scaled time first;
 *   a direct cast expression changes register allocation and offset homing.
 */
void STA_ACT_LIGHT_AnimD(StaActBillboardImage *p,StaActPokeElem *elem)
{
    ElemTail *t=&elem->tail.anim;
    StaActLightVec3 v;
    unsigned long offset;
    u16 time=t->count;
    int angle=(time<<9)%65536;
    long s=FX_SinCosTable_[(angle>>4)*2];
    MUSICAL_MCSS_SetElemScale((uptr)p->actorPool,((struct McssActorElem *)elem->slotImage[t->index]),(&v));
    offset=205;
    v.x+=fxmul((time/3)*offset,s);
    v.y-=3072;
    MUSICAL_MCSS_SetElemPos(p->actorPool, (struct McssActorElem *)((elem->slotImage[t->index])), (s32 *)( &v.x));
    MUSICAL_MCSS_SetElemField(p->actorPool,(u8 *)elem->slotImage[t->index],s>>1);
    t->count++;
    if(t->count>=180) {
        MUSICAL_MCSS_SetElemVisible((u8 *)p->actorPool,(u8 *)elem->slotImage[t->index],0);
        offset+=55;
        elem->handler.active=0;
        p->count-=1;
        if(p->count==0) GFL_USE_StopSeSlot(2);
    }
}

void STA_ACT_LIGHT_AnimE(StaActBillboardImage *image, StaActPokeElem *elem) {
    ElemTailSigned *t = &elem->tail.animSigned;
    char *r = (char *)MUSICAL_MCSS_GetRenderElem(elem->renderElem, elem->tail.anim.index);
    StaActLightVec3 v;
    elem->slotActive[elem->tail.anim.index] = 0;
    if (elem->flag == 0 || ((MssRenderElem *)r)->active == 0) {
        VEC_Add((const VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)((StaActLightVec3 *)&elem->x))), (const VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)((StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix(elem->renderElem)))), (VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)&v)));
        MUSICAL_MCSS_SetElemPos(image->actorPool, (struct McssActorElem *)elem->slotImage[t->index], (s32 *)((StaActLightVec3 *)&v));
    }
    t->b = -0x3000;
    MUSICAL_MCSS_SetElemVisible((u8 *)image->actorPool, (u8 *)elem->slotImage[t->index], 1);
    MUSICAL_MCSS_SetElemField(image->actorPool, (u8 *)elem->slotImage[t->index], 0);
    MUSICAL_MCSS_SetElemRotZ(image->actorPool, (u8 *)elem->slotImage[t->index], 1024, 1024);
}

/*
 * extent: 220-byte lead, 7FA8 two-byte return stub; 7FAA zero alignment padding.
 * function_starts: 0x021F7FA8
 */
void STA_ACT_LIGHT_AnimF(StaActBillboardImage *image,StaActPokeElem *elem)
{
    ElemTail *t=&elem->tail.anim;
    StaActLightVec3 v;
    Scale s;
    MUSICAL_MCSS_SetElemScale((uptr)image->actorPool,((struct McssActorElem *)elem->slotImage[t->index]), (&v));
    t->b+=164;
    v.x-=2867;
    v.y+=t->b;
    v.z=0xc8000;
    MUSICAL_MCSS_SetElemPos(image->actorPool, (struct McssActorElem *)elem->slotImage[t->index], (s32 *)((StaActLightVec3 *)&v));
    MUSICAL_MCSS_SetElemRot(image->actorPool,(u8 *)elem->slotImage[t->index],&s.x,&s.y);
    s.x+=12;
    s.y+=12;
    MUSICAL_MCSS_SetElemRotZ(image->actorPool,(u8 *)elem->slotImage[t->index],s.x,s.y);
    t->count++;
    if(t->count>=180) {
        MUSICAL_MCSS_SetElemVisible((u8 *)image->actorPool,(u8 *)elem->slotImage[t->index],0);
        elem->handler.active=0;
        image->count-=1;
        if(image->count==0) GFL_USE_StopSeSlot(2);
    }
}

void STA_ACT_LIGHT_AnimG(StaActBillboardImage *unused0, StaActPokeElem *unused1)
{
}

void STA_ACT_LIGHT_AnimH(StaActBillboardImage *image, StaActPokeElem *elem) {
    ElemTail *t = &elem->tail.anim;
    u16 angle = ((int)t->count << 11) % 65536;
    t->count++;
    if (t->count >= 0xb4) {
        elem->handler.active = 0;
        image->count -= 1;
        if (image->count == 0) GFL_USE_StopSeSlot(2);
        return;
    }
    MUSICAL_MCSS_SetElemRotZ(image->actorPool, (u8 *)elem->slotImage[t->index],
                  FX_SinCosTable_[(angle >> 4) * 2] / 8 + 1024,
                  FX_SinCosTable_[(angle >> 4) * 2 + 1] / 8 + 1024);
}

void STA_ACT_LIGHT_CopyActorPos(void *unused,StaActPokeElem *p,u32 *q) { q[0]=p->x; q[1]=p->y; q[2]=p->z; }

void STA_ACT_LIGHT_SetActorPos(void *unused,StaActPokeElem *p,const u32 *q) { p->x=q[0]; p->y=q[1]; p->z=q[2]; p->dirty=1; }

/*
 * note: unlabelled leaf in ov112 (the listing emits it as a .word run), filed
 * to witness the bl from src/pending/SCRIPT_COMMAND_TaskRotate.c.  The first
 * argument is ignored; the original moves r1 into r0, so the pointer is the
 * second parameter.
 */
void STA_ACT_LIGHT_SetActorAngle(int self, StaActPokeElem *elem, u16 v)
{
    elem->angle = v;
    if (elem->keepUpright == 1)
        elem->angle = 0;
    elem->dirty = 1;
}

void STA_ACT_LIGHT_SetActorOffset(void *unused,StaActPokeElem *p,const u32 *q) { p->offsetX=q[0]; p->offsetY=q[1]; p->offsetZ=q[2]; if(p->keepUpright==1) p->offsetY=0; p->dirty=1; }

void STA_ACT_LIGHT_StartRenderAnim(int unused,StaActPokeElem *elem) { MUSICAL_MCSS_ResumeRenderAnim(elem->renderElem); elem->renderAnimActive=1; }

/*
 * Struct parameter fixes the zero/load/store scheduling. The extent's
 * 021F80C8 tail stub is included; 021F53CC has its own verified shard.
 */
void STA_ACT_LIGHT_ResetRenderAnim(void *unused, StaActPokeElem *elem)
{
    MUSICAL_MCSS_PauseRenderAnim(elem->renderElem);
    elem->renderAnimActive = 0;
    MUSICAL_MCSS_SetRenderDrawOffset(elem->renderElem, 0);
}

void STA_ACT_LIGHT_SetRenderAnim(int unused, StaActPokeElem *elem, unsigned int anim)
{
    MUSICAL_MCSS_SetRenderAnim(elem->renderElem, anim);
}

/*
 * note: handed label 021F80D6 follows the parameter-home push.
 */
void STA_ACT_LIGHT_SetSlotVisible(StaActBillboardImage *p, StaActPokeElem *q, int v) {
    int i;
    int value = v;
    MUSICAL_MCSS_SetRenderVisible(q->renderElem, value);
    for (i = 0; i < 9; i++) {
        if (q->slotImage[i] != 0 && q->slotActive[i] == 1)
            MUSICAL_MCSS_SetElemVisible((u8 *)p->actorPool, (u8 *)q->slotImage[i], value);
    }
    BILLBOARD_SetElemVisible((void *)p->board, q->billboardIdx, (u32 *)(&v));
}

/*
 * extent: Existing matched follower STA_ACT_LIGHT_SetActorFlagB.c follows.
 */
int STA_ACT_LIGHT_IsRenderVisible(StaActBillboardImage *a,StaActPokeElem *elem) { return MUSICAL_MCSS_IsRenderVisible(elem->renderElem); }

/*
 * note: parent-coordinated blocker leaf for ov132 021FB258.
 */
int STA_ACT_LIGHT_SetActorFlagB(int unused, StaActPokeElem *p, int flag)
{
    if (p->noFlip == 1) p->flipX = 0;
    else p->flipX = flag;
    p->dirty = 1;
    return 1;
}

void STA_ACT_LIGHT_SetActorVisible(int unused,StaActPokeElem *elem,int visible) { elem->flag=visible; MUSICAL_MCSS_ResetRender2(elem->renderElem,visible); elem->dirty=1; }

/* Sets the light element's value word and marks the element updated. */
int STA_ACT_LIGHT_SetElemValue(void *unused, StaActPokeElem *elem, int value)
{
    elem->elemValue = value;
    elem->dirty = 1;
    return 1;
}
