/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200B400
 * packet:   pkt_0200B400
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200B400, func_0200B424, func_0200B438, func_0200B440
 *
 * 72 bytes, 0x0200B400..0x0200B448, 4 functions, three of which carry no
 * label in the generated listing: the last three save nothing or nothing but
 * r4, so the range arrives as a run of `.word`s.  See
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md.
 *
 * alias: this continues "battle_rec.c", whose constructor func_0200B3DC is
 * the last function of src/matched/unit_0200B394.c and is what func_0200B400
 * calls.  The object it builds is hung off the single global at 0x0214616C,
 * the same one src/matched/unit_0200B900.c reads.
 *
 * func_0200B400 frees the old object before building the new one and clears
 * the global in between, which is a guard the source wrote rather than dead
 * code: the store of NULL is inside the `if`, and the fresh pointer is
 * assigned unconditionally afterwards.  The address of the global is
 * materialised twice, once for the test and free and once for the final
 * store, because the pool word is reloaded after the call rather than kept
 * in the callee-saved register that already holds it.
 *
 * func_0200B440 returns 0x18A4 out of its own pool word, which is the
 * "a block file opens with a function returning its own size" shape this
 * region keeps producing, except that here the size belongs to whatever the
 * next file allocates rather than to the 0x2000 buffer above it.
 *
 * symbols:
 *   func_020307B0   0x020307B0  arm
 *   gObj_0214616C   0x0214616C  data
 */

typedef unsigned int u32;

extern void  func_020307B0(void *p);
extern void *func_0200B3DC(u32 heap);

extern void *gObj_0214616C;

void func_0200B400(u32 heap)
{
    if (gObj_0214616C != 0) {
        func_020307B0(gObj_0214616C);
        gObj_0214616C = 0;
    }
    gObj_0214616C = func_0200B3DC(heap);
}

void func_0200B424(void)
{
    func_020307B0(gObj_0214616C);
    gObj_0214616C = 0;
}

void func_0200B438(void *p)
{
    func_020307B0(p);
}

u32 func_0200B440(void)
{
    return 0x18A4;
}
