/*
 * file:     btl_server_p91.c
 * unit:     yes
 * function: func_021C82B8, func_021C82C4
 * address:  0x021C82B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B911C  0x021B911C  thumb  ov093
 *   func_06898CF4  0x06898CF4  thumb  ov095
 */
void func_021B911C(int);
int func_06898CF4(int a, int b);
void func_021C82B8(int *p);
int func_021C82C4(int a, int b, int c);


void func_021C82B8(int *p)
{
    func_021B911C(p[1]);
}


int func_021C82C4(int a, int b, int c)
{
    (void)a;
    return func_06898CF4(b, c);
}
