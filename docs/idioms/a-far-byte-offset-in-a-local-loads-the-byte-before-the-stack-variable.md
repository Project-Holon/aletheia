# A far byte offset in a local loads the byte before the stack variable

summary: when a compare between a byte field at a far offset (`c[0x604]`) and an
address-taken stack word (`x`) loads `x` first in the draft but the byte first in the
image, the source held the offset in a local (`k = 0x604; c[k] <= x`). With a literal
offset the byte tree is cheap and mwcc evaluates `x` first, so the registers of the two
operands swap (`cmp x, byte; blo` against the image's `cmp byte, x; bhi`).

Found in: `src/matched/ov/ov208_func_021C6760.c` (0x021C6760).

The image (Thumb, 1.1p1 -O4,p), a touch rectangle test in a loop:

    ldr   r0, [sp, #0xc]     ; 0x604, hoisted
    ldrb  r1, [r4, r0]       ; c[0x604] first
    ldr   r0, [sp, #0x1c]    ; x (address-taken by the touch getter)
    cmp   r1, r0
    bhi   next

The draft `if (c[0x604] <= x && x < c[0x604] + c[0x606] && ...)` loaded `x` into r1
first and gave `cmp r0, r1` (14 bytes out). Operand order, u8 locals for the rect
bytes, inline helpers and struct points did not change it. `int k; ... k = 0x604;`
with `c[k]`, `c[k + 1]`, `c[k + 2]`, `c[k + 3]` is EXACT: the byte tree now needs a
register for the offset, so it is evaluated before `x`.

Same shape, not yet tried: ov208 0x021BEFA0 (rect tests `cmp x0, x; bhi`).
