/*
 * function: PLIST_BATTLE_UpdateEffect
 * address: 0x021BD9C8
 * packet: pkt_ov091_021BD9C8
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0x02051614, unmatched accessor; +0x70 THM_CALL has no outside witness.
 * blocker: verified EXACT (one --arm, fixed compiler, 12 B) in scratch:
 *   unsigned int PARTICLE_GetEffectCount(unsigned int **p) { return (*p)[2]; }
 * symbols:
 *   func_02040588 0x02040588 arm
 *   PLIST_PLATE_SetMon 0x021BB200 thumb ov091
 *   PARTICLE_GetEffectCount 0x02051614 arm
 *   PARTICLE_UpdateAllSystems 0x02051574 arm
 *   G3D_SYSTEM_DrawStart 0x02047964 arm
 *   G3D_SYSTEM_ApplyLookAt 0x020479D8 arm
 *   PARTICLE_DrawAllSystems 0x02051534 arm
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   PM_VOICE_IsActive 0x02006BD0 thumb
 *   PM_VOICE_Play  0x02006984  thumb  arm9
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 *   GFL_USE_IsAnySeBusy  0x02006238  thumb  arm9
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void GFL_USE_PlaySeDefaultVolume(u32);
extern void PLIST_PLATE_SetMon(u8 *,u8 *,int,int);
extern int PARTICLE_GetEffectCount(int **p);
extern int GFL_USE_IsAnySeBusy(void);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u32 PM_VOICE_Play(u32,u32,u32,u32,u32,u32,u32,u32);
extern u32 PM_VOICE_IsActive(u32 i);
extern int PARTICLE_UpdateAllSystems(void);
extern void G3D_SYSTEM_DrawStart(void);
extern void G3D_SYSTEM_ApplyLookAt(void);
extern int PARTICLE_DrawAllSystems(void);
extern void G3D_SYSTEM_DrawEnd(void);
#define W(o) (*(u32 *)(p+(o)))
void PLIST_BATTLE_UpdateEffect(u8 *p)
{
    u32 species,form;
    if (W(0x26c) == 0) {
        p[0x268]++;
        if (p[0x268] == 1) {
            func_02040588(0,1);
            if (W(0x264)-1 <= 1) GFL_USE_PlaySeDefaultVolume(0x643);
            else if (W(0x264) == 3) GFL_USE_PlaySeDefaultVolume(0x644);
        }
        if (p[0x268] > p[0x269]) {
            PLIST_PLATE_SetMon(p,*(u8 **)(p+W(0x2c)*4+0x160),W(0x38),0);
            W(0x26c) = 1;
        }
    }
    if (PARTICLE_GetEffectCount((int **)W(0x260)) <= 0 && GFL_USE_IsAnySeBusy() == 0) {
        if (W(0x270) == 0) {
            species = POKE_TOOL_GetPartyValue((void *)W(0x38),5,0);
            form = POKE_TOOL_GetPartyValue((void *)W(0x38),0x6f,0);
            W(0x274) = PM_VOICE_Play(species,form,0x40,0,0,0,0,0);
            W(0x270) = 1;
        } else {
            if (PM_VOICE_IsActive(W(0x274)) == 0) p[0xc] = 0x10;
        }
    }
    PARTICLE_UpdateAllSystems();
    G3D_SYSTEM_DrawStart();
    G3D_SYSTEM_ApplyLookAt();
    PARTICLE_DrawAllSystems();
    G3D_SYSTEM_DrawEnd();
}
