/*
 * function: func_021FE930
 * address:  0x021FE930
 * packet:   pkt_ov094_021FE930
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Lever: the `mask |= 1 << i` tail is written out in both arms (then-arm
 * innermost, and the else arm); the compiler cross-jumps them and leaves the
 * `b` to the next instruction.  A single shared tail (goto/continue) gives no
 * `b` and hoists r7/r4 in the other order.
 *
 * symbols:
 *   func_021F7F1C  0x021F7F1C  thumb  ov094
 *   func_021F8694  0x021F8694  thumb  ov094
 *   func_021FFCB0  0x021FFCB0  thumb  ov094
 *   func_021F935C  0x021F935C  thumb  ov094
 *   func_021FF304  0x021FF304  thumb  ov094
 *   func_021FF470  0x021FF470  thumb  ov094
 *   func_021F89BC  0x021F89BC  thumb  ov094
 */
typedef struct {
    int pad0;
    int side;
    int mask;
} Arg;

extern int func_021F7F1C(int i);
extern int func_021F8694(void);
extern int func_021FFCB0(char *p, int key);
extern int func_021F935C(int x);
extern void func_021FF304(char *p, int key, int mode);
extern void func_021FF470(char *p, int key, void *v);
extern void func_021F89BC(void *h);

void func_021FE930(void *h, Arg *a)
{
    int i = 1;
    int want;

    if (a->side == 0)
        i = 0;
    if (a->side != 0)
        want = 0xaa;
    else
        want = 0x55;
    while (i <= 7) {
        if (func_021F7F1C(i)) {
            if (func_021FFCB0((char *)func_021F8694(), i) == 0) {
                if ((func_021F935C(i) & a->mask) == 0) {
                    func_021FF304((char *)func_021F8694(), i, 0);
                    func_021FF470((char *)func_021F8694(), i, 0);
                    a->mask |= func_021F935C(i);
                }
            }
        } else {
            a->mask |= func_021F935C(i);
        }
        i += 2;
    }
    if (want == a->mask)
        func_021F89BC(h);
}
