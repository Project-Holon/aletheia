/*
 * function: func_021F87E0
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
 */
typedef unsigned int u32;
typedef struct { u32 id; int coords; } Entry;
extern const Entry tbl_0220301C[], tbl_02202FC4[];
extern void *func_0201F81C(u32 n, u32 heap);
struct Slot;
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
int func_021F87E0(void **menu, void *msg, int kind)
{
    const Entry *table;
    int i;
    int count;
    if (kind == 0) { table = tbl_0220301C; count = 12; }
    else { table = tbl_02202FC4; count = 11; }
    *menu = func_0201F81C(count, 0x48);
    for (i = 0; i < count; i++) {
        func_0201F878(*menu, (u32)msg, table[i].id, i, 0x48);
    }
    return count;
}
