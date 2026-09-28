/*
 * function: func_020972F0
 * address:  0x020972F0
 * packet:   pkt_02096ED0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_02097170   0x02097170  arm
 *   func_02096670   0x02096670  arm
 */

typedef unsigned char u8;
typedef signed short s16;

typedef struct P0972 {
    u8 pad0[2];
    s16 f2;
    u8 f4;
    u8 buf[1];
} P0972;

extern void func_02097170(P0972 *p);
extern void func_02096670(P0972 *p, int n);

void func_020972F0(void *a0, int a1, int a2, P0972 *p)
{
    int n = *(s16 *)((char *)a0 + 2);
    int i;

    func_02097170(p);
    if (p->buf[0] > 9)
        return;
    if (n > 0x20)
        n = 0x20;
    func_02096670(p, n);
    while (p->f4 < n)
        p->buf[p->f4++] = 0;
    p->f2 -= (s16)(p->f4 - 1);
    for (i = 0; i < p->f4; i++)
        p->buf[i] += 0x30;
}
