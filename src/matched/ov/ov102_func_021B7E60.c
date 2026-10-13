/*
 * function: IRC_COMPATIBLE_MENU_PrintMessageCentered
 * address: 0x021B7E60
 * packet: pkt_ov102_021B7E60
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: halve before casting to u16, keeping the seventeenth input bit.
 * symbols:
 *   IRC_COMPATIBLE_MENU_TextGetMsgData 0x021B7CC4 thumb ov102
 *   IRC_COMPATIBLE_MENU_TextGetPrintQueue 0x021B7CC0 thumb ov102
 *   IRC_COMPATIBLE_MENU_TextGetFont 0x021B7CBC thumb ov102
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_GetWidth 0x02045738 arm
 *   BMP_WIN_GetHeight 0x02045740 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 */
#include "../include/Obj02809.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern int IRC_COMPATIBLE_MENU_TextGetMsgData(void *);
extern int IRC_COMPATIBLE_MENU_TextGetPrintQueue(void *);
extern int IRC_COMPATIBLE_MENU_TextGetFont(void *);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned int   u32;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct StrObj;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u8 BMP_WIN_GetWidth(struct Descriptor *p);
extern u8 BMP_WIN_GetHeight(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern u32 func_0201D42C(struct StrObj *s, void *font);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void IRC_COMPATIBLE_MENU_PrintMessageCentered(u8 *p, void *q, int n)
{
    int a, b, c;
    u16 x, y;
    a = IRC_COMPATIBLE_MENU_TextGetMsgData(q);
    b = IRC_COMPATIBLE_MENU_TextGetPrintQueue(q);
    c = IRC_COMPATIBLE_MENU_TextGetFont(q);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02809 *)p)->f0)), ((struct Obj02809 *)p)->f10);
    MSGDATA_ReadString((struct MsgBank *)a, n, (void *)(((struct Obj02809 *)p)->fC));
    x = BMP_WIN_GetWidth((struct Descriptor *)(((struct Obj02809 *)p)->f0)) * 4;
    y = BMP_WIN_GetHeight((struct Descriptor *)(((struct Obj02809 *)p)->f0)) * 4;
    x -= (u16)(func_0201D304((struct StrObj *)(((struct Obj02809 *)p)->fC), c, 0) >> 1);
    y -= (u16)(func_0201D42C((struct StrObj *)(((struct Obj02809 *)p)->fC), (void *)c) >> 1);
    PRINTSYS_QUE_Clear((struct PrintSys *)b);
    PRINTSYS_PrintQueColor((void *)b, (int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02809 *)p)->f4), (s16)x, (s16)y, (int)(((struct Obj02809 *)p)->fC), (int)c, (int)0x3dc1);
    p[8] = 1;
}
