/*
 * function: WORLDTRADE_ADAPTER_RegisterReceivedMonB
 * address: 0x022023A4
 * packet: pkt_ov135_022023A4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * evidence: ZUKAN_SAVE_RegisterCaught receives the entry r1 Pokemon pointer; fifth parameter is reassigned in its incoming stack slot.
 * symbols:
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   POKE_TOOL_CalcGender 0x02017F50 thumb
 *   POKEPARTY_Add 0x0201A98C thumb
 *   WORLDTRADE_ADAPTER_GetBoxParam 0x022026BC thumb ov135
 *   WORLDTRADE_ADAPTER_StoreDateAsLastId 0x0220246C thumb ov135
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb  arm9
 */
#include "../include/Obj02864.h"
#include "../include/Obj23476.h"
#include "../include/Obj23477.h"
#include "../include/Obj23478.h"
#include "../include/Obj23479.h"
#include "../include/Obj23480.h"
#include "../include/Obj23481.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Blk37;
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *, void *);
extern u32 POKEPARTY_GetCount(void *p);
extern void POKE_TOOL_SetPartyValue(void *,u32,u32);
extern u32 POKE_TOOL_GetPartyValue(void *,u32,u32);
extern u8 POKE_TOOL_CalcGender(u32 a, u16 b, u32 c);
struct Party;
struct PartyMon;
extern u32 POKEPARTY_Add(struct Party *,const struct PartyMon *);
extern int func_020076D0(void *save, int *pbox, int *pslot);
struct Sub02007454Entry;
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern u32 WORLDTRADE_ADAPTER_GetBoxParam(void *);
extern void WORLDTRADE_ADAPTER_StoreDateAsLastId(void *,int);
void WORLDTRADE_ADAPTER_RegisterReceivedMonB(u8 *p,void *mon,void *unused2,void *unused3,u32 index)
{
    u32 species, form, pos;
    ZUKAN_SAVE_RegisterCaught(*(struct Blk37 * *)&((struct Obj23476 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f10,mon);
    index=0xFF;
    if(POKEPARTY_GetCount(((struct Obj23477 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8)==6) index=0;
    POKE_TOOL_SetPartyValue(mon,9,0x46);
    species=POKE_TOOL_GetPartyValue(mon,5,0);
    form=POKE_TOOL_GetPartyValue(mon,0x6F,0);
    POKE_TOOL_SetPartyValue(mon,0x6E,POKE_TOOL_CalcGender((u16)species,form,POKE_TOOL_GetPartyValue(mon,0,0)));
    if(index==0xFF) {
        POKEPARTY_Add(*(struct Party * *)&((struct Obj23478 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8,(const struct PartyMon *)mon);
        pos=POKEPARTY_GetCount(((struct Obj23479 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8);
        ((struct Obj02864 *)p)->fDC=0xFF;
        pos--;
    } else {
        u32 slot=0;
        func_020076D0(((struct Obj23480 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->fC,(int *)(&index),(int *)(&slot));
        func_0200752C(((struct Obj23481 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->fC,index,(const struct Sub02007454Entry *)WORLDTRADE_ADAPTER_GetBoxParam(mon));
        ((struct Obj02864 *)p)->fDC=index;
        pos=slot;
    }
    ((struct Obj02864 *)p)->fE0=pos;
    WORLDTRADE_ADAPTER_StoreDateAsLastId(*(void **)*(u8 * *)&((struct Obj02864 *)p)->f0,1);
}
