/*
 * function: sub_02034BB0
 * address:  0x02034BB0
 * packet:   pkt_02034978
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02034DC4  0x02034DC4  arm
 *   func_02034D60  0x02034D60  arm
 *   func_02034CBC  0x02034CBC  arm
 *   func_02034D08  0x02034D08  arm
 *   sub_02034714   0x02034714  arm
 *   s_FileName     0x020A7970  data
 *   s_Expr0        0x020A7980  data
 *
 * The admission test sub_02034AC4 runs before it claims a slot: an overlay
 * may only be loaded if its RAM footprint is disjoint from every overlay
 * already live in the same table.  An overlay whose header cannot be read
 * is refused outright; an overlap is the GF_ASSERT(0) at gf_overlay.c:330
 * and a 0 return.
 *
 * The three ways two ranges can overlap are one `||` expression, not three
 * `if`s: all three arms branch to the same assert block, which is only
 * reachable as a shared exit if the disjunction is written as a single
 * expression (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md).
 *
 * The four out-parameters sit at sp+0xc, sp+8, sp+4 and sp+0 in declaration
 * order, the later declaration taking the lower address.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02034BB0.c \
 *       --func sub_02034BB0 --addr 0x02034BB0 --cc 1.1p1 --arm
 */

typedef signed int   s32;
typedef unsigned int u32;

struct Registration {
    s32 handle;
    s32 state;
};

extern const char s_FileName[];
extern const char s_Expr0[];

typedef unsigned char  u8;
extern int func_02034DC4(u32 id, u32 *start, u32 *end);
extern int func_02034D60(u32 id);
extern void *func_02034CBC(int i);
extern u8 func_02034D08(int i);
extern void                 sub_02034714(const char *file, u32 line, const char *expr);

int sub_02034BB0(s32 handle)
{
    u32 start;
    u32 end;
    u32 other_start;
    u32 other_end;
    int which;
    struct Registration *table;
    int count;
    int i;

    if (func_02034DC4(handle, &start, &end) == 0) {
        return 0;
    }

    which = func_02034D60(handle);
    table = func_02034CBC(which);
    count = func_02034D08(which);

    for (i = 0; i < count; i++) {
        if (table[i].state == 1) {
            if (func_02034DC4(table[i].handle, &other_start, &other_end) == 1) {
                if ((start >= other_start && start < other_end) ||
                    (end > other_start && end <= other_end) ||
                    (start <= other_start && end >= other_end)) {
                    sub_02034714(s_FileName, 330, s_Expr0);
                    return 0;
                }
            }
        }
    }
    return 1;
}
