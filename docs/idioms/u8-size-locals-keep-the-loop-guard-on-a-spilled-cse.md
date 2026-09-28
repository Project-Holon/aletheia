# A size local typed like its u8 getter keeps each loop guard on a spilled `w - 1`

summary: if a SIZE diff has stack slots for both `w - 1` and `(w - 1) * 8`, a loop guard of the form `ldr [sp]; cmp #1; ble` on that stored `w - 1`, and a loop bound that is computed again from `w`, declare the size locals `unsigned char` like the getters they come from. As `int` locals the guard stops sharing the corner offsets' common subexpression, and the function comes out shorter.

Found in: src/matched/ov170_func_021EB378.c (0x021EB378)

The window frame routine reads the window width and height from two getters that
return `u8`. It draws four corners at `(w - 1) * 8` and `(h - 1) * 8`, then four
edge loops `for (i = 1; i < h - 1; i++)`. The image keeps `w - 1`, `(w - 1) * 8`
and `h - 1` in stack slots. The rotated loop's guard compares the stored `h - 1`
against 1, and the loop bound is computed again as `h - 1` into a register.

With `int w; int h;` the compiler puts only the product in a slot. Each guard
then computes `h - 1` into the loop-bound register and compares that register,
so the function is 20 bytes short (844 against 864), with every stack offset
moved. Declaring `unsigned char w; unsigned char h;` gives 864 bytes, EXACT, with
no other change. The getters' return type does not show in the diff, because no
truncation is emitted.
