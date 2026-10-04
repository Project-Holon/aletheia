/*
 * function: func_021BB958
 * address: 0x021BB958
 * packet: pkt_ov110_021BB958
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BAC44 0x021BAC44 thumb ov110
 *   func_021BF7D4 0x021BF7D4 thumb ov110
 *   func_020457B0 0x020457B0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   func_02041B6C 0x02041B6C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021BAC44(u32 a);
extern void func_021BF7D4(u32 a, void *b);
extern void *func_020457B0(u32 size, u32 heap);
extern void *func_02045770(void *);
extern void func_02043B5C(void *, u32);
extern void func_0201DD78(int, int, int);
extern void func_0201C7A4(void *, int, int, void *, u32);
extern void func_02045808(void *);
extern void func_02045374(void *);
extern void func_02045334(void *);
extern void func_02041B6C(u32);
void func_021BB958(char *p)
{
    u32 r7 = func_021BAC44(*(u32 *)p);
    void *r4 = *(void **)(p + 0x94);
    void *r6 = func_020457B0(14, 42);
    func_021BF7D4(*(u32 *)(p + 4), r6);
    func_02043B5C(func_02045770(r4), 1);
    func_0201DD78(15, 14, 1);
    func_0201C7A4(func_02045770(r4), 0, 0, r6, r7);
    func_02045808(r6);
    func_02045374(r4);
    func_02045334(r4);
    func_02041B6C(1);
}
