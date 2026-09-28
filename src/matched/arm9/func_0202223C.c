/*
 * unit:     no
 * address:  0x0202223C
 * packet:   pkt_02022174
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0202223C
 *
 * symbols:
 *   g_021468E4     0x021468E4  data
 *   func_020222CC  0x020222CC  thumb
 *
 * Maps two sentinel colour values (0xFFFF, "read back the last value
 * written"; 0x7FFF, "white") to two hardware-register-friendly constants
 * and forwards to func_020222CC, which selects one of two hardware
 * addresses from its first argument and ignores the colour entirely
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-
 * leftovers.md; func_020222CC's own file spells this out).
 *
 * The sentinel readback is `g_021468E4.f10`, a halfword sixteen bytes into
 * a fixed object.  Writing it as `*(u16 *)(0x021468E4 + 0x10)` folds the
 * base and the offset into a single pool word (a plain integer constant
 * has no reason not to), which does not reproduce the original's separate
 * `ldr r1, [pc]; ldrh r1, [r1, #0x10]`.  Declaring the object as an extern
 * struct and taking a real relocation on its base keeps the offset in the
 * instruction encoding instead, matching
 * docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-
 * the-load-reach.md.  The base address is attested by ten other literal
 * pools in the image.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202223C.c \
 *       --func func_0202223C --addr 0x0202223C --cc 1.1p1 --thumb
 */

typedef unsigned int   u32;
typedef unsigned short u16;
typedef unsigned char  u8;

extern void func_020222CC(u32 a, u32 color);

struct G {
    u8  pad[0x10];
    u16 f10;
};
extern struct G g_021468E4;

void func_0202223C(u32 a, u32 color)
{
    if (color == 0xFFFF) {
        color = g_021468E4.f10;
    }
    if (color == 0x7FFF) {
        color = 0x10;
    } else {
        color = ~(u32)0xF;
    }
    func_020222CC(a, color);
}
