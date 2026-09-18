/*
 * function: func_0206168C
 * address:  0x0206168C
 * packet:   pkt_020613D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * symbols:
 *   g_020A816C   0x020A816C  data
 *
 * The exact mirror of func_0206164C: writes the caller's ten words into the
 * first two words of each of the five 0x18-byte records at 0x020A816C.  Ten
 * concrete bytes differ for the same register-choice reason (this C holds the
 * table pointer in lr where the original holds it in ip).  See
 * docs/notes/pkt_0206164C.c.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206168C.c \
 *       --func func_0206168C --addr 0x0206168C --arm --cc 1.1p1
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent020A816C {
    u32 w[6];
};

extern struct Ent020A816C g_020A816C[];

void func_0206168C(const u32 *src)
{
    int i;
    int j = 0;
    struct Ent020A816C *t = g_020A816C;

    for (i = 0; i < 5; i++) {
        t->w[0] = src[j];
        t->w[1] = src[j + 1];
        j += 2;
        t++;
    }
}
