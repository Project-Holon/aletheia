/*
 * unit:     yes
 * function: POKELIST_PollContextMenuChoice, POKELIST_OpenMenuWithCallback
 * address:  0x021B97D4
 * packet:   pkt_ov091_021B97D4
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * POKELIST_OpenMenuWithCallback is an unlabelled tail-call stub inside the extent.
 *
 * symbols:
 *   PLIST_MENU_Update  0x021BBBD8  thumb  ov091
 *   PLIST_MENU_GetSelectedCommand  0x021BBBE4  thumb  ov091
 *   PLIST_MENU_Close  0x021BBBA0  thumb  ov091
 *   PLIST_MENU_OpenFixed  0x021BBB40  thumb  ov091
 */

typedef unsigned char u8;

extern void PLIST_MENU_Update(int unused, int *q);
extern unsigned int PLIST_MENU_GetSelectedCommand(int a, unsigned char *b);
extern void PLIST_MENU_Close(unsigned char *a, unsigned char *b);
extern void PLIST_MENU_OpenFixed(u8 *a, u8 *b);

#define W(o) (*(int *)(p + (o)))

void POKELIST_PollContextMenuChoice(u8 *p)
{
    int r;

    PLIST_MENU_Update((int)p, (int *)W(0x154));
    r = PLIST_MENU_GetSelectedCommand((int)p, (unsigned char *)((int *)W(0x154)));
    if (r != 0x17) {
        ((void (*)(u8 *, int))W(0x14c))(p, r);
        PLIST_MENU_Close((unsigned char *)((int)p), (unsigned char *)((int *)W(0x154)));
    }
}

void POKELIST_OpenMenuWithCallback(u8 *p, int a1)
{
    p[0xc] = 9;
    W(0x14c) = a1;
    PLIST_MENU_OpenFixed(p, (u8 *)W(0x154));
}
