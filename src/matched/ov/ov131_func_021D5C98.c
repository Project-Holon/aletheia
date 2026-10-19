/*
 * function: P_STATUS_RequestRefresh
 * address: 0x021D5C98
 * packet: pkt_ov131_021D5C98
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware halfwords reread at 021D5D96, 021D5DA0, 021D5DA6
 *   and written at 021D5D9C, 021D5DA4, 021D5DAA.
 * arithmetic: full-word selectors have cases 0..3 and an empty default;
 *   no selector bound is assumed. Halfword OR with 64 fits promoted int.
 * interfaces: own matched 60D4,697C,7C38,9C3C,8F50,9D44,A84C;
 *   matched callers 4418,4240,7BF0 supply remaining two-argument calls.
 *   Full original 6CDC and 909C confirm both incoming payloads are passed.
 * symbols:
 *   P_STATUS_SetParamDecoded 0x021D60D4 thumb ov131
 *   P_STA_SUB_FreeWindows 0x021D6CDC thumb ov131
 *   P_STA_RIBBON_Noop 0x021D91EC thumb ov131
 *   P_STA_SUB_InitWindows 0x021D697C thumb ov131
 *   P_STA_RIBBON_CollectOwned 0x021D911C thumb ov131
 *   P_STA_INFO_DeleteWindows 0x021D7E84 thumb ov131
 *   P_STA_SKILL_FreeStatsPage 0x021D9D44 thumb ov131
 *   P_STA_RIBBON_Deactivate 0x021D909C thumb ov131
 *   P_STA_SKILL_FreeMovesPage 0x021DA84C thumb ov131
 *   P_STA_INFO_Setup 0x021D7C38 thumb ov131
 *   P_STA_SKILL_InitStatsPage 0x021D9C3C thumb ov131
 *   P_STA_RIBBON_Init 0x021D8F50 thumb ov131
 *   P_STA_SKILL_InitMovesPage 0x021DA6A4 thumb ov131
 */
#include "../include/Obj00039.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void P_STATUS_SetParamDecoded(u8 *,int);
extern void P_STA_SUB_FreeWindows(unsigned char *a, unsigned char *b);
extern void P_STA_RIBBON_Noop(void *,void *);
extern void P_STA_SUB_InitWindows(u8 *,int *);
extern void P_STA_RIBBON_CollectOwned(u8 *a, u8 *p);
extern void P_STA_INFO_DeleteWindows(void *p, void **q);
extern void P_STA_SKILL_FreeStatsPage(void *,u8 *);
extern void P_STA_RIBBON_Deactivate(u8 *a, u8 *p);
extern void P_STA_SKILL_FreeMovesPage(u8 *,u8 *);
extern void P_STA_INFO_Setup(void *,u8 *);
extern void P_STA_SKILL_InitStatsPage(void *,u8 *);
extern void P_STA_RIBBON_Init(void *,u8 *);
extern void P_STA_SKILL_InitMovesPage(u8 *a, u8 *p);
void P_STATUS_RequestRefresh(u8 *p)
{
    P_STATUS_SetParamDecoded(p,1);
    if (p[0x1a]!=((struct Obj00039 *)p)->f18) {
        if (p[0x1a]!=255) {
            P_STA_SUB_FreeWindows(p,((struct Obj00039 *)p)->f88);
            P_STA_RIBBON_Noop(p,((struct Obj00039 *)p)->f94);
        }
        P_STA_SUB_InitWindows(p,*(int * *)&((struct Obj00039 *)p)->f88);
        P_STA_RIBBON_CollectOwned(p,((struct Obj00039 *)p)->f94);
    }
    switch (((struct Obj00039 *)p)->f5C) {
    case 0: P_STA_INFO_DeleteWindows(p,(void **)(*(u8 * *)&((struct Obj00039 *)p)->f8C)); break;
    case 1: P_STA_SKILL_FreeStatsPage(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    case 2: P_STA_RIBBON_Deactivate(p,((struct Obj00039 *)p)->f94); break;
    case 3: P_STA_SKILL_FreeMovesPage(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    }
    switch (*(u32 *)&((struct Obj00039 *)p)->f58) {
    case 0: P_STA_INFO_Setup(p,*(u8 * *)&((struct Obj00039 *)p)->f8C); break;
    case 1: P_STA_SKILL_InitStatsPage(p,*(u8 * *)&((struct Obj00039 *)p)->f90); break;
    case 2: P_STA_RIBBON_Init(p,*(u8 * *)&((struct Obj00039 *)p)->f94); break;
    case 3: P_STA_SKILL_InitMovesPage(p,((struct Obj00039 *)p)->f90); break;
    }
    if (((struct Obj00039 *)p)->f5C!=*(u32 *)&((struct Obj00039 *)p)->f58) {
        ((struct Obj00039 *)p)->f25C=1;
        p[0x260]=0;
        *(volatile u16 *)0x0400000c |= 64;
        *(volatile u16 *)0x0400100a |= 64;
        *(volatile u16 *)0x0400100c |= 64;
    }
    P_STATUS_SetParamDecoded(p,0);
    ((struct Obj00039 *)p)->fC=1;
}
