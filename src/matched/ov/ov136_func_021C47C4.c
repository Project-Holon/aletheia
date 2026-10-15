/*
 * function: MAILSYS_PrintMessageText
 * address: 0x021C47C4
 * packet: pkt_ov136_021C47C4
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "../include/Obj02206.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 PRINTSYS_PrintStream(u32, u32, u32, u32, u32, u32, u32, u32, u16, u16);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 index);
void MAILSYS_PrintMessageText(u8 *p, int n)
{
    void *q;
    BMP_MENUWORK_DrawWindow(((struct Obj02206 *)p)->f5C, 2, 13, 4);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02206 *)p)->f5C), 255);
    MSGDATA_ReadString(((struct Obj02206 *)p)->f20, n, ((struct Obj02206 *)p)->f34);
    ((struct Obj02206 *)p)->f9C = PRINTSYS_PrintStream(*(u32 *)&((struct Obj02206 *)p)->f5C, 0, 0, *(u32 *)&((struct Obj02206 *)p)->f34, ((struct Obj02206 *)p)->f24, ((struct Obj02206 *)p)->f15, ((struct Obj02206 *)p)->f100, 4, (u16)((struct Obj02206 *)p)->f0, 15);
    q = ((struct Obj02206 *)p)->f5C;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_020409B4(BMP_WIN_GetBgLayer(q));
}
