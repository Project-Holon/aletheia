/*
 * function: func_021C9208
 * address:  0x021C9208
 * packet:   pkt_ov021_021C9208
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 *   d_021DAC08     0x021DAC08  data  a4
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct T { int w[15]; } T;
typedef struct V3 { int v[3]; } V3;

extern T d_021DAC08;

extern void func_0207ADC4(int *m);
extern void func_021AC1B8(u32 a, T *t);
struct Arg;
extern int func_02047AC8(void *a0, struct Arg *a1);

void func_021C9208(u32 a, u32 *b)
{
    T t = d_021DAC08;

    func_0207ADC4(&t.w[6]);
    func_021AC1B8(a, &t);
    func_02047AC8((void *)b[6], (struct Arg *)(&t));
    *(V3 *)&t = *(V3 *)(b + 10);
    func_02047AC8((void *)b[13], (struct Arg *)(&t));
}
