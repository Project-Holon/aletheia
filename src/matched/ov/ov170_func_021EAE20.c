/*
 * function: BOX2_SEQ_FillTextWin
 * address: 0x021EAE20
 * packet: pkt_ov170_021EAE20
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201EF14 0x0201EF14 thumb
 *   BOX2_SEQ_PrintTextWinEx 0x021EAC28 thumb ov170
 *   BOX2_SEQ_MakeScreen 0x021EABA0 thumb ov170
 */
#include "../include/Obj00414.h"
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201EF14(struct WordSet *p, u32 i, void *mon);
extern void BOX2_SEQ_PrintTextWinEx(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void BOX2_SEQ_MakeScreen(void **);
void BOX2_SEQ_FillTextWin(char *p, void **q, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    func_0201EF14(((struct Obj00414 *)p)->f84, 0, *q);
    BOX2_SEQ_PrintTextWinEx(p, i, ((struct Obj00414 *)p)->f80, 1, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}
