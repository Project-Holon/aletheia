/*
 * function: func_021D8484
 * address: 0x021D8484
 * packet: pkt_ov120_021D8484
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021D8B20 0x021D8B20 data ov120 a4
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef struct { int a, b; } Pair;
extern const Pair d_021D8B20;
extern void *func_020450F0(int, int, int, int, int, int, int);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, int);
extern void func_0201DD78(int, int, int);
extern void func_0202DE5C(void *, int);
extern void func_0202DE64(void *, int);
extern void func_0202DC60(void *, void *, int, int, Pair *);
extern void func_02045334(void *);
extern void func_02045374(void *);
extern void func_02041B6C(int);
void func_021D8484(char *p, int n)
{
    Pair c = d_021D8B20;
    void *q;
    if (!*(void **)(p + 0x88)) *(void **)(p + 0x88) = func_020450F0(1, 1, 15, 30, 5, 11, 1);
    q = *(void **)(p + 0x88);
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(15, 2, 0);
    func_0202DE5C(*(void **)(p + 0xcc), 0);
    func_0202DE64(*(void **)(p + 0xcc), 0x3c40);
    func_0202DC60(*(void **)(p + 0xcc), q, n, 0, &c);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}
