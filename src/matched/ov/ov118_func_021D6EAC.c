/*
 * function: POKETRADE_DEMO_MIDDLE_SetupEmitterA
 * address:  0x021D6EAC
 * packet:   pkt_021D6EAC
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_DEMO_MIDDLE_UpdateEmitterA  0x021D6E6C  thumb  ov118
 *   PARTICLE_EMITTER_SetCallback  0x02051A24  arm  arm9
 *   PARTICLE_EMITTER_SetUserData  0x02051A2C  arm  arm9
 *   PARTICLE_GetCallbackArg  0x02051774  arm  arm9
 *
 * Addresses are Black-image addresses.
 *
 * Promoted from MATCH by the recursive-unblocker lane: the ARM9 storage
 * setters PARTICLE_EMITTER_SetUserData/PARTICLE_EMITTER_SetCallback (0x02051A2C / 0x02051A24) now have
 * EXACT arm9 shard entries (pkt_02051A2C / pkt_02051A24), so both calls
 * resolve via `matched`.  Verified EXACT, 32 bytes.
 */

typedef unsigned int   u32;
extern u32 PARTICLE_GetCallbackArg(void);
extern void PARTICLE_EMITTER_SetUserData(void *p, int v);
extern void PARTICLE_EMITTER_SetCallback(void *p, int v);
extern void POKETRADE_DEMO_MIDDLE_UpdateEmitterA(void *obj, int on);

void POKETRADE_DEMO_MIDDLE_SetupEmitterA(void *p)
{
    PARTICLE_EMITTER_SetUserData(p, PARTICLE_GetCallbackArg());
    PARTICLE_EMITTER_SetCallback(p, (int)POKETRADE_DEMO_MIDDLE_UpdateEmitterA);
}
