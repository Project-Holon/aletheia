/*
 * function: INTRO_MSG_PrintText
 * address: 0x021BF23C
 * packet: pkt_ov204_021BF23C
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Caller consumes 0201CCE4's live r0 result; return declared pointer despite callee's void source.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb  arm9
 */
#include "../include/Obj02540.h"

extern signed char MSG_SPEED_GetWait(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(unsigned int, unsigned int, unsigned int);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void *PRINTSYS_PrintStream(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned short, unsigned short);
extern void BMP_MENUWORK_DrawWindow(void *, int, int, int);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void INTRO_MSG_PrintText(char *p, void *a, int flag)
{
    unsigned int value = MSG_SPEED_GetWait();
    void *desc = ((struct Obj02540 *)p)->f1C;
    BMP_Clear(BMP_WIN_GetBmp(desc), 15);
    GF_FONT_SetTextColor(1, 2, 15);
    MSGDATA_ReadString(((struct Obj02540 *)p)->fC, (unsigned int)a, ((struct Obj02540 *)p)->f3C);
    WORDSET_CopyTaggedText(((struct Obj02540 *)p)->f8, ((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f3C);
    ((struct Obj02540 *)p)->f14 = PRINTSYS_PrintStream((unsigned int)desc, 4, 0, *(unsigned int *)&((struct Obj02540 *)p)->f40, ((struct Obj02540 *)p)->f10, value, ((struct Obj02540 *)p)->f18, 0xFFFF, ((struct Obj02540 *)p)->f0, 15);
    if (flag == 0)
        BMP_MENUWORK_DrawWindow(desc, 1, 7, 9);
    else
        BMP_MENUWORK_DrawWindow(desc, 1, 16, 8);
    BMP_WIN_TransferChars(desc);
    BMP_WIN_MakeScreen(desc);
    func_02041B6C(BMP_WIN_GetBgLayer(desc));
}
