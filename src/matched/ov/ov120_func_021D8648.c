/*
 * function: GTSNEGO_MSG_DeleteConfirmWindow
 * address:  0x021D8648
 * packet:   pkt_021D8648
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj10403.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void func_02041B6C(u32 bit);

void GTSNEGO_MSG_DeleteConfirmWindow(u8 *p)
{
    APP_TASKMENU_WIN_Delete(((struct Obj10403 *)p)->fC4);
    func_02041B6C(5);
    *(u32 *)&((struct Obj10403 *)p)->fC4 = 0;
}
