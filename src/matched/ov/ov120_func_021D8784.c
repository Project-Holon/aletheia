/*
 * function: func_021D8784
 * address: 0x021D8784
 * packet: pkt_ov120_021D8784
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 */
typedef unsigned short u16;
extern void func_0201F02C(void *, int, int);
extern void func_02045CAC(void *, u16, int);
extern void func_0201F250(void *, int, int);
extern void *func_020450F0(int, int, int, int, int, int, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern void func_0201C7A4(void *, int, int, int, int);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
void func_021D8784(char *p, int n)
{
    void *q;
    func_0201F02C(*(void **)(p + 16), 0, n);
    func_02045CAC(*(void **)(p + 12), 37, *(int *)(p + 32));
    func_0201F250(*(void **)(p + 16), *(int *)(p + 24), *(int *)(p + 32));
    if (!*(void **)(p + 0x98)) *(void **)(p + 0x98) = func_020450F0(1, 11, 10, 10, 3, 11, 1);
    q = *(void **)(p + 0x98);
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(1, 2, 0);
    func_0201C7A4(func_02045770(q), 0, 0, *(int *)(p + 24), *(int *)(p + 20));
    func_02045334(q);
    func_02045374(q);
}
