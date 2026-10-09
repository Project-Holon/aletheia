/*
 * file:     unit_021B6D8C_p04.c
 * unit:     yes
 * function: func_021B816C, func_021B8184
 * address:  0x021B816C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DCE20   0x021DCE20  data
 *   func_021DCE2C   0x021DCE2C  data  ov016
 */
int func_021B816C(int a, int b);
void func_021B8184(int a, int b);

extern int (*func_021DCE20)(int);


int func_021B816C(int a, int b)
{
    if (b > 0)
        return func_021DCE20(b);
    return 0;
}

extern void (*func_021DCE2C)(int);


/*
 * Forward b to the handler in the global function pointer at 0x021DCE2C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021B8184.c \
 *       --func func_021B8184 --addr 0x021B8184 --region ov016 --cc dsi/1.1p1 --thumb
 */
void func_021B8184(int a, int b)
{
    func_021DCE2C(b);
}
