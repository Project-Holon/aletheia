/*
 * function: func_021B9C8C
 * address:  0x021B9C8C
 * packet:   pkt_ov218_021B9C8C
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_021BA4FC 0x021BA4FC thumb ov218
 *   func_021B9398 0x021B9398 thumb ov067
 *   func_021B9394 0x021B9394 thumb ov067
 *   func_021B9C80 0x021B9C80 thumb ov218
 *   func_021B9AE4 0x021B9AE4 thumb ov218
 *   func_021BA75C 0x021BA75C thumb ov218
 *   func_021BA6E8 0x021BA6E8 thumb ov218
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021BA4FC(u8 *p);
extern u32 func_021B9398(u8 *p, int index);
extern u32 func_021B9394(u8 *p);
extern void *func_021B9C80(u8 *p);
extern void func_021B9AE4(u8 *p, u32 a, u32 b, void *c, u32 d);
extern int func_021BA75C(u8 *p, int v);
extern void func_021BA6E8(u8 *p, int sel, u32 y);
void func_021B9C8C(u8 *p, u32 a, u32 b, u8 *c, u32 d)
{
    u32 t;
    func_021BA4FC(p);
    func_021B9398(*(u8 **)(p + 0x2C), a);
    t = func_021B9394(*(u8 **)(p + 0x2C));
    func_021B9AE4(*(u8 **)(p + 0x28), b, t, func_021B9C80(*(u8 **)(p + 0x28)), a);
    if (func_021BA75C(p, a)) {
        func_021BA6E8(p, d, (u32)(c + 0x14));
    }
}
