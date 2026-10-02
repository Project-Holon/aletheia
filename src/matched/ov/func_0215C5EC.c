/*
 * function: func_0215C5EC
 * address:  0x0215C5EC
 * packet:   pkt_0215C5EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two overlay lookups on the second argument, the second of them classified
 * by an arm9 call, then submitted together.
 *
 * symbols:
 *   func_0215A5F4   0x0215A5F4  thumb  ov010
 *   func_0215A5DC   0x0215A5DC  thumb  ov010
 *   func_020145CC   0x020145CC  thumb
 *   func_0215897C   0x0215897C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_020145CC(void *);
extern void func_0215897C(void *, void *);

int func_0215C5EC(void *a0, void *a1)
{
    void *v = func_0215A5F4(a1);

    func_0215897C(v, func_020145CC(func_0215A5DC(a1)));

    return 1;
}

