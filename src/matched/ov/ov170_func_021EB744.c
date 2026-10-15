/*
 * function: BOX2_SEQ_AddTextFrame
 * address: 0x021EB744
 * packet: pkt_ov170_021EB744
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_SEQ_AddBmpWinFrame 0x021EB708 thumb ov170
 */
#include "../include/Obj02213.h"
struct WinMgr;
extern void BOX2_SEQ_AddBmpWinFrame(void *m, unsigned i, void *d);
void BOX2_SEQ_AddTextFrame(char *p)
{
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 0, ((struct Obj02213 *)p)->f104);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 1, ((struct Obj02213 *)p)->f10C);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 2, ((struct Obj02213 *)p)->f114);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 3, ((struct Obj02213 *)p)->f11C);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 4, ((struct Obj02213 *)p)->f124);
    BOX2_SEQ_AddBmpWinFrame(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 5, ((struct Obj02213 *)p)->f12C);
}
