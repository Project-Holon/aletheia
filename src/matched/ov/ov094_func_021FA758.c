/*
 * function: BTLV_EFFVM_CmdDeleteParticleEmitter
 * address:  0x021FA758
 * packet:   pkt_ov094_021FA758
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Script command: releases the emitter slot for a key and marks it free.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   BTLV_EFFVM_ResolveParticleKey 0x021FE38C thumb ov094
 *   BTLV_EFFVM_FindEmitterSlot 0x021FD1A8 thumb ov094
 *   BTLV_EFFVM_DeleteEmitter 0x021FDB08 thumb ov094
 */
#include "../include/Obj00325.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern unsigned int BTLV_EFFVM_ResolveParticleKey(char *, unsigned int);
extern int BTLV_EFFVM_FindEmitterSlot(char *p, int v);
extern void BTLV_EFFVM_DeleteEmitter(void *);

int BTLV_EFFVM_CmdDeleteParticleEmitter(void *a, char *s)
{
    int slot = BTLV_EFFVM_FindEmitterSlot(s, BTLV_EFFVM_ResolveParticleKey(s, VM_GetU32(a)));

    if (slot != 16) {
        void **e = (void **)(s + 0xc) + slot;
        BTLV_EFFVM_DeleteEmitter(*e);
        *e = 0;
        ((int *)(s + 0x4c))[slot] = -1;
    }
    return ((struct Obj00325 *)s)->f23C;
}
