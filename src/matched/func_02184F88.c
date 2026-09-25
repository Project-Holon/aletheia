/*
 * function: func_02184F88
 * address:  0x02184F88
 * packet:   pkt_02184F88
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Allocator + base init, copies a seven-word record fetched through the node's
 * fourth word, then fills status fields.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02012894  0x02012894  thumb
 *   func_02184A14  0x02184A14  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void *func_02012894(int x);
void func_02184A14(void);
void func_02184CEC(void *obj, void *p);

void *func_02184F88(void *p)
{
    void *r0v = func_020122C0(p, 0, func_02184A14, 0x9c);
    char *r4 = func_020124E8(r0v);
    S7 *src;

    func_02184CEC(r4, p);
    src = func_02012894(*(int *)(r4 + 4));
    *(S7 *)(r4 + 0x10) = *src;
    *(int *)(r4 + 0x10) = 1;
    *(u16 *)(r4 + 0x18) = 2;
    *(int *)(r4 + 0x2c) = 0;
    return r0v;
}
