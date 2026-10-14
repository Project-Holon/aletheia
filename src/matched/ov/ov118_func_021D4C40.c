/*
 * function: func_021D4C40
 * address:  0x021D4C40
 * packet:   pkt_ov118_021D4C40
 * region:   ov118
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4480  0x021D4480  thumb  ov118
 *   func_021D434C  0x021D434C  thumb  ov118
 *   func_021D43C8  0x021D43C8  thumb  ov118
 *   func_021D49C4  0x021D49C4  thumb  ov118
 *   func_021D49F4  0x021D49F4  thumb  ov118
 *   func_021D4A48  0x021D4A48  thumb  ov118
 *   MCSS_SetPaletteFade  0x02015F50  thumb
 *   MCSS_SetVanishFlag  0x02015EA0  thumb
 *   MCSS_ResetVanishFlag  0x02015EB0  thumb
 *   MCSS_ResetAnmStopFlag  0x02015E4C  thumb
 *   MCSS_GetPosition  0x02015C30  thumb
 *   MCSS_SetPosition  0x02015C48  thumb
 *   MCSS_GetScale  0x02015C94  thumb
 *   MCSS_SetScale  0x02015CAC  thumb
 *   PARTICLE_StartEffectWithCallback  0x020515CC  arm
 *   WIPE_SYS_Start  0x0202208C  thumb
 *   func_020307B0  0x020307B0  arm
 *   POKETRADE_2D_ScheduleMainPlaneVisible  0x021E71F0  thumb  ov119
 *   POKETRADE_2D_ScheduleSubPlaneVisible  0x021E7208  thumb  ov119
 *   POKETRADE_SAVE_FreeIfSet  0x021DFD24  thumb  ov119
 *   POKETRADE_MCSS_SlideCreate  0x021DFB84  thumb  ov119
 *   POKETRADE_NEGO_PlaySeByKeyA  0x021DFA60  thumb  ov119
 *   POKETRADE_MCSS_SlideBegin  0x021DFB4C  thumb  ov119
 *   func_021D4A34  0x021D4A34  thumb  ov118
 *   func_021D4A94  0x021D4A94  thumb  ov118
 *   _dflt          0x0209B750  arm
 *   _dmul          0x0209B2E8  arm
 *   _dfix          0x0209C508  arm
 *   MCSS_SetAnmStopFlag  0x02015E04  thumb
 *   POKETRADE_MCSS_SlideUpdate  0x021DFC68  thumb  ov119
 *   POKETRADE_3D_RemoveCurrentUnit  0x021E3230  thumb  ov119
 *   POKETRADE_PROC_SetStep  0x021D8E84  thumb  ov119
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

extern int func_021D4480(int);
extern void func_021D434C(void *);
extern void func_021D43C8(void *);
extern void func_021D49C4(void *);
extern void func_021D49F4(void *obj, int on);
extern void func_021D4A48(void *, int);
extern void MCSS_SetPaletteFade(u32, u32, u32, s32, u32);
extern void MCSS_SetVanishFlag(u32);
extern void MCSS_ResetVanishFlag(u32);
extern void MCSS_ResetAnmStopFlag(void *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(u32, Vec *);
extern void MCSS_GetScale(u32, Vec *);
extern void MCSS_SetScale(u32, void *);
extern int PARTICLE_StartEffectWithCallback(u32, int, void *, void *);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void func_020307B0(u32);
extern void POKETRADE_2D_ScheduleMainPlaneVisible(void *, int);
extern void POKETRADE_2D_ScheduleSubPlaneVisible(void *, int);
extern void POKETRADE_SAVE_FreeIfSet(u32);
extern u32 POKETRADE_MCSS_SlideCreate(u32, int, Vec *, u32);
extern void POKETRADE_NEGO_PlaySeByKeyA(u32 key);
extern void POKETRADE_MCSS_SlideBegin(u32, int, void *);
extern void func_021D4A34(void *p);
extern void func_021D4A94(void *p);
extern void POKETRADE_MCSS_SlideUpdate(u32, void *);
extern void POKETRADE_3D_RemoveCurrentUnit(void *);
extern void POKETRADE_PROC_SetStep(void *, int);

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define WORK (*(u32 **)(p + 0xc))
#define SLOT0 (*(u32 *)(p + 0x85C))
#define SLOT1 (*(u32 *)(p + 0x860))

void func_021D4C40(u8 *p)
{
    Vec v1, v2, v3, v4, v5, v6, v7, v8;

    POKETRADE_NEGO_PlaySeByKeyA(FRAME);
    if (FRAME == func_021D4480(1)) {
        MCSS_SetPaletteFade(OBJ(0), 8, 8, 0, 0xFFFF);
    }
    if (FRAME == func_021D4480(2)) {
        MCSS_SetPaletteFade(OBJ(0), 0x10, 0x10, 0, 0xFFFF);
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
        MCSS_SetVanishFlag(OBJ(0));
    }
    if (FRAME == func_021D4480(0x356)) {
        PARTICLE_StartEffectWithCallback(WORK[0], 10, 0, p);
    }
    if (FRAME == func_021D4480(0x65)) {
        PARTICLE_StartEffectWithCallback(WORK[1], 1, 0, p);
    }
    if (FRAME == func_021D4480(0x9A)) {
        PARTICLE_StartEffectWithCallback(WORK[2], 2, 0, p);
    }
    if (FRAME == func_021D4480(0x356)) {
        PARTICLE_StartEffectWithCallback(WORK[8], 2, 0, p);
    }
    if (FRAME == func_021D4480(0xE)) {
        PARTICLE_StartEffectWithCallback(WORK[3], 3, 0, p);
    }
    if (FRAME == func_021D4480(0x483)) {
        PARTICLE_StartEffectWithCallback(WORK[7], 3, 0, p);
    }
    if (FRAME == func_021D4480(0x9A)) {
        PARTICLE_StartEffectWithCallback(WORK[4], 4, func_021D4A34, p);
    }
    if (FRAME == func_021D4480(0x152)) {
        PARTICLE_StartEffectWithCallback(WORK[5], 5, 0, p);
    }
    if (FRAME == func_021D4480(0x2BC)) {
        PARTICLE_StartEffectWithCallback(WORK[6], 6, func_021D4A94, p);
    }
    if (FRAME == func_021D4480(0x47F)) {
        func_021D434C(p);
    }
    if (FRAME == func_021D4480(0x10A)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, func_021D4480(0x14), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x12D) - 2) {
        if (SLOT0 != 0) {
            func_020307B0(SLOT0);
            SLOT0 = 0;
        }
        if (SLOT1 != 0) {
            func_020307B0(SLOT1);
            SLOT1 = 0;
        }
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, (int)func_021D49C4);
    }
    if (FRAME == func_021D4480(0x14A)) {
        MCSS_ResetVanishFlag(OBJ(2));
        v1.x = -0x32000;
        v1.y = -0x96000;
        v1.z = 0xA000;
        MCSS_SetPosition(OBJ(2), &v1);
        v1.x = -0x32000;
        v1.y = -0x37000;
        v1.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(2), func_021D4480(0xF), &v1, HEAP);
        MCSS_SetAnmStopFlag(OBJ(2));
        MCSS_GetScale(OBJ(2), &v1);
        v1.x *= 1.2;
        v1.y *= 1.2;
        MCSS_SetScale(OBJ(2), &v1);
    }
    if (FRAME == func_021D4480(0x14B)) {
        MCSS_ResetVanishFlag(OBJ(3));
        v2.x = 0x3C000;
        v2.y = 0x50000;
        v2.z = -0xA000;
        MCSS_SetPosition(OBJ(3), &v2);
        v2.x = 0x3C000;
        v2.y = 0x5000;
        v2.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(3), func_021D4480(0xF), &v2, HEAP);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_GetScale(OBJ(3), &v2);
        v2.x *= 1.2;
        v2.y *= 1.2;
        MCSS_SetScale(OBJ(3), &v2);
    }
    if (FRAME == func_021D4480(0x154)) {
        v3.x = -0x32000;
        v3.y = -0x37000;
        v3.z = 0xA000;
        POKETRADE_MCSS_SlideBegin(SLOT0, func_021D4480(0x1C), &v3);
        v3.x = 0x3C000;
        v3.y = 0x5000;
        v3.z = -0xA000;
        POKETRADE_MCSS_SlideBegin(SLOT1, func_021D4480(0x1C), &v3);
    }
    if (FRAME == func_021D4480(0x170)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        v4.x = -0x96000;
        v4.y = -0x37000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(2), func_021D4480(0x2E), &v4, HEAP);
        v4.x = 0x96000;
        v4.y = 0x5000;
        v4.z = 0;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(3), func_021D4480(0x2E), &v4, HEAP);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D4480(0x1B2)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        MCSS_ResetVanishFlag(OBJ(0));
        MCSS_SetPaletteFade(OBJ(0), 0, 0, 0, 0x7FFF);
        v5.x = -0x96000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        MCSS_SetPosition(OBJ(0), &v5);
        v5.x = 0x3C000;
        v5.y = 0x5000;
        v5.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(0), func_021D4480(0x67), &v5, HEAP);
        MCSS_GetScale(OBJ(0), &v5);
        v5.x *= 1.2;
        v5.y *= 1.2;
        MCSS_SetScale(OBJ(0), &v5);
        func_020307B0(SLOT1);
        SLOT1 = 0;
        MCSS_ResetVanishFlag(OBJ(1));
        v6.x = 0x96000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        MCSS_SetPosition(OBJ(1), &v6);
        v6.x = -0x2D000;
        v6.y = -0x37000;
        v6.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(1), func_021D4480(0x67), &v6, HEAP);
        MCSS_GetScale(OBJ(1), &v6);
        v6.x *= 1.2;
        v6.y *= 1.2;
        MCSS_SetScale(OBJ(1), &v6);
        *(u16 *)(SLOT0 + 0x16) = 1;
        *(u16 *)(SLOT1 + 0x16) = 1;
    }
    if (FRAME == func_021D4480(0x1F8)) {
        POKETRADE_MCSS_SlideBegin(SLOT0, func_021D4480(0x80), (void *)(SLOT0 + 0x28));
        POKETRADE_MCSS_SlideBegin(SLOT1, func_021D4480(0x80), (void *)(SLOT1 + 0x28));
    }
    if (FRAME == func_021D4480(0x27D)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        v7.x = 0x3C000;
        v7.y = 0x64000;
        v7.z = -0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT0);
        SLOT0 = POKETRADE_MCSS_SlideCreate(OBJ(0), func_021D4480(7), &v7, HEAP);
        v7.x = -0x2D000;
        v7.y = -0xA0000;
        v7.z = 0xA000;
        POKETRADE_SAVE_FreeIfSet(SLOT1);
        SLOT1 = POKETRADE_MCSS_SlideCreate(OBJ(1), func_021D4480(7), &v7, HEAP);
    }
    func_021D4480(0x48B);
    if (FRAME == func_021D4480(0x48B + 3)) {
        MCSS_ResetVanishFlag(OBJ(3));
        v8.x = 0;
        v8.y = -0x17000;
        v8.z = 0xA000;
        MCSS_SetPosition(OBJ(3), &v8);
        MCSS_SetAnmStopFlag(OBJ(3));
        MCSS_SetPaletteFade(OBJ(3), 0x10, 0x10, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x48F)) {
        MCSS_SetPaletteFade(OBJ(3), 8, 8, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x490)) {
        MCSS_SetPaletteFade(OBJ(3), 0, 0, 0, 0x7FFF);
    }
    if (FRAME == func_021D4480(0x28B)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, func_021D4480(0xA), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x2B5)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, func_021D4480(0x19), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x380)) {
        WIPE_SYS_Start(0, 0, 0, 0x7FFF, func_021D4480(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x3CA)) {
        WIPE_SYS_Start(0, 1, 1, 0x7FFF, func_021D4480(0x1E), 1, HEAP);
    }
    if (FRAME == func_021D4480(0x4C1)) {
        func_020307B0(SLOT0);
        SLOT0 = 0;
        func_020307B0(SLOT1);
        SLOT1 = 0;
        POKETRADE_3D_RemoveCurrentUnit(p);
        POKETRADE_PROC_SetStep(p, (int)func_021D49C4);
    }
    POKETRADE_MCSS_SlideUpdate(SLOT0, p);
    POKETRADE_MCSS_SlideUpdate(SLOT1, p);
}
