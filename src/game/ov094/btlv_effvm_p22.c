/*
 * file:     btlv_effvm_p22.c
 * unit:     yes
 * function: func_021F8730, func_021F8740, func_021F8754, func_021F8764
 * address:  0x021F8730
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 */
int func_021F8730(void);
unsigned short func_021F8740(int a);
int func_021F8754(void);
int func_021F8764(void);
extern char *d_0220AF20;


/*
 * Returns the word at 0x1dc of the global work block.
 */
int func_021F8730(void)
{
    return *(int *)(d_0220AF20 + 0x1dc);
}


/*
 * Returns halfword a of the table at 0x1d4 of the global work block.
 */
unsigned short func_021F8740(int a)
{
    return ((unsigned short *)(d_0220AF20 + 0x1d4))[a];
}


/*
 * Returns the word at 0x1e4 of the global work block.
 */
int func_021F8754(void)
{
    return *(int *)(d_0220AF20 + 0x1e4);
}


/*
 * Returns the word at 0x1e0 of the global work block.
 */
int func_021F8764(void)
{
    return *(int *)(d_0220AF20 + 0x1e0);
}
