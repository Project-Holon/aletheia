/*
 * function: POKETRADE_DEMO_MIDDLE_UpdateScene
 * address:  0x021D7130
 * packet:   pkt_ov118_021D7130
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Twin of ov118 021D5BB8 and 021D4C40 (same frame-dispatch shape, other ids).
 * Levers: a separate int local per block for the spilled index (one local
 * reused gave a register); the second pair of selectors declared b2 before
 * a2 for the register order; the stack table t declared before v8.
 *
 * symbols:
 *   POKETRADE_DEMO_DOWN_PassThrough  0x021D6734  thumb  ov118
 *   POKETRADE_DEMO_DOWN_CreateUnitActor  0x021D6600  thumb  ov118
 *   POKETRADE_DEMO_DOWN_LoadUnitResources  0x021D667C  thumb  ov118
 *   POKETRADE_DEMO_MIDDLE_StepEndScene  0x021D6C78  thumb  ov118
 *   POKETRADE_DEMO_MIDDLE_DeleteSlide  0x021D6CA8  thumb  ov118
 *   POKETRADE_DEMO_MIDDLE_CreateOfferSlide  0x021D6CC4  thumb  ov118
 *   POKETRADE_DEMO_MIDDLE_ResetMonSlide  0x021D6E04  thumb  ov118
 *   POKETRADE_DEMO_MIDDLE_SetupEmitterA  0x021D6EAC  thumb  ov118
 *   POKETRADE_DEMO_MIDDLE_SetupEmitterB  0x021D6F0C  thumb  ov118
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb  ov119
 *   POKETRADE_PROC_GetSideMon  0x021D8FA4  thumb  ov119
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   MCSS_GetPosition  0x02015C30  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_020307B0  0x020307B0  arm
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_3D_AddUnitAndInit  0x021E3208  thumb  ov119
 *   POKETRADE_3D_RemoveCurrentUnit  0x021E3230  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcss  0x021E35A0  thumb  ov119
 *   POKETRADE_3D_AddPokemonMcssPlain  0x021E36C8  thumb  ov119
 *   POKETRADE_3D_DeleteMcssSlot  0x021E36D8  thumb  ov119
 *   POKETRADE_SAVE_FreeIfSet  0x021DFD24  thumb  ov119
 *   POKETRADE_MCSS_SlideCreate  0x021DFB84  thumb  ov119
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb  ov119
 *   POKETRADE_MCSS_SlideBegin  0x021DFB4C  thumb  ov119
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
 *   _dflt          0x0209B750  arm
 *   _dmul          0x0209B2E8  arm
 *   _dfix          0x0209C508  arm
 *   d_021D7CEC     0x021D7CEC  data a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;

typedef struct {
    s32 x, y, z;
} Vec;

typedef struct {
    u32 v[4];
} Tbl;

extern int POKETRADE_DEMO_DOWN_PassThrough(int);
extern void POKETRADE_DEMO_DOWN_CreateUnitActor(void *);
extern void POKETRADE_DEMO_DOWN_LoadUnitResources(void *);
extern void POKETRADE_DEMO_MIDDLE_StepEndScene(void *);
extern void POKETRADE_DEMO_MIDDLE_DeleteSlide(void *p, int a1);
extern void POKETRADE_DEMO_MIDDLE_CreateOfferSlide(void *a0, int a1);
extern void POKETRADE_DEMO_MIDDLE_ResetMonSlide(void *p, int idx);
extern void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *);
extern void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *);
extern int POKETRADE_PROC_IsHostSide(void *);
extern void *POKETRADE_PROC_GetSideMon(void *, int);
struct McssFade;
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void MCSS_SetVanishFlag(void *p);
extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern void MCSS_SetAnmStopFlag(void *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_GetScale(void *p, u32 *out);
extern void MCSS_SetScale(void *p, u32 *src);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020307B0(void *p);
extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *, int);
extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *, int);
extern void POKETRADE_3D_AddUnitAndInit(void *, int);
extern void POKETRADE_3D_RemoveCurrentUnit(void *);
extern void POKETRADE_3D_AddPokemonMcss(void *, int, int, void *, int);
extern void POKETRADE_3D_AddPokemonMcssPlain(void *, int, int, void *, int);
extern void POKETRADE_3D_DeleteMcssSlot(void *, int);
extern void POKETRADE_SAVE_FreeIfSet(u32 *p);
extern void *POKETRADE_MCSS_SlideCreate(void *a0, void *a1, void *a2, u32 heapId);
extern void POKETRADE_NEGO_PlaySeByKeyA(u32 key);
extern void POKETRADE_MCSS_SlideBegin(void *p, void *a1, void *a2);
extern void POKETRADE_MCSS_SlideUpdate(void *p, int a1);
extern void POKETRADE_PROC_SetStep(void *, int);
extern const Tbl d_021D7CEC;

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define WORK (*(u32 **)(p + 0xc))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))
#define REC(i) (((Vec *)((u8 *)WORK + 0x60))[i])

void POKETRADE_DEMO_MIDDLE_UpdateScene(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7;
    Tbl t;
    Vec v8;
    int idx, idx2, idx3, idx4, a, b, b2, a2, k;
    u32 r;

    POKETRADE_NEGO_PlaySeByKeyA(FRAME);
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x12D)) {
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_3D_AddUnitAndInit(p, 4);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x2B6)) {
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_3D_AddUnitAndInit(p, 5);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(1)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(2)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(0), 0x10, 0x10, 0, 0xFFFF);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(3)) {
        POKETRADE_DEMO_DOWN_LoadUnitResources(p);
        POKETRADE_DEMO_DOWN_CreateUnitActor(p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(4)) {
        POKETRADE_2D_ScheduleMainPlaneVisible(p, 0x11);
        POKETRADE_2D_ScheduleSubPlaneVisible(p, 0x18);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(4)) {
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[0], 10, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x65)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[1], 1, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[2], 2, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x356)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[8], 2, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0xE)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[3], 3, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x483)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[7], 3, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x9A)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[4], 4, (int)POKETRADE_DEMO_MIDDLE_SetupEmitterA, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x152)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[5], 5, 0, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x2BC)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[6], 6, (int)POKETRADE_DEMO_MIDDLE_SetupEmitterB, (int)p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x47F)) {
        POKETRADE_DEMO_DOWN_CreateUnitActor(p);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x14), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x130)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x149)) {
        POKETRADE_3D_DeleteMcssSlot(p, 0);
        if (POKETRADE_PROC_IsHostSide(p) != 0) {
            POKETRADE_3D_AddPokemonMcss(p, 0, 1, POKETRADE_PROC_GetSideMon(p, 0), 0);
        } else {
            POKETRADE_3D_AddPokemonMcssPlain(p, 0, 1, POKETRADE_PROC_GetSideMon(p, 0), 0);
        }
        MCSS_GetScale((void *)OBJ(0), (u32 *)((u8 *)WORK + 0x60));
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x14A)) {
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
        SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(idx), (void *)POKETRADE_DEMO_DOWN_PassThrough(0xF), &v1, HEAP);
        MCSS_SetAnmStopFlag((void *)OBJ(idx));
        v1.x = REC(idx).x * 1.2;
        v1.y = REC(idx).y * 1.2;
        v1.z = REC(idx).z;
        MCSS_SetScale((void *)OBJ(idx), (u32 *)(&v1));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x14B)) {
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
        SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(idx2), (void *)POKETRADE_DEMO_DOWN_PassThrough(0xF), &v2, HEAP);
        MCSS_SetAnmStopFlag((void *)OBJ(idx2));
        v2.x = REC(idx2).x * 1.2;
        v2.y = REC(idx2).y * 1.2;
        v2.z = REC(idx2).z;
        MCSS_SetScale((void *)OBJ(idx2), (u32 *)(&v2));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        POKETRADE_MCSS_SlideBegin((void *)SLOT0, (void *)POKETRADE_DEMO_DOWN_PassThrough(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        POKETRADE_MCSS_SlideBegin((void *)SLOT1, (void *)POKETRADE_DEMO_DOWN_PassThrough(0x1C), &v3);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x170)) {
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
        SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(a), (void *)POKETRADE_DEMO_DOWN_PassThrough(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(b), (void *)POKETRADE_DEMO_DOWN_PassThrough(0x2E), &v4, HEAP);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x1B2)) {
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
        SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(idx3), (void *)POKETRADE_DEMO_DOWN_PassThrough(0x67), &v5, HEAP);
        v5.x = REC(idx3).x * 1.2;
        v5.y = REC(idx3).y * 1.2;
        v5.z = REC(idx3).z;
        MCSS_SetScale((void *)OBJ(idx3), (u32 *)(&v5));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x1B2)) {
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
        SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(idx4), (void *)POKETRADE_DEMO_DOWN_PassThrough(0x67), &v6, HEAP);
        v6.x = REC(idx4).x * 1.2;
        v6.y = REC(idx4).y * 1.2;
        v6.z = REC(idx4).z;
        MCSS_SetScale((void *)OBJ(idx4), (u32 *)(&v6));
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x1F8)) {
        POKETRADE_MCSS_SlideBegin((void *)SLOT0, (void *)POKETRADE_DEMO_DOWN_PassThrough(0x80), (void *)(SLOT0 + 0x28));
        POKETRADE_MCSS_SlideBegin((void *)SLOT1, (void *)POKETRADE_DEMO_DOWN_PassThrough(0x80), (void *)(SLOT1 + 0x28));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x27D)) {
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
        SLOT0 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(a2), (void *)POKETRADE_DEMO_DOWN_PassThrough(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet((u32 *)SLOT1);
        SLOT1 = (u32)POKETRADE_MCSS_SlideCreate((void *)OBJ(b2), (void *)POKETRADE_DEMO_DOWN_PassThrough(7), &v7, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x2B5)) {
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
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x48E)) {
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
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x48F)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(k), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x490)) {
        MCSS_SetPaletteFade((struct McssFade *)OBJ(k), 0, 0, 0, 0x7FFF);
    }
    if (POKETRADE_DEMO_DOWN_PassThrough(0x48E) < FRAME && *(u8 *)(p + 0x11EE) != 0 && *(u32 *)(p + 0x868) != 0
        && *(u32 *)(*(u32 *)(p + 0x868) + 8) == 9) {
        MCSS_GetPosition((void *)OBJ(r), (u32 *)(&v8));
        MCSS_SetPosition((void *)OBJ(k), (u32 *)(&v8));
        MCSS_ResetVanishFlag((void *)OBJ(k));
        MCSS_SetVanishFlag((void *)OBJ(r));
        **(u32 **)(p + 0x868) = OBJ(k);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x4A0)) {
        MCSS_ResetAnmStopFlag((void *)OBJ(k));
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x28B)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0xA), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x2B8)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x19), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x380)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x1E), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x3CA)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, POKETRADE_DEMO_DOWN_PassThrough(0x1E), 1, HEAP);
    }
    if (FRAME == POKETRADE_DEMO_DOWN_PassThrough(0x4C1)) {
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
