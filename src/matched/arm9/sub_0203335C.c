/*
 * function: BACKUP_SYSTEM_SwapBlockAreas
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
 *   SAVEDATA_GetTableMax  0x02033BF0  arm
 *
 * backup_system.c.  Swaps the two record marks across the whole packed
 * 2-bit-per-slot bitmap at +0x138: every slot holding 1 becomes 2 and every
 * slot holding 2 becomes 1 (0 and 3 are left alone).  The slot count is
 * SAVEDATA_GetTableMax(p->unk2c) + 2, the same count BACKUP_SYSTEM_FillBlockAreas fills; the one-slot
 * getter and setter are src/matched/unit_020332FC.c and BACKUP_SYSTEM_SetBlockArea.c.
 * Called by BACKUP_SYSTEM_SaveSeqMain when a save generation completes.
 *
 * Three spellings carry it (docs/notes/BACKUP_SYSTEM_SwapBlockAreas.c.txt has four lanes of
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
 *    (the lever that closed BACKUP_SYSTEM_FillBlockAreas); all loop values are u32 so the
 *    wrap uses subhs/addhs.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BACKUP_SYSTEM_SwapBlockAreas.c \
 *       --func BACKUP_SYSTEM_SwapBlockAreas --addr 0x0203335C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj0203335C {
    char pad[0x2c];
    void *unk2c;
    char pad30[0x108];
    u32 *slots;
};

struct Obj02033BF0;
extern u32 SAVEDATA_GetTableMax(struct Obj02033BF0 *p);

void BACKUP_SYSTEM_SwapBlockAreas(struct Obj0203335C *p)
{
    u32 n;
    u32 w;
    u32 sh;
    u32 n_;
    u32 i;
    u32 v;

    n = SAVEDATA_GetTableMax(p->unk2c) + 2;
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
