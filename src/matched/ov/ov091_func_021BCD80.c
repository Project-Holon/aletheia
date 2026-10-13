/*
 * function: PLIST_MENU_ExitTimer
 * address:  0x021BCD80
 * packet:   pkt_ov091_021BCD80
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_BATTLE_DeleteTimerWindows  0x021BD61C  thumb  ov091
 *   PLIST_BATTLE_DeleteTeamPanel  0x021BD18C  thumb  ov091
 *   PLIST_MENU_Nop  0x021BD058  thumb  ov091
 *   PLIST_MENU_DeleteBank  0x021BCE9C  thumb  ov091
 */
#include "../include/Obj01888.h"
#include "../include/Obj20910.h"
#include "../include/Obj20911.h"
#include "../include/Obj20912.h"

extern void PLIST_BATTLE_DeleteTimerWindows(char *a);
extern void PLIST_BATTLE_DeleteTeamPanel(char *a, char *p);
extern void PLIST_MENU_Nop(char *a);
extern void PLIST_MENU_DeleteBank(unsigned int p);

void PLIST_MENU_ExitTimer(char *a)
{
    if (((struct Obj20910 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f90 == 1)
        PLIST_BATTLE_DeleteTimerWindows(a);
    if (((struct Obj20911 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f8C == 1) {
        switch (((struct Obj20912 *)(*(char * *)&((struct Obj01888 *)a)->f280))->f64) {
        case 1:
            PLIST_BATTLE_DeleteTeamPanel(a, (char *)(((struct Obj01888 *)a)->f1F4));
            break;
        case 2:
            PLIST_BATTLE_DeleteTeamPanel(a, (char *)(((struct Obj01888 *)a)->f1F0));
            PLIST_BATTLE_DeleteTeamPanel(a, (char *)(((struct Obj01888 *)a)->f1F4));
            PLIST_BATTLE_DeleteTeamPanel(a, (char *)(((struct Obj01888 *)a)->f1F8));
            break;
        }
    }
    PLIST_MENU_Nop(a);
    PLIST_MENU_DeleteBank((unsigned int)a);
}
