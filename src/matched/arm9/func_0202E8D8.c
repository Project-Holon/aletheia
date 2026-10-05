/*
 * function: func_0202E8D8
 * address:  0x0202E8D8
 * packet:   pkt_0202E8D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Six-byte record matcher against a three-slot table at a0+0x22 (six bytes
 * apart).  Both loop counters are `unsigned char` - the lsls 0x18 / lsrs 0x18
 * pair after each increment is the narrowing, and the comparisons are `blo`,
 * so signed ints give `blt` instead.
 *
 * Do NOT bind the record base to a local `char *p`: writing the inner compare
 * as `p[0x22 + j]` makes the compiler hoist `adds r4, a0, i*6` ahead of the
 * ok/j initialisers and differs by six bytes.  Spelling the base out as
 * `a0 + i * 6` inside the compare leaves the hoist where the original has it
 * (after `movs r6,#1` and `movs r3,#0`).
 *
 * EXACT*: the compared extent ran long by the follower's padding - the
 * follower at 0x0202E930 is a two-halfword `ldr r3,[pc]; bx r3` long-branch
 * veneer with no label of its own.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E8D8.c \
 *       --func func_0202E8D8 --addr 0x0202E8D8 --cc 1.1p1 --thumb
 */

typedef unsigned int   u32;
struct Sub0200852CObj;
struct Sub020097BCObj;
extern int func_02009D1C(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);

int func_0202E8D8(char *a0, int a1, char *a2)
{
    unsigned char i;
    unsigned char j;

    if (a1 == 0) {
        return 0;
    }
    for (i = 0; i < 3; i++) {
        int ok = 1;

        for (j = 0; j < 6; j++) {
            if (*(unsigned char *)(a0 + i * 6 + 0x22 + j)
                    != *(unsigned char *)(a2 + j)) {
                ok = 0;
                break;
            }
        }
        if (ok == 1) {
            return func_02009D1C((struct Sub020097BCObj *)a1, (struct Sub0200852CObj *)((int)a0), 0);
        }
    }
    return 0;
}
