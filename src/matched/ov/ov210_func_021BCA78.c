/*
 * function: ZKNSEARCH_MAIN_DeleteScrollWindow
 * address:  0x021BCA78
 * packet:   pkt_ov210_021BCA78
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BGWINFRM_Delete  0x0202CA0C  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00085.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct WinMgr;
extern void BGWINFRM_Delete(struct WinMgr *mgr);

void ZKNSEARCH_MAIN_DeleteScrollWindow(u8 *p)
{
    BGWINFRM_Delete(*(struct WinMgr * *)&((struct Obj00085 *)p)->f20);
}
