/*
 * function: func_02033410
 * address:  0x02033410
 * packet:   pkt_02033410
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02082A7C  0x02082A7C  arm
 *   sub_02033BF0   0x02033BF0  arm
 *
 * backup_system.c.  Fills the whole packed 2-bit-per-slot bitmap at offset
 * 0x138 with one repeated value: MIi_CpuClear32 (func_02082A7C) wipes
 * p->nbytes bytes of it, then `val` is OR'd in two bits at a time for
 * sub_02033BF0(p->unk2c) + 2 slots.  The getter/setter for one slot of the
 * same bitmap are src/matched/unit_020332FC.c and
 * src/matched/sub_0203331C.c.
 *
 * Two spellings carry this function:
 *
 * 1. The shift amount and the word index must be u32, not int.  An int
 *    gives the SIGNED conditional pair `subge`/`addge` where the original
 *    has the unsigned `subhs`/`addhs`; docs/notes/pkt_02033410.c.txt
 *    records that this alone was worth 38 of the original 44 residue bytes.
 *
 * 2. The loop bound is read through a COPY of the count declared before the
 *    counter (`n_ = n;` with `u32 n_;` ahead of `u32 i;`).  Written the
 *    obvious way -- the loop testing `n` directly -- the allocator swaps
 *    the counter and the bound (original `mov ip, r6` / `adds r3, r0, #2`
 *    / `add ip, ip, #1` / `cmp ip, r3`; compiled the same four with r3 and
 *    ip exchanged), which is 9 concrete bytes at the right size and is the
 *    residue the old note parked at.  The extra copy splits the bound's
 *    live range so it is numbered after the counter and takes r3.  Found
 *    by tools/permuter.py --mode hill (`copy(n->n_@9) ; decl-order(n_<->i)`).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02033410.c \
 *       --func func_02033410 --addr 0x02033410 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Obj02033410 {
    char pad[0x2c];
    void *unk2c;
    char pad30[0x108];
    u32 *slots;
    u32  nbytes;
};

extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern u32  sub_02033BF0(void *p);

void func_02033410(struct Obj02033410 *p, u32 val)
{
    u32 n;
    u32 w;
    u32 sh;
    u32 n_;
    u32 i;

    func_02082A7C(0, p->slots, p->nbytes);
    n = sub_02033BF0(p->unk2c) + 2;
    w = 0;
    sh = 0;
    n_ = n;
    i = 0;
    if (n_ == 0) {
        return;
    }
    do {
        i++;
        p->slots[w] |= val << sh;
        sh += 2;
        if (sh >= 0x20) {
            sh -= 0x20;
            w++;
        }
    } while (i < n_);
}
