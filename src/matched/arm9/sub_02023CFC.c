/*
 * function: func_02023CFC
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
 *   sub_020056A0  0x020056A0  thumb
 *   sub_02023D94  0x02023D94  thumb
 */

typedef unsigned int u32;

extern void *sub_020056A0(void *cb, void *param, u32 flag);
struct Args2;
extern u32 sub_02023D94(void *obj, struct Args2 *args);

struct Struct_02023CFC {
    void *val;
    u32 idx;
};

void func_02023CFC(struct Struct_02023CFC *table, void *val, u32 idx)
{
    struct Struct_02023CFC *entry = &table[idx];

    entry->val = val;
    entry->idx = idx;
    sub_020056A0(sub_02023D94, entry, 1);
}
