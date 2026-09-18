/*
 * function: func_0206164C
 * address:  0x0206164C
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
 * Copies the first two words of each of the five 0x18-byte records at
 * 0x020A816C out into the caller's buffer, ten words in all.
 *
 * Ten concrete bytes differ and every instruction reproduces: the residue is
 * which of the three loop quantities gets which register.  The original holds
 * `i` in r3, the table pointer in ip and the destination index in lr; this C
 * holds `i` in r3, the index in ip and the table pointer in lr, so
 * `add ip, ip, #0x18` / `add lr, lr, #2` come out swapped while the indexed
 * store/address pair is byte-identical.  Declaration order moves the residue
 * (t,i,j -> 15 bytes, i,j,t -> 10, j,i,t -> 13) but never removes it: the
 * pointer-to-lr preference is an allocator decision.  See
 * docs/notes/pkt_0206164C.c.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0206164C.c \
 *       --func func_0206164C --addr 0x0206164C --arm --cc 1.1p1
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent020A816C {
    u32 w[6];
};

extern struct Ent020A816C g_020A816C[];

void func_0206164C(u32 *dst)
{
    int i;
    int j = 0;
    struct Ent020A816C *t = g_020A816C;

    for (i = 0; i < 5; i++) {
        dst[j] = t->w[0];
        dst[j + 1] = t->w[1];
        j += 2;
        t++;
    }
}
