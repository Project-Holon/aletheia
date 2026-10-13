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
#include "../include/Obj02755.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void BMP_WIN_SetPosY(struct Descriptor *p, u8 v);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void C_GEAR_POWER_ONOFF_PrintMessage(char *p, int a1, int a2);
extern u32 WIPE_SYS_EndCheck(void);
extern int TOUCHPANEL_GetTrg(void);

int C_GEAR_POWER_ONOFF_RunMessageStep(char *p)
{
    switch (((struct Obj02755 *)p)->f4A) {
    case 0:
        BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj02755 *)p)->f18));
        BMP_WIN_ClearScreen((struct Descriptor *)(((struct Obj02755 *)p)->f1C));
        BMP_WIN_SetPosY((struct Descriptor *)(((struct Obj02755 *)p)->f1C), 6);
        BMP_WIN_TransferChars((struct Descriptor *)((struct Obj02755 *)p)->f1C);
        BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj02755 *)p)->f1C));
        C_GEAR_POWER_ONOFF_PrintMessage(p, ((struct Obj02755 *)p)->f1C, 4);
        (((struct Obj02755 *)p)->f4A)++;
        break;
    case 1:
        if (WIPE_SYS_EndCheck() == 1)
            (((struct Obj02755 *)p)->f4A)++;
        break;
    case 2:
        if (TOUCHPANEL_GetTrg() != 0)
            (((struct Obj02755 *)p)->f4A)++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
