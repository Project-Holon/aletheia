/*
 * function: func_021D5E30
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
 *   func_021D7898 0x021D7898 thumb ov120
 *   func_021D5FC4 0x021D5FC4 thumb ov120
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
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
extern void func_021D7898(char *p);
extern void func_021D5FC4(u8 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);
int func_021D5E30(void *p, int a, int b, u8 *q)
{
    func_0200F7F4();
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GFL_NET_GetRunState()) GFL_NET_COMMAND_DeleteCommandTable(0x2200);
    if (((struct Obj05348 *)q)->f34) APP_TASKMENU_WIN_Delete(((struct Obj05348 *)q)->f34);
    if (((struct Obj05348 *)q)->f38) APP_TASKMENU_CloseMenu(((struct Obj05348 *)q)->f38);
    func_021D7898(((struct Obj05348 *)q)->f40);
    func_021D5FC4(((struct Obj05348 *)q)->f3C);
    func_020315D4(p);
    func_020306F0(31);
    return 1;
}
