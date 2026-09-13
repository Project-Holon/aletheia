# A __FILE__ argument is an ABS32 into the packed string area, not a local string

summary: declare the file-name string as an extern array pinned to its address
in the `symbols:` block; writing `__FILE__` puts the string in the object's own
rodata and the pool word then points at the wrong place.

Found in: `src/matched/unit_0200857C.c` (0x0200857C)

The debug allocator takes `__FILE__` and `__LINE__`. In the image the file-name
argument is a pool word holding an address in the packed string area:

```
ldr r3, [pc, #0x14]      /* 0x020A70B8, which spells "playtime.c" */
```

Write it as an extern array whose address is pinned in the header block:

```c
extern const char sub_0200857C_File[];
```

```
 * symbols:
 *   sub_0200857C_File   0x020A70B8  data
```

Writing the literal `__FILE__` instead does not work and makes the diff
misleading. The compiler then emits the string into this object's own
`.rodata` and relocates against a local symbol, and `match.py tu` lays out only
executable sections, so the pool word is filled with an address that has
nothing to do with the original.

The address is attested by the `string` class: the string before it ends with
its NUL at 0x020A70B6, which fixes where this one begins without reading the
pool word under test. See "The string class" in `docs/MATCHING.md`.
