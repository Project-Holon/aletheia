# A shared running cursor and a reused counter settle a parse-loop register rotation

summary: when two passes over one string are spelled with separate cursor
locals (`p`, `q`) and separate counters, this front end colours four
registers and the body is 4 bytes short; spelling it the way the algorithm
actually works -- one running pointer advanced through both passes and one
counter variable reused -- reproduces the image's allocation exactly.

Found in: src/matched/ov009_func_0219359C.c (0x0219359C, GameSpy
gpiReadKeyAndValue, ov009 in the Black image)

The public GameSpy gpiUtility.c body is:

```c
buffer += *index;
start = (char *)buffer;
if(*buffer++ != '\\') CallbackFatalError(...);
for(i = 0 ; (c = *buffer++) != '\\' ; i++) { ...; *key++ = (char)c; }
*key = '\0';
for(i = 0 ; ((c = *buffer++) != '\\') && (c != '\0') ; i++) { ...; *value++ = (char)c; }
*value = '\0';
*index += (buffer - start - 1);
```

Spelling that with `const char *p = buffer + *index; const char *q = p + 2;`
for the first pass and a separate `int v` for the second pass compiled
368 bytes against the image's 372 and rotated the whole allocation
(image: start in `lr`, cursor in `r1`, c in `r5` then `r3`, i in `r6` then
`r5`, value in `ip`; compiled: cursor in `r6`, value in `r1`, cursor again in
`lr`, i in `ip`).  No operand reordering closed the gap.

Transcribing the public form verbatim -- one `buffer` running pointer that
both loops share, one `i` declared once and reused -- reproduced all 372
bytes.  Note the value loop's `c` lands in `r3`, not the `r5` the first loop
used, because the reused `i` takes over `r5`: the variable roles matter, not
just their count.

When to reach for it: a same-size residue that rotates the c/i/cursor/value
registers around one or two loops over the same buffer.  Prefer the shape the
original source would have had (a running pointer, a reused index) over
fresh cursor/count locals before sweeping spellings.  Related:
reusing-a-loop-variable-across-phases-changes-the-allocation.md reaches the
same conclusion from a Gauss-Jordan inverse, where only the counter identity
mattered; here the cursor pointer's identity matters too.
