/*
 * file:     crt0_build.c
 * unit:     yes
 * address:  0x02005030
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    The build record the SDK linker fills in (crt0.FLX.c line 103; a .rodata
 *           section of its own after the module parameters in the original): eight
 *           words, the build flags and the magic pair.  A unit of its own because
 *           mwccarm merges all const objects of one unit into a single .rodata sorted
 *           by size, which cannot keep it apart from the tables of crt0.c.
 *
 * symbols:
 *   _start_BuildParams  0x02005030  data
 */

const unsigned long _start_BuildParams[8] = {
    0x00000000UL, 0x00000000UL, 0x00000000UL, 0x00000000UL,
    0x00000900UL, 0x00000001UL, 0xDEC08133UL, 0x3381C0DEUL,
};
