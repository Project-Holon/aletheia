/*
 * function: func_02731254
 * address:  0x02731254
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0208799C 0x0208799C arm
 *   func_02731210 0x02731210 arm twl
 */
typedef unsigned int u32;

extern void func_0208799C(u32);
extern void func_02731210(u32 id);

void func_02731254(u32 id, u32 irq)
{
    func_02731210(id);
    func_0208799C(irq);
}
