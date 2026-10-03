/*
 * function: func_021B6E88
 * address:  0x021B6E88
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies one 8-byte entry in and steps the +4 cursor.
 *
 * symbols:
 *   func_021B6EC4  0x021B6EC4  thumb  ov172
 *   func_021B6ECC  0x021B6ECC  thumb  ov172
 *   func_02082D44  0x02082D44  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 *func_021B6EC4(void *p, int i);
extern void  func_021B6ECC(void *a, void *b);
extern void  func_02082D44(void *a, void *b, int c);

void func_021B6E88(char *p, void *q)
{
    func_02082D44(q, func_021B6EC4(p, *(u16 *)(p + 4)), 8);
    func_021B6ECC(p, p + 4);
}
