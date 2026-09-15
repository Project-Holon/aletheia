/*
 * function: func_02074694
 * address:  0x02074694
 * packet:   pkt_0207457C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ptr_0214EA50  0x0214EA50  data
 */

typedef unsigned int u32;

struct TableEntry {
    u32 offset;
    u32 size;
    u32 field8;
    u32 fieldC;
};

struct TableHeader {
    u32 unk0;
    u32 unk4;
    u32 count;
    struct TableEntry entries[1];
};

struct Context {
    char pad[0x88];
    struct TableHeader *table;
};

extern struct Context *ptr_0214EA50;

void func_02074694(u32 idx, u32 val)
{
    struct Context *ctx = ptr_0214EA50;
    struct TableHeader *tbl = ctx->table;
    tbl->entries[idx].field8 = val;
}
