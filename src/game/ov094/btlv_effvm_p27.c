/*
 * file:     btlv_effvm_p27.c
 * unit:     yes
 * function: func_021F8B6C, func_021F8B90
 * address:  0x021F8B6C
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
 *   func_021F89BC 0x021F89BC thumb ov094
 *   func_0204A648 0x0204A648 arm
 *   func_02021D50 0x02021D50 thumb
 */
struct S02021D50;
extern void func_021F89BC(void *);
extern void func_0204A648(void);
extern void func_02021D50(struct S02021D50 *p);
void func_021F8B6C(void);
void func_021F8B90(void);
extern char *d_0220AF20;


/*
 * Runs func_021F89BC on each of the 32 live objects at 8 of the global work block.
 */
void func_021F8B6C(void)
{
    int i;

    for (i = 0; i < 32; i++) {
        if (((void **)(d_0220AF20 + 8))[i] != 0)
            func_021F89BC(((void **)(d_0220AF20 + 8))[i]);
    }
}


/*
 * Calls func_0204A648, then func_02021D50 on the handle at 0x18c of the global work block.
 */
void func_021F8B90(void)
{
    func_0204A648();
    func_02021D50(*(void **)(d_0220AF20 + 0x18c));
}
