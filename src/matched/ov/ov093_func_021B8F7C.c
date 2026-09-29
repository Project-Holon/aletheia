/*
 * function: func_021B8F7C
 * address:  0x021B8F7C
 * packet:   pkt_ov093_021B8F7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B86C8  0x021B86C8  thumb  ov093
 *   func_021B8B9C  0x021B8B9C  thumb  ov093
 *   func_021B969C  0x021B969C  thumb  ov093
 *   func_021B985C  0x021B985C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021B86C8(u8 *p);
extern int func_021B8B9C(u8 *p, u32 k);
extern void func_021B969C(u8 *a, u8 *b, u32 k, int z);
extern int func_021B985C(u8 *a, u32 k);

int func_021B8F7C(u8 *p, u32 k)
{
    if (func_021B86C8(p)) {
        k = (u8)((k + 2) & 3);
        if (func_021B8B9C(p, k)) {
            func_021B969C(p + 0xc8, p, k, 0);
            return func_021B985C(p + 0xc8, k);
        }
    }
    return 0;
}
