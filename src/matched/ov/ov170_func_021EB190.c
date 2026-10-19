/*
 * function: BOX2_SEQ_DrawItemEntry
 * address: 0x021EB190
 * packet: pkt_ov170_021EB190
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BOX2_SEQ_PrintTextWinEx 0x021EAC28 thumb ov170
 *   BOX2_SEQ_PrintTextWin 0x021EABD0 thumb ov170
 *   BOX2_SEQ_MakeScreen 0x021EABA0 thumb ov170
 *   WORDSET_SetSlotFromMsg36 0x0201EF40 thumb
 */
#include "../include/Obj00414.h"
#include "../include/Obj06549.h"
typedef struct { unsigned char pad[18]; unsigned char low : 7; unsigned char flag : 1; } Entry;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct WordSet;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BOX2_SEQ_PrintTextWinEx(char *, int, void *, unsigned, int, int, unsigned, unsigned short);
extern void BOX2_SEQ_PrintTextWin(unsigned char *w, int i, void *bank, unsigned idx, int x, int y, unsigned font, unsigned short color);
extern void BOX2_SEQ_MakeScreen(void **);
extern void WORDSET_SetSlotFromMsg36(struct WordSet *p, u32 i, u32 v);
void BOX2_SEQ_DrawItemEntry(char *p, unsigned char *e, int i)
{
    BMP_Clear(BMP_WIN_GetBmp(*(void **)(p + 0x94 + i * 8)), 0);
    if (((struct Obj06549 *)e)->f6 != 0) {
        WORDSET_SetSlotFromMsg36(((struct Obj00414 *)p)->f84, 0, ((struct Obj06549 *)e)->f6);
        BOX2_SEQ_PrintTextWinEx(p, i, ((struct Obj00414 *)p)->f80, 99, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    } else {
        BOX2_SEQ_PrintTextWin((unsigned char *)p, i, ((struct Obj00414 *)p)->f80, 105, 0, 0, ((struct Obj00414 *)p)->f78, 0x440);
    }
    BOX2_SEQ_MakeScreen((void **)(p + 0x94 + i * 8));
}
