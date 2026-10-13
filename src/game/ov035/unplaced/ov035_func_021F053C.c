/*
 * function: C_GEAR_POWER_ONOFF_RunMessageStep
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
 *   C_GEAR_POWER_ONOFF_RunMessageStep 0x021F053C thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   BMP_WIN_SetPosY 0x02045788 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   C_GEAR_POWER_ONOFF_PrintMessage 0x021F0254 thumb ov035
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   TOUCHPANEL_GetTrg 0x02035C60 arm
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

extern void BMP_WIN_ClearScreen(struct BmpWin *window);
extern void BMP_WIN_SetPosY(struct BmpWin *window, u8 posY);
extern void BMP_WIN_TransferChars(struct BmpWin *window);
extern void BMP_WIN_MakeScreen(struct BmpWin *window);
extern void C_GEAR_POWER_ONOFF_PrintMessage(CGearPowerOnOffWork *work, struct BmpWin *window, int windowKind);
extern u32 WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_GetTrg(void);

int C_GEAR_POWER_ONOFF_RunMessageStep(CGearPowerOnOffWork *work)
{
    switch (work->step) {
    case 0:
        BMP_WIN_ClearScreen(work->messageWindow);
        BMP_WIN_ClearScreen(work->menuWindow);
        BMP_WIN_SetPosY(work->menuWindow, 6);
        BMP_WIN_TransferChars(work->menuWindow);
        BMP_WIN_MakeScreen(work->menuWindow);
        C_GEAR_POWER_ONOFF_PrintMessage(work, work->menuWindow, 4);
        work->step++;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            work->step++;
        break;
    case 2:
        if (TOUCHPANEL_GetTrg() != 0)
            work->step++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
