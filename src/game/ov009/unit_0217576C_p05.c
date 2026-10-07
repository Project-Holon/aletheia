/*
 * file:     unit_0217576C_p05.c
 * unit:     yes
 * function: func_0217601C, func_0217603C
 * address:  0x0217601C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern int func_02175F3C(void);
extern void func_02082BCC(void *p, int v, int n);
void func_0217601C(void);
int func_0217603C(void);


/*
 * Clears the block 0x50 bytes into the module block.
 */
void func_0217601C(void)
{
    func_02082BCC((void *)(func_02175F3C() + 0x50), 0, 0x504);
}


/*
 * Word at +0x50 of the block func_02175F3C returns.
 */
int func_0217603C(void)
{
    return *(int *)(func_02175F3C() + 0x50);
}
