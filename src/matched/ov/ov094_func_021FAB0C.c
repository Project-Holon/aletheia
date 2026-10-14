/*
 * function: BTLV_EFFVM_CmdStartParticleEffectTargetedConstOffset
 * address: 0x021FAB0C
 * packet: pkt_ov094_021FAB0C
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * witness: arm9 BUTTON_MAN_GetBlock filed as src/matched/arm9/BUTTON_MAN_GetBlock.c.
 * trailing: 021FAC94 and 021FACA0 are tail-call stubs; not filed while ARM9 blocks.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   VM_GetU32 0x0201134C thumb
 *   PARTICLE_StartEffectWithCallback 0x020515CC arm
 *   PARTICLE_InitCamera 0x02051648 arm
 *   BUTTON_MAN_GetBlock 0x02051788 arm
 *   BTLV_EFFVM_ResolveParticleKey 0x021FE38C thumb ov094
 *   BTLV_EFFVM_FindEmitterSlot 0x021FD1A8 thumb ov094
 *   BTLV_EFFVM_ParticleStartCallback 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 *   d_02209DA8 0x02209DA8 data ov094 a4
 *   d_02209D9C 0x02209D9C data ov094 a4
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
typedef struct { u32 v[8]; } Desc;
extern char d_0220AE68[];
extern const Vec d_02209DA8, d_02209D9C;
extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern void PARTICLE_InitCamera(void *, Desc *, u16, Vec *, Vec *, Vec *, u16);
extern int BUTTON_MAN_GetBlock(char *p);
extern u32 BTLV_EFFVM_ResolveParticleKey(char *, u32);
extern int BTLV_EFFVM_FindEmitterSlot(char *, int);
extern void BTLV_EFFVM_ParticleStartCallback(void *p);
int BTLV_EFFVM_CmdStartParticleEffectTargetedConstOffset(void *a, char *s)
{
    Desc desc;
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x92d);
    idx = BTLV_EFFVM_FindEmitterSlot(s, BTLV_EFFVM_ResolveParticleKey(s, VM_GetU32(a)));
    x = VM_GetU32(a);
    p[0] = (int)a;
    p[8] = VM_GetU32(a);
    p[1] = 8;
    p[10] = VM_GetU32(a);
    p[11] = VM_GetU32(a);
    p[12] = VM_GetU32(a);
    p[2] = VM_GetU32(a);
    p[3] = 0;
    p[4] = VM_GetU32(a);
    p[5] = 0;
    p[9] = VM_GetU32(a);
    p[7] = VM_GetU32(a);
    p[17] = 0x1000;
    p[18] = VM_GetU32(a);
    p[20] = VM_GetU32(a);
    p[19] = VM_GetU32(a);
    p[16] = 3;
    if (idx != 16) {
        Vec zero = {0, 0, 0};
        Vec v1;
        Vec v2;
        v1 = d_02209DA8;
        v2 = d_02209D9C;
        desc.v[0] = 2;
        desc.v[1] = 0x3000;
        desc.v[2] = 0xffffd000;
        desc.v[3] = 0xffffc000;
        desc.v[4] = 0x4000;
        desc.v[5] = 0x1000;
        desc.v[6] = 0x200000;
        desc.v[7] = 0x1000;
        if (BUTTON_MAN_GetBlock(*(void **)(s + 0xc + idx * 4)) == 0)
            PARTICLE_InitCamera(*(void **)(s + 0xc + idx * 4), &desc, 0x2000, &zero, &v1, &v2, (((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000);
        if (PARTICLE_StartEffectWithCallback(*(int **)(s + 0xc + idx * 4), x, (int)BTLV_EFFVM_ParticleStartCallback, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}
