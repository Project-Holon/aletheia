/*
 * function: func_021D8418
 * address:  0x021D8418
 * packet:   pkt_021D8418
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   APP_TASKMENU_CloseMenu  0x02027858  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

struct TaskMenu;
extern void APP_TASKMENU_CloseMenu(struct TaskMenu *m);

void func_021D8418(int a)
{
    if (a != 0) {
        *(volatile u16 *)0x04000050 = 0;
        APP_TASKMENU_CloseMenu((struct TaskMenu *)a);
    }
}
