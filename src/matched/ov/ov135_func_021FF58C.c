/*
 * function: WORLDTRADE_STATUS_Open
 * address: 0x021FF58C
 * packet: pkt_ov135_021FF58C
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WORLDTRADE_ExitPlanes 0x021F50EC thumb ov135
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   ICA_ANIME_GetField1C 0x020120F4 thumb
 *   WORLDTRADE_BOX_ClampSlot 0x021F6B34 thumb ov135
 *   WORLDTRADE_BOX_GetMonCount 0x021F6B80 thumb ov135
 *   WORLDTRADE_BOX_GetPartyMon 0x021F6B40 thumb ov135
 *   PROCSYS_Push 0x02031348 arm
 *   str_02203E30 0x02203E30 data a1
 *   gPokeStatusProcData 0x021DC800 data ov131 a4
 *   ov131_id 0x83 data
 */
#include "../include/Obj01162.h"
#include "../include/Obj23428.h"
#include "../include/Obj23429.h"
#include "../include/Obj23430.h"
#include "../include/Obj23431.h"
#include "../include/Obj23432.h"
#include "../include/Obj23433.h"
#include "../include/Obj23434.h"
#include "../include/Obj23435.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    void *mon, *ctx, *save;
    u8 type, fD, fE, fF, f10, pad11[3];
    u16 f14, pad16;
    void *f18;
    u32 f1C, f20, f24;
} Request;
extern const char str_02203E30[], ov131_id[];
extern const u32 gPokeStatusProcData[];
extern void WORLDTRADE_ExitPlanes(u8 *);
struct Ctx;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *,u32,u32);
extern void *ICA_ANIME_GetField1C(const struct Ctx *p);
extern int WORLDTRADE_BOX_ClampSlot(int);
extern u32 WORLDTRADE_BOX_GetMonCount(u8 *p, u32 b, u32 c);
extern void *WORLDTRADE_BOX_GetPartyMon(void *,void *,int,int);
extern void PROCSYS_Push(void *,u32,const void *,void *);
void WORLDTRADE_STATUS_Open(u8 *p)
{
    Request *r;
    WORLDTRADE_ExitPlanes(p);
    *(Request * *)&((struct Obj01162 *)p)->f10DC=func_02030734(0x48,sizeof(Request),0,str_02203E30,0x4C);
    MI_CpuFill8(*(Request * *)&((struct Obj01162 *)p)->f10DC,0,sizeof(Request));
    r=*(Request * *)&((struct Obj01162 *)p)->f10DC;
    r->ctx=((struct Obj23428 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f20;
    r->save=ICA_ANIME_GetField1C(((struct Obj23429 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f40);
    if(WORLDTRADE_BOX_ClampSlot(((struct Obj01162 *)p)->fC4))
        r->fE=WORLDTRADE_BOX_GetMonCount(((struct Obj23430 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8,(u32)(((struct Obj23431 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->fC),((struct Obj01162 *)p)->fC4);
    else r->fE=30;
    r->fF=((struct Obj01162 *)p)->fC6;
    r->fD=1;
    r->f14=0;
    r->f10=0;
    r->f18=((struct Obj23432 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f2C;
    r->f20=0;
    if(WORLDTRADE_BOX_ClampSlot(((struct Obj01162 *)p)->fC4)) {
        r->mon=((struct Obj23433 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8;
        r->type=1;
    } else {
        r->mon=WORLDTRADE_BOX_GetPartyMon(((struct Obj23434 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->f8,((struct Obj23435 *)(*(u8 * *)&((struct Obj01162 *)p)->f0))->fC,((struct Obj01162 *)p)->fC4,0);
        r->type=2;
    }
    PROCSYS_Push(((struct Obj01162 *)p)->f12F0,(u32)ov131_id,gPokeStatusProcData,r);
    ((struct Obj01162 *)p)->fB8=1;
}
