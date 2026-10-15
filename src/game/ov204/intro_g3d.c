/*
 * file:     intro_g3d.c
 * unit:     yes
 * function: func_021BF67C, func_021BF720, func_021BF744, func_021BF77C, func_021BF788, func_021BF794, func_021BF7CC, func_021BF7F0, func_021BF804, func_021BF864, func_021BF898, func_021BF8DC, func_021BF9D0, func_021BF9FC, func_021BFA40, func_021BFAE4, func_021BFAE8, func_021BFB2C, func_021BFBA0, func_021BFBC8
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
 *   defaultPos_021C08FC 0x021C08FC data
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
 *   site_021C0B00 0x021C0B00 data a1
 *   va 0x021C0914 data a4
 *   vb 0x021C0920 data a4
 *   vc 0x021C0908 data a4
 *   setup 0x021C093C data a4
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
#include "../../matched/include/Obj10881.h"
#include "../../matched/include/Obj10882.h"
#include "../../matched/include/Obj14628.h"
#include "../../matched/include/Obj06674.h"
#include "../../matched/include/Obj02921.h"
#include "../../matched/include/Obj08385.h"
#include "../../matched/include/Obj06675.h"
#include "../../matched/include/Obj06676.h"
#include "../../matched/include/Obj25391.h"
#include "../../matched/include/Obj03922.h"
#include "../../matched/include/Obj01974.h"
#include "../../matched/include/Obj14629.h"
#include "intro_g3d_shared_types.h"

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

struct Vec { int v[3]; };

typedef unsigned char  u8;

typedef struct {u32 x,y,z;} Vec3;

typedef signed int     s32;

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

void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i);

void func_021BF720(u8 *p, int flag, u8 index);

void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v);

unsigned int func_021BF77C(char *p, u8 i);

void func_021BF788(u8 *p, u8 index);

void func_021BF794(u8 *p, u8 index, u32 alpha);

void func_021BF7CC(u8 *p, u8 index, int flag);

void func_021BF7F0(u8 *p);

int func_021BF804(char *p, unsigned int i, int step, int limit);

int func_021BF864(char *p,int delta,int limit);

void func_021BF898(char *p);

char *func_021BF8DC(void *owner,int kind,u32 heap);

void func_021BF9D0(char *p);

void func_021BF9FC(char *p);

int func_021BFA40(char *p);

void func_021BFAE4(char *p, int v);

void func_021BFAE8(char *p, unsigned int v);

int func_021BFB2C(char *p);

int func_021BFBA0(int *p);

void func_021BFBC8(char *p,unsigned value);

extern const struct Vec defaultPos_021C08FC;

extern const Vec3 va,vb,vc;

extern const char site_021C0B00[];

extern const char setup[];

void func_021BF67C(char *p, unsigned int a, unsigned int b, unsigned int c, unsigned int species, unsigned char i)
{
    char data[36];
    struct Vec pos = defaultPos_021C08FC;
    void *tmp = POKE_TOOL_Create((unsigned short)species, 0, 0, ((struct Obj10881 *)p)->f0);
    char *base = p + 8;
    unsigned int off = i * 12;
    MCSS_TOOL_MakeAddWorkFromPP(tmp, (struct Stats *)data, 0);
    func_020307B0(tmp);
    *(void **)(base + off) = MCSS_Add(((struct Obj10881 *)p)->f4, a, b, c, (const struct Sub150 *)data);
    MCSS_SetScale(*(void **)(base + off), (u32 *)(&pos));
    MCSS_SetAnmStopFlag(*(void **)(base + off));
    *(unsigned int *)(p + off + 12) = 0;
    *(unsigned int *)(p + off + 16) = 1;
    ((struct Obj10881 *)p)->f68 = 20 * (unsigned int)(((unsigned long long)GF_STANDARD_Rand() * 5) >> 32) + 200;
    MCSS_SetAnimCallback(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}

void func_021BF720(u8 *p, int flag, u8 index)
{
    if(flag==1)MCSS_ResetVanishFlag(*(void **)((u32)p+(u32)index*12+8));
    else MCSS_SetVanishFlag(*(void **)((u32)p+(u32)index*12+8));
}

/*
 * 10-byte getter follower 0x021BF77C is included; function_starts seed. Enum zero separates field and argument clears.
 */
void func_021BF744(char *p, unsigned int i, unsigned int flag, unsigned int v)
{
    char *base = p + 8;
    unsigned int off = i * 12;
    enum { Zero } zero;
    MCSS_SetAnimeIndex(*(void **)(base + off), flag);
    MCSS_ResetAnmStopFlag(*(void **)(base + off));
    zero = Zero;
    *(unsigned int *)(p + off + 12) = zero;
    *(unsigned int *)(p + off + 16) = v;
    MCSS_SetAnimCallback(*(void **)(base + off), base + off, (void (*)(void *, void *))func_021BF7F0, 0);
}

unsigned int func_021BF77C(char *p, u8 i)
{
    return *(unsigned int *)(p + i * 12 + 12);
}

void func_021BF788(u8 *p, u8 index)
{
    *(int *)((u8 *)((u32)p+(u32)index*12)+12)=0;
}

/*
 * prototype: The shifts at 021BF7B8/021BF7BC narrow the outgoing alpha to u8.
 */
void func_021BF794(u8 *p, u8 index, u32 alpha)
{
    func_0207D63C((void *)0x04000050,1,9,0,0);
    if(alpha>31)alpha=31;
    MCSS_SetAlpha(*(char **)((u32)p+(u32)index*12+8),(u8)alpha);
}

void func_021BF7CC(u8 *p, u8 index, int flag)
{
    if(flag!=0)MCSS_SetMepachiFlag(*(void **)((u32)p+(u32)index*12+8));
    else MCSS_ResetMepachiFlag(*(void **)((u32)p+(u32)index*12+8));
}

void func_021BF7F0(u8 *p)
{
    ((struct Obj10882 *)p)->f4=1;
    if(((struct Obj10882 *)p)->f8==1)MCSS_RestartAnime(((struct Obj10882 *)p)->f0);
}

int func_021BF804(char *p, unsigned int i, int step, int limit)
{
    struct Vec pos;
    char *base = p + 8;
    unsigned int off = i * 12;
    int done;
    MCSS_GetPosition(*(void **)(base + off), (u32 *)(&pos));
    done = 1;
    pos.v[0] += step;
    if (pos.v[0] != limit)
    {
        if ((step > 0 && pos.v[0] > limit) || (step < 0 && pos.v[0] < limit))
            pos.v[0] = limit;
        else
            done = 0;
    }
    MCSS_SetPosition(*(void **)(base + off), (u32 *)(&pos));
    if (*(unsigned int *)(p + off + 12) == 1)
        MCSS_SetAnmStopFlag(*(void **)(base + off));
    return done;
}

/*
 * extent: two zero alignment bytes at 0x021BF896 follow; no follower.
 */
int func_021BF864(char *p,int delta,int limit) { u32 v[3]; int done; MCSS_GetPosition(((struct Obj14628 *)p)->f14,v); v[1]-=delta; if((int)v[1]<=limit) { v[1]=limit;done=1; } else done=0;MCSS_SetPosition(((struct Obj14628 *)p)->f14,v);return done; }

void func_021BF898(char *p)
{
    if (((struct Obj06674 *)p)->f18 != 0)
    {
        if (((struct Obj06674 *)p)->f68 == 0)
        {
            ((struct Obj06674 *)p)->f68 = 20 * (unsigned int)(((unsigned long long)GF_STANDARD_Rand() * 5) >> 32) + 200;
            func_021BF744(p, 1, 0, 1);
            return;
        }
        MCSS_SetAnmStopFlag(((struct Obj06674 *)p)->f14);
        --((struct Obj06674 *)p)->f68;
    }
}

char *func_021BF8DC(void *owner,int kind,u32 heap)
{
    Vec3 a,b,c;
    char *p;
    void *obj;
    p=func_02030734(heap,48,1,site_021C0B00,162);
    ((struct Obj02921 *)p)->f4=heap;
    ((struct Obj02921 *)p)->f0=owner;
    ((struct Obj02921 *)p)->f8=G3D_UTIL_Create(10,16,heap);
    a=va;b=vb;c=vc;
    ((struct Obj02921 *)p)->fC=G3D_CAMERA_Create(2,24576,(u32)-24576,(u32)-32768,32768,4096,4194304,4096,&a,&b,&c,heap);
    if(kind!=7){
        ((struct Obj02921 *)p)->f10=G3D_UTIL_AddUnit(((struct Obj02921 *)p)->f8,setup);
        obj=(void *)func_02048A18(((struct Obj02921 *)p)->f8,((struct Obj02921 *)p)->f10);
        G3D_SYSTEM_EnableObjectAnime(obj,3);G3D_SYSTEM_EnableObjectAnime(obj,4);
        G3D_SYSTEM_DisableObjectAnime(obj,0);G3D_SYSTEM_DisableObjectAnime(obj,1);G3D_SYSTEM_DisableObjectAnime(obj,2);
    }else ((struct Obj02921 *)p)->f10=0xffff;
    ((struct Obj02921 *)p)->f18=1;
    return p;
}

void func_021BF9D0(char *p) { u16 id; G3D_CAMERA_Delete(((struct Obj08385 *)p)->fC); id=((struct Obj08385 *)p)->f10; if(id!=65535) G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj08385 *)p)->f8,id);G3D_UTIL_Delete(*(struct Rec * *)&((struct Obj08385 *)p)->f8);func_020307B0(p); }

void func_021BF9FC(char *p)
{
    struct Transform { int pos[3]; int scale[3]; int matrix[9]; } t;
    func_02048AD0(((struct Obj06675 *)p)->fC);
    if (((struct Obj06675 *)p)->f14 != 0 && ((struct Obj06675 *)p)->f18 != 0)
    {
        t.pos[0] = 0;
        t.pos[1] = 0;
        t.pos[2] = 0;
        t.scale[0] = 4096;
        t.scale[1] = 4096;
        t.scale[2] = 4096;
        MTX_Identity33_(t.matrix);
        G3D_SYSTEM_DrawObject((void *)func_02048A18(((struct Obj06675 *)p)->f8, ((struct Obj06675 *)p)->f10), (struct Arg *)(&t));
    }
}

int func_021BFA40(char *p)
{
    switch (((struct Obj06676 *)p)->f24)
    {
    case 0:
        func_0207D63C((void *)0x04000050, 1, 9, 0, 0);
        GFL_USE_PlaySeDefaultVolume(0x555);
        ++((struct Obj06676 *)p)->f24;
    case 1:
    {
        void *obj = (void *)func_02048A18(((struct Obj06676 *)p)->f8, ((struct Obj06676 *)p)->f10);
        int a = G3D_SYSTEM_IncObjectAnimeFrame(obj, 3, 4096);
        int b = G3D_SYSTEM_IncObjectAnimeFrame(obj, 4, 4096);
        if (a == 0 && b == 0)
        {
            G3D_SYSTEM_DisableObjectAnime(obj, 3);
            G3D_SYSTEM_DisableObjectAnime(obj, 4);
            G3D_SYSTEM_EnableObjectAnime(obj, 0);
            G3D_SYSTEM_EnableObjectAnime(obj, 1);
            G3D_SYSTEM_EnableObjectAnime(obj, 2);
            func_021BFBC8(p, 60);
            ++((struct Obj06676 *)p)->f24;
        }
        break;
    }
    case 2:
        return 1;
    }
    return 0;
}

void func_021BFAE4(char *p, int v)
{
    ((struct Obj25391 *)p)->f14 = v;
}

void func_021BFAE8(char *p, unsigned int v)
{
    ((struct Obj03922 *)p)->f1C = v;
    ((struct Obj03922 *)p)->f20 = 0;
    switch (v)
    {
    case 0:
        ((struct Obj03922 *)p)->f28 = 60;
        ((struct Obj03922 *)p)->f1C = 1;
        break;
    case 1: ((struct Obj03922 *)p)->f28 = 70; break;
    case 2: ((struct Obj03922 *)p)->f28 = 50; break;
    case 3: ((struct Obj03922 *)p)->f28 = 50; break;
    case 4: ((struct Obj03922 *)p)->f28 = 70; break;
    }
}

int func_021BFB2C(char *p)
{
    switch (((struct Obj01974 *)p)->f1C)
    {
    case 0: break;
    case 1:
        --((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 50) return 1;
        break;
    case 2:
        ++((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 70) return 1;
        break;
    case 3:
        --((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 0) return 1;
        break;
    case 4:
        ++((struct Obj01974 *)p)->f28;
        func_021BFBC8(p, ((struct Obj01974 *)p)->f28);
        if (((struct Obj01974 *)p)->f28 == 120) return 1;
        break;
    }
    return 0;
}

int func_021BFBA0(int *p)
{
    if (p[7] == 3) {
        p[10] = p[10] + 1;
        func_021BFBC8((char *)p, p[10]);
    } else {
        p[10] = p[10] - 1;
        func_021BFBC8((char *)p, p[10]);
    }
    return p[10] == 60;
}

void func_021BFBC8(char *p,unsigned value)
{
    void *ctl;
    int frame;
    float f;
    ctl=(void *)func_02048A18(((struct Obj14629 *)p)->f8,((struct Obj14629 *)p)->f10);
    if(value!=0) f=0.5f+(float)(value<<12);
    else f=(float)(value<<12)-0.5f;
    frame=(int)f;
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,0,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,1,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame(ctl,2,&frame);
}
