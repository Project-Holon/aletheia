/*
 * function: BOX2_SEQ_DeleteTextEntries
 * address:  0x021EB2A4
 * packet:   pkt_021EB2A4
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_FillTextWinEntry  0x021EADB4  thumb  ov170
 *   BOX2_SEQ_FillTextWin  0x021EAE20  thumb  ov170
 *   BOX2_SEQ_DrawCellEntry  0x021EAE74  thumb  ov170
 *   BOX2_SEQ_DrawSpriteEntry  0x021EAF20  thumb  ov170
 *   BOX2_SEQ_DrawTileEntry  0x021EAFBC  thumb  ov170
 *   BOX2_SEQ_DrawMoveEntry  0x021EB098  thumb  ov170
 *   BOX2_SEQ_DrawSwapEntry  0x021EB114  thumb  ov170
 *   BOX2_SEQ_DrawItemEntry  0x021EB190  thumb  ov170
 *   BOX2_SEQ_DrawMsgEntry  0x021EB208  thumb  ov170
 *   BOX2_SEQ_MakeScreen  0x021EABA0  thumb  ov170
 */
#include "../include/Obj00000.h"
typedef unsigned char u8;

extern void BOX2_SEQ_FillTextWinEntry(void *q, int a, int i);
extern void BOX2_SEQ_FillTextWin(char *p, void **q, int i);
extern void BOX2_SEQ_DrawCellEntry(void *q, int a, int i);
extern void BOX2_SEQ_DrawSpriteEntry(void *q, int a, int i);
extern void BOX2_SEQ_DrawTileEntry(void *p, int a, int i);
extern void BOX2_SEQ_DrawMoveEntry(char *p, unsigned char *e, int i);
extern void BOX2_SEQ_DrawSwapEntry(char *p, unsigned char *e, int i);
extern void BOX2_SEQ_DrawItemEntry(char *p, unsigned char *e, int i);
extern void BOX2_SEQ_DrawMsgEntry(void *q, int a, int i);
extern void BOX2_SEQ_MakeScreen(void **p);

void BOX2_SEQ_DeleteTextEntries(u8 *p, int a)
{
    BOX2_SEQ_FillTextWinEntry(((struct Obj00000 *)p)->f2C, a, 1);
    BOX2_SEQ_FillTextWin(((struct Obj00000 *)p)->f2C, (void **)a, 2);
    BOX2_SEQ_DrawCellEntry(((struct Obj00000 *)p)->f2C, a, 3);
    BOX2_SEQ_DrawSpriteEntry(((struct Obj00000 *)p)->f2C, a, 4);
    BOX2_SEQ_DrawTileEntry(p, a, 5);
    BOX2_SEQ_DrawMoveEntry(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 6);
    BOX2_SEQ_DrawSwapEntry(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 7);
    BOX2_SEQ_DrawItemEntry(((struct Obj00000 *)p)->f2C, (unsigned char *)a, 8);
    BOX2_SEQ_DrawMsgEntry(((struct Obj00000 *)p)->f2C, a, 9);
    BOX2_SEQ_MakeScreen((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xe4));
    BOX2_SEQ_MakeScreen((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xec));
    BOX2_SEQ_MakeScreen((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xf4));
    BOX2_SEQ_MakeScreen((void **)((u8 *)((struct Obj00000 *)p)->f2C + 0xfc));
}
