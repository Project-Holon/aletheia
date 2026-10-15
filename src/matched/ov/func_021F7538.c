/*
 * function: WORLDTRADE_DEPOSIT_PrintMessage
 * address:  0x021F7538
 * packet:   pkt_021F7538
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_AllocString   0x02045EC0  arm
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   BG_SYS_PushTile   0x020409B4  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   STRBUF_Delete   0x02045808  arm
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor  0x02202858  thumb  ov135
 *
 * Handle walk: 02045EC0 over the 0xb6c field, the 0xb68/0xb88 pair through
 * 0201F250, then the p+0xd40 window through the 02045334/02045374/
 * 02045730/020409B4 group and a 02202858 redraw with the p+0xfa0 block.
 */
#include "../include/Obj00018.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct CharBuf;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *MSGDATA_AllocString(struct MsgBank *bank, u32 index);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void BG_SYS_PushTile(u32 index);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p, u8 b, void *s, u32 x, u32 y, void *out);

void WORLDTRADE_DEPOSIT_PrintMessage(u8 *p, u32 b, u32 c, u32 d, u32 e)
{
    u32 v = (u32)MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), b);
    u32 h;

    WORDSET_CopyTaggedText((struct WordSet *)(*(u32 *)&((struct Obj00018 *)p)->fB68), (void *)(((struct Obj00018 *)p)->fB88), (void *)v);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj00018 *)p)->fD40)), 0xf);
    h = ((struct Obj00018 *)p)->fD40;
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    BG_SYS_PushTile(unit_02045730(h));
    BMP_MENUWORK_DrawWindow((void *)(((struct Obj00018 *)p)->fD40), 0, 1, 0xe);
    WORLDTRADE_ADAPTER_QueuePrintDefaultColor((void *)(((struct Obj00018 *)p)->fD40), 0, (void *)(((struct Obj00018 *)p)->fB88), 0, 0, p + 0xfa0);
    STRBUF_Delete((struct U16Vec *)v);
}
