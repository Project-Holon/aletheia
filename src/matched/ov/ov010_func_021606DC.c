/*
 * function: EVENT_SHORTCUT_MENU_OpenMessage
 * address:  0x021606DC
 * packet:   pkt_ov010_021606DC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 *   SCRIPT_SYS_GetEventScriptWork  0x021589D0  thumb  ov010
 *   SCRIPT_WORK_SetParams  0x02159058  thumb  ov010
 */

typedef unsigned int u32;

typedef unsigned short u16;
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern int SCRIPT_SYS_GetEventScriptWork(int a0);
extern int SCRIPT_WORK_SetParams(int a, int b, int c, int d, u16 e);

void *EVENT_SHORTCUT_MENU_OpenMessage(void *p, u32 a)
{
    void *h;

    h = SCRIPT_SYS_CreateScriptEventSimple((int)p, 0x7D6, 0, 0x15);
    SCRIPT_WORK_SetParams(SCRIPT_SYS_GetEventScriptWork((int)h), a, 0, 0, 0);
    return h;
}
