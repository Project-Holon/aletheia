/*
 * function: func_02051B0C
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
 *   func_0207E1F8  0x0207E1F8  arm
 *   func_0207E24C  0x0207E24C  arm
 *   func_0207E2A0  0x0207E2A0  arm
 *   func_0207E330  0x0207E330  arm
 *   func_0207E22C  0x0207E22C  arm
 *   func_0207E280  0x0207E280  arm
 *   func_0207E2F0  0x0207E2F0  arm
 *   func_0207E388  0x0207E388  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02051B0C.c \
 *       --func func_02051B0C --addr 0x02051B0C --cc 1.1p1 --arm
 */

extern void *func_0207E1F8(void);
extern void *func_0207E24C(void);
extern void *func_0207E2A0(void);
extern void *func_0207E330(void);
extern int func_0207E22C(void);
extern int func_0207E280(void);
extern void *func_0207E2F0(void);
extern void *func_0207E388(void);

int func_02051B0C(int i)
{
    switch (i) {
    case 0: return (int)func_0207E1F8();
    case 1: return (int)func_0207E24C();
    case 2: return (int)func_0207E2A0();
    case 3: return (int)func_0207E330();
    case 4: return func_0207E22C();
    case 5: return func_0207E280();
    case 6: return (int)func_0207E2F0();
    case 7: return (int)func_0207E388();
    }
    return 0;
}
