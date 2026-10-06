/*
 * function: func_021CC544
 * address:  0x021CC544
 * packet:   pkt_ov021_021CC544
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task step: hands the field's current map object to ov010 func_0215897C with a lookup through func_0216C204.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_0216C204  0x0216C204  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *p);
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
typedef unsigned char  u8;
extern int func_0216C204(void *a, u8 *b);
extern void func_0215897C(void *a, void *b);

int func_021CC544(void *task, void *p)
{
    void *a = func_0215A5F4(p);
    void *b = func_0215A5DC(p);
    func_0215897C(a, (void *)func_0216C204((void *)b, (u8 *)func_0201210C(b)));
    return 1;
}
