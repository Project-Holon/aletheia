/*
 * function: func_021F2130
 * address:  0x021F2130
 * packet:   pkt_ov029_021F2130
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02051C88  0x02051C88  arm
 *   func_021F2D50  0x021F2D50  thumb  ov029
 *   func_021F2DC8  0x021F2DC8  thumb  ov029
 *   func_021F1F80  0x021F1F80  thumb  ov029
 *   func_021F2DA8  0x021F2DA8  thumb  ov029
 *   func_021F05D0  0x021F05D0  thumb  ov029
 *   func_021F0728  0x021F0728  thumb  ov029
 *   func_021F1CD8  0x021F1CD8  thumb  ov029
 */

extern void func_02051C88(int);
extern void func_021F2D50(void *);
extern void func_021F2DC8(void *);
extern void func_021F1F80(void *);
extern int func_021F2DA8(void *);
extern void func_021F05D0(void *);
extern void func_021F0728(void *);
extern void func_021F1CD8(void *);

void func_021F2130(char *p)
{
    func_02051C88(*(int *)(p + 0x10));
    func_021F2D50(p);
    func_021F2DC8(p);
    func_021F1F80(p);
    if (func_021F2DA8(p) == 0) {
        if (*(unsigned char *)(p + 0x45A)) {
            func_021F05D0(p);
            func_021F0728(p);
            func_021F1CD8(p);
        }
    } else {
        *(int *)(p + 0x214) = 0;
    }
}
