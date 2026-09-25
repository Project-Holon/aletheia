/*
 * function: func_0215437C
 * address:  0x0215437C
 * packet:   pkt_0215437C
 * region:   ov003
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator + guard + three-field link setup.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026400  0x02026400  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_021542C0  0x021542C0  thumb  ov003
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
int func_02012138(void *p);
int func_02026454(int x);
void func_02026400(int x);
void *func_020124E8(void *p);
void func_021542C0(void);

void *func_0215437C(void *p, int a, int b)
{
    void *r7 = func_020122C0(p, 0, func_021542C0, 0x1C);
    int *obj;

    if (func_02026454(func_02012138(p)))
        func_02026400(func_02012138(p));
    obj = func_020124E8(r7);
    obj[1] = (int)p;
    obj[2] = a;
    obj[5] = b;
    return r7;
}
