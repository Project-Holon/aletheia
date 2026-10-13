/*
 * function: C_GEAR_RunFrame
 * address:  0x021F2130
 * packet:   pkt_ov029_021F2130
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BUTTON_MAN_UpdateSlots  0x02051C88  arm
 *   C_GEAR_TickIndicators  0x021F2D50  thumb  ov029
 *   C_GEAR_TickTabFrame  0x021F2DC8  thumb  ov029
 *   C_GEAR_UpdateClock  0x021F1F80  thumb  ov029
 *   C_GEAR_IsAnyIndicatorShown  0x021F2DA8  thumb  ov029
 *   C_GEAR_TickTabTimers  0x021F05D0  thumb  ov029
 *   C_GEAR_UpdateTabPalettes  0x021F0728  thumb  ov029
 *   C_GEAR_UpdateBeaconColors  0x021F1CD8  thumb  ov029
 */
#include "../include/Obj00042.h"

typedef signed int     s32;
struct Ctx;
extern s32 BUTTON_MAN_UpdateSlots(struct Ctx *c);
typedef unsigned char  u8;
extern void C_GEAR_TickIndicators(u8 *p);
extern void C_GEAR_TickTabFrame(char *p);
extern void C_GEAR_UpdateClock(char *p);
extern int C_GEAR_IsAnyIndicatorShown(u8 *p);
extern void C_GEAR_TickTabTimers(u8 *p);
extern void C_GEAR_UpdateTabPalettes(u8 *p);
extern void C_GEAR_UpdateBeaconColors(char *p);

void C_GEAR_RunFrame(char *p)
{
    BUTTON_MAN_UpdateSlots((struct Ctx *)(((struct Obj00042 *)p)->f10));
    C_GEAR_TickIndicators((u8 *)p);
    C_GEAR_TickTabFrame(p);
    C_GEAR_UpdateClock(p);
    if (C_GEAR_IsAnyIndicatorShown((u8 *)p) == 0) {
        if (((struct Obj00042 *)p)->f45A) {
            C_GEAR_TickTabTimers((u8 *)p);
            C_GEAR_UpdateTabPalettes((u8 *)p);
            C_GEAR_UpdateBeaconColors(p);
        }
    } else {
        ((struct Obj00042 *)p)->f214 = 0;
    }
}
