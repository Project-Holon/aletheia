/*
 * function: func_021EB744
 * address: 0x021EB744
 * packet: pkt_ov170_021EB744
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EB708 0x021EB708 thumb ov170
 */
#include "../include/Obj02213.h"
struct WinMgr;
extern void func_021EB708(void *m, unsigned i, void *d);
void func_021EB744(char *p)
{
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 0, ((struct Obj02213 *)p)->f104);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 1, ((struct Obj02213 *)p)->f10C);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 2, ((struct Obj02213 *)p)->f114);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 3, ((struct Obj02213 *)p)->f11C);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 4, ((struct Obj02213 *)p)->f124);
    func_021EB708(*(struct WinMgr * *)&((struct Obj02213 *)p)->f74, 5, ((struct Obj02213 *)p)->f12C);
}
