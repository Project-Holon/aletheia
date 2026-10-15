/*
 * function: WORLDTRADE_SERVER_StateFinishTrade
 * address: 0x02201CBC
 * packet: pkt_ov135_02201CBC
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_GetReturnBox 0x0200ADE0 thumb
 *   WORLDTRADE_ADAPTER_RegisterReceivedMon 0x022022B8 thumb ov135
 *   WORLDTRADE_ADAPTER_RegisterLanguageVersion 0x022024B0 thumb ov135
 *   WORLDTRADE_SERVER_RecordTradeResult 0x02201B44 thumb ov135
 *   WORLDTRADE_ADAPTER_SetPair 0x0220251C thumb ov135
 *   WORLDTRADE_SetIsDeposited  0x0200AD94  thumb  arm9
 */
#include "../include/Obj00018.h"
#include "../include/Obj23457.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec0200AD94;
struct RegB;
extern u16 WORLDTRADE_GetReturnBox(struct RegB *p);
extern void WORLDTRADE_ADAPTER_RegisterReceivedMon(void *, void *, u32, int);
extern void WORLDTRADE_ADAPTER_RegisterLanguageVersion(void *obj, u8 *p);
extern void WORLDTRADE_SERVER_RecordTradeResult(u8 *p, void *mon, u8 *r, void *old);
extern void WORLDTRADE_SetIsDeposited(struct Rec0200AD94 *p, u16 v);
extern void WORLDTRADE_ADAPTER_SetPair(u8 *p, u16 a, u16 b);
int WORLDTRADE_SERVER_StateFinishTrade(u8 *p)
{
    WORLDTRADE_ADAPTER_RegisterReceivedMon(p, p + 0xe4, WORLDTRADE_GetReturnBox(**(void ** *)&((struct Obj00018 *)p)->f0), ((struct Obj00018 *)p)->f207);
    WORLDTRADE_ADAPTER_RegisterLanguageVersion(((struct Obj23457 *)(*(u8 * *)&((struct Obj00018 *)p)->f0))->f18, p + 0xe4);
    WORLDTRADE_SERVER_RecordTradeResult(p, p + 0xe4, p + 0xe4, 0);
    WORLDTRADE_SetIsDeposited(**(void ** *)&((struct Obj00018 *)p)->f0, 0);
    ((struct Obj00018 *)p)->f28 = 0x22;
    WORLDTRADE_ADAPTER_SetPair(p, 0x17, 0xf);
    return 2;
}
