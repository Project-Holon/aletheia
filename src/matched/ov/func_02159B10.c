/*
 * function: func_02159B10
 * address:  0x02159B10
 * packet:   pkt_02159B10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Same three-argument submission as its neighbour, aimed at the second
 * overlay handler.
 *
 * symbols:
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_0215A5F4   0x0215A5F4  thumb  ov010
 *   func_02011330   0x02011330  thumb
 *   func_0215901C   0x0215901C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *);
extern void *func_0215A5F4(void *);
extern void *func_02011330(void *);
extern unsigned int func_0215901C(void *, void *, void *);

unsigned int func_02159B10(void *a0, void *a1)
{
    void *v = func_0215A5E4(a1);

    return func_0215901C(func_0215A5F4(a1), v, func_02011330(a0));
}

