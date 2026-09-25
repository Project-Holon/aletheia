/*
 * function: func_021B6984
 * address:  0x021B6984
 * packet:   pkt_021B6984
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * BLOCKER: 2 bytes, r1 vs r0.  The original compares p[0x1c] in r1 so that
 * the body load p[0x18] can use r0; this compiler folds the dead comparison
 * temporary onto r0 in every spelling tried (inline, named local, pointer
 * type, separate body local).  The rest is byte-correct.
 *
 * symbols:
 *   func_02015BA4  0x02015BA4  thumb
 */

extern void func_02015BA4(int);

void func_021B6984(char *p)
{
    int v = *(int *)(p + 0x1c);

    if (v != 0) {
        func_02015BA4(*(int *)(p + 0x18));
        *(int *)(p + 0x1c) = 0;
    }
}
