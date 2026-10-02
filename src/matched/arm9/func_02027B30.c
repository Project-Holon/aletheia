/*
 * function: func_02027B30
 * address:  0x02027B30
 * packet:   pkt_02027A24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

struct S;

extern void func_02045798(u32 a, u32 b);
extern void func_02045374(u32 a);
extern u8   func_02045730(u32 a);
extern void func_02041B6C(u32 bit);

void func_02027B30(u32 a0, struct S *s, int mode)
{
    if (mode == 1) {
        func_02045798(a0, (u8)*(u16 *)((u8 *)s + 2));
    } else if (mode == 0) {
        func_02045798(a0, (u8)(*(u16 *)((u8 *)s + 2) + 1));
    }
    func_02045374(a0);
    func_02041B6C(func_02045730(a0));
}
