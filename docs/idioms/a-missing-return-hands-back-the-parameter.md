# A path with no return statement hands back the parameter still in r0

summary: When one path of an s32 function returns the untouched first parameter
in r0 and the other returns a computed value, the original may have no return
statement on that path at all; writing `return v;` makes the compiler join the
paths through a register copy (+4 bytes), and an s64 return type recolours the
early loads because r1 becomes part of the result.

Found in: src/matched/func_020111BC.c (0x020111BC)

The image: `push {r3, lr}`, the mode byte loaded through r1, `adds r2, r0, #0`
(a copy of v for the 64-bit multiply), `beq` straight to `pop {r3, pc}` on the
0x30 path, and the quotient from `_ll_sdiv` popped out in r0 on the other. v is
never written back to r0 and r1 is never set on the early path.

Source that matches (dsi/1.1p1):

    s32 f(s32 v)
    {
        if (mode != 0x30) {
            return (s64)rate * v / 100;
        }
    }

Wrong spellings measured: `return v;` on either side, an assignment to v or to
a result local with one return, a ternary: all 48 bytes, the join value
coalesced with the multiply's copy of v (`adds r2, r0` / `adds r0, r2` after
the divide). An s64 return type with the missing return: 44 bytes but the mode
load moves to r3, 3 bytes out. A void function: 2 out.

Tell: an early exit that returns the incoming r0 with no instruction touching
it, beside a path that computes the result into r0, and a byte-correct shape
that only differs by a join copy when both paths return.
