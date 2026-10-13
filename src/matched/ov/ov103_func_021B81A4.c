/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered
 * address: 0x021B81A4
 * packet: pkt_ov103_021B81A4
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Narrow each dimension after shifting right, then subtract from the u16 coordinates.
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
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
#include "../include/Obj02811.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(void *);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *); extern void BMP_Clear(int,u8); extern void MSGDATA_ReadString(int,int,int); extern void PRINTSYS_QUE_Clear(int); extern void PRINTSYS_PrintQue(int,int,s16,s16,int,int);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p); extern int BMP_WIN_GetHeight(int); extern int func_0201D304(int,int,int); extern int func_0201D42C(int,int); extern void PRINTSYS_PrintQueColor(int,int,s16,s16,int,int,int);
void IRC_COMPATIBLE_TOUCH_TEST_PrintMessageCentered(u8 *p,void *q,int c) {int a,b,d; u16 x,y; a=IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(q); b=IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(q); d=IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(q); BMP_Clear((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02811 *)p)->f0),((struct Obj02811 *)p)->f10); MSGDATA_ReadString(a,c,((struct Obj02811 *)p)->fC); x=BMP_WIN_GetWidth((struct Descriptor *)(((struct Obj02811 *)p)->f0))*4; y=BMP_WIN_GetHeight(((struct Obj02811 *)p)->f0)*4; x-=(u16)(func_0201D304(((struct Obj02811 *)p)->fC,d,0)>>1); y-=(u16)(func_0201D42C(((struct Obj02811 *)p)->fC,d)>>1); PRINTSYS_QUE_Clear(b); PRINTSYS_PrintQueColor(b,(int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02811 *)p)->f4),x,y,((struct Obj02811 *)p)->fC,d,0x3dc4); p[8]=1; }
