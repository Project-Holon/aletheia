/*
 * function: func_021DA1DC
 * address: 0x021DA1DC
 * packet: pkt_ov119_021DA1DC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_NEGO_FindFreeOfferIndex 0x021DD3D4 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   POKETRADE_PROC_StepAddSelectedOffer 0x021DA1B4 thumb ov119
 */
#include "../include/Obj08053.h"

typedef unsigned short u16;
struct Entry;
extern int POKETRADE_NEGO_FindFreeOfferIndex(const char *p, int n, int a, int b);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void POKETRADE_PROC_StepAddSelectedOffer(char *p);
void func_021DA1DC(char *p) {
    int v=0;
    int n;
    if(((struct Obj08053 *)p)->fF88==((struct Obj08053 *)p)->f630) v=1;
    n=POKETRADE_NEGO_FindFreeOfferIndex(p,0,((struct Obj08053 *)p)->fF84,((struct Obj08053 *)p)->fF88);
    if(n!=-1) {
        if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),(u16)(n+0xC13),(u16)1,(u32)(&v))) {
            POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepAddSelectedOffer);
            return;
        }
    } else POKETRADE_PROC_SetStep(p,(int)POKETRADE_PROC_StepAddSelectedOffer);
}
