/*
 * file:     unit_021C3C94.c
 * unit:     yes
 * function: func_021C3C94, func_021C3CA4
 * address:  0x021C3C94
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
extern void func_021C3D58(void);
void func_021C3C94(void);
void func_021C3CA4(void);


/*
 * Call func_021C3D58, func_021C3CA4.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C3C94.c \
 *       --func func_021C3C94 --addr 0x021C3C94 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C3C94(void)
{
    func_021C3D58();
    func_021C3CA4();
}

/*
 * Empty stub: the routine carries no behaviour (see the call sites for why it exists).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C3CA4.c \
 *       --func func_021C3CA4 --addr 0x021C3CA4 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C3CA4(void)
{
}
