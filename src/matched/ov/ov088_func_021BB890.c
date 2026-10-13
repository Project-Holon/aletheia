/*
 * function: STARTMENU_MoveCursor
 * address:  0x021BB890
 * packet:   pkt_ov088_021BB890
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Moves the menu cursor at +0x128 by d rows through the row list at
 * +0x120, redraws the row it leaves, and scrolls (+0x138) when the new
 * row's top (+0x12f) runs off either edge.  Returns 1 when it moved.
 *
 * `old` is a u8 local and STARTMENU_PaintRowPalette takes its row as u8: only that
 * pair stores nv's spill before old's reload in the d >= 0 arm (each alone
 * is 21 B / 250 B off; see docs/notes/pkt_ov088_021BB890.c.txt).
 *
 * symbols:
 *   STARTMENU_RowTileY  0x021BB840  thumb  ov088
 *   STARTMENU_PaintRowPalette  0x021BB810  thumb  ov088
 *   _s32_div_f     0x0209C0A4  arm
 *   d_021BD5EE     0x021BD5EE  data  ov088  a2
 */
#include "../include/Obj00271.h"

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 d_021BD5EE[];

extern int STARTMENU_RowTileY(char *p, int y);
extern void STARTMENU_PaintRowPalette(void *, u8, int, int);

#define ROWH(r) (*(u16 *)((char *)d_021BD5EE + (r) * 4))

int STARTMENU_MoveCursor(char *p, int d)
{
    u8 old;
    u16 h;
    s8 y;
    u8 nv;
    s8 n;
    u8 cur;

    cur = p[0x128];
    old = (p + cur)[0x120];
    ((struct Obj00271 *)p)->f134 = 0;
    if (d < 0) {
        if (cur == 0)
            return 0;
        n = cur + d;
        h = ROWH((u8)(p + n)[0x120]);
        y = (s8)p[0x12f] - h;
        STARTMENU_PaintRowPalette(p, old, STARTMENU_RowTileY(p, (s8)p[0x12f]), 1);
        if ((u8)p[0x120] == 0) {
            if (y < 2) {
                if (n == 0) {
                    ((struct Obj00271 *)p)->f138 = -(((h - ((s8)p[0x12f] - 2)) / 3) * 8);
                    p[0x12f] = 2;
                } else {
                    ((struct Obj00271 *)p)->f138 = -((h / 3) * 8);
                }
            } else {
                p[0x12f] = y;
            }
        } else {
            p[0x12f] = y;
        }
    } else {
        if (cur + d >= 8)
            return 0;
        if ((u8)(p + (cur + d))[0x120] == 8)
            return 0;
        nv = (p + (s8)(cur + d))[0x120];
        y = (s8)p[0x12f] + ROWH(old);
        STARTMENU_PaintRowPalette(p, old, STARTMENU_RowTileY(p, (s8)p[0x12f]), 1);
        if ((u8)p[0x120] == 0) {
            if (y == 0x18) {
                ((struct Obj00271 *)p)->f138 = (ROWH(nv) / 3) * 8;
            } else if (y + ROWH(nv) > 0x18) {
                ((struct Obj00271 *)p)->f138 = (ROWH(nv) / 3) * 8;
            } else {
                p[0x12f] = y;
            }
        } else {
            p[0x12f] = y;
        }
    }
    ((struct Obj00271 *)p)->f128 += (u8)d;
    return 1;
}
