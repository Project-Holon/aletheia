/*
 * function: PSEL_ClearWin2
 * address: 0x021BB2A4
 * packet: pkt_ov223_021BB2A4
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Declare width before the zero x initializer: its store shares the
 * upcoming call's zero r2; const p left the six-byte scheduling diff.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_0201D42C 0x0201D42C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_GetWidth 0x020437DC arm
 *   BMP_GetHeight 0x020437E4 arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   PSEL_UpdateWindows 0x021BAF48 thumb ov223
 * The bitmap accessors' own sources return u16. This caller uses each
 * result at full width without truncation, so its declarations widen them.
 */
#include "../include/Obj03381.h"
typedef unsigned short u16;
typedef signed short s16;
struct MsgBank;
struct StrObj;
struct Descriptor;
struct U16Vec;
struct Bmp;
extern void *func_02045EC0(struct MsgBank *, unsigned);
extern unsigned func_0201D304(struct StrObj *, unsigned, unsigned);
extern unsigned func_0201D42C(struct StrObj *, void *);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern u16 BMP_GetWidth(const struct Bmp *bmp);
typedef unsigned int   u32;
extern u16 BMP_GetHeight(const struct Bmp *bmp);
extern void PRINTSYS_PrintQueColor(void *, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern void STRBUF_Delete(struct U16Vec *);
extern int PSEL_UpdateWindows(char *);
void PSEL_ClearWin2(char *p)
{
    struct StrObj *text = func_02045EC0(*(struct MsgBank * *)&((struct Obj03381 *)p)->f234, 12);
    u16 width = func_0201D304(text, *(unsigned *)&((struct Obj03381 *)p)->f18, 0);
    u16 x = 0;
    u16 height = func_0201D42C(text, ((struct Obj03381 *)p)->f18);
    unsigned w = BMP_GetWidth(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238));
    unsigned h = BMP_GetHeight(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238));
    u16 y = 0;
    if (w > width)
        x = ((int)w - width) / 2;
    if (h > height)
        y = ((int)h - height) / 2;
    PRINTSYS_PrintQueColor(((struct Obj03381 *)p)->f1C, (unsigned)BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj03381 *)p)->f238),
                 (s16)x, (s16)y, (unsigned)text, *(unsigned *)&((struct Obj03381 *)p)->f18, 0x3C40);
    STRBUF_Delete((struct U16Vec *)text);
    ((struct Obj03381 *)p)->f244 = 0;
    PSEL_UpdateWindows(p);
}
