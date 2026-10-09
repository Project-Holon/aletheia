/*
 * function: func_027309A8
 * address:  0x027309A8
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_027309FC 0x027309FC arm twl
 *   func_02731234 0x02731234 arm twl
 *   func_02731254 0x02731254 arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_027309FC(u32 ch, int start, int n, u32 val);
extern u32 func_02731234(u16 *p);
extern void func_02731254(u32 id, u32 irq);

u32 func_027309A8(u32 ch, int start, int n, u32 val)
{
    u16 sv;
    u32 irq, r;

    irq = func_02731234(&sv);
    r = func_027309FC(ch, start, n, val);
    func_02731254(sv, irq);
    return r;
}
