/*
 * file:     btlv_effvm_p25.c
 * unit:     yes
 * function: func_021F88F4, func_021F8914
 * address:  0x021F88F4
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
 *   func_021BA1EC 0x021BA1EC thumb ov093
 *   func_021BA20C 0x021BA20C thumb ov093
 */
extern int func_021BA1EC(char **p);
extern int func_021BA20C(char **p);
int func_021F88F4(void);
int func_021F8914(void);
extern char *d_0220AF20;


/*
 * Returns func_021BA1EC of the handle at 0x1e4 of the global work block, or 0 when it is null.
 */
int func_021F88F4(void)
{
    int r = 0;
    void *h = *(void **)(d_0220AF20 + 0x1e4);
    if (h != 0)
        r = func_021BA1EC(h);
    return r;
}


/*
 * Returns func_021BA20C of the handle at 0x1e4 of the global work block, or 0 when it is null.
 */
int func_021F8914(void)
{
    int r = 0;
    void *h = *(void **)(d_0220AF20 + 0x1e4);
    if (h != 0)
        r = func_021BA20C(h);
    return r;
}
