# Wave 21, lane F3: 0x0209128C is EXACT under dsi/1.1p1

0x0209128C is now filed as `src/matched/func_0209128C.c` in packet `pkt_02091284`. It
builds under the pinned `dsi/1.1p1 -O4,p` and needs no front-end pin.

- `match.py one`: EXACT, 28 bytes. The ABS32 to `g_02153B88` resolves as `sole-ref`.
- `manifest --verify --shard pkt_02091284`, first run: 2 entries EXACT, 1 rewritten.
- Second run: 2 entries EXACT, 0 rewritten.
- `src/pending/func_0209128C.c` has been removed.

## The source

```c
void func_0209128C(int x)
{
    u8 v;
    if (x && x) { v = 1; } else { v = 0; }
    g_02153B88 = v;
}
```

## How it was found

I scanned the arm9 listings for this sequence: a `cmp` or `tst`, then a predicated `mov`,
then the opposite predicated `mov` to the same register. I kept only functions whose shard
records `dsi/1.1p1`, which gave 116 of them. 1.1p1 keeps both predicates in three shapes:

1. **The destination is also a compare operand.**
   - Addresses: 0x0204C3A8, 0x02050934, 0x02096E04.
   - Also 0x02036F8C in func_02036F24, `idx = (b == 0) ? 1 : 0`, which has an instruction
     scheduled between the two movs.
2. **The condition is a `tst`.** Addresses: 0x020921E0, 0x02070434, 0x02044740.
3. **The condition is an `&&` chain.** For example, func_02037700 at 0x0203772C:
   `if (c->f64 != 0 && c->f6c != 0) flag = 1;`.

1.1p1 drops the first predicate only in one case: a single `cmp rX, #0` whose destination is a
different register. Examples are 0x02036ED4, 0x0203FA60, 0x02097194, and this function.

Probes on this function confirmed both levers:

- A `tst` condition (`x & 1`, `x & 0x80000000`) keeps `movne r1, #1`. The `tst` itself is the
  wrong instruction, so these probes are 2 or 3 bytes out.
- A two-term chain whose second test is redundant is byte-exact. Three spellings reach EXACT:
  `x != 0 && x != 0`, `x || x` and `x && x`. A fourth also does: an inline `on(x)` that returns
  `x != 0`, joined `&& x`.

The short-circuit if-conversion predicates both arms. The duplicate test is folded after that
point, so only one `cmp r0, #0` is left.

The lever only works in an if/else statement:

- The ternary `(x && x) ? 1 : 0`, `g = x && x` and the default-then-override form
  (`flag = 0; if (...) flag = 1`) all stay 1 out.
- A condition that folds early stays 1 out: `&g != 0` and `x == x`.

## Other measurements, all still 1 out

- Second-parameter ideas: a dead `r1` parameter, and `v` as the parameter itself.
- Dead stores to `x` or `y` inside an arm.
- Masks that fold back to `x`: `x & ~0`, `x | 0`, `x >> 0`, `x & 0xffffffff`.

The full table, with bytes out for all 31 spellings, is in `docs/notes/func_0209128C.c.txt`.

## For the integrator

- **Pins table:** `docs/FRONTEND-PINS.md` row 45 still lists `src/pending/func_0209128C.c`
  under `../2.0/sp2`. That row is stale, because the function is now 1.1p1 EXACT. The file is
  outside this lane's write set.
- **HANDOFF:** `docs/HANDOFF.md` lines 210 and 285 describe 0x0209128C as open or 1 out, so
  they need updating too.
- **Other 1.1p1 near misses:** the same lever may apply wherever 1.1p1 drops the first
  predicate of a two-armed constant select. This could include the reverse of the one-byte tell
  used to pin `func_02063F4C`, whose moveq/movne pair differs only there, and is worth checking
  under 1.1p1 before trusting that pin.
- **Idiom note:** the finding is idiom-worthy. A suggested slug is
  `a-both-arms-predicated-constant-select-is-a-two-term-and-chain`. No idiom file was written,
  because this lane was limited to its target's files.

## Budget and files

About 34 `match.py one` compiles and 2 manifest runs. Scratch files are in
/tmp/aletheia_laneF3; the old pending source is backed up there as `pending_backup.c`.

Files written:

- `src/matched/func_0209128C.c`: new
- `src/pending/func_0209128C.c`: removed
- `layout/matched/arm9/pkt_02091284.json`: written by manifest --verify
- `docs/notes/func_0209128C.c.txt`: a dated section appended
- this report
