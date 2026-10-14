/*
 * function: CG_HELP_Setup
 * address: 0x021D4240
 * packet: pkt_ov124_021D4240
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CG_HELP_InitDisplay 0x021D43F8 thumb ov124
 *   CG_HELP_LoadActorResources 0x021D4558 thumb ov124
 *   CG_HELP_InitWindows 0x021D46BC thumb ov124
 *   CG_HELP_VBlank 0x021D43F0 thumb ov124
 *   CG_HELP_DrawPageText 0x021D4940 thumb ov124
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 */
#include "../include/Obj00068.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void CG_HELP_InitDisplay(char *);
extern void CG_HELP_LoadActorResources(char *);
extern void CG_HELP_InitWindows(char *);
extern void CG_HELP_VBlank(void);
extern void *func_020056A0(void *,void *,int);
extern void CG_HELP_DrawPageText(char *,int);
extern void GFL_NET_RestartWithDefaultTimeout(unsigned,unsigned);
void CG_HELP_Setup(char *p)
{
    ((struct Obj00068 *)p)->f10 = 0;
    CG_HELP_InitDisplay(p);
    CG_HELP_LoadActorResources(p);
    CG_HELP_InitWindows(p);
    ((struct Obj00068 *)p)->f14 = func_020056A0(CG_HELP_VBlank,p,8);
    ((struct Obj00068 *)p)->f18 = 0;
    ((struct Obj00068 *)p)->fC = 1;
    CG_HELP_DrawPageText(p,((struct Obj00068 *)p)->f18);
    GFL_NET_RestartWithDefaultTimeout(0,((struct Obj00068 *)p)->f0);
}
