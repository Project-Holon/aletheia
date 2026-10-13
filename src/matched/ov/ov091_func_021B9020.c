/*
 * function: POKELIST_RunContextMenu
 * address:  0x021B9020
 * packet:   pkt_ov091_021B9020
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKELIST_EnterMenuPhase  0x021B907C  thumb  ov091
 *   POKELIST_CloseContextMenu  0x021B90F8  thumb  ov091
 *   POKELIST_DispatchMenuChoice  0x021B916C  thumb  ov091
 *   PLIST_MENU_Update  0x021BBBD8  thumb  ov091
 *   PLIST_MENU_GetSelectedCommand  0x021BBBE4  thumb  ov091
 */

typedef unsigned char u8;

extern void POKELIST_EnterMenuPhase(u8 *p);
extern void POKELIST_CloseContextMenu(u8 *p);
extern void POKELIST_DispatchMenuChoice(u8 *p);
extern void PLIST_MENU_Update(int unused, int *q);
extern unsigned int PLIST_MENU_GetSelectedCommand(int a, unsigned char *b);

#define W(o) (*(int *)(p + (o)))

void POKELIST_RunContextMenu(u8 *p)
{
    int r;

    switch (p[0xe]) {
    case 0:
        POKELIST_EnterMenuPhase(p);
        p[0xe] = 1;
        break;
    case 1:
        PLIST_MENU_Update((int)p, (int *)W(0x154));
        r = PLIST_MENU_GetSelectedCommand((int)p, (unsigned char *)((int *)W(0x154)));
        if (r != 0x17) {
            W(0x3c) = r;
            p[0xe] = 2;
        }
        if (*(u8 *)(W(0x280) + 0x63) == 1) {
            p[0xe] = 2;
        }
        break;
    case 2:
        POKELIST_CloseContextMenu(p);
        POKELIST_DispatchMenuChoice(p);
        break;
    }
}
