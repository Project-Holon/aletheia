/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName
 * address: 0x021B824C
 * packet: pkt_ov103_021B824C
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 2-byte zero padding before the next labelled function.
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData 0x021B8004 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue 0x021B8000 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_TextGetFont 0x021B7FFC thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet 0x021B8008 thumb ov103
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj02159.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(void *);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *); extern void BMP_Clear(int,u8); extern void MSGDATA_ReadString(int,int,int); extern void PRINTSYS_QUE_Clear(int); extern void PRINTSYS_PrintQue(int,int,s16,s16,int,int);
typedef unsigned int   u32;
struct WordSet;
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a); extern int func_02045EC0(int,int); extern void WORDSET_CopyTaggedText(int,int,int); extern void STRBUF_Delete(int);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageWithName(u8 *p,void *q,int c,u8 *x,s16 y,s16 z,int k) {int a,b,d,e; BMP_Clear((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02159 *)p)->f0),((struct Obj02159 *)p)->f10); a=IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(q); b=IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(q); WORDSET_SetSlotMyStatus((struct WordSet *)a,0,x+12); e=func_02045EC0(b,c); WORDSET_CopyTaggedText(a,((struct Obj02159 *)p)->fC,e); STRBUF_Delete(e); b=IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(q); d=IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(q); PRINTSYS_QUE_Clear(b); PRINTSYS_PrintQue(b,(int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02159 *)p)->f4),y,z,((struct Obj02159 *)p)->fC,d); p[8]=1; }
