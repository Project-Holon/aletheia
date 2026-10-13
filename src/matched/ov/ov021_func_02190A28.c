/*
 * function: FIELD_MSGBG_CreateMenuItemsFromTable
 * address:  0x02190A28
 * packet:   pkt_ov021_02190A28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   FIELD_MSGBG_CreateMenuItems  0x02190A20  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Pair {
    u32 a;
    u32 b;
} Pair;

extern u32 FIELD_MSGBG_CreateMenuItems(int n, u32 d);
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

u32 FIELD_MSGBG_CreateMenuItemsFromTable(const Pair *arr, int n, u32 c, u16 d)
{
    u32 obj;
    int i;

    obj = FIELD_MSGBG_CreateMenuItems(n, d);
    for (i = 0; i < n; i++)
        BMP_MENUWORK_AddMsgItem((struct Slot *)obj, c, arr[i].a, arr[i].b, d);
    return obj;
}
