# a / b and a % b on the same operands are two calls

summary: the division helper returns quotient and remainder together but the
compiler does not know that, so the original calls it twice in a row with
identical arguments.

Found in: `src/matched/unit_0200857C.c` (0x020085D4)

`_u32_div_f` returns the quotient in `r0` and the remainder in `r1`. The
compiler does not model that, and common subexpression elimination does not
touch a call, so `x / 60` and `x % 60` on the same operands become two separate
calls with the same arguments, back to back. The original visibly does this.

The reverse reading is the useful one: two consecutive identical calls to the
helper are a `/` and a `%` in the source, not a loop or a repeated operation.
Writing the division once into a temporary and deriving the remainder from it
(`x - q * 60`) is a different function and does not match.
