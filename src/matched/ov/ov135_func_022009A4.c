/*
 * function: WORLDTRADE_TITLE_PrintMessage
 * address: 0x022009A4
 * packet: pkt_ov135_022009A4
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor 0x02202858 thumb ov135
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "../include/Obj02863.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void BG_SYS_PushTile(u32);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p, u8 b, void *s, u32 x, u32 y, void *out);
void WORLDTRADE_TITLE_PrintMessage(u8 *p, u32 n, int a2, int a3, int a4)
{
    u32 w;
    MSGDATA_ReadString((struct MsgBank *)(((struct Obj02863 *)p)->fB6C), n, ((struct Obj02863 *)p)->fB88);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02863 *)p)->fD40)), 0xf);
    w = ((struct Obj02863 *)p)->fD40;
    BMP_WIN_TransferChars((struct Descriptor *)w);
    BMP_WIN_MakeScreen((struct Cfg *)w);
    BG_SYS_PushTile(BMP_WIN_GetBgLayer((struct Descriptor *)w));
    BMP_MENUWORK_DrawWindow((void *)(((struct Obj02863 *)p)->fD40), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((struct Obj02863 *)p)->fD40), 0, ((struct Obj02863 *)p)->fB88, 0, 0, p + 0xfa0);
}
