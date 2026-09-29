/*
 * function: func_021F38F0
 * address:  0x021F38F0
 * packet:   pkt_ov052_021F38F0
 * region:   ov052
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C98  0x02188C98  thumb  ov021
 *   func_0218DC4C  0x0218DC4C  thumb  ov021
 *   d_021F39CC     0x021F39CC  data  a4
 */

typedef struct { int v[4]; } T4;
typedef struct { int x, y, z; } V3;

extern T4 d_021F39CC;
extern int func_02188C98(int);
extern void func_0218DC4C(int, V3 *);

void func_021F38F0(char *a, int b)
{
    V3 v = {0, 0, 0};
    T4 t = d_021F39CC;
    unsigned char *p = *(unsigned char **)(a + 0x24);
    int r = func_02188C98(b);

    switch (p[1]) {
    case 0:
        if (p[0] == 1)
            return;
        *(int *)(p + 4) = t.v[p[2]];
        p[2]++;
        p[2] &= 3;
        p[1]++;
    case 1:
        if (--*(int *)(p + 4) <= 0) {
            *(int *)(p + 8) = 1;
            p[1]++;
        }
        break;
    case 2:
        v.y = *(int *)(p + 8) << 12;
        func_0218DC4C(r, &v);
        if (*(int *)(p + 8) == 0)
            p[1] = 0;
        if (*(int *)(p + 8) < 0) {
            *(int *)(p + 8) += 2;
            if (*(int *)(p + 8) > 0)
                *(int *)(p + 8) = 0;
        }
        *(int *)(p + 8) = -*(int *)(p + 8);
        break;
    }
}
