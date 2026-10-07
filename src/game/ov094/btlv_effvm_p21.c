/*
 * file:     btlv_effvm_p21.c
 * unit:     yes
 * function: func_021F86F0, func_021F8700
 * address:  0x021F86F0
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
int func_021F86F0(void);
int func_021F8700(void);
extern char *d_0220AF20;


/*
 * Returns the word at 0x1a0 of the global work block.
 */
int func_021F86F0(void)
{
    return *(int *)(d_0220AF20 + 0x1a0);
}


/*
 * Returns the word at 0x1b4 of the global work block.
 */
int func_021F8700(void)
{
    return *(int *)(d_0220AF20 + 0x1b4);
}
