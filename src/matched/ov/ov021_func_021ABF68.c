/*
 * function: func_021ABF68
 * address:  0x021ABF68
 * packet:   pkt_ov021_021ABF68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030CB0  0x02030CB0  arm
 *   func_02030734  0x02030734  arm
 *   func_02030CBC  0x02030CBC  arm
 *   func_021ABFFC  0x021ABFFC  thumb
 *   d_021DE018  0x021DE018  data  a4
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[3];
    u16 h14;
    u16 pad16;
    void *f18;
    int f1c;
    int f20;
} T;

typedef unsigned int   u32;
extern u32 func_02030CB0(u32 idx);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02030CBC(int n, void *buf);
extern int func_021ABFFC(int heap, int a, int n);
extern char d_021DE018[];

void func_021ABF68(T *t, int n)
{
    t->h14 = n;
    t->f18 = func_02030734(t->h4, func_02030CB0(n), 0, d_021DE018, 0x1db);
    t->f1c = func_02030CBC(n, t->f18);
    t->f20 = func_021ABFFC(t->h4, t->f1c, n);
}
