/*
 * file:     unit_021CDBA8.c
 * unit:     yes
 * function: func_021CDBA8, func_021CDBB8
 * address:  0x021CDBA8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021CDC78(void);
void func_021CDBA8(void);
void func_021CDBB8(void);


/*
 * Call func_021CDC78, func_021CDBB8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CDBA8.c \
 *       --func func_021CDBA8 --addr 0x021CDBA8 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CDBA8(void)
{
    func_021CDC78();
    func_021CDBB8();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CDBB8.c \
 *       --func func_021CDBB8 --addr 0x021CDBB8 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CDBB8(void)
{
}
