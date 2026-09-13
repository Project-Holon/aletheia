# The reach of the Thumb immediate decides whether a field access costs an adds

summary: `ldr` reaches +124, `ldrh` +62, `ldrb` +31, so a field past the limit
costs an extra `adds rN, #imm` that is an encoding artefact and not a pointer
in the source.

Found in: `src/matched/unit_02008828.c` (the +0x76 and +0x78 accessors)

The Thumb immediate-offset load and store forms scale their five-bit immediate
by the access width:

| form | scale | reach |
| --- | --- | --- |
| `ldr` / `str` | 4 | 124 |
| `ldrh` / `strh` | 2 | 62 |
| `ldrb` / `strb` | 1 | 31 |

So the word at +0x78 is one instruction while the halfword at +0x7C is two,
with no difference whatever in the source:

```
str  r1, [r0, #0x78]        /* the word: in reach */
adds r0, #0x7C              /* the halfword: out of reach */
strh r1, [r0]
```

Reading that `adds r0, #imm` as an offset computation in the source rather than
as an encoding artefact invents a pointer variable that is not there, and then
nothing after it lines up.
