/*
 * function: func_021E869C
 * address:  0x021E869C
 * packet:   pkt_ov093_021E869C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021E8638  0x021E8638  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct QF;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern int func_021D5B40(void *p);
extern int func_021E8638(int a, int b);

int func_021E869C(void *a, int b)
{
    void *r;
    int t;
    u16 s;

    r = func_021C7CF4(a, b);
    t = func_021D5444(r);
    s = func_021D5B40(r);
    if (func_021E8638(t, s) != 0)
        return 1;
    return 0;
}
