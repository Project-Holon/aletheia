/*
 * function: P_STA_SUB_CreateMcss
 * address: 0x021D785C
 * packet: pkt_ov131_021D785C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-02 relaunch R9. The +0xAA/+0xAC str/movs swap was a
 *   scheduler effect of the pre-allocation instruction count before group 2
 *   (a no-arg call inserted earlier shifts it; a band of 5 positions swaps).
 *   MCSS_TOOL_SetAnimeStopCallback is declared void(void *): its body only forwards to
 *   MCSS_SetAnimCallback, and an int return adds one result copy per call, which
 *   put the second store inside the band. ov195 declares it the same way.
 * symbols:
 *   d_021DC1F8 0x021DC1F8 data ov131 a4
 *   d_021DC240 0x021DC240 data ov131 a4
 *   d_021DC180 0x021DC180 data a4
 *   d_021DC1C8 0x021DC1C8 data ov131 a4
 *   P_STATUS_GetPokeParaSource 0x021D60A4 thumb ov131
 *   P_STA_SUB_GetSpeciesAdjust 0x021D7A44 thumb ov131
 *   P_STA_SUB_SetPetOffset 0x021D79A8 thumb ov131
 *   P_STA_SUB_ApplyMcssOffset 0x021D7A1C thumb ov131
 *   MCSS_SetShadowRotateX 0x02015D80 thumb
 *   MCSS_SetOfsScale 0x02015D30 thumb
 *   MCSS_SetShadowScale 0x02015CDC thumb
 *   MCSS_ResetVanishFlag 0x02015EB0 thumb
 *   MCSS_SetVanishFlag 0x02015EA0 thumb
 *   MCSS_SetShadowAlpha  0x02015FD4  thumb  arm9
 *   MCSS_TOOL_AddPokeMcss  0x02017270  thumb  arm9
 *   MCSS_TOOL_SetAnimeStopCallback  0x020173B4  thumb  arm9
 */
#include "../include/Obj00112.h"
#include "../include/Obj00994.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct { u32 x,y,z; } Vec;
extern const Vec d_021DC1F8,d_021DC240,d_021DC180,d_021DC1C8;
extern int P_STATUS_GetPokeParaSource(char *p);
extern void P_STA_SUB_GetSpeciesAdjust(void *,int,int *,int *);
extern void P_STA_SUB_SetPetOffset(void *p, unsigned char *q, int radius);
extern void P_STA_SUB_ApplyMcssOffset(void *,void *,Vec *);
extern void *MCSS_TOOL_AddPokeMcss(void *a0, void *a1, u32 a2, u32 a3, u32 a4, u32 a5);
extern void MCSS_SetShadowAlpha(char *,int);
extern void MCSS_SetShadowRotateX(u8 *,u16);
extern void MCSS_SetOfsScale(void *,u32 *);
extern void MCSS_TOOL_SetAnimeStopCallback(void *);
extern void MCSS_SetShadowScale(void *,u32 *);
extern void MCSS_ResetVanishFlag(void *);
extern void MCSS_SetVanishFlag(void *);
void P_STA_SUB_CreateMcss(u8 *p,u8 *q,void *mon)
{
    Vec a=d_021DC1F8;
    Vec b=d_021DC240;
    Vec c=d_021DC180;
    Vec d=d_021DC1C8;
    void *m=(void *)P_STATUS_GetPokeParaSource((void *)p);
    P_STA_SUB_GetSpeciesAdjust((void *)p,(int)q,(int *)&a,(int *)&b);
    ((struct Obj00994 *)q)->f0=MCSS_TOOL_AddPokeMcss(((struct Obj00112 *)p)->f78,m,0,0xd8000,0x48000,0);
    MCSS_SetShadowAlpha(*(char * *)&((struct Obj00994 *)q)->f0,2);
    MCSS_SetShadowRotateX(*(u8 * *)&((struct Obj00994 *)q)->f0,0xd555);
    MCSS_SetOfsScale(((struct Obj00994 *)q)->f0,&b.x);
    MCSS_TOOL_SetAnimeStopCallback(((struct Obj00994 *)q)->f0);
    MCSS_SetShadowScale(((struct Obj00994 *)q)->f0,&a.x);
    ((struct Obj00994 *)q)->f4=MCSS_TOOL_AddPokeMcss(((struct Obj00112 *)p)->f78,m,1,0xd8000,0x48000,0);
    MCSS_SetShadowAlpha(*(char * *)&((struct Obj00994 *)q)->f4,2);
    MCSS_SetShadowRotateX(*(u8 * *)&((struct Obj00994 *)q)->f4,0xd555);
    MCSS_SetOfsScale(((struct Obj00994 *)q)->f4,&c.x);
    MCSS_TOOL_SetAnimeStopCallback(((struct Obj00994 *)q)->f4);
    MCSS_SetShadowScale(((struct Obj00994 *)q)->f4,&a.x);
    P_STA_SUB_SetPetOffset((void *)p,q,0);
    P_STA_SUB_ApplyMcssOffset((void *)p,q,&d);
    if(((struct Obj00994 *)q)->fC==1) {
        MCSS_ResetVanishFlag(((struct Obj00994 *)q)->f0);
        MCSS_SetVanishFlag(((struct Obj00994 *)q)->f4);
        return;
    }
    MCSS_ResetVanishFlag(((struct Obj00994 *)q)->f4);
    MCSS_SetVanishFlag(((struct Obj00994 *)q)->f0);
}
