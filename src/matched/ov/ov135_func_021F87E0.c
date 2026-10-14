/*
 * function: WORLDTRADE_DEPOSIT_CreateGenderMenu
 * address: 0x021F87E0
 * packet: pkt_ov135_021F87E0
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   tbl_0220301C 0x0220301C data a4
 *   tbl_02202FC4 0x02202FC4 data a4
 *   BMP_MENUWORK_Create  0x0201F81C  thumb  arm9
 *   BMP_MENUWORK_AddMsgItem  0x0201F878  thumb  arm9
 */
typedef unsigned int u32;
typedef struct { u32 id; int coords; } Entry;
extern const Entry tbl_0220301C[], tbl_02202FC4[];
extern void *BMP_MENUWORK_Create(u32 n, u32 heap);
struct Slot;
extern void BMP_MENUWORK_AddMsgItem(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
int WORLDTRADE_DEPOSIT_CreateGenderMenu(void **menu, void *msg, int kind)
{
    const Entry *table;
    int i;
    int count;
    if (kind == 0) { table = tbl_0220301C; count = 12; }
    else { table = tbl_02202FC4; count = 11; }
    *menu = BMP_MENUWORK_Create(count, 0x48);
    for (i = 0; i < count; i++) {
        BMP_MENUWORK_AddMsgItem(*menu, (u32)msg, table[i].id, i, 0x48);
    }
    return count;
}
