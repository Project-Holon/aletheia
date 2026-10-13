/*
 * function: IRC_COMPATIBLE_MENU_PrintMessage
 * address: 0x021B7DFC
 * packet: pkt_ov102_021B7DFC
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   IRC_COMPATIBLE_MENU_TextGetMsgData 0x021B7CC4 thumb ov102
 *   IRC_COMPATIBLE_MENU_TextGetPrintQueue 0x021B7CC0 thumb ov102
 *   IRC_COMPATIBLE_MENU_TextGetFont 0x021B7CBC thumb ov102
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQue 0x0201C6FC thumb
 */
#include "../include/Obj05269.h"
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
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct PrintSys;
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void IRC_COMPATIBLE_MENU_PrintMessage(u8 *p, void *q, int n, int x, s16 y)
{
    int a, b, c;
    a = IRC_COMPATIBLE_MENU_TextGetMsgData(q);
    b = IRC_COMPATIBLE_MENU_TextGetPrintQueue(q);
    c = IRC_COMPATIBLE_MENU_TextGetFont(q);
    BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05269 *)p)->f0)), ((struct Obj05269 *)p)->f10);
    MSGDATA_ReadString((struct MsgBank *)a, n, (void *)(((struct Obj05269 *)p)->fC));
    PRINTSYS_PrintQue((struct PrintSys *)b, (int)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj05269 *)p)->f4), (s16)x, (s16)y, (void *)(((struct Obj05269 *)p)->fC), (int)c);
    p[8] = 1;
}
