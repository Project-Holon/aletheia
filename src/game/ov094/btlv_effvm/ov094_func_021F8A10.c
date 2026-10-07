/*
 * function: func_021F8A10
 * address:  0x021F8A10
 * packet:   pkt_ov094_021F8A10
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Runs func_021F89BC on each live object owned by a.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021F89BC 0x021F89BC thumb ov094
 */
typedef struct {
    char pad[8];
    void *obj[32];          /* 0x008 */
    char pad88[0x108 - 0x88];
    int owner[32];          /* 0x108 */
} Work;

extern Work *d_0220AF20;
extern void func_021F89BC(void *);

void func_021F8A10(int a)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (d_0220AF20->obj[i] != 0 && a == d_0220AF20->owner[i])
            func_021F89BC(d_0220AF20->obj[i]);
    }
}
