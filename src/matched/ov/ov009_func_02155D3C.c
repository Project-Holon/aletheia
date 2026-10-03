/*
 * function: func_02155D3C
 * address:  0x02155D3C
 * packet:   pkt_ov009_02155D3C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   func_02155D2C  0x02155D2C  thumb  ov009
 *   func_02155904  0x02155904  thumb  ov009
 *   func_02155374  0x02155374  thumb  ov009
 *   func_0216B838  0x0216B838  arm
 */

typedef struct {
    char pad[0x29c];
    void (*cb)(int, int);
    int arg;
} G;

extern G *d_021A8264;
void func_02155D2C(int e);
void func_02155904(void);
void func_02155374(int n);
unsigned char func_0216B838(void);

void func_02155D3C(int a, int b, int c, int d, int e)
{
    G *g;

    if (a == 0) {
        if (b == 0)
            func_02155D2C(e);
        else
            func_02155904();
    } else {
        func_02155374(14);
    }
    g = d_021A8264;
    if (g->cb != 0) {
        int r = func_0216B838();
        d_021A8264->cb(r, g->arg);
    }
}
