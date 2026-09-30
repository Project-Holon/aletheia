# A 4-byte-aligned out-header struct shifts its stack slot from the top of the frame

summary: when an out-parameter struct is only 2-aligned (every member is `u8`
or `u16`) mwcc places it at the highest **2**-aligned offset, so it lands two
bytes below the top of the frame in the *compiled* output; the original has it
at the highest **4**-aligned offset. Giving the temporary struct a `u32`
member (nothing else changes) pulls it back to the 4-aligned slot and the
`add rN, sp, #0x..` / `ldrb rN, [sp, #0x..]` pair lines up.

Found in: `src/pending/ov_sdk/ov107_func_021F2200.c` (0x021F2200,
MBi_CommParentRecvDataPerChild, mb_parent.o)

The function fills a request header through an out pointer:

```
021F2228  add r1, sp, #0x20      /* &hd */
...
021F2238  ldrb r8, [sp, #0x20]   /* hd.fileid */
```

with `sub sp, sp, #0x34`. Written with the obvious struct

```c
typedef struct {
    u8 fileid;
    u8 unk1;
    u16 f2;
    u8 pad[0x10];                /* sizeof 0x14, align 2 */
} MBCommChildBlockHeader;
```

1.1p1 puts the struct at `sp+0x1e`, two bytes low, because nothing in it asks
for four-byte alignment (`add r1, sp, #0x1e` in the diff). Adding one unused
`u32` member:

```c
typedef struct {
    u8 fileid;
    u8 unk1;
    u16 f2;
    u32 unk4;                    /* forces align 4, still sizeof 0x14 */
    u8 pad[0x0c];
} MBCommChildBlockHeader;
```

moves the slot to `sp+0x20` and every access — the `add` for the address and
the `ldrb` load — matches, with no instruction added or removed. The struct is
a stack temporary, so the extra member is never named and costs nothing.

The tell is a two-byte-only slip on a whole-frame out struct whose original
slot is 4-aligned: the real type has a word member the reconstruction is
missing. This is preference, not a hard requirement (a `u32` at any offset
does it), and it is independent of the function's register colouring.
