/*
 * function: sakeiCancelRequest
 * address:  0x021DD328
 * packet:   pkt_021DD328
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   gsiCoreCancelTask  0x0217CECC  arm  ov009
 *
 * Returns 3 unless both arguments, the word at +0x20 of the second and
 *  *  that word's +0x24 field are all non-null; otherwise hands the field to
 *  *  0x0217CECC (ov009) and returns 0.  One predicated cmpne chain, so the
 *  *  whole test is a single short-circuit expression.
 */

typedef unsigned long u32;

struct GSTask;
extern void gsiCoreCancelTask(struct GSTask *theTask);

int sakeiCancelRequest(char *a, char *b)
{
    u32 v;
    if (a && b && *(char **)(b + 0x20)
        && (v = *(u32 *)(*(u32 *)(b + 0x20) + 0x24)) != 0) {
        gsiCoreCancelTask((struct GSTask *)v);
        return 0;
    }
    return 3;
}

