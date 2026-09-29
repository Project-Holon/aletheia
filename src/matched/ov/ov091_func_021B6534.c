/*
 * function: func_021B6534
 * address:  0x021B6534
 * packet:   pkt_ov091_021B6534
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B6818  0x021B6818  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x14];
    void *v14;
    u8 pad18[0x68 - 0x18];
    struct {
        void *a;
        void *b;
        u8 pad[4];
    } e[3];
} Q;

typedef struct {
    u8 pad[640];
    Q *q;
} P;

extern int func_021B6818(P *p);
extern void func_020307B0(void *p);
extern void func_020315D4(int);
extern void func_020306F0(int);

int func_021B6534(int a0, int a1, int a2, P *p)
{
    u8 i;

    if (func_021B6818(p) == 0)
        return 0;
    if (a2 == 0) {
        for (i = 0; i < 3; i++) {
            if (p->q->e[i].a != 0)
                func_020307B0(p->q->e[i].a);
            if (p->q->e[i].b != 0)
                func_020307B0(p->q->e[i].b);
        }
        if (p->q->v14 != 0)
            func_020307B0(p->q->v14);
        func_020307B0(*(void **)p->q);
        func_020307B0(p->q);
    }
    func_020315D4(a0);
    func_020306F0(0x17);
    return 1;
}
