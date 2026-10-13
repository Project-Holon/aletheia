/*
 * function: SCRCMD_WORK_WaitMenu
 * address: 0x0215A954
 * packet: pkt_ov010_0215A954
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FIELD_MSGBG_MenuFuncMain 0x021909E4 thumb ov021
 *   SCRCMD_WORK_DeleteMenu 0x0215A920 thumb ov010
 */
#include "../include/Obj04148.h"
#include "../include/Obj12286.h"
typedef unsigned char u8;
typedef unsigned short u16;
struct Handle;
extern int FIELD_MSGBG_MenuFuncMain(struct Handle *h);
extern int SCRCMD_WORK_DeleteMenu(int a0);
int SCRCMD_WORK_WaitMenu(u8 *a) {
 u8 *p;
 int v;
 p = *(u8 * *)&((struct Obj12286 *)a)->f20 + 52;
 v = FIELD_MSGBG_MenuFuncMain(((struct Obj04148 *)p)->f1C);
 if (v == -1) return 0;
 SCRCMD_WORK_DeleteMenu((int)p);
 if (v != -2) **(u16 * *)&((struct Obj04148 *)p)->f8 = v;
 else **(u16 * *)&((struct Obj04148 *)p)->f8 = 65534;
 return 1;
}
