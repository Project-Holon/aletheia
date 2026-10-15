/*
 * file:     pokemontrade_demo_middle.c
 * unit:     yes
 * function: POKETRADE_DEMO_MIDDLE_StepStartPlayback, POKETRADE_DEMO_MIDDLE_PrintMessage, POKETRADE_DEMO_MIDDLE_StepMessage, POKETRADE_DEMO_MIDDLE_StepEndScene, POKETRADE_DEMO_MIDDLE_DeleteSlide, POKETRADE_DEMO_MIDDLE_CreateOfferSlide, POKETRADE_DEMO_MIDDLE_ResetMonSlide, POKETRADE_DEMO_MIDDLE_UpdateEmitterA, POKETRADE_DEMO_MIDDLE_SetupEmitterA, POKETRADE_DEMO_MIDDLE_UpdateEmitterB, POKETRADE_DEMO_MIDDLE_SetupEmitterB, POKETRADE_DEMO_MIDDLE_StepStartCompare, POKETRADE_DEMO_MIDDLE_StepSetup, POKETRADE_DEMO_MIDDLE_StepParticleSystems, POKETRADE_DEMO_MIDDLE_StepAddUnit, POKETRADE_DEMO_MIDDLE_UpdateScene
 * address:  0x021D6918
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D64F4  0x021D64F4  thumb  ov118
 *   func_021D6600  0x021D6600  thumb  ov118
 *   func_021D667C  0x021D667C  thumb  ov118
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   POKETRADE_3D_RemoveCurrentUnit  0x021E3230  thumb  ov119
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb  ov119
 *   POKETRADE_MCSS_SlideBegin  0x021DFB4C  thumb  ov119
 *   POKETRADE_MCSS_SlideCreate  0x021DFB84  thumb  ov119
 *   d_021D7CEC     0x021D7CEC  data  a4
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   func_021D6734  0x021D6734  thumb  ov118
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_2D_DeleteAllOfferIconActors  0x021E64B8  thumb  ov119
 *   POKETRADE_2D_DeleteAllBoxIcons  0x021E4888  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows  0x021E2680  thumb  ov119
 *   func_021D6738  0x021D6738  thumb  ov118
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   PM_VOICE_GetPerapVoiceSave  0x02006CAC  thumb
 *   PM_VOICE_Play  0x02006984  thumb
 *   func_020307B0  0x020307B0  arm
 *   MCSS_GetPosition  0x02015C30  thumb
 *   POKETRADE_SAVE_FreeIfSet  0x021DFD24  thumb  ov119
 *   POKETRADE_MCSS_SlideCreateWithOffsets  0x021DFBB4  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssPlain  0x021E36C8  thumb  ov119
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   d_021D82C0     0x021D82C0  data
 *   d_021D8470     0x021D8470  data
 *   d_021D8880     0x021D8880  data
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   MSGDATA_ReadString  0x02045CAC  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02041300  0x02041300  arm
 *   POKETRADE_SAVE_OpenMessageWindowAtPos  0x021E0FF4  thumb  ov119
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   POKETRADE_SAVE_IsMessagePrintDone  0x021E12AC  thumb  ov119
 *   POKETRADE_SAVE_CloseMessageWindowClear  0x021E1098  thumb  ov119
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   func_021D66E8  0x021D66E8  thumb  ov118
 *   POKETRADE_3D_ExitParticleManager  0x021E3034  thumb  ov119
 *   POKETRADE_3D_FreeParticleResources  0x021E2F2C  thumb  ov119
 *   POKETRADE_SAVE_ResetClactAndBeginEvent  0x021DFDA0  thumb  ov119
 *   d_021D7CDC     0x021D7CDC  data a4
 *   d_021D8398     0x021D8398  data a4
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   BUTTON_MAN_GetUserData  0x02051A34  arm
 *   ICA_ANIME_GetTranslate  0x02011610  thumb
 *   BUTTON_MAN_SetEmitterPos  0x02051838  arm
 *   func_021D6744  0x021D6744  thumb
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   func_021D6750  0x021D6750  thumb
 *   POKETRADE_PROC_DeleteAllResources  0x021DC720  thumb
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemMain  0x021E3E40  thumb
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   POKETRADE_2D_SetupSummaryBgs  0x021E5284  thumb
 *   POKETRADE_3D_AddPokemonMcss  0x021E35A0  thumb ov119
 *   POKETRADE_3D_InitParticleSystems  0x021E2F34  thumb
 *   POKETRADE_3D_SetupParticleSystemsLow  0x021E2FB0  thumb ov119
 *   POKETRADE_3D_CreateIcaStreamsForMode  0x021E2D70  thumb
 *   d_021D866C  0x021D866C  data
 *   POKETRADE_3D_SetupParticleSystemsHigh  0x021E3004  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb  ov119
 *   POKETRADE_DEMO_MIDDLE_UpdateScene  0x021D7130  thumb  ov118
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 */
#include "../../matched/include/Obj05325.h"
#include "../../matched/include/Obj00984.h"
#include "../../matched/include/Obj01725.h"
#include "../../matched/include/Obj13881.h"
#include "../../matched/include/Obj01149.h"
#include "../../matched/include/Obj13882.h"
#include "../../matched/include/Obj22692.h"
#include "../../matched/include/Obj22693.h"
#include "../../matched/include/Obj13883.h"
#include "../../matched/include/Obj22694.h"
#include "../../matched/include/Obj22695.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj22696.h"

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))
#define FLAG(i) (((int *)(p + 0x854))[i])
#define WORK (*(u8 **)(p + 0xc))
#define REC(i) (((Vec *)((u8 *)WORK + 0x60))[i])
struct WordSet;
struct MsgBank;
struct IcaAnime;
struct Rec12;
struct Bank;
typedef unsigned int u32;

typedef unsigned short u16;

typedef unsigned char u8;

typedef signed char s8;

typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u32 v[4];
} Quad;

typedef struct {
    u32 v[4];
} Tbl;

extern void func_021D64F4(s8 *fade);
extern void POKETRADE_MCSS_SlideUpdate(void *p, int a1);
extern int func_021D6734(int);
extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
extern void POKETRADE_2D_DeleteAllOfferIconActors(void *p);
extern void POKETRADE_2D_DeleteAllBoxIcons(char *p);
extern void POKETRADE_SAVE_DeleteOfferListWindows(char *p);
extern void func_021D6738(u8 *p, u32 v);
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *, int);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern void PM_VOICE_GetPerapVoiceSave(void **out);
extern u32 PM_VOICE_Play(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern u32 func_020307B0(void *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void POKETRADE_SAVE_FreeIfSet(u32 *p);
extern void *POKETRADE_MCSS_SlideCreateWithOffsets(void *a0, void *a1, void *a2, void *a3, u16 heapId);
extern void POKETRADE_3D_AddPokemonMcssPlain(void *p, int a, int b, void *mon, int c);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_SetVanishFlag(void *p);
extern void POKETRADE_PROC_SetStep(void *p, int next);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02041300(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void POKETRADE_SAVE_OpenMessageWindowAtPos(void *p, int a, int b);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern int POKETRADE_SAVE_IsMessagePrintDone(char *p);
extern void POKETRADE_SAVE_CloseMessageWindowClear(char *p);
extern void POKETRADE_3D_DeleteMcssSlot(void *p, int a);
extern void func_021D66E8(void *);
extern void POKETRADE_3D_ExitParticleManager(u32 *p, int a1);
extern void POKETRADE_3D_FreeParticleResources(void *);
extern void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);
extern void MCSS_GetScale(void *p, u32 *out);
extern void MCSS_SetScale(void *p, u32 *src);
extern int BUTTON_MAN_GetUserData(void *p);
extern unsigned int ICA_ANIME_GetTranslate(struct IcaAnime *, struct Rec12 *);
extern void BUTTON_MAN_SetEmitterPos(void *, Vec *);
extern u32 func_02051774(void);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern void func_021D6744(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern void func_021D6750(u8 *p);
extern void POKETRADE_PROC_DeleteAllResources(void *p);
extern void CLACT_ExitSystem(void);
extern void POKETRADE_2D_InitClactSystemMain(void *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKETRADE_2D_SetupSummaryBgs(void *p, int a);
extern void POKETRADE_3D_AddPokemonMcss(void *p, int a, int b, void *mon, int c);
extern void POKETRADE_3D_InitParticleSystems(void *w);
extern void POKETRADE_3D_SetupParticleSystemsLow(char *p);
extern void POKETRADE_3D_CreateIcaStreamsForMode(void *w, int a);
extern void POKETRADE_3D_SetupParticleSystemsHigh(char *p);
extern void POKETRADE_3D_AddUnitAndInit(void *p, int a);
extern void POKETRADE_DEMO_MIDDLE_UpdateScene(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepStartPlayback(u8 *p);
void POKETRADE_DEMO_MIDDLE_PrintMessage(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepMessage(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepEndScene(void *p);
void POKETRADE_DEMO_MIDDLE_DeleteSlide(void *p, int a1);
void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(void *a0, int a1);
void POKETRADE_DEMO_MIDDLE_ResetMonSlide(void *p, int idx);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *p);
void POKETRADE_DEMO_MIDDLE_UpdateEmitterB(void *obj, int on);
void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *p);
void POKETRADE_DEMO_MIDDLE_StepStartCompare(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepSetup(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepParticleSystems(u8 *p);
void POKETRADE_DEMO_MIDDLE_StepAddUnit(u8 *p);
extern const u8 d_021D82C0[];
extern const u8 d_021D8470[];
extern u8 d_021D8880[];
extern const Quad d_021D7CDC;
extern const u32 d_021D8398[];
extern const char d_021D866C[];


void POKETRADE_DEMO_MIDDLE_StepStartPlayback(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    func_021D64F4(*(s8 * *)&((struct Obj05325 *)p)->f818);
    POKETRADE_MCSS_SlideUpdate((void *)(((struct Obj05325 *)p)->f85C), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(((struct Obj05325 *)p)->f860), (int)p);
    if (FRAME > func_021D6734(0x2A)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0);
        POKETRADE_2D_DeleteAllOfferIconActors(p);
        POKETRADE_2D_DeleteAllBoxIcons((char *)p);
        POKETRADE_SAVE_DeleteOfferListWindows((char *)p);
        func_021D6738(p, 0);
        mon = POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p));
        POKE_TOOL_GetPartyValue(mon, 7, 0);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            a = POKE_TOOL_GetPartyValue(mon, 0xAB, 0);
            b = POKE_TOOL_GetPartyValue(mon, 0x6F, 0);
            PM_VOICE_GetPerapVoiceSave((void **)(&buf));
            PM_VOICE_Play(a, b, 0x40, 0, 0, 0, 0, (u32)(&buf));
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        if (((struct Obj05325 *)p)->f11ED == 0) {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v1));
            POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
            if (((struct Obj05325 *)p)->f11EF != 0) {
                SLOT0 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x14, &v1, d_021D8880, HEAP);
            } else {
                SLOT0 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x12, &v1, (void *)d_021D82C0, HEAP);
            }
            POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)), 1);
            MCSS_SetAnmStopFlag((void *)OBJ(2));
            MCSS_SetVanishFlag((void *)OBJ(2));
        } else {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v2));
            POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
            if (((struct Obj05325 *)p)->f11EF != 0) {
                SLOT0 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x14, &v2, d_021D8880, HEAP);
            } else {
                SLOT0 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x28, &v2, (void *)d_021D8470, HEAP);
            }
        }
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepMessage);
    }
}


/*
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_MIDDLE_PrintMessage(u8 *p)
{
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00984 *)p)->f5F4);
    if (((struct Obj00984 *)p)->f118C == 6) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00984 *)p)->f720), 0x98, (void *)(((struct Obj00984 *)p)->f73C));
    } else if (((struct Obj00984 *)p)->f118C == 8) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00984 *)p)->f720), 0x9B, (void *)(((struct Obj00984 *)p)->f73C));
    } else if (((struct Obj00984 *)p)->f11ED != 0) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00984 *)p)->f720), 0x82, (void *)(((struct Obj00984 *)p)->f73C));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00984 *)p)->f720), 0x81, (void *)(((struct Obj00984 *)p)->f73C));
    }
    func_0201EEF4(((struct Obj00984 *)p)->f724, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00984 *)p)->f724), 1, (void *)(((struct Obj00984 *)p)->f834));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00984 *)p)->f724), (void *)(((struct Obj00984 *)p)->f738), (void *)(((struct Obj00984 *)p)->f73C));
    func_02041300(4, 0, 0, 0, 0x20, 0x18, 0x11);
    POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
    POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}


void POKETRADE_DEMO_MIDDLE_StepMessage(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        POKETRADE_DEMO_MIDDLE_PrintMessage(p);
    }
    if (((struct Obj00984 *)p)->f11ED == 0 && FRAME == 6) {
        MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v));
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_ResetAnmStopFlag((void *)OBJ(2));
        *(u32 *)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && POKETRADE_SAVE_IsMessagePrintDone((char *)p) != 0) {
        POKETRADE_SAVE_CloseMessageWindowClear((char *)p);
        if (((struct Obj00984 *)p)->f11ED == 0) {
            POKETRADE_3D_DeleteMcssSlot(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepSetup);
    }
    POKETRADE_MCSS_SlideUpdate((void *)SLOT0, (int)p);
}


void POKETRADE_DEMO_MIDDLE_StepEndScene(void *p)
{
    func_021D66E8(p);
    POKETRADE_3D_ExitParticleManager(((struct Obj01725 *)p)->fC, 6);
    POKETRADE_3D_FreeParticleResources(((struct Obj01725 *)p)->fC);
    func_020307B0(((struct Obj01725 *)p)->fC);
    ((struct Obj01725 *)p)->fC = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_ResetClactAndBeginEvent);
}


void POKETRADE_DEMO_MIDDLE_DeleteSlide(void *p, int a1)
{
    void *q = ((struct Obj13881 *)p)->f85C;
    if (q != 0) {
        func_020307B0(q);
        ((struct Obj13881 *)p)->f85C = 0;
    }
}


/*
 * Lever: own callee 021DFBB4 takes the table as argument four and u16 heap
 * as argument five. Correct order and a word-aligned three-word output
 * buffer settle the saved registers; nonzero 11F0 arms come first. Bare
 * aligned data hints resolve the contested table through sole-ref/data.
 *
 * Addresses are Black-image addresses.
 */
void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(void *a0, int a1)
{
    void *x;
    u32 buf[3];

    x = POKETRADE_PROC_GetSideMon(a0, 1 - POKETRADE_PROC_IsHostSide(a0));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0),
                      0x40, 0, 0, 0, 0, 0);
    }
    if (((struct Obj01149 *)a0)->f11EE == 0) {
        MCSS_GetPosition((void *)((u32 *)((char *)a0 + 0x844))[a1], buf);
        POKETRADE_SAVE_FreeIfSet(*(u32 * *)&((struct Obj01149 *)a0)->f868);
        if (((struct Obj01149 *)a0)->f11F0 != 0)
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)((u32 *)((char *)a0 + 0x844))[a1], (void *)0x14, buf, (void *)d_021D8880, ((struct Obj01149 *)a0)->f5F4);
        else
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)((u32 *)((char *)a0 + 0x844))[a1], (void *)0x28, buf, (void *)d_021D8470, ((struct Obj01149 *)a0)->f5F4);
        return;
    } else {
        Quad t;
        u32 r6;

        t = d_021D7CDC;
        r6 = ((u32 *)((char *)a0 + 0x844))[t.v[a1]];
        MCSS_GetPosition((void *)((u32 *)((char *)a0 + 0x844))[a1], buf);
        POKETRADE_SAVE_FreeIfSet(*(u32 * *)&((struct Obj01149 *)a0)->f868);
        if (((struct Obj01149 *)a0)->f11F0 != 0)
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)r6, (void *)0x14, buf, (void *)d_021D8880, ((struct Obj01149 *)a0)->f5F4);
        else
            *(u32 *)&((struct Obj01149 *)a0)->f868 =
                (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)r6, (void *)0x12, buf, (void *)d_021D8398, ((struct Obj01149 *)a0)->f5F4);
    }
}


void POKETRADE_DEMO_MIDDLE_ResetMonSlide(void *p, int idx)
{
    u32 vec[3];
    MCSS_ResetVanishFlag((void *)(((u32 *)((char *)p + 0x844))[idx]));
    vec[0] = 0;
    vec[1] = 0xFFFE9000;
    vec[2] = 0xA000;
    MCSS_SetPosition((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
    MCSS_SetAnmStopFlag((void *)(((u32 *)((char *)p + 0x844))[idx]));
    MCSS_GetScale((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
    vec[0] = ((s32)vec[0] < 0) ? 0xFFFF0000 : 0x10000;
    vec[1] = 0x10000;
    vec[2] = 0x1000;
    MCSS_SetScale((void *)(((u32 *)((char *)p + 0x844))[idx]), vec);
}


void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22692 *)(*(char * *)&((struct Obj13882 *)w)->fC))->f98 != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((struct Obj22693 *)(*(char * *)&((struct Obj13882 *)w)->fC))->f98, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}


void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)POKETRADE_DEMO_MIDDLE_UpdateEmitterA);
}


void POKETRADE_DEMO_MIDDLE_UpdateEmitterB(void *obj, int on)
{
    s32 buf[3];
    Vec *v;
    void *w;

    if (on != 0 && obj != 0) {
        w = (void *)BUTTON_MAN_GetUserData(obj);
        if (((struct Obj22694 *)(*(char * *)&((struct Obj13883 *)w)->fC))->f9C != 0) {
            v = (Vec *)buf;
            v->x = 0;
            v->y = 0;
            v->z = 0;
            ICA_ANIME_GetTranslate(((struct Obj22695 *)(*(char * *)&((struct Obj13883 *)w)->fC))->f9C, (struct Rec12 *)v);
            BUTTON_MAN_SetEmitterPos(obj, v);
        }
    }
}


void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)POKETRADE_DEMO_MIDDLE_UpdateEmitterB);
}


void POKETRADE_DEMO_MIDDLE_StepStartCompare(u8 *p)
{
    u32 t;

    func_021D6744(p);
    FLAG(0) = 1;
    MCSS_SetAnimeIndex((void *)OBJ(0), 0);
    FLAG(1) = 1;
    MCSS_SetAnimeIndex((void *)OBJ(1), 0);
    if (POKETRADE_PROC_IsHostSide(p)) {
        t = OBJ(0);
        OBJ(0) = OBJ(1);
        OBJ(1) = t;
    }
    func_021D6738(p, 0);
    POKETRADE_PROC_SetStep(p, (int)func_021D6750);
}


void POKETRADE_DEMO_MIDDLE_StepSetup(u8 *p)
{
    POKETRADE_PROC_DeleteAllResources(p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain(p);
    ((struct Obj00001 *)p)->f9C4 = (int)CLACT_CreateUnit(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D866C, 0x9D);
    *(u16 *)(WORK + 0xBA) = HEAP;
    POKETRADE_2D_SetupSummaryBgs(p, 0);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    if (POKETRADE_PROC_IsHostSide(p)) {
        POKETRADE_3D_AddPokemonMcss(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 0);
        POKETRADE_3D_AddPokemonMcss(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 0);
        POKETRADE_3D_AddPokemonMcss(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 0);
    } else {
        POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 0);
        POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 0);
        POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 0);
    }
    MCSS_GetScale((void *)OBJ(0), (u32 *)(WORK + 0x60));
    MCSS_GetScale((void *)OBJ(1), (u32 *)(WORK + 0x6C));
    MCSS_GetScale((void *)OBJ(2), (u32 *)(WORK + 0x78));
    MCSS_GetScale((void *)OBJ(3), (u32 *)(WORK + 0x84));
    MCSS_SetVanishFlag((void *)OBJ(1));
    MCSS_SetVanishFlag((void *)OBJ(2));
    MCSS_SetVanishFlag((void *)OBJ(3));
    POKETRADE_3D_InitParticleSystems(WORK);
    POKETRADE_3D_SetupParticleSystemsLow((char *)WORK);
    POKETRADE_3D_CreateIcaStreamsForMode(WORK, 0);
    func_021D6738(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepParticleSystems);
}


void POKETRADE_DEMO_MIDDLE_StepParticleSystems(u8 *p)
{
    POKETRADE_3D_SetupParticleSystemsHigh(((struct Obj22696 *)p)->fC);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepAddUnit);
}


void POKETRADE_DEMO_MIDDLE_StepAddUnit(u8 *p)
{
    POKETRADE_3D_AddUnitAndInit(p, 3);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_UpdateScene);
}


extern void func_021D6600(void *);
extern void func_021D667C(void *);
extern void POKETRADE_3D_RemoveCurrentUnit(void *);
extern void POKETRADE_NEGO_PlaySeByKeyA(u32 key);
extern void POKETRADE_MCSS_SlideBegin(void *p, void *a1, void *a2);
extern void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern const Tbl d_021D7CEC;


/* Middle demo playback step: 3D unit swaps, MCSS slides, particles and wipes. */
void POKETRADE_DEMO_MIDDLE_UpdateScene(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7;
    Tbl t;
    Vec v8;
    int idx, idx2, idx3, idx4, a, b, b2, a2, k;
    u32 r;

    POKETRADE_NEGO_PlaySeByKeyA(FRAME);
    if (FRAME == func_021D6734(0x12D)) {
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_3D_AddUnitAndInit(p, 4);
    }
    if (FRAME == func_021D6734(0x2B6)) {
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_3D_AddUnitAndInit(p, 5);
    }
    if (FRAME == func_021D6734(1)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D6734(2)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == func_021D6734(3)) {
        func_021D667C(p);
        func_021D6600(p);
    }
    if (FRAME == func_021D6734(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x18);
    }
    if (FRAME == func_021D6734(4)) {
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == func_021D6734(0x356)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[0], 10, 0, (int)p);
    }
    if (FRAME == func_021D6734(0x65)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[1], 1, 0, (int)p);
    }
    if (FRAME == func_021D6734(0x9A)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[2], 2, 0, (int)p);
    }
    if (FRAME == func_021D6734(0x356)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[8], 2, 0, (int)p);
    }
    if (FRAME == func_021D6734(0xE)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[3], 3, 0, (int)p);
    }
    if (FRAME == func_021D6734(0x483)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[7], 3, 0, (int)p);
    }
    if (FRAME == func_021D6734(0x9A)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[4], 4, (int)POKETRADE_DEMO_MIDDLE_SetupEmitterA, (int)p);
    }
    if (FRAME == func_021D6734(0x152)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[5], 5, 0, (int)p);
    }
    if (FRAME == func_021D6734(0x2BC)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[6], 6, (int)POKETRADE_DEMO_MIDDLE_SetupEmitterB, (int)p);
    }
    if (FRAME == func_021D6734(0x47F)) {
        func_021D6600(p);
    }
    if (FRAME == func_021D6734(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, func_021D6734(0x14), 1, HEAP);
    }
    if (FRAME == func_021D6734(0x130)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, func_021D6734(0x19), 1, HEAP);
    }
    if (FRAME == func_021D6734(0x149)) {
        POKETRADE_3D_DeleteMcssSlot(p, 0);
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            POKETRADE_3D_AddPokemonMcss(p, 0, 1, POKETRADE_PROC_GetSideMon(p, 0), 0);
        } else {
            POKETRADE_3D_AddPokemonMcssPlain(p, 0, 1, POKETRADE_PROC_GetSideMon(p, 0), 0);
        }
        MCSS_GetScale((void *)OBJ(0), (u32 *)((u8 *)WORK + 0x60));
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == func_021D6734(0x14A)) {
        idx = 2;
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            idx = 1;
        }
        MCSS_ResetVanishFlag((void *)OBJ(idx));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        MCSS_SetPosition((void *)OBJ(idx), (u32 *)(&v1));
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
        SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(idx), (void *)func_021D6734(0xF), &v1, HEAP);
        MCSS_SetAnmStopFlag((void *)OBJ(idx));
        v1.x = REC(idx).x * 1.2;
        v1.y = REC(idx).y * 1.2;
        v1.z = REC(idx).z;
        MCSS_SetScale((void *)OBJ(idx), (u32 *)(&v1));
    }
    if (FRAME == func_021D6734(0x14B)) {
        idx2 = 3;
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            idx2 = 0;
        }
        MCSS_ResetVanishFlag((void *)OBJ(idx2));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        MCSS_SetPosition((void *)OBJ(idx2), (u32 *)(&v2));
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(idx2), (void *)func_021D6734(0xF), &v2, HEAP);
        MCSS_SetAnmStopFlag((void *)OBJ(idx2));
        v2.x = REC(idx2).x * 1.2;
        v2.y = REC(idx2).y * 1.2;
        v2.z = REC(idx2).z;
        MCSS_SetScale((void *)OBJ(idx2), (u32 *)(&v2));
    }
    if (FRAME == func_021D6734(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        POKETRADE_MCSS_SlideBegin((void *)SLOT0, (void *)func_021D6734(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        POKETRADE_MCSS_SlideBegin((void *)SLOT1, (void *)func_021D6734(0x1C), &v3);
    }
    if (FRAME == func_021D6734(0x170)) {
        func_020307B0((void *)SLOT0);
        SLOT0 = 0;
        func_020307B0((void *)SLOT1);
        SLOT1 = 0;
        a = 2;
        b = 3;
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            b = 0;
        }
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            a = 1;
        }
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
        SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(a), (void *)func_021D6734(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(b), (void *)func_021D6734(0x2E), &v4, HEAP);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D6734(0x1B2)) {
        idx3 = 0;
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            idx3 = 3;
        }
        func_020307B0((void *)SLOT0);
        SLOT0 = 0;
        MCSS_ResetVanishFlag((void *)OBJ(idx3));
        MCSS_SetPaletteFade((struct McssFade *)OBJ(idx3), 0, 0, 0, 0x7FFF);
        v5.x = -0x96000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        MCSS_SetPosition((void *)OBJ(idx3), (u32 *)(&v5));
        v5.x = 0x3C000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
        SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(idx3), (void *)func_021D6734(0x67), &v5, HEAP);
        v5.x = REC(idx3).x * 1.2;
        v5.y = REC(idx3).y * 1.2;
        v5.z = REC(idx3).z;
        MCSS_SetScale((void *)OBJ(idx3), (u32 *)(&v5));
    }
    if (FRAME == func_021D6734(0x1B2)) {
        idx4 = 1;
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            idx4 = 2;
        }
        func_020307B0((void *)SLOT1);
        SLOT1 = 0;
        MCSS_ResetVanishFlag((void *)OBJ(idx4));
        v6.x = 0x96000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        MCSS_SetPosition((void *)OBJ(idx4), (u32 *)(&v6));
        v6.x = -0x2D000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(idx4), (void *)func_021D6734(0x67), &v6, HEAP);
        v6.x = REC(idx4).x * 1.2;
        v6.y = REC(idx4).y * 1.2;
        v6.z = REC(idx4).z;
        MCSS_SetScale((void *)OBJ(idx4), (u32 *)(&v6));
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D6734(0x1F8)) {
        POKETRADE_MCSS_SlideBegin((void *)SLOT0, (void *)func_021D6734(0x80), (void *)(SLOT0 + 0x28));
        POKETRADE_MCSS_SlideBegin((void *)SLOT1, (void *)func_021D6734(0x80), (void *)(SLOT1 + 0x28));
    }
    if (FRAME == func_021D6734(0x27D)) {
        b2 = 1;
        a2 = 0;
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            a2 = 3;
        }
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            b2 = 2;
        }
        POKETRADE_DEMO_MIDDLE_DeleteSlide(p, 0);
        POKETRADE_DEMO_MIDDLE_DeleteSlide(p, 1);
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
        SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(a2), (void *)func_021D6734(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(b2), (void *)func_021D6734(7), &v7, HEAP);
    }
    if (FRAME == func_021D6734(0x2B5)) {
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_SetVanishFlag((void *)OBJ(1));
        MCSS_SetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(3));
    }
    t = d_021D7CEC;
    k = 3;
    if (POKETRADE_PROC_IsHostSide(p) != 0) {
        k = 0;
    }
    r = t.v[k];
    if (FRAME == func_021D6734(0x48E)) {
        if (*(u8 *)(p + 0x11EE) == 0) {
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(p, k);
            POKETRADE_DEMO_MIDDLE_CreateOfferSlide(p, k);
            MCSS_SetPaletteFade((struct McssFade *)OBJ(k), 0x10, 0x10, 0, 0x7FFF);
        } else {
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(p, k);
            MCSS_SetVanishFlag((void *)OBJ(k));
            POKETRADE_DEMO_MIDDLE_ResetMonSlide(p, r);
            POKETRADE_DEMO_MIDDLE_CreateOfferSlide(p, k);
            MCSS_SetPaletteFade((struct McssFade *)OBJ(r), 0x10, 0x10, 0, 0x7FFF);
        }
    }
    if (FRAME == func_021D6734(0x48F)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(k), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D6734(0x490)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(k), 0, 0, 0, 0x7FFF);
    }
    if (func_021D6734(0x48E) < FRAME && *(u8 *)(p + 0x11EE) != 0 && *(u32 *)(p + 0x868) != 0
        && *(u32 *)(*(u32 *)(p + 0x868) + 8) == 9) {
        MCSS_GetPosition((void *)OBJ(r), (u32 *)(&v8));
        MCSS_SetPosition((void *)OBJ(k), (u32 *)(&v8));
        MCSS_ResetVanishFlag((void *)OBJ(k));
        MCSS_SetVanishFlag((void *)OBJ(r));
        **(u32 **)(p + 0x868) = OBJ(k);
    }
    if (FRAME == func_021D6734(0x4A0)) {
        MCSS_ResetAnmStopFlag((void *)OBJ(k));
    }
    if (FRAME == func_021D6734(0x28B)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, func_021D6734(0xA), 1, HEAP);
    }
    if (FRAME == func_021D6734(0x2B8)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, func_021D6734(0x19), 1, HEAP);
    }
    if (FRAME == func_021D6734(0x380)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, func_021D6734(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D6734(0x3CA)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, func_021D6734(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D6734(0x4C1)) {
        POKETRADE_DEMO_MIDDLE_DeleteSlide(p, 0);
        POKETRADE_DEMO_MIDDLE_DeleteSlide(p, 1);
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, (int)POKETRADE_DEMO_MIDDLE_StepEndScene);
    }
    POKETRADE_MCSS_SlideUpdate((void *)SLOT0, (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)SLOT1, (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(*(u32 *)(p + 0x864)), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(*(u32 *)(p + 0x868)), (int)p);
}
