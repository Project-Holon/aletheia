/*
 * function: func_021D8520
 * address: 0x021D8520
 * packet: pkt_ov120_021D8520
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 0x021D858E.
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned short u16;
extern void func_02045CAC(void *, u16, int);
extern void *func_020450F0(int, int, int, int, int, int, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
typedef signed short   s16;
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D8520(char *p, u16 n)
{
    void *q;
    func_02045CAC(*(void **)(p + 12), n, *(int *)(p + 24));
    if (!*(void **)(p + 0x68)) *(void **)(p + 0x68) = func_020450F0(1, 0, 0, 14, 2, 11, 1);
    q = *(void **)(p + 0x68);
    func_02043B5C(func_02045770(q), 0);
    func_0201DD78(15, 2, 0);
    func_0201C7A4(func_02045770(q), 2, 2, (void *)(*(int *)(p + 24)), (void *)(*(int *)(p + 20)));
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(1);
}
