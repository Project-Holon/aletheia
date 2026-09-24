# Wave 21, lane F2: 0x0201DB20

**Verdict: EXACT\*** under dsi/1.1p1 -O4,p. The code is 154 bytes and the listing extent is 156, because it includes 2 bytes of padding. Before this pass the function stood at DIFF 15.

The file is `src/matched/sub_0201DB20.c`. I ran `manifest --verify --shard pkt_0201DB20` twice. Both runs report func_0201DB20 as EXACT\*, and the second run rewrote nothing. The other three entries in the shard are unchanged: DBBC is EXACT, DBF4 is EXACT\* and DC44 is EXACT.

## The lever

The chain step goes through a second pointer local and ends in a copy. The locals are declared in the order m, lo, hi:

```c
n = m->pNext;
if (n != 0)
    n = (struct CMap *)(*(u8 **)((u8 *)f + 0x88) + ((u8 *)n - f->unk68));
else
    return 0;
m = n;
```

## How it was found

I did not permute the wave 15 source. I reduced the function instead, with m declared first, to find which feature makes m colour last:

- **m colours first (m r4, lo r5, hi r6, which is the image's assignment)** in these reductions:
  - the search on its own
  - the switch without the outer loop
  - the outer loop with a plain `m = m->pNext` chain step
- **m colours last** as soon as m's loop-carried definition is an arithmetic result. Even `m = (u8 *)m + 4` does it. In that case declaration order has no effect on m.
- **Why earlier lanes saw no change:** every one of their spellings kept m's loop-carried definition arithmetic. That covers:
  - all 120 declaration orders
  - the dead-parameter and inline-parameter forms
  - the named pNext holder
- **The fix:** route the rebased value through the copy `m = n;`. With that copy, m, lo and hi colour in declaration order.

Declaration orders measured with the copy in place (bytes out):

| order | result |
|---|---|
| m lo hi n | EXACT\* |
| n m lo hi | EXACT\* |
| m n lo hi | EXACT\* |
| m hi lo n | 7 |
| hi lo m n | 15 |
| lo hi m n | 18 |

## Also measured, all flat

I measured about a dozen other spellings and none improved on 15. They include:

- prediction-shaped conditions
- copies inside the search loop, which get propagated away
- m, lo and hi as inline parameters in all 6 orders
- lo hoisted to function entry
- the preceding functions compiled in the same translation unit

The dated section in the notes lists every one with its result.

## Budget

About 50 `match.py` compiles and 5 raw compiles, spent checking for an IR-dump pragma (there is none usable). I did not run the permuter.

## Files written

- `src/matched/sub_0201DB20.c` (new, status EXACT)
- `layout/matched/arm9/pkt_0201DB20.json` (written by `manifest --verify`)
- `docs/notes/sub_0201DB20.c.txt` (a dated section appended)
- this report

Scratch files are in `/tmp/aletheia_laneF2/w`.

## Suggestion for the integrator

This lever is probably worth its own idiom file, something like "an arithmetic loop-carried definition colours the variable last; a copy from a second local restores declaration order". I did not write one because this lane is limited to files for its own target.

## Outside sources

This lane did not consult, clone or download any other decompilation or reconstruction. The work used only the image, `match.py` output, and aletheia's own docs, notes and idioms. The CMap field names (ccodeBegin, pNext, mapInfo and the rest) were already in this function's notes, from wave 15. The lever was found only by compiling reduced versions of the function.
