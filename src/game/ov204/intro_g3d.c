/*
 * file:     intro_g3d.c
 * unit:     yes
 * function: INTRO_G3D_AddPokemonSlot, INTRO_G3D_SetVanishFlag, INTRO_G3D_SetSlotAnim, INTRO_G3D_GetSlotAnimFinished, INTRO_G3D_ClearSlotAnimFinished, INTRO_G3D_SetSlotAlpha, INTRO_G3D_SetSlotMepachi, INTRO_G3D_OnAnimEnd, INTRO_G3D_MoveSlot, INTRO_G3D_MoveSlot1, INTRO_G3D_UpdateIdleAnim, INTRO_G3D_Create, INTRO_G3D_Delete, INTRO_G3D_Draw, INTRO_G3D_UpdateIntro, INTRO_G3D_SetVisible, INTRO_G3D_SetAnimMode, INTRO_G3D_UpdateAnimMode, INTRO_G3D_UpdateAnimFrame, INTRO_G3D_SetAnimFrame
 * address:  0x021BF67C
 * region:   ov204
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from intro_g3d.c by tools/splitfile.py.
 *
 * symbols:
 *   gIntroG3dDefaultPos 0x021C08FC data
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   func_020307B0 0x020307B0 arm
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetAnimeIndex 0x02016028 thumb
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   MCSS_SetAnimCallback 0x02015F2C thumb
 *   func_0207D63C 0x0207D63C arm
 *   MCSS_SetAlpha 0x02015FBC thumb
 *   MCSS_SetMepachiFlag 0x02015DB0 thumb
 *   MCSS_ResetMepachiFlag 0x02015DC0 thumb
 *   MCSS_RestartAnime 0x02016374 thumb
 *   MCSS_GetPosition 0x02015C30 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   func_02030734 0x02030734 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_DisableObjectAnime 0x020477D4 arm
 *   gIntroG3dSite 0x021C0B00 data a1
 *   gIntroG3dCameraPos 0x021C0914 data a4
 *   gIntroG3dCameraTarget 0x021C0920 data a4
 *   gIntroG3dCameraUp 0x021C0908 data a4
 *   gIntroG3dUnitSetup 0x021C093C data a4
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   func_02048AD0 0x02048AD0 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   G3D_SYSTEM_IncObjectAnimeFrame 0x020478B8 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   MCSS_Add  0x020159C8  thumb  arm9
 *   MCSS_TOOL_MakeAddWorkFromPP  0x02017100  thumb  arm9
 *   POKE_TOOL_Create  0x020173F0  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "intro_types.h"

struct Obj;

struct Rec;

struct Stats;

struct Sub150;

struct G3dSys;

struct Owner;

struct Ctx;

struct Light;

struct Arg;

struct AnmCtl;

typedef struct {u32 x,y,z;} Vec3;

/*
 * The intro 3D effect object (0x30 allocated). Created by INTRO_G3D_Create,
 * drawn by INTRO_G3D_Draw, updated by INTRO_G3D_UpdateIntro.
 */
typedef struct IntroG3dWork {
    void *owner;                /* 0x00 */
    unsigned short heapId;      /* 0x04 */
    unsigned char pad_6[2];
    void *util;                 /* 0x08: G3D_UTIL_Create result */
    void *camera;               /* 0x0C: G3D_CAMERA_Create result */
    unsigned short unitId;      /* 0x10: G3D_UTIL_AddUnit result */
    unsigned char pad_12[2];
    unsigned int visible;       /* 0x14: draw enable */
    unsigned int active;        /* 0x18: set on create, checked by draw */
    unsigned int animMode;      /* 0x1C: INTRO_G3D_SetAnimMode mode */
    unsigned int animFinished;  /* 0x20 */
    unsigned int introState;    /* 0x24: INTRO_G3D_UpdateIntro state */
    unsigned int animFrame;     /* 0x28: animation frame */
    unsigned char pad_2C[4];    /* 0x2C: allocation tail, never touched */
} IntroG3dWork;

extern void *POKE_TOOL_Create(unsigned short, unsigned short, unsigned long long, unsigned short);

extern void MCSS_TOOL_MakeAddWorkFromPP(void *p, struct Stats *out, u32 lvl);

extern u32 func_020307B0(void *p);

extern struct Rec *MCSS_Add(struct Obj *obj, u32 a1, u32 a2, u32 a3, const struct Sub150 *src);

extern void MCSS_SetScale(void *p, u32 *src);

extern void MCSS_SetAnmStopFlag(void *);

extern unsigned int GF_STANDARD_Rand(void);

extern void MCSS_SetAnimCallback(void *, void *, void (*)(void *, void *), int);

extern void MCSS_ResetVanishFlag(void *);

extern void MCSS_SetVanishFlag(void *);

extern void MCSS_SetAnimeIndex(void *, unsigned int);

extern void MCSS_ResetAnmStopFlag(void *);

extern void func_0207D63C(void *,int,int,int,int);

extern void MCSS_SetAlpha(char *p, int v);

extern void MCSS_SetMepachiFlag(void *);

extern void MCSS_ResetMepachiFlag(void *);

extern void MCSS_RestartAnime(void *);

extern void MCSS_GetPosition(void *p, u32 *out);

extern void MCSS_SetPosition(void *p, u32 *src);

extern void *func_02030734(u32,u32,int,const char *,u16);

extern void *G3D_UTIL_Create(u16,u16,u32);

extern void *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,Vec3 *,Vec3 *,Vec3 *,u32);

extern u16 G3D_UTIL_AddUnit(void *,const void *);

extern u32 func_02048A18(u8 *a0, int i);

extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);

extern int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);

extern void G3D_CAMERA_Delete(void *);

extern void G3D_UTIL_RemoveUnit(struct Ctx *,u32);

extern void G3D_UTIL_Delete(struct Rec *);

extern void func_02048AD0(struct Light *l);

extern void MTX_Identity33_(void *);

extern void G3D_SYSTEM_DrawObject(void *a0, struct Arg *a1);

extern void GFL_USE_PlaySeDefaultVolume(u32 a);

extern int G3D_SYSTEM_IncObjectAnimeFrame(void *, int, int);

extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);

void INTRO_G3D_AddPokemonSlot(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);

void INTRO_G3D_SetVanishFlag(u8 *p, int flag, u8 index);

void INTRO_G3D_SetSlotAnim(char *p, unsigned int i, unsigned int flag, unsigned int v);

unsigned int INTRO_G3D_GetSlotAnimFinished(char *p, u8 i);

void INTRO_G3D_ClearSlotAnimFinished(u8 *p, u8 index);

void INTRO_G3D_SetSlotAlpha(u8 *p, u8 index, u32 alpha);

void INTRO_G3D_SetSlotMepachi(u8 *p, u8 index, int flag);

void INTRO_G3D_OnAnimEnd(IntroMcssSlot *slot);

int INTRO_G3D_MoveSlot(char *p, unsigned int i, int step, int limit);

int INTRO_G3D_MoveSlot1(char *p,int delta,int limit);

void INTRO_G3D_UpdateIdleAnim(char *p);

char *INTRO_G3D_Create(void *owner,int kind,u32 heap);

void INTRO_G3D_Delete(char *p);

void INTRO_G3D_Draw(char *p);

int INTRO_G3D_UpdateIntro(char *p);

void INTRO_G3D_SetVisible(char *p, int v);

void INTRO_G3D_SetAnimMode(char *p, unsigned int v);

int INTRO_G3D_UpdateAnimMode(char *p);

int INTRO_G3D_UpdateAnimFrame(int *p);

void INTRO_G3D_SetAnimFrame(char *p,unsigned value);

extern const IntroVec gIntroG3dDefaultPos;

extern const Vec3 gIntroG3dCameraPos,gIntroG3dCameraTarget,gIntroG3dCameraUp;

extern const char gIntroG3dSite[];

extern const char gIntroG3dUnitSetup[];

void INTRO_G3D_AddPokemonSlot(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    char data[36];
    IntroVec pos = gIntroG3dDefaultPos;
    void *tmp = POKE_TOOL_Create((unsigned short)species, 0, 0, work->heapId);
    MCSS_TOOL_MakeAddWorkFromPP(tmp, (struct Stats *)data, 0);
    func_020307B0(tmp);
    work->slots[i].object = MCSS_Add(work->sys, a, b, c, (const struct Sub150 *)data);
    MCSS_SetScale(work->slots[i].object, (u32 *)(&pos));
    MCSS_SetAnmStopFlag(work->slots[i].object);
    work->slots[i].animFinished = 0;
    work->slots[i].loopAnim = 1;
    work->idleTimer = 20 * (unsigned int)(((unsigned long long)GF_STANDARD_Rand() * 5) >> 32) + 200;
    MCSS_SetAnimCallback(work->slots[i].object, &work->slots[i], (void (*)(void *, void *))INTRO_G3D_OnAnimEnd, 0);
}

void INTRO_G3D_SetVanishFlag(u8 *p, int flag, u8 index)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    if(flag==1)MCSS_ResetVanishFlag(work->slots[index].object);
    else MCSS_SetVanishFlag(work->slots[index].object);
}

/*
 * 10-byte getter follower 0x021BF77C is included; function_starts seed. Enum zero separates field and argument clears.
 */
void INTRO_G3D_SetSlotAnim(char *p, unsigned int i, unsigned int flag, unsigned int v)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    enum { Zero } zero;
    MCSS_SetAnimeIndex(work->slots[i].object, flag);
    MCSS_ResetAnmStopFlag(work->slots[i].object);
    zero = Zero;
    work->slots[i].animFinished = zero;
    work->slots[i].loopAnim = v;
    MCSS_SetAnimCallback(work->slots[i].object, &work->slots[i], (void (*)(void *, void *))INTRO_G3D_OnAnimEnd, 0);
}

unsigned int INTRO_G3D_GetSlotAnimFinished(char *p, u8 i)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    return work->slots[i].animFinished;
}

void INTRO_G3D_ClearSlotAnimFinished(u8 *p, u8 index)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    work->slots[index].animFinished=0;
}

/*
 * prototype: The shifts at 021BF7B8/021BF7BC narrow the outgoing alpha to u8.
 */
void INTRO_G3D_SetSlotAlpha(u8 *p, u8 index, u32 alpha)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    func_0207D63C((void *)0x04000050,1,9,0,0);
    if(alpha>31)alpha=31;
    MCSS_SetAlpha((char *)work->slots[index].object,(u8)alpha);
}

void INTRO_G3D_SetSlotMepachi(u8 *p, u8 index, int flag)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    if(flag!=0)MCSS_SetMepachiFlag(work->slots[index].object);
    else MCSS_ResetMepachiFlag(work->slots[index].object);
}

void INTRO_G3D_OnAnimEnd(IntroMcssSlot *slot)
{
    slot->animFinished=1;
    if(slot->loopAnim==1)MCSS_RestartAnime(slot->object);
}

int INTRO_G3D_MoveSlot(char *p, unsigned int i, int step, int limit)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    IntroVec pos;
    int done;
    MCSS_GetPosition(work->slots[i].object, (u32 *)(&pos));
    done = 1;
    pos.v[0] += step;
    if (pos.v[0] != limit)
    {
        if ((step > 0 && pos.v[0] > limit) || (step < 0 && pos.v[0] < limit))
            pos.v[0] = limit;
        else
            done = 0;
    }
    MCSS_SetPosition(work->slots[i].object, (u32 *)(&pos));
    if (work->slots[i].animFinished == 1)
        MCSS_SetAnmStopFlag(work->slots[i].object);
    return done;
}

/*
 * extent: two zero alignment bytes at 0x021BF896 follow; no follower.
 */
int INTRO_G3D_MoveSlot1(char *p,int delta,int limit)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    u32 v[3];
    int done;
    MCSS_GetPosition(work->slots[1].object,v);
    v[1]-=delta;
    if((int)v[1]<=limit) { v[1]=limit;done=1; } else done=0;
    MCSS_SetPosition(work->slots[1].object,v);
    return done;
}

void INTRO_G3D_UpdateIdleAnim(char *p)
{
    IntroMcssWork *work = (IntroMcssWork *)p;
    if (work->slots[1].animFinished != 0)
    {
        if (work->idleTimer == 0)
        {
            work->idleTimer = 20 * (unsigned int)(((unsigned long long)GF_STANDARD_Rand() * 5) >> 32) + 200;
            INTRO_G3D_SetSlotAnim(p, 1, 0, 1);
            return;
        }
        MCSS_SetAnmStopFlag(work->slots[1].object);
        --work->idleTimer;
    }
}

char *INTRO_G3D_Create(void *owner,int kind,u32 heap)
{
    IntroG3dWork *p;
    Vec3 a,b,c;
    void *obj;
    p=func_02030734(heap,48,1,gIntroG3dSite,162);
    p->heapId=heap;
    p->owner=owner;
    p->util=G3D_UTIL_Create(10,16,heap);
    a=gIntroG3dCameraPos;b=gIntroG3dCameraTarget;c=gIntroG3dCameraUp;
    p->camera=G3D_CAMERA_Create(2,24576,(u32)-24576,(u32)-32768,32768,4096,4194304,4096,&a,&b,&c,heap);
    if(kind!=7){
        p->unitId=G3D_UTIL_AddUnit(p->util,gIntroG3dUnitSetup);
        obj=(void *)func_02048A18(p->util,p->unitId);
        G3D_SYSTEM_EnableObjectAnime(obj,3);G3D_SYSTEM_EnableObjectAnime(obj,4);
        G3D_SYSTEM_DisableObjectAnime(obj,0);G3D_SYSTEM_DisableObjectAnime(obj,1);G3D_SYSTEM_DisableObjectAnime(obj,2);
    }else p->unitId=0xffff;
    p->active=1;
    return (char *)p;
}

void INTRO_G3D_Delete(char *p)
{
    IntroG3dWork *work = (IntroG3dWork *)p;
    u16 id;
    G3D_CAMERA_Delete(work->camera);
    id=work->unitId;
    if(id!=65535) G3D_UTIL_RemoveUnit(work->util,id);
    G3D_UTIL_Delete(work->util);
    func_020307B0(p);
}

void INTRO_G3D_Draw(char *p)
{
    struct Transform { int pos[3]; int scale[3]; int matrix[9]; } t;
    IntroG3dWork *work = (IntroG3dWork *)p;
    func_02048AD0(work->camera);
    if (work->visible != 0 && work->active != 0)
    {
        t.pos[0] = 0;
        t.pos[1] = 0;
        t.pos[2] = 0;
        t.scale[0] = 4096;
        t.scale[1] = 4096;
        t.scale[2] = 4096;
        MTX_Identity33_(t.matrix);
        G3D_SYSTEM_DrawObject((void *)func_02048A18(work->util, work->unitId), (struct Arg *)(&t));
    }
}

int INTRO_G3D_UpdateIntro(char *p)
{
    IntroG3dWork *work = (IntroG3dWork *)p;
    switch (work->introState)
    {
    case 0:
        func_0207D63C((void *)0x04000050, 1, 9, 0, 0);
        GFL_USE_PlaySeDefaultVolume(0x555);
        ++work->introState;
    case 1:
    {
        void *obj = (void *)func_02048A18(work->util, work->unitId);
        int a = G3D_SYSTEM_IncObjectAnimeFrame(obj, 3, 4096);
        int b = G3D_SYSTEM_IncObjectAnimeFrame(obj, 4, 4096);
        if (a == 0 && b == 0)
        {
            G3D_SYSTEM_DisableObjectAnime(obj, 3);
            G3D_SYSTEM_DisableObjectAnime(obj, 4);
            G3D_SYSTEM_EnableObjectAnime(obj, 0);
            G3D_SYSTEM_EnableObjectAnime(obj, 1);
            G3D_SYSTEM_EnableObjectAnime(obj, 2);
            INTRO_G3D_SetAnimFrame(p, 60);
            ++work->introState;
        }
        break;
    }
    case 2:
        return 1;
    }
    return 0;
}

void INTRO_G3D_SetVisible(char *p, int v)
{
    IntroG3dWork *work = (IntroG3dWork *)p;
    work->visible = v;
}

void INTRO_G3D_SetAnimMode(char *p, unsigned int v)
{
    IntroG3dWork *work = (IntroG3dWork *)p;
    work->animMode = v;
    work->animFinished = 0;
    switch (v)
    {
    case 0:
        work->animFrame = 60;
        work->animMode = 1;
        break;
    case 1: work->animFrame = 70; break;
    case 2: work->animFrame = 50; break;
    case 3: work->animFrame = 50; break;
    case 4: work->animFrame = 70; break;
    }
}

int INTRO_G3D_UpdateAnimMode(char *p)
{
    IntroG3dWork *work = (IntroG3dWork *)p;
    switch (work->animMode)
    {
    case 0: break;
    case 1:
        --work->animFrame;
        INTRO_G3D_SetAnimFrame(p, work->animFrame);
        if (work->animFrame == 50) return 1;
        break;
    case 2:
        ++work->animFrame;
        INTRO_G3D_SetAnimFrame(p, work->animFrame);
        if (work->animFrame == 70) return 1;
        break;
    case 3:
        --work->animFrame;
        INTRO_G3D_SetAnimFrame(p, work->animFrame);
        if (work->animFrame == 0) return 1;
        break;
    case 4:
        ++work->animFrame;
        INTRO_G3D_SetAnimFrame(p, work->animFrame);
        if (work->animFrame == 120) return 1;
        break;
    }
    return 0;
}

int INTRO_G3D_UpdateAnimFrame(int *p)
{
    IntroG3dWork *work = (IntroG3dWork *)p;
    if (work->animMode == 3) {
        work->animFrame = work->animFrame + 1;
        INTRO_G3D_SetAnimFrame((char *)p, work->animFrame);
    } else {
        work->animFrame = work->animFrame - 1;
        INTRO_G3D_SetAnimFrame((char *)p, work->animFrame);
    }
    return work->animFrame == 60;
}

void INTRO_G3D_SetAnimFrame(char *p,unsigned value)
{
    IntroG3dWork *work = (IntroG3dWork *)p;
    void *ctl;
    int frame;
    float f;
    ctl=(void *)func_02048A18(work->util,work->unitId);
    if(value!=0) f=0.5f+(float)(value<<12);
    else f=(float)(value<<12)-0.5f;
    frame=(int)f;
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,0,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,1,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,2,&frame);
}
