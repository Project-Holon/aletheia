/*
 * function: SHORTCUT_MENU_ListMoveCallback
 * address:  0x021C576C
 * packet:   pkt_ov021_021C576C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Raises the done flag on map object 0x13 (EXACT*: pad).
 *
 * symbols:
 *   BMP_MENULIST_GetAttr  0x02020350  thumb  arm9
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Obj;
extern u32 BMP_MENULIST_GetAttr(struct Obj *obj, u32 what);

void SHORTCUT_MENU_ListMoveCallback(void *a)
{
    *(u32 *)(BMP_MENULIST_GetAttr(a, 0x13) + 0x44) = 1;
}
