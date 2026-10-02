/*
 * function: func_021EA14C
 * address:  0x021EA14C
 * packet:   pkt_ov170_021EA14C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_020077B8 0x020077B8 thumb
 *   func_021EA1C0 0x021EA1C0 thumb
 *   func_021E8FC0 0x021E8FC0 thumb
 *   func_021E087C 0x021E087C thumb
 */

typedef struct {
    int pad0;
    void *x4;
} Top;

extern void func_020061E4(unsigned se);
extern int func_020077B8(void *save, unsigned box);
extern void func_021EA1C0(unsigned char *p);
extern int func_021E8FC0(unsigned char *p, int (*cb)(unsigned char *), int n);
extern int func_021E087C(unsigned char *p);

int func_021EA14C(unsigned char *p, unsigned i, int v)
{
    if (i >= 0x1E && i >= 0x24 && i != 0xFF) {
        unsigned k = p[0x19] + i - 0x24;
        if (k >= p[0x15])
            k -= p[0x15];
        if (k == p[0x14]) {
            func_020061E4(0x557);
            return 0x15;
        }
        if (func_020077B8((*(Top **)p)->x4, k) == 0) {
            func_020061E4(0x557);
            return 0x15;
        }
    }
    *(unsigned char *)(*(char **)(p + 0x2C) + 0xA17E) = i;
    p[0x1A] = 2;
    *(int *)(p + 0x28) = v;
    func_021EA1C0(p);
    return func_021E8FC0(p, func_021E087C, 0x17);
}
