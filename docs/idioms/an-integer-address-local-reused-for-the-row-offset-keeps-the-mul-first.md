# An integer address local reused for the row offset keeps the mul first

summary: Define an integer local with the row offset, then redefine it as the index term plus the
pointer sum. This keeps the multiply first and gives the original add operand order.

Shape (Thumb, ov197 0x0220BA2C):

    muls r4, r0, r4        ; c * 0x90
    ldrb r0, [r1, r7]      ; idx = q[0x535]
    adds r4, r6, r4        ; row = p + c*0x90
    lsls r0, r0, #2
    adds r0, r0, r4        ; e = idx*4 + row  (e shares idx*4's register)

The pointer forms (`p + c*0x90 + idx*4`, `&(idx*4)[row]`, `e += ...`) put row first in the
final add, so e takes row's register and the scheduler cannot lift the ldrb (5 bytes). The
one-expression integer sum `idx*4 + (u32)(p + c*0x90)` gives the right operand order but moves
the idx load above the mul.

Source that matches: define an integer local with the offset, then redefine it.

    u32 e = c * 0x90;
    e = q[0x535] * 4 + (u32)(p + e);
    *(u16 *)(e + 0x150) = r[0];
    *(u16 *)(e + 0x152) = r[1];

The first definition fixes the mul in its own statement (a redefined local is not forward
substituted), and the second gives idx*4 as the first operand.
