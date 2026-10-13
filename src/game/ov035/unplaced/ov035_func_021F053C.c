/*
 * function: func_021F053C
 * address:  0x021F053C
 * packet:   pkt_ov035_021F053C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F053C 0x021F053C thumb
 *   func_020456F8 0x020456F8 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_021F0254 0x021F0254 thumb ov035
 *   func_020221A4 0x020221A4 thumb
 *   func_02035C60 0x02035C60 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BmpWin;

/* Work area of the C-Gear power on/off screen (fields used by this step only). */
typedef struct CGearPowerOnOffWork {
    u8 reserved0[24];
    struct BmpWin *messageWindow; /* 0x18 */
    struct BmpWin *menuWindow;    /* 0x1C */
    u8 reserved20[42];
    u16 step;                     /* 0x4A */
} CGearPowerOnOffWork;

extern void func_020456F8(struct BmpWin *window);
extern void BMP_WIN_SetPosY(struct BmpWin *window, u8 posY);
extern void func_02045334(struct BmpWin *window);
extern void func_02045374(struct BmpWin *window);
extern void func_021F0254(CGearPowerOnOffWork *work, struct BmpWin *window, int windowKind);
extern u32 func_020221A4(void);
extern int func_02035C60(void);

int func_021F053C(CGearPowerOnOffWork *work)
{
    switch (work->step) {
    case 0:
        func_020456F8(work->messageWindow);
        func_020456F8(work->menuWindow);
        BMP_WIN_SetPosY(work->menuWindow, 6);
        func_02045334(work->menuWindow);
        func_02045374(work->menuWindow);
        func_021F0254(work, work->menuWindow, 4);
        work->step++;
        break;
    case 1:
        if (func_020221A4() == 1)
            work->step++;
        break;
    case 2:
        if (func_02035C60() != 0)
            work->step++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
