/*
 * function: func_021F7E38
 * address:  0x021F7E38
 * packet:   pkt_ov094_021F7E38
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 *   func_021FFE48  0x021FFE48  thumb  ov094
 *   func_022003EC  0x022003EC  thumb  ov094
 *   func_022001DC  0x022001DC  thumb  ov094
 */
typedef struct {
    char pad[0x190];
    void *h190;
} Work;

extern Work *d_0220AF20;

extern void func_021FFE48(void *h, int b, int a);
extern void func_022003EC(void *h, int a, int *buf, int b);
extern void func_022001DC(void *h, int b, int *buf);

void func_021F7E38(int a, int b)
{
    int buf[9];

    func_021FFE48(d_0220AF20->h190, b, a);
    func_022003EC(d_0220AF20->h190, a, buf, b);
    func_022001DC(d_0220AF20->h190, b, buf);
}
