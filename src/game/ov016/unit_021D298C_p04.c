/*
 * file:     unit_021D298C_p04.c
 * unit:     yes
 * function: func_021D2F50, func_021D2F8C
 * address:  0x021D2F50
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern int func_02090B9C(int, int);
extern int func_021D29C8(int);
extern int func_021D2A44(void);
extern int func_02090BB8(int);
int func_021D2F50(void);
int func_021D2F8C(void);


/*
 * Select port 6, start key sharing on the global object's tail, then reset on mismatch.
 * Addresses are Black-image addresses.
 */
int func_021D2F50(void)
{
    int *g = (int *)0x021DE660;

    func_021D29C8(6);
    if (func_02090B9C(g[1] + 0x1e00, 0xd) == 2)
        return 1;
    func_021D2A44();
    return 0;
}


/*
 * Query the global object's tail, then reset on anything but the ready answer.
 * Addresses are Black-image addresses.
 */
int func_021D2F8C(void)
{
    int *g = (int *)0x021DE660;

    if (func_02090BB8(g[1] + 0x1e00) == 2)
        return 1;
    func_021D2A44();
    return 0;
}
