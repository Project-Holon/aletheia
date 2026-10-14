/*
 * function: BTLV_EFFVM_CmdStartParticleEffectTargeted
 * address: 0x021FA458
 * packet: pkt_ov094_021FA458
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * witness: arm9 BUTTON_MAN_GetBlock filed as src/matched/arm9/BUTTON_MAN_GetBlock.c.
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   BUTTON_MAN_GetBlock 0x02051788 arm
 *   BTLV_EFFVM_ResolveParticleKey 0x021FE38C thumb ov094
 *   BTLV_EFFVM_FindEmitterSlot 0x021FD1A8 thumb ov094
 *   BTLV_EFFVM_StartParticleEffectInternal 0x021FDD60 thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   d_02209E1C 0x02209E1C data a4
 *   d_02209D90 0x02209D90 data a4
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { u32 v[8]; } Desc;
extern char d_0220AE68[];
extern const Vec d_02209E1C, d_02209D90;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
struct Dst648;
struct Src648;
extern void PARTICLE_InitCamera(struct Dst648 *this, struct Src648 *src, u16 a2, int *a3, int *a4, int *a5, u32 a6);
extern int BUTTON_MAN_GetBlock(char *p);
extern unsigned int BTLV_EFFVM_ResolveParticleKey(char *, unsigned int);
extern int BTLV_EFFVM_FindEmitterSlot(char *p, int v);
extern void BTLV_EFFVM_StartParticleEffectInternal(char *, int *, int, int);

int BTLV_EFFVM_CmdStartParticleEffectTargeted(void *a, char *s)
{
    Desc desc;
    int *p;
    int slot;
    int arg;

    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x7b6);
    slot = BTLV_EFFVM_FindEmitterSlot(s, BTLV_EFFVM_ResolveParticleKey(s, VM_GetU32(a)));
    arg = VM_GetU32(a);
    p[0] = (int)a;
    p[1] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = VM_GetU32(a);
    p[4] = VM_GetU32(a);
    p[5] = VM_GetU32(a);
    p[17] = VM_GetU32(a);
    p[18] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    p[16] = 1;
    if (p[1] == 13) {
        p[1] = 9;
        p[16] = 2;
    }
    if (p[2] == 8)
        p[2] = p[1];
    if (slot != 16) {
        Vec zero = {0, 0, 0};
        Vec v1;
        Vec v2;
        v1 = d_02209E1C;
        v2 = d_02209D90;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (BUTTON_MAN_GetBlock(*(void **)(s + 12 + slot * 4)) == 0)
            PARTICLE_InitCamera(*(void **)(s + 12 + slot * 4), (struct Src648 *)(&desc), 0x2000, (int *)(&zero), (int *)(&v1), (int *)(&v2), (u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000));
        BTLV_EFFVM_StartParticleEffectInternal(s, p, slot, arg);
    }
    func_020307B0(p);
    return ((struct Obj00325 *)s)->f23C;
}
