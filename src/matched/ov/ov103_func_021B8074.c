/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_InitWindow
 * address: 0x021B8074
 * packet: pkt_ov103_021B8074
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: The third register parameter is u8: its full-word spill reload stays after the stack-argument stores.
 * symbols:
 *   IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData 0x021B8004 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue 0x021B8000 thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_TextGetFont 0x021B7FFC thumb ov103
 *   IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet 0x021B8008 thumb ov103
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   MI_CpuFill8 0x02082BCC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj03231.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetMsgData(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetPrintQueue(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetFont(void *); extern int IRC_COMPATIBLE_TOUCH_TEST_TextGetWordSet(void *);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *); extern void BMP_Clear(int,u8); extern void func_02045CAC(int,int,int); extern void PRINTSYS_QUE_Clear(int); extern void PRINTSYS_PrintQue(int,int,s16,s16,int,int);
extern void MI_CpuFill8(void *,int,int); extern unsigned BMP_WIN_Create(unsigned,unsigned,unsigned,unsigned,u8,u8,u8); extern int STRBUF_Create(int,u16); extern void BMP_WIN_TransferChars(struct Descriptor *); extern void BMP_WIN_MakeScreen(int); extern int BMP_WIN_GetBgLayer(int); extern void func_020409B4(int);
void IRC_COMPATIBLE_TOUCH_TEST_InitWindow(u8 *p,int a,int b,u8 c,u8 d,u8 e,u8 f,u16 g,u8 h,u16 i) {int q; MI_CpuFill8(p,0,20); ((struct Obj03231 *)p)->f10=g; ((struct Obj03231 *)p)->f0=BMP_WIN_Create(a,b,c,d,e,f,h); ((struct Obj03231 *)p)->fC=STRBUF_Create(255,i); ((struct Obj03231 *)p)->f4=((struct Obj03231 *)p)->f0; p[8]=0; BMP_Clear((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj03231 *)p)->f0),((struct Obj03231 *)p)->f10); q=((struct Obj03231 *)p)->f0; BMP_WIN_TransferChars((struct Descriptor *)q); BMP_WIN_MakeScreen(q); func_020409B4(BMP_WIN_GetBgLayer(q)); }
