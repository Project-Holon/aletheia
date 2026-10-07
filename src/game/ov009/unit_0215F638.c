/*
 * file:     unit_0215F638.c
 * unit:     yes
 * function: func_0215F638, func_0215F644
 * address:  0x0215F638
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern int func_0215E6B8(int s);
extern int func_0215E84C(int s);
int func_0215F638(int s, int how);
int func_0215F644(int s);


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * This is SOC_Shutdown(s, how): SOCL_Shutdown reads only s, but every
 * caller sets how (mov r1, #2 in ov114 and ov125), so it stays.
 */
int func_0215F638(int s, int how)
{
    return func_0215E6B8(s);
}


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
int func_0215F644(int s)
{
    return func_0215E84C(s);
}
