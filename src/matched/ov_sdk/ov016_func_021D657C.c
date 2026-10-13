/*
 * function: func_021D657C
 * address:  0x021D657C
 * packet:   pkt_ov016_021D657C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes: SIZE-EXACT (272 B), 2/2 relocs resolved, 40 concrete bytes out (was 54).
 * The instruction stream is identical instruction-for-instruction; the whole
 * residue is the front end's colouring of the caller-saved scratch register
 * set {r0,r1,r2} in the key-mask block at +0028..+0078:
 *   image   bit repr r1, ks pointer r0, mask temp r2
 *   ours    bit repr r0, ks pointer r2, mask temp r1
 * plus one scheduling slot: the release `cont` read at +0068 uses the trg
 * statement's cached ks pointer in the image (which then reloads ks at +006C
 * only for the store base), ours reloads ks first and reads cont through it.
 * A second scheduling slot remains at +00E0: the image interleaves the
 * count=40 store (L164) between the repeat arm's ks load and its ldrh (both
 * L163); ours sinks it past the whole RMW.
 *
 * The vendor object (stamp 4.0.0.1025) is byte-identical to the image, and its
 * .debug_line fixes the source statement order: line 144 is the single mask
 * block, 147 trg, 148 release, 149 cont+repeat, 152 for, 153 mask, 154 if,
 * 157/158/159 the ==40 arm, 162/163/164 the ==47 arm -- where line 163 (the
 * repeat OR) PRECEDES line 164 (count=40). Spelling the ==47 arm in that
 * vendor order (`repeat |= mask;` then `count[i] = 40;`) recolours the whole
 * loop onto the image's r5=40 / r6,r7 temps and took the file from 71 to 54
 * concrete bytes; the reverse order rotates them (r7=40 / r5,r6). See
 * docs/idioms/a-swapped-store-and-rmw-in-one-arm-recolours-the-whole-loop.md.
 *
 * blocker: the +0028 block colouring is a 4.0.0.1025-vs-1.1p1 front-end
 * difference. bit/i/input are the only DWARF locals (order input, i, bit), so
 * no named-temporary lever exists; six declaration orders, a named mask local,
 * a self-assignment of bit and of input, a second u16 local for the masked
 * value, casts on either statement, and operand/associativity respellings of
 * the mask all compile to the same 54. A 4.0.0.1025 vendor object is not a
 * blocker per the wave brief in general, but this specific scratch rotation is
 * not reachable from 1.1p1 source.
 *
 * Wave-8 re-measure (same 54): const/volatile on the input pointer, no named
 * `input` at all (direct derefs), initialiser-at-declaration, C99 for-scope,
 * named raw and named u16+int mask locals, mask term swap/paren/NAND/u16-cast
 * respellings.  Only unsigned `i` (55, blo vs blt) and u8 masks (190+) move it.
 * This is the allocator tie of
 * docs/idioms/a-base-pointer-and-its-mask-scratch-swap-as-an-allocator-tie.md:
 * the long-lived bit/mask accumulator and the object pointer are two scratch
 * colours the 1024/1025 allocator picks oppositely, with no boundary crossing.
 *
 * lane04 (2026-10-01): 54 -> 40. The vendor relocation names
 * `_ZZ7readKeyvE5count`, a function-local static: `static unsigned char
 * count[14];` inside the function (named reloc, resolves) removes the +00E0
 * count=40 slot. Left: the +0028..+0078 scratch colouring and the +0068
 * cont-read slot. A file-static ks pointer (MemInput) and the reverse ==47 arm
 * order (66) do not help.
 *
 * wave 2 lane 20 (2026-10-01): EXACT. The DWARF local `input` is reused:
 * after the KEYINPUT read it is set to &ks->cont (between the two bit
 * statements), and trg/release read cont through *input. That gives the
 * image's mixed reload pattern (cont via the cached ks, ks reloaded for the
 * store base) and, from its live range across the mask statement, the
 * r1/r0/r2 scratch colours. Not a 1025 front-end wall.
 *
 * sdk:      readKey (libdwcutil.TWL.HYB.a input.o)
 *
 * symbols:
 *   gInputStatics     0x021DE688 data
 *   _ZZ13func_021D657CvE5count 0x021DE690 data
 */

struct keystate {
    char pad0[0x30];
    unsigned short cont;
    unsigned short trg;
    unsigned short repeat;
    unsigned short release;
};

struct keyfold {
    int f0;
    struct keystate *ks;
};

extern struct keyfold gInputStatics;

void func_021D657C(void)
{
    static unsigned char count[14];
    unsigned short *input;
    int i;
    unsigned short bit;

    input = (unsigned short *)0x04000130;
    bit = ((*input | *(unsigned short *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF;
    input = &gInputStatics.ks->cont;
    bit = bit & ~((bit & 0x40) << 1) & ~((bit & 0x20) >> 1);
    gInputStatics.ks->trg = (*input ^ bit) & bit;
    gInputStatics.ks->release = (*input ^ bit) & *input;
    gInputStatics.ks->cont = bit;
    gInputStatics.ks->repeat = gInputStatics.ks->trg;
    for (i = 0; i < 14; i++) {
        if (!(bit & (unsigned short)(1 << i))) {
            count[i] = 0;
        } else {
            count[i]++;
            if (count[i] == 40) {
                gInputStatics.ks->repeat |= (unsigned short)(1 << i);
            } else if (count[i] == 47) {
                gInputStatics.ks->repeat |= (unsigned short)(1 << i);
                count[i] = 40;
            }
        }
    }
}
