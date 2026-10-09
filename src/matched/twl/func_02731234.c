/*
 * function: func_02731234
 * address:  0x02731234
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988 0x02087988 arm
 *   func_027311E8 0x027311E8 arm twl
 */
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02087988(void);
extern void func_027311E8(u16 *p);

u32 func_02731234(u16 *p)
{
    u32 irq = func_02087988();
    func_027311E8(p);
    return irq;
}
