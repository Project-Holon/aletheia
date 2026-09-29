# An out-of-range ctype guard folds to one `cmp` only when the test is unsigned

summary: A `__ctype_mapC[c]` guard folds to a single `cmp rX,#0x80; movhs` only
in the `(unsigned)(c) >= 0x80u` spelling; the signed `c < 0 || c >= 0x80` form
keeps a short-circuit pair and costs several instructions.

When SDK C reaches for a `__ctype_mapC[c]` table it must first reject an
out-of-range `c`. Two spellings compile differently under `-O4,p`:

```c
/* A: folds to `cmp r0,#0x80; movhs r0,#0` + conditional table load */
#define isalnum(c) (((unsigned)(c) >= 0x80u) ? 0 : (__ctype_mapC[(c)] & 0x9))

/* B: materialises the boolean, then branches on it */
#define isalnum(c) (((c) < 0 || (c) >= 0x80) ? 0 : (__ctype_mapC[(c)] & 0x9))
```

`c` here is a sign-extended `char` (`ldrsb`), so on a 32-bit compare every
negative value is `>= 0x80u` unsigned; form A therefore collapses the two
guards into the single unsigned compare the original emits.  Form B keeps
them as a short-circuit disjunction and costs a `mov r0,#1; cmp r1,#0; blt;
cmp r1,#0x80; movlt; ...` sequence, several instructions longer.

The visible tell is the instruction right after the `ldrsb`: the original
has `cmp rX,#0x80` / `movhs`, not a `cmp rX,#0` branch.

Two corollaries seen in the same family:

* The macro argument must be a single `char` local, not an lvalue such as
  `buffer[*pos]`.  Referencing `buffer[*pos]` three times inside the macro
  reloads it three times (the compiler will not common them across the
  `__ctype_mapC` base load), which is what forces form B even when A was
  written.  Bind `char c = buffer[*pos];` first.

* `gsiXmlUtilParseElement` (ov009, 0x02181E80) is size-exact against this
  idiom but still ~95 words of pure `-O4,p` scheduling away; switching the
  macro between A and B moves the function by 8 bytes, so it is a real
  choice the source made, not noise.
