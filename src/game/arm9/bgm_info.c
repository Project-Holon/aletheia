/*
 * file:     bgm_info.c
 * unit:     yes
 * function: func_02006E40, func_02006E64, func_02006E7C, func_02006EA4
 * address:  0x02006E40
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from bgm_info.c at 0x02006E40 (__FILE__ anchor boundary, certain cut).
 *
 * symbols:
 *   func_02030734       0x02030734  arm
 *   func_020307B0       0x020307B0  arm
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);

struct BgmInfoTable {
    u8   count;
    u8   pad01[3];
    u16 *bgmId;
    u8  *issMode;
};
extern void func_02048F74(void *dst, u32 archiveId, u32 member, u32 offset, u32 *size);
void sub_02006EA4(struct BgmInfoTable *table, u32 heapId);
struct BgmInfoTable *sub_02006E40(u32 heapId);
extern const char sub_02006E40_File[];

/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * alias: the file identity is in the image.  sub_02006E40 and sub_02006EA4
 * both pass 0x020A7048 to the debug allocator at 0x02030734, and the bytes
 * at 0x020A7048 spell "bgm_info.c".  The string before it is "snd_mic.c",
 * whose terminator at 0x020A7045 plus two bytes of padding fixes 0x020A7048
 * by construction, so the address is carried by the `string` class: the two
 * pool words that name it are both inside this range and `literal` discards
 * them.  See "The string class" in docs/MATCHING.md.
 *
 * A twelve byte BGM info table holding a count and two parallel arrays: a u16
 * BGM id array at +4 and a u8 ISS mode array at +8, both allocated from the same heap
 * by sub_02006EA4 and both freed by sub_02006E64.  sub_02006E7C is the
 * lookup, a linear scan of the BGM id array returning the ISS mode at the same
 * index.
 *
 * Two things the bytes settle:
 *
 *  - sub_02006E7C saves r4 and r5 and no lr, so it is a leaf, and it still
 *    carries a label because the sweep accepts `push {r4, r5}` when the
 *    trace reaches it from a branch.  Its loop bound is signed (`ble` on the
 *    guard, `blt` on the back edge) even though the count is a `u8` field,
 *    which is the ordinary integer promotion of a byte compared against an
 *    `int` induction variable.
 *  - the fourth argument of the four func_02048F74 calls is a running
 *    counter, not a function of the loop index.  Written as `i * 3 + 1` and
 *    `i * 3 + 3` the compiler reassociates the multiply against the array
 *    index and computes the value inside the loop (`adds r6, r4, r1`), which
 *    is 49 bytes wrong; written as a variable stepped by three it produces
 *    the original's `adds r3, r6, #0` and `adds r3, r6, #2`.
 *  - where that variable is stepped decides two registers and one
 *    instruction.  The original materialises its value 1 as `adds r6, r4, #1`
 *    off the zero already in r4, immediately before the first allocation, so
 *    the increment has to sit between the first func_02048F74 call and the
 *    two allocations.  Move it after them and the compiler hoists the file
 *    name pool word into r7 instead, loading it once rather than twice, and
 *    puts the heap id in r6.  Write the increment as `offset = 1` anywhere and the
 *    constant is common-subexpression-eliminated with the 1 that is the fifth
 *    argument of the first call, which deletes the instruction outright and
 *    shifts the rest of the function by two bytes.
 */
struct BgmInfoTable *sub_02006E40(u32 heapId)
{
    struct BgmInfoTable *table = func_02030734(
        heapId, sizeof(struct BgmInfoTable), 0, sub_02006E40_File, 0x47);

    sub_02006EA4(table, heapId);
    return table;
}

void sub_02006E64(struct BgmInfoTable *table)
{
    func_020307B0(table->bgmId);
    func_020307B0(table->issMode);
    func_020307B0(table);
}

u8 sub_02006E7C(const struct BgmInfoTable *table, u16 bgmId)
{
    int i;

    for (i = 0; i < table->count; i++) {
        if (bgmId == table->bgmId[i]) {
            return table->issMode[i];
        }
    }
    return 0;
}

void sub_02006EA4(struct BgmInfoTable *table, u32 heapId)
{
    int i;
    int offset;

    offset = 0;
    func_02048F74(table, 0x57, 0, offset, (u32 *)1);
    offset++;
    table->bgmId = func_02030734(heapId, table->count * 2, 0, sub_02006E40_File,
                               0xAF);
    table->issMode = func_02030734(heapId, table->count, 0, sub_02006E40_File, 0xB0);
    for (i = 0; i < table->count; i++) {
        func_02048F74(&table->bgmId[i], 0x57, 0, offset, (u32 *)2);
        func_02048F74(&table->issMode[i], 0x57, 0, offset + 2, (u32 *)1);
        offset += 3;
    }
}
