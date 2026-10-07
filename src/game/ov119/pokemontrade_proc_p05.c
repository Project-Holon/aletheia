/*
 * file:     pokemontrade_proc_p05.c
 * unit:     yes
 * function: func_021D90AC, func_021D90C0
 * address:  0x021D90AC
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D9038  0x021D9038  thumb  ov119
 */
extern int func_021D9038(int a, int b, int c, int d, int e, int f);
int func_021D90AC(int a, int b, int c, int d, int e);
int func_021D90C0(int a, int b, int c, int d, int e);


/*
 * DWCi_EncSessionGetAsync: sixth argument is zero.
 */
int func_021D90AC(int a, int b, int c, int d, int e)
{
    return func_021D9038(a, b, c, d, e, 0);
}


int func_021D90C0(int a, int b, int c, int d, int e)
{
    return func_021D9038(a, b, c, d, e, 1);
}
