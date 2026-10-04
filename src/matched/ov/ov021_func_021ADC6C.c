/*
 * function: func_021ADC6C
 * address:  0x021ADC6C
 * packet:   pkt_ov021_021ADC6C
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
 *   d_021D9254     0x021D9254  data  a4
 */

typedef unsigned char u8;

typedef struct T { int w[15]; } T;

extern T d_021D9254;

extern void func_0207ADC4(int *m);
extern void func_021AC1B8(int a, T *t);
struct Arg;
extern int func_02047AC8(void *a0, struct Arg *a1);

void func_021ADC6C(int a, u8 *b)
{
    T t = d_021D9254;
    int c = *(int *)(b + 8);

    if (b[3] == 0) {
        func_0207ADC4(&t.w[6]);
        func_021AC1B8(a, &t);
        func_02047AC8((void *)(*(int *)(c + b[0x1c] * 0x18 + 0x28)), (struct Arg *)(&t));
    }
}
