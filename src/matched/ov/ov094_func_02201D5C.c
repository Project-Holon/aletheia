/*
 * function: func_02201D5C
 * address:  0x02201D5C
 * packet:   pkt_ov094_02201D5C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02201E04  0x02201E04  thumb  ov094
 *   func_02201FF4  0x02201FF4  thumb  ov094
 *   func_0220203C  0x0220203C  thumb  ov094
 *
 * lever: a brace-initialised Vec local compiles to an @N rodata template; three field stores do not.
 */
typedef struct {
    int x, y, z;
} Vec;

extern void func_02201FF4(void *a, void *b);
extern void func_0220203C(void *a);
extern void func_02201E04(void *o, int idx, int c, Vec *v, void *d, int s1, int s2, int s3,
                          void (*f1)(void *, void *), void (*f2)(void *));

void func_02201D5C(char *o, int idx, int c, void *d, int s1, int s2, int s3)
{
    Vec v;

    v.x = 0x1000;
    v.y = 0x1000;
    v.z = 0x1000;

    func_02201E04(o, idx, c, &v, d, s1, s2, s3, func_02201FF4, func_0220203C);
    *(unsigned *)(o + 0x7c) |= 1 << idx;
}
