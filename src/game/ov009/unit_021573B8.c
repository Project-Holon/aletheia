/*
 * file:     unit_021573B8.c
 * unit:     yes
 * function: func_021573B8, func_021573BC
 * address:  0x021573B8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void func_021573B8(void);
int func_021573BC(void);

/*
 * network.o static leaf: the empty callback CPS_Startup installs by default.
 *   Placed from the vendor symtab; entry seeded in layout/function_starts.txt
 *   (pool word at ov009 0x0215759C in CPS_Startup).
 *
 * sdk:      empty_func (libcps.TWL.HYB.a network.o, static)
 */
void func_021573B8(void)
{
}

/*
 * network.o static leaf: the default link-state callback CPS_Startup installs,
 *   reporting the link as up. Placed from the vendor symtab; entry seeded in
 *   layout/function_starts.txt (pool word at ov009 0x021575A4 in CPS_Startup).
 *
 * sdk:      default_link_is_on (libcps.TWL.HYB.a network.o, static)
 */
int func_021573BC(void)
{
    return 1;
}
