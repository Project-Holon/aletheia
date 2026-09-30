# Lane U54 — ov009 big DWC partials: the object listing is the fastest route, and it has a method

Rows in slice `scratch/a2/slices/u54.txt`: `0x02163628`, `0x0217AB78`, `0x0216D57C`,
`0x021702A0`, `0x0219091C`. This note only records what changes method for the *other*
big ov009 DWC rows, so it is short on purpose.

## The archive member's `.text` is the image, byte for byte

`sdkobj <addr> --region ov009` prints, for each of these rows, a full instruction listing of
the defining object (`sdk/TwlDWC/lib/ARM9-TS/Rom/libdwcmatch.TWL.HYB.a` /
`libdwcauth.TWL.HYB.a`) annotated against the image, and the header line says
`bytes 0 concrete mismatches of 2845 concrete bytes`. Every row is `= ` (identical) or `~`
(relocation bits only). So for these rows a transcription is not a search: the listing *is*
the target, and `sdkobj` additionally gives the DWARF locals with their allocated registers
and the frame map the C cannot supply.

## Resolve the literal pool before writing anything

Every global the body touches is reached through a pooled address, and the pool is the last
~0x60 bytes of the function (`0x0217B788..0x0217B7E4` for `DWCi_Netcheck_Thread`). A one-page
script that walks the listing, resolves each `ldr rX,[pc,#imm]` to its pool word, and prints
the pool in address order recovers the whole global/constant usage in first-use order —
including the constants that are *not* what they look like: the first-stage timeout is
`40000/2` (pooled 40000, `lsr #1` at use) and the interval clamp is 180000, while 20000,
302, -23302 and 120000 are pooled raw. Guessing those spellings costs whole compile rounds.
Lane copy kept at `scratch/u54/anno.py` (`python scratch/u54/anno.py` → `netcheck.anno.txt`).

## Frame and stack map come from the DWARF, not from the previous body

For 0x0217AB78 the object frame is `0x290` and the DWARF locals sit at `[sp+8]`, `[sp+20]`,
`[sp+24]`, `[sp+38]`, `[sp+cc]`; the frame is exactly `0x38 + 0x94 (calinfo) + 0x1c4
(authresult) = 0x290`, i.e. DWCAuthResult is 452 bytes. Getting the buffer sizes from the
DWARF is what reproduces the frame; the paused bodies all had a `sub sp` far too small
(`0x90`/`0x160`-class), which by itself guarantees every subsequent instruction is
misaligned.

## What is left on these rows is register colouring, not structure

After a full transcription of 0x0217AB78 the push set, the frame, the call sequence and the
exits all line up (3400 bytes compiled against 3184, was 1696); the first divergence is
`+000C` image `mov r7, #0` | ours `mov r6, #0` — the three zero-initialised buffer pointers
(`data r7`, `url r8`, `wait sb` per the DWARF) colour differently, and everything after
shifts with them. That is the same class as the `021B87F0`/`021C84BC` exchange the wave
already recorded as unclosable from C: do not re-spell the body a third time hoping for the
colouring, and do not sweep pins (every row here is a 4.0.0.1025 stamp, and the U21-U30
correction says body-blocked, not compiler-blocked).
