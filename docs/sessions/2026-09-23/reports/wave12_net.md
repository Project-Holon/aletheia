# Wave 12: net_system.c, net_handle.c, gf_standard.c

7 of 9 targets closed EXACT. Every one is filed in src/matched and gated with `manifest --verify --shard`. Nothing was committed.

| addr | bytes | family | verdict | file | shard |
|---|---|---|---|---|---|
| 0x020394C0 | 28 | net_system | EXACT | src/matched/func_020394C0.c | pkt_020394C0 |
| 0x02037680 | 128 | net_system | EXACT | src/matched/func_02037680.c | pkt_02037478 |
| 0x02037478 | 520 | net_system | EXACT | src/matched/func_02037478.c | pkt_02037478 |
| 0x02038DF0 | 608 | net_system | EXACT | src/matched/func_02038DF0.c | pkt_02038DF0 |
| 0x0203A020 | 248 | net_handle | DIFF, 11 out | note appended, docs/notes/pkt_02039D94.c.txt | - |
| 0x02039D94 | 652 | net_handle | EXACT | src/matched/func_02039D94.c | pkt_02039D94 |
| 0x0203F258 | 164 | gf_standard | EXACT | src/matched/func_0203F258.c | pkt_0203F258 |
| 0x0203F7C4 | 304 | gf_standard | EXACT | src/matched/func_0203F7C4.c | pkt_0203F7C4 |
| 0x0203F0A8 | 340 | gf_standard | DIFF, 16 out | note appended, docs/notes/func_0203F0A8.c.txt | - |

All seven closures compile under the default compiler, dsi/1.1p1, with -O4,p and ARM. None needs a compiler pin.

## What closed each function
Most of these fixes were wrong declarations, which matches the wave 10/11 lessons.
- **func_0203640C always takes 3 arguments.** The "2-argument sites" in func_02037680 and in func_02037478's first loop pass the slot stride f1E0 as the header length. The r2 value is loaded deliberately, not left over from the mla. This fix alone closed func_02037680. func_02037478 also needed the loop index declared before n1/n2/n3; without that, n1 and i swap r7/r8.
- **func_02038DF0** was written from scratch because the old note kept no source. The key change was writing the func_020364D4 chunk call in both arms of the `func_0203A804(h)` test. The compiler then hoists the shared argument setup and sinks the call, which reproduces the image's `mov r3,r2 / b / ldr r3,[sp,#4]` diamond. Written as a ternary it is 8 bytes short. The fifth parameter `n` must be u32. Two permuter suggestions were needed: `h` as u32, and declaration order (len, sv, p, h, cnt). func_02036540's result is narrowed through a u16 local.
- **func_02039D94**:
  - The owner callbacks at g+0x14 and g+0x10 take func_0203D650()'s result as their argument, which is why the image calls through r1.
  - Phases 2 and 4 reuse the entry pointer `e` for the own entry; there is no separate `own` local.
- **func_0203F258**: the output record is three u64s `{x, mul=0x5D588B656C078965, add=0x269EC3}` of a 64-bit LCG, not six u32s.
- **func_0203F7C4**: the sign test is `cross = f.x + f.y + f.z` (the sum of all three components). The note's two static inline helpers are still needed.
- **func_020394C0**: `return func_020366A8(g_021469D0 + 0xCC);` was exact on the first try.

## Still DIFF
- **0x0203A020** (11 bytes out): the store `mov r3,#1 ... strb r3,[r5,#0xd]` lands in the wrong place.
  - The goto-free form, with wrapping ifs, gives the same 11 bytes; it is recorded as the best source.
  - Making the owner record non-volatile is worse (17 out), because the two loads in the zero arm reorder.
  - The store's position did not change under any spelling tried. That includes a comma expression in every argument position, a fourth argument of 1, a key pointer, a volatile store, inline helpers, and a reused parameter. Every other compiler build either gives the same 11/17 or a different size.
  - The residue is the prepass schedule of the store, not its register.
  - Permuter: anneal, 2000 compiles, best `DIFF asm=205 bytes-out=11 size=248/248`.
- **0x0203F0A8** (16 bytes out): the addressing-mode residue is unchanged. Its note says not to re-run the permuter, so I tried three new readings of the y expression by hand: 16, 16 and 57 bytes out. The note now suggests trying a different declared type for the state block next.

## Evidence notes
- func_0203A804 resolves as sole-ref/code.
- func_0203A7EC resolves as `sdk`. The SDK table's name for it, DWC_IsValidFriendData, is probably a signature false match; the address itself is right.
- func_02036B4C resolves as sole-ref.
- From layout/symbols_sdk.json: 0x02082D44 is MI_CpuCopy8 and 0x02087C6C is OS_GetMacAddress.

## Integrator: seed
None. 0x020394C0 is already in layout/function_starts.txt (line 383). No EXACT* results.

## Family headers updated
- **net_system.h**: corrected the func_0203640C arity entry, which the old header got wrong (it is always 3 arguments; the header is a {buffer, length} ring header). Also marked 02037478, 02037680 and 020394C0 exact, and added func_02038DF0 with the NetRing and NetReasm structs.
- **net_handle.h**: the callbacks are now typed `u32 (*)(u32)`. Updated the func_02039D94 status and added the findings for func_0203A020.
- **gf_standard.h**: added struct Lcg64 for func_0203F258 and updated the func_0203F7C4 status.

Notes appended: pkt_02037288_wave25, pkt_02038DF0, pkt_02039D94 (DIFF section for 0203A020), pkt_0203F258, func_0203F7C4, func_0203F0A8 (DIFF section).
