/*
 * function: IRC_RESULT_PrintRewardMessage
 * address: 0x021B8008
 * packet: pkt_ov105_021B8008
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 closed: the flag zero is written after the WORDSET_SetSlotMyStatus call (flag=0 after b+=12 call), not before it. Plain int flag, no Context struct.
 * symbols:
 *   IRC_RESULT_GetFont 0x021B7CA0 thumb ov105
 *   IRC_RESULT_GetPrintQueue 0x021B7CA4 thumb ov105
 *   IRC_RESULT_GetMessages 0x021B7CA8 thumb ov105
 *   IRC_RESULT_GetWordSet 0x021B7CAC thumb ov105
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   WORDSET_SetSlotFromBank 0x0201EF6C thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { void *descriptor,*window; u8 active,pad[3]; void *buffer; u16 color; } Window;
extern int IRC_RESULT_GetFont(void *);
extern int IRC_RESULT_GetPrintQueue(void *);
extern int IRC_RESULT_GetMessages(void *);
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct PrintSys;
struct U16Vec;
struct WordSet;
extern int IRC_RESULT_GetWordSet(void *p);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void WORDSET_SetSlotFromBank(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
void IRC_RESULT_PrintRewardMessage(Window *p, void *a, u8 *b, unsigned c, int d)
{
 void *msg; int bank; void *text; int font; int tag; int flag;
 BMP_Clear(BMP_WIN_GetBmp(p->descriptor),p->color);
 msg=(void *)IRC_RESULT_GetWordSet(a);
 bank=IRC_RESULT_GetMessages(a);
 b+=12; WORDSET_SetSlotMyStatus(msg,0,b); flag=0;
 if(c>1) flag=1;
 WORDSET_SetSlotFromBank(msg,1,134,flag,0); WORDSET_SetSlotNumber(msg,2,c,1,0,1);
 text=func_02045EC0((void *)bank,d);
 WORDSET_CopyTaggedText(msg,p->buffer,text); STRBUF_Delete(text);
 font=IRC_RESULT_GetPrintQueue(a); tag=IRC_RESULT_GetFont(a);
 PRINTSYS_PrintQue((struct PrintSys *)font,(u32)BMP_WIN_GetBmp(p->window),0,0,p->buffer,tag);
 p->active=1;
}
