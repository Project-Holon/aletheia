/*
 * One function of a translation unit, matched as a byte range.  Written
 * from the disassembly in asm/arm9/src/000_02004000.s.
 *
 * It is recorded as a unit rather than as a single function because its
 * section is 54 bytes and the next function starts at 0x02005DE4, so the
 * extent disasm.py infers for it runs two bytes long over the linker's
 * `00 00` fill and a per-function entry would read EXACT*.  The byte range
 * comparison is over the 54 bytes the section actually occupies.
 *
 * unit:     yes
 * address:  0x02005DAC
 * packet:   pkt_02005DAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005DAC
 *
 * symbols:
 *   sub_02005924   0x02005924  thumb
 *   sub_0200590C   0x0200590C  thumb
 *   sub_02005CE0   0x02005CE0  thumb
 *   sub_02005D14   0x02005D14  thumb
 *   sub_02005F90   0x02005F90  thumb
 *   func_020755A8  0x020755A8  arm
 *
 * Two guarded steps of a wireless session teardown, each abandoning the
 * function when its predicate comes back zero, and a five argument call
 * whose fifth argument goes on the stack.
 *
 * The detail worth recording is the two -1 arguments.  The original builds
 * them as
 *
 *   movs r1, #6
 *   subs r2, r1, #7
 *   adds r3, r2, #0
 *
 * that is, it derives -1 from the 6 it has just materialised for the
 * previous argument rather than spending a `movs`/`mvns` pair on it.  That
 * is a peephole on two constants that happen to be live at the same time and
 * says nothing about the source, which is a plain call with the literals
 * written out.
 *
 * Near miss, recorded here because this function is the surviving part of
 * pkt_02005DAC.  The other five functions of the range, 0x02005DE4 through
 * 0x02005E64, were written and reproduce every concrete byte, but they cap
 * at MATCH: sub_02005DE4 calls the ARM routine at 0x02072E8C and
 * sub_02005E04 and sub_02005E30 call the one at 0x02072F5C, and those four
 * `blx` sites are the only references to either address anywhere in the
 * 3.9 MB image, overlays included.  The `label` class therefore has no
 * witness outside the compared range and the honesty rule discards the ones
 * inside it.  Nothing is wrong with the C; the evidence is absent.  See
 * "The honesty rule" in docs/MATCHING.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02005DAC.c \
 *       --func sub_02005DAC --addr 0x02005DAC --cc 1.1p1 --thumb
 */

extern int   sub_02005924(void *arg);
extern void *sub_0200590C(void);
extern int   sub_02005CE0(void *arg);
extern void  sub_02005D14(void);
extern void  sub_02005F90(void);

extern void func_020755A8(void *obj, int a, int b, int c, void *arg);

void sub_02005DAC(void *arg)
{
    sub_02005F90();
    if (sub_02005CE0(arg) == 0) {
        return;
    }
    sub_02005D14();
    if (sub_02005924(arg) == 0) {
        return;
    }
    func_020755A8(sub_0200590C(), 6, -1, -1, arg);
}
