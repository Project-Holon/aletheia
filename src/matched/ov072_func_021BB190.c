/*
 * function: func_021BB190
 * address:  0x021BB190
 * packet:   pkt_021BB190
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (12) runs 2 bytes past the compiled function (10);
 *           trailing alignment padding, no byte difference.  A two-word copy
 *           at a nonzero offset is a struct assignment (hoists both loads and
 *           allocates r2/r0); two locals let the stores reorder and diff.
 */

typedef struct {
    int a;
    int b;
} S;

void func_021BB190(char *p, int *o)
{
    *(S *)o = *(S *)(p + 0x20);
}
