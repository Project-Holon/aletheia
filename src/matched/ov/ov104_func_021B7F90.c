/*
 * function: IRC_RHYTHM_PrintCenteredMessageColor
 * address: 0x021B7F90
 * packet: pkt_ov104_021B7F90
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
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
#include "../include/Obj02812.h"
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
struct PrintSys;
struct StrObj;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void IRC_RHYTHM_PrintCenteredMessageColor(u8 *p,void *a,int b,u16 c) { int bank; int font; int tag; u16 x; u16 y; bank=IRC_RHYTHM_GetMessages(a); font=IRC_RHYTHM_GetPrintQueue(a); tag=IRC_RHYTHM_GetFont(a); BMP_Clear(BMP_WIN_GetBmp(((struct Obj02812 *)p)->f0),((struct Obj02812 *)p)->f10); MSGDATA_ReadString((struct MsgBank *)bank,b,((struct Obj02812 *)p)->fC); x=BMP_WIN_GetWidth(((struct Obj02812 *)p)->f0)*4; y=BMP_WIN_GetHeight(((struct Obj02812 *)p)->f0)*4; x-=(u16)(func_0201D304(((struct Obj02812 *)p)->fC,tag,0)/2); y-=(u16)(func_0201D42C(((struct Obj02812 *)p)->fC,(void *)tag)/2); PRINTSYS_PrintQueColor((void *)font,(u32)BMP_WIN_GetBmp(((struct Obj02812 *)p)->f4),(s16)x,(s16)y,(u32)(((struct Obj02812 *)p)->fC),tag,c); p[8]=1; }
