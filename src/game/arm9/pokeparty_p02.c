/*
 * file:     pokeparty_p02.c
 * unit:     yes
 * function: func_02019CF8, func_02019D00, func_02019D30, func_02019D58, func_02019D84, func_02019DA4, func_02019E54, func_02019ED4, func_02019FD0, func_0201A090, func_0201A26C, func_0201A2A8, func_0201A30C, func_0201A354, func_0201A364, func_0201A374, func_0201A3F4
 * address:  0x02019CF8
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
 *   func_02019BBC  0x02019BBC  thumb
 *   func_02019C90  0x02019C90  thumb
 *   sub_0209E280_Map  0x0209E280  data
 *   d_0209E42C 0x0209E42C data a2
 *   func_02017E1C   0x02017E1C  thumb
 *   func_0200AE54   0x0200AE54  thumb
 *   func_0200AFD4   0x0200AFD4  thumb
 *   func_0201A5FC   0x0201A5FC  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A59C  0x0201A59C  thumb
 *   func_0201AA50   0x0201AA50  thumb
 *   func_02019CA0   0x02019CA0  thumb
 *   func_02019B58   0x02019B58  thumb
 *   func_02048F60  0x02048F60  arm
 *   func_02048F4C  0x02048F4C  arm
 *   func_0201EFA4   0x0201EFA4  thumb
 *   func_020457B0   0x020457B0  arm
 *   func_02045CAC   0x02045CAC  arm
 *   func_0201F250   0x0201F250  thumb
 */
struct Reg;
struct MsgBank;
struct WordSet;
struct U16Vec;
typedef unsigned int   u32;

typedef signed int     s32;

typedef unsigned short u16;

typedef unsigned long long u64;

typedef unsigned char  u8;

extern unsigned int func_02019BBC(unsigned int item);
extern u32 func_02019C90(u32 a, u32 b, u32 k);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern u32 func_0200AE54(struct Reg *p, u32 id);
extern u32 func_0200AFD4(struct Reg *p, u32 id, s32 n);
extern int func_0201A5FC(void *a0, void *a1, u8 *a2, char *a3, u32 *a4);
extern u32 func_0201AA18(void *p);
extern void MI_CpuFill8(void *dst, u8 v, u32 n);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_0201A59C(void *a0, void *a1, void *a2);
extern u32 func_0201AA50(void *p);
extern void func_02019CA0(void *p, u32 v);
extern void func_02019B58(void *p);
extern void *func_02048F60(unsigned int archive_id, unsigned int member, unsigned int heap);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
unsigned int func_02019CF8(unsigned int item);
u32 func_02019D00(u32 id);
u32 func_02019D30(u32 a, u32 n);
int func_02019D58(u16 a, int b);
int func_02019D84(unsigned short value);
int func_02019DA4(void *a0, void *a1);
int func_02019E54(u32 a0, u32 a1, u32 a2);
int sub_02019ED4(void *ctx, void *q);
int func_02019FD0(void *a0, void *a1, u32 *a2);
int func_0201A090(void *rules, void *party, u32 *mask);
u32 func_0201A26C(void *a0, u32 a1);
void func_0201A2A8(void *a0, void *a1);
void func_0201A30C(void *a0, void *a1, u32 c);
void *func_0201A354(int a, int b);
void func_0201A364(int a, unsigned int b);
void *func_0201A374(u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4);
void *func_0201A3F4(const u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4);
extern u16 sub_0209E280_Map[];
extern const unsigned short d_0209E42C[];





/*
 * Plain forwarder to func_02019BBC (ldr r3, =target; bx r3).  Callee of
 * ov170 func_021DD718.
 */
unsigned int func_02019CF8(unsigned int item)
{
    return func_02019BBC(item);
}





/*
 * Neither carries a label in the generated listing.  func_02019D00
 * is a dense switch over 0x74..0x77 whose four arms each return a constant,
 * and the `subs r0, #0x74` in front of the `cmp`/`bhi` is the compiler's
 * normalisation of the range rather than anything the source wrote; see
 * docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md.
 *
 * The range stops at 0x02019D58.  The two unlabelled search loops after it,
 * at 0x02019D58 and 0x02019D84, reproduce every concrete byte but read
 * halfword tables at 0x0209E280 and 0x0209E42C, and each of those addresses
 * appears in exactly one literal pool in the whole image, the one under test,
 * so the literal class discards its only witness and no cut helps.
 */
u32 func_02019D00(u32 id)
{
    switch (id) {
    case 0x74:
        return 1;
    case 0x75:
        return 2;
    case 0x76:
        return 3;
    case 0x77:
        return 4;
    }
    return 0;
}





u32 func_02019D30(u32 a, u32 n)
{
    if (a != 0x28A) {
        if ((s32)n >= (s32)func_02019C90(a, n, 0x20)) {
            n = 0;
        }
        return n;
    }
    if (n >= 2) {
        n = 0;
    }
    return n;
}




/*
 * note:     re-verified 2026-09-21: EXACT*.  The MATCH cap was lifted by the
 *           sole-ref widening of 2026-09-21, not by any edit to the C:
 *           the data address this file reaches now attests as
 *           sole-ref/data.  Promoted from src/pending/ unchanged.
 */
int func_02019D58(u16 a, int b)
{
    u16 i;

    if (b != 0) {
        for (i = 0; i < 4; i++)
            if (sub_0209E280_Map[i] == a)
                return 0;
    }
    return b;
}



/*
 * Witness leaf for ov119 func_021DD0CC: membership test in a 12 entry u16 table.
 */
int func_02019D84(unsigned short value)
{
    unsigned i;
    for (i = 0; i < 12; i++) {
        if (value == d_0209E42C[i])
            return 1;
    }
    return 0;
}





/*
 * A stat comparison against a threshold picked by selector 4 of the first
 * argument: selector 5 (one over the limit) and 6 (under it) are both
 * rejected with 2, and the tail reports 0x20 for the presence flag, 4 or
 * 0x40 for the two range checks, and 1 when there is no object at all.  The
 * two comparisons are signed, which is what `ble`/`bge` says.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019DA4.c \
 *       --func func_02019DA4 --addr 0x02019DA4 --cc 1.1p1 --thumb
 */
int func_02019DA4(void *a0, void *a1)
{
    u16 v5 = (u16)func_02017E1C(a1, 5, 0);
    u16 v6 = (u16)func_02017E1C(a1, 6, 0);
    int m;
    int s;
    int t;
    int r;

    if (a0 == 0)
        return 1;

    m = func_0200AE54(a0, 4);
    s = func_0200AE54(a0, 5);
    t = func_02017E1C(a1, 0x9E, 0);

    switch (s) {
    case 1:
        if (m > t)
            return 2;
        break;
    case 2:
        if (m < t)
            return 2;
        break;
    }

    r = 0;
    if (func_02017E1C(a1, 0x4C, 0) != 0)
        return 0x20;
    if (func_0200AFD4(a0, 9, v5) != 0)
        return 4;
    if (func_0200AFD4(a0, 0xA, v6) != 0)
        r = 0x40;
    return r;
}






/*
 * Maps a flag word to a small code: the four bits 2, 4, 0x20 and 0x40 all
 * answer 5 (one disjunction, so they share a single exit), then 8, 0x10,
 * 0x100, 0x80 and 1 each answer their own code and zero answers 0.  The
 * query is answered through two stack words whose addresses are passed to
 * func_0201A5FC, and the caller's second and third registers are forwarded
 * unchanged, so the query takes five arguments.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019E54.c \
 *       --func func_02019E54 --addr 0x02019E54 --cc 1.1p1 --thumb
 */
int func_02019E54(u32 a0, u32 a1, u32 a2)
{
    u64 q;
    u32 r;

    if (a0 == 0)
        return 0;

    func_0201A5FC((void *)a0, (void *)a1, (u8 *)a2, (char *)(&q), &r);
    if (r == 0)
        return 0;

    if ((r & 2) || (r & 4) || (r & 0x20) || (r & 0x40))
        return 5;
    if (r & 8)
        return 2;
    if (r & 0x10)
        return 3;
    if (r & 0x100)
        return 1;
    if (r & 0x80)
        return 7;
    if (r & 1)
        return 4;
    return 0;
}






/*
 * EXACT*: the inferred extent runs 2 bytes past the 250-byte body because the
 * follower at 0x02019FD0 has no lr-saving prologue and so carries no label.
 * No byte differs.
 *
 * The party "is this team legal for the rule set" check.  It reads each
 * member's species (id 5) and form (id 0x9E) into two parallel u16[6] stack
 * arrays, zeroes the species of any member func_02019DA4 rejects, then runs an
 * O(n^2) duplicate-species scan that zeroes the worse of each colliding pair
 * (worse = the larger form value) and decrements a running count.  If the
 * surviving count is below what func_0200AE54(ctx, 2) requires it answers 4;
 * otherwise the answer is 0 or 1 from func_0201A59C.
 *
 * Two layout tells pin the frame:
 *   - the 12-byte MI_CpuFill8 buffer is declared LAST, not first: the later
 *     declarator gets the lower stack address, which is what puts `pad` at
 *     sp+0x10 and `species` at sp+0x28
 *     (docs/idioms/local-declaration-order-is-stack-order.md).
 *   - the outer scan loop assigns its counter before its bound (`i = 0;`
 *     then `lim = n - 1;`), or the `movs r0,#0` and the `subs r0,r0,#1`
 *     swap places
 *     (docs/idioms/assign-the-loop-counter-before-the-loop-bound-or-zero-costs-a-pool-word.md).
 *
 * VERSION SENSITIVITY: party ids 5 and 0x9E and the rule-set keys 7 and 2 are
 * content numbering; the team size 6 is the array bound and is structural.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02019ED4.c \
 *       --func sub_02019ED4 --addr 0x02019ED4 --cc 1.1p1 --thumb
 */
int sub_02019ED4(void *ctx, void *q)
{
    u16 species[6];
    u16 form[6];
    u8 pad[12];
    int n;
    int cnt;
    int i;
    int j;
    int lim;
    int r;

    n = func_0201AA18(q);
    cnt = n;
    MI_CpuFill8(pad, 0, 12);
    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(q, i);

        species[i] = (u16)func_02017E1C(mon, 5, 0);
        form[i] = (u16)func_02017E1C(mon, 0x9E, 0);
        if (func_02019DA4(ctx, mon) != 0) {
            species[i] = 0;
            cnt--;
        }
    }

    if ((int)func_0200AE54(ctx, 7) == 0 && n > 1) {
        i = 0;
        lim = n - 1;
        for (; i < lim; i++) {
            for (j = i + 1; j < n; j++) {
                if (species[i] == species[j] && species[i] != 0) {
                    if (form[i] > form[j]) {
                        species[i] = 0;
                    } else {
                        species[j] = 0;
                    }
                    cnt--;
                }
            }
        }
    }

    if (cnt < (int)func_0200AE54(ctx, 2)) {
        return 4;
    }

    r = 0;
    if (func_0201A59C(ctx, q, 0) != 1) {
        r = 1;
    }
    return r;
}






/*
 * EXACT* note: the 190 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A08E before the next labelled function at 0x0201A090.
 *
 * The same stat comparison as func_02019DA4, but it reports into the third
 * argument's word with or-bits instead of returning a code: bit 1 for a
 * selector 5 record above the threshold or a selector 6 one below it, bit 2
 * for the range check, bit 6 for the second one, and the return value stays 1
 * unless a bit was set.  The `*a2 |= 2; r = 0;` pair is written out in both
 * arms and the compiler cross-jumps them.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02019FD0.c \
 *       --func func_02019FD0 --addr 0x02019FD0 --cc 1.1p1 --thumb
 */
int func_02019FD0(void *a0, void *a1, u32 *a2)
{
    u16 v5 = (u16)func_02017E1C(a1, 5, 0);
    u16 v6 = (u16)func_02017E1C(a1, 6, 0);
    int r = 1;
    int m;
    int s;
    int t;

    if (a0 == 0)
        return r;

    m = func_0200AE54(a0, 4);
    s = func_0200AE54(a0, 5);
    t = func_02017E1C(a1, 0x9E, 0);

    switch (s) {
    case 1:
        if (m > t) {
            r = 0;
            *a2 |= 2;
        }
        break;
    case 2:
        if (m < t) {
            r = 0;
            *a2 |= 2;
        }
        break;
    }

    if (func_0200AFD4(a0, 9, v5) != 0) {
        if (func_02017E1C(a1, 0x4C, 0) == 0) {
            r = 0;
            *a2 |= 4;
        }
    }
    if (func_0200AFD4(a0, 0xA, v6) != 0) {
        r = 0;
        *a2 |= 0x40;
    }
    return r;
}





/*
 * poke_tool.c (wave 13): the party legality check against a rule set.
 * Three parallel six-entry u16 arrays (species, item, form) are collected
 * from the non-egg members; the rule set's queries 2 (minimum count),
 * 7 (duplicate species allowed), 8 (duplicate items allowed) and 0xB/0xC (a
 * required species/form) set bits 0x01/0x08/0x10/0x80 of *mask and the
 * error codes 4/2/3/7, a failing member check gives 5, and when nothing
 * failed func_0201A59C decides between 0 and 1.
 *
 * WHAT CLOSED IT (docs/notes/func_0201A090.c.txt: 478 against 476, err
 * spilled to sp+8 with a six-register push): the arrays are indexed plainly,
 * `species[i]` -- the note's invented `j = i * 2; species[j >> 1]` was the
 * source of the `lsls/bics` fixups; the compiler itself CSEs `i * 2` into
 * the sp+8 slot.  Then the permuter (hill, one mutation) found the last
 * lever: in the duplicate-item test the mask update comes BEFORE the error
 * code (`*mask |= 0x10; err = 3;`), the opposite of the species test.  That
 * order is what keeps err in r7 for the whole function.
 *
 * EXACT* only because of the two-byte alignment pad at 0x0201A26A; the
 * follower 0x0201A26C is its own labelled EXACT entry.
 */
int func_0201A090(void *rules, void *party, u32 *mask)
{
    u16 species[6];
    u16 item[6];
    u16 form[6];
    int i;
    int total;
    int n;
    int err;
    void *mon;
    int k;
    int want_s, want_f;

    n = 0;
    err = 0;
    if (rules == 0)
        return 0;
    for (i = 0; i < 6; i++) {
        species[i] = 0;
        form[i] = 0;
        item[i] = 0;
    }
    total = func_0201AA50(party);
    if (total < (int)func_0200AE54(rules, 2)) {
        *mask |= 1;
        err = 4;
    }
    for (i = 0; i < (int)func_0201AA18(party); i++) {
        mon = func_0201AB28(party, i);
        if (func_02019FD0(rules, mon, mask) == 0)
            err = 5;
        if (func_02017E1C(mon, 0x4c, 0) == 0) {
            species[i] = func_02017E1C(mon, 5, 0);
            item[i] = func_02017E1C(mon, 6, 0);
            form[i] = func_02017E1C(mon, 0x6f, 0);
            n += func_02017E1C(mon, 0x9e, 0);
        }
    }
    if ((int)func_0200AE54(rules, 7) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (species[i] == species[k] && species[i] != 0) {
                    err = 2;
                    *mask |= 8;
                }
            }
        }
    }
    if ((int)func_0200AE54(rules, 8) == 0 && total > 1) {
        for (i = 0; i < 5; i++) {
            for (k = i + 1; k < 6; k++) {
                if (item[i] == item[k] && species[i] != 0 && item[i] != 0) {
                    *mask |= 0x10;
                    err = 3;
                }
            }
        }
    }
    want_s = (int)func_0200AE54(rules, 0xb);
    want_f = (int)func_0200AE54(rules, 0xc);
    i = 0;
    if (want_s != 0 && total > 1) {
        for (i = 0; i < 6; i++) {
            if (want_s == species[i] && want_f == form[i])
                break;
        }
    }
    if (i == 6) {
        *mask |= 0x80;
        err = 7;
    }
    if (err == 0 && func_0201A59C(rules, party, 0) == 0)
        err = 1;
    return err;
}





/*
 * Picks the smaller (or larger, per selector 5) of a value read from the
 * object and the caller's second argument, with the selector 3 / 4 / 5 arms
 * emitted as a compare chain and the default falling through to the caller's
 * value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A26C.c \
 *       --func func_0201A26C --addr 0x0201A26C --cc 1.1p1 --thumb
 */
u32 func_0201A26C(void *a0, u32 a1)
{
    u32 v = func_0200AE54(a0, 4);
    u32 w = func_0200AE54(a0, 5);

    switch (w) {
    case 3:
        if (a1 > v)
            return v;
        break;
    case 4:
        return v;
    case 5:
        if (a1 < v)
            return v;
        break;
    }
    return a1;
}





/*
 * EXACT* note: the 98 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A30A before the next labelled function at 0x0201A30C.
 *
 * Sweeps the records of the second argument and rewrites those whose 0xA9
 * flag is set and whose recomputed value disagrees with what the first
 * argument's own query returns.  The value from before the loop is a spilled
 * local, so it is re-read from the frame at the one place it is used.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A2A8.c \
 *       --func func_0201A2A8 --addr 0x0201A2A8 --cc 1.1p1 --thumb
 */
void func_0201A2A8(void *a0, void *a1)
{
    u32 v = func_0200AE54(a0, 4);
    int i;

    for (i = 0; i < (int)func_0201AA18(a1); i++) {
        void *e = func_0201AB28(a1, i);

        if (func_02017E1C(e, 0xA9, 0) != 0) {
            u32 w = func_02017E1C(e, 0x9E, 0);

            if (func_0201A26C(a0, w) != w)
                func_02019CA0(e, v);
        }
    }
}





/*
 * EXACT* note: the 70 byte body reproduces exactly; the inferred extent runs to
 * the next label because of two bytes of 00 00 padding at 0x0201A352, then two unlabelled 12-byte argument-shuffling tail-call thunks at 0x0201A354 (calls 0x02048F60 with (0x69, a, b)) and 0x0201A364 (calls 0x02048F4C with (b, 0x69, a)), each followed by its own pool word, before the next labelled function at 0x0201A374.
 *
 * Guarded sweep over a record array: only when the object reports state zero
 * does it walk the records and act on those whose 0xA9 flag is set.  The
 * bound is re-evaluated at the bottom of the loop, so it stays a call in the
 * condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A30C.c \
 *       --func func_0201A30C --addr 0x0201A30C --cc 1.1p1 --thumb
 */
void func_0201A30C(void *a0, void *a1, u32 c)
{
    int i;

    if (func_0200AE54(a0, 0x11) != 0)
        return;

    for (i = 0; i < (int)func_0201AA18(a1); i++) {
        void *e = func_0201AB28(a1, i);

        if (func_02017E1C(e, 0xA9, 0) != 0)
            func_02019B58(e);
    }
}





/*
 * Witness leaf for ov021 func_021B574C and func_021B57CC.
 */
void *func_0201A354(int a, int b)
{
    return func_02048F60(0x69, a, b);
}





/*
 * Unlabelled Thumb argument-shuffling tail-call thunk: func_02048F4C(b, 0x69, a).
 */
void func_0201A364(int a, unsigned int b)
{
    func_02048F4C((void *)b, 0x69, a);
}




/*
 * Load one 0x40-byte sprite record whose mode word is chosen from the pair of
 * bytes at a0+2/+3: (1,6) selects 6, equal bytes select 7, a byte above 1
 * with 6 following selects 8 and anything else 9.  Both palette fields are
 * stamped through func_0201EFA4, the record is allocated against a4, its
 * slots are filled from *a2 through func_02045CAC and the pair is bound by
 * func_0201F250.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201A374.c \
 *       --func func_0201A374 --addr 0x0201A374 --cc 1.1p1 --thumb
 */
void *func_0201A374(u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4)
{
    u32 mode;
    void *p;

    if (a0[2] == 1 && a0[3] == 6) {
        mode = 6;
    } else if (a0[2] == a0[3]) {
        mode = 7;
    } else if (a0[2] > 1 && a0[3] == 6) {
        mode = 8;
    } else {
        mode = 9;
    }
    func_0201EFA4((struct WordSet *)a1, 0, a0[2], 1, 0, 1);
    func_0201EFA4((struct WordSet *)a1, 1, a0[3], 1, 0, 1);
    p = func_020457B0(0x40, a4);
    func_02045CAC((struct MsgBank *)(*a2), mode, (void *)a3);
    func_0201F250((struct WordSet *)a1, p, (void *)a3);
    return p;
}




/*
 * poke_tool.c tail (wave 13), the twin of func_0201A374: pick the sprite
 * record's mode from the format byte at a0+5 (0 -> 6, 4 -> 0xb, 1 -> 0xd,
 * 2 -> 0xc, 3 -> 0xe, 5 -> 0xf, anything else 6; an if chain in that order,
 * the image tests it in source order), stamp the byte at a0+4 through
 * func_0201EFA4, allocate the 0x40-byte record against a4, fill it from *a2
 * and bind it with func_0201F250.
 *
 * WHAT CLOSED IT (docs/notes/pkt_0201A3F4.c.txt: 8 bytes out, the byte at
 * a0+4 loaded after the two outgoing stack stores instead of before): the
 * record parameter is `const u8 *`.  A load through a const pointer may move
 * above the stores to the outgoing-argument area; through a plain pointer it
 * may not.  Same lever as func_02050C30 and func_02051838 this wave.
 *
 * EXACT* because the follower at 0x0201A468 (a leaf that scans 0x52 bytes
 * from +0xa and tail-calls 0x02045EC0) carries no label.
 */
void *func_0201A3F4(const u8 *a0, u32 a1, u32 *a2, u32 a3, u16 a4)
{
    u32 mode;
    void *p;

    if (a0[5] == 0) {
        mode = 6;
    } else if (a0[5] == 4) {
        mode = 0xb;
    } else if (a0[5] == 1) {
        mode = 0xd;
    } else if (a0[5] == 2) {
        mode = 0xc;
    } else if (a0[5] == 3) {
        mode = 0xe;
    } else if (a0[5] == 5) {
        mode = 0xf;
    } else {
        mode = 6;
    }
    func_0201EFA4((struct WordSet *)a1, 0, a0[4], 3, 0, 1);
    p = func_020457B0(0x40, a4);
    func_02045CAC((struct MsgBank *)(*a2), mode, (void *)a3);
    func_0201F250((struct WordSet *)a1, p, (void *)a3);
    return p;
}
