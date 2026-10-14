/*
 * function: func_021DB9B4
 * address: 0x021DB9B4
 * packet: pkt_ov119_021DB9B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_NEGO_FindOfferIndex 0x021DD34C thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   POKETRADE_PROC_ClearSideMon 0x021D94A0 thumb ov119
 *   POKETRADE_PROC_RequestBoxRedraw 0x021D8B38 thumb ov119
 *   POKETRADE_PROC_SetStep 0x021D8E84 thumb ov119
 *   func_021DB998 0x021DB998 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;

extern int POKETRADE_PROC_IsNetSession(void *);
extern int POKETRADE_NEGO_FindOfferIndex(char *,int,int);
typedef unsigned int   u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern void POKETRADE_PROC_ClearSideMon(void *,int);
extern void POKETRADE_PROC_RequestBoxRedraw(char *p);
extern void POKETRADE_PROC_SetStep(void *,int);
extern void func_021DB998(char *p);
void func_021DB9B4(char *p)
{
    POKETRADE_NEGO_FindOfferIndex(p,((struct Obj00001 *)p)->fF98,((struct Obj00001 *)p)->fF94);
    if(POKETRADE_PROC_IsNetSession(p)) {
        if(!GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc06,0,0)) return;
    }
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(int *)&((struct Obj00001 *)p)->f9C0),8,0);
    ((struct Obj00001 *)p)->fF84=-1;
    ((struct Obj00001 *)p)->fF88=-1;
    ((struct Obj00001 *)p)->fF7C=-1;
    ((struct Obj00001 *)p)->fF80=-1;
    ((struct Obj00001 *)p)->fF94=-1;
    ((struct Obj00001 *)p)->fF98=-1;
    POKETRADE_PROC_ClearSideMon(p,0);
    POKETRADE_PROC_RequestBoxRedraw(p);
    POKETRADE_PROC_SetStep(p,(int)func_021DB998);
}
