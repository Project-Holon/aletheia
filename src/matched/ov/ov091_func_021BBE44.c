/*
 * unit:     yes
 * function: PLIST_MENU_DeleteTaskMenuWin, PLIST_MENU_UpdateTaskMenuWin, PLIST_MENU_SetTaskMenuWinActive
 * address:  0x021BBE44
 * packet:   pkt_021BBE44
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three null-guarded wrappers, each into an ARM9 routine.
 *
 * symbols:
 *   APP_TASKMENU_WIN_Delete  0x02028148  thumb
 *   APP_TASKMENU_WIN_Update  0x02028178  thumb
 *   APP_TASKMENU_WIN_SetActive  0x02028218  thumb
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Obj;
extern void APP_TASKMENU_WIN_Delete(u8 *p);
extern void APP_TASKMENU_WIN_Update(u8 *p);
extern void APP_TASKMENU_WIN_SetActive(struct Obj *obj, u32 a);

void PLIST_MENU_DeleteTaskMenuWin(int x)
{
    if (x != 0)
        APP_TASKMENU_WIN_Delete((u8 *)x);
}

void PLIST_MENU_UpdateTaskMenuWin(int x)
{
    if (x != 0)
        APP_TASKMENU_WIN_Update((u8 *)x);
}

void PLIST_MENU_SetTaskMenuWinActive(int x, int f)
{
    if (x != 0)
        APP_TASKMENU_WIN_SetActive((struct Obj *)x, f);
}
