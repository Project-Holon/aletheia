/*
 * function: func_02207960
 * address:  0x02207960
 * packet:   pkt_ov094_02207960
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_022079C0  0x022079C0  thumb  ov094
 *   func_02030EAC  0x02030EAC  arm
 *   d_0220AAB4     0x0220AAB4  data   ov094  a2
 */
typedef struct {
    short x;
    short y;
} Pt;

typedef struct {
    unsigned int lo : 3;
    unsigned int b3 : 1;
} Bf;

extern const Pt d_0220AAB4;
extern void func_022079C0(char *p, int i, Pt *pt);
struct Node;
extern void func_02030EAC(struct Node *n);

void func_02207960(char *p, int i)
{
    char *q = p + 0xb0;
    int o = i * 128;
    void *t;

    if (((Bf *)(q + o))->b3) {
        Pt pt = d_0220AAB4;

        if (i & 1)
            pt.x *= -1;
        func_022079C0(p, i, &pt);
        ((Bf *)(q + o))->b3 = 0;
    }
    t = *(void **)(p + o + 0xbc);
    if (t != 0) {
        func_02030EAC(t);
        *(int *)(p + o + 0xbc) = 0;
    }
}
