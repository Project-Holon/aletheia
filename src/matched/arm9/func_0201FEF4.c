/*
 * function: func_0201FEF4
 * address:  0x0201FEF4
 * packet:   pkt_0201F93C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0201C6EC(u32 p);
extern void func_0201C4C0(u32 p);
extern void func_020307B0(void *ptr);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_0201D83C(void *ptr);
extern void func_0201F868(void *p);
struct Descriptor;
extern void func_020452E8(struct Descriptor *d);
extern void func_0201F9E8(u8 *o, u8 *out);

void func_0201FEF4(u8 *o)
{
    func_0201C6EC(*(u32 *)(o + 0x18));
    func_0201C4C0(*(u32 *)(o + 0x18));
    func_020307B0(*(void **)(o + 0x14));
    func_0201F7A8(*(void **)(o + 4), 0);
    func_0201D83C(*(void **)(o + 0x1c));
    func_0201F868(*(void **)o);
    func_020452E8(*(void **)(o + 4));
    func_0201F9E8(o, 0);
}
