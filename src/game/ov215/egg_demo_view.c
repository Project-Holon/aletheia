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
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GFL_USE_AddMainTask 0x020056A0 thumb
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MTX_Identity33_ 0x0207ADC4 arm
 *   d_021F73F4 0x021F73F4 data a1
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
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
 *   PARTICLE_RESOURCE_GetType 0x02051B04 arm
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
 *   G3D_UTIL_GetObject 0x02048A18 arm
 *   G3D_SYSTEM_DrawObject 0x02047A60 arm
 *   G3D_UTIL_AddUnit 0x02047E88 arm
 *   G3D_UTIL_GetUnitObjIdx 0x020489F4 arm
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_SetObjectAnimeFrame 0x0204784C arm
 *   d_021F7330 0x021F7330 data a4
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   G3D_SYSTEM_LoopObjectAnimeFrame    0x02047910  arm
 *   G3D_SYSTEM_IncObjectAnimeFrame    0x020478B8  arm
 *   _fadd                        0x0209C95C  arm
 *   _fdiv                        0x0209CE10  arm
 *   _ffix                        0x0209C494  arm
 *   _fflt                        0x0209BDBC  arm
 *   _ffltu                       0x0209BE04  arm
 *   _fgr                         0x0209BBB0  arm
 *   _fmul                        0x0209C77C  arm
 *   _fsub                        0x0209CB8C  arm
 */
#include "egg_demo_types.h"

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

typedef struct { unsigned short tag; unsigned short pad2; int x,y,z,sx,sy,sz,matrix[9],tail; } Record;

#include "../types.h"

typedef struct {int x,y,z;} EggDemoVec3;

typedef struct {u32 species;float x,y;} Entry;

/* The egg demo view work, 96 bytes, allocated by EGG_DEMO_VIEW_Create. */
struct EggDemoView {
    unsigned short heapId;       /* 0x00 */
    unsigned char pad2[2];       /* 0x02 */
    void *mon;                   /* 0x04 hatched mon */
    unsigned short species;      /* 0x08 */
    unsigned char padA[2];       /* 0x0A */
    int animState;               /* 0x0C process step */
    int startFlag;               /* 0x10 set by SetActive */
    int visible;                 /* 0x14 shown on screen */
    unsigned int frameCounter;   /* 0x18 */
    int soundPlaying;            /* 0x1C */
    int soundSlot;               /* 0x20 */
    int soundDelay;              /* 0x24 */
    int soundStep;               /* 0x28 */
    void *vblankTask;            /* 0x2C */
    void *mcss;                  /* 0x30 MCSS handle */
    void *pokeMcss;              /* 0x34 poke MCSS handle */
    int animStopFlag;            /* 0x38 */
    unsigned int alphaActive;    /* 0x3C */
    unsigned char alphaTarget;   /* 0x40 */
    unsigned char pad41[3];      /* 0x41 */
    void *particles;             /* 0x44 */
    void *util;                  /* 0x48 G3D util */
    unsigned short unitId;       /* 0x4C */
    unsigned short animIndex;    /* 0x4E */
    unsigned short recordCount;  /* 0x50 */
    unsigned char pad52[2];      /* 0x52 */
    Record *records;             /* 0x54 */
    int animFrame;               /* 0x58 */
    int modelAnimState;          /* 0x5C */
};

/* The particle system work, 0x481C bytes, allocated by EGG_DEMO_VIEW_CreateParticles. */
struct EggDemoParticles {
    unsigned short frame;        /* 0x00 */
    unsigned short index;        /* 0x02 */
    unsigned short count;        /* 0x04 */
    unsigned char pad6[2];       /* 0x06 */
    const void *table;           /* 0x08 */
    unsigned char padC[0x4800];  /* 0x0C particle storage */
    void *system;                /* 0x480C */
    unsigned char resourceType;  /* 0x4810 */
    unsigned char pad4811[3];    /* 0x4811 */
    int active;                  /* 0x4814 */
    int life;                    /* 0x4818 */
};

extern void G3D_UTIL_RemoveUnit(void *util, u32 unitIdx);
struct G3dObject;
extern int G3D_SYSTEM_LoopObjectAnimeFrame(struct G3dObject *obj, int anmIdx, int step);
extern void *GFL_HEAP_Alloc(unsigned,unsigned,int,const char *,u16);
struct Tcb;

extern struct Tcb *GFL_USE_AddMainTask(void (*)(int,char *), void *work, unsigned int priority);

extern u32 GFL_HEAP_Free(void *p);

extern void MTX_Identity33_(void *);
struct PokemonParam;

extern u32 POKE_TOOL_GetPartyValue(struct PokemonParam *pp, unsigned int paramId, unsigned int arg);
struct TcbTask;

extern void TCB_DeleteTask(struct TcbTask *task);

extern void GFL_USE_PlaySeDefaultVolume(u32);

extern int GFL_USE_IsAnySeBusy(void);

extern int GFL_USE_IsSeSlotBusy(u32);

extern int GFL_USE_GetSeSlot(u32);

extern void GFL_USE_PlaySeInSlot(unsigned int seqNo, int slot);

extern void GFL_USE_StopSeSlot(int);

extern void EGG_DEMO_VIEW_StartModelAnim(char *);

extern int EGG_DEMO_VIEW_IsModelAnimDone(char *);

extern void EGG_DEMO_VIEW_EndModelAnim(char *);

extern u32 PM_VOICE_Play(unsigned int species, unsigned int form, unsigned int pan, unsigned int dual, unsigned int volumeBiasB, unsigned int frequencyOffsetB, unsigned int reverse, void **recordedVoice);

extern int PM_VOICE_IsAnyActive(void);

extern void MCSS_Main(struct McssSys *sys);

extern void MCSS_Draw(struct McssSys *);
struct McssWork;

extern void MCSS_SetVanishFlag(struct McssWork *work);

extern void MCSS_SetPaletteFade(struct McssWork *work, unsigned int start, unsigned int end, int wait, unsigned int color);

extern int MCSS_CheckPaletteFade(struct McssWork *work);

extern struct McssSys *MCSS_Init(unsigned int maxCount, unsigned int heapId);

extern void MCSS_SetTextureTransAdrs(struct McssSys *sys, unsigned int adrs);

extern void MCSS_SetOrthoMode(struct McssSys *sys);

extern void MCSS_Exit(struct McssSys *sys);

extern struct McssWork *MCSS_TOOL_AddPokeMcss(struct McssSys *sys, void *pp, unsigned int direction, int x, int y, int z);

extern void MCSS_SetShadowVanishFlag(struct McssWork *work, int flag);

extern void MCSS_SetPosition(struct McssWork *work, unsigned int *src);

extern void MCSS_SetScale(struct McssWork *work, unsigned int *src);

extern u16 MCSS_GetSizeY(struct McssWork *work);

extern s16 MCSS_GetOfsY(struct McssWork *work);

extern s16 MCSS_GetOfsX(struct McssWork *work);

extern void MCSS_SetOfsPosition(struct McssWork *work, unsigned int *src);

extern void MCSS_SetAnmStopFlag(struct McssWork *work);

extern void MCSS_Del(struct McssSys *sys, struct McssWork *work);

/* Legacy 020173B4 inputs r1-r3 are replaced by its body; full forwarding
 * 02015F2C supplies fixed member, one, original p and callback to 02063000.
 * It reads no caller r1-r3. 02016028 retains live incoming flag in r1. */
extern void MCSS_SetAnimeIndex(struct McssWork *work, unsigned int animeIndex);

extern void *MCSS_GetAnimCtrl(struct McssWork *work);
struct MultiCellAnim;

extern void NNS_G2dRestartMCAnimation(struct MultiCellAnim *pMCAnim);

extern void MCSS_ResetAnmStopFlag(struct McssWork *work);
struct CellAnim;

extern void NNS_G2dSetCellAnimationParam(struct CellAnim *anim, int type, int param, int func);

extern int MCSS_TOOL_SetAnimeStopCallback(struct McssWork *work);

extern u8 MCSS_GetAlpha(struct McssWork *work);

extern void MCSS_SetAlpha(struct McssWork *work, int alpha);

extern void MCSS_ResetVanishFlag(struct McssWork *work);

extern void PARTICLE_InitManager(unsigned);
struct ParticleSys;

extern struct ParticleSys *PARTICLE_CreateSystemDefault(unsigned int workBuf, unsigned int workSize, unsigned int withCamera, unsigned int heapId);

extern void *PARTICLE_LoadArchiveMember(unsigned,unsigned,unsigned);

extern u16 PARTICLE_RESOURCE_GetType(void *);

extern void PARTICLE_SetupSystem(struct ParticleSys *sys, void *block, unsigned int applyNow, unsigned int taskMgr);

extern void PARTICLE_ExitManager(void);

extern int PARTICLE_StartEffect(struct ParticleSys *sys, int resId, int arg);

extern void PARTICLE_KillAllEffects(struct ParticleSys *sys);

extern void PARTICLE_Main(void);

extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);

extern struct Util *G3D_UTIL_Create(u16,u16,u16);

extern void G3D_UTIL_Delete(struct Rec *);

extern unsigned G3D_UTIL_GetObject(unsigned char *,int);
struct G3dObjectStatus;

extern void G3D_SYSTEM_DrawObject(struct G3dObject *obj, struct G3dObjectStatus *status);

extern u16 G3D_UTIL_AddUnit(struct Util *,const struct Setup *);

extern unsigned G3D_UTIL_GetUnitObjIdx(unsigned char *,int);

extern int G3D_SYSTEM_EnableObjectAnime(struct G3dObject *obj, unsigned int anmIdx);

extern int G3D_SYSTEM_SetObjectAnimeFrame(struct G3dObject *obj, unsigned short anmIdx, int *frame);

extern int G3D_SYSTEM_IncObjectAnimeFrame(struct G3dObject *obj, int anmIdx, int step);

Record *EGG_DEMO_VIEW_CreateRecords(unsigned heap,unsigned count);

void EGG_DEMO_VIEW_FreeRecords(void *work);

char *EGG_DEMO_VIEW_Create(unsigned heap,void *mon);

void EGG_DEMO_VIEW_Delete(char *work);

void EGG_DEMO_VIEW_Update(char *work);

void EGG_DEMO_VIEW_Draw(char *work);

void EGG_DEMO_VIEW_SetActive(char *work);

int EGG_DEMO_VIEW_GetActive(char *work);

void EGG_DEMO_VIEW_SetSpecies(char *work, void *species);

int EGG_DEMO_VIEW_IsFadeDone(char *work);

void EGG_DEMO_VIEW_ResetAnimState(char *work);

int EGG_DEMO_VIEW_IsFinished(char *work);

void EGG_DEMO_VIEW_Noop(void);

void EGG_DEMO_VIEW_InitMcss(char *work);

void EGG_DEMO_VIEW_DeleteMcss(char *work);

void EGG_DEMO_VIEW_AddPokeMcss(char *work);

void EGG_DEMO_VIEW_DeletePokeMcss(char *work);

void EGG_DEMO_VIEW_HidePokeMcss(char *work);

void EGG_DEMO_VIEW_PlayAnim(char *work,unsigned flag,int enable);

int EGG_DEMO_VIEW_OnAnimStop(char *work);

void EGG_DEMO_VIEW_UpdateAlpha(char *work);

void EGG_DEMO_VIEW_StartFadeOut(char *work);

int EGG_DEMO_VIEW_IsFadeOutDone(char *work);

void EGG_DEMO_VIEW_StartFadeIn(char *work);

char *EGG_DEMO_VIEW_CreateParticles(unsigned heap,unsigned count,const void *table);

void EGG_DEMO_VIEW_DeleteParticles(char *work);

void EGG_DEMO_VIEW_UpdateParticles(char *work);

void EGG_DEMO_VIEW_MainParticles(char *work);

void EGG_DEMO_VIEW_StartParticles(char *work);

void EGG_DEMO_VIEW_InitModel(char *work);

void EGG_DEMO_VIEW_DeleteModel(char *work);

void EGG_DEMO_VIEW_DrawModels(char *work);

void EGG_DEMO_VIEW_AddModel(char *work);

void EGG_DEMO_VIEW_RemoveModel(char *work);

void EGG_DEMO_VIEW_UpdateModel(char *work);

extern const char d_021F73F4[];

extern const unsigned d_021F7340[],d_021F7314[];

extern const Entry table_021F7384[];

extern const unsigned long long d_021F7300;

extern const EggDemoVec3 d_021F73B4;

extern const struct Setup d_021F7330;

Record *EGG_DEMO_VIEW_CreateRecords(unsigned heap,unsigned count)
{
    Record *records;
    u16 i;
    records=GFL_HEAP_Alloc(heap,68*count,1,d_021F73F4,283);
    for(i=0;i<count;i++) {
        records[i].x=0;records[i].y=0;records[i].z=0;
        records[i].sx=4096;records[i].sy=4096;records[i].sz=4096;
        MTX_Identity33_(records[i].matrix);
    }
    return records;
}

void EGG_DEMO_VIEW_FreeRecords(void *work){GFL_HEAP_Free(work);}

/*
 * evidence: sole callback 021F6AB4 resolved after owned leaf shard verification.
 */
char *EGG_DEMO_VIEW_Create(unsigned heap,void *mon)
{
    char *work;
    work=GFL_HEAP_Alloc(heap,96,1,d_021F73F4,433);
    ((struct EggDemoView *)work)->heapId=heap;
    ((struct EggDemoView *)work)->mon=mon;
    ((struct EggDemoView *)work)->species=POKE_TOOL_GetPartyValue(mon,5,0);
    ((struct EggDemoView *)work)->animState=0;
    ((struct EggDemoView *)work)->startFlag=0;
    ((struct EggDemoView *)work)->visible=0;
    ((struct EggDemoView *)work)->frameCounter=0;
    ((struct EggDemoView *)work)->soundPlaying=0;
    ((struct EggDemoView *)work)->soundDelay=0;
    ((struct EggDemoView *)work)->soundStep=0;
    ((struct EggDemoView *)work)->vblankTask=GFL_USE_AddMainTask((void ( *)(int,char *))EGG_DEMO_VIEW_Noop, (char *)work, 1);
    EGG_DEMO_VIEW_InitMcss(work);
    EGG_DEMO_VIEW_AddPokeMcss(work);
    if(((struct EggDemoView *)work)->species==490)
        ((struct EggDemoView *)work)->particles=EGG_DEMO_VIEW_CreateParticles(((struct EggDemoView *)work)->heapId,5,d_021F7340);
    else
        ((struct EggDemoView *)work)->particles=EGG_DEMO_VIEW_CreateParticles(((struct EggDemoView *)work)->heapId,3,d_021F7314);
    EGG_DEMO_VIEW_InitModel(work);
    EGG_DEMO_VIEW_AddModel(work);
    return work;
}

/*
 * trailing: zero halfword at 021F67DE is alignment padding.
 */
void EGG_DEMO_VIEW_Delete(char *work){EGG_DEMO_VIEW_RemoveModel(work);EGG_DEMO_VIEW_DeleteModel(work);EGG_DEMO_VIEW_DeleteParticles(*(char * *)&((struct EggDemoView *)work)->particles);EGG_DEMO_VIEW_DeletePokeMcss(work);EGG_DEMO_VIEW_DeleteMcss(work);TCB_DeleteTask((struct TcbTask *)(*(struct Node * *)&((struct EggDemoView *)work)->vblankTask));GFL_HEAP_Free(work);}

void EGG_DEMO_VIEW_Update(char *work)
{
    u32 limit,a,b;
    switch(((struct EggDemoView *)work)->animState) {
    case 0:
        if(((struct EggDemoView *)work)->startFlag) {
            ((struct EggDemoView *)work)->animState=1;((struct EggDemoView *)work)->frameCounter=0;
            EGG_DEMO_VIEW_PlayAnim(work,1,1);
            EGG_DEMO_VIEW_StartParticles(*(char * *)&((struct EggDemoView *)work)->particles);
        }
        break;
    case 1:
        if(((struct EggDemoView *)work)->species==490)limit=300;else limit=380;
        ((struct EggDemoView *)work)->frameCounter++;
        if(((struct EggDemoView *)work)->species==490) {
            switch(((struct EggDemoView *)work)->soundStep) {
            case 0: if(((struct EggDemoView *)work)->frameCounter==10){GFL_USE_PlaySeDefaultVolume(1955);((struct EggDemoView *)work)->soundStep=1;}break;
            case 1: if(!GFL_USE_IsAnySeBusy()){GFL_USE_PlaySeDefaultVolume(1960);((struct EggDemoView *)work)->soundStep=2;}break;
            case 2: if(!GFL_USE_IsAnySeBusy())((struct EggDemoView *)work)->soundStep=3;break;
            case 3:break;
            }
        }else{
            if(((struct EggDemoView *)work)->frameCounter==20)GFL_USE_PlaySeDefaultVolume(1954);
            else if(((struct EggDemoView *)work)->frameCounter==109)GFL_USE_PlaySeDefaultVolume(1954);
            else if(((struct EggDemoView *)work)->frameCounter==218)GFL_USE_PlaySeDefaultVolume(1488);
            if(((struct EggDemoView *)work)->frameCounter==10)GFL_USE_PlaySeDefaultVolume(1968);
            else if(((struct EggDemoView *)work)->frameCounter==15)GFL_USE_PlaySeDefaultVolume(1968);
            else if(((struct EggDemoView *)work)->frameCounter==85)GFL_USE_PlaySeDefaultVolume(1968);
            else if(((struct EggDemoView *)work)->frameCounter==90)GFL_USE_PlaySeDefaultVolume(1968);
            if(((struct EggDemoView *)work)->soundPlaying&&!GFL_USE_IsSeSlotBusy(((struct EggDemoView *)work)->soundSlot)) {
                ((struct EggDemoView *)work)->soundPlaying=0;
                if(((struct EggDemoView *)work)->frameCounter>=150&&((struct EggDemoView *)work)->frameCounter<309)((struct EggDemoView *)work)->soundDelay=20;
                else if(((struct EggDemoView *)work)->frameCounter>309)((struct EggDemoView *)work)->soundDelay=0;
            }
            if(((struct EggDemoView *)work)->frameCounter>=150&&((struct EggDemoView *)work)->frameCounter<limit) {
                if(!((struct EggDemoView *)work)->soundPlaying) {
                    if(!((struct EggDemoView *)work)->soundDelay) {
                        ((struct EggDemoView *)work)->soundSlot=GFL_USE_GetSeSlot(1967);
                        GFL_USE_PlaySeInSlot((unsigned int)1967,((struct EggDemoView *)work)->soundSlot);
                        ((struct EggDemoView *)work)->soundPlaying=1;
                    }else ((struct EggDemoView *)work)->soundDelay--;
                }
            }else if(((struct EggDemoView *)work)->frameCounter==limit&&((struct EggDemoView *)work)->soundPlaying&&GFL_USE_IsSeSlotBusy(((struct EggDemoView *)work)->soundSlot)) {
                GFL_USE_StopSeSlot(((struct EggDemoView *)work)->soundSlot);((struct EggDemoView *)work)->soundPlaying=0;
            }
        }
        if(((struct EggDemoView *)work)->frameCounter==limit) {
            EGG_DEMO_VIEW_StartFadeOut(work);EGG_DEMO_VIEW_StartModelAnim(work);GFL_USE_PlaySeDefaultVolume(1935);((struct EggDemoView *)work)->animState=2;
        }
        break;
    case 2:if(EGG_DEMO_VIEW_IsFadeOutDone(work))((struct EggDemoView *)work)->animState=3;break;
    case 3:if(EGG_DEMO_VIEW_IsModelAnimDone(work)){EGG_DEMO_VIEW_HidePokeMcss(work);((struct EggDemoView *)work)->visible=1;((struct EggDemoView *)work)->animState=4;}break;
    case 4:((struct EggDemoView *)work)->visible=0;break;
    case 6:
        if(++((struct EggDemoView *)work)->frameCounter>=120){EGG_DEMO_VIEW_StartFadeIn(work);EGG_DEMO_VIEW_EndModelAnim(work);((struct EggDemoView *)work)->animState=7;((struct EggDemoView *)work)->frameCounter=0;}
        break;
    case 7:
        if(++((struct EggDemoView *)work)->frameCounter>=65) {
            ((struct EggDemoView *)work)->animState=8;
            a=POKE_TOOL_GetPartyValue(((struct EggDemoView *)work)->mon,5,0);
            b=POKE_TOOL_GetPartyValue(((struct EggDemoView *)work)->mon,111,0);
            PM_VOICE_Play(a,b,64,0,0,0,0,0);
        }
        break;
    case 8:if(!PM_VOICE_IsAnyActive())((struct EggDemoView *)work)->animState=9;break;
    case 9:break;
    }
    EGG_DEMO_VIEW_UpdateAlpha(work);
    MCSS_Main((struct McssSys *)(*(char * *)&((struct EggDemoView *)work)->mcss));
    EGG_DEMO_VIEW_UpdateParticles(*(char * *)&((struct EggDemoView *)work)->particles);
    EGG_DEMO_VIEW_UpdateModel(work);
}

void EGG_DEMO_VIEW_Draw(char *work){MCSS_Draw(*(struct McssSys * *)&((struct EggDemoView *)work)->mcss);EGG_DEMO_VIEW_DrawModels(work);EGG_DEMO_VIEW_MainParticles(*(char * *)&((struct EggDemoView *)work)->particles);}

/*
 * leaf: two unlabelled leaves blocking concrete MATCH900 ov215021F5884.
 * extent: setter, two alignment bytes, four-byte getter; twelve bytes total.
 */
void EGG_DEMO_VIEW_SetActive(char *work){((struct EggDemoView *)work)->startFlag=1;}

int EGG_DEMO_VIEW_GetActive(char *work){return ((struct EggDemoView *)work)->visible;}

void EGG_DEMO_VIEW_SetSpecies(char *work, void *species)
{
    EGG_DEMO_VIEW_DeletePokeMcss(work);
    ((struct EggDemoView *)work)->mon = (void *)species;
    EGG_DEMO_VIEW_AddPokeMcss(work);
    EGG_DEMO_VIEW_PlayAnim(work,0,0);
    MCSS_SetVanishFlag(((struct EggDemoView *)work)->pokeMcss);
    MCSS_SetPaletteFade((struct McssWork *)((struct EggDemoView *)work)->pokeMcss,16,16,0,32767);
    ((struct EggDemoView *)work)->animState = 5;
}

/*
 * trailing: existing followers 021F6A98/6AA4 unit and 021F6AB4 shard.
 */
int EGG_DEMO_VIEW_IsFadeDone(char *work){if(MCSS_CheckPaletteFade(((struct EggDemoView *)work)->pokeMcss)==0)return 1;return 0;}

void EGG_DEMO_VIEW_ResetAnimState(char *work){((struct EggDemoView *)work)->animState=6;((struct EggDemoView *)work)->frameCounter=0;}

int EGG_DEMO_VIEW_IsFinished(char *work){if(((struct EggDemoView *)work)->animState>=9)return 1;return 0;}

/*
 * evidence: sole callback blocker of 021F6720; parent SDK/ownership audit.
 * extent: bx lr at 021F6AB4, zero padding at 6AB6; 6AB8 begins next function.
 */
void EGG_DEMO_VIEW_Noop(void)
{
}

void EGG_DEMO_VIEW_InitMcss(char *work)
{
    ((struct EggDemoView *)work)->mcss = MCSS_Init((unsigned int)1, (unsigned int)(*(unsigned short *)work));
    MCSS_SetTextureTransAdrs(((struct EggDemoView *)work)->mcss, 3 << 16);
    MCSS_SetOrthoMode(((struct EggDemoView *)work)->mcss);
    ((struct EggDemoView *)work)->alphaActive = 0;
    ((struct EggDemoView *)work)->alphaTarget = 0;
}

void EGG_DEMO_VIEW_DeleteMcss(char *work){MCSS_Exit((struct McssSys *)(*(u8 * *)&((struct EggDemoView *)work)->mcss));}

/*
 * lever: FX float rounding macro; translation z shares the constructor's -50<<16 literal.
 */
void EGG_DEMO_VIEW_AddPokeMcss(char *work)
{
    EggDemoVec3 trans,scale,delta;
    u32 species;
    u8 i=0;
    float angle,y,x;
    ((struct EggDemoView *)work)->pokeMcss=MCSS_TOOL_AddPokeMcss(((struct EggDemoView *)work)->mcss,((struct EggDemoView *)work)->mon,0,0,0xfff42000,0xffce0000);
    MCSS_SetShadowVanishFlag((struct McssWork *)(*(char * *)&((struct EggDemoView *)work)->pokeMcss),1);
    species=POKE_TOOL_GetPartyValue(((struct EggDemoView *)work)->mon,171,0);
    if(species!=650){
        for(;i<4;i++){
            if(species==table_021F7384[i].species){
                trans.x=FIX(table_021F7384[i].x);
                trans.y=FIX(table_021F7384[i].y);
                trans.z=0xffce0000;
                MCSS_SetPosition(((struct EggDemoView *)work)->pokeMcss,(u32 *)&trans);
                break;
            }
        }
    }
    scale.x=65536;scale.y=65536;scale.z=4096;
    MCSS_SetScale(((struct EggDemoView *)work)->pokeMcss,(u32 *)&scale);
    angle=(float)MCSS_GetSizeY(((struct EggDemoView *)work)->pokeMcss);
    y=(float)MCSS_GetOfsY(((struct EggDemoView *)work)->pokeMcss);
    x=(float)MCSS_GetOfsX(((struct EggDemoView *)work)->pokeMcss);
    if(angle>96.0f)angle=96.0f;
    y=(96.0f-angle)/2.0f+y;
    x=0.0f-x;
    delta.x=FIX(x);delta.y=FIX(y);delta.z=0;
    MCSS_SetOfsPosition(((struct EggDemoView *)work)->pokeMcss,(u32 *)&delta);
    MCSS_SetAnmStopFlag(((struct EggDemoView *)work)->pokeMcss);
}

/*
 * trailing: existing follower 021F6CC0 in its own matched shard.
 */
void EGG_DEMO_VIEW_DeletePokeMcss(char *work){MCSS_SetVanishFlag(((struct EggDemoView *)work)->pokeMcss);MCSS_Del(((struct EggDemoView *)work)->mcss,((struct EggDemoView *)work)->pokeMcss);}

/*
 * leaf: sole overlay blocker of 021F67E0; tail-call pool ends at 021F6CCC.
 */
void EGG_DEMO_VIEW_HidePokeMcss(char *work){MCSS_SetVanishFlag(((struct EggDemoView *)work)->pokeMcss);}

void EGG_DEMO_VIEW_PlayAnim(char *work,unsigned flag,int enable)
{
    void *obj;
    MCSS_SetAnimeIndex(((struct EggDemoView *)work)->pokeMcss,flag);
    obj=MCSS_GetAnimCtrl(((struct EggDemoView *)work)->pokeMcss);
    NNS_G2dRestartMCAnimation(obj);
    MCSS_ResetAnmStopFlag(((struct EggDemoView *)work)->pokeMcss);
    if(enable) {
        NNS_G2dSetCellAnimationParam(obj,1,(int)work,(int)EGG_DEMO_VIEW_OnAnimStop);
        ((struct EggDemoView *)work)->animStopFlag=0;
    } else MCSS_TOOL_SetAnimeStopCallback((((struct EggDemoView *)work)->pokeMcss));
}

/*
 *   entry), so neither label nor sole-ref/code can attest the bl site;
 *   byte-correct.
 */
int EGG_DEMO_VIEW_OnAnimStop(char *work)
{
    MCSS_SetAnmStopFlag((void *)(((struct EggDemoView *)work)->pokeMcss));
    ((struct EggDemoView *)work)->animStopFlag = 1;
    return 1;
}

void EGG_DEMO_VIEW_UpdateAlpha(char *work){u8 n;if(((struct EggDemoView *)work)->alphaActive){n=MCSS_GetAlpha((struct McssWork *)(*(struct Data * *)&((struct EggDemoView *)work)->pokeMcss));if(n>((struct EggDemoView *)work)->alphaTarget)n--;else n++;MCSS_SetAlpha((struct McssWork *)(*(char * *)&((struct EggDemoView *)work)->pokeMcss),n);if(n==((struct EggDemoView *)work)->alphaTarget)((struct EggDemoView *)work)->alphaActive=0;}}

void EGG_DEMO_VIEW_StartFadeOut(char *work){MCSS_SetAnmStopFlag(((struct EggDemoView *)work)->pokeMcss);MCSS_SetPaletteFade((struct McssWork *)(*(struct McssFade * *)&((struct EggDemoView *)work)->pokeMcss),0,16,0,32767);}

int EGG_DEMO_VIEW_IsFadeOutDone(char *work){if(MCSS_CheckPaletteFade(((struct EggDemoView *)work)->pokeMcss)==0)return 1;return 0;}

void EGG_DEMO_VIEW_StartFadeIn(char *work){MCSS_ResetVanishFlag(((struct EggDemoView *)work)->pokeMcss);MCSS_SetPaletteFade((struct McssWork *)(*(struct McssFade * *)&((struct EggDemoView *)work)->pokeMcss),16,0,2,32767);}

char *EGG_DEMO_VIEW_CreateParticles(unsigned heap,unsigned count,const void *table)
{
    char *work;
    unsigned zero[3]={0};
    unsigned long long config;
    int resource;
    work=GFL_HEAP_Alloc(heap,0x481C,1,d_021F73F4,0x502);
    ((struct EggDemoParticles *)work)->frame=0;
    ((struct EggDemoParticles *)work)->index=0;
    ((struct EggDemoParticles *)work)->count=count;
    *(const void * *)&((struct EggDemoParticles *)work)->table=table;
    ((struct EggDemoParticles *)work)->active=0;
    ((struct EggDemoParticles *)work)->life=-1;
    PARTICLE_InitManager(heap);
    *(int *)&((struct EggDemoParticles *)work)->system=(int)PARTICLE_CreateSystemDefault((int)(work+12),0x4800,1,heap);
    config=d_021F7300;
    resource=(int)PARTICLE_LoadArchiveMember((unsigned)config,(unsigned)(config>>32),heap);
    ((struct EggDemoParticles *)work)->resourceType=PARTICLE_RESOURCE_GetType((void *)resource);
    PARTICLE_SetupSystem(((struct EggDemoParticles *)work)->system,(void *)resource,1,0);
    return work;
}

void EGG_DEMO_VIEW_DeleteParticles(char *work)
{
    PARTICLE_ExitManager();
    GFL_HEAP_Free(work);
}

/*
 * prototype: 515B4 receives visibly loaded r1/r2 despite legacy one-argument callee.
 */
void EGG_DEMO_VIEW_UpdateParticles(char *work)
{
    if (((struct EggDemoParticles *)work)->active) {
        EggDemoVec3 v=d_021F73B4;
        while (((struct EggDemoParticles *)work)->index<((struct EggDemoParticles *)work)->count) {
            const char *table=*(const char * *)&((struct EggDemoParticles *)work)->table;
            unsigned index=((struct EggDemoParticles *)work)->index;
            u16 frame=((struct EggDemoParticles *)work)->frame;
            u16 key=*(u16 *)(table+(int)index*4);
            if (frame!=key) break;
            PARTICLE_StartEffect(*(void **)(work+*(unsigned char *)(table+index*4+2)*0x4808+0x480c),*(unsigned char *)(table+index*4+3),(int)(&v));
            (((struct EggDemoParticles *)work)->index)++;
        }
        (((struct EggDemoParticles *)work)->frame)++;
    }
    if (((struct EggDemoParticles *)work)->life>=0) {
        if (((struct EggDemoParticles *)work)->life==0) PARTICLE_KillAllEffects(((struct EggDemoParticles *)work)->system);
        (((struct EggDemoParticles *)work)->life)--;
    }
}

void EGG_DEMO_VIEW_MainParticles(char *work){PARTICLE_Main();}

/*
 * leaf: sole overlay blocker of 021F67E0; store and return, pool ends 021F6EF8.
 */
void EGG_DEMO_VIEW_StartParticles(char *work){((struct EggDemoParticles *)work)->active=1;}

void EGG_DEMO_VIEW_InitModel(char *work){unsigned z=0;G3D_SYSTEM_SetSwapBuffersMode(1,z);*(struct Util * *)&((struct EggDemoView *)work)->util=G3D_UTIL_Create(4,1,((struct EggDemoView *)work)->heapId);((struct EggDemoView *)work)->recordCount=z;}

void EGG_DEMO_VIEW_DeleteModel(char *work){G3D_UTIL_Delete(*(struct Rec * *)&((struct EggDemoView *)work)->util);}

void EGG_DEMO_VIEW_DrawModels(char *work)
{
    unsigned short i;
    for(i=0;i<((struct EggDemoView *)work)->recordCount;i++) {
        char *entry=*(char * *)&((struct EggDemoView *)work)->records+i*0x44;
        if(((Record *)entry)->tail)
            G3D_SYSTEM_DrawObject((void *)G3D_UTIL_GetObject(*(unsigned char * *)&((struct EggDemoView *)work)->util,((Record *)entry)->tag),(struct G3dObjectStatus *)(entry+4));
    }
}

void EGG_DEMO_VIEW_AddModel(char *work)
{
    unsigned id;
    char *entry;
    u16 i;
    void *q;
    int frame;
    ((struct EggDemoView *)work)->unitId=G3D_UTIL_AddUnit(*(struct Util * *)&((struct EggDemoView *)work)->util,&d_021F7330);
    ((struct EggDemoView *)work)->recordCount=1;
    *(struct Record * *)&((struct EggDemoView *)work)->records=(struct Record *)EGG_DEMO_VIEW_CreateRecords(((struct EggDemoView *)work)->heapId,((struct EggDemoView *)work)->recordCount);
    id=G3D_UTIL_GetUnitObjIdx(*(unsigned char * *)&((struct EggDemoView *)work)->util,((struct EggDemoView *)work)->unitId);
    ((struct EggDemoView *)work)->animIndex=0;
    entry=*(char * *)&((struct EggDemoView *)work)->records;
    ((Record *)entry)->tag=id;
    ((Record *)entry)->x=0;
    ((Record *)entry)->y=0;
    ((Record *)entry)->z=0;
    ((Record *)entry)->tail=1;
    for(i=0;i<((struct EggDemoView *)work)->recordCount;i++)
        G3D_SYSTEM_EnableObjectAnime((struct G3dObject *)G3D_UTIL_GetObject(*(unsigned char * *)&((struct EggDemoView *)work)->util,*(u16 *)(*(char * *)&((struct EggDemoView *)work)->records+i*68)),0);
    ((struct EggDemoView *)work)->animFrame=0;
    q=(void *)G3D_UTIL_GetObject(*(unsigned char * *)&((struct EggDemoView *)work)->util,*(u16 *)(*(char * *)&((struct EggDemoView *)work)->records+((struct EggDemoView *)work)->animIndex*68));
    frame=0;
    ((struct EggDemoView *)work)->modelAnimState=0;
    G3D_SYSTEM_EnableObjectAnime((struct G3dObject *)q,1);
    G3D_SYSTEM_EnableObjectAnime((struct G3dObject *)q,2);
    G3D_SYSTEM_SetObjectAnimeFrame((struct G3dObject *)q,1,&frame);
    G3D_SYSTEM_SetObjectAnimeFrame((struct G3dObject *)q,2,&frame);
}

void EGG_DEMO_VIEW_RemoveModel(char *work){G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct EggDemoView *)work)->util,((struct EggDemoView *)work)->unitId);EGG_DEMO_VIEW_FreeRecords(((struct EggDemoView *)work)->records);((struct EggDemoView *)work)->recordCount=0;}

void EGG_DEMO_VIEW_UpdateModel(char *work)
{
    u16 i;
    void *q;
    int a, b;

    for (i = 0; i < ((struct EggDemoView *)work)->recordCount; i++) {
        G3D_SYSTEM_LoopObjectAnimeFrame((void *)G3D_UTIL_GetObject((unsigned char *)(((struct EggDemoView *)work)->util), *(u16 *)(*(char * *)&((struct EggDemoView *)work)->records + i * 0x44)), 0, 0x1000);
    }
    ((struct EggDemoView *)work)->animFrame = ((struct EggDemoView *)work)->animFrame + 1;
    q = (void *)G3D_UTIL_GetObject((unsigned char *)(((struct EggDemoView *)work)->util), *(u16 *)(*(char * *)&((struct EggDemoView *)work)->records + ((struct EggDemoView *)work)->animIndex * 0x44));
    if (((struct EggDemoView *)work)->modelAnimState == 1) {
        a = G3D_SYSTEM_IncObjectAnimeFrame(q, 1, 0x5000);
        b = G3D_SYSTEM_IncObjectAnimeFrame(q, 2, 0x5000);
        if (a == 0 && b == 0)
            ((struct EggDemoView *)work)->modelAnimState = 2;
    } else if (((struct EggDemoView *)work)->modelAnimState == 3) {
        a = G3D_SYSTEM_IncObjectAnimeFrame(q, 1, -0x2000);
        b = G3D_SYSTEM_IncObjectAnimeFrame(q, 2, -0x2000);
        if (a == 0 && b == 0)
            ((struct EggDemoView *)work)->modelAnimState = 0;
    }
}

void EGG_DEMO_VIEW_StartModelAnim(char *work){((struct EggDemoView *)work)->modelAnimState=1;}

int EGG_DEMO_VIEW_IsModelAnimDone(char *work){return ((struct EggDemoView *)work)->modelAnimState==2;}

void EGG_DEMO_VIEW_EndModelAnim(char *work){((struct EggDemoView *)work)->modelAnimState=3;}
