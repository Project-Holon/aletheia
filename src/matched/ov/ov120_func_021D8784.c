/*
 * function: GTSNEGO_MSG_PrintSingle
 * address: 0x021D8784
 * packet: pkt_ov120_021D8784
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   WORDSET_SetSlotMyStatus  0x0201F02C  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "../include/Obj00131.h"
typedef unsigned short u16;
struct MsgBank;
struct WordSet;
extern void WORDSET_SetSlotMyStatus(struct WordSet *p, unsigned int i, void *a);
extern void MSGDATA_ReadString(struct MsgBank *bank, unsigned int index, void *dest);
typedef signed short   s16;
struct WordSet;
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern unsigned int BMP_WIN_Create(unsigned int layer, unsigned int a, unsigned int b, unsigned int tiles, unsigned char c, unsigned char d, unsigned char slot);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
void GTSNEGO_MSG_PrintSingle(char *p, void *n)
{
    void *q;
    WORDSET_SetSlotMyStatus(((struct Obj00131 *)p)->f10, 0, n);
    MSGDATA_ReadString(((struct Obj00131 *)p)->fC, 37, (void *)(*(int *)&((struct Obj00131 *)p)->f20));
    WORDSET_CopyTaggedText(((struct Obj00131 *)p)->f10, (void *)(*(int *)&((struct Obj00131 *)p)->f18), (void *)(*(int *)&((struct Obj00131 *)p)->f20));
    if (!((struct Obj00131 *)p)->f98) ((struct Obj00131 *)p)->f98 = (void *)BMP_WIN_Create(1, 11, 10, 10, 3, 11, 1);
    q = ((struct Obj00131 *)p)->f98;
    BMP_Clear(BMP_WIN_GetBmp(q), 0);
    GF_FONT_SetTextColor(1, 2, 0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q), 0, 0, (void *)(*(int *)&((struct Obj00131 *)p)->f18), (void *)(*(int *)&((struct Obj00131 *)p)->f14));
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
}
