/*
 * file:     unit_0217576C_p04.c
 * unit:     yes
 * function: func_02175FB8, func_02175FC8, func_02175FE4
 * address:  0x02175FB8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0217603C  0x0217603C  arm  ov009
 *   func_0217637C  0x0217637C  arm  ov009
 *   func_02177748  0x02177748  arm  ov009
 */
extern int func_02175F3C(void);
extern int func_0217603C(void);
extern unsigned char *func_0217637C(int index);
extern void func_02177748(int aid);
unsigned char func_02175FB8(void);
int func_02175FC8(void);
void func_02175FE4(void);


unsigned char func_02175FB8(void)
{
    return *(unsigned char *)(func_02175F3C() + 0x16);
}


/*
 * Cleared when the word at +0x7b0 of the module block is one.
 */
int func_02175FC8(void)
{
    return *(int *)(func_02175F3C() + 0x7b0) != 1;
}


/*
 * DWCi_ResetLastSomeDataRecvTimeByAidAll: restamps every node's transport record.
 */
void func_02175FE4(void)
{
    int i;

    for (i = 0; i < func_0217603C(); i++) {
        func_02177748(func_0217637C(i)[0x16]);
    }
}
