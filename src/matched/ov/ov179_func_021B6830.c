/*
 * function: func_021B6830
 * address:  0x021B6830
 * packet:   pkt_ov179_021B6830
 * region:   ov179
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr-saving prologue): the listing prints it as .word
 * data.  Entry of the ov179 command table (pool word 0x021B6831 at 0x021B6A68).
 */
int func_021B6830(char *p, int *q)
{
    *(int *)(p + 0x6034) = q[1];
    *(int *)(p + 0x6038) = q[2];
    *(int *)(p + 0x6050) = 3;
    *(int *)(p + 0x6054) = 5;
    return 2;
}
