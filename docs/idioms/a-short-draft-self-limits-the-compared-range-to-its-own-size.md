# A draft that compiles short self-limits the compared range to its own size

summary: `match.py one` compares exactly `len(fb.data)` bytes — the *compiled*
function's length — at the target address, not the original's listed extent.
`target_bytes(addr, n)` is called with `n = len(fb.data)` (tools/match.py
~5152-5155). So a skeleton draft whose body is a fraction of the real function
silently compares only that fraction, and the range printed in the header
(`021702A0..021705F4`) is an artefact of the draft, not evidence of a mid-body
`func_` label cutting the original. The real extent is still reported separately
as `listing extent for the original: N bytes`, and if the short prefix *did*
match the verdict would carry the trailing `*` (`EXACT*`/`MATCH*`) with the note
`listing says the original is N bytes, compiled M`.

Found in: `src/pending/ov_sdk/ov009_func_021702A0.c` (ov009, 0x021702A0,
`DWCi_ProcessRecvMatchCommand`, 4396 bytes / 1099 instructions). Its header
diagnosed the 852-byte comparison as a mid-function `func_` label cutting the
extent (per `a-bl-target-inside-a-function-cuts-its-extent.md`); the listing
actually runs to 0x021713CC and the disassembled 0x021705F4 is live code
(`ldr r0, [r4]`), not a label. 852 is just what the skeleton compiles to.

Tell: `compiled N bytes` in the `match.py one` output, and the header range
`addr..addr+N`, with `N` well under the `listing extent for the original`. Do
not read the small range as a gift: there is no way to compare a *smaller*
window than the body you write. The only route to a byte check of the whole
function is a body that compiles to the whole function's length; a shorter body
can at best be `EXACT*`/`MATCH*` over its prefix, and `manifest --verify` treats
any `*` as unclean. For a multi-kilobyte switch dispatcher this means the lane's
work is transcription of the full 4396 bytes, not of a nominal prefix.
