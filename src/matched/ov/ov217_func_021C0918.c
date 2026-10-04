/*
 * function: func_021C0918
 * address:  0x021C0918
 * packet:   pkt_ov217_021C0918
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026498  0x02026498  thumb
 *   func_021BF734  0x021BF734  thumb  ov217
 *
 * Opens the +0x10 record (func_02012138 on the result of func_021BF734),
 * tags it with 1, and releases it when func_02026454 reports state 2.
 * Closed by the generator's duplicate guard statement (O89).
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Ctx;
extern u32 func_02012138(const struct Ctx *);
struct Comm;
extern void func_02026400(struct Comm *p);
extern u32 func_02026454(void *obj);
extern void func_02026498(void *obj, u32 flag);
extern u32 func_021BF734(u8 *);
void func_021C0918(u8 *a0)
{
    u32 v1 = func_02012138((const struct Ctx *)func_021BF734(a0));
    func_02026498((void *)v1, 1);
    if (func_02026454((void *)v1) == 2) {
    func_02026400((struct Comm *)v1);
    }
}
