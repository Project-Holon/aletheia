/*
 * function: IRC_RHYTHM_PrintMessageWithName
 * address: 0x021B8030
 * packet: pkt_ov104_021B8030
 * region: ov104
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_RHYTHM_GetFont 0x021B7DE0 thumb ov104
 *   IRC_RHYTHM_GetPrintQueue 0x021B7DE4 thumb ov104
 *   IRC_RHYTHM_GetMessages 0x021B7DE8 thumb ov104
 *   IRC_RHYTHM_GetWordSet 0x021B7DEC thumb ov104
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 *   WORDSET_SetSlotMyStatus 0x0201F02C thumb
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj05274.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern int IRC_RHYTHM_GetFont(void *);
extern int IRC_RHYTHM_GetPrintQueue(void *);
extern int IRC_RHYTHM_GetMessages(void *);
extern int IRC_RHYTHM_GetWordSet(void *);
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct PrintSys;
struct WordSet;
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, u32 i, void *a);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
void IRC_RHYTHM_PrintMessageWithName(u8 *p, void *a, int b, u8 *c, s16 x, s16 y, u16 a6) { int set; int bank; void *text; int font; int tag; BMP_Clear(BMP_WIN_GetBmp(((struct Obj05274 *)p)->f0),((struct Obj05274 *)p)->f10); set=IRC_RHYTHM_GetWordSet(a); bank=IRC_RHYTHM_GetMessages(a); WORDSET_SetSlotMyStatus((struct WordSet *)set,0,c+0xc); text=func_02045EC0((struct MsgBank *)bank,b); WORDSET_CopyTaggedText((struct WordSet *)set,((struct Obj05274 *)p)->fC,text); STRBUF_Delete(text); font=IRC_RHYTHM_GetPrintQueue(a); tag=IRC_RHYTHM_GetFont(a); PRINTSYS_PrintQue((struct PrintSys *)font,(u32)BMP_WIN_GetBmp(((struct Obj05274 *)p)->f4),x,y,((struct Obj05274 *)p)->fC,tag); p[8]=1; }
