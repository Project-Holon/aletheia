/*
 * function: func_021B010C
 * address:  0x021B010C
 * packet:   pkt_ov021_021B010C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B0084  0x021B0084  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_021B0084(void);

u32 func_021B010C(u32 a, u32 x, u32 y)
{
    u32 h;
    u32 *p;

    h = (u32)func_020122C0((void *)a, 0, func_021B0084, 0xc);
    p = func_020124E8((struct Obj *)h);
    p[0] = x;
    p[1] = y;
    return h;
}
