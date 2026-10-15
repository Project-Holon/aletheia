/*
 * function: GAME_DATA_SaveMain
 * address:  0x02012DD0
 * packet:   pkt_02012DD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_SaveMain.c \
 *       --func GAME_DATA_SaveMain --addr 0x02012DD0 --cc 1.1p1 --thumb
 *
 * symbols:
 *   SAVE_CONTROL_MainSave  0x02007168  thumb
 *   WIH_DWC_ResumeTimers  0x02010444  thumb
 *   GFL_USE_IsLoaderBusy  0x02005C64  thumb
 *   UI_ClearFlags39Global  0x020351A0  arm
 */
#include "../include/Obj11252.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern int  GFL_USE_IsLoaderBusy(void);
struct Sub02007168;
extern u32 SAVE_CONTROL_MainSave(struct Sub02007168 *p);
extern int UI_ClearFlags39Global(u32 v);
extern void WIH_DWC_ResumeTimers(void);

int GAME_DATA_SaveMain(u8 *p)
{
    int r;

    if (GFL_USE_IsLoaderBusy() == 1) {
        return 0;
    }
    r = SAVE_CONTROL_MainSave((struct Sub02007168 *)(((struct Obj11252 *)p)->f0));
    if ((u32)(r - 2) <= 1) {
        UI_ClearFlags39Global(2);
        WIH_DWC_ResumeTimers();
        ((struct Obj11252 *)p)->f1CE = 0;
    }
    return r;
}
