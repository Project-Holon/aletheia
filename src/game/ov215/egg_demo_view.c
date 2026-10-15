/*
 * file:     egg_demo_view.c
 * unit:     yes
 * function: EGG_DEMO_VIEW_CreateRecords, EGG_DEMO_VIEW_FreeRecords, EGG_DEMO_VIEW_Create, EGG_DEMO_VIEW_Delete, EGG_DEMO_VIEW_Update, EGG_DEMO_VIEW_Draw, EGG_DEMO_VIEW_SetActive, EGG_DEMO_VIEW_GetActive, EGG_DEMO_VIEW_SetSpecies, EGG_DEMO_VIEW_IsFadeDone, EGG_DEMO_VIEW_ResetAnimState, EGG_DEMO_VIEW_IsFinished, EGG_DEMO_VIEW_Noop, EGG_DEMO_VIEW_InitMcss, EGG_DEMO_VIEW_DeleteMcss, EGG_DEMO_VIEW_AddPokeMcss, EGG_DEMO_VIEW_DeletePokeMcss, EGG_DEMO_VIEW_HidePokeMcss, EGG_DEMO_VIEW_PlayAnim, EGG_DEMO_VIEW_OnAnimStop, EGG_DEMO_VIEW_UpdateAlpha, EGG_DEMO_VIEW_StartFadeOut, EGG_DEMO_VIEW_IsFadeOutDone, EGG_DEMO_VIEW_StartFadeIn, EGG_DEMO_VIEW_CreateParticles, EGG_DEMO_VIEW_DeleteParticles, EGG_DEMO_VIEW_UpdateParticles, EGG_DEMO_VIEW_MainParticles, EGG_DEMO_VIEW_StartParticles, EGG_DEMO_VIEW_InitModel, EGG_DEMO_VIEW_DeleteModel, EGG_DEMO_VIEW_DrawModels, EGG_DEMO_VIEW_AddModel, EGG_DEMO_VIEW_RemoveModel, EGG_DEMO_VIEW_UpdateModel, EGG_DEMO_VIEW_StartModelAnim, EGG_DEMO_VIEW_IsModelAnimDone, EGG_DEMO_VIEW_EndModelAnim
 * address:  0x021F66C8
 * region:   ov215
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from egg_demo_view.c by tools/splitfile.py.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_020307B0 0x020307B0 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   d_021F73F4 0x021F73F4 data a1
 *   func_02017E1C 0x02017E1C thumb
 *   d_021F7340 0x021F7340 data a4
 *   d_021F7314 0x021F7314 data a4
 *   TCB_DeleteTask 0x02030EAC arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GFL_USE_IsAnySeBusy 0x02006238 thumb
 *   GFL_USE_IsSeSlotBusy 0x02006224 thumb
 *   GFL_USE_GetSeSlot 0x02006148 thumb
 *   GFL_USE_PlaySeInSlot 0x0200616C thumb
 *   GFL_USE_StopSeSlot 0x020061F8 thumb
 *   EGG_DEMO_VIEW_StartModelAnim 0x021F70F8 thumb ov215
 *   EGG_DEMO_VIEW_IsModelAnimDone 0x021F7100 thumb ov215
 *   EGG_DEMO_VIEW_EndModelAnim 0x021F7110 thumb ov215
 *   PM_VOICE_Play 0x02006984 thumb
 *   PM_VOICE_IsAnyActive 0x02006650 thumb
 *   MCSS_Main 0x02014C08 thumb
 *   MCSS_Draw 0x02014D2C thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetPaletteFade 0x02015F50 thumb
 *   MCSS_CheckPaletteFade 0x0201600C thumb
 *   MCSS_Init 0x02014B08 thumb
 *   MCSS_SetTextureTransAdrs 0x02016020 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Exit 0x02014BA8 thumb
 *   table_021F7384 0x021F7384 data a4
 *   MCSS_TOOL_AddPokeMcss 0x02017270 thumb
 *   MCSS_SetShadowVanishFlag 0x02015FF0 thumb
 *   MCSS_SetPosition 0x02015C48 thumb
 *   MCSS_SetScale 0x02015CAC thumb
 *   MCSS_GetSizeY 0x02015F0C thumb
 *   MCSS_GetOfsY 0x02015F1C thumb
 *   MCSS_GetOfsX 0x02015F14 thumb
 *   MCSS_SetOfsPosition 0x02015C78 thumb
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   MCSS_Del 0x02015BA4 thumb
 *   MCSS_SetAnimeIndex 0x02016028 thumb
 *   MCSS_GetAnimCtrl 0x02015EE8 thumb
 *   NNS_G2dRestartMCAnimation 0x02064CBC arm
 *   MCSS_ResetAnmStopFlag 0x02015E4C thumb
 *   NNS_G2dSetCellAnimationParam 0x02063000 arm
 *   MCSS_TOOL_SetAnimeStopCallback 0x020173B4 thumb
 *   MCSS_GetAlpha 0x02015FAC thumb
 *   MCSS_SetAlpha 0x02015FBC thumb
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   PARTICLE_InitManager 0x02050B80 arm
 *   PARTICLE_CreateSystemDefault 0x02050C04 arm
 *   PARTICLE_LoadArchiveMember 0x0205121C arm
 *   BUTTON_MAN_GetResourceType 0x02051B04 arm
 *   PARTICLE_SetupSystem 0x02051230 arm
 *   d_021F7300 0x021F7300 data a4
 *   PARTICLE_ExitManager 0x02050ED4 arm
 *   PARTICLE_StartEffect 0x020515B4 arm
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   d_021F73B4 0x021F73B4 data a4
 *   PARTICLE_Main 0x02050BE8 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   G3D_UTIL_Delete 0x02047E54 arm
 *   func_02048A18 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   func_020489F4 0x020489F4 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   d_021F7330 0x021F7330 data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame    0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame    0x020478B8  arm
 */
#include "../../matched/include/Obj00317.h"
#include "../../matched/include/Obj04636.h"
#include "../../matched/include/Obj01083.h"
#include "../../matched/include/Obj06708.h"
#include "../../matched/include/Obj25756.h"
#include "../../matched/include/Obj25757.h"
#include "../../matched/include/Obj25758.h"
#include "../../matched/include/Obj14710.h"
#include "../../matched/include/Obj25759.h"
#include "../../matched/include/Obj25760.h"
#include "../../matched/include/Obj02262.h"
#include "../../matched/include/Obj10941.h"
#include "../../matched/include/Obj25761.h"
#include "../../matched/include/Obj06707.h"
#include "../../matched/include/Obj14711.h"
#include "../../matched/include/Obj05551.h"
#include "../../matched/include/Obj14712.h"
#include "../../matched/include/Obj25762.h"
#include "../../matched/include/Obj14713.h"
#include "../../matched/include/Obj03373.h"
#include "../../matched/include/Obj02263.h"
#include "../../matched/include/Obj25763.h"
#include "../../matched/include/Obj14714.h"
#include "../../matched/include/Obj06709.h"
#include "egg_demo_graphic_shared_types.h"

#define W(o) (*(u32 *)(p+(o)))

#define FIX(x) ((int)(((x)>0)?((x)*4096.0f+.5f):((x)*4096.0f-.5f)))

struct McssSys;

struct McssFade;

struct Obj;

struct Data;

struct Util;

struct Rec;

struct Arg;

struct Setup;

struct Record;

struct G3dSys;

struct AnmCtl;

struct Ctx;

typedef struct { int tag,x,y,z,sx,sy,sz,matrix[9],tail; } Record;

typedef signed int     s32;

typedef struct {int x,y,z;} Vec_021F63CC;

typedef struct {u32 species;float x,y;} Entry;

typedef struct { int x,y,z; } Vec_021F6D7C;

extern void *func_02030734(unsigned,unsigned,int,const char *,u16);

extern void *func_020056A0(void (*)(int,char *),char *,unsigned);

extern u32 func_020307B0(void *p);

extern void MTX_Identity33_(void *);

extern u32 func_02017E1C(void *p, u32 id, u32 v);

extern void TCB_DeleteTask(struct Node *);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern int GFL_USE_IsAnySeBusy(void);

extern int GFL_USE_IsSeSlotBusy(u32);

extern int GFL_USE_GetSeSlot(u32);

extern void GFL_USE_PlaySeInSlot(void *,int);

extern void GFL_USE_StopSeSlot(int);

extern void EGG_DEMO_VIEW_StartModelAnim(char *);

extern int EGG_DEMO_VIEW_IsModelAnimDone(char *);

extern void EGG_DEMO_VIEW_EndModelAnim(char *);

extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);

extern int PM_VOICE_IsAnyActive(void);

extern void MCSS_Main(char *);

extern void MCSS_Draw(struct McssSys *);

extern void MCSS_SetVanishFlag(void *);

extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);

extern int MCSS_CheckPaletteFade(void *);

extern void *MCSS_Init(u32 id, void *heap);

extern void MCSS_SetTextureTransAdrs(void *, unsigned int);

extern void MCSS_SetOrthoMode(void *);

extern void MCSS_Exit(u8 *);

extern void *MCSS_TOOL_AddPokeMcss(void *,void *,u32,u32,u32,u32);

extern void MCSS_SetShadowVanishFlag(char *,int);

extern void MCSS_SetPosition(void *,u32 *);

extern void MCSS_SetScale(void *,u32 *);

extern u16 MCSS_GetSizeY(void *);

extern s16 MCSS_GetOfsY(void *);

extern s16 MCSS_GetOfsX(void *);

extern void MCSS_SetOfsPosition(void *,u32 *);

extern void MCSS_SetAnmStopFlag(void *);

extern void MCSS_Del(void *,void *);

/* Legacy 020173B4 inputs r1-r3 are replaced by its body; full forwarding
 * 02015F2C supplies fixed member, one, original p and callback to 02063000.
 * It reads no caller r1-r3. 02016028 retains live incoming flag in r1. */
extern void MCSS_SetAnimeIndex(void *,unsigned);

extern void *MCSS_GetAnimCtrl(void *);

extern void NNS_G2dRestartMCAnimation(struct Obj *x);

extern void MCSS_ResetAnmStopFlag(void *);

extern void NNS_G2dSetCellAnimationParam(int p0, int p1, int p2, int p3);

extern int MCSS_TOOL_SetAnimeStopCallback(int a0);

extern u8 MCSS_GetAlpha(struct Data *);

extern void MCSS_SetAlpha(char *,int);

extern void MCSS_ResetVanishFlag(void *);

extern void PARTICLE_InitManager(unsigned);

extern int PARTICLE_CreateSystemDefault(int,int,int,int);

extern int PARTICLE_LoadArchiveMember(unsigned,unsigned,unsigned);

extern u16 BUTTON_MAN_GetResourceType(void *);

extern void PARTICLE_SetupSystem(void *,unsigned,unsigned,unsigned);

extern void PARTICLE_ExitManager(void);

extern int PARTICLE_StartEffect(void *p, int b, int c);

extern void PARTICLE_KillAllEffects(void *);

extern void PARTICLE_Main(void);

extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);

extern struct Util *G3D_UTIL_Create(u16,u16,u16);

extern void G3D_UTIL_Delete(struct Rec *);

extern unsigned func_02048A18(unsigned char *,int);

extern void G3D_SYSTEM_DrawObject(void *,struct Arg *);

extern u16 G3D_UTIL_AddUnit(struct Util *,const struct Setup *);

extern unsigned func_020489F4(unsigned char *,int);

extern unsigned G3D_SYSTEM_EnableObjectAnime(struct G3dSys *,unsigned);

extern u32 G3D_SYSTEM_SetObjectAnimeFrame(struct AnmCtl *c, u16 idx, s32 *frame);

extern int G3D_SYSTEM_IncObjectAnimeFrame(void *p, int a, int b);

Record *EGG_DEMO_VIEW_CreateRecords(unsigned heap,unsigned count);

void EGG_DEMO_VIEW_FreeRecords(void *p);

char *EGG_DEMO_VIEW_Create(unsigned heap,void *mon);

void EGG_DEMO_VIEW_Delete(char *p);

void EGG_DEMO_VIEW_Update(char *p);

void EGG_DEMO_VIEW_Draw(char *p);

void EGG_DEMO_VIEW_SetActive(char *p);

int EGG_DEMO_VIEW_GetActive(char *p);

void EGG_DEMO_VIEW_SetSpecies(char *p,int a);

int EGG_DEMO_VIEW_IsFadeDone(char *p);

void EGG_DEMO_VIEW_ResetAnimState(char *p);

int EGG_DEMO_VIEW_IsFinished(char *p);

void EGG_DEMO_VIEW_Noop(void);

void EGG_DEMO_VIEW_InitMcss(char *p);

void EGG_DEMO_VIEW_DeleteMcss(char *p);

void EGG_DEMO_VIEW_AddPokeMcss(char *p);

void EGG_DEMO_VIEW_DeletePokeMcss(char *p);

void EGG_DEMO_VIEW_HidePokeMcss(char *p);

void EGG_DEMO_VIEW_PlayAnim(char *p,unsigned flag,int enable);

int EGG_DEMO_VIEW_OnAnimStop(char *a);

void EGG_DEMO_VIEW_UpdateAlpha(char *p);

void EGG_DEMO_VIEW_StartFadeOut(char *p);

int EGG_DEMO_VIEW_IsFadeOutDone(char *p);

void EGG_DEMO_VIEW_StartFadeIn(char *p);

char *EGG_DEMO_VIEW_CreateParticles(unsigned heap,unsigned count,const void *table);

void EGG_DEMO_VIEW_DeleteParticles(char *a);

void EGG_DEMO_VIEW_UpdateParticles(char *p);

void EGG_DEMO_VIEW_MainParticles(char *p);

void EGG_DEMO_VIEW_StartParticles(char *p);

void EGG_DEMO_VIEW_InitModel(char *p);

void EGG_DEMO_VIEW_DeleteModel(char *p);

void EGG_DEMO_VIEW_DrawModels(char *p);

void EGG_DEMO_VIEW_AddModel(char *p);

void EGG_DEMO_VIEW_RemoveModel(char *p);

void EGG_DEMO_VIEW_UpdateModel(char *p);

extern const char d_021F73F4[];

extern const unsigned d_021F7340[],d_021F7314[];

extern const Entry table_021F7384[];

extern const unsigned long long d_021F7300;

extern const Vec_021F6D7C d_021F73B4;

extern const struct Setup d_021F7330;

Record *EGG_DEMO_VIEW_CreateRecords(unsigned heap,unsigned count)
{
    Record *p;
    u16 i;
    p=func_02030734(heap,68*count,1,d_021F73F4,283);
    for(i=0;i<count;i++) {
        p[i].x=0;p[i].y=0;p[i].z=0;
        p[i].sx=4096;p[i].sy=4096;p[i].sz=4096;
        MTX_Identity33_(p[i].matrix);
    }
    return p;
}

void EGG_DEMO_VIEW_FreeRecords(void *p){func_020307B0(p);}

/*
 * evidence: sole callback 021F6AB4 resolved after owned leaf shard verification.
 */
char *EGG_DEMO_VIEW_Create(unsigned heap,void *mon)
{
    char *p;
    p=func_02030734(heap,96,1,d_021F73F4,433);
    ((struct Obj00317 *)p)->f0=heap;
    ((struct Obj00317 *)p)->f4=mon;
    ((struct Obj00317 *)p)->f8=func_02017E1C(mon,5,0);
    ((struct Obj00317 *)p)->fC=0;
    ((struct Obj00317 *)p)->f10=0;
    ((struct Obj00317 *)p)->f14=0;
    ((struct Obj00317 *)p)->f18=0;
    ((struct Obj00317 *)p)->f1C=0;
    ((struct Obj00317 *)p)->f24=0;
    ((struct Obj00317 *)p)->f28=0;
    ((struct Obj00317 *)p)->f2C=func_020056A0((void ( *)(int,char *))EGG_DEMO_VIEW_Noop, (char *)p, 1);
    EGG_DEMO_VIEW_InitMcss(p);
    EGG_DEMO_VIEW_AddPokeMcss(p);
    if(((struct Obj00317 *)p)->f8==490)
        ((struct Obj00317 *)p)->f44=EGG_DEMO_VIEW_CreateParticles(((struct Obj00317 *)p)->f0,5,d_021F7340);
    else
        ((struct Obj00317 *)p)->f44=EGG_DEMO_VIEW_CreateParticles(((struct Obj00317 *)p)->f0,3,d_021F7314);
    EGG_DEMO_VIEW_InitModel(p);
    EGG_DEMO_VIEW_AddModel(p);
    return p;
}

/*
 * trailing: zero halfword at 021F67DE is alignment padding.
 */
void EGG_DEMO_VIEW_Delete(char *p){EGG_DEMO_VIEW_RemoveModel(p);EGG_DEMO_VIEW_DeleteModel(p);EGG_DEMO_VIEW_DeleteParticles(*(char * *)&((struct Obj04636 *)p)->f44);EGG_DEMO_VIEW_DeletePokeMcss(p);EGG_DEMO_VIEW_DeleteMcss(p);TCB_DeleteTask(*(struct Node * *)&((struct Obj04636 *)p)->f2C);func_020307B0(p);}

void EGG_DEMO_VIEW_Update(char *p)
{
    u32 limit,a,b;
    switch(W(12)) {
    case 0:
        if(W(16)) {
            W(12)=1;W(24)=0;
            EGG_DEMO_VIEW_PlayAnim(p,1,1);
            EGG_DEMO_VIEW_StartParticles(*(char * *)&((struct Obj01083 *)p)->f44);
        }
        break;
    case 1:
        if(((struct Obj01083 *)p)->f8==490)limit=300;else limit=380;
        W(24)++;
        if(((struct Obj01083 *)p)->f8==490) {
            switch(W(40)) {
            case 0: if(W(24)==10){GFL_USE_PlaySeDefaultVolume(1955);W(40)=1;}break;
            case 1: if(!GFL_USE_IsAnySeBusy()){GFL_USE_PlaySeDefaultVolume(1960);W(40)=2;}break;
            case 2: if(!GFL_USE_IsAnySeBusy())W(40)=3;break;
            case 3:break;
            }
        }else{
            if(W(24)==20)GFL_USE_PlaySeDefaultVolume(1954);
            else if(W(24)==109)GFL_USE_PlaySeDefaultVolume(1954);
            else if(W(24)==218)GFL_USE_PlaySeDefaultVolume(1488);
            if(W(24)==10)GFL_USE_PlaySeDefaultVolume(1968);
            else if(W(24)==15)GFL_USE_PlaySeDefaultVolume(1968);
            else if(W(24)==85)GFL_USE_PlaySeDefaultVolume(1968);
            else if(W(24)==90)GFL_USE_PlaySeDefaultVolume(1968);
            if(W(28)&&!GFL_USE_IsSeSlotBusy(W(32))) {
                W(28)=0;
                if(W(24)>=150&&W(24)<309)W(36)=20;
                else if(W(24)>309)W(36)=0;
            }
            if(W(24)>=150&&W(24)<limit) {
                if(!W(28)) {
                    if(!W(36)) {
                        W(32)=GFL_USE_GetSeSlot(1967);
                        GFL_USE_PlaySeInSlot((void *)1967,W(32));
                        W(28)=1;
                    }else W(36)--;
                }
            }else if(W(24)==limit&&W(28)&&GFL_USE_IsSeSlotBusy(W(32))) {
                GFL_USE_StopSeSlot(W(32));W(28)=0;
            }
        }
        if(W(24)==limit) {
            EGG_DEMO_VIEW_StartFadeOut(p);EGG_DEMO_VIEW_StartModelAnim(p);GFL_USE_PlaySeDefaultVolume(1935);W(12)=2;
        }
        break;
    case 2:if(EGG_DEMO_VIEW_IsFadeOutDone(p))W(12)=3;break;
    case 3:if(EGG_DEMO_VIEW_IsModelAnimDone(p)){EGG_DEMO_VIEW_HidePokeMcss(p);W(20)=1;W(12)=4;}break;
    case 4:W(20)=0;break;
    case 6:
        if(++W(24)>=120){EGG_DEMO_VIEW_StartFadeIn(p);EGG_DEMO_VIEW_EndModelAnim(p);W(12)=7;W(24)=0;}
        break;
    case 7:
        if(++W(24)>=65) {
            W(12)=8;
            a=func_02017E1C(((struct Obj01083 *)p)->f4,5,0);
            b=func_02017E1C(((struct Obj01083 *)p)->f4,111,0);
            PM_VOICE_Play(a,b,64,0,0,0,0,0);
        }
        break;
    case 8:if(!PM_VOICE_IsAnyActive())W(12)=9;break;
    case 9:break;
    }
    EGG_DEMO_VIEW_UpdateAlpha(p);
    MCSS_Main(*(char * *)&((struct Obj01083 *)p)->f30);
    EGG_DEMO_VIEW_UpdateParticles(*(char * *)&((struct Obj01083 *)p)->f44);
    EGG_DEMO_VIEW_UpdateModel(p);
}

void EGG_DEMO_VIEW_Draw(char *p){MCSS_Draw(*(struct McssSys * *)&((struct Obj06708 *)p)->f30);EGG_DEMO_VIEW_DrawModels(p);EGG_DEMO_VIEW_MainParticles(*(char * *)&((struct Obj06708 *)p)->f44);}

/*
 * leaf: two unlabelled leaves blocking concrete MATCH900 ov215021F5884.
 * extent: setter, two alignment bytes, four-byte getter; twelve bytes total.
 */
void EGG_DEMO_VIEW_SetActive(char *p){((struct Obj25756 *)p)->f10=1;}

int EGG_DEMO_VIEW_GetActive(char *p){return ((struct Obj25757 *)p)->f14;}

void EGG_DEMO_VIEW_SetSpecies(char *p,int a)
{
    EGG_DEMO_VIEW_DeletePokeMcss(p);
    *(int *)(p + 4) = a;
    EGG_DEMO_VIEW_AddPokeMcss(p);
    EGG_DEMO_VIEW_PlayAnim(p,0,0);
    MCSS_SetVanishFlag(*(void **)(p + 0x34));
    MCSS_SetPaletteFade(*(struct McssFade **)(p + 0x34),16,16,0,32767);
    *(int *)(p + 0xC) = 5;
}

/*
 * trailing: existing followers 021F6A98/6AA4 unit and 021F6AB4 shard.
 */
int EGG_DEMO_VIEW_IsFadeDone(char *p){if(MCSS_CheckPaletteFade(((struct Obj25758 *)p)->f34)==0)return 1;return 0;}

void EGG_DEMO_VIEW_ResetAnimState(char *p){((struct Obj14710 *)p)->fC=6;((struct Obj14710 *)p)->f18=0;}

int EGG_DEMO_VIEW_IsFinished(char *p){if(((struct Obj25759 *)p)->fC>=9)return 1;return 0;}

/*
 * evidence: sole callback blocker of 021F6720; parent SDK/ownership audit.
 * extent: bx lr at 021F6AB4, zero padding at 6AB6; 6AB8 begins next function.
 */
void EGG_DEMO_VIEW_Noop(void)
{
}

void EGG_DEMO_VIEW_InitMcss(char *p)
{
    *(void **)(p + 0x30) = MCSS_Init(1, (void *)(*(unsigned short *)p));
    MCSS_SetTextureTransAdrs(*(void **)(p + 0x30), 3 << 16);
    MCSS_SetOrthoMode(*(void **)(p + 0x30));
    *(unsigned int *)(p + 0x3c) = 0;
    *(unsigned char *)(p + 0x40) = 0;
}

void EGG_DEMO_VIEW_DeleteMcss(char *p){MCSS_Exit(*(u8 * *)&((struct Obj25760 *)p)->f30);}

/*
 * lever: FX float rounding macro; translation z shares the constructor's -50<<16 literal.
 */
void EGG_DEMO_VIEW_AddPokeMcss(char *p)
{
    Vec_021F63CC trans,scale,delta;
    u32 species;
    u8 i=0;
    float angle,y,x;
    ((struct Obj02262 *)p)->f34=MCSS_TOOL_AddPokeMcss(((struct Obj02262 *)p)->f30,((struct Obj02262 *)p)->f4,0,0,0xfff42000,0xffce0000);
    MCSS_SetShadowVanishFlag(*(char * *)&((struct Obj02262 *)p)->f34,1);
    species=func_02017E1C(((struct Obj02262 *)p)->f4,171,0);
    if(species!=650){
        for(;i<4;i++){
            if(species==table_021F7384[i].species){
                trans.x=FIX(table_021F7384[i].x);
                trans.y=FIX(table_021F7384[i].y);
                trans.z=0xffce0000;
                MCSS_SetPosition(((struct Obj02262 *)p)->f34,(u32 *)&trans);
                break;
            }
        }
    }
    scale.x=65536;scale.y=65536;scale.z=4096;
    MCSS_SetScale(((struct Obj02262 *)p)->f34,(u32 *)&scale);
    angle=(float)MCSS_GetSizeY(((struct Obj02262 *)p)->f34);
    y=(float)MCSS_GetOfsY(((struct Obj02262 *)p)->f34);
    x=(float)MCSS_GetOfsX(((struct Obj02262 *)p)->f34);
    if(angle>96.0f)angle=96.0f;
    y=(96.0f-angle)/2.0f+y;
    x=0.0f-x;
    delta.x=FIX(x);delta.y=FIX(y);delta.z=0;
    MCSS_SetOfsPosition(((struct Obj02262 *)p)->f34,(u32 *)&delta);
    MCSS_SetAnmStopFlag(((struct Obj02262 *)p)->f34);
}

/*
 * trailing: existing follower 021F6CC0 in its own matched shard.
 */
void EGG_DEMO_VIEW_DeletePokeMcss(char *p){MCSS_SetVanishFlag(((struct Obj10941 *)p)->f34);MCSS_Del(((struct Obj10941 *)p)->f30,((struct Obj10941 *)p)->f34);}

/*
 * leaf: sole overlay blocker of 021F67E0; tail-call pool ends at 021F6CCC.
 */
void EGG_DEMO_VIEW_HidePokeMcss(char *p){MCSS_SetVanishFlag(((struct Obj25761 *)p)->f34);}

void EGG_DEMO_VIEW_PlayAnim(char *p,unsigned flag,int enable)
{
    void *obj;
    MCSS_SetAnimeIndex(((struct Obj06707 *)p)->f34,flag);
    obj=MCSS_GetAnimCtrl(((struct Obj06707 *)p)->f34);
    NNS_G2dRestartMCAnimation(obj);
    MCSS_ResetAnmStopFlag(((struct Obj06707 *)p)->f34);
    if(enable) {
        NNS_G2dSetCellAnimationParam((int)obj,1,(int)p,(int)EGG_DEMO_VIEW_OnAnimStop);
        ((struct Obj06707 *)p)->f38=0;
    } else MCSS_TOOL_SetAnimeStopCallback((int)(((struct Obj06707 *)p)->f34));
}

/*
 *   entry), so neither label nor sole-ref/code can attest the bl site;
 *   byte-correct.
 */
int EGG_DEMO_VIEW_OnAnimStop(char *a)
{
    MCSS_SetAnmStopFlag((void *)(((struct Obj14711 *)a)->f34));
    ((struct Obj14711 *)a)->f38 = 1;
    return 1;
}

void EGG_DEMO_VIEW_UpdateAlpha(char *p){u8 n;if(((struct Obj05551 *)p)->f3C){n=MCSS_GetAlpha(*(struct Data * *)&((struct Obj05551 *)p)->f34);if(n>((struct Obj05551 *)p)->f40)n--;else n++;MCSS_SetAlpha(*(char * *)&((struct Obj05551 *)p)->f34,n);if(n==((struct Obj05551 *)p)->f40)((struct Obj05551 *)p)->f3C=0;}}

void EGG_DEMO_VIEW_StartFadeOut(char *p){MCSS_SetAnmStopFlag(((struct Obj14712 *)p)->f34);MCSS_SetPaletteFade(*(struct McssFade * *)&((struct Obj14712 *)p)->f34,0,16,0,32767);}

int EGG_DEMO_VIEW_IsFadeOutDone(char *p){if(MCSS_CheckPaletteFade(((struct Obj25762 *)p)->f34)==0)return 1;return 0;}

void EGG_DEMO_VIEW_StartFadeIn(char *p){MCSS_ResetVanishFlag(((struct Obj14713 *)p)->f34);MCSS_SetPaletteFade(*(struct McssFade * *)&((struct Obj14713 *)p)->f34,16,0,2,32767);}

char *EGG_DEMO_VIEW_CreateParticles(unsigned heap,unsigned count,const void *table)
{
    char *p;
    unsigned zero[3]={0};
    unsigned long long config;
    int resource;
    p=func_02030734(heap,0x481C,1,d_021F73F4,0x502);
    ((struct Obj03373 *)p)->f0=0;
    ((struct Obj03373 *)p)->f2=0;
    ((struct Obj03373 *)p)->f4=count;
    *(const void * *)&((struct Obj03373 *)p)->f8=table;
    ((struct Obj03373 *)p)->f4814=0;
    ((struct Obj03373 *)p)->f4818=-1;
    PARTICLE_InitManager(heap);
    *(int *)&((struct Obj03373 *)p)->f480C=PARTICLE_CreateSystemDefault((int)(p+12),0x4800,1,heap);
    config=d_021F7300;
    resource=PARTICLE_LoadArchiveMember((unsigned)config,(unsigned)(config>>32),heap);
    ((struct Obj03373 *)p)->f4810=BUTTON_MAN_GetResourceType((void *)resource);
    PARTICLE_SetupSystem(((struct Obj03373 *)p)->f480C,resource,1,0);
    return p;
}

void EGG_DEMO_VIEW_DeleteParticles(char *a)
{
    PARTICLE_ExitManager();
    func_020307B0(a);
}

/*
 * prototype: 515B4 receives visibly loaded r1/r2 despite legacy one-argument callee.
 */
void EGG_DEMO_VIEW_UpdateParticles(char *p)
{
    if (((struct Obj02263 *)p)->f4814) {
        Vec_021F6D7C v=d_021F73B4;
        while (((struct Obj02263 *)p)->f2<((struct Obj02263 *)p)->f4) {
            const char *table=*(const char * *)&((struct Obj02263 *)p)->f8;
            unsigned index=((struct Obj02263 *)p)->f2;
            u16 frame=((struct Obj02263 *)p)->f0;
            u16 key=*(u16 *)(table+(int)index*4);
            if (frame!=key) break;
            PARTICLE_StartEffect(*(void **)(p+*(unsigned char *)(table+index*4+2)*0x4808+0x480c),*(unsigned char *)(table+index*4+3),(int)(&v));
            (((struct Obj02263 *)p)->f2)++;
        }
        (((struct Obj02263 *)p)->f0)++;
    }
    if (((struct Obj02263 *)p)->f4818>=0) {
        if (((struct Obj02263 *)p)->f4818==0) PARTICLE_KillAllEffects(((struct Obj02263 *)p)->f480C);
        (((struct Obj02263 *)p)->f4818)--;
    }
}

void EGG_DEMO_VIEW_MainParticles(char *p){PARTICLE_Main();}

/*
 * leaf: sole overlay blocker of 021F67E0; store and return, pool ends 021F6EF8.
 */
void EGG_DEMO_VIEW_StartParticles(char *p){((struct Obj25763 *)p)->f4814=1;}

void EGG_DEMO_VIEW_InitModel(char *p){unsigned z=0;G3D_SYSTEM_SetSwapBuffersMode(1,z);*(struct Util * *)&((struct Obj00317 *)p)->f48=G3D_UTIL_Create(4,1,((struct Obj00317 *)p)->f0);((struct Obj00317 *)p)->f50=z;}

void EGG_DEMO_VIEW_DeleteModel(char *p){G3D_UTIL_Delete(*(struct Rec * *)&((struct Obj04636 *)p)->f48);}

void EGG_DEMO_VIEW_DrawModels(char *p)
{
    unsigned short i;
    for(i=0;i<((struct Obj06708 *)p)->f50;i++) {
        char *entry=*(char * *)&((struct Obj06708 *)p)->f54+i*0x44;
        if(((struct Obj14714 *)entry)->f40)
            G3D_SYSTEM_DrawObject((void *)func_02048A18(*(unsigned char * *)&((struct Obj06708 *)p)->f48,((struct Obj14714 *)entry)->f0),(struct Arg *)(entry+4));
    }
}

void EGG_DEMO_VIEW_AddModel(char *p)
{
    unsigned id;
    char *entry;
    u16 i;
    void *q;
    int frame;
    ((struct Obj00317 *)p)->f4C=G3D_UTIL_AddUnit(*(struct Util * *)&((struct Obj00317 *)p)->f48,&d_021F7330);
    ((struct Obj00317 *)p)->f50=1;
    *(struct Record * *)&((struct Obj00317 *)p)->f54=(struct Record *)EGG_DEMO_VIEW_CreateRecords(((struct Obj00317 *)p)->f0,((struct Obj00317 *)p)->f50);
    id=func_020489F4(*(unsigned char * *)&((struct Obj00317 *)p)->f48,((struct Obj00317 *)p)->f4C);
    ((struct Obj00317 *)p)->f4E=0;
    entry=*(char * *)&((struct Obj00317 *)p)->f54;
    ((struct Obj06709 *)entry)->f0=id;
    ((struct Obj06709 *)entry)->f4=0;
    ((struct Obj06709 *)entry)->f8=0;
    ((struct Obj06709 *)entry)->fC=0;
    ((struct Obj06709 *)entry)->f40=1;
    for(i=0;i<((struct Obj00317 *)p)->f50;i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)func_02048A18(*(unsigned char * *)&((struct Obj00317 *)p)->f48,*(u16 *)(*(char * *)&((struct Obj00317 *)p)->f54+i*68)),0);
    ((struct Obj00317 *)p)->f58=0;
    q=(void *)func_02048A18(*(unsigned char * *)&((struct Obj00317 *)p)->f48,*(u16 *)(*(char * *)&((struct Obj00317 *)p)->f54+((struct Obj00317 *)p)->f4E*68));
    frame=0;
    ((struct Obj00317 *)p)->f5C=0;
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)q,1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dSys *)q,2);
    G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)q,1,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame((struct AnmCtl *)q,2,&frame);
}

void EGG_DEMO_VIEW_RemoveModel(char *p){G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj04636 *)p)->f48,((struct Obj04636 *)p)->f4C);EGG_DEMO_VIEW_FreeRecords(((struct Obj04636 *)p)->f54);((struct Obj04636 *)p)->f50=0;}

void EGG_DEMO_VIEW_UpdateModel(char *p)
{
    u16 i;
    void *q;
    int a, b;

    for (i = 0; i < ((struct Obj01083 *)p)->f50; i++) {
        G3D_SYSTEM_LoopObjectAnimeFrame((void *)func_02048A18((unsigned char *)(((struct Obj01083 *)p)->f48), *(u16 *)(*(char * *)&((struct Obj01083 *)p)->f54 + i * 0x44)), 0, 0x1000);
    }
    ((struct Obj01083 *)p)->f58 = ((struct Obj01083 *)p)->f58 + 1;
    q = (void *)func_02048A18((unsigned char *)(((struct Obj01083 *)p)->f48), *(u16 *)(*(char * *)&((struct Obj01083 *)p)->f54 + ((struct Obj01083 *)p)->f4E * 0x44));
    if (((struct Obj01083 *)p)->f5C == 1) {
        a = G3D_SYSTEM_IncObjectAnimeFrame(q, 1, 0x5000);
        b = G3D_SYSTEM_IncObjectAnimeFrame(q, 2, 0x5000);
        if (a == 0 && b == 0)
            ((struct Obj01083 *)p)->f5C = 2;
    } else if (((struct Obj01083 *)p)->f5C == 3) {
        a = G3D_SYSTEM_IncObjectAnimeFrame(q, 1, -0x2000);
        b = G3D_SYSTEM_IncObjectAnimeFrame(q, 2, -0x2000);
        if (a == 0 && b == 0)
            ((struct Obj01083 *)p)->f5C = 0;
    }
}

void EGG_DEMO_VIEW_StartModelAnim(char *p){((struct Obj01083 *)p)->f5C=1;}

int EGG_DEMO_VIEW_IsModelAnimDone(char *p){return ((struct Obj01083 *)p)->f5C==2;}

void EGG_DEMO_VIEW_EndModelAnim(char *p){((struct Obj01083 *)p)->f5C=3;}
