/*
 * function: func_02189734
 * address:  0x02189734
 * packet:   pkt_02189734
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02026454  0x02026454  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02026400  0x02026400  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Comm;
extern void func_02026400(struct Comm *p);
extern u32 func_02026454(u32, u32, u32, u32);
extern u32 func_02026460(void *obj);

int func_02189734(u32 a, u32 b, u32 c, u32 d)
{
if (func_02026454(a, b, c, d) == 0) {
    return 1;
}
if (func_02026460((void *)a) == 0) {
    func_02026400((struct Comm *)a);
}
return 0;
}

