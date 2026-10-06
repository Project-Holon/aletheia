/*
 * function: func_021F8908
 * address: 0x021F8908
 * packet: pkt_ov135_021F8908
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Builds a message menu: reads the entry range for an id, allocates the table
 * and fills one slot per entry. The slot call takes five arguments (heap id
 * 0x48 on the stack), as in the other matched callers of func_0201F878 (the
 * arm9 definition lists four parameters; the fifth is passed but not read).
 * Closed with opt_common_subs off: the original does not share start + i
 * between the table index and the tag. 2026-10-05 (P21): plain form 16 bytes
 * off, only that pragma closes it. Table extern is not const (const gave 18).
 *
 * symbols:
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   func_021F88D8 0x021F88D8 thumb ov135
 *   tbl_022030E8 0x022030E8 data a2
 */
#pragma opt_common_subs off
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021F88D8(u32 id, u32 *start);
extern void *func_0201F81C(u32 n, u32 heap);
struct Slot;
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern u16 tbl_022030E8[];
int func_021F8908(void **menu, void *msg, int id)
{
    int i;
    int count;
    u32 start;
    count = func_021F88D8(id, &start);
    *menu = func_0201F81C(count, 0x48);
    for (i = 0; (i < count) ? 1 : 0; i++) {
        func_0201F878(*menu, (u32)msg, tbl_022030E8[start + i], start + i + 1, 0x48);
    }
    return count;
}
#pragma opt_common_subs reset
