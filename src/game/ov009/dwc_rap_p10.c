/*
 * file:     dwc_rap_p10.c
 * unit:     yes
 * function: func_02155B14
 * address:  0x02155B14
 * packet:   pkt_ov009_02155B14
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   func_02155A80  0x02155A80  thumb  ov009
 *   func_0216B838  0x0216B838  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    char pad[0x280];
    void (*cb)(int, int, int);
    char pad2[0x7a6 - 0x284];
    u8 flag;
} G;

extern G *d_021A8264;
int func_02155A80(void *src, int len, int c);
unsigned char func_0216B838(void);

int func_02155B14(int a, int b)
{
    if (d_021A8264->flag == 0)
        return 0;
    if (func_02155A80((void *)a, b, 1) == 0)
        return 0;
    d_021A8264->flag = 0;
    if (d_021A8264->cb != 0) {
        int r = func_0216B838();
        d_021A8264->cb(r, a, (u16)b);
    }
    return 1;
}
