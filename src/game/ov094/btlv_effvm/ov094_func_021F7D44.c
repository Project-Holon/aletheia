/*
 * function: func_021F7D44
 * address:  0x021F7D44
 * packet:   pkt_ov094_021F7D44
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Queues request 0x23d with value b on the handle at 0x188, then sets the word at 0x1e8 to 1.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 *   func_021F9844 0x021F9844 thumb ov094
 *   func_021F94F8 0x021F94F8 thumb ov094
 */
typedef struct {
    int w[3];
    unsigned short v;
} Req;

extern char *d_0220AF20;
extern void func_021F9844(Req *);
extern void func_021F94F8(void *, int, int, int, Req *);

void func_021F7D44(int a, unsigned short b)
{
    Req req;

    func_021F9844(&req);
    req.v = b;
    func_021F94F8(*(void **)(d_0220AF20 + 0x188), 0, a, 0x23d, &req);
    *(int *)(d_0220AF20 + 0x1e8) = 1;
}
