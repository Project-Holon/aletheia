/*
 * function: func_021A5EDC
 * address:  0x021A5EDC
 * packet:   pkt_ov021_021A5EDC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb
 *   func_021A3964  0x021A3964  thumb
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int pad[4];
    unsigned char *f14;
} S;

extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *p, int a);
extern void func_021A3964(unsigned char *a, int b);

void func_021A5EDC(S *a, void *b, int c, int d, u16 e, int f)
{
    int k;
    if (f == 1) {
        k = 0x14;
    } else if (d & 2) {
        k = 0x58;
    } else {
        k = 0xc;
    }
    func_0216D410(b, func_02197E7C(e, k));
    a->f0 = 1;
    func_021A3964(a->f14, 1);
}
