/*
 * function: func_02731210
 * address:  0x02731210
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02084CEC 0x02084CEC arm
 *   func_02084F10 0x02084F10 arm
 */
typedef unsigned int u32;

extern void func_02084CEC(u32, void *, void *);
extern void func_02084F10(u32);

void func_02731210(u32 id)
{
    func_02084CEC(id, (void *)0x02FFF680, 0);
    func_02084F10(id);
}
