/*
 * file:     unit_021BA118.c
 * unit:     yes
 * function: func_021BA118, func_021BA124, func_021BA130
 * address:  0x021BA118
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

extern void func_0208CC78(void);
extern void func_0208CCFC(void);
extern void func_0208CD94(void);
void func_021BA118(void);
void func_021BA124(void);
void func_021BA130(void);


/*
 * ov114 tail-call thunk (ldr ip,pool; bx ip).
 */
void func_021BA118(void)
{
    func_0208CC78();
}


void func_021BA124(void)
{
    func_0208CCFC();
}


void func_021BA130(void)
{
    func_0208CD94();
}
