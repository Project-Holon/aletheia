/*
 * function: func_021BB36C
 * address:  0x021BB36C
 * packet:   pkt_ov021_021BB36C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B79E4  0x021B79E4  thumb  ov021
 *   func_021B79F0  0x021B79F0  thumb  ov021
 */

typedef struct {
    void *f0;
    char pad[0x10];
    int f14;
} Obj;

extern void func_021B79E4(void *a);
extern void func_021B79F0(void *a, int b);

void func_021BB36C(Obj *p)
{
    func_021B79E4(p->f0);
    if (p->f14 == 0) {
        func_021B79F0(p->f0, 0);
    }
}
