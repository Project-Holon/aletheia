/*
 * function: func_021DE9E8
 * address:  0x021DE9E8
 * packet:   pkt_ov119_021DE9E8
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E12AC  0x021E12AC  thumb  ov119
 *   d_021E76DC     0x021E76DC  data  a4
 *   func_021E131C  0x021E131C  thumb  ov119
 *   func_021D8E84  0x021D8E84  thumb  ov119
 *   func_021DE988  0x021DE988  thumb  ov119
 */

typedef struct {
    int a;
    int b;
} Pair;

extern int func_021E12AC(char *p);
extern const Pair d_021E76DC;
extern void func_021E131C(char *p, int *ids, int count, int x, int y);
extern void func_021D8E84(void *p, int next);
extern void func_021DE988(char *p);

void func_021DE9E8(void *p)
{
    Pair t;
    if (func_021E12AC(p) != 0) {
        t = d_021E76DC;
        func_021E131C(p, (int *)&t, 2, 0x20, 12);
        func_021D8E84(p, (int)func_021DE988);
    }
}
