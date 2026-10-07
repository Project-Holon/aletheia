/*
 * file:     unit_021F4560_p01.c
 * unit:     yes
 * function: func_021F4560, func_021F45C8, func_021F4628
 * address:  0x021F4560
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   WM_GetAllowedChannel             0x0208ee60 arm
 *   d_021F6F90   0x021F6F90  data
 *   WM_SetIndCallback                0x0208eac8 arm
 *   MBi_CheckWmErrcode               0x021f6334 arm
 *   WM_SetLifeTime                   0x02090dec arm
 *   MBi_ParentCallback               0x021f46c8 arm
 *   mbi_life_mp                      0x021f6e58 data
 */
#include "../../matched/include/G_WmBase.h"
#include "../../matched/include/G_MBiData.h"

typedef unsigned short u16;

struct WMScanExParam {
    char _0[6];
    u16 channel;
};

typedef unsigned char u8;

extern u16 WM_GetAllowedChannel(void);
extern void MBi_CheckWmErrcode(u16 apiid, int errcode);
extern int WM_SetIndCallback(void (*callback)(void *));
extern int WM_SetLifeTime(void (*callback)(void *), u16 tableNumber, u16 camLifeTime, u16 frameLifeTime, u16 mpLifeTime);
extern void MBi_ParentCallback(void *arg);
extern struct WmBase d_021F6F90;
extern struct MBiData mbi_life_mp;


static int changeScanChannel(struct WMScanExParam *p)
{
    u16 i;
    u16 channel_bmp;
    u16 channel;

    channel_bmp = WM_GetAllowedChannel();
    if (channel_bmp == 0)
        return 0;
    i = 0;
    channel = p->channel;
    do {
        if ((channel_bmp & channel) != 0 && p->channel != channel) {
            p->channel = channel;
            break;
        }
        i = (u16)(i + 1);
        channel = (u16)(channel == 0 ? 1 : channel << 1);
    } while (i < 16);
    return 1;
}


static int MBi_IsSendEnabled(void)
{
    int ret = 0;
    int g = 0;
    int f = 0;
    char *base = *(char **)(((char *)&d_021F6F90) + 0xC);

    if (*(u16 *)(base + 0x528) == 1 && *(u8 *)(base + 0x50C) == 0)
        f = 1;
    if (f) {
        if (*(u16 *)(base + 0x526) == 0)
            g = 1;
    }
    if (g) {
        if (*(u16 *)(base + 0x52A) != 0)
            ret = 1;
    }
    return ret;
}


static void MBi_OnInitializeDone(void)
{
    MBi_CheckWmErrcode(0x80, WM_SetIndCallback(MBi_ParentCallback));
    MBi_CheckWmErrcode(0x1D, WM_SetLifeTime(MBi_ParentCallback, mbi_life_mp.mbi_life_table_no, mbi_life_mp.cam, mbi_life_mp.frame, mbi_life_mp.mbi_life_mp));
}
