/*
 * function: func_021C2274
 * address: 0x021C2274
 * packet: pkt_ov099_021C2274
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_021C2370 0x021C2370 thumb ov099
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj02157.h"
typedef short s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void func_021C2370(char *, int);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void PRINTSYS_Print(void *, s16, s16, void *, void *);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
void func_021C2274(char *p, void *window, int id, int slot, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(window), 0);
    GF_FONT_SetTextColor(15, 2, 0);
    func_021C2370(p, id - 1);
    MSGDATA_ReadString(((struct Obj02157 *)p)->fE0, 33, ((struct Obj02157 *)p)->fF0);
    func_0201F250(((struct Obj02157 *)p)->f8B0, ((struct Obj02157 *)p)->fF8, ((struct Obj02157 *)p)->fF0);
    PRINTSYS_Print(BMP_WIN_GetBmp(window), 2, 8, ((struct Obj02157 *)p)->fF8, ((struct Obj02157 *)p)->fE8);
    BMP_WIN_TransferChars(window);
}
