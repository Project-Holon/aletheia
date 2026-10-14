/*
 * function: POKETRADE_PROC_CheckPartyBoxSelected
 * address: 0x021D9E0C
 * packet: pkt_ov119_021D9E0C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepOpenMenu 0x021D9DC4 thumb ov119
 */
#include "../include/Obj13890.h"

typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepOpenMenu(void *);
void POKETRADE_PROC_CheckPartyBoxSelected(char *p)
{
    int v = 0;
    if (((struct Obj13890 *)p)->fF88 == ((struct Obj13890 *)p)->f630) v=1;
    if (GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xC16,1,(u32)(&v)))
        POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepOpenMenu);
}
