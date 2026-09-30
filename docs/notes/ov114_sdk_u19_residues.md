# ov114 SDK wave, lane U19 — residue report (16 rows, all still DIFF)

Every row compiled with `tools/match.py one ... --region ov114 --arm --lang c99`.

## Pin check (evidence-backed, permitted)

`--cc` swept over all nine `dsi/` trees on the three closest rows
(021C98E0, 021C9B64, 021CB764):

| tree | 021C98E0 | 021C9B64 | 021CB764 (p2 source) |
|---|---|---|---|
| 1.1, 1.1p1, 1.2, 1.2p1, 1.2p2, 1.3, 1.3p1 | 4 B | 6 B | 24 B |
| 1.6sp1, 1.6sp2 | 4 B | 24 B | 24 B |

So `1.2` (byte-exact for 021C7A74) and `1.1p1` are byte-identical on this slice and
1.6sp* is a regression. Flag check on 021C98E0: `-O3,p` gives 244 bytes / 133 B
(regression), `-O4,p` is right. The compiler/flag axis is exhausted; all 16 residues are
body-shape or backend allocator order.

## Root cause shared by the near misses

Rows 021C98E0, 021C9B64, 021CB764, 021CB3B4 and 021BBA14 all differ by a **descending vs
ascending hand-out of temporary registers**: our compile assigns the first-created
temporary the *higher* free register, the object gives it the *lower* one. Same
instruction multiset, same size, no source spelling tried (declaration order,
initialiser form, `register`, extra named pointer, single vs split expression, struct
copy vs explicit 2-byte loop) moves it.

## Per row

| addr | fn | bytes | concrete diff | best shape found | first image-only instruction | first ours-only instruction |
|---|---|---|---|---|---|---|
| 021BACFC | NHTTPi_setReqQueue | 152/152 | 17 | parked | `ldr r2, [r6, #4]` (id reload) | `mvn r1, #0` |
| 021BBA14 | NHTTPi_CancelRequestAsync | 148 (target 152) | 66 | parked | `ldeq r0, [r6, #0xc]` | `ldreq r1, [r6, #0xc]` |
| 021CA5E4 | ASN1Skip | 180 (target 184) | 80 | parked | `ldr r4, [r0]` | `ldr lr, [r0]` |
| 021CB3B4 | CRYPTOi__BN_add_word | 224/224 | 46 (**was 48**) | `scratch/u19/v3_021CB3B4.c` | `mov r2, #0` (zero hoisted to function head) | `moveq r0, r4` |
| 021C98E0 | DWCi_EncValidateKey | 240/240 | 4 | parked | `ldrb r0, [r8, #1]` | `ldrb r1, [r8, #1]` |
| 021C60C8 | DWCi_Ndi_encodeBASE64 | 248/248 | 95 | parked | `add r8, r8, r0` | `add r7, r7, #4` |
| 021BBBC8 | NHTTPi_getHeaderValue | 292 (target 296) | 186 | parked | `addlt sp, sp, #0xc` | `addlt sp, sp, #0xc` (block shifted) |
| 021CB764 | CRYPTOi__BN_usub | 332/332 | 24 (**was 51**) | `scratch/u19/p2_021CB764.c` | `ldr r5, [r6, #4]` (b->top) | `ldr r4, [r6, #4]` |
| 021CC674 | CRYPTOi__BN_gen_exp_string | 408/408 | 43 | parked | `push {r3, ... r10, lr}` | `push {r4, ... sl, lr}` (no r3/fp slot) |
| 021BC740 | NHTTPi_RecvProxyConnectHeader | 484/484 | 142 | parked | `str r0, [sp, #0xc]` | `mov sl, r0` |
| 021C9B64 | DWCi_EncSessionCompleteCallback | 568/568 | 6 | parked | `ldr r3, [pc, #0x19c]` (src ptr) | `ldr ip, [pc, #0x19c]` |
| 021C7644 | DWCi_Ndi_response_list | 724 (target 640) | 507 | parked | pool offset `#0x244` | `#0x298` (source is 84 B too long) |
| 021C68BC | req_callback | 664 (target 648) | 513 | parked | `mov r8, r0` | `mov r7, r0` (source 16 B too long) |
| 021BD7E8 | NHTTPi_ThreadSendProc | 896/896 | 46 | parked | `mov r6, r0` (sysInfo_p) | `mov r7, r0` |
| 021C3218 | ghiPostStateDoPosting | 628 (target 1564) | 537 | parked | `push {r4, ... r10, lr}` | `push {r3, r4, r5, r6, r7, lr}` (stub; ~936 B of body missing) |
| 021CD210 | CRYPTOi__BN_mod_exp_mont | 1764 (target 1908) | 1505 | parked | `push {r4, ... r10, fp, lr}` | `push {r3, r4, ... fp, lr}` |

## Two notes that matter for the next pass

1. **`tools/sdkobj.py` reports "(no DWARF subprogram ...)" for every `crypto_bobj1.o`
   row**: 021CB3B4, 021CB764, 021CC674, 021CD210. There is no recoverable register
   assignment for those four — they can only be closed by matching the source text of
   OpenSSL's `BN_add_word` / `BN_usub` / `BN_mod_exp_mont` bodies, not by DWARF.
2. **021CB3B4's whole residue is one hoisted zero.** The object materialises `mov r2, #0`
   at +0010, before the `w == 0` early return, and keeps that register live across the
   `BN_sub_word` call so `a->neg = 0` and `a->top = 0` both store r2; ours re-materialises
   the zero twice (r2 at +0030, r0 at +005C), which in turn pushes the `a->d` temporary
   from r1 to r2 and `l` from r0 to r1. Fixing the hoist fixes all 46 bytes at once.
   `l = w + a->d[i]` (single expression, `scratch/u19/v3_021CB3B4.c`) removes the last
   loop-body mismatch but is neutral on the hoist.
3. **021CB764 exact spelling found for the guards.** `long i` plus hoisting the guard to
   `if (a->top < b->top) return 0;` *before* `max = a->top; min = b->top;`
   (`scratch/u19/p2_021CB764.c`) drops 51 -> 24 B: the loads then come out in the
   object's order (`b->top` first) and only the `r4`/`r5` binding of `max`/`min` is
   reversed. `int i` with the same guard is 51 B.
