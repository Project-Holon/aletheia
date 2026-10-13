/*
 * function: PLIST_MENU_StartItemUse
 * address: 0x021BC350
 * packet: pkt_ov091_021BC350
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PLIST_MENU_GetItemUseKind 0x021BBE74 thumb ov091
 *   PLIST_PLATE_GetHp 0x021BB464 thumb ov091
 *   POKE_TOOL_CalcLevel 0x02018430 thumb
 *   PLIST_MESSAGE_CreateWordSet 0x021BB97C thumb ov091
 *   PLIST_MESSAGE_SetWordSetPokemon 0x021BB99C thumb ov091
 *   PLIST_MESSAGE_SetWordSetNumber 0x021BB9EC thumb ov091
 *   POKELIST_ShowMessage 0x021B9788 thumb ov091
 *   PLIST_MESSAGE_DestroyWordSet 0x021BB98C thumb ov091
 *   STRBUF_Create 0x020457B0 arm
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   GAME_BEACON_SetPokeLevelUp 0x02027268 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PLIST_MENU_HasMonParam 0x021BCC2C thumb ov091
 *   PLIST_MENU_ShowMonValueMessage 0x021BCC80 thumb ov091
 *   PLIST_MESSAGE_SetWordSetMove 0x021BB9CC thumb ov091
 *   PLIST_MENU_ShowMonMessage 0x021BCC40 thumb ov091
 *   PLIST_MENU_ShowItemResult 0x021BC5CC thumb ov091
 *   PLIST_MENU_OnLevelUpMessageDone 0x021BC6A0 thumb ov091
 *   PLIST_MENU_ShowHpRestored 0x021BC548 thumb ov091
 *   POKELIST_CheckItemUsable 0x021B9E44 thumb ov091
 *   gPlistStatParamIds 0x021BECE4 data ov091 a2
 */
#include "../include/Obj00009.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern int PLIST_MENU_GetItemUseKind(int);
struct U16Vec;
extern unsigned short PLIST_PLATE_GetHp(int unused, unsigned short *p);
extern unsigned int POKE_TOOL_CalcLevel(void *p);
extern void PLIST_MESSAGE_CreateWordSet(u8 *,int);
extern void PLIST_MESSAGE_SetWordSetPokemon(int a, int b, int c, int d);
extern void PLIST_MESSAGE_SetWordSetNumber(int a, int b, int c, int d, unsigned char e);
extern void POKELIST_ShowMessage(u8 *p, int a1, int a2, int a3);
typedef unsigned int   u32;
extern void PLIST_MESSAGE_DestroyWordSet(void *p, u32 s);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern void GAME_BEACON_SetPokeLevelUp(int);
extern void STRBUF_Delete(struct U16Vec *vec);
extern int PLIST_MENU_HasMonParam(void *p, int i, int a2);
extern void PLIST_MENU_ShowMonValueMessage(int p, int id, int v);
extern void PLIST_MESSAGE_SetWordSetMove(int a, int b, int c, int d);
extern void PLIST_MENU_ShowMonMessage(int p, int id);
extern void PLIST_MENU_ShowItemResult(int);
extern void PLIST_MENU_OnLevelUpMessageDone(char *p);
extern void PLIST_MENU_ShowHpRestored(int);
extern void POKELIST_CheckItemUsable(u8 *p);
extern u16 gPlistStatParamIds[];
#define W(k) (*(int *)(p+(k)))
#define H(k) (*(u16 *)(p+(k)))
int PLIST_MENU_StartItemUse(u8 *p,int v)
{
    int n=PLIST_MENU_GetItemUseKind(*(u16 *)(W(0x280)+0x44));
    int t;
    u8 i;
    u16 z;
    switch(n) {
    case 0:case 8:case 10:case 25:case 29:break;
    case 1:{
        int row=W(0x2c);
        ((struct Obj00009 *)p)->fC=10;
        H(0x11c)=PLIST_PLATE_GetHp((int)p,(short unsigned int *)(*(int *)(p+row*4+0x160)));
        W(0x120)=(int)PLIST_MENU_ShowItemResult;
        break;
    }
    case 2:
        t=(int)POKE_TOOL_CalcLevel((void *)W(0x38));
        PLIST_MESSAGE_CreateWordSet(p,(int)W(0x150));
        PLIST_MESSAGE_SetWordSetPokemon((int)p,W(0x150),0,W(0x38));
        PLIST_MESSAGE_SetWordSetNumber((int)p,W(0x150),1,(u16)(t+1),3);
        POKELIST_ShowMessage(p,0x9d,1,(int)PLIST_MENU_OnLevelUpMessageDone);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
        t=(int)STRBUF_Create(12,H(0));
        POKE_TOOL_GetPartyValue((void *)W(0x38),0x73,t);
        GAME_BEACON_SetPokeLevelUp(t);
        STRBUF_Delete((struct U16Vec *)t);
        for(i=0;i<6;i++) {
            int j=i*2;
            *(u16 *)(p+j+0x124)=POKE_TOOL_GetPartyValue((void *)W(0x38),*(u16 *)((u8 *)gPlistStatParamIds+j),0);
        }
        break;
    case 3:PLIST_MENU_ShowMonMessage((int)p,0x47);break;
    case 4:PLIST_MENU_ShowMonMessage((int)p,0x2d);break;
    case 5:PLIST_MENU_ShowMonMessage((int)p,0x2f);break;
    case 6:PLIST_MENU_ShowMonMessage((int)p,0x30);break;
    case 7:PLIST_MENU_ShowMonMessage((int)p,0x2e);break;
    case 9:PLIST_MENU_ShowMonMessage((int)p,0x33);break;
    case 11:case 12:{
        int row=W(0x2c);
        ((struct Obj00009 *)p)->fC=10;
        H(0x11c)=PLIST_PLATE_GetHp((int)p,(short unsigned int *)(*(int *)(p+row*4+0x160)));
        W(0x120)=(int)PLIST_MENU_ShowHpRestored;
        break;
    }
    case 13:case 14:case 15:case 16:case 17:case 18:
        PLIST_MENU_ShowMonValueMessage((int)p,0x37,(u16)(n-13));break;
    case 19:case 20:case 21:case 22:case 23:case 24:
        z=n-19;
        if(PLIST_MENU_HasMonParam((void *)W(0x38),z+13,*(u16 *)(W(0x280)+0x44))==0) PLIST_MENU_ShowMonValueMessage((int)p,0x55,z);
        else if(POKE_TOOL_GetPartyValue((void *)W(0x38),9,0)==255) PLIST_MENU_ShowMonValueMessage((int)p,0x54,z);
        else PLIST_MENU_ShowMonValueMessage((int)p,0x53,z);
        break;
    case 26:case 27:
        PLIST_MESSAGE_CreateWordSet(p,(int)W(0x150));
        PLIST_MESSAGE_SetWordSetMove((int)p,W(0x150),0,(u16)v);
        POKELIST_ShowMessage(p,0x34,1,(int)POKELIST_CheckItemUsable);
        PLIST_MESSAGE_DestroyWordSet(p,W(0x150));
        break;
    case 28:PLIST_MENU_ShowMonMessage((int)p,0x31);break;
    }
    return n;
}
