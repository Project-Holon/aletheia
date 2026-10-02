/*
 * function: func_021A5EA4
 * address:  0x021A5EA4
 * packet:   pkt_ov021_021A5EA4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D5F8  0x0216D5F8  thumb
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

extern u16 func_0216D5F8(void *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *p, int a);
extern void func_021A3964(unsigned char *a, int b);

void func_021A5EA4(S *a, void *b, int c, int d, u16 e)
{
    if (e == 9) {
        e = func_0216D5F8(b);
    }
    func_0216D410(b, func_02197E7C(e, 0));
    a->f0 = 0;
    func_021A3964(a->f14, 0);
}
