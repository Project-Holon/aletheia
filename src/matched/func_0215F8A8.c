/*
 * function: func_0215F8A8
 * address:  0x0215F8A8
 * packet:   pkt_0215F8A8
 * region:   ov010
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator with callback, three sub-init calls over the new node.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012944  0x02012944  thumb
 *   func_0215E580  0x0215E580  thumb  ov010
 *   func_0215F734  0x0215F734  thumb  ov010
 *   func_0215F900  0x0215F900  thumb  ov010
 *   func_0215F920  0x0215F920  thumb  ov010
 *   func_0215F948  0x0215F948  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
int func_020120F4(void *p);
int func_02012944(int x);
void func_0215E580(int x);
void func_0215F734(void);
void func_0215F900(void *obj);
void func_0215F920(void *obj);
void func_0215F948(void *obj);

void *func_0215F8A8(void *p, int a1)
{
    int r7 = func_020120F4(p);
    void *r0v = func_020122C0(p, 0, func_0215F734, 0x7C);
    char *r4 = func_020124E8(r0v);

    *(int *)r4 = (int)p;
    *(int *)(r4 + 4) = r7;
    *(int *)(r4 + 8) = a1;
    *(int *)(r4 + 0x10) = func_02012944(r7);
    *(int *)(r4 + 0x78) = 0;
    *(int *)(r4 + 0x14) = (int)p;
    *(int *)(r4 + 0x18) = a1;
    func_0215E580(r7);
    func_0215F900(r4);
    func_0215F920(r4);
    func_0215F948(r4);
    return r0v;
}
