/*
 * file:     unit_0206A0C4.c
 * function: func_0206A0C4
 * address:  0x0206A0C4
 * packet:   pkt_02069FF8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * The DETACH half of the texture/palette upload descriptor whose ATTACH half
 * is src/matched/func_0206A00C.c: for each of the descriptor's two slots
 * (texture at +0x08/+0x10, palette at +0x18/+0x20), when the caller passed a
 * non-null out-pointer, clear the slot's "uploaded" bit 0, hand the caller the
 * VRAM address the slot held, and zero the slot.  Two independent halves with
 * no shared state, which is why the second `if` exits with a bare `bxeq lr`
 * rather than branching to a common tail.
 *
 * TWO THINGS THE BYTES FORCED:
 *
 *   1. `x &= ~1` ON A `u16` FIELD COSTS A POOL WORD.  The field is loaded with
 *      `ldrh`, so the operand of the AND is an `int` after promotion and `~1`
 *      is 0xFFFFFFFE, which does not fit an ARM rotated immediate: the front
 *      end materialises it as a literal (`ldr r3, [pc, #0x40]` / `and r3, lr,
 *      r3`) and the function grows a pool.  The image has `bic ip, ip, #1`,
 *      which only appears once the result is narrowed back to `u16` INSIDE the
 *      expression:
 *
 *          t->f10 = (u16)(t->f10 & ~1);
 *
 *      With the cast the AND is a 16-bit operation, ~1 is 0xFFFE, and `bic #1`
 *      is exact.  Without it the function is 92 bytes against the image's 76.
 *      This is the halfword sibling of
 *      docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md.
 *
 *   2. The two out-pointers are tested against null and NOT dereferenced
 *      unconditionally, which is what makes the function a leaf: the image
 *      never pushes anything and returns with `bxeq lr` / `bx lr`.
 *
 * THE `../2.0/sp2` PIN.  With the casts in place dsi/1.1p1 is still 80 bytes
 * against the image's 76 and 75 concrete bytes out, for one reason: it spends
 * `lr` as a scratch register for the first half's loaded halfword and
 * therefore has to open `push {r3, lr}` and return through `pop {r3, pc}`,
 * where the image keeps everything in `ip` and `r3` and stays a leaf.  That is
 * the wide-frame symptom of docs/FRONTEND-PINS.md read on a leaf rather than
 * on a callee-saved register.  ../2.0/sp2 and ../1.2/sp2 both reproduce the
 * image byte for byte with the same C; ../2.0/sp2 is recorded here because the
 * neighbouring cluster docs/families/cluster_0206A17C.h is already pin-heavy
 * on 2.0 and because the sibling filed in this same pass,
 * src/matched/func_0206A00C.c, is 2.0 and NOT 1.2.  Since two front ends agree
 * on this row it is not usable as evidence for either pin on its own, and it
 * is deliberately not offered as one in docs/FRONTEND-PINS.md.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A0C4.c \
 *       --func func_0206A0C4 --addr 0x0206A0C4 --arm --cc ../2.0/sp2
 *   -> EXACT, compiled 76 = original 76, 0 relocation sites
 */

typedef unsigned short u16;
typedef unsigned int u32;

struct Tex {
    u32 pad00[2];
    u32 f08;
    u32 pad0c[1];
    u16 f10;
    u16 pad12;
    u32 pad14[1];
    u32 f18;
    u32 pad1c[1];
    u16 f20;
    u16 pad22;
};

void func_0206A0C4(struct Tex *t, u32 *a, u32 *b)
{
    if (a != 0) {
        t->f10 = (u16)(t->f10 & ~1);
        *a = t->f08;
        t->f08 = 0;
    }
    if (b != 0) {
        t->f20 = (u16)(t->f20 & ~1);
        *b = t->f18;
        t->f18 = 0;
    }
}
