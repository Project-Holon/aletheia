/*
 * function: B_PLIST_MAIN_GetRowStatus
 * address: 0x02210DA8
 * packet: pkt_ov198_02210DA8
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing 02210E1E halfword is zero alignment padding.
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_MAIN_IsBattleSlot 0x02210F04 thumb ov198
 *   B_PLIST_MAIN_IsSlotSelectable 0x02210F4C thumb ov198
 *   B_PLIST_MAIN_IsRowFlagged 0x02210ED4 thumb ov198
 *   B_PLIST_MAIN_IsIndexInParty 0x02210F98 thumb ov198
 */
#include "../include/Obj10852.h"
#include "../include/Obj25270.h"
#include "../include/Obj25271.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *,int);
extern u32 B_PLIST_MAIN_IsBattleSlot(u32,u32);
extern int B_PLIST_MAIN_IsSlotSelectable(u8 *,int);
extern u8 B_PLIST_MAIN_IsRowFlagged(u8 *);
extern unsigned B_PLIST_MAIN_IsIndexInParty(u8 *p, int index);
int B_PLIST_MAIN_GetRowStatus(u8 *p)
{
    int index=B_PLIST_MAIN_GetOrderIndex(p,(*(u8 **)p)[32]);
    u8 *q=p+4+76*index;
    if(B_PLIST_MAIN_IsBattleSlot((u32)p,index)==1) return 1;
    if(((struct Obj25270 *)q)->f10==0) return 2;
    if(B_PLIST_MAIN_IsSlotSelectable(p,(*(u8 **)p)[32])==1) return 3;
    if(B_PLIST_MAIN_IsRowFlagged(p)==1) return 5;
    if(B_PLIST_MAIN_IsIndexInParty(p,(*(u8 **)p)[32])==1) return 4;
    if(((struct Obj25271 *)(*(u8 * *)&((struct Obj10852 *)p)->f0))->f26!=0) return 6;
    return 0;
}
