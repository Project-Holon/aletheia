/*
 * file:     btlv_effvm_p07.c
 * unit:     yes
 * function: func_021F7BEC, func_021F7C0C
 * address:  0x021F7BEC
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
 *   func_021F97E4 0x021F97E4 thumb ov094
 *   func_021F9814 0x021F9814 thumb ov094
 */
extern void func_021F97E4(void *);
extern void func_021F9814(void *);
void func_021F7BEC(void);
void func_021F7C0C(void);
extern char *d_0220AF20;


/*
 * Calls func_021F97E4 on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 0.
 */
void func_021F7BEC(void)
{
    func_021F97E4(*(void **)(d_0220AF20 + 0x188));
    *(int *)(d_0220AF20 + 0x1e8) = 0;
}


/*
 * Calls func_021F9814 on the handle at 0x188 of the global work block, then sets the word at 0x1e8 to 1.
 */
void func_021F7C0C(void)
{
    func_021F9814(*(void **)(d_0220AF20 + 0x188));
    *(int *)(d_0220AF20 + 0x1e8) = 1;
}
