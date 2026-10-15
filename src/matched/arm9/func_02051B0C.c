/*
 * function: BUTTON_MAN_CallHandlerById
 * address:  0x02051B0C
 * packet:   pkt_02051A54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Eight-way dispatch on a button-man handler id: each of the eight ids tail
 * calls its own handler and returns that handler's value, and any id above 7
 * falls out of the switch to `return 0;`.  That trailing `return 0;` is what
 * the image has at +0x7C (`mov r0, #0; pop {r3, pc}`) and it is also the
 * addls-skipped target at +0x0C, so the `switch` has no `default:` label at
 * all - writing the arms as bare calls (or with `break`) instead of
 * `return f();` loses those eight bytes and the arms' `pop {r3, pc}` with
 * them.
 *
 * Addresses are Black-image addresses.
 *
 * symbols:
 *   G2_GetBG0CharPtr  0x0207E1F8  arm
 *   G2_GetBG1CharPtr  0x0207E24C  arm
 *   G2_GetBG2CharPtr  0x0207E2A0  arm
 *   G2_GetBG3CharPtr  0x0207E330  arm
 *   func_0207E22C  0x0207E22C  arm
 *   func_0207E280  0x0207E280  arm
 *   G2S_GetBG2CharPtr  0x0207E2F0  arm
 *   G2S_GetBG3CharPtr  0x0207E388  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BUTTON_MAN_CallHandlerById.c \
 *       --func BUTTON_MAN_CallHandlerById --addr 0x02051B0C --cc 1.1p1 --arm
 */

extern void *G2_GetBG0CharPtr(void);
extern void *G2_GetBG1CharPtr(void);
extern void *G2_GetBG2CharPtr(void);
extern void *G2_GetBG3CharPtr(void);
extern int func_0207E22C(void);
extern int func_0207E280(void);
extern void *G2S_GetBG2CharPtr(void);
extern void *G2S_GetBG3CharPtr(void);

int BUTTON_MAN_CallHandlerById(int i)
{
    switch (i) {
    case 0: return (int)G2_GetBG0CharPtr();
    case 1: return (int)G2_GetBG1CharPtr();
    case 2: return (int)G2_GetBG2CharPtr();
    case 3: return (int)G2_GetBG3CharPtr();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (int)G2S_GetBG2CharPtr();
    case 7: return (int)G2S_GetBG3CharPtr();
    }
    return 0;
}
