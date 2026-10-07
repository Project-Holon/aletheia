/*
 * file:     unit_021DD2D4_p02.c
 * unit:     yes
 * function: func_021DD358, func_021DD380, func_021DD3A8
 * address:  0x021DD358
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DD2D4  0x021DD2D4  arm
 */
extern void func_021DD2D4(int, int, int, int, int, int);
void func_021DD358(int a, int b, int c, int d);
void func_021DD380(int a, int b, int c, int d);
void func_021DD3A8(int a, int b, int c, int d);


/*
 * Register the 0x021DE024 callback with func_021DD2D4: forwards the four
 * incoming register arguments and appends (0, callback).
 */
void func_021DD358(int a, int b, int c, int d)
{
    func_021DD2D4(a, b, c, d, 0, 0x021DE024);
}


void func_021DD380(int a, int b, int c, int d)
{
    func_021DD2D4(a, b, c, d, 1, 0x021DE0D4);
}


/*
 * Register the 0x021DEBE0 callback with func_021DD2D4: forwards the four
 * incoming register arguments and appends (4, callback).
 */
void func_021DD3A8(int a, int b, int c, int d)
{
    func_021DD2D4(a, b, c, d, 4, 0x021DEBE0);
}
