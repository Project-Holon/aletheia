/*
 * function: func_021F663C
 * address:  0x021F663C
 * packet:   pkt_021F663C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MSGDATA_AllocString   0x02045EC0  arm
 *   func_0201F250  0x0201F250  thumb
 *   BMP_WIN_GetBmp   0x02045770  arm
 *   BMP_Clear   0x02043B5C  arm
 *   BMP_WIN_TransferChars   0x02045334  arm
 *   BMP_WIN_MakeScreen   0x02045374  arm
 *   unit_02045730  0x02045730  arm
 *   sub_020409B4   0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   STRBUF_Delete   0x02045808  arm
 *   func_02202858  0x02202858  thumb  ov135
 *
 * Window teardown: the handle is the 0xd40 or 0xdd0 window selected by the
 * sixth argument, and that one handle is used by every call in the body.
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
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 unit_02045730(u32 a);
extern void sub_020409B4(u32 index);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 func_02202858(void *p, u8 b, void *s, u32 x, u32 y, void *out);

void func_021F663C(u8 *p, u32 b, u32 c, u32 d, u32 e, u32 sel)
{
    u32 v = (u32)MSGDATA_AllocString((struct MsgBank *)(*(u32 *)&((struct Obj00018 *)p)->fB6C), b);
    u32 h;

    func_0201F250((struct WordSet *)(*(u32 *)&((struct Obj00018 *)p)->fB68), (void *)(((struct Obj00018 *)p)->fB88), (void *)v);
    h = *(u32 *)(p + (sel == 0 ? 0xd40 : 0xdd0));
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)h)), 0xf);
    BMP_WIN_TransferChars((struct Descriptor *)h);
    BMP_WIN_MakeScreen((struct Cfg *)h);
    sub_020409B4(unit_02045730(h));
    func_0201F73C((void *)h, 0, 1, 0xe);
    func_02202858((void *)h, 0, (void *)(((struct Obj00018 *)p)->fB88), 0, 0, p + 0xfa0);
    STRBUF_Delete((struct U16Vec *)v);
}
