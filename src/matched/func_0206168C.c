/*
 * function: func_0206168C
 * address:  0x0206168C
 * packet:   pkt_020611D4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A816C     0x020A816C  data
 *
 * RESTORE half of the pair whose save half is src/matched/func_0206164C.c:
 * it copies two words per record back from the caller's flat buffer into the
 * first two words of each of the five 0x18-byte records at 0x020A816C.
 *
 * Same lever as the save half (see that file's header): the image derives the
 * second loop zero from the first with `mov ip, r3`, so `j` has to be spelled
 * as a copy of `i` and not as its own literal `0`.
 *
 * The one DIFFERENCE from the save half is declaration order, and it is not
 * cosmetic.  In the save half `t` is declared BETWEEN `i` and `j`, which puts
 * the table pointer in ip and the destination index in lr; here the same order
 * is 10 bytes out because the registers are the other way round -- the image
 * puts the table pointer in lr and the index in ip.  Declaring `j` before `t`
 * reproduces it exactly.  The two mirrors therefore disagree on declaration
 * order despite being written from the same template, which is the
 * declaration-order-is-register-order idiom applied in both directions.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0206168C.c \
 *       --func func_0206168C --addr 0x0206168C --arm --cc 1.1p1
 *   EXACT, 64 bytes, 1 relocation site, resolved.
 */

typedef unsigned int u32;

struct Ent020A816C { u32 w[6]; };

extern struct Ent020A816C g_020A816C[];

void func_0206168C(u32 *src)
{
    int i = 0;
    int j = i;
    struct Ent020A816C *t = g_020A816C;

    for (; i < 5; i++) {
        t->w[0] = src[j];
        t->w[1] = src[j + 1];
        j += 2;
        t++;
    }
}
