/*
 * function: BMP_MENULIST_Redraw
 * address:  0x02020234
 * packet:   pkt_02020234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENULIST_Redraw.c \
 *       --func BMP_MENULIST_Redraw --addr 0x02020234 --cc 1.1p1 --thumb
 *
 * symbols:
 *   BMP_MENULIST_DrawItems  0x0202055C  thumb
 *   BMP_MENULIST_DrawCursor  0x020206C0  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 */
#include "../include/Obj08776.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

struct Ctl {
    u8 pad[0x18];
    u8 lo4 : 4;
    u8 hi4 : 4;
};

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *a);
struct CharBuf;
struct Obj;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENULIST_DrawItems(struct Obj *obj, u16 row, u16 col, u16 n, u32 flag);
extern void BMP_MENULIST_DrawCursor(struct Obj *obj);

void BMP_MENULIST_Redraw(u8 *p)
{
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj08776 *)p)->fC)),
                  ((struct Ctl *)p)->lo4);
    BMP_MENULIST_DrawItems((struct Obj *)p, ((struct Obj08776 *)p)->f40, 0, ((struct Obj08776 *)p)->f12, 1);
    BMP_MENULIST_DrawCursor((struct Obj *)p);
}
