/*
 * function: POKETRADE_NEGO_AddSelectedAsOffer
 * address: 0x021DD5B4
 * packet: pkt_ov119_021DD5B4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKETRADE_PROC_LoadSlotMon 0x021D8D4C thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   POKETRADE_NEGO_AddOffer 0x021DD428 thumb ov119
 *   POKETRADE_NEGO_SendOfferMon 0x021DF9E8 thumb ov119
 *   POKETRADE_NEGO_RemoveOffer 0x021DD4F4 thumb ov119
 *   func_020307B0 0x020307B0 arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   POKETRADE_2D_CreateOfferIconActor 0x021E6334 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned int   u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, char *p);
extern int POKETRADE_PROC_IsNetSession(void *);
struct S119DD4F4;
struct State;
extern int POKETRADE_NEGO_AddOffer(struct State *p, int side, int a, int b, void *value);
extern int POKETRADE_NEGO_SendOfferMon(char *,void *,int);
extern void POKETRADE_NEGO_RemoveOffer(struct S119DD4F4 *p, int i, int j);
extern u32 func_020307B0(void *p);
extern u32 POKE_TOOL_GetPartyParamSize(void);
extern void POKETRADE_2D_CreateOfferIconActor(char *p, int i, int j, void *mon, int selected, u32 visible);
int POKETRADE_NEGO_AddSelectedAsOffer(char *p,int a,int b)
{
    int value,slot;
    unsigned i;
    GFL_NET_HANDLE_GetCurrentHandle();
    value=(int)POKETRADE_PROC_LoadSlotMon(*(void ** *)&((struct Obj00001 *)p)->f828,((struct Obj00001 *)p)->fF88,((struct Obj00001 *)p)->fF84,p);
    if(POKETRADE_PROC_IsNetSession(p)) {
        i=0;
        slot=POKETRADE_NEGO_AddOffer((struct State *)p,0,a,b,(void *)value);
        if(slot!=-1) {
            if(POKETRADE_NEGO_SendOfferMon(p,*(void **)(p+slot*4+0xfd8),slot+0xc07)==0) {
                POKETRADE_NEGO_RemoveOffer((struct S119DD4F4 *)p,0,slot);
                func_020307B0((void *)value);
                return 0;
            }
            for(i=0;i<(unsigned)POKE_TOOL_GetPartyParamSize();i++) {}
        }
    } else {
        slot=POKETRADE_NEGO_AddOffer((struct State *)p,0,a,b,(void *)value);
    }
    if(slot==-1) {func_020307B0((void *)value);return 1;}
    POKETRADE_2D_CreateOfferIconActor(p,0,slot,(void *)value,1,0);
    func_020307B0((void *)value);
    return 1;
}
