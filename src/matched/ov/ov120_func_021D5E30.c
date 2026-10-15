/*
 * function: GTSNEGO_DISP_Delete
 * address: 0x021D5E30
 * packet: pkt_ov120_021D5E30
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: 2-byte zero alignment padding at 0x021D5E86.
 * symbols:
 *   func_0200F7F4 0x0200F7F4 thumb
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 *   APP_TASKMENU_WIN_Delete 0x02028148 thumb
 *   APP_TASKMENU_CloseMenu 0x02027858 thumb
 *   GTSNEGO_MSG_Delete 0x021D7898 thumb ov120
 *   GTSNEGO_DISP_DeleteMsgSystem 0x021D5FC4 thumb ov120
 *   func_020315D4 0x020315D4 arm
 *   GFL_HEAP_DeleteChecked 0x020306F0 arm
 */
#include "../include/Obj05348.h"
typedef unsigned char u8;
extern void func_0200F7F4(void);
extern unsigned int WIPE_SYS_EndCheck(void);
extern int GFL_NET_GetRunState(void);
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned int);
struct S020315D4;
struct TaskMenu;
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);
extern void GTSNEGO_MSG_Delete(char *p);
extern void GTSNEGO_DISP_DeleteMsgSystem(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void GFL_HEAP_DeleteChecked(unsigned int heap);
int GTSNEGO_DISP_Delete(void *p, int a, int b, u8 *q)
{
    func_0200F7F4();
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) GFL_NET_COMMAND_DeleteCommandTable(0x2200);
    if (((struct Obj05348 *)q)->f34) APP_TASKMENU_WIN_Delete(((struct Obj05348 *)q)->f34);
    if (((struct Obj05348 *)q)->f38) APP_TASKMENU_CloseMenu(((struct Obj05348 *)q)->f38);
    GTSNEGO_MSG_Delete(((struct Obj05348 *)q)->f40);
    GTSNEGO_DISP_DeleteMsgSystem(((struct Obj05348 *)q)->f3C);
    func_020315D4(p);
    GFL_HEAP_DeleteChecked(31);
    return 1;
}
