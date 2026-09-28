/*
 * function: func_021C4D48
 * address:  0x021C4D48
 * packet:   pkt_ov111_021C4D48
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207D658  0x0207D658  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

extern void func_0207D658(u32 reg, u32 plane, s32 value);

#define REG_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define REG_DB_WIN0H    (*(volatile u16 *)0x04001040)
#define REG_DB_WIN0V    (*(volatile u16 *)0x04001044)
#define REG_DB_WININ    (*(volatile u16 *)0x04001048)
#define REG_DB_WINOUT   (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT   (*(volatile u16 *)0x04001050)

static inline void SetWnd0InsidePlane(int wnd, int effect)
{
    u32 tmp = (REG_DB_WININ & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    REG_DB_WININ = (u16)tmp;
}

static inline void SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp = (REG_DB_WINOUT & ~0x3F) | wnd;
    if (effect) {
        tmp |= 0x20;
    }
    REG_DB_WINOUT = (u16)tmp;
}

void func_021C4D48(int side)
{
    if (side < 0) {
        REG_DB_BLDCNT = 0;
        REG_DB_DISPCNT &= ~0xE000;
    } else if (side == 0) {
        func_0207D658(0x04001050, 0xC, -8);
        REG_DB_WIN0H = 0xE000;
        REG_DB_WIN0V = 0xA8;
        SetWnd0InsidePlane(0x1C, 1);
        SetWndOutsidePlane(0x1F, 0);
        REG_DB_DISPCNT = (REG_DB_DISPCNT & ~0xE000) | 0x2000;
    } else if (side == 1) {
        func_0207D658(0x04001050, 0xC, -8);
        REG_DB_WIN0H = 0x20;
        REG_DB_WIN0V = 0xA8;
        SetWnd0InsidePlane(0x1C, 1);
        SetWndOutsidePlane(0x1F, 0);
        REG_DB_DISPCNT = (REG_DB_DISPCNT & ~0xE000) | 0x2000;
    }
}
