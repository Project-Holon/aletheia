/*
 * function: func_02730B04
 * address:  0x02730B04
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02730B48 0x02730B48 arm twl
 *   func_02731234 0x02731234 arm twl
 *   func_02731254 0x02731254 arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02730B48(u32 ch, u32 val);
extern u32 func_02731234(u16 *p);
extern void func_02731254(u32 id, u32 irq);

u32 func_02730B04(u32 ch, u32 val)
{
    u16 sv;
    u32 irq, r;

    irq = func_02731234(&sv);
    r = func_02730B48(ch, val);
    func_02731254(sv, irq);
    return r;
}
