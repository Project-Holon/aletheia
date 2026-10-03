/*
 * function: func_021B8350
 * address:  0x021B8350
 * packet:   pkt_ov071_021B8350
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F554  0x0201F554  thumb
 *   func_0201F548  0x0201F548  thumb
 *   func_020215EC  0x020215EC  thumb
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045374  0x02045374  arm
 *   func_0201F73C  0x0201F73C  thumb
 */

typedef struct {
    char pad[0x3c];
    int f3c;
} W;

typedef unsigned int   u32;
typedef unsigned char  u8;
void func_021B8350(W *w, int *b)
{
    extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
    extern u8 func_0201F548(int i);
    extern void func_020215EC(int, int, int, int, int, int, int, int);
    extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
    extern int func_02045770(int);
    extern void func_02043B5C(int, int);
    extern void func_02045374(int);
    extern void func_0201F73C(int, int, int, int);

    func_0201F554(5, 1, 0, 0x61);
    func_020215EC(*b, 5, func_0201F548(0), 0x61, 1, 0x20, 0xb0, 0);
    w->f3c = func_020450F0(5, 1, 0x13, 0x1e, 4, 0xd, 1);
    func_02043B5C(func_02045770(w->f3c), 0xff);
    func_02045374(w->f3c);
    func_0201F73C(w->f3c, 0, 1, 0xb);
}
