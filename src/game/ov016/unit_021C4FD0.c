/*
 * file:     unit_021C4FD0.c
 * unit:     yes
 * function: func_021C4FD0, func_021C4FE0
 * address:  0x021C4FD0
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021C50A0(void);
void func_021C4FD0(void);
void func_021C4FE0(void);


/*
 * Call func_021C50A0, func_021C4FE0.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C4FD0.c \
 *       --func func_021C4FD0 --addr 0x021C4FD0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C4FD0(void)
{
    func_021C50A0();
    func_021C4FE0();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C4FE0.c \
 *       --func func_021C4FE0 --addr 0x021C4FE0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C4FE0(void)
{
}
