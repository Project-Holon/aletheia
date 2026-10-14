/*
 * function: WORLDTRADE_INPUT_PrintBankString
 * address: 0x021F90B8
 * packet: pkt_ov135_021F90B8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   func_0201F73C 0x0201F73C thumb
 *   WORLDTRADE_ADAPTER_StartPrintStream 0x02202878 thumb ov135
 *   WORLDTRADE_ADAPTER_QueuePrintDefaultColor 0x02202858 thumb ov135
 */
#include "../include/Obj02857.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void func_0201F73C(void *, int, int, int);
extern void WORLDTRADE_ADAPTER_StartPrintStream(void *a, unsigned b, unsigned c, int d, int e, u8 *p);
extern u32 WORLDTRADE_ADAPTER_QueuePrintDefaultColor(void *p, u8 b, void *s, u32 x, u32 y, void *out);
void WORLDTRADE_INPUT_PrintBankString(u8 *p, void *bank, u32 index, int unused1, int unused2, int slow)
{
    void *str;
    str = func_02045EC0(bank, index);
    func_0201F250(((struct Obj02857 *)p)->fB68, ((struct Obj02857 *)p)->fB88, str);
    STRBUF_Delete(str);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj02857 *)p)->fD40), 15);
    BMP_WIN_TransferChars(((struct Obj02857 *)p)->fD40);
    func_0201F73C(((struct Obj02857 *)p)->fD40, 0, 1, 14);
    if (slow)
        WORLDTRADE_ADAPTER_StartPrintStream(((struct Obj02857 *)p)->fD40, 0, (unsigned int)(((struct Obj02857 *)p)->fB88), 0, 0, p + 0xfa0);
    else
        WORLDTRADE_ADAPTER_QueuePrintDefaultColor(((struct Obj02857 *)p)->fD40, 0, ((struct Obj02857 *)p)->fB88, 0, 0, p + 0xfa0);
    ((struct Obj02857 *)p)->fDFC = 0;
}
