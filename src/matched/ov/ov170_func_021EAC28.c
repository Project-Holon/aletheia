/*
 * function: BOX2_SEQ_PrintTextWinEx
 * address:  0x021EAC28
 * packet:   pkt_ov170_021EAC28
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *
 * Expands message idx of bank into the work string buffer and prints it into
 * message window i; marks the window dirty.
 */
#include "../include/Obj00414.h"

typedef unsigned int u32;
typedef unsigned short u16;

struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct WordSet;
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);

void BOX2_SEQ_PrintTextWinEx(char *w, int i, void *bank, u32 idx, int x, int y, u32 font, u16 color)
{
    u32 print;
    void *s;
    s = func_02045EC0(bank, idx);
    WORDSET_CopyTaggedText(((struct Obj00414 *)w)->f84, (void *)(*(u32 *)&((struct Obj00414 *)w)->f88), s);
    print = ((struct Obj00414 *)w)->f8C;
    PRINTSYS_PrintQueColor((void *)print, (u32)BMP_WIN_GetBmp(*(void **)(w + i * 8 + 0x94)), (short)x, (short)y, *(u32 *)&((struct Obj00414 *)w)->f88, font, color);
    *(unsigned char *)(w + i * 8 + 0x98) = 1;
    STRBUF_Delete(s);
}
