/*
 * function: func_021BB484
 * address:  0x021BB484
 * packet:   pkt_ov021_021BB484
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DE2E8     0x021DE2E8  data  a4
 *   func_021BB4BC  0x021BB4BC  thumb  ov021
 */

typedef struct {
    int f0;
} Obj;

extern int d_021DE2E8;

extern void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);
typedef unsigned int   u32;
extern void func_021BB4BC(u32 *p);

Obj *func_021BB484(int a, int b)
{
    Obj *q = func_02030734(b, 0x38, 1, (const char *)&d_021DE2E8, 0x6F);

    q->f0 = a;
    func_021BB4BC((u32 *)q);
    return q;
}
