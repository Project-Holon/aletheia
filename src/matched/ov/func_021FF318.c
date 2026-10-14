/*
 * function: WORLDTRADE_SEARCH_PrintMessage
 * address:  0x021FF318
 * packet:   pkt_021FF318
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 *   BMP_WIN_MakeScreen  0x02045374  arm  arm9
 *   MSGDATA_ReadString  0x02045CAC  arm  arm9
 *   BMP_WIN_GetBgLayer  0x02045730  arm  arm9
 *   BMP_WIN_GetBmp  0x02045770  arm  arm9

 * Tear the object down: unhook the two sub-objects, release the +0xd40 resource, wire the 0/1/e quad, then drain the four engine hooks.
 */
#include "../include/Obj00018.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p, u8 b, void *s, u32 x, u32 y, void *out);
extern void BMP_WIN_TransferChars(struct Descriptor *v);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(u32 v);

void WORLDTRADE_SEARCH_PrintMessage(u8 *p, u32 k, int b, int c, int d)
{
    u32 v;

    MSGDATA_ReadString((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), k, (void *)(*(u32 *)(p + 0xb6c + 0x1c)));
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    func_0201F73C((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(*(u32 *)(p + 0xb6c + 0x1c)), 0, 0, p + 0xfa0);
    v = ((struct Obj00018 *)p)->fD40;
    BMP_WIN_TransferChars((struct Descriptor *)v);
    BMP_WIN_MakeScreen((struct Cfg *)v);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)v));
}
