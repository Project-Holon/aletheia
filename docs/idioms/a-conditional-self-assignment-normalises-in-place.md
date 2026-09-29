# A conditional self-assignment normalises a value in place; a boolean expression does not

summary: mwccarm spells `x = x; if (x) x = 1;` as `cmp rX, #0; movne rX, #1`,
leaving the zero case untouched, but spells the equivalent `x = x != 0` (or
`x ? 1 : 0`) as a full 0/1 materialisation `cmp; movne; moveq`.  The extra
`moveq` is one instruction and four bytes.

Found in: `src/matched/ov_sdk/ov009_func_0218C774.c` (0x0218CA58)

`gpiSetInfoi` case 0x715 forwards a boolean of the `value` parameter to
`OS_SPrintf(intValue, "%d", value != 0)`.  The vendor normalises `value` in
place, because when `value == 0` the register already holds zero:

```
0218CA58  cmp r2, #0
0218CA5C  movne r2, #1        ; r2 still holds value, and 0 maps to 0
0218CA60  mov r0, r4
0218CA64  bl OS_SPrintf
```

The obvious C produces a full boolean instead, and the function is four bytes
too long:

```c
OS_SPrintf(intValue, str15207, value != 0);   /* cmp; movne r2,#1; moveq r2,#0 */
```

Parenthesising, a ternary, `!!value`, `value && 1`, and assigning the result
back (`value = value != 0;`) all emit the `moveq` too.  What reproduces the
vendor is a conditional self-assignment, which is not a boolean expression at
all so the compiler never has to clear the false case:

```c
value = value;
if (value)
    value = 1;
OS_SPrintf(intValue, str15207, value);        /* cmp; movne:  EXACT */
```

(The first statement looks redundant but is what keeps `value` in its argument
register; it compiles away.)  When the only remaining difference on a function
is a size of four bytes and the extra instruction is `moveq` feeding a call
argument, try this shape.
