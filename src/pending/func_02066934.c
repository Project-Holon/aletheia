/*
 * function: func_02066934
 * address:  0x02066934
 * packet:   pkt_02066890
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * status:   DIFF
 *
 * symbols:
 *   func_020640B0   0x020640B0  arm
 *   g_02148B20      0x02148B20  data
 *
 * Publishes the callback / count / record-array triple into the global bank at
 * 0x02148B20, then for each of the n 0x30-byte records calls func_020640B0 on
 * it and sets its nine words at +0xC..+0x2C to the record's own loop index.
 * n == 0 is the predicated early return off the `movs` that loads it.
 *
 * Two shapes are pinned by the byte comparison and are not re-derivable:
 * the three global stores fuse into one `stm` only in the write order
 * cb / recs / count (field order and count-first both emit `str` plus
 * `stmib`, four bytes longer), and the loop stores a *copy* of the counter,
 * which only a post-increment used as a value (`v = i++`) produces.
 *
 * Residue, seventeen bytes, one register pair swapped: the original puts the
 * counter in r5 and the copy in r4, this C puts the counter in r4 and the copy
 * in r5, so `mov r5, #0`, `mov r4, r5`, the nine `str`s and the `add`/`cmp`
 * all read the other register.  Every lever tried failed to flip it:
 * declaration order both ways, `v = 0` before the loop, split
 * `v = i; i = i + 1;`, `while (++i < n)`, a chained assignment, all
 * `u32`/`int`/`unsigned long` combinations for the two locals and a `static`
 * helper.  See docs/notes/func_02066934.c.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02066934.c \
 *       --func func_02066934 --addr 0x02066934 --arm --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Rec02066934 {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u32 unk_1c;
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
    u32 unk_2c;
};

struct Bank02066934 {
    u32                  cb;    /* +0x00 */
    u32                  count; /* +0x04 */
    struct Rec02066934  *recs;  /* +0x08 */
};

extern struct Bank02066934 g_02148B20;
extern void func_020640B0(struct Rec02066934 *rec);

void func_02066934(struct Rec02066934 *recs, u32 n, u32 cb)
{
    u32 v;
    u32 i = 0;

    g_02148B20.cb    = cb;
    g_02148B20.recs  = recs;
    g_02148B20.count = n;

    if (n == 0) {
        return;
    }

    do {
        v = i++;
        func_020640B0(recs);
        recs->unk_0c = v;
        recs->unk_10 = v;
        recs->unk_14 = v;
        recs->unk_18 = v;
        recs->unk_1c = v;
        recs->unk_20 = v;
        recs->unk_24 = v;
        recs->unk_28 = v;
        recs->unk_2c = v;
        recs++;
    } while (i < n);
}
