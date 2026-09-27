# Runtime lane: hand-written ARM9 runtime.a assembly

Form: the existing `asm void func(void) { ... }` precedent in src/matched
(func_02091220.c, func_021B62A8.c), verified with `python tools/match.py one
--src <file> --func <name> --addr <addr> --cc 1.1p1 --arm`. No tool changes
needed: `one` compares exactly the compiled function's byte count against the
target address regardless of whether disasm.py has a function label there,
so each entry verifies independently. mwccarm's legacy ARM asm dialect needed
translation from capstone's disassembly syntax: standalone `lsl/lsr/asr`
become `mov{cond}{s} rd, rn, lsl rm`; cond+S order is `<op><cond><s>` (not
`<op><s><cond>`); `mrs/msr` use `cpsr`/`cpsr_flg`, not `apsr`; `push`/`pop`
are unsupported, use `stmdb sp!, {...}` / `ldmia sp!, {...}`.

Files (scratchpad/runtime/, not committed):
- converters.c: `_s32_to_float _u32_to_float _f2s _f2u _d2s _d2u
  _s32_to_double _u32_to_double _f2d` (9 rows, 728 bytes). All EXACT.
- compares.c: `__fcmp_1..4 __dcmp_1..6` (10 rows, 1284 bytes), APSR-return
  functions. All EXACT.
- misc.c: `_ll_mul_shl` (ll_mul falls through into ll_shl, one file per the
  grouping rule) and `_runtime_null_stub` (2 rows, 84 bytes). All EXACT.

21 of 34 rows reproduced and verified EXACT: 2096 bytes.

Not done (13 rows, ~6868 bytes), left for a follow-up pass: the
interconnected clusters that share tails/branches per the layout header --
`_ll_divmod_entry_signed/_body/_entry_flag0/_entry_flag1` (512B),
`_s32_div_f/_div_by_zero_check/_u32_div_not_0_f` (~1008B, div_by_zero_check
falls through, cannot stand alone), `_double_arith_body` (412B), `__fmul`
(480B), `__fsub`+`__fadd` (fadd branches into fsub's interior, 1204B),
`__dadd_dsub` (+ weak `_double_arith_prelude`, 944B), `__dmul` (+264B
normalisation table, 1128B), `__fdiv` (952B), `__ddiv` (1344B). These need
more transcription time; no tool blocker, same verified form applies (fdiv's
"data inside the preceding routine" tell needs no special handling either --
the pc-relative instruction's bytes don't depend on what data is really
there).

For the integrator: count the 2096 verified bytes as reproduced assembly,
reported separately from the C-match percentage; the remaining 6868 bytes of
layout/runtime_arm9.txt stay in their current (non-C, unreproduced) state
until a follow-up lane finishes the interconnected clusters. Manifest/shard
entries and final file placement under src/ are the integrator's call.
