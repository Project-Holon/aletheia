/*
 * function: BOX2_SEQ_DrawMonName
 * address:  0x021EB874
 * packet:   pkt_ov170_021EB874
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_020078C4 0x020078C4 thumb
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   BMP_Clear 0x02043B5C arm
 *   PRINTSYS_PrintColor 0x0201C7D0 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BMP_OAM_UploadChars 0x020257D0 thumb
 */
#include "../include/Obj23975.h"
#include "../include/Obj23977.h"
#include "../include/Obj23978.h"
#include "../include/Obj23979.h"
#include "../include/Obj23980.h"
#include "../include/Obj23981.h"
#include "../include/Obj23982.h"
#include "../include/Obj23983.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct Obj;
struct U16Vec;
struct WordSet;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern int func_020078C4(void *save, u32 box);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void PRINTSYS_PrintColor(void *x, short y, short z, void *s, void *w, unsigned short v);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_OAM_UploadChars(struct Obj *o);

void BOX2_SEQ_DrawMonName(char **p, unsigned a, int i)
{
    void *s = func_02045EC0(((struct Obj23975 *)(p[11]))->f80, 0x1E);
    unsigned n = func_020078C4((void *)(((unsigned *)p[0])[1]), a);
    WORDSET_SetSlotNumber(((struct Obj23977 *)(p[11]))->f84, 0, n, 2, 0, 1);
    WORDSET_CopyTaggedText(((struct Obj23978 *)(p[11]))->f84, ((struct Obj23979 *)(p[11]))->f88, s);
    BMP_Clear(*(void **)(p[11] + i * 8 + 8), 0);
    if (n == 0x1E)
        PRINTSYS_PrintColor(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23980 *)(p[11]))->f88, ((struct Obj23981 *)(p[11]))->f7C, 0x1480);
    else
        PRINTSYS_PrintColor(*(void **)(p[11] + i * 8 + 8), 0, 0, ((struct Obj23982 *)(p[11]))->f88, ((struct Obj23983 *)(p[11]))->f7C, 0x440);
    STRBUF_Delete(s);
    BMP_OAM_UploadChars(*(void **)(p[11] + i * 8 + 4));
}
