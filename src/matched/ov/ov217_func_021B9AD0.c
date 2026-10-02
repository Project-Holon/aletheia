/*
 * function: func_021B9AD0
 * address:  0x021B9AD0
 * packet:   pkt_ov217_021B9AD0
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C09AC  0x021C09AC  thumb  ov217
 *   func_021BA4E0  0x021BA4E0  thumb  ov217
 *   func_021BA504  0x021BA504  thumb  ov217
 *   func_021BA4D0  0x021BA4D0  thumb  ov217
 *   func_021BA4CC  0x021BA4CC  thumb  ov217
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_021C09AC(void *);
extern u32 func_021BA4E0(u32);
extern void func_021BA504(u32);
extern void func_021BA4D0(u32, u32);
extern void func_021BA4CC(u32, u32);

u32 func_021B9AD0(void *self)
{
    u32 v = func_021C09AC(self);
    u32 o = func_021BA4E0(v);
    func_021BA504(o);
    func_021BA4D0(o, v);
    func_021BA4CC(o, (u32)self);
    return o;
}
