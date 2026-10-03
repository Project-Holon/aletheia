/*
 * function: func_02209458
 * address:  0x02209458
 * packet:   pkt_ov094_02209458
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3B4  0x0204B3B4  arm
 *   func_02030EAC  0x02030EAC  arm
 */
typedef unsigned int u32;

typedef struct {
    int f[7];
} Row;

typedef struct {
    Row r[2];
    char pad[0x6c - 0x38];
    void *m6c;
    void *m70;
} W;

extern void func_0204B3B4(int h);
struct Node;
extern void func_02030EAC(struct Node *n);

void func_02209458(W *w)
{
    int i;
    int j;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            if (w->r[i].f[j + 2] != 0) {
                func_0204B3B4(w->r[i].f[j + 2]);
                w->r[i].f[j + 2] = 0;
            }
        }
    }
    if (w->m6c != 0) {
        func_02030EAC(w->m6c);
        w->m6c = 0;
    }
    if (w->m70 != 0) {
        func_02030EAC(w->m70);
        w->m70 = 0;
    }
}
