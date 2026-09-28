/*
 * function: func_0202A1CC
 * address:  0x0202A1CC
 * packet:   pkt_0202A19C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Bounded scan of the container's 8-byte records: the one whose key matches and
 * whose second field is either 2 or the caller's v2, and whose third field is
 * the caller's v3, is returned by index; 0xffff when none is.  The bound is
 * re-read at the foot of the loop, which is the shape of
 * src/matched/sub_0202BFC4.c: the container has to be declared as a struct
 * with a `count` member and the records reached as `c->items[i]`, because the
 * subscript form is what keeps `c` live in r0 and re-loads `c->count` at the
 * bottom of the loop.  Written with a separate base pointer the compiler caches
 * the bound and the residue is 10 bytes of register shuffling.
 *
 * Closes the blocker of src/pending/func_0202A20C.c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202A1CC.c \
 *       --func func_0202A1CC --addr 0x0202A1CC --thumb --cc 1.1p1
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Item {
    u16 key;
    u16 v2;
    u16 v3;
    u16 pad;
};

struct Container {
    const struct Item *items;
    u32 pad1;
    u32 pad2;
    u32 count;
};

u32 func_0202A1CC(const struct Container *c, u32 key, u32 v2, u32 v3)
{
    u32 i;

    for (i = 0; i < c->count; i++) {
        if (c->items[i].key != key) {
            continue;
        }
        if (c->items[i].v2 != 2 && c->items[i].v2 != v2) {
            continue;
        }
        if (c->items[i].v3 != v3) {
            continue;
        }
        return i;
    }
    return 0xffff;
}
