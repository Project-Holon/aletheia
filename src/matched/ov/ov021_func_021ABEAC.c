/*
 * function: func_021ABEAC
 * address:  0x021ABEAC
 * packet:   pkt_ov021_021ABEAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DE018  0x021DE018  data  a4
 */

typedef unsigned short u16;

typedef struct {
    int f0;
    int f4;
} E;

typedef struct T T;

typedef struct {
    int id;
    int (*f4)(T *t, u16 h);
    void (*f8)(T *t, int v);
} D;

struct T {
    int f0;
    u16 h4;
    u16 pad6;
    int pad8[2];
    E *f10;
};

extern void *func_02030734(int heap, int size, int clear, const char *file, int line);
extern char d_021DE018[];

void func_021ABEAC(T *t)
{
    E *e;
    int i;
    e = t->f10 = func_02030734(t->h4, t->f0 * 8, 1, d_021DE018, 0x174);
    i = 0;
    if (t->f0 > 0) {
        for (; i < t->f0; i++) {
            e->f0 = 0x18;
            e++;
        }
    }
}
