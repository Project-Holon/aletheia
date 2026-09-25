# An indexed field must stay inline; a named base pointer flips the base and index registers

summary: `*(int *)(p + K + i * 4)` scales `i` first and keeps the base in the
lower callee-saved register; binding `p + K` to a named `int *s` and writing
`s[i]` instead materialises the base first and moves the scaled index into the
lower register, swapping `r4` and `r5` at every `ldr`/`str` and nowhere else.

Found in: `src/matched/func_021DE34C.c` (0x021DE34C), `src/matched/func_021B7550.c`
(0x021B7550), `src/matched/func_021B75E8.c` (0x021B75E8)

The three functions are the same shape: a pointer plus a scaled index reaches a
field past a large offset, and the value is conditionally freed and cleared.

```
lsls r5, r1, #2          /* index * 4, into r5 */
ldr  r1, [pc, #K]        /* the field base offset */
adds r4, r0, r1          /* base pointer, into r4 */
ldr  r0, [r4, r5]        /* s[i] */
```

Writing the base as a named local,

```c
int *s = (int *)(p + 0xb74);
if (s[i] != 0) { func(s[i]); s[i] = 0; }
```

compiles the *other* way round on this compiler: the base is materialised
first and takes `r5`, while the scaled index takes `r4`:

```
ldr  r2, [pc, #K]
lsls r4, r1, #2
adds r5, r0, r2
ldr  r0, [r5, r4]
```

The bytes are otherwise identical; only the two registers are interchanged at
every access. Keeping the whole expression inline reproduces the original
exactly:

```c
if (*(int *)(p + 0xb74 + i * 4) != 0) {
    func(*(int *)(p + 0xb74 + i * 4));
    *(int *)(p + 0xb74 + i * 4) = 0;
}
```

The compiler CSEs the three accesses, so the inline form is not longer. This is
the register-allocation sibling of
`docs/idioms/declaration-order-decides-which-register-a-local-gets.md`: there a
declaration order picked the register, here introducing (or not introducing) a
named base pointer does. When an indexed-field diff is a pure `r4`/`r5` swap,
try inlining the address expression before touching anything else.
