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
 *   table 0x020A1B38 data a2
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
#include "sta_act_light_shared_types.h"
#include "sta_act_bg_shared_types.h"

#define E (*(u8 **)(q + off + 0x84))

#define EA (*(u8 **)(q + off + 0xA8))

#define FXR(x) ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

struct Trip;

struct Personal;

struct Board;

typedef short s16;

/* Animation state at Elem + 0xF0 (16 bytes). Some animators count with an
   unsigned short and some with a signed short, so the counter is unioned. */
typedef struct { u16 count; u16 pad; int index; int a; int b; } ElemTail;

typedef struct { short count; short pad; int index; int a; int b; } ElemTailSigned;

/* One sprite element of a BillboardImage (264 bytes). The same record is the
   3D actor the actor system hands out through STA_ACTING_GetActor. */
typedef struct {
    int value;            /* 0x00 */
    int dirty;              /* 0x04 */
    int flag;             /* 0x08 */
    int elemValue;              /* 0x0C */
    int keepUpright;              /* 0x10 */
    int noFlip;              /* 0x14 */
    int x;                /* 0x18 */
    int y;                /* 0x1C */
    int z;                /* 0x20 */
    int scaleX;           /* 0x24 */
    int scaleY;           /* 0x28 */
    int scaleZ;           /* 0x2C */
    int offsetX;              /* 0x30 */
    int offsetY;              /* 0x34 */
    int offsetZ;              /* 0x38 */
    int pivotShiftX;              /* 0x3C */
    int pivotShiftY;              /* 0x40 */
    u8 pad_44[4];         /* 0x44 */
    u16 angle;            /* 0x48 */
    u16 pad_4A;           /* 0x4A */
    int renderAnimActive;              /* 0x4C */
    u16 animTimer;              /* 0x50 */
    u16 pad_52;           /* 0x52 */
    int flipX;              /* 0x54 */
    void *renderElem;     /* 0x58 */
    u32 billboardIdx;     /* 0x5C */
    int slotArc[9];       /* 0x60 */
    void *slotImage[9];   /* 0x84 */
    void *slotRecord[9];  /* 0xA8 */
    int slotActive[9];    /* 0xCC */
    union {
        ElemTail anim;        /* unsigned counter */
        ElemTailSigned animSigned; /* signed counter */
    } tail;               /* 0xF0 */
    u32 pad_100;          /* 0x100 */
    union {
        int active;                        /* 0x104 nonzero while an animation runs */
        void (*animFunc)(char *, char *);  /* 0x104 current animator */
    } handler;            /* 0x104 */
} Elem;

typedef struct {
    u16 heap;             /* 0x00 */
    u16 pad_02;
    u32 b;                /* 0x04 */
    void *board;          /* 0x08 */
    void *renderObj;      /* 0x0C */
    void *actorPool;      /* 0x10 */
    Elem elems[4];        /* 0x14 */
    u16 frame;            /* 0x434 */
    u16 pad_436;
    u32 image;            /* 0x438 */
    u8 count;             /* 0x43C */
    u8 pad_43D[3];
} BillboardImage;

typedef struct { u8 pad_00[8]; u16 monsNo; u8 pad_0A; u8 form; } MonInput;

typedef struct { int pad[5]; int flag; } Record;

typedef struct { int m[9]; } Mtx;

typedef long long s64;

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

extern void BILLBOARD_SetElemVisible(struct BbBoard *board, u32 elemIndex, u32 *visible);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern u32 GFL_HEAP_Free(void *);

extern u32 BILLBOARD_AddImageFromArchive(struct BbBoard *board, u32 arcId, u32 dataId, u32 formatIndex, u32 sizeCode, u8 columns, u8 rows);

extern void BILLBOARD_DeleteImage(struct BbBoard *board, s32 index);

extern u32 STA_ACTING_GetElapsedTicks(u8 *p);
struct McssActorPool;

extern void MUSICAL_MCSS_UpdateObject(struct McssActorPool *p);

extern u8 *MUSICAL_MCSS_GetRenderFlags(u8 *);

extern char *MUSICAL_MCSS_GetRenderMatrix(char *);

extern void VEC_Add(const Vec3 *,const Vec3 *,Vec3 *);

extern void MTX_RotZ33_(Mtx *,int,int);

extern void MTX_MultVec33(const Vec3 *,const Mtx *,Vec3 *);

extern void VEC_Subtract(const Vec3 *,const Vec3 *,Vec3 *);

extern void MUSICAL_MCSS_SetRenderPos(int *p, int *q);

extern void MUSICAL_MCSS_SetRenderFrame(int *,u16);

extern void MUSICAL_MCSS_SetRenderScale(int *p, int *q);

extern void MUSICAL_MCSS_SetRenderDrawOffset(void *slot, s32 isLarge);

extern u32 GFL_USE_GetRandom(u32);

extern u8 *MUSICAL_MCSS_GetRenderElem(u8 *, int);

extern int MUSICAL_MCSS_ElemKeepsFlippedHeight(u8 *);

extern int MUSICAL_MCSS_ElemHasAltDepth(u8 *);
struct McssActorElem;

extern void MUSICAL_MCSS_SetElemPos(void *unused, struct McssActorElem *p, s32 *q);

extern void MUSICAL_MCSS_SetElemField(void *unused, u8 *elem, u16 v);

extern void MUSICAL_MCSS_SetElemRotZ(void *unused, u8 *elem, s16 a, s16 b);

extern void MUSICAL_MCSS_SetElemVisible(u8 *, u8 *, u32);

extern void BILLBOARD_SetElemPos(u8 *board, int i, struct Trip *src);

extern u8 *MUSICAL_MCSS_SetupRenderObj(void *,u8 *,u32);
struct PersonalData;

extern struct PersonalData *POKE_PERSONAL_Create(unsigned int species, int form, unsigned int heap);

extern u32 POKE_PERSONAL_GetParam(struct PersonalData *data, u32 field);

extern void POKE_PERSONAL_Delete(struct PersonalData *data);

extern void *MUSICAL_MCSS_CreateResourceArc(int type);

extern struct McssActorElem *MUSICAL_MCSS_AddImage(struct McssActorPool *pool, s32 type, u32 id, s32 *v);

extern s32 BILLBOARD_AddElem(struct Board *b, u32 id, u16 v12, u16 v14, Vec3 *src, u8 k, u32 w, u32 mode);

extern void BILLBOARD_FreeElem(struct BbBoard *board, u32 elemIndex);

extern void MUSICAL_MCSS_FreeElem(u8 *p, u8 *e);

extern void MUSICAL_MCSS_FreeResourceArc(struct Tagged *resourceArc);

extern void MUSICAL_MCSS_FreeRenderObj(int, int);

extern u32 MUSICAL_MCSS_GetActorPoolResource(u8 *);

extern unsigned char MUSICAL_MCSS_GetElemB(void *p, int i);

extern void GFL_USE_PlaySeInSlot(u32 seqNo, s32 slot);

extern void GFL_USE_StopSeSlot(int);

extern void *STA_ACTING_GetEffectSystem(void *p);

extern char *STA_ACT_EFFECT_StartSystem(char *p, u32 a);

extern void STA_ACT_EFFECT_StartEffect(int, int, Vec3 *);

extern void MUSICAL_MCSS_SetElemScale(u32 unused, u32 p, u32 q);

extern void STA_ACT_EFFECT_SetEmitterPos(char *,int,int);

extern void STA_ACT_EFFECT_KillEffect(char *,int);

extern void STA_ACT_EFFECT_KillSystem(u8 *unused, u8 *p);

extern void MUSICAL_MCSS_SetElemRot(void *unused, u8 *elem, s16 *a, s16 *b);

extern void MUSICAL_MCSS_ResumeRenderAnim(void **p);

extern void MUSICAL_MCSS_PauseRenderAnim(void *a);

extern void MUSICAL_MCSS_SetRenderAnim(void *a, u32 n);

extern void MUSICAL_MCSS_SetRenderVisible(int *p, int b);

extern int MUSICAL_MCSS_IsRenderVisible(u8 **p);

extern void MUSICAL_MCSS_ResetRender2(int a, int b);

u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e);

void STA_ACT_LIGHT_DeleteBillboardImage(char *p);

void STA_ACT_LIGHT_UpdateBillboard(u8 *p);

void STA_ACT_LIGHT_UpdateSprite(char *p);

void STA_ACT_LIGHT_CalcSpriteXform(u8 *p,u8 *q);

void STA_ACT_LIGHT_SetSpritePos(u8 *self, u8 *q);

void STA_ACT_LIGHT_UpdateElem(u8 *p);

void STA_ACT_LIGHT_CopyElemB(u8 *unused, u8 *elem);

void STA_ACT_LIGHT_SetElemFrame(u8 *p, u16 v);

void STA_ACT_LIGHT_AddPokemonElem(u8 *p,u8 *input);

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

void STA_ACT_LIGHT_ResetRenderAnim(void *a, Elem *b);

void STA_ACT_LIGHT_SetRenderAnim(int a, Elem *b, unsigned int c);

void STA_ACT_LIGHT_SetSlotVisible(BillboardImage *p, Elem *q, int v);

int STA_ACT_LIGHT_IsRenderVisible(int unused,u8 *p);

int STA_ACT_LIGHT_SetActorFlagB(int unused, int *p, int flag);

void STA_ACT_LIGHT_SetActorVisible(int a,u8 *p,int b);

extern char d_021F8464[];

extern s16 table[];

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
        if (((Record *)(p + i * 0x108))->flag == 1)
            STA_ACT_LIGHT_FreeElem((char *)((int)p), (char *)((int)(p + 0x14 + i * 0x108)));
    }
    BILLBOARD_DeleteImage((struct BbBoard *)((BillboardImage *)p)->board, ((BillboardImage *)p)->image);
    GFL_HEAP_Free((void *)((int)p));
}

void STA_ACT_LIGHT_UpdateBillboard(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) STA_ACT_LIGHT_CalcSpriteXform(p,p+20+i*264); }

/*
 * extent: two-byte zero padding before 021F7204.
 */
void STA_ACT_LIGHT_UpdateSprite(char *p) {
    int i;
    unsigned j;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1) {
            STA_ACT_LIGHT_SetSpritePos((unsigned char *)p, (unsigned char *)(p + 0x14 + i * 0x108));
            if (((BillboardImage *)p)->b != 0) {
                for (j = 0; j < STA_ACTING_GetElapsedTicks((u8 *)(((BillboardImage *)p)->b)); j++) {
                    if (*(void (**)(char *, char *))(p + i * 0x108 + 0x118) != 0)
                        (*(void (**)(char *, char *))(p + i * 0x108 + 0x118))(p, p + 0x14 + i * 0x108);
                }
            }
        }
    }
    MUSICAL_MCSS_UpdateObject((struct McssActorPool *)((BillboardImage *)p)->actorPool);
}

/*
 * ABI: 5350/535C/5368 forward r1 to6234/624C/6264; complete targets read vector/u16 despite legacy wrapper declarations omitting it.
 * original: delta.z stack slot is untouched before the RotZ multiplication and subtraction, which cancel its contribution; retain original stores only.
 */
void STA_ACT_LIGHT_CalcSpriteXform(u8 *p,u8 *elem)
{
    Vec3 pos;
    Vec3 scale;
    Vec3 delta;
    Mtx matrix;
    Vec3 *a;
    Vec3 *b;
    int angle;
    a=(Vec3 *)MUSICAL_MCSS_GetRenderFlags(*(u8 * *)&((Elem *)elem)->renderElem);
    b=(Vec3 *)MUSICAL_MCSS_GetRenderMatrix(*(char * *)&((Elem *)elem)->renderElem);
    VEC_Add((const Vec3 *)((Vec3 *)(elem+24)), (const Vec3 *)((Vec3 *)(elem+48)), (Vec3 *)&pos);
    angle=((Elem *)elem)->angle;
    delta.x=0;
    delta.y=b->y;
    MTX_RotZ33_(&matrix,-table[(angle>>4)*2],table[(angle>>4)*2+1]);
    MTX_MultVec33((const Vec3 *)&delta, &matrix, (Vec3 *)(elem+60));
    VEC_Subtract((const Vec3 *)&delta, (const Vec3 *)((Vec3 *)(elem+60)), (Vec3 *)(elem+60));
    pos.x=(pos.x-a->x-((Elem *)elem)->pivotShiftX)/16;
    pos.y=(0xc0000-(pos.y-a->y+((Elem *)elem)->pivotShiftY))/16;
    MUSICAL_MCSS_SetRenderPos(*(int * *)&((Elem *)elem)->renderElem,(int *)(&pos));
    MUSICAL_MCSS_SetRenderFrame(*(int * *)&((Elem *)elem)->renderElem,((Elem *)elem)->angle);
    scale.x=((Elem *)elem)->scaleX<<4;
    scale.y=((Elem *)elem)->scaleY<<4;
    scale.z=((Elem *)elem)->scaleZ<<4;
    if(((Elem *)elem)->flipX==1) scale.x*=-1;
    MUSICAL_MCSS_SetRenderScale(*(int * *)&((Elem *)elem)->renderElem,(int *)(&scale));
    ((Elem *)elem)->dirty=0;
    if(((Elem *)elem)->renderAnimActive==1) {
        ((Elem *)elem)->animTimer+=(u16)GFL_USE_GetRandom(2);
        if(((Elem *)elem)->animTimer>120) MUSICAL_MCSS_SetRenderDrawOffset((void *)(*(int *)&((Elem *)elem)->renderElem),1);
        else MUSICAL_MCSS_SetRenderDrawOffset((void *)(*(int *)&((Elem *)elem)->renderElem),0);
        if(((Elem *)elem)->animTimer>125) ((Elem *)elem)->animTimer=GFL_USE_GetRandom(120)/3U;
    }
}

/*
 * note 2026-10-05 (wD7 lane15): closed. The else arm of MUSICAL_MCSS_ElemHasAltDepth writes the whole v3.z store in
 *   each arm of the k - 7 test (q+0x20 plus 0xA000 or 0x5000, minus EA[4] << 11). The zz local that
 *   merged at the join was what swapped off (r4) and t (r6); tail merging rebuilds the shared add.
 */
void STA_ACT_LIGHT_SetSpritePos(u8 *self, u8 *q)
{
    Vec3 elemPos;
    Mtx mtx;
    Vec3 anchorShift;
    Vec3 rotatedOffset;
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
                    MUSICAL_MCSS_GetRenderFlags(*(u8 **)(q + 0x58));
                    z = t->height;
                    MTX_RotZ33_(&mtx, -table[(ang0 >> 4) * 2], table[(ang0 >> 4) * 2 + 1]);
                    MTX_MultVec33((const Vec3 *)&t->offsetX, &mtx, (Vec3 *)&rotatedOffset);
                    if (neg == 1) {
                        ang2 = (u16)(0x10000 - ang2);
                    }
                    if (MUSICAL_MCSS_ElemKeepsFlippedHeight(E) == 0 && neg == 1) {
                        z = -z;
                    }
                    MTX_MultVec33((const Vec3 *)&t->anchorX, &mtx, (Vec3 *)&anchorShift);
                    VEC_Subtract((const Vec3 *)&t->anchorX, (const Vec3 *)&anchorShift, (Vec3 *)&anchorShift);
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
    BILLBOARD_SetElemPos(*(void **)(self + 8), *(u32 *)(q + 0x5C), (struct Trip *)(&elemPos));
}

void STA_ACT_LIGHT_UpdateElem(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) { if(STA_ACT_LIGHT_IsRenderVisible((int)p,p+20+i*264)==1) STA_ACT_LIGHT_CopyElemB(p,p+20+i*264); } }

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
void STA_ACT_LIGHT_AddPokemonElem(u8 *image,u8 *input)
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
    ((Elem *)q)->value=1;
    ((Elem *)q)->dirty=1;
    ((Elem *)q)->flag=1;
    ((Elem *)q)->elemValue=0;
    ((Elem *)q)->keepUpright=0;
    ((Elem *)q)->noFlip=0;
    ((Elem *)q)->handler.active=0;
    ((Elem *)q)->renderElem=MUSICAL_MCSS_SetupRenderObj(((BillboardImage *)image)->renderObj,input,1);
    personal=POKE_PERSONAL_Create((u32)((MonInput *)input)->monsNo,(u32)((MonInput *)input)->form,(u32)((BillboardImage *)image)->heap);
    if(POKE_PERSONAL_GetParam(personal,16)==1) ((Elem *)q)->keepUpright=1;
    if(POKE_PERSONAL_GetParam(personal,34)==1) ((Elem *)q)->noFlip=1;
    POKE_PERSONAL_Delete(personal);
    ((Elem *)q)->x=0;
    ((Elem *)q)->y=0;
    ((Elem *)q)->z=0;
    ((Elem *)q)->offsetX=0;
    ((Elem *)q)->offsetY=0;
    ((Elem *)q)->offsetZ=0;
    ((Elem *)q)->scaleX=4096;
    ((Elem *)q)->scaleY=4096;
    ((Elem *)q)->scaleZ=4096;
    STA_ACT_LIGHT_SetupElem((u32)image,q,((MonInput *)input)->monsNo);
    ((Elem *)q)->angle=0;
    position=(int *)(q+24);
    scale=1024;
    records=input;
    records=records+20;
    for(i=0;i<9;i++) {
        id=*(u16 *)(input+20+6*i);
        record=records;
        record=record+6*i;
        row=q+4*i;
        ((Elem *)q)->slotRecord[i]=record;
        if(id!=255) {
            ((Elem *)q)->slotActive[i]=1;
            ((Elem *)q)->slotArc[i]=(int)MUSICAL_MCSS_CreateResourceArc(id);
            ((Elem *)q)->slotImage[i]=MUSICAL_MCSS_AddImage(((BillboardImage *)image)->actorPool,id,(u32)((Elem *)q)->slotArc[i],(int *)(q+24));
            MUSICAL_MCSS_SetElemRotZ(((BillboardImage *)image)->actorPool,((Elem *)q)->slotImage[i],scale,scale);
            MUSICAL_MCSS_SetElemVisible((u8 *)((BillboardImage *)image)->actorPool,(u8 *)((Elem *)q)->slotImage[i],0);
        } else {
            ((Elem *)q)->slotActive[i]=0;
            ((Elem *)q)->slotArc[i]=0;
            ((Elem *)q)->slotImage[i]=0;
        }
    }
    ((Elem *)q)->billboardIdx=BILLBOARD_AddElem(((BillboardImage *)image)->board,((BillboardImage *)image)->image,1024,768,(Vec3 *)(q+24),30,0,0);
    flag=1;
    BILLBOARD_SetElemVisible(((BillboardImage *)image)->board,((Elem *)q)->billboardIdx,&flag);
    ((Elem *)q)->animTimer=GFL_USE_GetRandom(150)>>1;
    ((Elem *)q)->renderAnimActive=1;
}

/*
 * extent: trailing two-byte zero padding before 021F77EC.
 */
void STA_ACT_LIGHT_FreeElem(char *image, char *elem) {
    u8 i;
    BILLBOARD_FreeElem(((BillboardImage *)image)->board, ((Elem *)elem)->billboardIdx);
    for (i = 0; i < 9; i++) {
        if (((Elem *)elem)->slotImage[i] != 0) {
            MUSICAL_MCSS_FreeElem((u8 *)((BillboardImage *)image)->actorPool, (u8 *)((Elem *)elem)->slotImage[i]);
            MUSICAL_MCSS_FreeResourceArc((struct Tagged *)((Elem *)elem)->slotArc[i]);
            ((Elem *)elem)->slotArc[i] = 0;
            ((Elem *)elem)->slotImage[i] = 0;
        }
    }
    MUSICAL_MCSS_FreeRenderObj((int)((BillboardImage *)image)->renderObj, (int)((Elem *)elem)->renderElem);
    ((Elem *)elem)->value = 0;
}

/*
 * Addresses are Black-image addresses.
 */
void STA_ACT_LIGHT_SetupElem(u32 unused, u8 *elem, u32 v)
{
    if (v == 0xe8) { ((Elem *)elem)->scaleX = 0xfb3; return; }
    if (v == 0x184 || v == 0x1fc) { ((Elem *)elem)->scaleX = 0xfc0; return; }
    if (v == 0x4b || v == 0xcd || v == 0xf5) { ((Elem *)elem)->scaleX = 0xfcc; return; }
    if (v == 0x2d || v == 0x142) { ((Elem *)elem)->scaleX = 0x1040; return; }

    if (v == 9 || v == 0x21 || v == 0x3d || v == 0x41 || v == 0x4c ||
        v == 0x7a || v == 0x7b || v == 0x8d || v == 0xd6 || v == 0xeb ||
        v == 0xfd || v == 0x100 || v == 0x108 || v == 0x115 || v == 0x11e ||
        v == 0x13b || v == 0x15b || v == 0x1b2 || v == 0x1bc || v == 0x276) {
        ((Elem *)elem)->scaleY = 0xfcc;
        return;
    }
    if (v == 0x25 || v == 0xd7 || v == 0xdb || v == 0x16a || v == 0x250 ||
        v == 0x264) {
        ((Elem *)elem)->scaleY = 0xfd9;
        return;
    }
    if (v == 0x12 || v == 0x35 || v == 0x7e || v == 0x80 || v == 0x9c ||
        v == 0x9d || v == 0xb5 || v == 0xd0 || v == 0xf6 || v == 0xf8 ||
        v == 0x134 || v == 0x162 || v == 0x17a || v == 0x189 || v == 0x18e ||
        v == 0x1a3 || v == 0x1cc || v == 0x222 || v == 0x231 || v == 0x26f ||
        v == 0x283) {
        ((Elem *)elem)->scaleY = 0xfe6;
        return;
    }
    if (v == 0x26 || v == 0x120) { ((Elem *)elem)->scaleY = 0xff3; return; }

    if (v == 0x1c1) {
        ((Elem *)elem)->scaleX = 0x1040;
        ((Elem *)elem)->scaleY = 0xfcc;
        return;
    }
    if (v == 0x26e) {
        ((Elem *)elem)->scaleX = 0xfc0;
        ((Elem *)elem)->scaleY = 0xfcc;
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
    if(*(int *)(elem+132+index*4)==0 || ((Elem *)elem)->handler.active!=0) return;
    v=MUSICAL_MCSS_GetElemB((void *)MUSICAL_MCSS_GetActorPoolResource((u8 *)((BillboardImage *)image)->actorPool),**(u16 **)(elem+168+index*4));
    ((Elem *)elem)->tail.anim.count=0;
    ((Elem *)elem)->tail.anim.index=index;
    ((Elem *)elem)->tail.anim.a=0;
    GFL_USE_PlaySeInSlot((u32)d_021F832C[v],2);
    ((BillboardImage *)image)->count+=1;
    switch(v) {
    case 0: STA_ACT_LIGHT_AnimNone(image,elem); ((Elem *)elem)->handler.animFunc=STA_ACT_LIGHT_StopSe; break;
    case 1: STA_ACT_LIGHT_AnimA(image,elem); ((Elem *)elem)->handler.animFunc=(void (*)(char *,char *))STA_ACT_LIGHT_AnimB; break;
    case 2: STA_ACT_LIGHT_AnimC(image,elem); ((Elem *)elem)->handler.animFunc=(void (*)(char *,char *))STA_ACT_LIGHT_AnimD; break;
    case 3: STA_ACT_LIGHT_AnimE(image,elem); ((Elem *)elem)->handler.animFunc=STA_ACT_LIGHT_AnimF; break;
    case 4: STA_ACT_LIGHT_AnimG(image,elem); ((Elem *)elem)->handler.animFunc=STA_ACT_LIGHT_AnimH; break;
    }
}

int STA_ACT_LIGHT_IsElemActive(char *p,char *elem)
{
    if(((Elem *)elem)->handler.active!=0) return 1;
    return 0;
}

void STA_ACT_LIGHT_AnimNone(char *p,char *q)
{
}

void STA_ACT_LIGHT_StopSe(char *image, char *elem) {
    ElemTail *tail = &((Elem *)elem)->tail.anim;
    s16 *v = *(s16 **)(elem + 0xa8 + tail->index * 4);
    v[1] += 0x1000;
    tail->count += 1;
    if (tail->count >= 0xc0) {
        ((Elem *)elem)->handler.active = 0;
        ((BillboardImage *)image)->count -= 1;
        if (((BillboardImage *)image)->count == 0) GFL_USE_StopSeSlot(2);
    }
}

/*
 * extent: two-byte zero padding before 021F7BA8.
 */
void STA_ACT_LIGHT_AnimA(char *image, char *elem) {
    ElemTailSigned *t = &((Elem *)elem)->tail.animSigned;
    int a = (int)STA_ACTING_GetEffectSystem((void *)(((BillboardImage *)image)->b));
    char *r = (char *)MUSICAL_MCSS_GetRenderElem((u8 *)((Elem *)elem)->renderElem, ((Elem *)elem)->tail.anim.index);
    Vec3 v;
    t->a = (int)STA_ACT_EFFECT_StartSystem((char *)a, 0x35);
    if (((Elem *)elem)->flag == 1 && ((MssRenderElem *)r)->active == 1) {
        MUSICAL_MCSS_SetElemScale((u32)((BillboardImage *)image)->actorPool, *(int *)(elem + 0x84 + t->index * 4), (u32)(&v));
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z += 0x1000;
    } else {
        VEC_Add((const Vec3 *)((Vec3 *)(elem + 0x18)), (const Vec3 *)((Vec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)((Elem *)elem)->renderElem)), (Vec3 *)&v);
        v.x /= 16;
        v.y = (0xc0000 - v.y) / 16;
        v.z -= 0x1c000;
    }
    STA_ACT_EFFECT_StartEffect(t->a, 0, (Vec3 *)&v);
}

void STA_ACT_LIGHT_AnimB(u8 *image,u8 *elem)
{
    ElemTail *t=&((Elem *)elem)->tail.anim;
    u8 *r=MUSICAL_MCSS_GetRenderElem((u8 *)((Elem *)elem)->renderElem, ((Elem *)elem)->tail.anim.index);
    Vec3 v;
    int a;
    if(((Elem *)elem)->flag==1 && ((MssRenderElem *)r)->active==1) {
        MUSICAL_MCSS_SetElemScale((u32)((BillboardImage *)image)->actorPool,*(int *)(elem+132+t->index*4),(u32)(&v));
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z+=0x1000;
    } else {
        VEC_Add((const Vec3 *)((Vec3 *)(elem+24)), (const Vec3 *)((Vec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)((Elem *)elem)->renderElem)), (Vec3 *)&v);
        v.x/=16;
        v.y=(0xc0000-v.y)/16;
        v.z-=0x1c000;
    }
    STA_ACT_EFFECT_SetEmitterPos((char *)t->a,0,(int)&v);
    t->count++;
    if(t->count>=180) {
        a=(int)STA_ACTING_GetEffectSystem((void *)(((BillboardImage *)image)->b));
        STA_ACT_EFFECT_KillEffect((char *)t->a,0);
        STA_ACT_EFFECT_KillSystem((void *)a,(void *)t->a);
        ((Elem *)elem)->handler.active=0;
        ((BillboardImage *)image)->count-=1;
        if(((BillboardImage *)image)->count==0) GFL_USE_StopSeSlot(2);
    }
}

void STA_ACT_LIGHT_AnimC(char *image, char *elem) {
    ElemTailSigned *t = &((Elem *)elem)->tail.animSigned;
    char *r = (char *)MUSICAL_MCSS_GetRenderElem((u8 *)((Elem *)elem)->renderElem, ((Elem *)elem)->tail.anim.index);
    Vec3 v;
    ((Elem *)elem)->slotActive[((Elem *)elem)->tail.anim.index] = 0;
    if (((Elem *)elem)->flag == 0 || ((MssRenderElem *)r)->active == 0) {
        VEC_Add((Vec3 *)((Vec3 *)(elem + 0x18)), (Vec3 *)((Vec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)((Elem *)elem)->renderElem)), (Vec3 *)((Vec3 *)&v));
        v.z -= 0x1c000;
        MUSICAL_MCSS_SetElemPos(((BillboardImage *)image)->actorPool, (struct McssActorElem *)(*(int *)(elem + 0x84 + t->index * 4)), (s32 *)((Vec3 *)&v));
    }
    MUSICAL_MCSS_SetElemVisible((u8 *)((BillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 1);
    MUSICAL_MCSS_SetElemField(((BillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 0);
    MUSICAL_MCSS_SetElemRotZ(((BillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 1024, 1024);
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
    ElemTail *t=&((Elem *)elem)->tail.anim;
    Vec3 v;
    unsigned long offset;
    u16 time=t->count;
    int angle=(time<<9)%65536;
    long s=table[(angle>>4)*2];
    MUSICAL_MCSS_SetElemScale(*(u32 *)(p+0x10),*(u32 *)(elem+0x84+t->index*4),(u32)&v);
    offset=205;
    v.x+=fxmul((time/3)*offset,s);
    v.y-=3072;
    MUSICAL_MCSS_SetElemPos((void *)((*(u32 *)(p+0x10))), (struct McssActorElem *)((int)(*(void **)(elem+0x84+t->index*4))), (s32 *)((Vec3 *)(&v.x)));
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
    ElemTailSigned *t = &((Elem *)elem)->tail.animSigned;
    char *r = (char *)MUSICAL_MCSS_GetRenderElem((u8 *)((Elem *)elem)->renderElem, ((Elem *)elem)->tail.anim.index);
    Vec3 v;
    ((Elem *)elem)->slotActive[((Elem *)elem)->tail.anim.index] = 0;
    if (((Elem *)elem)->flag == 0 || ((MssRenderElem *)r)->active == 0) {
        VEC_Add((Vec3 *)((Vec3 *)((Vec3 *)(elem + 0x18))), (Vec3 *)((Vec3 *)((Vec3 *)MUSICAL_MCSS_GetRenderMatrix((char *)((Elem *)elem)->renderElem))), (Vec3 *)((Vec3 *)&v));
        MUSICAL_MCSS_SetElemPos(((BillboardImage *)image)->actorPool, (struct McssActorElem *)(*(int *)(elem + 0x84 + t->index * 4)), (s32 *)((Vec3 *)&v));
    }
    t->b = -0x3000;
    MUSICAL_MCSS_SetElemVisible((u8 *)((BillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 1);
    MUSICAL_MCSS_SetElemField(((BillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 0);
    MUSICAL_MCSS_SetElemRotZ(((BillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)), 1024, 1024);
}

/*
 * extent: 220-byte lead, 7FA8 two-byte return stub; 7FAA zero alignment padding.
 * function_starts: 0x021F7FA8
 */
void STA_ACT_LIGHT_AnimF(char *image,char *elem)
{
    ElemTail *t=&((Elem *)elem)->tail.anim;
    Vec3 v;
    Scale s;
    MUSICAL_MCSS_SetElemScale((u32)((BillboardImage *)image)->actorPool,*(int *)(elem+0x84+t->index*4),(unsigned int)(&v));
    t->b+=164;
    v.x-=2867;
    v.y+=t->b;
    v.z=0xc8000;
    MUSICAL_MCSS_SetElemPos(((BillboardImage *)image)->actorPool, (struct McssActorElem *)(*(int *)(elem+0x84+t->index*4)), (s32 *)((Vec3 *)&v));
    MUSICAL_MCSS_SetElemRot(((BillboardImage *)image)->actorPool,(u8 *)(*(int *)(elem+0x84+t->index*4)),&s.x,&s.y);
    s.x+=12;
    s.y+=12;
    MUSICAL_MCSS_SetElemRotZ(((BillboardImage *)image)->actorPool,(u8 *)(*(int *)(elem+0x84+t->index*4)),s.x,s.y);
    t->count++;
    if(t->count>=180) {
        MUSICAL_MCSS_SetElemVisible((u8 *)((BillboardImage *)image)->actorPool,(u8 *)(*(int *)(elem+0x84+t->index*4)),0);
        ((Elem *)elem)->handler.active=0;
        ((BillboardImage *)image)->count-=1;
        if(((BillboardImage *)image)->count==0) GFL_USE_StopSeSlot(2);
    }
}

void STA_ACT_LIGHT_AnimG(char *unused0, char *unused1)
{
}

void STA_ACT_LIGHT_AnimH(char *image, char *elem) {
    ElemTail *t = &((Elem *)elem)->tail.anim;
    u16 angle = ((int)t->count << 11) % 65536;
    t->count++;
    if (t->count >= 0xb4) {
        ((Elem *)elem)->handler.active = 0;
        ((BillboardImage *)image)->count -= 1;
        if (((BillboardImage *)image)->count == 0) GFL_USE_StopSeSlot(2);
        return;
    }
    MUSICAL_MCSS_SetElemRotZ(((BillboardImage *)image)->actorPool, (u8 *)(*(int *)(elem + 0x84 + t->index * 4)),
                  table[(angle >> 4) * 2] / 8 + 1024,
                  table[(angle >> 4) * 2 + 1] / 8 + 1024);
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
    ((Elem *)elem)->angle = v;
    if (((Elem *)elem)->keepUpright == 1)
        ((Elem *)elem)->angle = 0;
    ((Elem *)elem)->dirty = 1;
}

void STA_ACT_LIGHT_SetActorOffset(void *unused,u32 *p,const u32 *q) { p[12]=q[0]; p[13]=q[1]; p[14]=q[2]; if(p[4]==1) p[13]=0; p[1]=1; }

void STA_ACT_LIGHT_StartRenderAnim(int unused,u8 *elem) { MUSICAL_MCSS_ResumeRenderAnim(((Elem *)elem)->renderElem); ((Elem *)elem)->renderAnimActive=1; }

/*
 * Struct parameter fixes the zero/load/store scheduling. The extent's
 * 021F80C8 tail stub is included; 021F53CC has its own verified shard.
 */
void STA_ACT_LIGHT_ResetRenderAnim(void *unused, Elem *elem)
{
    MUSICAL_MCSS_PauseRenderAnim(elem->renderElem);
    elem->renderAnimActive = 0;
    MUSICAL_MCSS_SetRenderDrawOffset(elem->renderElem, 0);
}

void STA_ACT_LIGHT_SetRenderAnim(int unused, Elem *elem, unsigned int anim)
{
    MUSICAL_MCSS_SetRenderAnim(elem->renderElem, anim);
}

/*
 * note: handed label 021F80D6 follows the parameter-home push.
 */
void STA_ACT_LIGHT_SetSlotVisible(BillboardImage *p, Elem *q, int v) {
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
int STA_ACT_LIGHT_IsRenderVisible(int a,u8 *elem) { return MUSICAL_MCSS_IsRenderVisible(((Elem *)elem)->renderElem); }

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

void STA_ACT_LIGHT_SetActorVisible(int unused,u8 *elem,int visible) { ((Elem *)elem)->flag=visible; MUSICAL_MCSS_ResetRender2((int)(((Elem *)elem)->renderElem),visible); ((Elem *)elem)->dirty=1; }

/* Sets the light element's value word and marks the element updated. */
int STA_ACT_LIGHT_SetElemValue(void *unused, int *elem, int value)
{
    elem[3] = value;
    elem[1] = 1;
    return 1;
}
