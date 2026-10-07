/*
 * file:     unit_021CE9B8_p01.c
 * unit:     yes
 * function: func_021CE9B8, func_021CE9D0
 * address:  0x021CE9B8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
void func_021CE9B8(void);
void func_021CE9D0(void);

/*
 * Clear the byte at +0x1e of the object behind the global pointer.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE9B8.c \
 *       --func func_021CE9B8 --addr 0x021CE9B8 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CE9B8(void)
{
    *(unsigned char *)(*(char **)0x021DE63C + 0x1e) = 0;
}

/*
 * Set the byte at +0x1e of the object behind the global pointer to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021CE9D0.c \
 *       --func func_021CE9D0 --addr 0x021CE9D0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021CE9D0(void)
{
    *(unsigned char *)(*(char **)0x021DE63C + 0x1e) = 1;
}
