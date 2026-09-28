/*
 * function: func_02176674
 * address:  0x02176674
 * packet:   pkt_ov009_021702A0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * DWCi_StopMeshMaking: abandons the mesh step in progress, cancelling any NAT negotiation.
 *
 * symbols:
 *   func_02175F3C  0x02175F3C  arm  ov009
 *   func_02176554  0x02176554  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02199FB4  0x02199FB4  arm  ov009
 *   func_02171F68  0x02171F68  arm  ov009
 *   func_021719A4  0x021719A4  arm  ov009
 *   func_0217653C  0x0217653C  arm  ov009
 */

typedef struct {
    int w[10];
} NodeInfo;

extern char *func_02175F3C(void);
extern int func_02176554(void);
extern void MI_CpuFill8(void *p, int v, int n);
extern void func_02199FB4(int cookie);
extern int func_02171F68(int unused);
extern int func_021719A4(int error);
extern void func_0217653C(void);

int func_02176674(void)
{
    if (*(int *)(func_02175F3C() + 0x5a4) == 0) {
        return 0;
    }
    *(int *)(func_02175F3C() + 0x5a4) = 0;
    *(int *)(func_02175F3C() + 0x5a8) = *(int *)(func_02175F3C() + 0x61c);
    if (func_02176554() != 0) {
        *(NodeInfo *)(func_02175F3C() + 0x5ac) = *(NodeInfo *)(func_02175F3C() + 0x554);
    } else {
        MI_CpuFill8(func_02175F3C() + 0x5ac, 0, 0x28);
    }
    if (*(int *)(func_02175F3C() + 0x618) != 0) {
        func_02199FB4(*(int *)(func_02175F3C() + 0x618));
        *(int *)(func_02175F3C() + 0x618) = 0;
        *(unsigned char *)(func_02175F3C() + 0x5f8) = 0;
        *(int *)(func_02175F3C() + 0x5fc) = 0;
        *(unsigned long long *)(func_02175F3C() + 0x600) = 0;
    }
    if (*(int *)(func_02175F3C() + 0x61c) == 3 || *(int *)(func_02175F3C() + 0x61c) == 5 ||
        *(int *)(func_02175F3C() + 0x61c) == 6 || *(int *)(func_02175F3C() + 0x61c) == 14 ||
        *(int *)(func_02175F3C() + 0x61c) == 15) {
        if (*(int *)(func_02175F3C() + 0x67c) != 0) {
            if (func_021719A4(func_02171F68(0)) != 0) {
                func_0217653C();
                return 1;
            }
        }
        *(unsigned char *)(func_02175F3C() + 0x18) = 0;
        *(int *)(func_02175F3C() + 0x5dc) = 0;
    }
    func_0217653C();
    return 1;
}
