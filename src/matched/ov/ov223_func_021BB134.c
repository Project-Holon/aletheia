/*
 * function: func_021BB134
 * address: 0x021BB134
 * packet: pkt_ov223_021BB134
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing B18A halfword is zero alignment padding.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 */
typedef unsigned char u8;
struct Descriptor;
struct CharBuf;
struct Cfg;
struct Rec3;
struct U16Vec;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *, u8);
extern void func_02045334(struct Descriptor *);
extern void func_02045374(struct Cfg *);
extern u8 func_02045730(struct Descriptor *);
extern void func_02041B6C(unsigned);
extern void func_0201CE48(struct Rec3 *);
extern void func_02045808(struct U16Vec *);
void func_021BB134(char *p)
{
    struct Descriptor *d;
    func_02043B5C(func_02045770(*(struct Descriptor **)(p + 0x23C)), 0);
    d = *(struct Descriptor **)(p + 0x23C);
    func_02045334(d);
    func_02045374((struct Cfg *)d);
    func_02041B6C(func_02045730(d));
    if (*(struct Rec3 **)(p + 0x250))
        func_0201CE48(*(struct Rec3 **)(p + 0x250));
    *(int *)(p + 0x250) = 0;
    if (*(struct U16Vec **)(p + 0x258))
        func_02045808(*(struct U16Vec **)(p + 0x258));
    *(int *)(p + 0x258) = 0;
}
