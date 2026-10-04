/*
 * function: func_021D034C
 * address:  0x021D034C
 * packet:   pkt_ov021_021D034C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021DB8F0  0x021DB8F0  data  ov021  a4
 *   func_0207ADC4  0x0207ADC4  arm
 *   func_021AC1B8  0x021AC1B8  thumb  ov021
 *   func_02047AC8  0x02047AC8  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct V {
    u32 w[15];
} V;

extern const V data_021DB8F0;
extern void func_0207ADC4(void *a);
extern void func_021AC1B8(u32 a, V *v);
struct Arg;
extern int func_02047AC8(void *a0, struct Arg *a1);

void func_021D034C(u32 a, u8 *b)
{
    V v;

    if (b[1] == 0) {
        v = data_021DB8F0;
        func_0207ADC4(&v.w[6]);
        func_021AC1B8(a, &v);
        func_02047AC8((void *)(*(u32 *)(b + 0xc)), (struct Arg *)(&v));
    }
}
