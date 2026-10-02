/*
 * function: func_021DEE7C
 * address:  0x021DEE7C
 * packet:   pkt_ov093_021DEE7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */
typedef unsigned char u8;
extern int func_021D775C(int);
extern void func_021DD044(void *, void *, int);
void func_021DEE7C(void *a, void *b, int c, int *d)
{
    if (c == func_021D775C(3) && *d != 0)
        func_021DD044(a, b, c);
}
