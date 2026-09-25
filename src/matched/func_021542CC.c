/*
 * function: func_021542CC
 * address:  0x021542CC
 * packet:   pkt_021542CC
 * region:   ov007
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Field touch on the argument, then allocator + guard + three-field link setup.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02154310  0x02154310  thumb  ov007
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

int func_020120F4(void *p);
void *func_020122C0(void *p, int a, void (*cb)(void), int n);
int func_02012138(void *p);
int func_02026454(int x);
void func_02026400(int x);
void *func_020124E8(void *p);
void func_02154310(void);

void *func_021542CC(void *p, int a, int b)
{
    void *r7;
    int *obj;

    func_020120F4(p);
    r7 = func_020122C0(p, 0, func_02154310, 0x10);
    obj = func_020124E8(r7);
    obj[0] = a;
    obj[1] = (int)p;
    obj[3] = b;
    if (func_02026454(func_02012138(p)))
        func_02026400(func_02012138(p));
    return r7;
}
