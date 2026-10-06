/*
 * function: func_020053EC
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
 *   g_020A9E80     0x020A9E80  data
 *   func_020351D0  0x020351D0  arm
 *   func_02005420  0x02005420  arm
 *   func_02005428  0x02005428  arm
 *
 * Three guards and then a hardware write: 0x04000204 bit 15 is the ARM9
 * "card slot 1 power" style latch and the constant is materialised as
 * `lsrs r0, r2, #0xb` off the register address already in r2 (0x04000204 >>
 * 11 == 0x8000) rather than as a movs pair.  g_020A9E80 is the same global
 * func_02005440 (src/pending/func_02005440.c) sets to 1 one function later,
 * so the flag this reads is set by its neighbour.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020053EC.c \
 *       --func func_020053EC --addr 0x020053EC --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 g_020A9E80;
extern int func_020351D0(u32 mode);
extern int func_02005420(void);
extern int func_02005428(void);

void func_020053EC(void)
{
    if (g_020A9E80 == 0) {
        return;
    }
    if (func_020351D0(2) != 0) {
        return;
    }
    if (func_02005420() != 0) {
        return;
    }
    *(volatile u16 *)0x04000204 |= 0x8000;
    func_02005428();
}
