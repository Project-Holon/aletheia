/*
 * function: BR_CODEIN_CodeSetMenuText
 * address: 0x021E03B0
 * packet: pkt_ov183_021E03B0
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_OAM_GetRecordValue 0x02025B64 thumb
 *   WORDSET_SetSlotFromMsgE7 0x0201F048 thumb
 *   WORDSET_DeleteMsgdataF094 0x0201F094 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   gSpeciesNameBank 0x020A7370 data a4
 */
#include "../include/Obj00277.h"
#include "../include/Obj00351.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int gSpeciesNameBank;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetWordSet(char *);
extern void BR_UTIL_SetTextFromMessage(char *,void *,void *,void *,u16);
extern void BR_UTIL_SetTextFromBuffer(char *,void *,void *,u16);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern u8 BMP_OAM_GetRecordValue(u32);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern void WORDSET_DeleteMsgdataF094(struct WordSet *p, u32 i, u32 a, u32 n);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
void BR_CODEIN_CodeSetMenuText(char *p,char *q,int mode)
{
    int first,second,ws;
    void *data,*text;
    first=BR_RES_GetFont(*(char * *)&((struct Obj00351 *)q)->f8);
    second=BR_RES_GetMsgData(*(char * *)&((struct Obj00351 *)q)->f8);
    switch(mode) {
    case 0:
        if(((struct Obj00351 *)q)->f18!=19)BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)(((struct Obj00351 *)q)->f18+205),(void *)first,0x3da0);
        else BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00277 *)p)->f24,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 1:
        if(((struct Obj00351 *)q)->f14!=0xffff)BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)gSpeciesNameBank,(void *)(u32)((struct Obj00351 *)q)->f14,(void *)first,0x3da0);
        else BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00277 *)p)->f2C,(void *)second,(void *)117,(void *)first,0x3da0);
        return;
    case 2:
        if(((struct Obj00351 *)q)->f16==255 && ((struct Obj00351 *)q)->f17==255) {
            BR_UTIL_SetTextFromMessage(*(char * *)&((struct Obj00277 *)p)->f34,(void *)second,(void *)117,(void *)first,0x3da0);
            return;
        }
        ws=BR_RES_GetWordSet(*(char * *)&((struct Obj00351 *)q)->f8);
        data=func_02045EC0((void *)second,24);
        text=STRBUF_Create(128,((struct Obj00277 *)p)->f54);
        if(!BMP_OAM_GetRecordValue(((struct Obj00351 *)q)->f16))WORDSET_SetSlotFromMsgE7((void *)ws,0,((struct Obj00351 *)q)->f16);
        else WORDSET_DeleteMsgdataF094((void *)ws,0,((struct Obj00351 *)q)->f16,((struct Obj00351 *)q)->f17);
        WORDSET_CopyTaggedText((void *)ws,text,data);
        BR_UTIL_SetTextFromBuffer(*(char * *)&((struct Obj00277 *)p)->f34,text,(void *)first,0x3da0);
        STRBUF_Delete(data);STRBUF_Delete(text);
        break;
    }
}
