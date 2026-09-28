/*
 * function: func_021F8B40
 * address:  0x021F8B40
 * packet:   pkt_ov094_021F9AB8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
typedef struct {
    char pad[8];
    void *handle[32];      /* 0x008 */
    void (*cb[32])(void *); /* 0x088 */
    int arg[32];           /* 0x108 */
} Work;

extern Work *d_0220AF20;

extern void func_021F89BC(void *h);

int func_021F8B40(void)
{
    Work *w;
    int i;

    i = 0;
    w = d_0220AF20;
    for (; i < 32; i++) {
        if (w->handle[i] == 0)
            break;
    }
    if (i == 32) {
        func_021F89BC(w->handle[0]);
        i = 0;
    }
    return i;
}
