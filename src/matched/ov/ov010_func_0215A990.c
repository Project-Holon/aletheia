/*
 * function: SCRCMD_WORK_WaitMenuOrCancel
 * address: 0x0215A990
 * packet: pkt_ov010_0215A990
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: result declared before pointer gives original r4/result, r5/base.
 * symbols:
 *   SCRCMD_WORK_WaitMenu 0x0215A954 thumb ov010
 *   KEY_GetTrg 0x020362DC arm
 *   SCRCMD_WORK_DeleteMenu 0x0215A920 thumb ov010
 */
#include "../include/Obj04148.h"
#include "../include/Obj12286.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int SCRCMD_WORK_WaitMenu(u8 *);
extern u32 KEY_GetTrg(void);
extern int SCRCMD_WORK_DeleteMenu(int a0);
int SCRCMD_WORK_WaitMenuOrCancel(u8 *a) {
 int v;
 u8 *p;
 p = *(u8 * *)&((struct Obj12286 *)a)->f20 + 52;
 v = SCRCMD_WORK_WaitMenu(a);
 if (v == 0 && (KEY_GetTrg() & 1024)) {
 SCRCMD_WORK_DeleteMenu((int)p);
 **(u16 * *)&((struct Obj04148 *)p)->f8 = 65533;
 v = 1;
 }
 return v;
}
