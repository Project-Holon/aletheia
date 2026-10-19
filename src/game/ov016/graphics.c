/*
 * file:     graphics.c
 * unit:     yes
 * function: DWCi_GXlVisible, DWCi_GXlInvisible, DWCi_GXlSetWndPosition, DWCi_GXlSetWndPlane
 * address:  0x021D603C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
#define REG_DISPCNT(base) (*(volatile unsigned long *)(base))
#define LO(a) \
    do { \
        int v = (*(vu16 *)(a) & ~0x3f) | plane; \
        if (effect) \
            v |= 0x20; \
        *(vu16 *)(a) = v; \
    } while (0)
#define HI(a) \
    do { \
        int v = (*(vu16 *)(a) & ~0x3f00) | (plane << 8); \
        if (effect) \
            v |= 0x2000; \
        *(vu16 *)(a) = v; \
    } while (0)
#include "../types.h"

typedef struct {
    u16 x1;
    u16 y1;
    u16 x2;
    u16 y2;
} Rect;

void DWCi_GXlVisible(int lcd, int plane);
void DWCi_GXlInvisible(int lcd, int plane);
void DWCi_GXlSetWndPosition(int lcd, int wnd, Rect *r);
void DWCi_GXlSetWndPlane(int lcd, int wnd, int plane, int effect);

void DWCi_GXlVisible(int lcd, int plane)
{
    if (lcd == 1) {
        unsigned long v = (REG_DISPCNT(0x04001000) & 0x1f00) >> 8;

        REG_DISPCNT(0x04001000) = (REG_DISPCNT(0x04001000) & ~0x1f00) | ((v | plane) << 8);
    } else {
        unsigned long v = (REG_DISPCNT(0x04000000) & 0x1f00) >> 8;

        REG_DISPCNT(0x04000000) = (REG_DISPCNT(0x04000000) & ~0x1f00) | ((v | plane) << 8);
    }
}

/*
 * sdk:      DWCi_GXlInvisible (graphics.o)
 *
 * Closed (w5_nm): the plane mask is read into a local first and DISPCNT is read
 * again inside the store expression (get-then-set order); reading both into
 * locals up front gave the converse r0/r2 roles.
 */
void DWCi_GXlInvisible(int lcd, int plane)
{
    if (lcd == 1) {
        unsigned long v = (REG_DISPCNT(0x04001000) & 0x1f00) >> 8;

        REG_DISPCNT(0x04001000) = (REG_DISPCNT(0x04001000) & ~0x1f00) | ((v & ~plane) << 8);
    } else {
        unsigned long v = (REG_DISPCNT(0x04000000) & 0x1f00) >> 8;

        REG_DISPCNT(0x04000000) = (REG_DISPCNT(0x04000000) & ~0x1f00) | ((v & ~plane) << 8);
    }
}

static inline void SetWin(u16 *reg, u16 x1, u16 y1, u16 x2, u16 y2)
{
    ((vu16 *)reg)[0] = (u16)(((x1 << 8) & 0xff00) | (x2 & 0xff));
    ((vu16 *)reg)[2] = (u16)(((y1 << 8) & 0xff00) | (y2 & 0xff));
}

/*
 * sdk:      DWCi_GXlSetWndPosition (libdwcutil.TWL.HYB.a(graphics.o))
 */
void DWCi_GXlSetWndPosition(int lcd, int wnd, Rect *r)
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

/*
 * sdk:      DWCi_GXlSetWndPlane (libdwcutil.TWL.HYB.a(graphics.o))
 */
void DWCi_GXlSetWndPlane(int lcd, int wnd, int plane, int effect)
{
    switch (wnd) {
    case 0:
        if (lcd == 1)
            LO(0x04001048);
        else
            LO(0x04000048);
        break;
    case 1:
        if (lcd == 1)
            HI(0x04001048);
        else
            HI(0x04000048);
        break;
    case 2:
        if (lcd == 1)
            HI(0x0400104a);
        else
            HI(0x0400004a);
        break;
    case 3:
        if (lcd == 1)
            LO(0x0400104a);
        else
            LO(0x0400004a);
        break;
    }
}
