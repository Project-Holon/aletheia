/*
 * function: func_0206E5EC
 * address:  0x0206E5EC
 * packet:   pkt_0206E394
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206E4FC    0x0206E4FC  arm
 *
 * Walks the count byte at +0x18, calling func_0206E4FC with the counter and the
 * caller's second argument; the counter is zeroed before the entry test (which
 * is why the original's `mov r4, #0` precedes `cmp`/`popls`) and the count is
 * re-read from memory every iteration.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206E5EC.c \
 *       --func func_0206E5EC --addr 0x0206E5EC --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef unsigned char u8;

typedef struct {
    u8 unk00[0x18];
    u8 count18;
} Obj0206E5EC;

extern void func_0206E4FC(Obj0206E5EC *p, u32 idx, u32 a);

void func_0206E5EC(Obj0206E5EC *p, u32 a)
{
    u32 i = 0;

    for (i = 0; i < p->count18; i++) {
        func_0206E4FC(p, i, a);
    }
}
