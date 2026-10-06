/*
 * function: func_021ABEE8
 * address:  0x021ABEE8
 * packet:   pkt_ov021_021ABEE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021ABF48  0x021ABF48  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 */

typedef struct {
    int kind;
    int arg;
} E;

typedef struct {
    int n;
    int f4;
    int f8;
    int fc;
    E *e;
} O;

typedef struct {
    int f0;
    int f4;
    void (*fn)(O *o, int arg);
} T;

extern T *func_021ABF48(int kind);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void func_021ABEE8(O *o)
{
    int i;
    E *e;

    i = 0;
    e = o->e;
    if (i < o->n) {
        for (; i < o->n; i++, e++) {
            if (e->kind != 0x18) {
                func_021ABF48(e->kind)->fn(o, e->arg);
                e->kind = 0x18;
                e->arg = 0;
            }
        }
    }
    func_020307B0(o->e);
    o->e = 0;
}
