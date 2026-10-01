/*
 * function: func_021B680C
 * address:  0x021B680C
 * packet:   pkt_ov179_021B680C
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr-saving prologue).  The two stores are written
 * into both arms: the compiler cross-jumps them into one tail
 * (bne / ldr / b / ldr, str [p,o]; adds o,#4; str [p,o+4]).  Selecting
 * the offset into a local and storing once after the if/else either
 * if-converts the select (int offset) or folds the second store to
 * [p+o,#4] (long offset).
 */
int func_021B680C(char *p, int *q)
{
    if (q[1] == 0) {
        *(int *)(p + 0x6024) = q[2];
        *(int *)(p + 0x6028) = q[3];
    } else {
        *(int *)(p + 0x602C) = q[2];
        *(int *)(p + 0x6030) = q[3];
    }
    return 1;
}
