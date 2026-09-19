/*
 * function: func_02066934
 * address:  0x02066934
 * packet:   pkt_02066890
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gUnk_02148B20  0x02148B20  data
 *   sub_020640B0   0x020640B0  arm
 *
 * Publish the record pool (callback, count, array) into the global bank at
 * 0x02148B20, then, for each of the n 0x30-byte records, run the per-record
 * routine sub_020640B0 on it and clear the nine words at +0x0C..+0x2C.
 * n == 0 is the predicated early return off the `movs` that loads it.
 *
 * THE NINE STORES WRITE ZERO, NOT THE LOOP INDEX.  The loop's back edge is
 * `blo 0x02066954` (the argument move) and the `mov r4, r5` that feeds every
 * `str r4, [r7, #..]` sits at 0x02066950, *outside* that back edge, in the
 * preheader, where r5 is the counter's zero: the stored value is
 * loop-invariant and r4 is mwcc rematerialising the constant 0 off the
 * known-zero counter register.  Reading the copy as `v = i++` puts it back
 * inside the loop and costs 17 bytes; docs/notes/func_02066934.c.txt (the
 * previous reading of this function, which called these stores "the record's
 * own loop index") is superseded by this file.
 *
 * Two scheduling points that the bytes do pin:
 *   - `i = 0` is initialised BEFORE the three bank stores; moved after them
 *     the `mov r5, #0` lands after the `popeq` and 12 bytes differ.
 *   - the stores are written as plain `0` literals, which is also what makes
 *     the constant hoistable into r4.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02066934.c \
 *       --func func_02066934 --addr 0x02066934 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

struct Rec {
    u8  pad_00[0xc];
    u32 unk_0c, unk_10, unk_14, unk_18, unk_1c, unk_20, unk_24, unk_28, unk_2c;
};

struct Bank {
    void       *cb;     /* 0x00 */
    u32         count;  /* 0x04 */
    struct Rec *recs;   /* 0x08 */
};

extern struct Bank gUnk_02148B20;
extern void sub_020640B0(struct Rec *c);

void func_02066934(struct Rec *recs, u32 n, void *cb)
{
    u32 i = 0;

    gUnk_02148B20.cb    = cb;
    gUnk_02148B20.recs  = recs;
    gUnk_02148B20.count = n;

    if (n == 0) return;

    do {
        sub_020640B0(recs);
        recs->unk_0c = 0; recs->unk_10 = 0; recs->unk_14 = 0;
        recs->unk_18 = 0; recs->unk_1c = 0; recs->unk_20 = 0;
        recs->unk_24 = 0; recs->unk_28 = 0; recs->unk_2c = 0;
        recs++;
        i++;
    } while (i < n);
}
