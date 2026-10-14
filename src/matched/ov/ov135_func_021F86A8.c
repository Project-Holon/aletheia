/*
 * function: WORLDTRADE_DEPOSIT_CreateSpeciesMenu
 * address: 0x021F86A8
 * packet: pkt_ov135_021F86A8
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   tbl_02203B84 0x02203B84 data a2
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 *   ZUKAN_SAVE_IsSeen  0x0200D064  thumb  arm9
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 tbl_02203B84[];
struct Blk37;
extern u32 ZUKAN_SAVE_IsSeen(struct Blk37 *p, u16 id);
extern void *BMP_MENUWORK_Create(u32 n, u32 heap);
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
int WORLDTRADE_DEPOSIT_CreateSpeciesMenu(void **menu, void *msg, void *endmsg, u16 *list, u32 unused4, u32 unused5, u32 kind, void *bag)
{
    int i;
    int size;
    int count;
    int start;
    count = 0;
    start = tbl_02203B84[kind];
    size = tbl_02203B84[kind + 1] - start;
    for (i = 0; i < size; i++) {
        if (ZUKAN_SAVE_IsSeen(bag, list[start + i]) != 0) count++;
    }
    *menu = BMP_MENUWORK_Create(count + 1, 0x48);
    for (i = 0; i < size; i++) {
        if (ZUKAN_SAVE_IsSeen(bag, list[start + i]) != 0) {
            BMP_MENUWORK_AddMsgItem(*menu, (u32)msg, list[start + i], list[start + i], 0x48);
        }
    }
    BMP_MENUWORK_AddMsgItem(*menu, (u32)endmsg, 0x85, -2, 0x48);
    return count + 1;
}
