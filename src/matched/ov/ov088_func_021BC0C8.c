/*
 * function: func_021BC0C8
 * address:  0x021BC0C8
 * packet:   pkt_ov088_021BC0C8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: extent runs long; the follower holds three unlabelled tail-call
 * stubs at 0x021BC0E4, 0x021BC0FC, 0x021BC114 (function_starts seeds).
 *
 * symbols:
 *   func_020071E8  0x020071E8  thumb
 */

typedef unsigned int   u32;
struct Sub020071E4Ctrl;
extern u32 func_020071E8(const struct Sub020071E4Ctrl *ctrl);

int func_021BC0C8(char *p)
{
    int r = func_020071E8(*(void **)p);
    *(int *)(p + 0x148) = r;
    return r != 0;
}
