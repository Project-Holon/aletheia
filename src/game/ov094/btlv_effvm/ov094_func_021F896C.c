/*
 * function: func_021F896C
 * address:  0x021F896C
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
 *   func_021F8B40  0x021F8B40  thumb  ov094
 */
typedef struct {
    char pad[8];
    void *handle[32];      /* 0x008 */
    void (*cb[32])(void *); /* 0x088 */
    int arg[32];           /* 0x108 */
} Work;

extern Work *d_0220AF20;

extern int func_021F8B40(void);

void func_021F896C(void *h, void (*cb)(void *), int arg)
{
    int i = func_021F8B40();

    d_0220AF20->handle[i] = h;
    d_0220AF20->cb[i] = cb;
    d_0220AF20->arg[i] = arg;
}
