/*
 * function: sub_0203335C
 * address:  0x0203335C
 * packet:   pkt_0203335C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02033BF0  0x02033BF0  arm
 *
 * backup_system.c.  Swaps the two record marks across the whole packed
 * 2-bit-per-slot bitmap at +0x138: every slot holding 1 becomes 2 and every
 * slot holding 2 becomes 1 (0 and 3 are left alone).  The slot count is
 * sub_02033BF0(p->unk2c) + 2, the same count func_02033410 fills; the one-slot
 * getter and setter are src/matched/unit_020332FC.c and sub_0203331C.c.
 * Called by func_02032CD0 when a save generation completes.
 *
 * Three spellings carry it (docs/notes/sub_0203335C.c.txt has four lanes of
 * measurements at 21 bytes out before these were found):
 *
 * 1. The clear mask is the 64-bit complement written on a widened value,
 *    `(long long)(3 << sh) ^ -1` (docs/idioms/
 *    a-64-bit-complement-is-eors-with-minus-one-not-mvns.md).  With the int
 *    form `(3 << sh) ^ -1` every instruction is right but the hoisted 3 is
 *    coloured before the word index; the widened form numbers the 3 and the
 *    -1 after it and gives the image's sb/r7/r8 for 3/-1/mask.
 * 2. The first read indexes with `(int) w` while the clear and the set
 *    index with the plain u32 `w`; without the cast the word index, the
 *    slots pointer and the slot value rotate (r2/r6/r5 -> r6/r5/r2, 28
 *    bytes).  Found by tools/permuter.py anneal, then isolated by a sweep.
 * 3. The bound is a copy `n_ = n` tested by the loop, the guard tests `n`
 *    (the lever that closed func_02033410); all loop values are u32 so the
 *    wrap uses subhs/addhs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0203335C.c \
 *       --func sub_0203335C --addr 0x0203335C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj0203335C {
    char pad[0x2c];
    void *unk2c;
    char pad30[0x108];
    u32 *slots;
};

extern u32 sub_02033BF0(void *p);

void sub_0203335C(struct Obj0203335C *p)
{
    u32 n;
    u32 w;
    u32 sh;
    u32 n_;
    u32 i;
    u32 v;

    n = sub_02033BF0(p->unk2c) + 2;
    w = 0;
    sh = 0;
    i = 0;
    n_ = n;
    if (n == 0) {
        return;
    }
    do {
        v = (p->slots[(int)w] >> sh) & 3;
        if (v != 0) {
            if (v == 1) {
                v = 2;
            } else if (v == 2) {
                v = 1;
            }
            p->slots[w] &= (long long)(3 << sh) ^ -1;
            p->slots[w] |= v << sh;
        }
        sh += 2;
        i++;
        if (sh >= 0x20) {
            sh -= 0x20;
            w++;
        }
    } while (i < n_);
}
