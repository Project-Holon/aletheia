/*
 * function: func_021F5840
 * address:  0x021F5840
 * packet:   pkt_021F5840
 * region:   ov082
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  register allocation, not logic.  My C reproduces the whole body
 * but the original parks `a` in r4 and the loop bound `e` in r0 (so the
 * nested loop compares r2 with r0 and the table load is [r4+4*idx]); mwcc
 * here keeps `a` in r0 and `e` in r1 and puts f[1] in r4.  No relocations
 * are involved, so a matching C shape would be EXACT; the several source
 * shapes tried (int/unsigned, char*/unsigned*, subscript vs pointer) all
 * land on the same allocation.  Zero external evidence issue.
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_021F5840(unsigned *a, unsigned b, unsigned c, unsigned d, unsigned e, char *f)
{
    unsigned i, j;
    unsigned base;

    if (*(int *)(f + 4) != 0)
        return;
    if (*(u8 *)(f + 8) != 0) {
        *(u8 *)(f + 8) = *(u8 *)(f + 8) - 1;
        return;
    }
    if (*(u16 *)(f + 0xa) == 0 && *(int *)f != 0)
        return;

    *(int *)(f + 4) = 1;
    base = c + d * *(u16 *)(a + *(u16 *)(f + 0xa));
    for (i = 0; i < 2; i++) {
        for (j = 0; j < e; j++) {
            *(u16 *)(f + 12 * i + 0xc + 2 * j) =
                (u16)(base + e * i + j);
        }
    }
    *(u8 *)(f + 8) = *(u8 *)(f + 9);
    (*(u16 *)(f + 0xa))++;
    if (*(u16 *)(f + 0xa) >= b) {
        *(u16 *)(f + 0xa) = 0;
        *(int *)f = 1;
    }
}
