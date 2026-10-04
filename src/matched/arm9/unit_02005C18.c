/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x02005C18
 * packet:   pkt_02005924
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02005C18
 *
 * symbols:
 *   sub_02005C18_State  0x020AA260  data
 *   func_02074758       0x02074758  arm
 *
 * Sixteen bytes with no prologue that disasm.py does not label, because a
 * tail call saves nothing and its prologue sweep only recognises a function
 * that saves `lr`.  It reads one field of the state block and tail calls the
 * ARM routine at 0x02074758 with it, which in Thumb is `ldr` the address out
 * of the literal pool and `bx`: the compiler cannot encode a direct branch
 * to a different section, let alone one that changes instruction set, so the
 * target arrives as an ABS32 the linker fills in with the Thumb bit clear.
 */

typedef unsigned int u32;

struct Sub02005C18State {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
};

extern struct Sub02005C18State sub_02005C18_State;

extern void func_02074758(void **a0);

void sub_02005C18(void)
{
    func_02074758((void **)sub_02005C18_State.unk10);
}
