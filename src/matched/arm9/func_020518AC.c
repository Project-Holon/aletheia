/*
 * function: func_020518AC
 * address:  0x020518AC
 * packet:   pkt_02051838
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02057EF8  0x02057EF8  arm
 *   func_02057F8C  0x02057F8C  arm
 *   func_020580A8  0x020580A8  arm
 *   func_02058180  0x02058180  arm
 *   func_02058204  0x02058204  arm
 *   func_020582CC  0x020582CC  arm
 *
 * Linear search of the block at obj+0x20 for the first 8-byte entry whose
 * first word is the handler address selected by `kind`, returning that
 * entry's second word (or NULL).  The six handlers are the 3D-rig rows at
 * 0x02057EF8..0x020582CC, all pool words and all attested by the sibling
 * pool at 0x02052DB0.
 *
 * Two tells decide the shape.  Declaring the index BEFORE the count is what
 * puts the count in r4 and the index in lr (declaration-order-decides-which-
 * register-a-local-gets).  And the image's `adds ip, r5, lr, lsl #3` / `beq`
 * pair at +0040 is a redundant null test on the entry pointer: the `adds`
 * form only appears when the source writes `if (e == 0) continue;`, which
 * folds into the address computation.  Without it the switch is four bytes
 * shorter and every branch target shifts.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020518AC.c \
 *       --func func_020518AC --addr 0x020518AC --cc 1.1p1 --arm
 */

typedef unsigned short u16;

struct Ent {
    void *fn;
    void *data;
};

struct Blk {
    char pad[0x18];
    struct Ent *ents;
    u16 count;
};

extern void func_02057EF8(void);
extern void func_02057F8C(void);
extern void func_020580A8(void);
extern void func_02058180(void);
extern void func_02058204(void);
extern void func_020582CC(void);

void *func_020518AC(void *obj, int kind)
{
    struct Blk *b = *(struct Blk **)((char *)obj + 0x20);
    int i;
    int n = b->count;

    if (n == 0)
        return 0;

    for (i = 0; i < n; i++) {
        struct Ent *e = &b->ents[i];
        if (e == 0)
            continue;
        switch (kind) {
        case 0:
            if (e->fn == (void *)func_020582CC)
                return e->data;
            break;
        case 1:
            if (e->fn == (void *)func_02058204)
                return e->data;
            break;
        case 2:
            if (e->fn == (void *)func_02058180)
                return e->data;
            break;
        case 3:
            if (e->fn == (void *)func_020580A8)
                return e->data;
            break;
        case 4:
            if (e->fn == (void *)func_02057F8C)
                return e->data;
            break;
        case 5:
            if (e->fn == (void *)func_02057EF8)
                return e->data;
            break;
        default:
            return 0;
        }
    }
    return 0;
}
