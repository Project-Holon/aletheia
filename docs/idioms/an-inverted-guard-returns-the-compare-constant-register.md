# An inverted guard with a trailing return -1 hands back the compare's constant register

summary: When the image returns a sentinel from the register that the
sentinel compare used (`cmp r6, sb` / `moveq r0, sb`), write the body inside
`if (i != -1) { ...; return i; }` with `return -1;` after it. An early
`if (i == -1) return i;` returns the index register, and an early
`return -1;` materialises a second constant and recolours the function.

Found in: src/matched/func_0204A7A0.c (0x0204A7A0), src/matched/sub_0204A6C8.c (0x0204A6C8)

The image, after a scan that leaves i = -1 when nothing is found:

    mvn r6, #0          ; i = -1
    mvn sb, #0          ; the compare constant, reused later (sb + 0x8000)
    cmp r6, sb
    addeq sp, sp, #0x1c
    moveq r0, sb        ; returns the constant's register, not i
    popeq {...}

Source that matches (dsi/1.1p1):

    found:
        if (i != (u32)-1) {
            ... body ...
            return i;
        }
        return -1;

Wrong spellings measured (four waves): `if (i == (u32)-1) return i;` with
the image's declaration order, every byte right except `moveq r0, r6` (1
out); `return -1;`, `return (u32)-1;`, a `none` local, an enum member, a
0xFFFFFFFF compare, a long return type: 47, the -1 moves to lr and heapId to
r8; a goto to a shared return: 185; the scan as an inline helper: 1 / 47.
With the guard inverted the compiler still emits the early exit as a
predicated epilogue, but the returned -1 is the same value as the compare
operand, so it takes the compare's register and the rest of the colouring
stands. The declaration order still matters (slot before i: exact; i before
slot: 18).

The sibling 0x0204A6C8 closed the same way, although its residue did not
look like a return at all: the early `return -1;` form was right at the exit
and 4 out on the order of two moves after a later call (`mov r8, r0` for the
call result, `mov r7, #0` for a zero shared by the next call and a store),
flat through five waves of prototype, volatile, temporary and declaration
levers. Inverting the guard changes the flow graph (the body becomes the
guarded block, the not-found path the join) and the allocator then emits
the two moves in the image's order. So try the inversion on any
scan-then-claim function whose residue is a tie, not only on the return.

Tell: a predicated early exit that returns the register holding the
sentinel the index was compared against, next to a byte-correct build that
returns the index register instead.
