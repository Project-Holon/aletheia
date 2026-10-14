/*
 * function: BTLV_EFFVM_SetupEmitterCallbacks
 * address: 0x021FDFA0
 * packet: pkt_ov094_021FDFA0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   VM_GetU32 0x0201134C thumb
 *   PARTICLE_StartEffectWithCallback 0x020515CC arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   BUTTON_MAN_GetBlock 0x02051788 arm
 *   BTLV_EFFVM_ResolveParticleKey 0x021FE38C thumb ov094
 *   BTLV_EFFVM_FindEmitterSlot 0x021FD1A8 thumb ov094
 *   BTLV_EFFVM_EmitterInitCallback 0x021FD9F0 thumb ov094
 *   BTLV_EFFVM_ResolveSlotKey 0x021FCF2C thumb ov094
 *   BTLV_EFFECT_GetMcss 0x021F8694 thumb ov094
 *   BTLV_MCSS_GetSlotPosition 0x021FF3F4 thumb ov094
 *   _s32_div_f 0x0209C0A4 arm
 *   d_0220AE68 0x0220AE68 data
 *   d_02209E10 0x02209E10 data
 *   d_02209DB4 0x02209DB4 data
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { u32 v[8]; } Desc;
extern char d_0220AE68[];
extern const Vec d_02209E10, d_02209DB4;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void PARTICLE_InitCamera(void *, Desc *, u16, Vec *, Vec *, Vec *, u16);
extern int BUTTON_MAN_GetBlock(char *p);
extern u32 BTLV_EFFVM_ResolveParticleKey(char *, u32);
extern int BTLV_EFFVM_FindEmitterSlot(char *, int);
extern void BTLV_EFFVM_EmitterInitCallback(void *p);
extern int BTLV_EFFVM_ResolveSlotKey(int a, int idx);
extern int BTLV_EFFECT_GetMcss(void);
extern void BTLV_MCSS_GetSlotPosition(void *obj, void *out, int idx);
extern int _s32_div_f(int, int);
int BTLV_EFFVM_SetupEmitterCallbacks(void *a, char *s, int mode)
{
    int *p;
    int idx;
    int x;
    int y;
    int flags;

    idx = BTLV_EFFVM_FindEmitterSlot(s, BTLV_EFFVM_ResolveParticleKey(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    flags = 0;
    *(int **)(s + 0x1f4 + ((struct Obj00325 *)s)->f234 * 4) = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x40, 0, d_0220AE68, 0x1c79);
    p = *(int **)(s + 0x1f4 + ((struct Obj00325 *)s)->f234 * 4);
    ((struct Obj00325 *)s)->f234 += 1;
    p[0] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    y = VM_GetU32(a);
    p[6] = 0;
    p[9] = p[8] = VM_GetU32(a);
    p[10] = 0;
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[13] = 0;
    p[14] = VM_GetU32(a);
    p[7] = _s32_div_f(0x10000, p[8]);
    p[15] = mode;
    if (idx == 16)
        goto end;
    if (mode == 1) {
        if (BUTTON_MAN_GetBlock(*(void **)(s + 0xc + idx * 4)) == 0) {
            Desc desc;
            Vec zero = {0, 0, 0};
            Vec v1;
            Vec v2;
            v1 = d_02209E10;
            v2 = d_02209DB4;
            desc.v[0] = 2;
            desc.v[1] = 0x3000;
            desc.v[2] = 0xffffd000;
            desc.v[3] = 0xffffc000;
            desc.v[4] = 0x4000;
            desc.v[5] = 0x1000;
            desc.v[6] = 0x200000;
            desc.v[7] = 0x1000;
            PARTICLE_InitCamera(*(void **)(s + 0xc + idx * 4), &desc, 0x2000, &zero, &v1, &v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        }
    }
    switch (p[0]) {
    case 0:
    case 1:
        flags = BTLV_EFFVM_ResolveSlotKey((int)a, 14);
        BTLV_MCSS_GetSlotPosition((void *)BTLV_EFFECT_GetMcss(), &p[1], flags);
        break;
    case 2:
    case 3:
        flags = BTLV_EFFVM_ResolveSlotKey((int)a, 16);
        BTLV_MCSS_GetSlotPosition((void *)BTLV_EFFECT_GetMcss(), &p[1], flags);
        break;
    case 4:
    case 5:
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        break;
    }
    if (flags & 1)
        p[6] = 0x8000;
    p[2] += y;
    if (PARTICLE_StartEffectWithCallback(*(int **)(s + 0xc + idx * 4), x, (int)BTLV_EFFVM_EmitterInitCallback, (int)p) == -1)
        func_020307B0(p);
end:
    return ((struct Obj00325 *)s)->f23C;
}
