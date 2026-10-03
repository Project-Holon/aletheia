/*
 * function: func_021E5DAC
 * address:  0x021E5DAC
 * packet:   pkt_ov093_021E5DAC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5B40  0x021D5B40  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D805C  0x021D805C  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern u32 func_021D5B40(void *p);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern u32 func_021D805C(u32 v, int k);

void func_021E5DAC(u8 *p, void *a, int b, int *c)
{
    void *r;
    u16 v;
    u8 *q;
    if (b != func_021D775C(3))
        return;
    r = func_021C7CF4(a, b);
    v = func_021D5B40(r);
    if (v == 0)
        return;
    q = func_021C88A4(a, 0x23, b);
    *(int *)(q + 4) = 1;
    func_021C88C8(a, q);
    *c = 1;
    if (func_021D775C(0x46) == 0 && func_021D775C(0x47) == 0 && func_021D805C(v, 9) != 0) {
        q = func_021C88A4(a, 0x22, b);
        q[4] = func_021D775C(4);
        *(u16 *)(q + 6) = v;
        func_021C88C8(a, q);
    }
}
