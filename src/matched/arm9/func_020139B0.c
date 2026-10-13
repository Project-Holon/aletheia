/*
 * function: ZONEDATA_Init
 * address:  0x020139B0
 * packet:   pkt_02013528
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked on: the `string` class, and permanently.  Every concrete byte of
 * this function is reproduced; the only unresolved relocation is the ABS32 at
 * +0x90 naming "zonedata.c" at 0x020A72B0, and no pool anywhere else in the
 * image holds that word.  The string class cannot rescue it either: the six
 * bytes immediately before 0x020A72B0 are the { u16 key; u16 value }
 * substitution table ZONEDATA_GetChangedZoneId reads (0x0000 -> 0x01a8, 0x0126 -> 0x0127),
 * not a preceding string's terminator, so attest_string's condition (5) fails.
 * See docs/idioms/a-string-after-a-data-table-has-no-witness.md.  Nothing in
 * the C can change this; it is evidence-starved, not mistranslated.
 *
 * symbols:
 *   g_ZoneDataMgr  0x02146264  data
 *   sZonedataFile     0x020A72B0  data
 *   func_02030734     0x02030734  arm
 *   func_020490F4     0x020490F4  arm
 *   ARC_UTIL_LoadMemberWithSize     0x0204A298  arm
 *
 * The constructor of the zone-header subsystem, and the function that names
 * the original source file: it passes "zonedata.c" (0x020A72B0) and line 0x60
 * to the allocator, so the 0x4c byte object it builds at 0x02146264 is the
 * ZoneData manager, and every accessor built on ZONEDATA_GetHeader reads through it.
 *
 * Three things this function pins down about the on-disk zone data.
 *
 * +0x00 is a persistent archive handle opened by func_020490F4(0x0c, heap).
 * ARC_TOOL_OpenArchive, which func_020490F4 calls to bind the handle, indexes a 235
 * entry char* table at 0x020A6C58 (installed by ARC_TOOL_SetTable from
 * 0x020055FA with count 0xeb) by that same id, and entry 0x0c of that table
 * is the string "a/0/1/2".  ZONEDATA_GetHeader then reads records out of that
 * handle at 0x30 * id for 0x30 bytes, so the zone header table is sub-file 0
 * of a/0/1/2 with a 48-byte stride.
 *
 * +0x34 is seeded with 0x1ab = 427 before any record is cached.  a/0/1/2's
 * only sub-file is 20496 bytes, exactly 427 * 48, so 427 is one past the last
 * zone id and the seed is a deliberate never-matches cache tag rather than a
 * real id.  That count is content, not code, and is the kind of constant that
 * may differ in White; nothing here reads a version identifier.
 *
 * The three ARC_UTIL_LoadMemberWithSize calls each load a whole sub-file into the heap and
 * write back its byte size through the fifth argument: (0x51, 13) is
 * a/0/8/1 sub-file 13, (0x52, 1) is a/0/8/2 sub-file 1 and (0x95, 0) is
 * a/1/4/9 sub-file 0, by the same id-to-name table as above.  Each size is
 * divided by four into a companion count field (+0x40 u16, +0x42 u8,
 * +0x43 u8), and func_02013EEC, func_02013F2C and func_02013F6C walk the
 * matching pointer as an array of 4-byte { u16 key; u16 value } entries, so
 * all three are (zone id -> value) side tables, not part of the record.
 *
 * Two locals, not one: the first two sizes land in the local at sp+8 and the
 * third in a separate local at sp+4.  Declaration order is stack order, so
 * the twice-used local has to be declared first.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/ZONEDATA_Init.c \
 *       --func ZONEDATA_Init --addr 0x020139B0 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct ZoneDataMgr {
    void *archive;
    u8    record[0x34 - 0x04];
    u16   cached_id;
    u16   pad36;
    void *table38;
    void *table3c;
    u16   count40;
    u8    count42;
    u8    count43;
    void *table44;
    u8    subst_on[0x4c - 0x48];
};

extern struct ZoneDataMgr *g_ZoneDataMgr;
extern const char sZonedataFile[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int ARC_UTIL_LoadMemberWithSize(int a0, int a1, int a2, int a3, u32 *out);

void ZONEDATA_Init(u32 heap)
{
    u32 size;
    u32 size2;

    if (g_ZoneDataMgr != 0)
        return;

    g_ZoneDataMgr = func_02030734(heap, 0x4c, 1, sZonedataFile, 0x60);
    g_ZoneDataMgr->archive = func_020490F4(0x0c, heap);

    g_ZoneDataMgr->table38 = (void *)ARC_UTIL_LoadMemberWithSize(0x51, 13, 0, heap, &size);
    g_ZoneDataMgr->count40 = size >> 2;

    g_ZoneDataMgr->table3c = (void *)ARC_UTIL_LoadMemberWithSize(0x52, 1, 0, heap, &size);
    g_ZoneDataMgr->count42 = size >> 2;

    g_ZoneDataMgr->table44 = (void *)ARC_UTIL_LoadMemberWithSize(0x95, 0, 0, heap, &size2);
    g_ZoneDataMgr->count43 = size2 >> 2;

    g_ZoneDataMgr->cached_id = 0x1ab;
}
