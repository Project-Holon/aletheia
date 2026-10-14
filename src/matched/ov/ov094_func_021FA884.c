/*
 * function: BTLV_EFFVM_CmdStartParticleEffectConstOffset
 * address: 0x021FA884
 * packet: pkt_ov094_021FA884
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   VM_GetU32 0x0201134C thumb
 *   PARTICLE_StartEffectWithCallback 0x020515CC arm
 *   BTLV_EFFVM_ResolveParticleKey 0x021FE38C thumb ov094
 *   BTLV_EFFVM_FindEmitterSlot 0x021FD1A8 thumb ov094
 *   BTLV_EFFVM_ParticleStartCallback 0x021FD1CC thumb ov094
 *   d_0220AE68 0x0220AE68 data ov094 a1
 */
#include "../include/Obj00325.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern char d_0220AE68[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern int PARTICLE_StartEffectWithCallback(int *p, int a, int b, int c);
extern u32 BTLV_EFFVM_ResolveParticleKey(char *, u32);
extern int BTLV_EFFVM_FindEmitterSlot(char *, int);
extern void BTLV_EFFVM_ParticleStartCallback(void *p);
int BTLV_EFFVM_CmdStartParticleEffectConstOffset(void *a, char *s)
{
    int *p;
    int idx;
    int x;
    p = func_02030734((u16)((((struct Obj00325 *)s)->f238 & 0x7fff) | 0x8000), 0x5c, 1, d_0220AE68, 0x8a2);
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
    p[19] = 0x1000;
    p[20] = VM_GetU32(a);
    p[21] = VM_GetU32(a);
    if (p[21] == 0) p[21] = 1;
    if (idx != 16) {
        if (PARTICLE_StartEffectWithCallback(*(int **)(s + 0xc + idx * 4), x, (int)BTLV_EFFVM_ParticleStartCallback, (int)p) == -1) {
            func_020307B0(p);
        }
    } else {
        func_020307B0(p);
    }
    return ((struct Obj00325 *)s)->f23C;
}
