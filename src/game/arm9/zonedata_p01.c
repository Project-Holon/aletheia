/*
 * file:     zonedata_p01.c
 * unit:     yes
 * function: func_020139B0, func_02013A48, func_02013A80, func_02013A94
 * address:  0x020139B0
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_sub02013AD0Obj  0x02146264  data
 *   sZonedataFile     0x020A72B0  data
 *   func_02030734     0x02030734  arm
 *   func_020490F4     0x020490F4  arm
 *   func_0204A298     0x0204A298  arm
 *   func_020307B0     0x020307B0  arm
 *   func_02049238     0x02049238  arm
 *   sub_020A72A8_Key  0x020A72A8  data
 *   sub_020A72AA_Val  0x020A72AA  data
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

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *handle);
void func_020139B0(u32 heap);
void func_02013A48(void);
void sub_02013A80(u32 index, u8 on);
u16 func_02013A94(u32 key);
extern struct ZoneDataMgr *g_sub02013AD0Obj;
extern const char sZonedataFile[];
extern u16 sub_020A72A8_Key[];
extern u16 sub_020A72AA_Val[];


/*
 * Blocked on: the `string` class, and permanently.  Every concrete byte of
 * this function is reproduced; the only unresolved relocation is the ABS32 at
 * +0x90 naming "zonedata.c" at 0x020A72B0, and no pool anywhere else in the
 * image holds that word.  The string class cannot rescue it either: the six
 * bytes immediately before 0x020A72B0 are the { u16 key; u16 value }
 * substitution table func_02013A94 reads (0x0000 -> 0x01a8, 0x0126 -> 0x0127),
 * not a preceding string's terminator, so attest_string's condition (5) fails.
 * See docs/idioms/a-string-after-a-data-table-has-no-witness.md.  Nothing in
 * the C can change this; it is evidence-starved, not mistranslated.
 *
 * The constructor of the zone-header subsystem, and the function that names
 * the original source file: it passes "zonedata.c" (0x020A72B0) and line 0x60
 * to the allocator, so the 0x4c byte object it builds at 0x02146264 is the
 * ZoneData manager, and every accessor built on sub_02013AD0 reads through it.
 *
 * Three things this function pins down about the on-disk zone data.
 *
 * +0x00 is a persistent archive handle opened by func_020490F4(0x0c, heap).
 * func_02048DDC, which func_020490F4 calls to bind the handle, indexes a 235
 * entry char* table at 0x020A6C58 (installed by func_02048CEC from
 * 0x020055FA with count 0xeb) by that same id, and entry 0x0c of that table
 * is the string "a/0/1/2".  sub_02013AD0 then reads records out of that
 * handle at 0x30 * id for 0x30 bytes, so the zone header table is sub-file 0
 * of a/0/1/2 with a 48-byte stride.
 *
 * +0x34 is seeded with 0x1ab = 427 before any record is cached.  a/0/1/2's
 * only sub-file is 20496 bytes, exactly 427 * 48, so 427 is one past the last
 * zone id and the seed is a deliberate never-matches cache tag rather than a
 * real id.  That count is content, not code, and is the kind of constant that
 * may differ in White; nothing here reads a version identifier.
 *
 * The three func_0204A298 calls each load a whole sub-file into the heap and
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
 *   python tools/match.py one --src src/pending/func_020139B0.c \
 *       --func func_020139B0 --addr 0x020139B0 --cc 1.1p1 --thumb
 */
void func_020139B0(u32 heap)
{
    u32 size;
    u32 size2;

    if (g_sub02013AD0Obj != 0)
        return;

    g_sub02013AD0Obj = func_02030734(heap, 0x4c, 1, sZonedataFile, 0x60);
    g_sub02013AD0Obj->archive = func_020490F4(0x0c, heap);

    g_sub02013AD0Obj->table38 = (void *)func_0204A298(0x51, 13, 0, heap, &size);
    g_sub02013AD0Obj->count40 = size >> 2;

    g_sub02013AD0Obj->table3c = (void *)func_0204A298(0x52, 1, 0, heap, &size);
    g_sub02013AD0Obj->count42 = size >> 2;

    g_sub02013AD0Obj->table44 = (void *)func_0204A298(0x95, 0, 0, heap, &size2);
    g_sub02013AD0Obj->count43 = size2 >> 2;

    g_sub02013AD0Obj->cached_id = 0x1ab;
}


/*
 * A whole translation-unit range, matched as one byte range.
 *
 * 0x02013A80 is an unlabelled follower: it saves no lr, so disasm.py prints it
 * as the tail of func_02013A48 instead of as a function of its own, and
 * func_02013A48 alone verifies EXACT* for that reason.  Taking the two as one
 * 76-byte unit closes the star; seed 0x02013A80 into
 * layout/function_starts.txt anyway.
 *
 * The destructor of the zone-header subsystem allocated by func_020139B0, and
 * a second, independent reading of the manager's field map: it frees +0x44,
 * +0x3c and +0x38 with the plain heap free func_020307B0, which is what makes
 * those three heap buffers rather than pointers into the image, and closes
 * +0x00 with func_02049238 (archive close plus free), which is what makes
 * +0x00 an archive handle and not a fourth buffer.  The manager itself is
 * freed last and the global cleared.
 *
 * Release order is the reverse of the order func_020139B0 fills the fields
 * in, so the two functions together fix the field order as well as the types.
 *
 * The global is reloaded before every call because it is an ordinary extern,
 * not a same-file static: each `ldr r0, [r4]` in the original is a fresh read
 * of 0x02146264, and writing the frees through the global directly (rather
 * than caching it in a local) is what reproduces them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013A48.c \
 *       --func func_02013A48 --addr 0x02013A48 --cc 1.1p1 --thumb
 */
void func_02013A48(void)
{
    if (g_sub02013AD0Obj == 0)
        return;

    func_020307B0(g_sub02013AD0Obj->table44);
    func_020307B0(g_sub02013AD0Obj->table3c);
    func_020307B0(g_sub02013AD0Obj->table38);
    func_02049238(g_sub02013AD0Obj->archive);
    func_020307B0(g_sub02013AD0Obj);
    g_sub02013AD0Obj = 0;
}


/*
 * A whole translation-unit range, matched as one byte range.
 *
 * 0x02013A80 is an unlabelled follower: it saves no lr, so disasm.py prints it
 * as the tail of func_02013A48 instead of as a function of its own, and
 * func_02013A48 alone verifies EXACT* for that reason.  Taking the two as one
 * 76-byte unit closes the star; seed 0x02013A80 into
 * layout/function_starts.txt anyway.
 *
 * The destructor of the zone-header subsystem allocated by func_020139B0, and
 * a second, independent reading of the manager's field map: it frees +0x44,
 * +0x3c and +0x38 with the plain heap free func_020307B0, which is what makes
 * those three heap buffers rather than pointers into the image, and closes
 * +0x00 with func_02049238 (archive close plus free), which is what makes
 * +0x00 an archive handle and not a fourth buffer.  The manager itself is
 * freed last and the global cleared.
 *
 * Release order is the reverse of the order func_020139B0 fills the fields
 * in, so the two functions together fix the field order as well as the types.
 *
 * The global is reloaded before every call because it is an ordinary extern,
 * not a same-file static: each `ldr r0, [r4]` in the original is a fresh read
 * of 0x02146264, and writing the frees through the global directly (rather
 * than caching it in a local) is what reproduces them.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02013A48.c \
 *       --func func_02013A48 --addr 0x02013A48 --cc 1.1p1 --thumb
 */
void sub_02013A80(u32 index, u8 on)
{
    if (g_sub02013AD0Obj != 0)
        g_sub02013AD0Obj->subst_on[index] = on;
}


u16 func_02013A94(u32 key)
{
    int i;
    char *p = *(char **)0x02146264;

    for (i = 0; i < 2; i++) {
        if (*(u8 *)(p + 0x48 + i) != 0 && key == sub_020A72A8_Key[i * 2])
            return sub_020A72AA_Val[i * 2];
    }
}
