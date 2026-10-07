/*
 * file:     unit_021C3CC0_p06.c
 * unit:     yes
 * function: func_021C4D48, func_021C4E0C
 * address:  0x021C4D48
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0207D658  0x0207D658  arm
 *   func_021C4B74  0x021C4B74  thumb
 */
#define REG_DB_DISPCNT  (*(volatile u32 *)0x04001000)
#define REG_DB_WIN0H    (*(volatile u16 *)0x04001040)
#define REG_DB_WIN0V    (*(volatile u16 *)0x04001044)
#define REG_DB_WININ    (*(volatile u16 *)0x04001048)
#define REG_DB_WINOUT   (*(volatile u16 *)0x0400104A)
#define REG_DB_BLDCNT   (*(volatile u16 *)0x04001050)
typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

typedef unsigned char u8;

extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_021C4B74(char *p, int flag);
void func_021C4D48(int side);
int func_021C4E0C(char *p);


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


/*
 * Addresses are Black-image addresses.
 */
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

/*
 * note 2026-10-05 (wave D4 lane 02): case 0 writes both stores (0x304C and 0x3050) in each
 * if/else arm. The compiler sinks the common stores into the join block and keeps the 0x305C
 * constant live, so 0x304C/0x3050 come out as 0x305C-0x10 / 0x305C-0xC.
 */
int func_021C4E0C(char *p)
{
    switch (*(u8 *)(p + 0x32C6)) {
    case 0:
        if (*(u16 *)(p + 0x305C) == 0) {
            *(u32 *)(p + 0x304C) = 0x20;
            *(u32 *)(p + 0x3050) = 0x98;
        } else {
            *(u32 *)(p + 0x304C) = 0xE0;
            *(u32 *)(p + 0x3050) = 0x98;
        }
        *(u32 *)(p + 0x303C) = 0x103D;
        *(u32 *)(p + 0x3040) = 0x103D;
        *(u8 *)(p + 0x32C6) = 1;
        break;
    case 1:
        *(int *)(p + 0x303C) += 0x100;
        *(int *)(p + 0x3040) += 0x100;
        if (*(int *)(p + 0x303C) >= 0x2000) {
            *(int *)(p + 0x303C) = 0x2000;
            *(int *)(p + 0x3040) = 0x2000;
            *(u8 *)(p + 0x32C6) = 2;
        }
        break;
    case 2:
        *(u16 *)(p + 0x305E) = 1;
        func_021C4B74(p, *(int *)(p + 0x3034));
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    case 3:
        *(u8 *)(p + 0x32C6) = 4;
        break;
    case 4:
        *(int *)(p + 0x303C) -= 0x100;
        *(int *)(p + 0x3040) -= 0x100;
        if (*(int *)(p + 0x303C) <= 0x1000) {
            *(int *)(p + 0x303C) = 0x1000;
            *(int *)(p + 0x3040) = 0x1000;
            *(u8 *)(p + 0x32C6) = 5;
        }
        break;
    case 5:
        *(int *)(p + 0x304C) = 0x80;
        *(int *)(p + 0x3050) = 0x60;
        *(u16 *)(p + 0x305E) = 0;
        func_021C4B74(p, *(int *)(p + 0x3034));
        func_021C4D48(-1);
        return 1;
    case 6:
        *(u8 *)(p + 0x32C6) = 7;
        break;
    case 7:
        *(int *)(p + 0x304C) -= 8;
        if (*(int *)(p + 0x304C) < 0x20) {
            *(int *)(p + 0x304C) = 0x20;
            *(u8 *)(p + 0x32C6) = 8;
        }
        break;
    case 8:
        *(u16 *)(p + 0x305C) ^= 1;
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    case 9:
        *(u8 *)(p + 0x32C6) = 10;
        break;
    case 10:
        *(int *)(p + 0x304C) += 8;
        if (*(int *)(p + 0x304C) > 0xE0) {
            *(int *)(p + 0x304C) = 0xE0;
            *(u8 *)(p + 0x32C6) = 11;
        }
        break;
    case 11:
        *(u16 *)(p + 0x305C) ^= 1;
        func_021C4D48(*(u16 *)(p + 0x305C));
        return 1;
    }
    *(u8 *)(p + 0x32CA) |= 4;
    return 0;
}
