/*
 * function: func_02159AE8
 * address:  0x02159AE8
 * packet:   pkt_02159AE8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two record lookups on the second argument and a classification of the
 * first, submitted as three arguments.
 *
 * symbols:
 *   func_0215A5E4   0x0215A5E4  thumb  ov010
 *   func_0215A5F4   0x0215A5F4  thumb  ov010
 *   func_02011330   0x02011330  thumb
 *   func_02158FE0   0x02158FE0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0215A5E4(void *a0);
extern void *func_0215A5F4(void *p);
extern u16 func_02011330(void *);
extern u16 *func_02158FE0(void *, void *, unsigned int);

u16 *func_02159AE8(void *a0, void *a1)
{
    void *v = func_0215A5E4(a1);

    return func_02158FE0(func_0215A5F4(a1), v, func_02011330(a0));
}

