/*
 * function: func_021D60EC
 * address:  0x021D60EC
 * packet:   pkt_ov016_021D60EC
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GXlSetWndPosition (libdwcutil.TWL.HYB.a(graphics.o))
 *
 * symbols:

 */

typedef unsigned short u16;
typedef volatile u16 vu16;

typedef struct {
    u16 x1;
    u16 y1;
    u16 x2;
    u16 y2;
} Rect;

static inline void SetWin(u16 *reg, u16 x1, u16 y1, u16 x2, u16 y2)
{
    ((vu16 *)reg)[0] = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    ((vu16 *)reg)[2] = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

void func_021D60EC(int lcd, int wnd, Rect *r)
{
    if (lcd == 1) {
        if (wnd == 0)
            SetWin((u16 *)0x04001040, r->x1, r->y1, r->x2, r->y2);
        else
            SetWin((u16 *)0x04001042, r->x1, r->y1, r->x2, r->y2);
    } else {
        if (wnd == 0)
            SetWin((u16 *)0x04000040, r->x1, r->y1, r->x2, r->y2);
        else
            SetWin((u16 *)0x04000042, r->x1, r->y1, r->x2, r->y2);
    }
}
