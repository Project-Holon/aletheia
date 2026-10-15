/*
 * function: EGG_DEMO_VIEW_SetSpecies
 * address: 0x021F6A48
 * packet: pkt_ov215_021F6A48
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetPaletteFade 0x02015F50 thumb
 *   EGG_DEMO_VIEW_DeletePokeMcss 0x021F6CAC thumb ov215
 *   EGG_DEMO_VIEW_AddPokeMcss 0x021F6AEC thumb ov215
 *   EGG_DEMO_VIEW_PlayAnim 0x021F6CCC thumb ov215
 */
typedef unsigned char u8;
struct McssFade;
extern void MCSS_SetVanishFlag(void *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void MCSS_SetPaletteFade(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
extern void EGG_DEMO_VIEW_DeletePokeMcss(char *);
extern void EGG_DEMO_VIEW_AddPokeMcss(char *);
extern void EGG_DEMO_VIEW_PlayAnim(char *,unsigned,int);
void EGG_DEMO_VIEW_SetSpecies(char *p,int a)
{
    EGG_DEMO_VIEW_DeletePokeMcss(p);
    *(int *)(p + 4) = a;
    EGG_DEMO_VIEW_AddPokeMcss(p);
    EGG_DEMO_VIEW_PlayAnim(p,0,0);
    MCSS_SetVanishFlag(*(void **)(p + 0x34));
    MCSS_SetPaletteFade(*(struct McssFade **)(p + 0x34),16,16,0,32767);
    *(int *)(p + 0xC) = 5;
}
