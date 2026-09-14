# Several __LINE__ arguments in one function are one pool word and a chain of adds

summary: a constructor that calls the debug allocator four times passes four
different line numbers, and this front end materialises only the first of them
from a literal pool and derives the rest with `adds r0, r0, #k`; the deltas are
the distances between the calls in the original source, so the pool word plus
the three immediates recover four exact line numbers rather than one.

Found in: `src/matched/unit_0201C328.c` (0x0201C328)

`sub_0201C328` allocates its module object, two arrays and then one record per
element.  Each allocation passes `__FILE__` and `__LINE__`, and the four line
numbers arrive like this:

```
ldr  r0, [pc, #0x7c]     /* 0x00000241, i.e. 577 */
str  r0, [sp]            /* the fifth argument of the first call */
...
ldr  r0, [pc, #0x68]     /* the same pool word */
adds r0, r0, #1          /* 578 */
str  r0, [sp]
...
ldr  r0, [pc, #0x50]
adds r0, r0, #2          /* 579 */
str  r0, [sp]
...
ldr  r0, [pc, #0x34]
adds r0, r0, #7          /* 584, into a stack local, reloaded per iteration */
str  r0, [sp, #4]
```

One pool word, three `adds`.  Common subexpression elimination treats the four
constants as one value plus three offsets because 577 needs a pool word anyway
(a `movs` immediate reaches 255) and an `adds rN, #k` is two bytes against the
four a second pool word would cost.

Two things follow, and the second is why this is worth a file.

**The C is just the four constants.** Writing `577`, `578`, `579` and `584` as
plain arguments reproduces all of it; nothing has to be spelled as an offset,
and writing them as `577`, `577 + 1`, ... changes nothing.  Getting this wrong
in the other direction is the trap: reading the `adds r0, r0, #1` as an
argument the source computed sends the search after a variable that is not
there.

**The line numbers are recoverable, and they locate the function in its
original file.** 577, 578, 579 and 584 in `waza_tool.c` and 287 in
`printsys.c`; `pokeparty.c`'s constructor is at 65 and its swap routine at
382.  Together with the `__FILE__` strings, which
`docs/idioms/file-string-is-an-abs32-into-the-string-area.md` covers, that puts
matched ranges at known line numbers of known original sources, which is direct
evidence for where one translation unit ends and the next begins: a range whose
line numbers run backwards cannot be one file.
