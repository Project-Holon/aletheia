/*
 * function: SHORTCUT_MENU_OnKeyUp
 * address:  0x021C5440
 * packet:   pkt_ov021_021C5440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Message-window step: opens the window and plays SE 0x548, or scrolls to
 * the cursor line. Load-bearing: int-typed line count (stops (c-1)-(n-1)
 * folding) and the u16 local for the line index.
 *
 * symbols:
 *   SHORTCUT_MENU_DeleteList  0x021C59A8  thumb  ov021
 *   SHORTCUT_MENU_CreateList  0x021C58CC  thumb  ov021
 *   SHORTCUT_MENU_SetActorsY  0x021C59F8  thumb  ov021
 *   BMP_MENULIST_GetPos  0x020202FC  thumb  arm9
 *   BMP_MENULIST_GetRowY  0x02020324  thumb  arm9
 *   BMP_MENULIST_GetAttr  0x02020350  thumb  arm9
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0;
    void *msg;
    u8 pad8[0x1C];
    u32 f24;
    u8 pad28[0xC];
    u16 h34;
    u16 pad36;
    u8 pad38[8];
    u32 f40;
} S;

struct Obj;
extern u32 BMP_MENULIST_GetAttr(struct Obj *obj, u32 what);
extern int SHORTCUT_MENU_DeleteList(u32 a, u32 b, u32 c);
extern void SHORTCUT_MENU_CreateList(char *p, u16 a, u16 b, u32 heap);
extern void GFL_USE_PlaySeDefaultVolume(u32 se);
extern void BMP_MENULIST_GetPos(struct Obj *obj, u16 *a, u16 *b);
extern u16 BMP_MENULIST_GetRowY(struct Obj *obj, u32 n);
extern void SHORTCUT_MENU_SetActorsY(S *p, int v);

void SHORTCUT_MENU_OnKeyUp(S *p, int mode, u32 c, u32 *done)
{
    int n;
    u16 tmp;
    u16 h;

    if (mode == 0) {
        n = BMP_MENULIST_GetAttr(p->msg, 3);
        SHORTCUT_MENU_DeleteList((u32)p, 0, 0);
        SHORTCUT_MENU_CreateList((char *)p, (c - 1) - (n - 1), n - 1, p->h34);
        if (p->f24 == 1)
            p->f40 = 1;
        GFL_USE_PlaySeDefaultVolume(0x548);
        *done = 1;
    } else if (p->f40 == 1 && p->f24 == 1) {
        BMP_MENULIST_GetPos(p->msg, 0, &tmp);
        h = BMP_MENULIST_GetRowY(p->msg, tmp) >> 3;
        SHORTCUT_MENU_SetActorsY(p, (h + 0xC) * 8);
        p->f40 = 0;
        *done = 1;
    }
}
