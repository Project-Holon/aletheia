/*
 * function: func_0216A244
 * address:  0x0216A244
 * packet:   pkt_0216A244
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * unblocked: func_021A3244 (ov021 tail-call thunk) matched bottom-up and
 *   filed as pkt_021A3244; the `ov021` token resolves its call as
 *   `matched, overlay`.  Extent runs 32 against 30 compiled: the unlabelled
 *   follower.
 *
 * The overlay's own status call takes the arm9 handle; anything but one
 * reads as failure.
 *
 * symbols:
 *   func_02188CB4   0x02188CB4  thumb
 *   func_021A3208   0x021A3208  thumb
 *   func_021A3244   0x021A3244  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_02188CB4(unsigned char *p);
extern int func_021A3208(void *);
extern int func_021A3244(void *);

int func_0216A244(void *a0)
{
    void *v = func_02188CB4(*(void **)((char *)a0 + 8));

    if (func_021A3208(v) == 1)
        return func_021A3244(v);

    return 1;
}
