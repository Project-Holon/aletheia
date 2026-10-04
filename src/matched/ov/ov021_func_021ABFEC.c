/*
 * function: func_021ABFEC
 * address:  0x021ABFEC
 * packet:   pkt_ov021_021ABFEC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC074  0x021AC074  thumb
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

struct Mgr;
extern void func_021AC074(struct Mgr *m);

void func_021ABFEC(T *t)
{
    if (t->f20 != 0) {
        func_021AC074((struct Mgr *)t->f20);
    }
}
