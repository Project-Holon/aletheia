/*
 * function: GTSNEGO_DISP_StartTrade
 * address: 0x021D42D8
 * packet: pkt_ov120_021D42D8
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: existing matched followers 021D435C, 021D437C, 021D439C remain separate.
 * symbols:
 *   func_020355D8 0x020355D8 arm
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   GTSNEGO_DISP_SetCursorState 0x021D69F4 thumb ov120
 *   GTSNEGO_DISP_SelectParty 0x021D593C thumb ov120
 *   GTSNEGO_DISP_SetStateCallback 0x021D4244 thumb ov120
 *   GTSNEGO_DISP_OnPartySelected 0x021D5980 thumb ov120
 */
#include "../include/Obj02830.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_020355D8(u8 v);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void GTSNEGO_DISP_SetCursorState(u8 *, void *, u32);
extern int GTSNEGO_DISP_SelectParty(u8 *, int);
extern void GTSNEGO_DISP_SetStateCallback(int *p, int v, int a2);
extern void GTSNEGO_DISP_OnPartySelected(u8 *);
int GTSNEGO_DISP_StartTrade(int n, u8 *p)
{
    ((struct Obj02830 *)p)->f138 = n;
    func_020355D8(1);
    if (((struct Obj02830 *)p)->f184 == 1) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        return 1;
    }
    if (n == 0) {
        ((struct Obj02830 *)p)->f15C = 0;
        GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct Obj02830 *)p)->f3C, ((struct Obj02830 *)p)->f34, 0);
        GTSNEGO_DISP_SelectParty(p, ((struct Obj02830 *)p)->f15C);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OnPartySelected, 0x177);
    } else {
        ((struct Obj02830 *)p)->f15C = 1;
        GTSNEGO_DISP_SetCursorState(*(u8 * *)&((struct Obj02830 *)p)->f3C, ((struct Obj02830 *)p)->f34, 1);
        GTSNEGO_DISP_SelectParty(p, ((struct Obj02830 *)p)->f15C);
        GTSNEGO_DISP_SetStateCallback((int *)p, (int)GTSNEGO_DISP_OnPartySelected, 0x17e);
    }
    return 1;
}
