/*
 * function: IRC_RESULT_PrintMessageWithNames
 * address: 0x021B7F78
 * packet: pkt_ov105_021B7F78
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before IRC_RESULT_PrintRewardMessage
 * symbols:
 *   IRC_RESULT_GetFont 0x021B7CA0 thumb ov105
 *   IRC_RESULT_GetPrintQueue 0x021B7CA4 thumb ov105
 *   IRC_RESULT_GetMessages 0x021B7CA8 thumb ov105
 *   IRC_RESULT_GetWordSet 0x021B7CAC thumb ov105
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201EF6C 0x0201EF6C thumb
 */
#include "../include/Obj05279.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int IRC_RESULT_GetFont(void *);
extern int IRC_RESULT_GetPrintQueue(void *);
extern int IRC_RESULT_GetMessages(void *);
extern int IRC_RESULT_GetWordSet(void *p);
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct U16Vec;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct MsgBank;
struct PrintSys;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201EF6C(struct WordSet *p, u32 i, u32 v, u32 a, u32 b);
void IRC_RESULT_PrintMessageWithNames(u8 *p, void *a, int b, u8 *c, u8 *d, int a5)
{
 void *msg; int bank; void *text; int font; int tag;
 BMP_Clear(BMP_WIN_GetBmp(((struct Obj05279 *)p)->f0),((struct Obj05279 *)p)->f10);
 msg=(void *)IRC_RESULT_GetWordSet(a); bank=IRC_RESULT_GetMessages(a);
 func_0201F02C(msg,0,d+12); func_0201F02C(msg,1,c+12);
 text=func_02045EC0((struct MsgBank *)bank,b);
 func_0201F250(msg,((struct Obj05279 *)p)->fC,text); STRBUF_Delete(text);
 font=IRC_RESULT_GetPrintQueue(a); tag=IRC_RESULT_GetFont(a);
 PRINTSYS_PrintQue((struct PrintSys *)font,(u32)BMP_WIN_GetBmp(((struct Obj05279 *)p)->f4),0,0,((struct Obj05279 *)p)->fC,tag);
 p[8]=1;
}
