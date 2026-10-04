/*
 * function: func_0215F1C8
 * address:  0x0215F1C8
 * packet:   pkt_ov010_0215F1C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_0217294C     0x0217294C  data  ov010  a4
 *   func_0215F168  0x0215F168  thumb  ov010
 *   func_020113D0  0x020113D0  thumb
 */

typedef unsigned short u16;

extern void *func_0215A5F4(void *p);
typedef unsigned int   u32;
extern void *func_02158FB4(void *p);
extern u16 *func_02159AE8(void *a, void *b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_0217294C[];
extern int func_0215F168(int a0, int a1);
extern void func_020113D0(char *p, int val);

int func_0215F1C8(void *a, void *b)
{
    void **slot;
    u16 *w;
    void **p;

    slot = func_02158FB4(func_0215A5F4(b));
    w = func_02159AE8(a, b);
    p = func_02030734(4, 4, 1, d_0217294C, 0x63);
    *slot = p;
    *p = w;
    *w = 0;
    func_020113D0(a, (int)func_0215F168);
    return 1;
}
