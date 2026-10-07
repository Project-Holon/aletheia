/*
 * file:     unit_021C3280.c
 * unit:     yes
 * function: func_021C3280, func_021C3290, func_021C3294
 * address:  0x021C3280
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void func_021C3280(void);
void func_021C3290(void);
void func_021C3294(void);


void func_021C3280(void)
{
    func_021C3290();
    func_021C3294();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C3290.c \
 *       --func func_021C3290 --addr 0x021C3290 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C3290(void)
{
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C3294.c \
 *       --func func_021C3294 --addr 0x021C3294 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C3294(void)
{
}
