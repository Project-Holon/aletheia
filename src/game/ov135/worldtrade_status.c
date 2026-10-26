/*
 * file:     worldtrade_status.c
 * unit:     yes
 * function: WORLDTRADE_STATUS_Open, WORLDTRADE_STATUS_WaitIdle, WORLDTRADE_STATUS_Close
 * address:  0x021FF58C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from worldtrade_box.c, worldtrade_enter.c, worldtrade_adapter.c, WORLDTRADE_ADAPTER_QueueMessagePrint.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Free 0x020307B0 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   GFL_HEAP_Alloc 0x02030734 arm
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   PROCSYS_Push  0x02031348  arm
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   WORLDTRADE_ClearAndShowPlanes  0x021F5074  thumb  ov135
 *   WORLDTRADE_AdvanceScreenId  0x021F4EC8  thumb  ov135
 *   WORLDTRADE_SetStateAndReturn  0x021F4EC0  thumb
 *   WORLDTRADE_BOX_IsPartyBox 0x021F6B34 thumb ov135
 *   WORLDTRADE_BOX_GetMonCount 0x021F6B80 thumb ov135
 *   WORLDTRADE_BOX_GetPartyMon 0x021F6B40 thumb ov135
 *   str_02203E30 0x02203E30 data a1
 *   gPokeStatusProcData 0x021DC800 data ov131 a4
 *   ov131_id       0x00000083  data
 */
#include "worldtrade_types.h"

#include "../arm9/mi_memory.h"

#include "../arm9/gfl_heap_wrap.h"

struct GameSystem;
struct GameData;

#include "../arm9/gamesystem.h"

#include "worldtrade.h"





#include "worldtrade_box.h"



#include "../arm9/procsys.h"

int WORLDTRADE_STATUS_Open(WorldtradeWork *p);

u32 WORLDTRADE_STATUS_WaitIdle(WorldtradeWork *p);

u32 WORLDTRADE_STATUS_Close(WorldtradeWork *p);

extern const char str_02203E30[], ov131_id[];

extern const struct ProcData gPokeStatusProcData;

int WORLDTRADE_STATUS_Open(WorldtradeWork *p)
{
    PokeStatusRequest *r;
    WORLDTRADE_ExitPlanes(p);
    p->statusReq=GFL_HEAP_Alloc(0x48,sizeof(PokeStatusRequest),0,str_02203E30,0x4C);
    MI_CpuFill8(p->statusReq,0,sizeof(PokeStatusRequest));
    r=p->statusReq;
    r->config=p->ctx->statusConfig;
    r->save=GAMESYSTEM_GetGameData(p->ctx->gameData);
    if(WORLDTRADE_BOX_IsPartyBox(p->box))
        r->slotCount=WORLDTRADE_BOX_GetMonCount(p->ctx->party,p->ctx->save,p->box);
    else r->slotCount=30;
    r->slot=p->slot;
    r->enabled=1;
    r->page=0;
    r->mode=0;
    r->nationalDexEnabled=p->ctx->nationalDexEnabled;
    r->result=0;
    if(WORLDTRADE_BOX_IsPartyBox(p->box)) {
        r->mon=p->ctx->party;
        r->type=1;
    } else {
        r->mon=WORLDTRADE_BOX_GetPartyMon(p->ctx->party,p->ctx->save,p->box,0);
        r->type=2;
    }
    PROCSYS_Push(p->procSys,(uptr)ov131_id,&gPokeStatusProcData,r);
    p->subLcdRefresh=1;
    return 1;
}

/*
 * Answer 2, or set the 5/mode pair and answer 3 when the +0x12f4 word is clear.
 */
u32 WORLDTRADE_STATUS_WaitIdle(WorldtradeWork *p)
{
    u32 r = 2;

    if (p->busy_u == 0) {
        WORLDTRADE_SetStateAndReturn(p, 5, p->kind);
        r = 3;
    }
    return r;
}

u32 WORLDTRADE_STATUS_Close(WorldtradeWork *p)
{
    PokeStatusRequest *q = p->statusReq;

    p->slot = q->slot;
    GFL_HEAP_Free(q);
    WORLDTRADE_ClearAndShowPlanes(p);
    WORLDTRADE_AdvanceScreenId(p);
    return 0;
}
