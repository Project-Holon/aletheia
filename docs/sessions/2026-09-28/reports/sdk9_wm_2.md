# sdk9_wm_2 report (libwm second pass, arm9)

Territory: WM_StepDataSharing, WmInitCore. dacktimer_alarmhandler (0x02061C30) not attempted,
as instructed (needs a 3.0.0.139 build). All C written from sdkobj/match.py output only; no
file under sdk/ opened.

## Filed (EXACT, manifest --verify twice, second pass 0 rewritten)

| address | symbol (object) | bytes | verdict |
| --- | --- | --- | --- |
| 0x020902D8 | WM_StepDataSharing (wm_ds.o) | 816 | EXACT |

- src/matched/arm9_sdk/func_020902D8.c
- layout/matched/arm9/pkt_020902D8.json

The one lever was the aid argument on the parent path: `WmDataSharingReceiveData(dsInfo, 0, ...)`
with a literal 0 (the aid is known zero there). Passing `aid` keeps it live in fp and stops
the constant 1 from being pooled into fp, which moves every callee-saved register. Also:
`sendData` is `const u16 *` (DWARF drops const), and the index wraps are `% 4u` (signed `% 4`
emits the asr/ror sequence).

## Pending (src/pending/arm9_sdk/func_0208E038.c, no shard)

| address | symbol (object) | bytes | verdict |
| --- | --- | --- | --- |
| 0x0208E038 | WmInitCore (wm_system.o, static) | 640 | DIFF as plain C; EXACT with a zero-byte asm statement, unfiled |

I continued the first pass's file (its own object-derived work) and only changed the header
and added one line.

Finding: under 1.1p1 -O4,p the b-to-bottom-test loop form, with the constant first test not
folded, comes out whenever the function contains inline asm. That means an `asm {}` statement,
or an inlined static helper whose body holds one. I measured this on a minimal loop and on
the full function. Nothing else I tried produces it:
- loop spellings: for, while, goto with an explicit test label, const bound, sizeof bound,
  unsigned bound, variable init, inline-parameter init, volatile store, volatile global,
  register, varargs, static local, function-pointer call, address-taken local, setjmp.
- opt pragmas: opt_unroll_loops, opt_strength_reduction, opt_loop_invariants,
  opt_propagation, opt_dead_code, opt_lifetimes, opt_common_subs, peephole, scheduling,
  optimization_level 3.
- an empty `asm {}`, `asm("")`, `__asm {}`, an uncalled inline asm helper, and asm under
  `if (0)` do not trigger it.

`asm { .align 4 }` right after `e = OS_DisableInterrupts();` emits no bytes, and with it the
whole function is byte-identical (640/640 under `match.py one`). I left it unfiled because the
statement emits no instruction, so it meets neither condition of the brief's asm-evidence
rule. The object evidence is behavioural: in this compiler, the unrotated loops only come
from the inline-asm optimisation mode. The original probably inlined a header helper that
holds asm and emits nothing here, but I cannot name it without the source. The integrator
needs to rule on this; if accepted, filing is a copy to src/matched plus a one-entry shard.
Permuter not run (the loop shape has been explained).

## Files written

- src/matched/arm9_sdk/func_020902D8.c
- layout/matched/arm9/pkt_020902D8.json
- src/pending/arm9_sdk/func_0208E038.c (header rewritten, asm statement added)
- this report. Scratch in scratchpad/sdk9_wm_2/.

## Catalog / DWARF disagreements

None new.

## Next pass

- Ruling on WmInitCore's zero-byte asm statement. The same tell (a b-to-bottom-test counted
  loop with a constant start under -O4,p) should be checked on other open SDK rows; it may
  be an idiom worth indexing.
- dacktimer_alarmhandler waits on a 3.0.0.139 compiler build.
