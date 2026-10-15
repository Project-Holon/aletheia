/*
 * function: GFL_USE_PollPowerExit
 * address:  0x020053EC
 * packet:   pkt_02005328
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02005420 and 02005428 - both are 8-byte ARM `ldr pc, [pc, #-4]`
 *           stubs whose pointer words (0x027315D0, 0x027314F0) lie outside
 *           every region of layout/layout.json, so `veneer_at()`'s
 *           `names_known_code()` refuses them and the `veneer` class cannot
 *           attest either call.  All 44 concrete bytes are right.
 *
 * symbols:
 *   _PreExitState     0x020A9E80  data
 *   UI_TestFlags39Global  0x020351D0  arm
 *   func_02005420  0x02005420  arm
 *   func_02005428  0x02005428  arm
 *
 * Three guards and then a hardware write: 0x04000204 bit 15 is the ARM9
 * "card slot 1 power" style latch and the constant is materialised as
 * `lsrs r0, r2, #0xb` off the register address already in r2 (0x04000204 >>
 * 11 == 0x8000) rather than as a movs pair.  _PreExitState is the same global
 * GFL_USE_OnPreExit (src/pending/GFL_USE_OnPreExit.c) sets to 1 one function later,
 * so the flag this reads is set by its neighbour.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GFL_USE_PollPowerExit.c \
 *       --func GFL_USE_PollPowerExit --addr 0x020053EC --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 _PreExitState;
extern int UI_TestFlags39Global(u32 mode);
extern int func_02005420(void);
extern int func_02005428(void);

void GFL_USE_PollPowerExit(void)
{
    if (_PreExitState == 0) {
        return;
    }
    if (UI_TestFlags39Global(2) != 0) {
        return;
    }
    if (func_02005420() != 0) {
        return;
    }
    *(volatile u16 *)0x04000204 |= 0x8000;
    func_02005428();
}
