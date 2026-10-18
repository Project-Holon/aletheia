/*
 * function: GSYNC_MENU_StateSetupButtons
 * address: 0x021D4A04
 * packet: pkt_ov123_021D4A04
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: one-word struct = {0} keeps add r1, sp then str [r1]; scalar/array sink the address.
 * symbols:
 *   GSYNC_MENU_CreateButtonWindows 0x021D45F4 thumb ov123
 *   BUTTON_MAN_Create 0x02051B84 arm
 *   GSYNC_MENU_RunButtonCallback 0x021D4778 thumb ov123
 *   GSYNC_MENU_OnButtonPressed 0x021D4BA8 thumb ov123
 *   GSYNC_MENU_StateButtonsActive 0x021D4CA0 thumb ov123
 *   sGsyncMenuButtonWinDefs 0x021DA9C0 data a4
 *   d_021DA640 0x021DA640 data a4
 *   d_021DA648 0x021DA648 data a4
 *   GSYNC_MENU_ChangeState 0x021D4244 thumb ov123
 */
#include "../include/Obj10434.h"
typedef unsigned short u16;
extern void GSYNC_MENU_CreateButtonWindows(int, void *, char *, void *, void *, void *);
typedef unsigned char  u8;
extern void *BUTTON_MAN_Create(u8 *a0, int a1, int a2, int a3);
extern void GSYNC_MENU_RunButtonCallback(void);
extern int GSYNC_MENU_OnButtonPressed(int n, char *p);
extern void GSYNC_MENU_StateButtonsActive(char *p);
extern char sGsyncMenuButtonWinDefs[];
extern int d_021DA640[];
extern int d_021DA648[];
extern void GSYNC_MENU_ChangeState(char *, void *, int);
void GSYNC_MENU_StateSetupButtons(char *p)
{
    struct { int value; } zero = {0};
    GSYNC_MENU_CreateButtonWindows(1, &zero, p, sGsyncMenuButtonWinDefs, d_021DA640, d_021DA640 + 1);
    ((struct Obj10434 *)p)->f20 = BUTTON_MAN_Create((u8 *)d_021DA648, (int)GSYNC_MENU_RunButtonCallback, (int)p, ((struct Obj10434 *)p)->fC);
    ((struct Obj10434 *)p)->f4 = GSYNC_MENU_OnButtonPressed;
    GSYNC_MENU_ChangeState(p, GSYNC_MENU_StateButtonsActive, 0x321);
}
