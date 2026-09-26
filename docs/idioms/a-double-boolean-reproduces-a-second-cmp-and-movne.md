# A double boolean is what reproduces the image's second `cmp`/`movne`

summary: when a comparison result is passed as an argument but the image
materialises it twice (`cmp; movne #1; moveq #0` then `cmp #0; movne #1;
moveq #0`), the source held the first result in a named local and then wrote
`local != 0` again at the call; folding the two tests into one loses four
instructions and twelve bytes.  `_Bool` is not a keyword in this C99 front end,
so writing the conversion explicitly is the only route.

Found in: src/pending/ov009_func_0219329C.c (0x0219329C)

`gpiCheckForError`'s fatal branch ends in

```
bl   func_02094B20
cmp  r0, #0
movne r0, #1
moveq r0, #0        ; b = (func_02094B20(...) != 0)
cmp  r0, #0
mov  r2, #1
moveq r2, #0        ; arg3 = (b != 0)
mov  r0, r8
mov  r1, #4
bl   func_02189D78
```

The double test is real: the value was assigned to an `int` local first, then
re-tested when it was passed.  Writing the obvious single test

```c
func_02189D78(connection, 4, func_02094B20(input, g_021A5734) != 0);
```

emits just `mov r2, #1; moveq r2, #0` and compiles 208 bytes against the
image's 220; the whole tail then shifts by twelve bytes and reads as a
register-rotation wall.  Holding the first result in a local and re-testing it

```c
int b = func_02094B20(input, g_021A5734) != 0;
func_02189D78(connection, 4, b != 0);
```

is EXACT up to the one wildcarded relocation.

Two spelling notes:

* `_Bool` is not a keyword for `-lang c99` here -- `extern int f(..., _Bool);`
  is a CCERR ("illegal function definition"), so the shadow conversion cannot
  be spelled as a parameter type.
* The re-test must be written `b != 0`, not `b`; passing the `int` straight
  through drops the second `cmp`.

The same tell decides the run of comparisons that feed an argument register:
a lone `cmp/movne/moveq` pair in the image where the compile emits one pair
means the source has an intermediate local whose boolean is re-evaluated at the
call.
