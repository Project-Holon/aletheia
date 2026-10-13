/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_PrintMessage
 * address: 0x021B8138
 * packet: pkt_ov103_021B8138
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
 */
#include "../include/Obj02159.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(void *);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *); extern void BMP_Clear(int,u8); extern void MSGDATA_ReadString(int,int,int); extern void PRINTSYS_QUE_Clear(int); extern void PRINTSYS_PrintQue(int,int,s16,s16,int,int);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessage(u8 *p,void *q,int c,int x,s16 y) { int a,b,d; a=IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(q); b=IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(q); d=IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(q); BMP_Clear((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02159 *)p)->f0),((struct Obj02159 *)p)->f10); MSGDATA_ReadString(a,c,((struct Obj02159 *)p)->fC); PRINTSYS_QUE_Clear(b); PRINTSYS_PrintQue(b,(int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02159 *)p)->f4),x,y,((struct Obj02159 *)p)->fC,d); p[8]=1; }
