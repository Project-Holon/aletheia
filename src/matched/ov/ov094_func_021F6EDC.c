/*
 * function: func_021F6EDC
 * address:  0x021F6EDC
 * packet:   pkt_ov094_021F6EDC
 * region:   ov094
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: inferred extent is two bytes long; the follower is an unlabelled
 * leaf that disasm.py did not label.
 *
 * symbols:
 *   func_02048AFC  0x02048AFC  arm
 *   func_02048B44  0x02048B44  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_021F73A4  0x021F73A4  thumb  ov094
 */

extern void func_02048AFC(int, const int *);
extern void func_02048B44(int, int);
struct Light;
extern void func_02048AD0(struct Light *l);
extern void func_021F73A4(int *);

void func_021F6EDC(int *p, int *a, int *b)
{
    if (a) {
        p[6] = a[0];
        p[7] = a[1];
        p[8] = a[2];
        func_02048AFC(p[1], a);
    }
    if (b) {
        p[9] = b[0];
        p[10] = b[1];
        p[11] = b[2];
        func_02048B44(p[1], (int)b);
    }
    func_02048AD0((struct Light *)p[1]);
    func_021F73A4(p);
}
