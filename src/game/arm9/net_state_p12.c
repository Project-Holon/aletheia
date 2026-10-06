/*
 * file:     net_state_p12.c
 * unit:     yes
 * function: func_02037154, func_02037174, func_02037190
 * address:  0x02037154
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02036CA8  0x02036CA8  arm
 *   g_021469C8     0x021469C8  data
 */
struct Icon;
typedef unsigned int u32;

typedef unsigned char u8;

extern void func_02036CA8(struct Icon *c);
void func_02037154(void);
void func_02037174(void);
void func_02037190(void);
extern u32  g_021469C8[];


/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * `bl` to 0x02036CA8, which has no outside witness.  0x02036CA8 carries no
 * `func_` label in the listing, so the `label` class cannot reach it, and the
 * only branch to it anywhere in the image is the one inside this function, so
 * there is no second caller to attest it either.  It closes the day
 * 0x02036CA8 is matched itself (its manifest entry would then be the witness)
 * or a second caller turns up.
 *
 * Flush hook: does nothing while the handler in the second word of the global
 * at 0x021469C8 is unarmed, otherwise hands it to func_02036CA8.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02037154.c \
 *       --func func_02037154 --addr 0x02037154 --cc 1.1p1 --arm
 */
void func_02037154(void)
{
    if (g_021469C8[1] == 0)
        return;
    func_02036CA8((struct Icon *)g_021469C8[1]);
}


/*
 * Sets the flag byte at +0x0F of the armed handler, and does nothing at all
 * when the handler is not armed - the `movne`/`strbne` pair is the whole body.
 * src/matched/func_02037190.c is the same function clearing the same byte.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037174.c \
 *       --func func_02037174 --addr 0x02037174 --cc 1.1p1 --arm
 */
void func_02037174(void)
{
    u8 *q;

    q = (u8 *)g_021469C8[1];
    if (q != 0)
        q[0x0F] = 1;
}


/*
 * Clears the flag byte at +0x0F of the armed handler; the only difference from
 * src/matched/func_02037174.c is the `movne r0, #0` instead of `#1`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037190.c \
 *       --func func_02037190 --addr 0x02037190 --cc 1.1p1 --arm
 */
void func_02037190(void)
{
    u8 *q;

    q = (u8 *)g_021469C8[1];
    if (q != 0)
        q[0x0F] = 0;
}
