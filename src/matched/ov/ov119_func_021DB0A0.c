/*
 * function: POKETRADE_PROC_SendSideMon
 * address: 0x021DB0A0
 * packet: pkt_ov119_021DB0A0
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_LoadSlotMon 0x021D8D4C thumb ov119
 *   POKETRADE_PROC_IsNetSession 0x021D8A24 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   POKE_TOOL_GetPartyParamSize 0x020173EC thumb
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_020307B0 0x020307B0 arm
 *   POKETRADE_PROC_SetSideMon 0x021D9468 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;

extern void *POKETRADE_PROC_LoadSlotMon(void **a, int b, int c, char *p);
extern int POKETRADE_PROC_IsNetSession(void *);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int POKE_TOOL_GetPartyParamSize(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_020307B0(void *p);
extern void POKETRADE_PROC_SetSideMon(void *,int,void *);
int POKETRADE_PROC_SendSideMon(char *p)
{
    int t=(int)POKETRADE_PROC_LoadSlotMon(*(void ** *)&((struct Obj00001 *)p)->f828,((struct Obj00001 *)p)->fF88,((struct Obj00001 *)p)->fF84,p);
    if(POKETRADE_PROC_IsNetSession(p)) {
        unsigned id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
        if(GFL_NET_SendToHandle((void *)id,(u16)0xc01,(u16)POKE_TOOL_GetPartyParamSize(),t)==0) {
            func_020307B0((void *)t);
            return 0;
        }
    }
    POKETRADE_PROC_SetSideMon(p,0,(void *)t);
    func_020307B0((void *)t);
    return 1;
}
