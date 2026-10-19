/*
 * function: BEACON_DETAIL_GRA_SetupSlot
 * address: 0x021BD174
 * packet: pkt_ov216_021BD174
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * checks: 1 ABI rederived from matched bodies/callers; C58 remains wide because caller truncates to u16. 2 no twin. 3 prior enum/const trials exhausted; 4 far-offset-before-index modular integer address formation rescues MATCH*722; 5 current idioms/neighbours read. Six authorized ov010 leaves EXACT with adjacent TU audits; prior once300 not repeated.
 * tail: 2B zero alignment at 021BD446..021BD448.
 * symbols:
 *   GAME_BEACON_ACCESSOR_GetFavoriteColorRgb 0x02165CC0 thumb ov010
 *   PALANM_BlendColors 0x02021F64 thumb
 *   BEACON_DETAIL_GRA_LoadPalette 0x021BCD08 thumb ov216
 *   BEACON_DETAIL_GRA_GetPmVersionClass 0x021BCDC0 thumb ov216
 *   GAME_BEACON_ACCESSOR_GetPlayerName 0x02165C34 thumb ov010
 *   BEACON_DETAIL_GRA_DrawWindowRecord 0x021BD07C thumb ov216
 *   GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond 0x02165C60 thumb ov010
 *   STRBUF_Clear 0x0204581C arm
 *   WORDSET_SetSlotFromMsg38 0x0201F1C8 thumb
 *   BEACON_DETAIL_GRA_PrintMsg 0x021BCEA4 thumb ov216
 *   GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst 0x02165C78 thumb ov010
 *   WORDSET_SetSlotFromMsg2B 0x0201F198 thumb
 *   GAME_BEACON_ACCESSOR_GetPlayTime 0x02165D10 thumb ov010
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   GAME_BEACON_ACCESSOR_GetNation 0x02165C58 thumb ov010
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   GAME_BEACON_ACCESSOR_GetArea 0x02165C5C thumb ov010
 *   WORDSET_SetSlotFromKeyedMessage 0x0201F094 thumb
 *   GAME_BEACON_ACCESSOR_GetPassCount 0x02165D40 thumb ov010
 *   GAME_BEACON_ACCESSOR_GetThanksCount 0x02165D48 thumb ov010
 *   PMS_DRAW_IsActive 0x0202DCC4 thumb
 *   PMS_DRAW_Clear 0x0202DC9C thumb
 *   GAME_BEACON_ACCESSOR_GetDetailsPms 0x02165C90 thumb ov010
 *   PMS_DRAW_Print 0x0202DC48 thumb
 *   GAME_BEACON_ACCESSOR_GetTrainerAppearance 0x02165CE8 thumb ov010
 *   CURSOR_MOVE_GetTableGroup 0x02025C88 thumb
 *   POKEGRA_LoadTrainerGraphics 0x0202DAA4 thumb
 *   GAME_BEACON_ACCESSOR_GetResearchTeamRank 0x02165CB4 thumb ov010
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   BEACON_DETAIL_GRA_SetActorAnim 0x021BCE7C thumb ov216
 */
#include "../include/Obj00051.h"
#include "../include/Obj05555.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
enum Index { IndexZero=0 };
struct Pair { u16 a,b; };
struct Quad { u16 a,b,c,d; };
struct Rgb555 { u16 r:5,g:5,b:5,pad:1; };
struct WordSet; struct U16Vec; struct Obj; struct Rec; struct S;
struct Obj0202DCC4; struct Obj0202DC98;
extern void GAME_BEACON_ACCESSOR_GetFavoriteColorRgb(int a0, int a1);
extern void PALANM_BlendColors(u16 *,u16 *,u32,int,u16);
extern void BEACON_DETAIL_GRA_LoadPalette(void *p, unsigned mode, unsigned a, unsigned b);
extern int BEACON_DETAIL_GRA_GetPmVersionClass(void *);
extern void GAME_BEACON_ACCESSOR_GetPlayerName(struct Rec *,void *);
extern void BEACON_DETAIL_GRA_DrawWindowRecord(void *,void **,int,short,u8,u8,u8,u8);
extern int GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond(int a0);
extern void STRBUF_Clear(struct U16Vec *);
extern void WORDSET_SetSlotFromMsg38(struct WordSet *,u32,u32);
extern void BEACON_DETAIL_GRA_PrintMsg(u8 *p, u8 n);
extern int GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst(int a0);
extern void WORDSET_SetSlotFromMsg2B(struct WordSet *,u32,u32);
struct R;
extern void GAME_BEACON_ACCESSOR_GetPlayTime(const struct S *p, u16 *a, u16 *b);
extern void WORDSET_SetSlotNumber(struct WordSet *,u32,u32,u32,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetNation(const u8 *p);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetArea(const u8 *p);
extern void WORDSET_SetSlotFromKeyedMessage(struct WordSet *,u32,u32,u32);
extern u32 GAME_BEACON_ACCESSOR_GetPassCount(const struct S *p);
extern u32 GAME_BEACON_ACCESSOR_GetThanksCount(const struct S *p);
extern u32 PMS_DRAW_IsActive(const struct Obj0202DCC4 *,u32);
extern void PMS_DRAW_Clear(struct Obj0202DC98 *,int,u32);
extern void GAME_BEACON_ACCESSOR_GetDetailsPms(const struct R *p, struct Quad *q);
extern void PMS_DRAW_Print(u32,u32,u32,u32);
extern u8 GAME_BEACON_ACCESSOR_GetTrainerAppearance(struct S *);
extern u32 CURSOR_MOVE_GetTableGroup(u32);
extern void POKEGRA_LoadTrainerGraphics(void *set, u32 id, void *dstA, void *dstB, volatile u16 which);
extern u8 GAME_BEACON_ACCESSOR_GetResearchTeamRank(void *);
extern void CLACT_SetActorDrawEnable(struct Obj *,u32);
extern void BEACON_DETAIL_GRA_SetActorAnim(void *p, unsigned short value);
void BEACON_DETAIL_GRA_SetupSlot(char *p,void *record,u16 unused,u8 slot)
{
    struct Pair colors;
    struct Quad data;
    struct Pair counts;
    char *q=(char *)p+0x15c+slot*128;
    u32 subtype;
    u16 value;
    int position;
    int index;
    GAME_BEACON_ACCESSOR_GetFavoriteColorRgb((int)(&colors.a),(int)record);
    PALANM_BlendColors(&colors.a,&colors.b,1,3,0);
    position=slot*16;
    BEACON_DETAIL_GRA_LoadPalette(&colors,1,(u16)(position+1),2);
    BEACON_DETAIL_GRA_LoadPalette(*(char * *)&((struct Obj00051 *)p)->f11C+BEACON_DETAIL_GRA_GetPmVersionClass(record)*32,1,(u16)(position+10),2);
    GAME_BEACON_ACCESSOR_GetPlayerName(record,((struct Obj00051 *)p)->f13C);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)q,*(int *)&((struct Obj00051 *)p)->f13C,6,48,13,2,0);
    subtype=GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerSecond((int)record);
    if(subtype==255) STRBUF_Clear(*(struct U16Vec * *)&((struct Obj00051 *)p)->f140);
    else {WORDSET_SetSlotFromMsg38(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,subtype);BEACON_DETAIL_GRA_PrintMsg((u8 *)p,5);}
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+16),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,1);
    subtype=GAME_BEACON_ACCESSOR_GetQuestionnaireAnswerFirst((int)record);
    if(subtype==255) STRBUF_Clear(*(struct U16Vec * *)&((struct Obj00051 *)p)->f140);
    else {WORDSET_SetSlotFromMsg2B(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,subtype);BEACON_DETAIL_GRA_PrintMsg((u8 *)p,4);}
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+32),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,0);
    GAME_BEACON_ACCESSOR_GetPlayTime(record,&counts.b,&counts.a);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,2,counts.b,3,0,1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,3,counts.a,2,2,1);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,6);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+48),*(int *)&((struct Obj00051 *)p)->f140,6,48,13,2,1);
    value=(unsigned)GAME_BEACON_ACCESSOR_GetNation(record);
    WORDSET_SetSlotFromMsgE7(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,value);
    WORDSET_SetSlotFromKeyedMessage(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,value,GAME_BEACON_ACCESSOR_GetArea(record));
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,8);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+80),*(int *)&((struct Obj00051 *)p)->f140,0,0,28,4,0);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,0,GAME_BEACON_ACCESSOR_GetPassCount(record),5,1,1);
    WORDSET_SetSlotNumber(*(struct WordSet * *)&((struct Obj00051 *)p)->f138,1,GAME_BEACON_ACCESSOR_GetThanksCount(record),5,1,1);
    BEACON_DETAIL_GRA_PrintMsg((u8 *)p,10);
    BEACON_DETAIL_GRA_DrawWindowRecord((char *)p,(void **)(q+96),*(int *)&((struct Obj00051 *)p)->f140,21,0,6,4,0);
    if(PMS_DRAW_IsActive(*(struct Obj0202DCC4 * *)&((struct Obj00051 *)p)->f158,slot)!=0) PMS_DRAW_Clear(*(struct Obj0202DC98 * *)&((struct Obj00051 *)p)->f158,slot,1);
    GAME_BEACON_ACCESSOR_GetDetailsPms(record,&data);
    PMS_DRAW_Print(*(u32 *)&((struct Obj00051 *)p)->f158,((struct Obj05555 *)q)->f70,(u32)&data,slot);
    ((struct Obj05555 *)q)->f7C=GAME_BEACON_ACCESSOR_GetTrainerAppearance(record);
    index=slot*12;
    POKEGRA_LoadTrainerGraphics(((struct Obj00051 *)p)->f58,CURSOR_MOVE_GetTableGroup(((struct Obj05555 *)q)->f7C),*(void **)((u32)p+0x6c+(u32)index),*(void **)((u32)p+0x68+(u32)index),((struct Obj00051 *)p)->f2);
    subtype=GAME_BEACON_ACCESSOR_GetResearchTeamRank(record);
    if(subtype==0) {CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj05555 *)q)->f74,0);return;}
    BEACON_DETAIL_GRA_SetActorAnim(((struct Obj05555 *)q)->f74,(u8)(subtype+1));
    CLACT_SetActorDrawEnable(*(struct Obj * *)&((struct Obj05555 *)q)->f74,1);
}
