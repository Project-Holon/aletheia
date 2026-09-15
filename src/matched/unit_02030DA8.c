/*
 * unit:     yes
 * function: sub_02030DA8
 * address:  0x02030DA8
 * packet:   pkt_02030CBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_02030C44  0x02030C44  arm
 *   sub_02030DA8  0x02030DA8  arm
 *   sub_02030DC8  0x02030DC8  arm
 *
 * Previously capped at MATCH: 0x02030C44 has exactly one caller image-wide,
 * the call inside sub_02030DC8 below, so no `label` witness exists and no cut
 * could free the site.  src/matched/unit_02030C44.c now reproduces the node
 * allocator's own byte range, so the PC24 at +0x34 resolves in the `matched`
 * class and the unit is EXACT.
 *
 * Insert one node into the context's circular list, kept sorted ascending on
 * the key at +0x0C, plus the re-entry wrapper that guards it.
 *
 * The two functions are one unit rather than two files because nothing in
 * the image branches to 0x02030DC8 except the wrapper: as separate files the
 * wrapper's call has no witness of any class and caps at MATCH, while in one
 * translation unit it is `local` and needs no image evidence at all
 * (docs/idioms/split-a-unit-so-two-call-sites-attest-each-other.md read the
 * other way round).
 *
 * The wrapper takes four parameters, not one.  Its own bytes never set r1,
 * r2 or r3 before the call, which is what forwarding untouched parameters
 * looks like, and the tell is the register the constant 1 lands in: `mov ip,
 * #1` before the call and `mov r1, #0` after it.  With fewer parameters
 * declared, r1 is free on both sides and the compiler uses it twice.
 *
 * The list is doubly linked through +0x04 (prev) and +0x08 (next) with the
 * sentinel embedded in the context at +0x08, which is why `c->head.unk_04`
 * is the same word as the context's +0x0C and the loop bound is the address
 * of the sentinel itself.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02030DA8.c \
 *       --addr 0x02030DA8 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Node {
    u32          unk_00;
    struct Node *unk_04;
    struct Node *unk_08;
    u32          unk_0c;
    u32          unk_10;
    u32          unk_14;
    u32          unk_18;
};

struct Cfg {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
    u32 unk_14;
};

struct Ctx {
    u8           pad_00[8];
    struct Node  head;
    u8           pad_24[8];
    u32          busy;
    struct Cfg  *unk_30;
    struct Node *unk_34;
};

extern struct Node *sub_02030C44(struct Ctx *c, u32 a, u32 b, u32 key);
extern struct Node *sub_02030DC8(struct Ctx *c, u32 a, u32 b, u32 key);

struct Node *sub_02030DA8(struct Ctx *c, u32 a, u32 b, u32 key)
{
    struct Node *n;

    c->busy = 1;
    n = sub_02030DC8(c, a, b, key);
    c->busy = 0;
    return n;
}

struct Node *sub_02030DC8(struct Ctx *c, u32 a, u32 b, u32 key)
{
    struct Node *n;
    struct Node *p;

    n = sub_02030C44(c, a, b, key);
    if (n == 0) {
        return 0;
    }

    n->unk_0c = key;
    n->unk_10 = b;
    n->unk_14 = a;

    if (c->unk_30->unk_14 != 0) {
        if (c->unk_30->unk_0c <= key) {
            n->unk_18 = 1;
        } else {
            n->unk_18 = 0;
        }
    } else {
        n->unk_18 = 0;
    }

    for (p = c->head.unk_08; p != &c->head; p = p->unk_08) {
        if (p->unk_0c > n->unk_0c) {
            n->unk_04 = p->unk_04;
            n->unk_08 = p;
            p->unk_04->unk_08 = n;
            p->unk_04 = n;
            if (p == c->unk_34) {
                c->unk_34 = n;
            }
            return n;
        }
    }

    if (c->unk_34 == &c->head) {
        c->unk_34 = n;
    }
    n->unk_04 = c->head.unk_04;
    n->unk_08 = &c->head;
    c->head.unk_04->unk_08 = n;
    c->head.unk_04 = n;
    return n;
}
