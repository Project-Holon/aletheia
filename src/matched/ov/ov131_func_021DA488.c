/*
 * function: P_STA_SKILL_PrintMoveDetail
 * address: 0x021DA488
 * packet: pkt_ov131_021DA488
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA6A2.
 * semantics: C1E8 forwards BD28(a,2); BDB4 case 2 at 0201BE0C
 * returns ldrb, bounding kind to 0..255 and (kind+16)*4 to 1084.
 * AB84 copies all 36 output bytes at 0204AB9C..0204ABB0 before B784
 * reads them. Other scalar arithmetic uses u8 indices or constants.
 * symbols:
 *   WAZA_TOOL_GetDamageType 0x0201C1E8 thumb
 *   APP_ICON_GetMoveKindPaletteOffset 0x02027604 thumb
 *   P_STATUS_GetPokePara 0x021D6064 thumb ov131
 *   P_STATUS_PrintMsgToWin 0x021D618C thumb ov131
 *   P_STATUS_PrintWordSetMsgToWin 0x021D6214 thumb ov131
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   CLACT_GetCharacterProxy 0x0204AB84 arm
 *   CLACT_SetActorImageProxy 0x0204B784 arm
 *   CLACT_SetActorPaletteOffset 0x0204B6F4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   WAZA_TOOL_GetPower  0x0201C1D8  thumb  arm9
 *   WAZA_TOOL_IsAlwaysHit  0x0201C1F4  thumb  arm9
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb  arm9
 *   WAZA_TOOL_GetParam  0x0201BD28  thumb  arm9
 *   WORDSET_CreateDefault  0x0201EC64  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb  arm9
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb  arm9
 */
#include "../include/Obj01408.h"
#include "../include/Obj04513.h"
#include "../include/Obj23163.h"
#include "../include/Obj23164.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u32 w[9]; } Record;
extern void *P_STATUS_GetPokePara(u8 *);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj;
struct Rec;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern void P_STATUS_PrintMsgToWin(unsigned char *p, unsigned int a, int b, int c, unsigned short d, unsigned short e);
extern void P_STATUS_PrintWordSetMsgToWin(unsigned char *p, unsigned int a, void *b, int c, unsigned short d, unsigned short e, unsigned short f);
struct Struct36;
extern int WAZA_TOOL_GetDamageType(int a);
extern void CLACT_GetCharacterProxy(u32 idx, struct Rec *dst);
extern void CLACT_SetActorImageProxy(char *dst, const struct Struct36 *src);
extern u8 APP_ICON_GetMoveKindPaletteOffset(u8);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);
extern u32 WAZA_TOOL_GetPower(u16);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 WAZA_TOOL_GetParam(u16,u32);
extern u32 WAZA_TOOL_IsAlwaysHit(u16 id);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 MSGDATA_Delete(struct Rec *rec);
void P_STA_SKILL_PrintMoveDetail(u8 *a,u8 *p)
{
    void *data,*object1,*object2,*table,*str;
    u8 i;
    int zero,one,id,kind;
    u32 count,value;
    Record record;
    data=P_STATUS_GetPokePara(a);
    zero=0;
    for(i=8;i<=11;i++) BMP_Clear(BMP_WIN_GetBmp(*(void **)(p+0x5c+i*4)),zero);
    if(p[41]<4) id=POKE_TOOL_GetBoxValue(data,p[41]+54,zero);
    else if(p[41]==255) {
        if((*(u8 **)(a+8))[13]==2 && p[43]==5) id=((struct Obj23163 *)(*(u8 * *)&((struct Obj04513 *)a)->f8))->f14;
        else id=POKE_TOOL_GetBoxValue(data,54,0);
    } else id=((struct Obj23164 *)(*(u8 * *)&((struct Obj04513 *)a)->f8))->f14;
    one=1;
    P_STATUS_PrintMsgToWin(a,(unsigned int)(((struct Obj01408 *)p)->f7C),149,1,one,15424);
    kind=WAZA_TOOL_GetDamageType((u16)id);
    CLACT_GetCharacterProxy(*(u32 *)(a+(kind+16)*4+152),(struct Rec *)(&record));
    CLACT_SetActorImageProxy(((struct Obj01408 *)p)->f94,(const struct Struct36 *)(&record));
    CLACT_SetActorPaletteOffset(((struct Obj01408 *)p)->f94,APP_ICON_GetMoveKindPaletteOffset(kind),1);
    P_STATUS_PrintMsgToWin(a,(unsigned int)(((struct Obj01408 *)p)->f80),147,1,one,15424);
    count=WAZA_TOOL_GetPower(id);
    if(count<=1) P_STATUS_PrintMsgToWin(a,(unsigned int)(((struct Obj01408 *)p)->f80),154,87,one,1088);
    else {
        object1=WORDSET_CreateDefault(((struct Obj04513 *)a)->f0);
        WORDSET_SetSlotNumber(object1,0,count,3,one,one);
        P_STATUS_PrintWordSetMsgToWin(a,(unsigned int)(((struct Obj01408 *)p)->f80),object1,150,81,one,1088);
        WORDSET_Delete(object1);
    }
    P_STATUS_PrintMsgToWin(a,(unsigned int)(((struct Obj01408 *)p)->f84),148,1,1,15424);
    value=WAZA_TOOL_GetParam(id,4);
    if(WAZA_TOOL_IsAlwaysHit(id)==1 || value==0) P_STATUS_PrintMsgToWin(a,(unsigned int)(((struct Obj01408 *)p)->f84),154,87,1,1088);
    else {
        object2=WORDSET_CreateDefault(((struct Obj04513 *)a)->f0);
        WORDSET_SetSlotNumber(object2,0,value,3,1,1);
        P_STATUS_PrintWordSetMsgToWin(a,(unsigned int)(((struct Obj01408 *)p)->f84),object2,151,81,1,1088);
        WORDSET_Delete(object2);
    }
    table=func_02045B38(0,2,202,((struct Obj04513 *)a)->f0);
    str=func_02045EC0(table,id);
    PRINTSYS_PrintQueColor(((struct Obj04513 *)a)->f84,(int)BMP_WIN_GetBmp(((struct Obj01408 *)p)->f88),1,1,(u32)str,((struct Obj04513 *)a)->f80,1088);
    STRBUF_Delete(str);
    MSGDATA_Delete(table);
    ((struct Obj01408 *)p)->fC=0;
    ((struct Obj01408 *)p)->f8=1;
}
