# Lane T21 — ov009 open SDK rows 24–31 (fresh pass over the T4 slice)

No row in the slice reached EXACT. One real advance (0x021685CC, 108 B -> 18 B) and a
precise first-difference line for every other row. Compiled with
`python tools/match.py one --src src/pending/ov_sdk/ov009_<ADDR>.c --func func_<ADDR>
--addr 0x<ADDR> --region ov009 --arm --lang c99 --diff`, 1.1p1 / -O4,p / c99, ~85 min wall.

Current state of the eight parked rows (working tree, 2026-09-30):

| row | address | bytes | name | concrete | first differing instruction (image | ours) |
|----|----|----|----|----|----|
| 24 | 0x021685CC | 276 | DWCi_GetMathRand32 | 18 | +0098 `ldm r4, {r2, r3}` \| `ldr r1, [pc, #0x68]` |
| 25 | 0x0216C8DC | 296 | DWC_AddMatchKeyInt | 134 | +0004 `movs r6, r1` \| `movs r7, r1` |
| 26 | 0x0216CA04 | 300 | DWC_AddMatchKeyString | 133 | +0004 `movs r6, r1` \| `movs r7, r1` |
| 27 | 0x02182414 | 320 | gsiXmlUtilParseName | 7 | +0038 `ldrsb r3, [sl, r0]` \| `ldrsb r2, [sl, r0]` |
| 28 | 0x021986C4 | 324 | gt2StringToAddress | 189 (328 vs 324) | +002C `beq #0x21987e4` \| `beq #0x21987e8` |
| 29 | 0x02164D74 | 364 | WCM_InitEx | 18 | +0018 `ldr sb, [pc, #0x148]` \| `mov r1, #0` |
| 30 | 0x021894D8 | 364 | gpiSendData | 21 | +0118 `ldr r2, [r1]` \| `ldr r3, [r1]` |
| 31 | 0x0219C5B8 | 364 | qr2_process_ip_verify | 46 | +0024 `mov r0, r5` \| `sub r8, r5, #1` |

## 0x021685CC — 276 B, 18 concrete, and the pool word was the whole story (108 -> 18)

The parked body compiles to 268 B with **one** pool word for the context and ctx/`&seed`/max in
r4/r5/r6; the image is 276 B with **two** pool words both holding 0x021AA848 and ctx/`&seed`/max in
r6/r4/r5. Two words for one address is the signature of
`docs/idioms/a-duplicated-pool-word-is-a-second-extern-name-for-the-same-address.md`: the source
named the context through two different externs. Declaring a second alias at the same address
(`g_021AA848_x  0x021AA848  data` in the `symbols:` block, used only for the seed store) splits the
word, restores 276 B and the image's whole register assignment, and drops the residue from 108 to
18 concrete bytes. Both ABS32 sites then resolve as `sole-ref` (4 of 4 resolved).

What is left is one literal load's position. The image keeps source order inside the init block

```
        +0094 ldr r0, [pc, #0x68]   ; the second name, for the x store
        +0098 ldm r4, {r2, r3}
        +009C stm r0, {r2, r3}
        +00A0 ldr r0, [pc, #0x60]   ; mul lo
        +00A4 ldr r1, [pc, #0x60]   ; mul hi
        +00A8 str r0, [r6, #8]
```

this build hoists the mul-lo literal one statement early, above the second name's load:

```
        +0094 ldr r0, [pc, #0x68]   ; mul lo
        +0098 ldr r1, [pc, #0x68]   ; the second name
        +009C ldm r4, {r2, r3}
```

Everything else is identical; the hoist is what rotates r0/r1. Measured flat (all 276 B, all 18
concrete unless noted): the seed store as a plain `u64` extern, as `*(u64 *)&alias`, through a named
`char`/struct pointer local, inside a nested `{}` block, with the aliases swapped so the guard holds
the second name, and with the alias declared before the first. Writing `mul`/`add` before the seed
store (4 spellings) moves the hoist into the seed computation and costs 51. The next lever here is
whatever makes mwccarm start the `mul = ...` statement late — 24's hoist is the mirror image of 29's
below, where the image hoists and this build does not, so the pair is worth reading together.

## 0x02164D74 — 364 B, 18 concrete, the same lever inverted

Image: `ldr sb, [pc, #0x148]` (+0018), `mov r1, #0` (+001C), `ldr r2, [sb, #4]` (+0020), `mov r5, r0`
(+0024), `str r1, [sp]` (+0028). This build: `mov r1, #0`, `ldr sb, [pc, #0x144]`, `str r1, [sp]`,
`ldr r2, [sb, #4]`, `mov r5, r0` — same five instructions, the pool load sunk below the zero it
hoists in the image and the expectLen spill raised above the `wcmw` field load. Both are 364 B, so
this is the zero/spill schedule alone, not a size lever.

## 0x0219C5B8 — 364 B, 46 concrete (the floor of T4's 13 spellings, not broken)

The image's `numDuplicates = 0` is a copy of `i`'s zero (`mov r0, r5` at +0024, in the **entry**
block, before `firstFreeIndex = -1`); this build keeps `i` in r0 and materialises that copy at the
loop preheader (+004C), so `i`/`numDuplicates` swap between r5 and r0 for the rest of the function.
Also re-measured flat at 46 B: swapped declarations (`numDuplicates` before `i`), swapped
`i = 0;` / `numDuplicates = 0;` statements, dropping the redundant pre-loop `i = 0;`, and
`numDuplicates = i;` as the zero. The lever is which of the two counters takes the entry-block zero.

## Re-measured flat in this lane

`0x02182414` (7 B, r2/r3 colouring swap: image keeps the char in r3 and `buffer + *pos` in r2);
`0x0216C8DC` / `0x0216CA04` (134/133 B, one callee-saved slot and one hoisted zero, per T4's note);
`0x021986C4` (189 B, +4 B); `0x021894D8` (21 B, +0118 `ldr r2,[r1]` vs `ldr r3,[r1]`). No pin or flag
sweep was run — T4 and the project-level measurements already closed that axis.
