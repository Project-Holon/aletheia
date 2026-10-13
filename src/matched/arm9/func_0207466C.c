/*
 * function: NNS_SndArcGetFileAddress
 * address:  0x0207466C
 * packet:   pkt_0207457C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gNNSSndCurrentArc  0x0214EA50  data
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

extern struct Context *gNNSSndCurrentArc;

u32 NNS_SndArcGetFileAddress(u32 idx)
{
    struct Context *ctx = gNNSSndCurrentArc;
    struct TableHeader *tbl = ctx->table;
    if (idx >= tbl->count) {
        return 0;
    }
    return tbl->entries[idx].field8;
}
