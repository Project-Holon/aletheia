/*
 * file:     unit_021C7A18.c
 * unit:     yes
 * function: func_021C7A18, func_021C7A24
 * address:  0x021C7A18
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned int u32;

extern int func_0209477C(const u8 *s);
extern void func_020949F4(void);
u32 func_021C7A18(const u8 *a0);
void func_021C7A24(void);


/*
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 */
u32 func_021C7A18(const u8 *a0)
{
    return func_0209477C(a0);
}


void func_021C7A24(void)
{
    func_020949F4();
}
