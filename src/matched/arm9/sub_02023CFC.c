/*
 * function: WIPE_SUB_RequestWindowVisible
 * address:  0x02023CFC
 * packet:   pkt_02023AB0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_AddMainTask  0x020056A0  thumb
 *   sub_02023D94  0x02023D94  thumb
 */

typedef unsigned int u32;

extern void *GFL_USE_AddMainTask(void *cb, void *param, u32 flag);
struct Args2;
extern u32 sub_02023D94(void *obj, struct Args2 *args);

struct Struct_02023CFC {
    void *val;
    u32 idx;
};

void WIPE_SUB_RequestWindowVisible(struct Struct_02023CFC *table, void *val, u32 idx)
{
    struct Struct_02023CFC *entry = &table[idx];

    entry->val = val;
    entry->idx = idx;
    GFL_USE_AddMainTask(sub_02023D94, entry, 1);
}
