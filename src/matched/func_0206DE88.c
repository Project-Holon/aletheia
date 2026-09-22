/*
 * function: func_0206DE88
 * address:  0x0206DE88
 * packet:   pkt_0206BEA0
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0206DB80    0x0206DB80  arm
 *   func_0207DC98    0x0207DC98  arm
 *   func_0207BDE0    0x0207BDE0  arm
 *   func_0207DCC8    0x0207DCC8  arm
 *
 * The 3D-engine reset path: drain the pending display list (func_0206DB80),
 * zero GXFIFO's control words at 0x04000440/0x04000444/0x04000454, then, if a
 * matrix block was given, spin func_0207DC98 on a 0x40-byte stack scratch
 * until it reports ready and hand the pair to func_0207BDE0; if a second block
 * was given, spin func_0207DCC8 on it; finally write 1 to 0x04000448 and 2 to
 * 0x04000440 (the store to 0x04000440 is spelled `str r0, [r1, #-8]` off the
 * 0x04000448 pool word, so the two are one base in the original too).
 *
 * PIN ../2.0/sp2, the cluster pin (docs/FRONTEND-PINS.md, and the sibling
 * src/matched/func_0206DB80.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206DE88.c \
 *       --func func_0206DE88 --addr 0x0206DE88 --cc ../2.0/sp2 --arm
 */

typedef unsigned int u32;

extern void func_0206DB80(void);
extern u32  func_0207DC98(void *p);
extern void func_0207BDE0(void *p, void *q);
extern u32  func_0207DCC8(void *p);

void func_0206DE88(void *a, void *b)
{
    u32 tmp[0x10];

    func_0206DB80();
    *(u32 *)0x04000440 = 0;
    *(u32 *)0x04000444 = 0;
    *(u32 *)0x04000454 = 0;
    if (a != 0) {
        while (func_0207DC98(tmp) != 0)
            ;
        func_0207BDE0(tmp, a);
    }
    if (b != 0) {
        while (func_0207DCC8(b) != 0)
            ;
    }
    *(u32 *)0x04000448 = 1;
    *(u32 *)0x04000440 = 2;
}
