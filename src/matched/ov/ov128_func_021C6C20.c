/*
 * function: Wf2dmapFriend_PrintTrainerStats
 * address: 0x021C6C20
 * packet: pkt_ov128_021C6C20
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GAME_DATA_GetWifiList 0x0201283C thumb
 *   func_02009864 0x02009864 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 */
#include "../include/Obj10483.h"
#include "../include/Obj23069.h"
typedef unsigned char u8;
struct BigObj;
extern unsigned int GAME_DATA_GetWifiList(const struct BigObj *p);
typedef unsigned int   u32;
struct Sub020097BCObj;
struct WordSet;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
int Wf2dmapFriend_PrintTrainerStats(u8 *p,u8 *q,int idx)
{
    void *base;
    unsigned v;
    int result;
    base=(void *)GAME_DATA_GetWifiList(((struct Obj23069 *)q)->f4);
    result=1;
    v=func_02009864(base,idx,7);
    if(v==0) result=0;
    WORDSET_SetSlotNumber(((struct Obj10483 *)p)->f0,2,v,2,0,1);
    v=func_02009864(base,idx,5);
    WORDSET_SetSlotNumber(((struct Obj10483 *)p)->f0,0,v,4,1,1);
    v=func_02009864(base,idx,6);
    WORDSET_SetSlotNumber(((struct Obj10483 *)p)->f0,1,v,2,0,1);
    return result;
}
