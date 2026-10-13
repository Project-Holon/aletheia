/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02006CAC
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: PM_VOICE_GetPerapVoiceSave
 *
 * symbols:
 *   func_020070A4  0x020070A4  thumb
 *   func_02007B44  0x02007B44  thumb
 *
 * One function, sixteen bytes, alone in its own range because both of its
 * neighbours are held out by the honesty rule and a matched range has to be
 * contiguous.  The near miss census for the two, 0x02006C2C before it and
 * 0x02006CBC after it, is in the header of src/matched/unit_02006B20.c.
 *
 * func_020070A4 takes no argument: it is a lazily initialised singleton
 * getter and never reads r0.  The incoming r0 here is only saved into r4 and
 * used as the destination of the store, so the call is nested rather than
 * sequenced, and the result of func_02007B44 is written through the argument.
 * func_02007B44 is `SAVE_CONTROL_GetBlock(sys, 0x24)` in src/matched/unit_02007AC8.c,
 * the save block lookup, so what this writes is a pointer to save block 0x24.
 */

struct Sub02007084Ctrl;
struct Sub02007AC8Entry;
extern struct Sub02007084Ctrl *func_020070A4(void);
extern struct Sub02007AC8Entry *func_02007B44(void *sys);

void PM_VOICE_GetPerapVoiceSave(void **out)
{
    *out = func_02007B44(func_020070A4());
}
