/*
 * function: func_021D4CE8
 * address:  0x021D4CE8
 * packet:   pkt_ov117_021D4CE8
 * region:   ov117
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D4480  0x021D4480  thumb  ov117
 *   func_021D434C  0x021D434C  thumb  ov117
 *   func_021D43C8  0x021D43C8  thumb  ov117
 *   func_021D49C4  0x021D49C4  thumb  ov117
 *   func_021D49F4  0x021D49F4  thumb  ov117
 *   func_021D4A48  0x021D4A48  thumb  ov117
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
 *   func_021E71F0  0x021E71F0  thumb  ov119
 *   func_021E7208  0x021E7208  thumb  ov119
 *   func_021DFD24  0x021DFD24  thumb  ov119
 *   func_021DFB84  0x021DFB84  thumb  ov119
 *   func_021DFA98  0x021DFA98  thumb  ov119
 *   func_021DFC68  0x021DFC68  thumb  ov119
 *   func_021E3230  0x021E3230  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *
 * Addresses are Black-image addresses.
 */
#include "../../../matched/include/Obj00342.h"

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
struct McssFade;
extern void func_021D49F4(void *obj, void *p);
extern void func_021D4A48(u8 *p, int idx);
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void MCSS_SetVanishFlag(void *p);
extern void MCSS_ResetVanishFlag(void *p);
extern void MCSS_ResetAnmStopFlag(void *p);
extern void MCSS_GetPosition(void *p, u32 *out);
extern void MCSS_SetPosition(void *p, u32 *src);
extern void MCSS_GetScale(void *p, u32 *out);
extern void MCSS_SetScale(void *p, u32 *src);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void WIPE_SYS_Start(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_020307B0(void *p);
extern void func_021E71F0(void *, int);
extern void func_021E7208(void *, int);
extern void func_021DFD24(u32 *p);
extern void *func_021DFB84(void *a0, void *a1, void *a2, u32 heapId);
extern void func_021DFA98(int);
extern void func_021DFC68(void *p, int a1);
extern void func_021E3230(void *);
extern void func_021D8E84(void *, int);

#define FRAME (*(s32 *)(p + 0xF2C))
#define OBJ(i) (((u32 *)(p + 0x844))[i])
#define HEAP (*(u16 *)(p + 0x5F4))
#define WORK (*(u32 **)(p + 0xc))

void func_021D4CE8(u8 *p)
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
        func_021E71F0(p, 0x11);
        func_021E7208(p, 0x18);
    }
    if (FRAME == func_021D4480(4)) {
        MCSS_SetVanishFlag((void *)OBJ(0));
    }
    if (FRAME == func_021D4480(-1)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[0], 0, 0, (int)p);
    }
    if (FRAME == func_021D4480(0x15E)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[1], 0, 0, (int)p);
    }
    if (FRAME == func_021D4480(0xC8)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[2], 1, 0, (int)p);
    }
    if (FRAME == func_021D4480(0x14)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[3], 2, 0, (int)p);
    }
    if (FRAME == func_021D4480(0x258)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[4], 2, 0, (int)p);
    }
    if (FRAME == func_021D4480(-1)) {
        PARTICLE_StartEffectWithCallback((int *)WORK[5], 3, 0, (int)p);
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
        func_021DFD24((u32 *)(((struct Obj00342 *)p)->f85C));
        ((struct Obj00342 *)p)->f85C = (unsigned int)func_021DFB84((void *)OBJ(2), (void *)func_021D4480(0x96), &v, HEAP);
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
        func_021DFD24((u32 *)(((struct Obj00342 *)p)->f860));
        ((struct Obj00342 *)p)->f860 = (unsigned int)func_021DFB84((void *)OBJ(3), (void *)func_021D4480(0x96), &v2, HEAP);
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
    func_021DFA98(FRAME);
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
        func_021E3230(p);
        func_021D8E84(p, (int)func_021D49C4);
    }
    func_021DFC68((void *)(((struct Obj00342 *)p)->f85C), (int)p);
    func_021DFC68((void *)(((struct Obj00342 *)p)->f860), (int)p);
    func_021DFC68((void *)(((struct Obj00342 *)p)->f864), (int)p);
    func_021DFC68((void *)(*(u32 *)&((struct Obj00342 *)p)->f868), (int)p);
}
