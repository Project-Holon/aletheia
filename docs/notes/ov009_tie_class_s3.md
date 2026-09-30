# ov009 tie class (size-exact, <=8 concrete bytes) — lane S3

Seven rows, all `size-exact: allocation or scheduling`: the image and our build produce the
same length and the same instruction sequence, and differ only in operand/register selection.
All seven were re-measured from the parked sources with
`python tools/match.py one --src <src> --func <f> --addr <a> --region ov009 --arm --cc 1.1p1 --lang c99 --diff`.

**Verdict: none closed. All seven parked with a named residue.** No parked source was modified.

## Class-wide measurements (all negative)

* `match.py sweep` (9 compilers x 7 `-O` spellings) on 0215E2C0, 02194B74, 02180A64, 02180C94,
  02182414, 021990A0: every configuration reproduces the parked residue byte for byte.
  No pin wins; `-O4,p` is already the optimum for all six (the next best is -O3=85 diffs+).
* 14 `-opt` variants on 02194B74 (`noschedule`, `nopeephole`, `nocse`, `nopropagation`,
  `nostrength`, `nodead`, `nofold`, `level=4`, `inline off`, `ipa function`, `-O3,p`, `-O4,s`,
  `-O4,p -opt space/speed`): all but `-O4,s`/space reproduce the same 4 diffs.
* 11 body re-spellings of 0215E2C0 (locals in both orders, no locals, `unsigned short` locals,
  `p[1] - p[0]` over a `unsigned short *`, `-in + out - 1`, split `- 1`, explicit parens,
  `(long)` cast, separate declaration): all 4 diffs, byte-identical.
* 8 re-spellings of the 02180A64 16-byte copy (struct assignment, `GSUdpHdr *` temp,
  halfword index loop, halfword pointer loop, byte loop, `theMessage + 0`, `__builtin_memcpy`
  via a real `memcpy` call): the four struct-shaped forms all give the same 8 diffs; the
  hand-written loops change the size.

## The one lever that does move an eor row (02194B74 / 0219FE44)

Materialising the accumulator into a local *before* the last two `^`s flips the middle eor
from `eor r0, r2, r0` to the image's `eor r0, r0, r2`, on both functions:

```c
int t = (buffer[0] & 1) ^ (oddmode ^ ((i ^ buffer[i - 1]) & 1));
int d = (buffer[i - 1] < buffer[0]);
oddmode = (t ^ (buffer[0] < 0x4f)) ^ d;
```

That leaves 8 bytes (3 rows) instead of 4 (2 rows): it fixes `+0084`, and moves the residue to
the two `chal[i-1]`/`chal[0]` loads and the last eor. 0219FE44 behaves identically (8 diffs, same
three rows), so the shape is a class property, not a local accident. Roughly 50 further
parenthesisation/associativity/temp spellings (including every left- and right-nested form of the
five terms, `^=` chains, and `unsigned`/`int` temp types) either reproduce the parked 4 diffs or
make it much worse; the parked right-nested form is still the best at 4 diffs.

## Named residues (first differing instruction, image | ours)

| addr | bytes | Fn | residue |
|---|---|---|---|
| 0x0215E2C0 | 36 | SOCLi_GetWriteBufferFreeSize | `+0008 ldrh r1,[r0]` \| `ldrh r1,[r0,#2]` — the two ring-buffer loads are emitted in the opposite order (`+000C`, `+0014 sub r0,r0,r1` \| `sub r0,r1,r0` follow). Same value, swapped load order ⇒ r1/r0 swap. |
| 0x021990A0 | 52 | GetClientUniqueID | `+0020 mvn r1,#0x80000000` \| `sub r1,r0,#0x80000002` — the compiler folds the `0x7fffffff` upper bound against the `r0 == 1` already live; the image materialises the constant directly. |
| 0x02194B74 | 248 | gti2GetChallenge | `+0084 eor r0,r0,r2` \| `eor r0,r2,r0` (last two xor joins of the oddmode chain put the new term first). |
| 0x0219FE44 | 236 | SetupListChallenge | `+007C eor r0,r0,r2` \| `eor r0,r2,r0` — identical residue to 02194B74. |
| 0x02182414 | 320 | gsiXmlUtilParseName | `+0038 ldrsb r3,[sl,r0]` \| `ldrsb r2,[sl,r0]` — the first char and `buffer + *pos` swap r2/r3 (load order and store `+0088 str r2,[r7]` \| `str r3,[r7]` follow). |
| 0x02180A64 | 408 | gsUdpReceivedRoutingCB | `+0064 add r4,sp,#0x30` \| `add r3,sp,#0x30` — the inlined 16-byte copy colours dst=r4/src=r3 in the image, dst=r3/src=r4 for us (same for the whole loop). |
| 0x02180C94 | 436 | gsUdpConnAttemptCB | `+0050 ldr r3,[sp,#0x94]` \| `ldr r4,[sp,#0x94]` — same copy colouring as 02180A64. |

## Where the evidence points

All seven residues are the *same* choice made differently by the code generator: which of two
values takes the lower scratch register in a two-value expression, or the operand slot given to
a commutative operand. Nothing in the C source, the pin or the flag set moves them, which matches
the project-wide measurement that the allocator class is shut; they are candidates for a capped
row rather than more spellings.

Working files: `scratch/s3/` (`base_diffs.txt`, `sweep_*.json`, `gen_*.py`, the `v*`/`w*`/`A*`/
`a64_*`/`z15E_*`/`b9FE_*` variant sources).
