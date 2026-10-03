/*
 * function: func_0220687C
 * address:  0x0220687C
 * packet:   pkt_ov094_0220687C
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030EE8  0x02030EE8  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02206864  0x02206864  thumb  ov094
 */

extern int func_02206864(char *p, void *q);
extern void *func_02030EE8(void *h);
extern void func_020307B0(void *p);
struct Node;
extern void func_02030EAC(struct Node *n);

void func_0220687C(char *p, void *q)
{
    int i = func_02206864(p, q);
    int off;

    if (q != 0) {
        void *r = func_02030EE8(q);
        char *t = p + 0x28;
        void (*cb)(void *);

        off = i * 4;
        cb = *(void (**)(void *))(t + off);
        if (cb != 0)
            cb(q);
        if (r != 0)
            func_020307B0(r);
        func_02030EAC(q);
        *(int *)(p + off + 8) = 0;
        *(int *)(t + off) = 0;
    }
}
