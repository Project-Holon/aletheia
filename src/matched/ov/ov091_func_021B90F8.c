/*
 * function: POKELIST_CloseContextMenu
 * address:  0x021B90F8
 * packet:   pkt_ov091_021B90F8
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PLIST_MENU_Close  0x021BBBA0  thumb  ov091
 *   PLIST_MESSAGE_CloseWindow  0x021BB7A4  thumb  ov091
 *   POKELIST_IsItemMode  0x021B9A84  thumb  ov091
 *   POKELIST_HasBackButton  0x021B9AB4  thumb  ov091
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02041570  0x02041570  arm
 *   func_020355C4  0x020355C4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef unsigned int   u32;
extern void PLIST_MENU_Close(unsigned char *a, unsigned char *b);
extern void PLIST_MESSAGE_CloseWindow(void *p, u32 *s);
extern int POKELIST_IsItemMode(u32 p);
extern int POKELIST_HasBackButton(u8 *p);
struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0207D63C(u16 *r, int a, int b, int c, int d);
extern void func_02041570(int channel, u16 val);
extern u8 func_020355C4(void);

#define W(o) (*(int *)(p + (o)))

void POKELIST_CloseContextMenu(u8 *p)
{
    PLIST_MENU_Close((unsigned char *)((int)p), (unsigned char *)((int *)W(0x154)));
    PLIST_MESSAGE_CloseWindow(p, (u32 *)W(0x150));
    if (POKELIST_IsItemMode((u32)p) == 1 || POKELIST_HasBackButton(p) == 0) {
        func_0204B3DC((struct Obj *)W(0x1e0), 0);
    } else {
        func_0204B3DC((struct Obj *)W(0x1e0), 1);
    }
    if (W(0x3c) != 4 && W(0x3c) != 5) {
        func_0207D63C((u16 *)0x04000050, 0x14, 8, 0x10, 0xa);
        W(0x10) = 0;
    }
    func_02041570(0, 0);
    W(8) = func_020355C4();
}
