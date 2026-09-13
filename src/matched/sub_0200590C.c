/*
 * Matched game function, written from the disassembly in
 * asm/arm9/src/000_02004000.s.
 *
 * function: sub_0200590C
 * address:  0x0200590C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0200590C_Cur    0x020AA1AC  data
 *   sub_0200590C_Table  0x020AA1B8  data
 *
 * Original (24 bytes, leaf, two ABS32 literals):
 *   ldr  r0, [pc, #0xc]   ; &sub_0200590C_Cur
 *   ldr  r2, [pc, #0x10]  ; &sub_0200590C_Table
 *   ldr  r1, [r0, #4]
 *   movs r0, #0x1c
 *   muls r0, r1, r0
 *   adds r0, r2, r0
 *   adds r0, #8
 *   bx   lr
 *   .word <cur>
 *   .word <table>
 *
 * Address of a member inside an element of a 0x1C-byte table, indexed by a
 * word held in a second global.  0x1C is not a power of two, so the element
 * offset is a real multiply; the trailing `adds r0, #8` is the member
 * offset, which is what makes this an address-of rather than a load.
 *
 * Both pool words are ABS32 relocations, resolved against the addresses
 * declared above; each is attested by a dozen or more other functions that
 * load the same address from their own pools.
 */

typedef unsigned int u32;

struct Sub0200590CEntry {
    u32 unk00;
    u32 unk04;
    u32 unk08[5];
};

struct Sub0200590CCur {
    u32 unk00;
    u32 index;
};

extern struct Sub0200590CCur  sub_0200590C_Cur;
extern struct Sub0200590CEntry sub_0200590C_Table[];

u32 *sub_0200590C(void)
{
    return sub_0200590C_Table[sub_0200590C_Cur.index].unk08;
}
