/*
 * function: func_021CB6DC
 * address:  0x021CB6DC
 * packet:   pkt_ov021_021CB6DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task step: resolves the field's current map object and reports whether its fade has finished.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED8  0x02012ED8  thumb
 *   func_02167CB4  0x02167CB4  thumb  ov010
 * Addresses are Black-image addresses.
 */

extern void *func_0215A5F4(void *p);
extern void *func_02158F54(void *p);
struct Big;
struct Ctx;
struct Obj;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012ED8(struct Big *p);
extern int func_02167CB4(struct Obj *o);

int func_021CB6DC(void *task, void *p)
{
    if (func_02167CB4(func_02012ED8(func_020120F4(func_02158F54(func_0215A5F4(p))))) == 1)
        return 1;
    return 0;
}
