/*
 * function: WORLDTRADE_SERVER_WaitTrade
 * address: 0x0220171C
 * packet: pkt_ov135_0220171C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DPW_TR_IsAsyncEnd 0x021C866C arm ov114
 *   DPW_TR_GetAsyncResult 0x021C86A8 arm ov114
 *   WORLDTRADE_ADAPTER_RemovePartyMon 0x022021F8 thumb ov135
 *   WORLDTRADE_ADAPTER_RegisterReceivedMonB 0x022023A4 thumb ov135
 *   WORLDTRADE_ADAPTER_RegisterLanguageVersion 0x022024B0 thumb ov135
 *   WORLDTRADE_SERVER_RecordTradeResult 0x02201B44 thumb ov135
 *   WORLDTRADE_CancelSave 0x021F513C thumb ov135
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 */
#include "../include/Obj01943.h"
#include "../include/Obj23444.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int DPW_TR_IsAsyncEnd(void);
extern int DPW_TR_GetAsyncResult(void);
extern void WORLDTRADE_ADAPTER_RemovePartyMon(u8 *,int);
extern void WORLDTRADE_ADAPTER_RegisterReceivedMonB(u8 *p, void *mon, void *unused2, void *unused3, u32 index);
extern void WORLDTRADE_ADAPTER_RegisterLanguageVersion(void *obj, u8 *p);
extern void WORLDTRADE_SERVER_RecordTradeResult(u8 *,void *,u8 *,void *);
extern void WORLDTRADE_CancelSave(u8 *p);
extern u32 func_0200FBB0(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern void func_0200FBA0(void);
extern void GFL_NET_STATE_ClearErrorMode(void);
int WORLDTRADE_SERVER_WaitTrade(u8 *p)
{
    int r;
    if(DPW_TR_IsAsyncEnd()) {
        r=DPW_TR_GetAsyncResult();
        ((struct Obj01943 *)p)->fF8C=0;
        switch(r) {
        case 0:
            ((struct Obj01943 *)p)->f28=0x22;
            WORLDTRADE_ADAPTER_RemovePartyMon(p,0);
            WORLDTRADE_ADAPTER_RegisterReceivedMonB(p,p+0xA24,p+0xE4,p+0xA24,((struct Obj01943 *)p)->fC4);
            WORLDTRADE_ADAPTER_RegisterLanguageVersion(((struct Obj23444 *)(*(u8 * *)&((struct Obj01943 *)p)->f0))->f18,p+0xA24);
            WORLDTRADE_SERVER_RecordTradeResult(p,p+0xA24,p+0xA24,p+0xE4);
            break;
        case -5:
            ((struct Obj01943 *)p)->f38=r;
            ((struct Obj01943 *)p)->f28=0x15;
            break;
        case -6: case -7: case -8: case -9: case -10: case -11:
            ((struct Obj01943 *)p)->f38=r;
            ((struct Obj01943 *)p)->f28=0x2D;
            break;
        case -12:
            ((struct Obj01943 *)p)->f38=r;
            ((struct Obj01943 *)p)->f28=0x2D;
            break;
        case -15: case -14: case -2:
            ((struct Obj01943 *)p)->f38=r;
            ((struct Obj01943 *)p)->f28=0x2B;
            func_0200FBB0(); GFL_NET_STATE_SetWifiError(); func_0200FBA0(); GFL_NET_STATE_ClearErrorMode();
            break;
        case -13:
            WORLDTRADE_CancelSave(p);
            break;
        }
    } else {
        if(++((struct Obj01943 *)p)->fF8C==0xE10) WORLDTRADE_CancelSave(p);
    }
    return 2;
}
