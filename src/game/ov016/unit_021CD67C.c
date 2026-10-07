/*
 * file:     unit_021CD67C.c
 * unit:     yes
 * function: func_021CD67C, func_021CD68C
 * address:  0x021CD67C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021CD79C(void);
void func_021CD67C(void);
void func_021CD68C(void);


/*
 * Call func_021CD79C, func_021CD68C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CD67C.c \
 *       --func func_021CD67C --addr 0x021CD67C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CD67C(void)
{
    func_021CD79C();
    func_021CD68C();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CD68C.c \
 *       --func func_021CD68C --addr 0x021CD68C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CD68C(void)
{
}
