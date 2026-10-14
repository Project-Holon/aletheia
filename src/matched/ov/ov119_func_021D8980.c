/*
 * function: POKETRADE_PROC_ResetTouchbarBackButton
 * address: 0x021D8980
 * packet: pkt_ov119_021D8980
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status:   EXACT*
 * 2026-10-02: the first call's target 021B65B4 (thumb, ov067 window) was an
 *  unlabelled tail-call stub; seeded in layout/function_starts.txt and matched
 *  as src/matched/ov/ov067_func_021B65B4.c, so every call now resolves.
 * symbols:
 *   TOUCHBAR_ResetAndEnableButton 0x021B65B4 thumb ov067
 *   TOUCHBAR_SetButtonVisible 0x021B6558 thumb ov067
 *   TOUCHBAR_SetButtonEnabled 0x021B6548 thumb ov067
 */
#include "../include/Obj00001.h"
typedef unsigned int u32;
extern void TOUCHBAR_ResetAndEnableButton(u32 *p, u32 a1);
extern void TOUCHBAR_SetButtonVisible(unsigned char *p, unsigned int id, unsigned int v);
extern int TOUCHBAR_SetButtonEnabled(unsigned char *p, unsigned int id, int v);
int POKETRADE_PROC_ResetTouchbarBackButton(char *p)
{
    TOUCHBAR_ResetAndEnableButton(*(u32 * *)&((struct Obj00001 *)p)->f9C0, 1);
    TOUCHBAR_SetButtonVisible((unsigned char *)(*(u32 * *)&((struct Obj00001 *)p)->f9C0), 1, 1);
    return TOUCHBAR_SetButtonEnabled((unsigned char *)(*(u32 * *)&((struct Obj00001 *)p)->f9C0), 1, 1);
}
