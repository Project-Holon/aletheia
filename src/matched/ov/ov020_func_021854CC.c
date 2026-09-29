/*
 * function: func_021854CC
 * address:  0x021854CC
 * packet:   pkt_ov020_021854CC
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B2C  0x02012B2C  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02184504  0x02184504  thumb  ov020
 *   func_02184CEC  0x02184CEC  thumb  ov020
 *   func_02185EB0  0x02185EB0  thumb  ov020
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int f[7]; } S7;

void *func_020122C0(void *p, int a, void (*cb)(void), int n);
void *func_020124E8(void *p);
void *func_020120F4(void *p);
void *func_020127A4(void *p);
void func_02012B2C(void *p, int a);
void func_02184504(void);
void func_02184CEC(void *obj, void *p);
void func_02185EB0(void *a, void *b);

void *func_021854CC(void *p, int u, int u2, const S7 *src, u16 h)
{
    void *r7 = func_020120F4(p);
    void *r0v;
    char *r4;

    func_02012B2C(func_020127A4(r7), 0);
    r0v = func_020122C0(p, 0, func_02184504, 0x9c);
    r4 = func_020124E8(r0v);
    func_02184CEC(r4, p);
    *(S7 *)(r4 + 0x10) = *src;
    *(u16 *)(r4 + 0x18) = h;
    *(int *)(r4 + 0x2c) = 0;
    *(u8 *)(r4 + 0x30) = 1;
    func_02185EB0(r7, r4 + 0x10);
    return r0v;
}
