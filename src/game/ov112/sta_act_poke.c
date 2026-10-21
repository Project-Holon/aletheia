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

#define E (*(u8 **)(q + off + 0x84))

#define EA (*(u8 **)(q + off + 0xA8))

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














u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e);

void STA_ACT_LIGHT_DeleteBillboardImage(char *p);

void STA_ACT_LIGHT_UpdateBillboard(u8 *p);

void STA_ACT_LIGHT_UpdateSprite(char *p);

void STA_ACT_LIGHT_CalcSpriteXform(u8 *p,u8 *q);

void STA_ACT_LIGHT_SetSpritePos(u8 *self, u8 *q);

void STA_ACT_LIGHT_UpdateElem(u8 *p);

void STA_ACT_LIGHT_CopyElemB(u8 *unused, u8 *elem);

void STA_ACT_LIGHT_SetElemFrame(u8 *p, u16 v);

u8 *STA_ACT_LIGHT_AddPokemonElem(u8 *p,u8 *input);

void STA_ACT_LIGHT_FreeElem(char *p, char *q);

void STA_ACT_LIGHT_SetupElem(u32 unused, u8 *p, u32 v);

void STA_ACT_LIGHT_HandleElemAnim(char *p,char *q,int index);

int STA_ACT_LIGHT_IsElemActive(char *p,char *q);

void STA_ACT_LIGHT_AnimNone(char *p,char *q);

void STA_ACT_LIGHT_StopSe(char *p, char *q);

void STA_ACT_LIGHT_AnimA(char *p, char *q);

void STA_ACT_LIGHT_AnimB(u8 *p,u8 *q);

void STA_ACT_LIGHT_AnimC(char *p, char *q);

void STA_ACT_LIGHT_AnimD(u8 *p,u8 *q);

void STA_ACT_LIGHT_AnimE(char *p, char *q);

void STA_ACT_LIGHT_AnimF(char *p,char *q);

void STA_ACT_LIGHT_AnimG(char *unused0, char *unused1);

void STA_ACT_LIGHT_AnimH(char *p, char *q);

void STA_ACT_LIGHT_CopyActorPos(void *unused,u32 *p,u32 *q);

void STA_ACT_LIGHT_SetActorPos(void *unused,u32 *p,const u32 *q);

void STA_ACT_LIGHT_SetActorAngle(int self, char *p, u16 v);

void STA_ACT_LIGHT_SetActorOffset(void *unused,u32 *p,const u32 *q);

void STA_ACT_LIGHT_StartRenderAnim(int unused,u8 *p);

void STA_ACT_LIGHT_ResetRenderAnim(void *a, StaActPokeElem *b);

void STA_ACT_LIGHT_SetRenderAnim(int a, StaActPokeElem *b, unsigned int c);

void STA_ACT_LIGHT_SetSlotVisible(StaActBillboardImage *p, StaActPokeElem *q, int v);

int STA_ACT_LIGHT_IsRenderVisible(int unused,u8 *p);

int STA_ACT_LIGHT_SetActorFlagB(int unused, int *p, int flag);

void STA_ACT_LIGHT_SetActorVisible(int a,u8 *p,int b);

extern char d_021F8464[];

extern s16 FX_SinCosTable_[];

extern void *d_021F832C[];

u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e)
{
    u8 i = 0;
    u8 *p;
    p = GFL_HEAP_Alloc(heap, 0x440, 0, d_021F8464, 0x93);
    *(u16 *)p = heap;
    *(u32 *)(p + 4) = b;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = d;
    *(u16 *)(p + 0x434) = i;
    *(u32 *)(p + 8) = e;
    *(u8 *)(p + 0x43c) = i;
    for (i = 0; i < 4; i++) {
        u8 *q = p + i * 0x108;
        *(u32 *)(q + 0x14) = 0;
        *(u32 *)(q + 0x18) = 0;
    }
    *(u32 *)(p + 0x438) = BILLBOARD_AddImageFromArchive((struct BbBoard *)(*(u32 *)(p + 8)), 0x2f, 0x1d, 3, 0x33, 0x40, 0x40);
    return p;
}

void STA_ACT_LIGHT_DeleteBillboardImage(char *p) {
    int i;
    for (i = 0; i < 4; i++) {
        if (((StaActPokeRecord *)(p + i * 0x108))->flag == 1)
            STA_ACT_LIGHT_FreeElem((char *)((sptr)p), (char *)((sptr)(p + 0x14 + i * 0x108)));
    }
    BILLBOARD_DeleteImage((struct BbBoard *)((StaActBillboardImage *)p)->board, ((StaActBillboardImage *)p)->image);
    GFL_HEAP_Free((void *)((sptr)p));
}

void STA_ACT_LIGHT_UpdateBillboard(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) STA_ACT_LIGHT_CalcSpriteXform(p,p+20+i*264); }

/*
 * extent: two-byte zero padding before 021F7204.
 */
void STA_ACT_LIGHT_UpdateSprite(char *p) {
    int i;
    unsigned j;
    for (i = 0; i < 4; i++) {
        if (((StaActPokeRecord *)(p + i * 0x108))->flag == 1) {
            STA_ACT_LIGHT_SetSpritePos((unsigned char *)p, (unsigned char *)(p + 0x14 + i * 0x108));
            if (((StaActBillboardImage *)p)->b != 0) {
                for (j = 0; j < STA_ACTING_GetElapsedTicks((u8 *)(((StaActBillboardImage *)p)->b)); j++) {
                    if (*(void (**)(char *, char *))(p + i * 0x108 + 0x118) != 0)
                        (*(void (**)(char *, char *))(p + i * 0x108 + 0x118))(p, p + 0x14 + i * 0x108);
                }
            }
        }
    }
    MUSICAL_MCSS_UpdateObject((struct McssActorPool *)((StaActBillboardImage *)p)->actorPool);
}

/*
 * ABI: 5350/535C/5368 forward r1 to6234/624C/6264; complete targets read vector/u16 despite legacy wrapper declarations omitting it.
 * original: delta.z stack slot is untouched before the RotZ multiplication and subtraction, which cancel its contribution; retain original stores only.
 */
void STA_ACT_LIGHT_CalcSpriteXform(u8 *p,u8 *elem)
{
    StaActLightVec3 pos;
    StaActLightVec3 scale;
    StaActLightVec3 delta;
    Mtx matrix;
    StaActLightVec3 *a;
    StaActLightVec3 *b;
    int angle;
    a=(StaActLightVec3 *)MUSICAL_MCSS_GetRenderFlags((u8 *)(*(u8 * *)&((StaActPokeElem *)elem)->renderElem));
    b=(StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)(*(char * *)&((StaActPokeElem *)elem)->renderElem));
    VEC_Add((const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)(elem+24))), (const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)(elem+48))), (VecFx32 *)&pos);
    angle=((StaActPokeElem *)elem)->angle;
    delta.x=0;
    delta.y=b->y;
    MTX_RotZ33_((MtxFx33 *)&matrix,-FX_SinCosTable_[(angle>>4)*2],FX_SinCosTable_[(angle>>4)*2+1]);
    MTX_MultVec33((const VecFx32 *)&delta, (const MtxFx33 *)&matrix, (VecFx32 *)((StaActLightVec3 *)(elem+60)));
    VEC_Subtract((const VecFx32 *)&delta, (const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)(elem+60))), (VecFx32 *)((StaActLightVec3 *)(elem+60)));
    pos.x=(pos.x-a->x-((StaActPokeElem *)elem)->pivotShiftX)/16;
    pos.y=(0xc0000-(pos.y-a->y+((StaActPokeElem *)elem)->pivotShiftY))/16;
    MUSICAL_MCSS_SetRenderPos(*(int * *)&((StaActPokeElem *)elem)->renderElem,(int *)(&pos));
    MUSICAL_MCSS_SetRenderFrame(*(int * *)&((StaActPokeElem *)elem)->renderElem,((StaActPokeElem *)elem)->angle);
    scale.x=((StaActPokeElem *)elem)->scaleX<<4;
    scale.y=((StaActPokeElem *)elem)->scaleY<<4;
    scale.z=((StaActPokeElem *)elem)->scaleZ<<4;
    if(((StaActPokeElem *)elem)->flipX==1) scale.x*=-1;
    MUSICAL_MCSS_SetRenderScale(*(int * *)&((StaActPokeElem *)elem)->renderElem,(int *)(&scale));
    ((StaActPokeElem *)elem)->dirty=0;
    if(((StaActPokeElem *)elem)->renderAnimActive==1) {
        ((StaActPokeElem *)elem)->animTimer+=(u16)GFL_USE_GetRandom(2);
        if(((StaActPokeElem *)elem)->animTimer>120) MUSICAL_MCSS_SetRenderDrawOffset((void *)(*(int *)&((StaActPokeElem *)elem)->renderElem),1);
        else MUSICAL_MCSS_SetRenderDrawOffset((void *)(*(int *)&((StaActPokeElem *)elem)->renderElem),0);
        if(((StaActPokeElem *)elem)->animTimer>125) ((StaActPokeElem *)elem)->animTimer=GFL_USE_GetRandom(120)/3U;
    }
}

/*
 * note 2026-10-05 (wD7 lane15): closed. The else arm of MUSICAL_MCSS_ElemHasAltDepth writes the whole v3.z store in
 *   each arm of the k - 7 test (q+0x20 plus 0xA000 or 0x5000, minus EA[4] << 11). The zz local that
 *   merged at the join was what swapped off (r4) and t (r6); tail merging rebuilds the shared add.
 */
void STA_ACT_LIGHT_SetSpritePos(u8 *self, u8 *q)
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
        if (*(int *)(q + 0x54) == 1) {
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
        if (E != 0 && *(int *)(q + off + 0xCC) == 1) {
            if (*(int *)(q + 0xC) == 1 && *(int *)(q + 8) == 1) {
                t = (MssRenderElem *)MUSICAL_MCSS_GetRenderElem(*(u8 **)(q + 0x58), k);
                if (t->active == 1) {
                    neg = (t->height < 0) ? 1 : 0;
                    ang0 = (u16)(0x10000 - t->angleA);
                    ang2 = (u16)((0x10000 + t->angleB + *(s16 *)(EA + 2)) % 0x10000);
                    MUSICAL_MCSS_GetRenderFlags((u8 *)(*(u8 **)(q + 0x58)));
                    z = t->height;
                    MTX_RotZ33_((MtxFx33 *)&mtx, -FX_SinCosTable_[(ang0 >> 4) * 2], FX_SinCosTable_[(ang0 >> 4) * 2 + 1]);
                    MTX_MultVec33((const VecFx32 *)&t->offsetX, (const MtxFx33 *)&mtx, (VecFx32 *)&rotatedOffset);
                    if (neg == 1) {
                        ang2 = (u16)(0x10000 - ang2);
                    }
                    if (MUSICAL_MCSS_ElemKeepsFlippedHeight(E) == 0 && neg == 1) {
                        z = -z;
                    }
                    MTX_MultVec33((const VecFx32 *)&t->anchorX, (const MtxFx33 *)&mtx, (VecFx32 *)&anchorShift);
                    VEC_Subtract((const VecFx32 *)&t->anchorX, (const VecFx32 *)&anchorShift, (VecFx32 *)&anchorShift);
                    h = *(u16 *)(self + 0x434);
                    elemPos.x = t->x + rotatedOffset.x + 0x80000 + FXR(h);
                    elemPos.y = t->y + rotatedOffset.y + 0x60000;
                    if (MUSICAL_MCSS_ElemHasAltDepth(E) == 1) {
                        elemPos.z = *(int *)(q + 0x20) - 0x14000;
                    } else {
                        if (k - 7 <= 1u) {
                            elemPos.z = *(int *)(q + 0x20) + 0xA000 - (*(u8 *)(EA + 4) << 11);
                        } else {
                            elemPos.z = *(int *)(q + 0x20) + 0x5000 - (*(u8 *)(EA + 4) << 11);
                        }
                    }
                    MUSICAL_MCSS_SetElemPos((void *)(*(u32 *)(self + 0x10)), (struct McssActorElem *)E, (s32 *)&elemPos);
                    MUSICAL_MCSS_SetElemField((void *)(*(u32 *)(self + 0x10)), E, (u16)(ang2 - ang0));
                    MUSICAL_MCSS_SetElemRotZ((void *)(*(u32 *)(self + 0x10)), E, (s16)(z / 16 / 4), (s16)(t->rotZ / 16 / 4));
                    MUSICAL_MCSS_SetElemVisible(*(u8 **)(self + 0x10), E, 1);
                }
            } else {
                MUSICAL_MCSS_SetElemVisible(*(u8 **)(self + 0x10), E, 0);
            }
        }
    }
    MUSICAL_MCSS_GetRenderFlags(*(u8 **)(q + 0x58));
    elemPos.x = *(int *)(q + 0x18) / 16;
    elemPos.y = (0xC0000 - *(int *)(q + 0x1C)) / 16;
    elemPos.z = 0x32;
    BILLBOARD_SetElemPos((struct BbBoard *)(*(void **)(self + 8)), *(u32 *)(q + 0x5C), (VecFx32 *)((struct Trip *)(&elemPos)));
}

void STA_ACT_LIGHT_UpdateElem(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) { if(STA_ACT_LIGHT_IsRenderVisible((sptr)p,p+20+i*264)==1) STA_ACT_LIGHT_CopyElemB(p,p+20+i*264); } }

void STA_ACT_LIGHT_CopyElemB(u8 *unused, u8 *elem) { }

void STA_ACT_LIGHT_SetElemFrame(u8 *p, u16 v)
{
    u8 i;
    *(u16 *)(p + 0x434) = v;
    for (i = 0; i < 9; i++) {
        u8 *e = p + i * 0x108;
        if (*(u32 *)(e + 0x14) == 1) *(u32 *)(e + 0x18) = 1;
    }
}

/*
 * ABI: 4B3C forwards full r0 to4AA8(int); its extern remains int despite superseded i5 narrow score.
 * lever: split records/record pointer steps, expand immutable position at4B88, record/id declaration swap (permuter183).
 */
u8 *STA_ACT_LIGHT_AddPokemonElem(u8 *image,u8 *input)
{
    u8 i;
    void *personal;
    int *position;
    u8 *records;
    u8 *q;
    u8 *row;
    u32 id;
    int scale;
    u8 *record;
    u32 flag;
    for(i=0;i<9;i++) {
        if(*(int *)(image+20+264*i)==0) break;
    }
    q=image+20+264*i;
    ((StaActPokeElem *)q)->value=1;
    ((StaActPokeElem *)q)->dirty=1;
    ((StaActPokeElem *)q)->flag=1;
    ((StaActPokeElem *)q)->elemValue=0;
    ((StaActPokeElem *)q)->keepUpright=0;
    ((StaActPokeElem *)q)->noFlip=0;
    ((StaActPokeElem *)q)->handler.active=0;
    ((StaActPokeElem *)q)->renderElem=MUSICAL_MCSS_SetupRenderObj(((StaActBillboardImage *)image)->renderObj,input,1);
    personal=POKE_PERSONAL_Create((u32)((MonInput *)input)->monsNo,(u32)((MonInput *)input)->form,(u32)((StaActBillboardImage *)image)->heap);
    if(POKE_PERSONAL_GetParam(personal,16)==1) ((StaActPokeElem *)q)->keepUpright=1;
    if(POKE_PERSONAL_GetParam(personal,34)==1) ((StaActPokeElem *)q)->noFlip=1;
    POKE_PERSONAL_Delete(personal);
    ((StaActPokeElem *)q)->x=0;
    ((StaActPokeElem *)q)->y=0;
    ((StaActPokeElem *)q)->z=0;
    ((StaActPokeElem *)q)->offsetX=0;
    ((StaActPokeElem *)q)->offsetY=0;
    ((StaActPokeElem *)q)->offsetZ=0;
    ((StaActPokeElem *)q)->scaleX=4096;
    ((StaActPokeElem *)q)->scaleY=4096;
    ((StaActPokeElem *)q)->scaleZ=4096;
    STA_ACT_LIGHT_SetupElem((uptr)image,q,((MonInput *)input)->monsNo);
    ((StaActPokeElem *)q)->angle=0;
    position=(int *)(q+24);
    scale=1024;
    records=input;
    records=records+20;
    for(i=0;i<9;i++) {
        id=*(u16 *)(input+20+6*i);
        record=records;
        record=record+6*i;
        row=q+4*i;
        ((StaActPokeElem *)q)->slotRecord[i]=record;
        if(id!=255) {
            ((StaActPokeElem *)q)->slotActive[i]=1;
            ((StaActPokeElem *)q)->slotArc[i]=(sptr)MUSICAL_MCSS_CreateResourceArc(id);
            ((StaActPokeElem *)q)->slotImage[i]=MUSICAL_MCSS_AddImage(((StaActBillboardImage *)image)->actorPool,id,(u32)((StaActPokeElem *)q)->slotArc[i],(int *)(q+24));
            MUSICAL_MCSS_SetElemRotZ(((StaActBillboardImage *)image)->actorPool,((StaActPokeElem *)q)->slotImage[i],scale,scale);
            MUSICAL_MCSS_SetElemVisible((u8 *)((StaActBillboardImage *)image)->actorPool,(u8 *)((StaActPokeElem *)q)->slotImage[i],0);
        } else {
            ((StaActPokeElem *)q)->slotActive[i]=0;
            ((StaActPokeElem *)q)->slotArc[i]=0;
            ((StaActPokeElem *)q)->slotImage[i]=0;
        }
    }
    ((StaActPokeElem *)q)->billboardIdx=BILLBOARD_AddElem((struct BbBoard *)(((StaActBillboardImage *)image)->board),((StaActBillboardImage *)image)->image,1024,768,(VecFx32 *)((StaActLightVec3 *)(q+24)),30,0,0);
    flag=1;
    BILLBOARD_SetElemVisible(((StaActBillboardImage *)image)->board,((StaActPokeElem *)q)->billboardIdx,&flag);
    ((StaActPokeElem *)q)->animTimer=GFL_USE_GetRandom(150)>>1;
    ((StaActPokeElem *)q)->renderAnimActive=1;
    return q;
}

/*
 * extent: trailing two-byte zero padding before 021F77EC.
 */
void STA_ACT_LIGHT_FreeElem(char *image, char *elem) {
    u8 i;
    BILLBOARD_FreeElem(((StaActBillboardImage *)image)->board, ((StaActPokeElem *)elem)->billboardIdx);
    for (i = 0; i < 9; i++) {
        if (((StaActPokeElem *)elem)->slotImage[i] != 0) {
            MUSICAL_MCSS_FreeElem((u8 *)((StaActBillboardImage *)image)->actorPool, (u8 *)((StaActPokeElem *)elem)->slotImage[i]);
            MUSICAL_MCSS_FreeResourceArc((struct Tagged *)((StaActPokeElem *)elem)->slotArc[i]);
            ((StaActPokeElem *)elem)->slotArc[i] = 0;
            ((StaActPokeElem *)elem)->slotImage[i] = 0;
        }
    }
    MUSICAL_MCSS_FreeRenderObj((sptr)((StaActBillboardImage *)image)->renderObj, (sptr)((StaActPokeElem *)elem)->renderElem);
    ((StaActPokeElem *)elem)->value = 0;
}

/*
 * Addresses are Black-image addresses.
 */
void STA_ACT_LIGHT_SetupElem(u32 unused, u8 *elem, u32 v)
{
    if (v == 0xe8) { ((StaActPokeElem *)elem)->scaleX = 0xfb3; return; }
    if (v == 0x184 || v == 0x1fc) { ((StaActPokeElem *)elem)->scaleX = 0xfc0; return; }
    if (v == 0x4b || v == 0xcd || v == 0xf5) { ((StaActPokeElem *)elem)->scaleX = 0xfcc; return; }
    if (v == 0x2d || v == 0x142) { ((StaActPokeElem *)elem)->scaleX = 0x1040; return; }

    if (v == 9 || v == 0x21 || v == 0x3d || v == 0x41 || v == 0x4c ||
        v == 0x7a || v == 0x7b || v == 0x8d || v == 0xd6 || v == 0xeb ||
        v == 0xfd || v == 0x100 || v == 0x108 || v == 0x115 || v == 0x11e ||
        v == 0x13b || v == 0x15b || v == 0x1b2 || v == 0x1bc || v == 0x276) {
        ((StaActPokeElem *)elem)->scaleY = 0xfcc;
        return;
    }
    if (v == 0x25 || v == 0xd7 || v == 0xdb || v == 0x16a || v == 0x250 ||
        v == 0x264) {
        ((StaActPokeElem *)elem)->scaleY = 0xfd9;
        return;
    }
    if (v == 0x12 || v == 0x35 || v == 0x7e || v == 0x80 || v == 0x9c ||
        v == 0x9d || v == 0xb5 || v == 0xd0 || v == 0xf6 || v == 0xf8 ||
        v == 0x134 || v == 0x162 || v == 0x17a || v == 0x189 || v == 0x18e ||
        v == 0x1a3 || v == 0x1cc || v == 0x222 || v == 0x231 || v == 0x26f ||
        v == 0x283) {
        ((StaActPokeElem *)elem)->scaleY = 0xfe6;
        return;
    }
    if (v == 0x26 || v == 0x120) { ((StaActPokeElem *)elem)->scaleY = 0xff3; return; }

    if (v == 0x1c1) {
        ((StaActPokeElem *)elem)->scaleX = 0x1040;
        ((StaActPokeElem *)elem)->scaleY = 0xfcc;
        return;
    }
    if (v == 0x26e) {
        ((StaActPokeElem *)elem)->scaleX = 0xfc0;
        ((StaActPokeElem *)elem)->scaleY = 0xfcc;
        return;
    }
}

/*
 * extent: Thumb followers7A80 (18 code+2 zero padding7A92) and7A94 (BX LR+2 zero padding7A96), parent-cleared.
 * ABI: 514C retains caller's explicitly loaded r1 halfword although its own legacy body ignores that input.
 */
void STA_ACT_LIGHT_HandleElemAnim(char *image,char *elem,int index)
{
    u32 v;
    if(*(int *)(elem+132+index*4)==0 || ((StaActPokeElem *)elem)->handler.active!=0) return;
    v=MUSICAL_MCSS_GetElemB((void *)MUSICAL_MCSS_GetActorPoolResource((u8 *)((StaActBillboardImage *)image)->actorPool),**(u16 **)(elem+168+index*4));
    ((StaActPokeElem *)elem)->tail.anim.count=0;
    ((StaActPokeElem *)elem)->tail.anim.index=index;
    ((StaActPokeElem *)elem)->tail.anim.a=0;
    GFL_USE_PlaySeInSlot((uptr)d_021F832C[v],2);
    ((StaActBillboardImage *)image)->count+=1;
    switch(v) {
    case 0: STA_ACT_LIGHT_AnimNone(image,elem); ((StaActPokeElem *)elem)->handler.animFunc=STA_ACT_LIGHT_StopSe; break;
    case 1: STA_ACT_LIGHT_AnimA(image,elem); ((StaActPokeElem *)elem)->handler.animFunc=(void (*)(char *,char *))STA_ACT_LIGHT_AnimB; break;
    case 2: STA_ACT_LIGHT_AnimC(image,elem); ((StaActPokeElem *)elem)->handler.animFunc=(void (*)(char *,char *))STA_ACT_LIGHT_AnimD; break;
    case 3: STA_ACT_LIGHT_AnimE(image,elem); ((StaActPokeElem *)elem)->handler.animFunc=STA_ACT_LIGHT_AnimF; break;
    case 4: STA_ACT_LIGHT_AnimG(image,elem); ((StaActPokeElem *)elem)->handler.animFunc=STA_ACT_LIGHT_AnimH; break;
    }
}

int STA_ACT_LIGHT_IsElemActive(char *p,char *elem)
{
    if(((StaActPokeElem *)elem)->handler.active!=0) return 1;
    return 0;
}

void STA_ACT_LIGHT_AnimNone(char *p,char *q)
{
}

void STA_ACT_LIGHT_StopSe(char *image, char *elem) {
    ElemTail *tail = &((StaActPokeElem *)elem)->tail.anim;
    s16 *v = *(s16 **)(elem + 0xa8 + tail->index * 4);
    v[1] += 0x1000;
    tail->count += 1;
    if (tail->count >= 0xc0) {
        ((StaActPokeElem *)elem)->handler.active = 0;
        ((StaActBillboardImage *)image)->count -= 1;
        if (((StaActBillboardImage *)image)->count == 0) GFL_USE_StopSeSlot(2);
    }
}

/*
 * extent: two-byte zero padding before 021F7BA8.
 */
void STA_ACT_LIGHT_AnimA(char *image, char *elem) {
    ElemTailSigned *t = &((StaActPokeElem *)elem)->tail.animSigned;
    int a = (sptr)STA_ACTING_GetEffectSystem((void *)(((StaActBillboardImage *)image)->b));
    char *r = (char *)MUSICAL_MCSS_GetRenderElem((u8 *)((StaActPokeElem *)elem)->renderElem, ((StaActPokeElem *)elem)->tail.anim.index);
    StaActLightVec3 v;
    t->a = (sptr)STA_ACT_EFFECT_StartSystem((char *)a, 0x35);
    if (((StaActPokeElem *)elem)->flag == 1 && ((MssRenderElem *)r)->active == 1) {
        MUSICAL_MCSS_SetElemScale((uptr)((StaActBillboardImage *)image)->actorPool, *(int *)(elem + 0x84 + t->index * 4), (uptr)(&v));
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z += 0x1000;
    } else {
        VEC_Add((const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)(elem + 0x18))), (const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)((StaActPokeElem *)elem)->renderElem))), (VecFx32 *)&v);
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z -= 0x1c000;
    }
    STA_ACT_EFFECT_StartEffect((char *)t->a, 0, (StaActingVec *)&v);
}

void STA_ACT_LIGHT_AnimB(u8 *image,u8 *elem)
{
    ElemTail *t=&((StaActPokeElem *)elem)->tail.anim;
    u8 *r=MUSICAL_MCSS_GetRenderElem((u8 *)((StaActPokeElem *)elem)->renderElem, ((StaActPokeElem *)elem)->tail.anim.index);
    StaActLightVec3 v;
    sptr a;
    if(((StaActPokeElem *)elem)->flag==1 && ((MssRenderElem *)r)->active==1) {
        MUSICAL_MCSS_SetElemScale((uptr)((StaActBillboardImage *)image)->actorPool,*(int *)(elem+132+t->index*4),(uptr)(&v));
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z+=0x1000;
    } else {
        VEC_Add((const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)(elem+24))), (const VecFx32 *)((const StaActLightVec3 *)((StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)((StaActPokeElem *)elem)->renderElem))), (VecFx32 *)&v);
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z-=0x1c000;
    }
    STA_ACT_EFFECT_SetEmitterPos((char *)t->a,0,(sptr)&v);
    t->count++;
    if(t->count>=180) {
        a=(sptr)STA_ACTING_GetEffectSystem((void *)(((StaActBillboardImage *)image)->b));
        STA_ACT_EFFECT_KillEffect((char *)t->a,0);
        STA_ACT_EFFECT_KillSystem((void *)a,(void *)t->a);
        ((StaActPokeElem *)elem)->handler.active=0;
        ((StaActBillboardImage *)image)->count-=1;
        if(((StaActBillboardImage *)image)->count==0) GFL_USE_StopSeSlot(2);
    }
}

void STA_ACT_LIGHT_AnimC(char *image, char *elem) {
    ElemTailSigned *t = &((StaActPokeElem *)elem)->tail.animSigned;
    char *r = (char *)MUSICAL_MCSS_GetRenderElem((u8 *)((StaActPokeElem *)elem)->renderElem, ((StaActPokeElem *)elem)->tail.anim.index);
    StaActLightVec3 v;
    ((StaActPokeElem *)elem)->slotActive[((StaActPokeElem *)elem)->tail.anim.index] = 0;
    if (((StaActPokeElem *)elem)->flag == 0 || ((MssRenderElem *)r)->active == 0) {
        VEC_Add((const VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)(elem + 0x18))), (const VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)((StaActPokeElem *)elem)->renderElem))), (VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)&v)));
        v.z -= 0x1c000;
        MUSICAL_MCSS_SetElemPos(((StaActBillboardImage *)image)->actorPool, (struct McssActorElem *)(*(int *)(elem + 0x84 + t->index * 4)), (s32 *)((StaActLightVec3 *)&v));
    }
    MUSICAL_MCSS_SetElemVisible((u8 *)((StaActBillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 1);
    MUSICAL_MCSS_SetElemField(((StaActBillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 0);
    MUSICAL_MCSS_SetElemRotZ(((StaActBillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 1024, 1024);
}

static inline long fxmul(long a,long b)
{
    return (long)(((s64)a*b+2048)>>12);
}

/*
 * lever: inline signed-long FX multiply takes the scaled time first;
 *   a direct cast expression changes register allocation and offset homing.
 */
void STA_ACT_LIGHT_AnimD(u8 *p,u8 *elem)
{
    ElemTail *t=&((StaActPokeElem *)elem)->tail.anim;
    StaActLightVec3 v;
    unsigned long offset;
    u16 time=t->count;
    int angle=(time<<9)%65536;
    long s=FX_SinCosTable_[(angle>>4)*2];
    MUSICAL_MCSS_SetElemScale(*(u32 *)(p+0x10),*(u32 *)(elem+0x84+t->index*4),(uptr)&v);
    offset=205;
    v.x+=fxmul((time/3)*offset,s);
    v.y-=3072;
    MUSICAL_MCSS_SetElemPos((void *)((*(u32 *)(p+0x10))), (struct McssActorElem *)((sptr)(*(void **)(elem+0x84+t->index*4))), (s32 *)((StaActLightVec3 *)(&v.x)));
    MUSICAL_MCSS_SetElemField((void *)(*(u32 *)(p+0x10)),(u8 *)(*(u32 *)(elem+0x84+t->index*4)),s>>1);
    t->count++;
    if(t->count>=180) {
        MUSICAL_MCSS_SetElemVisible(*(u8 **)(p+0x10),*(u8 **)(elem+0x84+t->index*4),0);
        offset+=55;
        *(int *)(elem+offset)=0;
        *(u8 *)(p+0x43c)-=1;
        if(*(u8 *)(p+0x43c)==0) GFL_USE_StopSeSlot(2);
    }
}

void STA_ACT_LIGHT_AnimE(char *image, char *elem) {
    ElemTailSigned *t = &((StaActPokeElem *)elem)->tail.animSigned;
    char *r = (char *)MUSICAL_MCSS_GetRenderElem((u8 *)((StaActPokeElem *)elem)->renderElem, ((StaActPokeElem *)elem)->tail.anim.index);
    StaActLightVec3 v;
    ((StaActPokeElem *)elem)->slotActive[((StaActPokeElem *)elem)->tail.anim.index] = 0;
    if (((StaActPokeElem *)elem)->flag == 0 || ((MssRenderElem *)r)->active == 0) {
        VEC_Add((const VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)((StaActLightVec3 *)(elem + 0x18)))), (const VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)((StaActLightVec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)((StaActPokeElem *)elem)->renderElem)))), (VecFx32 *)((StaActLightVec3 *)((StaActLightVec3 *)&v)));
        MUSICAL_MCSS_SetElemPos(((StaActBillboardImage *)image)->actorPool, (struct McssActorElem *)(*(int *)(elem + 0x84 + t->index * 4)), (s32 *)((StaActLightVec3 *)&v));
    }
    t->b = -0x3000;
    MUSICAL_MCSS_SetElemVisible((u8 *)((StaActBillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 1);
    MUSICAL_MCSS_SetElemField(((StaActBillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 0);
    MUSICAL_MCSS_SetElemRotZ(((StaActBillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 1024, 1024);
}

/*
 * extent: 220-byte lead, 7FA8 two-byte return stub; 7FAA zero alignment padding.
 * function_starts: 0x021F7FA8
 */
void STA_ACT_LIGHT_AnimF(char *image,char *elem)
{
    ElemTail *t=&((StaActPokeElem *)elem)->tail.anim;
    StaActLightVec3 v;
    Scale s;
    MUSICAL_MCSS_SetElemScale((uptr)((StaActBillboardImage *)image)->actorPool,*(int *)(elem+0x84+t->index*4),(uptr)(&v));
    t->b+=164;
    v.x-=2867;
    v.y+=t->b;
    v.z=0xc8000;
    MUSICAL_MCSS_SetElemPos(((StaActBillboardImage *)image)->actorPool, (struct McssActorElem *)(*(int *)(elem+0x84+t->index*4)), (s32 *)((StaActLightVec3 *)&v));
    MUSICAL_MCSS_SetElemRot(((StaActBillboardImage *)image)->actorPool,(u8 *)(*(int *)(elem+0x84+t->index*4)),&s.x,&s.y);
    s.x+=12;
    s.y+=12;
    MUSICAL_MCSS_SetElemRotZ(((StaActBillboardImage *)image)->actorPool,(u8 *)(*(int *)(elem+0x84+t->index*4)),s.x,s.y);
    t->count++;
    if(t->count>=180) {
        MUSICAL_MCSS_SetElemVisible((u8 *)((StaActBillboardImage *)image)->actorPool,(u8 *)(*(int *)(elem+0x84+t->index*4)),0);
        ((StaActPokeElem *)elem)->handler.active=0;
        ((StaActBillboardImage *)image)->count-=1;
        if(((StaActBillboardImage *)image)->count==0) GFL_USE_StopSeSlot(2);
    }
}

void STA_ACT_LIGHT_AnimG(char *unused0, char *unused1)
{
}

void STA_ACT_LIGHT_AnimH(char *image, char *elem) {
    ElemTail *t = &((StaActPokeElem *)elem)->tail.anim;
    u16 angle = ((int)t->count << 11) % 65536;
    t->count++;
    if (t->count >= 0xb4) {
        ((StaActPokeElem *)elem)->handler.active = 0;
        ((StaActBillboardImage *)image)->count -= 1;
        if (((StaActBillboardImage *)image)->count == 0) GFL_USE_StopSeSlot(2);
        return;
    }
    MUSICAL_MCSS_SetElemRotZ(((StaActBillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)),
                  FX_SinCosTable_[(angle >> 4) * 2] / 8 + 1024,
                  FX_SinCosTable_[(angle >> 4) * 2 + 1] / 8 + 1024);
}

void STA_ACT_LIGHT_CopyActorPos(void *unused,u32 *p,u32 *q) { q[0]=p[6]; q[1]=p[7]; q[2]=p[8]; }

void STA_ACT_LIGHT_SetActorPos(void *unused,u32 *p,const u32 *q) { p[6]=q[0]; p[7]=q[1]; p[8]=q[2]; p[1]=1; }

/*
 * note: unlabelled leaf in ov112 (the listing emits it as a .word run), filed
 * to witness the bl from src/pending/SCRIPT_COMMAND_TaskRotate.c.  The first
 * argument is ignored; the original moves r1 into r0, so the pointer is the
 * second parameter.
 */
void STA_ACT_LIGHT_SetActorAngle(int self, char *elem, u16 v)
{
    ((StaActPokeElem *)elem)->angle = v;
    if (((StaActPokeElem *)elem)->keepUpright == 1)
        ((StaActPokeElem *)elem)->angle = 0;
    ((StaActPokeElem *)elem)->dirty = 1;
}

void STA_ACT_LIGHT_SetActorOffset(void *unused,u32 *p,const u32 *q) { p[12]=q[0]; p[13]=q[1]; p[14]=q[2]; if(p[4]==1) p[13]=0; p[1]=1; }

void STA_ACT_LIGHT_StartRenderAnim(int unused,u8 *elem) { MUSICAL_MCSS_ResumeRenderAnim(((StaActPokeElem *)elem)->renderElem); ((StaActPokeElem *)elem)->renderAnimActive=1; }

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
    MUSICAL_MCSS_SetRenderVisible((int *)q->renderElem, value);
    for (i = 0; i < 9; i++) {
        if (q->slotImage[i] != 0 && q->slotActive[i] == 1)
            MUSICAL_MCSS_SetElemVisible((u8 *)p->actorPool, (u8 *)q->slotImage[i], value);
    }
    BILLBOARD_SetElemVisible((void *)p->board, q->billboardIdx, (u32 *)(&v));
}

/*
 * extent: Existing matched follower STA_ACT_LIGHT_SetActorFlagB.c follows.
 */
int STA_ACT_LIGHT_IsRenderVisible(int a,u8 *elem) { return MUSICAL_MCSS_IsRenderVisible(((StaActPokeElem *)elem)->renderElem); }

/*
 * note: parent-coordinated blocker leaf for ov132 021FB258.
 */
int STA_ACT_LIGHT_SetActorFlagB(int unused, int *p, int flag)
{
    if (p[5] == 1) p[21] = 0;
    else p[21] = flag;
    p[1] = 1;
    return 1;
}

void STA_ACT_LIGHT_SetActorVisible(int unused,u8 *elem,int visible) { ((StaActPokeElem *)elem)->flag=visible; MUSICAL_MCSS_ResetRender2((sptr)(((StaActPokeElem *)elem)->renderElem),visible); ((StaActPokeElem *)elem)->dirty=1; }

/* Sets the light element's value word and marks the element updated. */
int STA_ACT_LIGHT_SetElemValue(void *unused, int *elem, int value)
{
    elem[3] = value;
    elem[1] = 1;
    return 1;
}
