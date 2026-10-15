/*
 * file:     pokemontrade_ircdemo.c
 * unit:     yes
 * function: func_021D4664, func_021D4820, func_021D48F0, func_021D49C4, func_021D49F4, func_021D4A48, func_021D4B88, func_021D4BF4, POKETRADE_IRCDEMO_UpdateScene
 * address:  0x021D4664
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D4240  0x021D4240  thumb  ov117
 *   func_021D434C  0x021D434C  thumb  ov117
 *   func_021D43C8  0x021D43C8  thumb  ov117
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   func_021D4480  0x021D4480  thumb  ov117
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_2D_DeleteAllOfferIconActors  0x021E64B8  thumb  ov119
 *   POKETRADE_2D_DeleteAllBoxIcons  0x021E4888  thumb  ov119
 *   POKETRADE_SAVE_DeleteOfferListWindows  0x021E2680  thumb  ov119
 *   func_021D4484  0x021D4484  thumb  ov117
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
 *   d_021D5220     0x021D5220  data
 *   d_021D53D0     0x021D53D0  data
 *   d_021D5600     0x021D5600  data
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
 *   func_021D4434  0x021D4434  thumb  ov117
 *   POKETRADE_3D_ExitParticleManager  0x021E3034  thumb  ov119
 *   POKETRADE_3D_FreeParticleResources  0x021E2F2C  thumb  ov119
 *   POKETRADE_SAVE_ResetClactAndBeginEvent  0x021DFDA0  thumb  ov119
 *   MCSS_SetAlpha  0x02015FBC  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   d_021D5200     0x021D5200  data
 *   d_021D52F8     0x021D52F8  data
 *   func_021D4490  0x021D4490  thumb  ov117
 *   MCSS_SetAnimeIndex  0x02016028  thumb
 *   func_021D449C  0x021D449C  thumb  ov117
 *   d_021D51DC     0x021D51DC  data
 *   POKETRADE_PROC_DeleteAllResources  0x021DC720  thumb  ov119
 *   CLACT_ExitSystem  0x0204A5AC  arm
 *   POKETRADE_2D_InitClactSystemMain  0x021E3E40  thumb  ov119
 *   CLACT_CreateUnit  0x0204B100  arm
 *   func_02030734  0x02030734  arm
 *   POKETRADE_2D_SetupSummaryBgs  0x021E5284  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb  ov119
 *   MCSS_GetScale  0x02015C94  thumb
 *   POKETRADE_3D_InitTradeParticleSet  0x021E3070  thumb  ov119
 *   POKETRADE_3D_CreateIcaStreamsEnding  0x021E2EFC  thumb  ov119
 *   POKETRADE_IRCDEMO_UpdateScene  0x021D4CE8  thumb  ov117
 *   d_021D55CC     0x021D55CC  data
 */
#include "../../matched/include/Obj05323.h"
#include "../../matched/include/Obj00982.h"
#include "../../matched/include/Obj01722.h"
#include "../../matched/include/Obj22645.h"
#include "../../matched/include/Obj00342.h"
#include "../../matched/include/Obj06419.h"
#include "../../matched/include/Obj02829.h"

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define WORK (*(u8 **)(p + 0xc))
struct WordSet;
struct MsgBank;
struct McssFade;
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

extern void func_021D4240(s8 *fade);
extern void POKETRADE_MCSS_SlideUpdate(void *p, int a1);
extern int func_021D4480(int);
extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *p, int a);
extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *p, int a);
extern void POKETRADE_2D_DeleteAllOfferIconActors(void *p);
extern void POKETRADE_2D_DeleteAllBoxIcons(char *p);
extern void POKETRADE_SAVE_DeleteOfferListWindows(char *p);
extern void func_021D4484(u8 *p, u32 v);
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
extern void func_021D4434(void *);
extern void POKETRADE_3D_ExitParticleManager(u32 *p, int a1);
extern void POKETRADE_3D_FreeParticleResources(void *);
extern void POKETRADE_SAVE_ResetClactAndBeginEvent(void *p);
extern void MCSS_SetAlpha(char *p, int v);
extern void MCSS_SetScale(void *p, u32 *src);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void func_021D4490(u8 *p);
extern void MCSS_SetAnimeIndex(void *a, u32 flag);
extern void func_021D449C(u8 *p);
extern void POKETRADE_PROC_DeleteAllResources(char *p);
extern void CLACT_ExitSystem(void);
extern void POKETRADE_2D_InitClactSystemMain(char *p);
extern struct Bank *CLACT_CreateUnit(int count, u8 flag, u32 heapId);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void POKETRADE_2D_SetupSummaryBgs(char *p, int mode);
extern void POKETRADE_3D_AddUnitAndInit(void *p, int a);
extern void MCSS_GetScale(void *p, u32 *out);
extern void POKETRADE_3D_InitTradeParticleSet(void *w);
extern void POKETRADE_3D_CreateIcaStreamsEnding(char *p);
extern void POKETRADE_IRCDEMO_UpdateScene(u8 *p);
void func_021D4664(u8 *p);
void func_021D4820(u8 *p);
void func_021D48F0(u8 *p);
void func_021D49C4(void *p);
void func_021D49F4(void *obj, void *p);
void func_021D4A48(u8 *p, int idx);
void func_021D4B88(u8 *p);
void func_021D4BF4(u8 *p);
extern const u8 d_021D5220[];
extern const u8 d_021D53D0[];
extern u8 d_021D5600[];
extern const Quad d_021D5200;
extern const u8 d_021D52F8[];
extern const Vec d_021D51DC;
extern const char d_021D55CC[];


void func_021D4664(u8 *p)
{
    void *mon;
    u32 a;
    u32 b;
    Vec v1;
    Vec v2;
    u32 buf;

    func_021D4240(*(s8 * *)&((struct Obj05323 *)p)->f818);
    POKETRADE_MCSS_SlideUpdate((void *)(((struct Obj05323 *)p)->f85C), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(((struct Obj05323 *)p)->f860), (int)p);
    if (FRAME > func_021D4480(0x2A)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0);
        POKETRADE_2D_DeleteAllOfferIconActors(p);
        POKETRADE_2D_DeleteAllBoxIcons((char *)p);
        POKETRADE_SAVE_DeleteOfferListWindows((char *)p);
        func_021D4484(p, 0);
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
        if (((struct Obj05323 *)p)->f11ED == 0) {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v1));
            POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
            if (((struct Obj05323 *)p)->f11EF != 0) {
                SLOT0 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x14, &v1, d_021D5600, HEAP);
            } else {
                SLOT0 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x12, &v1, (void *)d_021D5220, HEAP);
            }
            POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)), 1);
            MCSS_SetAnmStopFlag((void *)OBJ(2));
            MCSS_SetVanishFlag((void *)OBJ(2));
        } else {
            MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v2));
            POKETRADE_SAVE_FreeIfSet((u32 *)SLOT0);
            if (((struct Obj05323 *)p)->f11EF != 0) {
                SLOT0 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x14, &v2, d_021D5600, HEAP);
            } else {
                SLOT0 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)OBJ(0), (void *)0x28, &v2, (void *)d_021D53D0, HEAP);
            }
        }
        POKETRADE_PROC_SetStep(p, (int)func_021D48F0);
    }
}


void func_021D4820(u8 *p)
{
    GFL_NET_RestartWithDefaultTimeout(0, ((struct Obj00982 *)p)->f5F4);
    if (((struct Obj00982 *)p)->f118C == 6) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x98, (void *)(((struct Obj00982 *)p)->f73C));
    } else if (((struct Obj00982 *)p)->f118C == 8) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x9B, (void *)(((struct Obj00982 *)p)->f73C));
    } else if (((struct Obj00982 *)p)->f11ED != 0) {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x82, (void *)(((struct Obj00982 *)p)->f73C));
    } else {
        MSGDATA_ReadString((struct MsgBank *)(((struct Obj00982 *)p)->f720), 0x81, (void *)(((struct Obj00982 *)p)->f73C));
    }
    func_0201EEF4(((struct Obj00982 *)p)->f724, 0, POKETRADE_PROC_GetSideMon(p, POKETRADE_PROC_IsHostSide(p)));
    func_0201F02C((struct WordSet *)(*(u32 *)&((struct Obj00982 *)p)->f724), 1, (void *)(((struct Obj00982 *)p)->f834));
    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00982 *)p)->f724), (void *)(((struct Obj00982 *)p)->f738), (void *)(((struct Obj00982 *)p)->f73C));
    func_02041300(4, 0, 0, 0, 0x20, 0x18, 0x11);
    POKETRADE_SAVE_OpenMessageWindowAtPos(p, 1, 0);
    POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x14);
    *(volatile u16 *)0x04001050 = 0;
}


void func_021D48F0(u8 *p)
{
    Vec v;

    if (FRAME == 10) {
        func_021D4820(p);
    }
    if (((struct Obj00982 *)p)->f11ED == 0 && FRAME == 6) {
        MCSS_GetPosition((void *)OBJ(0), (u32 *)(&v));
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        MCSS_ResetVanishFlag((void *)OBJ(2));
        MCSS_SetVanishFlag((void *)OBJ(0));
        MCSS_ResetAnmStopFlag((void *)OBJ(2));
        *(u32 *)SLOT0 = OBJ(2);
    }
    if (FRAME > 0xC8 && POKETRADE_SAVE_IsMessagePrintDone((char *)p) != 0) {
        POKETRADE_SAVE_CloseMessageWindowClear((char *)p);
        if (((struct Obj00982 *)p)->f11ED == 0) {
            POKETRADE_3D_DeleteMcssSlot(p, 0);
            OBJ(0) = OBJ(2);
            OBJ(2) = 0;
        }
        if (SLOT0 != 0) {
            func_020307B0((void *)SLOT0);
            SLOT0 = 0;
        }
        POKETRADE_PROC_SetStep(p, (int)func_021D4BF4);
    }
    POKETRADE_MCSS_SlideUpdate((void *)SLOT0, (int)p);
}


void func_021D49C4(void *p)
{
    func_021D4434(p);
    POKETRADE_3D_ExitParticleManager(((struct Obj01722 *)p)->fC, 6);
    POKETRADE_3D_FreeParticleResources(((struct Obj01722 *)p)->fC);
    func_020307B0(((struct Obj01722 *)p)->fC);
    ((struct Obj01722 *)p)->fC = 0;
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_SAVE_ResetClactAndBeginEvent);
}


void func_021D49F4(void *obj, void *p)
{
    Vec v;
    MCSS_SetAlpha(obj, 0x1f);
    MCSS_ResetVanishFlag(obj);
    v.x = 0;
    v.y = -0x17000;
    v.z = 0xa000;
    MCSS_SetPosition(obj, (u32 *)(&v));
    MCSS_SetAnmStopFlag(obj);
    MCSS_SetScale(obj, (u32 *)((char *)((struct Obj22645 *)p)->fC + 0x48));
    MCSS_SetPaletteFade(obj, 0x10, 0x10, 0, 0x7fff);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D4A48(u8 *p, int idx)
{
    void *x;
    u32 buf[3];

    x = POKETRADE_PROC_GetSideMon(p, 1 - POKETRADE_PROC_IsHostSide(p));
    POKE_TOOL_GetPartyValue(x, 7, 0);
    if (POKE_TOOL_GetPartyValue(x, 0x4c, 0) == 0) {
        PM_VOICE_Play(POKE_TOOL_GetPartyValue(x, 0xab, 0), POKE_TOOL_GetPartyValue(x, 0x6f, 0), 0x40, 0, 0, 0, 0, 0);
    }
    if (((struct Obj00342 *)p)->f11EE == 0) {
        MCSS_GetPosition((void *)(((u32 *)(p + 0x844))[idx]), buf);
        POKETRADE_SAVE_FreeIfSet((u32 *)(*(u32 *)&((struct Obj00342 *)p)->f868));
        if (((struct Obj00342 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x14, buf, d_021D5600, ((struct Obj00342 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)(((u32 *)(p + 0x844))[idx]), (void *)0x28, buf, (void *)d_021D53D0, ((struct Obj00342 *)p)->f5F4);
        }
    } else {
        Quad t = d_021D5200;
        u32 obj = ((u32 *)(p + 0x844))[t.v[idx]];
        MCSS_GetPosition((void *)(((u32 *)(p + 0x844))[idx]), buf);
        POKETRADE_SAVE_FreeIfSet((u32 *)(*(u32 *)&((struct Obj00342 *)p)->f868));
        if (((struct Obj00342 *)p)->f11F0 != 0) {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)obj, (void *)0x14, buf, d_021D5600, ((struct Obj00342 *)p)->f5F4);
        } else {
            *(u32 *)&((struct Obj00342 *)p)->f868 = (u32)POKETRADE_MCSS_SlideCreateWithOffsets((void *)obj, (void *)0x12, buf, (void *)d_021D52F8, ((struct Obj00342 *)p)->f5F4);
        }
    }
}


void func_021D4B88(u8 *p)
{
    func_021D4490(p);
    ((struct Obj06419 *)p)->f854 = 1;
    MCSS_SetAnimeIndex((void *)(((struct Obj06419 *)p)->f844), 0);
    MCSS_SetAnmStopFlag((void *)(((struct Obj06419 *)p)->f844));
    if (((struct Obj06419 *)p)->f118C == 4) {
        Vec v = d_021D51DC;
        MCSS_SetPosition((void *)(((struct Obj06419 *)p)->f844), (u32 *)(&v));
    }
    func_021D4484(p, 0);
    POKETRADE_PROC_SetStep(p, (int)func_021D449C);
}


void func_021D4BF4(u8 *p)
{
    POKETRADE_PROC_DeleteAllResources((char *)p);
    CLACT_ExitSystem();
    POKETRADE_2D_InitClactSystemMain((char *)p);
    ((struct Obj02829 *)p)->f9C4 = (int)CLACT_CreateUnit(3, 0, HEAP);
    WORK = func_02030734(HEAP, 0xBC, 1, d_021D55CC, 0x65);
    *(u16 *)(WORK + 0xBA) = HEAP;
    POKETRADE_2D_SetupSummaryBgs((char *)p, 1);
    *(volatile u16 *)0x04001050 = 0;
    *(volatile u16 *)0x04000050 = 0;
    POKETRADE_3D_AddUnitAndInit(p, 2);
    POKETRADE_3D_AddPokemonMcssPlain(p, 1, 0, POKETRADE_PROC_GetSideMon(p, 1), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 2, 0, POKETRADE_PROC_GetSideMon(p, 0), 1);
    POKETRADE_3D_AddPokemonMcssPlain(p, 3, 1, POKETRADE_PROC_GetSideMon(p, 1), 1);
    MCSS_GetScale((void *)OBJ(3), (u32 *)(WORK + 0x54));
    MCSS_SetVanishFlag((void *)OBJ(1));
    MCSS_SetVanishFlag((void *)OBJ(2));
    MCSS_SetVanishFlag((void *)OBJ(3));
    POKETRADE_3D_InitTradeParticleSet(WORK);
    POKETRADE_3D_CreateIcaStreamsEnding((char *)WORK);
    func_021D4484(p, 0);
    POKETRADE_PROC_SetStep(p, (int)POKETRADE_IRCDEMO_UpdateScene);
}


extern void func_021D434C(void *);
extern void func_021D43C8(void *);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId);
extern void POKETRADE_NEGO_PlaySeByKeyB(int);
extern void POKETRADE_3D_RemoveCurrentUnit(void *);


/* IRC demo playback step: palette fades, particle bursts, wipes and MCSS slides. */
void POKETRADE_IRCDEMO_UpdateScene(u8 *p)
{
    Vec v;
    Vec v2;
    Vec v3;
    Vec v4;

    if (FRAME == func_021D4480(1)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(2)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(3)) {
        func_021D43C8(p);
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x18);
    }
    if (FRAME == func_021D4480(4)) {
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == func_021D4480(-1)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[0], 0, 0, (int)p);
    }
    if (FRAME == func_021D4480(0x15E)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[1], 0, 0, (int)p);
    }
    if (FRAME == func_021D4480(0xC8)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[2], 1, 0, (int)p);
    }
    if (FRAME == func_021D4480(0x14)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[3], 2, 0, (int)p);
    }
    if (FRAME == func_021D4480(0x258)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[4], 2, 0, (int)p);
    }
    if (FRAME == func_021D4480(-1)) {
        PARTICLE_StartEffectWithCallback((int *)((u32 *)WORK)[5], 3, 0, (int)p);
    }
    if (FRAME == func_021D4480(0x256)) {
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(0x82)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, func_021D4480(0x14), 1, HEAP);
    }
    if (FRAME == func_021D4480(0xB4)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, func_021D4480(0x19), 1, HEAP);
    }
    if (FRAME == func_021D4480(0xFA)) {
        MCSS_ResetVanishFlag((void *)OBJ(2));
        v.x = -0x32000;
        v.y = -0x1F4000;
        v.z = 0xA000;
        MCSS_SetPosition((void *)OBJ(2), (u32 *)(&v));
        v.x = -0x32000;
        v.y = 0x12C000;
        v.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)(((struct Obj00342 *)p)->f85C));
        ((struct Obj00342 *)p)->f85C = (unsigned int)POKETRADE_MCSS_SlideCreate((void *)OBJ(2), (void *)func_021D4480(0x96), &v, HEAP);
        MCSS_GetScale((void *)OBJ(2), (u32 *)(&v));
        v.x = v.x * 2;
        v.y = v.y * 2;
        MCSS_SetScale((void *)OBJ(2), (u32 *)(&v));
    }
    if (FRAME == func_021D4480(0xFB)) {
        MCSS_ResetVanishFlag((void *)OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x12C000;
        v2.z = -0xA000;
        MCSS_SetPosition((void *)OBJ(3), (u32 *)(&v2));
        v2.x = 0x3C000;
        v2.y = -0x172000;
        v2.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)(((struct Obj00342 *)p)->f860));
        ((struct Obj00342 *)p)->f860 = (unsigned int)POKETRADE_MCSS_SlideCreate((void *)OBJ(3), (void *)func_021D4480(0x96), &v2, HEAP);
        MCSS_SetScale((void *)OBJ(3), (u32 *)((u8 *)WORK + 0x54));
        MCSS_GetScale((void *)OBJ(3), (u32 *)(&v2));
        *(s32 *)((u8 *)WORK + 0x48) = v2.x;
        *(s32 *)((u8 *)WORK + 0x4C) = v2.y;
        *(s32 *)((u8 *)WORK + 0x50) = v2.z;
        MCSS_GetScale((void *)OBJ(3), (u32 *)(&v3));
    }
    if (FRAME == func_021D4480(0xFC)) {
    }
    if (FRAME == func_021D4480(0x267)) {
        if (((struct Obj00342 *)p)->f11EE == 0) {
            func_021D49F4((void *)OBJ(3), p);
        } else {
            func_021D49F4((void *)OBJ(3), p);
            MCSS_SetVanishFlag((void *)OBJ(3));
            func_021D49F4((void *)OBJ(1), p);
        }
        func_021D4A48(p, 3);
    }
    if (FRAME == func_021D4480(0x268)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(3), 8, 8, 0, 0x7FFF);
        MCSS_SetPaletteFade((struct McssFade *)OBJ(1), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x269)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(3), 0, 0, 0, 0x7FFF);
        MCSS_SetPaletteFade((struct McssFade *)OBJ(1), 0, 0, 0, 0x7FFF);
    }
    if (func_021D4480(0x267) < FRAME && ((struct Obj00342 *)p)->f11EE != 0 && *(u32 *)&((struct Obj00342 *)p)->f868 != 0
        && *(u32 *)(*(u32 *)&((struct Obj00342 *)p)->f868 + 8) == 9) {
        MCSS_GetPosition((void *)OBJ(1), (u32 *)(&v4));
        MCSS_SetPosition((void *)OBJ(3), (u32 *)(&v4));
        MCSS_ResetVanishFlag((void *)OBJ(3));
        MCSS_SetVanishFlag((void *)OBJ(1));
        **(u32 * *)&((struct Obj00342 *)p)->f868 = OBJ(3);
    }
    if (FRAME == func_021D4480(0x279)) {
        MCSS_ResetAnmStopFlag((void *)OBJ(3));
    }
    POKETRADE_NEGO_PlaySeByKeyB(FRAME);
    if (FRAME == func_021D4480(0x199)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, func_021D4480(0xA), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x1A4)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, func_021D4480(0x19), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x293)) {
        func_020307B0((void *)(((struct Obj00342 *)p)->f85C));
        ((struct Obj00342 *)p)->f85C = 0;
        func_020307B0((void *)(((struct Obj00342 *)p)->f860));
        ((struct Obj00342 *)p)->f860 = 0;
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, (int)func_021D49C4);
    }
    POKETRADE_MCSS_SlideUpdate((void *)(((struct Obj00342 *)p)->f85C), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(((struct Obj00342 *)p)->f860), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(((struct Obj00342 *)p)->f864), (int)p);
    POKETRADE_MCSS_SlideUpdate((void *)(*(u32 *)&((struct Obj00342 *)p)->f868), (int)p);
}
