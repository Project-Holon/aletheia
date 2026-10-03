/*
 * function: func_021B70D8
 * address: 0x021B70D8
 * packet: pkt_ov173_021B70D8
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_021B6FDC 0x021B6FDC thumb ov173
 *   func_021B7968 0x021B7968 thumb ov173
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32);
extern void func_021B6FDC(char *, u8, u8);
extern void func_021B7968(char *);
void func_021B70D8(char *p)
{
    u32 i;
    void *q;
    func_02043B5C(func_02045770(*(void **)(p + 0x30)), 0);
    for (i = 0; i < 4; i++)
        func_021B6FDC(p, *(u16 *)(*(char **)p + 0x16), i);
    q = *(void **)(p + 0x30);
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
    func_02041B6C(7);
    func_021B7968(p);
}
