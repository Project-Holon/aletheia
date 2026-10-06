/*
 * function: func_021F56BC
 * address:  0x021F56BC
 * packet:   pkt_ov112_021F56BC
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * note (2026-10-04, wave D3 lane 03): first complete structural draft, not tuned.
 *   Listing extent 021F56BC..021F5EDC (2080 bytes), frame 0x254, mid pool at 021F5A24
 *   (0x04000444, 02148D8C/98/A4, 021F8310/1C/04, 02148B98, 0xFFFFF000, 0xFFFA0000,
 *   02148B54, 0x04000470, 020A1B38 sin/cos table, 0x0400046C) and tail pool 021F5ED0.
 *   Shape: G3 setup (push, mode 0, store 0, mode 3, identity, mode 2); camera pick by
 *   p->f8 bit 0; outer loop i < p[0] over p[1][i] objects, skip null or (fEC >> 2) & 1;
 *   per object a 16-byte pose rec at sp+0x244 filled by kind 0/1/2 of
 *   obj+0x28 -> [0x1c] -> f4; translation/rotation/scale writes; func_021F65EC;
 *   polygon attr word built from bitfields at obj+0x90; inner loop j over parts of
 *   p->f6C->f4[rec.id]; second pose rec at sp+0x234; two func_021F5EDC calls;
 *   innermost k < 8 over bytes ent[0x30+k] != 0xFF with s64 fixed point math and
 *   an indirect call through p->fF8.
 *   Known hard parts: the compiler derives small constants from register-held I/O
 *   addresses (lsrs r1, r0, #0x13 = 0x80 from 0x04000470; lsrs #0xe = 0x1000 from
 *   0x0400046C; r0 >> 0x12 = 0x100), the float rounding idiom
 *   (v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f) then _ffix, and the
 *   many spilled loop-invariant offsets at sp+0x80..0xAC (0x80 constants and
 *   field offsets r5-8, r5-4 with r5 = 0x10C).
 *   The innermost k-loop math is an approximation of the listing (021F5BD4..021F5E8C),
 *   re-derive it from the listing before tuning.
 *   Verdict of this draft: DIFF, compiled 1680 bytes vs 2080, 1623 bytes differ, 52 of 55
 *   relocations resolved. Prologue already differs (push r3 extra, frame 0x198 vs 0x254):
 *   the original keeps more stack locals (spilled invariants at sp+0x80..0xAC, s64 halves
 *   at sp+0x68..0x74, sub-pose rec at sp+0x234, 0x5C-byte source records).
 *   Siblings: func_021F5EDC (callee, 13 args, see 021F5B6A..021F5BCC for the stack layout).
 *
 * note (2026-10-05, wave D4 lane 06): p->f8 bit 0 is now read through a one-bit bitfield
 *   (Bits.b0): the camera pick now gives the original lsls #0x1f; lsrs #0x1f test (1623 -> 1611
 *   bytes differ, compiled 1684 vs 2080).  Still open: the frame (0x254 vs 0x198, push without
 *   r3), the zero local stored at [sp] at entry, the spilled invariants, and the innermost k-loop
 *   which still needs re-deriving from the listing (021F5BD4..021F5E8C).
 *
 * note (2026-10-05, wave D5 lane 06): body rewritten from a fresh reading of the listing
 *   (the code after the mid pool needs `show --addr 0x021F5A5C --size 0x480 --thumb`, the
 *   default show desyncs at 021F5A44).  Fixes: r4 is obj for the whole loop, so the j/k loops
 *   read obj+0x6C/0x68/0x20/0x24/0xF8, func_021F5EDC takes obj (not p) and &cb.z (sp+0xB8,
 *   zeroed per object), and the indirect call goes through the second parameter `arg`
 *   (`arg((u8)pt->f4, &cb.pos, obj->fF8)`); a 0x3C-byte callback record at sp+0xB4 (w out
 *   word, z, pos with y negated, x2/y2 scaled by obj->fD4/16 and fD8/16, z, obj+0xD4 vec,
 *   obj+0x100 vec, obj->fFC, ang + (pt->f10 << 11)); on pt->f4 == 5 the result goes to
 *   obj+0x100/0x104/0x108.  k loop: two rotations (part by pose.rot + sub.rot scaled by the
 *   pose*sub scale, then the table entry (x, z at +2/+4) plus pose.dx/dz by pose.rot scaled by
 *   pose.sx/sy), operand order (s64)vec * scale.  Else-branch: a local 4x4 matrix filled with
 *   constants at sp+0x114, func_0207B5C0(&d_02148B98, &m4), func_0207BE14(&m4, &d_02148B54,
 *   &m4), second func_021F660C uses that matrix.  Sub-pose kind 0 leaves dz unset.  obj skip
 *   test reads p[1][i] twice and bit 2 of obj->fEC as a bitfield; obj+0x90 and obj+0x68 are
 *   loop-level pointer locals (sp+0x5C, sp+0x50).  Result: compiled 1996 vs 2080 (was 1684),
 *   frame 0x248 vs 0x254, prologue and the obj test now line up modulo slot numbers.
 *   Open: the zero stored at [sp] at entry (push without r3 in the original), the i slot
 *   (0x5C vs 0x58), mid-pool placement (original after the attr word at 021F5A20), LoadPose
 *   register shape (original keeps src = obj+0x28 in r0), the eight spilled 0x800 rounding
 *   words at sp+0x80..0x94/0x9C/0xA0 and the 0x100/0x10C offsets at sp+0x98/0xA4..0xAC.
 * note (2026-10-05, wave D6 lane 01): three fixes from a fresh reading of the head and the pose loader.
 *   (1) func_0207D7C4 takes a fifth argument (NULL, as in the matched callers): the zero stored at [sp]
 *   at entry is that stack argument, written once before the camera-pick branch. The prologue now
 *   matches to 021F56F8 apart from the frame size. (2) LoadPose is a switch on the u16 kind with a
 *   compare chain (beq 0, cmp 1, cmp 2, b out), and the id is a u16 read (ldrh) through a
 *   {u16 id; u16 pad; s16 dx; s16 dz} source record. (3) obj+0x90, obj+0x68 and obj+0x28 come from
 *   static inline accessors (ObjAttr, ObjSrcs, ObjAnim): the parameter copy gives the original
 *   `adds r0,r4,#0; str [sp,#K]; adds r0,#0x90; str [sp,#K]` double store for srcs and keeps src =
 *   obj+0x28 in r0 for the kind load (`ldr r3,[r0,#0x1c]`). Compiled 2008 vs 2080 (was 1996).
 *   Open: frame 0x24C vs 0x254 (8 bytes of locals missing, every sp offset is 8 low), attr (obj+0x90)
 *   stays in r5 where the original spills it to sp+0x5C, the zero/kind registers in the obj head
 *   (original zero r2, kind r3; ours zero r3, kind r1), and everything after 021F57BC not re-checked.
 * note (2026-10-05, wave D7 lane 01): read only, no new build. The original spills attr (obj+0x90) to
 *   sp+0x5C and reloads it three times for the attr word (021F59EE, 021F59F0, 021F5A00); r5 is a
 *   short-lived temp there (0x10C offset at 021F59A6). So the original has more long-lived values than
 *   ours; the 8 missing frame bytes are likely two more spilled locals. Also: the callback arg is
 *   ov112 func_021F546C (mode = (u8)pt->f4, in = &cb.pos, p = obj->fF8), see that draft for the
 *   0x38-byte slot layout of obj->fF8.
 * note (2026-10-05, wave D8 lane 01): three local shape fixes from the listing at 021F58C4..021F591E.
 *   (1) The pos and (ox, oy, 0) MTX_TRANS writes are a G3_Translate(x, y, z) static inline: the
 *   original loads all three values before the three stores (ldr r3,[sp,#0x230]; ldr r2; ldr r1;
 *   str; str; str); 0x0400046C writes are G3_Scale(sx, sy, 0x1000). (2) The flag increment is
 *   `flag++` on the u8 local: the original reloads the spilled zero and does adds/lsls/lsrs, where
 *   `flag = (u8)(flag + 1)` folds to movs #1. (3) The rotation ternary has no inner (u16) cast:
 *   `u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;` truncates once after the join, as in the
 *   original. Compiled 2012 vs 2080 (byte count is not comparable, every later offset shifts).
 *   Still open: frame 0x24C vs 0x254. The original spill area is 8 bytes larger (struct locals start
 *   at sp+0xB4 in the original, sp+0xAC in ours), so the original spills two more values; attr
 *   (obj+0x90) is one of them (sp+0x5C, ours keeps it in r5). G3_Translate(pos) still takes r2/r1/r0
 *   for z/y/x and r3 for the register base, the original r3/r2/r1 and r0. The rounding constant
 *   0x800 is derived from the halfword offset 2 held in r6 (`movs r6,#2; ldrsh r1,[r2,r6]` then
 *   `lsls r2,r6,#0xa`), ours does the same from r7. The k-loop past 021F5A5C was not re-checked.
 * note (2026-10-05, wave D9 lane 04): six fixes from a fresh reading of the j/k loops (compiled 2064 vs
 *   2080; on a register-blind instruction diff 94 lines differ, was 210).  (1) obj->f6C has one more
 *   level: the record table is at obj->f6C->f4 (as in matched func_021F5EDC, struct H/E1/E2), both in
 *   the j-loop test and for the entry reads.  (2) The sub-pose uses the same LoadPose switch: kind 0
 *   also zeroes dz, by cross-jumping into the kind 2 tail (listing 021F5AE6 b 021F5B1A).  The entry
 *   te and the part pt are not locals: j*8 and b*0x14 are spilled CSE values and every read is
 *   written inline.  (3) The 0x1D write goes to 0x0400044C (MTX_STORE), not 0x04000450.  (4) Every
 *   fixed-point product is a FxMul(s64 a, s64 b) static inline: it puts the vector in r0:r1 and the
 *   scale in r2:r3 and spills fx/fz with s/c in r5/r6, as in the original.  psx/psy are s64 locals
 *   assigned before the first product (the original sign-extends both before the first _ll_mul).
 *   (5) obj->fEC bit 0 is a one-bit bitfield.  (6) Declaration order `fx, fz, c, s, X, c2, Z, s2`
 *   gives the original registers in both rotations; the attr word is written right-nested
 *   a7 | (0xF0000 | (a4 | (a3 | (a5 | a0 | 0x40000000)))) to get the original OR order.
 *   Still open: frame 0x250 + push r3 vs 0x254. The original spills attr (obj+0x90) to sp+0x5C and
 *   keeps &pos in r7 across the two func_021F660C calls; ours keeps attr in r5 and rematerialises
 *   &pos.  Tried without effect: attr declaration position, block scope, a struct type, a PolyAttr
 *   inline, a Persp inline and a `Vec *pp` local for the 660C calls.  A separate `int w` local (not
 *   cb.w) gives the 0x254 frame but puts w at sp+0xB0, not 0xB4, so it is not the answer.  The k-loop
 *   head schedules the fx/fz loads before `ang` (original: ang first); `ent->parts[k]` inline instead
 *   of `b` is worse.  `j = 0` sits after the first scale product in the original; only an unnatural
 *   split of the sy/sx block reproduces it.
 * note (2026-10-05, wave D9r lane 22): 94 -> 0 instruction lines differ; 5 bytes left (two spill slots).
 *   (1) The 0x040004A8 word is the SDK inline G3_TexImageParam with enum parameter types, as in the
 *   matched sibling arm9 func_02014D2C (same renderer: same matrix calls, Pose switch, TexInfo record
 *   at obj+0x90 with addr/s/t/fmt/pltt0 at 0/0xC/0x10/0x14/0x1C).  With it, attr spills to sp+0x5C and
 *   &pos stays in r7 across the func_021F660C calls; the frame is 0x254 and the push has no r3.
 *   (2) attr, srcs and a new ctrl (obj+0x28) are plain assignments in the order attr, ctrl, srcs (the
 *   accessor inlines are gone; they made no difference once attr spills).  (3) Declaration order
 *   ent, attr, i, j, srcs, k gives the original slots.  (4) for (j = 0; ...) without the early
 *   j = 0 statement: the 0 is shared with the first FxMul high word, as in the original.  (5) ang is an int
 *   (u16 cast at the assignment).  (6) X = te.x; X += pose.dx; (same for Z) gives the te.x-first load
 *   order.  (7) c2 (the cos of pr) is written inline at both uses: the original spills it as a CSE
 *   temp (lowest slot, reload with no copy).  (8) The obj+0x100 write is VEC_Set(v, x2, y2, 0), which
 *   loads y2 before x2.
 *   Residue: the CSE temps j*8 and c2 have swapped slots (original j*8 sp+0x34, c2 sp+0x30; ours the
 *   reverse).  A diagnostic without the j-loop use of ents[j] gives the original order, so the j*8
 *   temp is created later than c2 in ours.  Tried without effect: s2 inline too, c/s inline (worse),
 *   an idx local, operand order of the c2 products, k-loop locals at function scope, a te local in
 *   the k loop, src passed straight to LoadPose, named c2 in any scope (goes to the named slots).
 * note (2026-10-05, wave D9r lane 53): residue unchanged at 5 bytes (j*8 CSE temp at sp+0x30, cos(pr) temp
 *   at sp+0x34; original reverse).  One clean-up: the `one` local (0x1000 for the sub-pose LoadPose) is
 *   gone; LoadPose(&sub, src, 0x1000) gives the same bytes (the 0x1000 reload from sp+0x64 is the
 *   compiler's own hoisted constant).  Tried without effect on the slot pair (each a real compile): a TabEnt
 *   pointer or a u16 h local for the head read; `int id = j` alias at head or in the k loop; the j loop and the
 *   k loop as if/do-while; pose.rot inline (no pr local; same bytes); s2 load moved above the X/Z reads; X/Z
 *   reads as (ents + j)->x, as a Cell() inline, or as byte offsets (j * 8 + 2) in both head and k loop
 *   (byte offsets in the k loop only stop the j*8 CSE and LICM-hoist a second copy); cos(pr) spelled four
 *   other ways (1 + idx, (T + idx)[1], &T[idx][1], idx << 1) and through a Cos() inline; RotX/RotZ inlines and
 *   an FX_MUL-style macro for the second rotation (worse); a `const s16 *sc` pointer for s2/cos (worse);
 *   k-loop declaration order.  The pair stays swapped in every variant, so its order is probably fixed by the
 *   colouring tie-break, not by source position of the two expressions.
 * note (2026-10-05, wave D9r lane 90): residue unchanged at 5 bytes (same slot pair).  Compared with the
 *   matched twin arm9 func_02014D2C line by line and tested new forms, each a real compile.  Same 5 bytes:
 *   outer i loop as the twin's `i = 0; if (n > 0) do { } while (++i < n);`; a typed MAnim/Frame chain
 *   (`((Obj *)obj)->anim->frames[pose.id]`) instead of the raw obj+0x6C casts; the node as a 0x5C-byte
 *   struct array (`&(*nodes)[idx]`, as the twin); a frame-cells pointer local at the head; a named int
 *   node index at the head; SDK FX_SinIdx/FX_CosIdx inlines (int idx, fx16 return) for every table
 *   read; the break test as `if (ent->parts[k] == 0xFF) break; b = ent->parts[k];`; the rotated vector
 *   in vx/vz locals before the two FxMul calls.  Worse: the head index through a NodeIdx() inline
 *   (loses the loop-condition entry pointer, 1056 B); the k loop as a static inline (not inlined,
 *   1832 B); `k < 8 && parts[k] != 0xFF` in the for condition (744 B); X/Z as one expression each
 *   (64 B).  Diagnostics (not candidates): a third use of the cos(pr) temp, X/Z reads moved to the top
 *   of the k loop, and no Z read all keep ours order (j*8 below cos(pr), b*0x14 lowest), so the order
 *   does not follow use count or program position of the k-loop reads.
 * note (2026-10-05, wave D9r lane 107): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp sp+0x34;
 *   original reverse).  New tries, each a real compile: FxMul with int (fx32) parameters as in the twin's
 *   FX_MUL, with s64 or int psx/psy (89 B, worse); cos(pr) as an int-typed value ((int) cast at both uses,
 *   or an int-returning CosI() inline; same 5 B); 5EDC prototype and Ent fields as int, as in the matched
 *   func_021F5EDC, and 660C with its matched const int / u32 parameters (same 5 B); `int b` for the part
 *   byte (same 5 B); s16 (fx16) locals for s2, for c/s, or for all three (508 to 728 B, worse); named c2 in
 *   three placements (430+ B, adds a copy); mixed spellings for the X/Z reads (index for one, byte offset
 *   for the other: 870 B; `(ents + j)->x` for X only: same 5 B).  Diagnostics: `int pr` swaps the pr and
 *   flag slots (0x38/0x3C), so local width moves slot order; an extra k-loop use of ents[j] does not move
 *   j*8 off sp+0x30.  The slot order of the two CSE temps does not follow use count or type.
 * note (2026-10-05, wave D9r lane 124): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  Tested the inline-return-temp idiom (ov125 021D6B40) on every helper in
 *   the j/k loops, each a real compile: LoadPose hand-expanded for sub, and for both pose and sub (output
 *   identical to the draft, byte for byte); RoundF hand-expanded as a plain ternary and with a block-local
 *   `int v` (identical); the two second-rotation FxMul calls hand-expanded with a block-local s64 operand
 *   (identical) or as one expression (2084 B, worse); a Cell() inline returning &ents[j] at all three
 *   uses, head included (1056 B).  So the inlines are transparent here; no inline temp sets this pair.
 *   Also tried: the head .h read as a byte offset (j*8+6: 1040 B) or as (ents + j) cast to char * (same
 *   5 B); an index local for s2/cos(pr) as u32, int (same 5 B) or u16 (483 B).  Diagnostics: `u32 j`
 *   and a branch between the two cos(pr) uses keep ours order.
 * note (2026-10-05, wave D9r lane 135): residue unchanged at 5 bytes (j*8 temp sp+0x30, cos(pr) temp
 *   sp+0x34; original reverse).  New head-of-j-loop forms, each a real compile, all give the same 5 B
 *   (the front end normalises them to one tree): a `Tab *tab` assigned in the loop condition
 *   (`j < (tab = &T[pose.id])->count`) and read at the head as tab->ents[j].h, also through a TabEnt
 *   pointer local taken from tab (te = tab->ents; te[j].h, or te = &tab->ents[j]); entries as a u16/s16
 *   halfword array at all three uses (`((u16 *)ents)[j * 4 + 3]`, x/z at j * 4 + 1 / + 2); getters that
 *   take the already-computed ents (or &T[pose.id]) plus j: EntH(e, j), EntAt(e, j)->h, EntIdx(e, j),
 *   TabEntAt(t, j)->h (head only: same 5 B; also at the X/Z reads: 6 B, add operand swap); src at
 *   function scope.  Worse: a struct copy `TabEnt e = ents[j]` at the head (1100 B); h as an 8-bit
 *   bitfield pair (u16, s16 or u32 fields: 998 to 1056 B, lsls/lsrs instead of and/asr); the u16 head
 *   read only (X/Z left as fields: 1040 B); tab also used at the X/Z reads (1136 B, tab held in a register).
 *   Off the head, also same 5 B: a non-const `s16` table (as in the twin), the table named
 *   FX_SinCosTable_, s2 and the second rotation in a nested block.  Diagnostics: without cos(pr) as a CSE
 *   (second use replaced) j*8 stays at sp+0x30, so it is the cos(pr) temp that lands above j*8; without
 *   the head use j*8 becomes a LICM temp at sp+0x3C (above the narrow pr/flag locals) and cos(pr) drops
 *   to sp+0x30.  No head spelling reached changes the temp order.
 * note (2026-10-05, wave D9r lane 152): residue unchanged at 5 bytes; the file body is unchanged.
 *   New tries, each a real compile.  The slot order of the late group (flag, pr, j*8, cos(pr), b*0x14)
 *   moves with the declared TYPE of j, not with any spelling of the expressions:
 *   - `long j` (or s32/unsigned long): j*8 goes to sp+0x38, above pr (pr 0x34, cos 0x30 correct, b*0x14
 *     0x2c correct): 6 B.  `unsigned int j` keeps ours order (7 B).  The type of i, of the k-loop
 *     locals (long/fx32), of b (int), of u32 (unsigned long), and fx32 struct fields do not move it.
 *   - `long j` plus `int pr` (or long pr): j*8 0x34 and cos 0x30 are correct, but pr and flag swap
 *     (pr 0x3C, flag 0x38): 9 B.  So the original needs u16 pr with j*8 between pr and cos; no type
 *     pair of (j, pr) gives that.
 *   - reusing the first-rotation `c` (or `s` and `c`) for the second rotation: j*8 goes to 0x34, but
 *     the second web of c gets the lowest slot (0x2C, below b*0x14) and the rz product gains a copy
 *     (431 B).  A named s16 c2 also adds the copy and stays at 0x34.
 *   - pose.rot spelled in place of pr in ang, s2, or one/both cos reads: j*8 goes to 0x34, but pr
 *     takes a late slot (0x30) and cos moves to 0x38 (5 to 10 B; split spellings also break the
 *     shared T+idx address).
 *   - same 5 B: cos and sin as a {sin, cos} struct table (cast or extern), five mixed spellings of one
 *     cos read (1 + idx, (T + idx)[1], *(&T[i] + 1), (idx << 1) + 1, (&T[i])[1]), FX_SinIdx/FX_CosIdx
 *     with int or long idx (with long j), pr declared with an initialiser in a block, pr at function
 *     scope reused for the G3 rotation angles (with long j: still 6 B), b assigned after its
 *     declaration, an unreferenced label between the products, byte-offset j * sizeof(TabEnt) reads.
 *   Worse: RotA/RotB inlines taking cos as a parameter (432 B, rz product copy); a `const s16 *sc`
 *   pointer (432 B); a 5EDC prototype with a long j parameter (j itself moves to the late group).
 *   Reading of the pattern: the late slots look like spill temporaries in the order the allocator
 *   spills them (round by round, then by definition order).  cos(pr) is in the first round in every
 *   variant; the original needs it in a later round than pr.  No natural source change found that
 *   does this without moving another slot.
 * note (2026-10-05, wave D9r lane 198): residue unchanged at 5 bytes; the file body is unchanged.  Lane 152's
 *   suggestion (long j or s32 plus a way to push pr back above j*8 with pr still u16) tested as a table; every row a
 *   real compile.  Slots low to high (b*0x14 is 0x2C in every row):
 *   original                     cos 30, j*8 34, pr 38, flag 3C
 *   base (int j)                 j*8 30, cos 34, pr 38, flag 3C: 5 B
 *   long j / unsigned long j     cos 30, pr 34, j*8 38, flag 3C: 6 B (8 B for unsigned long: extra loop-test byte)
 *   unsigned int / size_t j      as base, 7 B (loop-test byte differs)
 *   named `int jo = j * 8;` (head, X and Z read through ((TabEnt *)((char *)ents + jo))), int or u32, any
 *   declaration order of {jo, pr, flag} at function scope (6 orders), jo at function or j-body scope:
 *                                cos 30, pr 34, jo 38, flag 3C: 7 B (the X/Z add operand order also changes)
 *   named jo plus a redundant second `jo = j * 8;` BEFORE the last use (idiom a-redundant-second-assignment...;
 *   after the loadpose, before the 5EDC calls, before the k loop, first or after the break test in the k body):
 *                                jo 30, cos 34, pr 38, flag 3C: 6 B.  A second assignment after the last use
 *                                (after cb.pos or at the end of the k body) is dead and gives the single-assign row.
 *   jo declared long or as a char * / void *: long moves it to a high named slot (22 B); a pointer is the base row.
 *   jo split into jh (head) and jk (k loop): as the double-assign row.
 *   So j*8 only ever lands at one of two places: below cos (temp) or above pr (named, or long-typed); the original
 *   needs the slot between them.  Declaration order and scope of jo, pr and flag never moved any slot.
 *   pr changes with long j: `int`, `long`, `u32` or `unsigned long` pr give j*8 34 and cos 30 (correct) but pr 3C and
 *   flag 38 (5 B differ); flag as u16, s16 (same 5 B), int, u32, long with `flag = (flag + 1) & 0xFF` (1429 to 1462 B);
 *   pr s16 or u8 (740 B); pr at function scope as int (14 to 43 B, pr 0x48).  pr read earlier (at the top of the j
 *   body, 1034 B; before the k loop, 309 B; first statement of the k body or declared with an initialiser before
 *   the break test, 19 B: the load schedule changes), later (just before the s2 read: 1780 B).  pr declared at j
 *   body scope: same as base (5 B) or, with long j, 6 B.
 *   The angle through u16 helpers SinA(u16)/CosA(u16): with pr passed or with pose.rot passed directly, no pr local
 *   used at the reads: same slots as base (5 B) or as long j (6 B).  j as an enum type: 1091 B; signed char j: 91 B.
 *   Diagnostic only: a third pr use does not give a comparable build (frame changes).
 *   Reading: the slot order is a ranking, not a source position: with j*8 a CSE temp it ranks below cos(pr), with
 *   j*8 named (or long) it ranks above pr, and the original has it between.  No natural form found for the middle rank.
 * note (2026-10-05, wave D9r lane S8): residue unchanged at 5 bytes; the file body is unchanged (the earlier
 *   lane left only notes, body identical to HEAD).  Slot facts measured with a Thumb decode of the compiled
 *   bytes (7 real compiles, none repeating a lane 152 or 198 row):
 *   - the compound byte-offset idiom of the sibling 021F546C (`u32 jo = j; jo *= 8;`, head, X and Z read
 *     through (TabEnt *)((char *)ents + jo)): b 2C, cos 30, pr 34, jo 38, flag 3C (7 B).  j*8 is not a named
 *     byte offset: any named local lands above pr, the original has j*8 below pr.
 *   - named locals order by first assignment in the code, not by declaration: with `u16 pr;` declared in the
 *     j body BEFORE jo, pr still lands below jo (pr 34, jo 38).  So declaration order cannot place jo.
 *   - the spilled CSE temps (b*0x14, cos, j*8) always sit below every named local.  The original j*8 (0x34)
 *     is in the temp band, above cos, which is the only pair left swapped.
 *   - statement order tests (second rotation before the first; fz read after the Z read) change the frame
 *     and schedule (836 and 842 B), so they cannot show the pair order.
 *   mwcc source (inspiredrobot/mwcc): Coloring_SelectColors flags a web Spilled in select-stack order and
 *   SpillCode_00531800 (slot assignment, not reconstructed there) runs per retry round; Coloring_SimplifyGraph
 *   picks potential spills by min spill_cost / degree.  Our listing and the original are instruction identical,
 *   so cost and degree of j*8 and cos are equal in both builds; only the web numbering or tie order differs.
 *   Lane 22's diagnostic (no head use of ents[j] gives the original order) fits a numbering reading: the head
 *   use makes j*8 a temp that is created before cos in ours.  No source form that creates cos(pr) before j*8
 *   without moving code was found (cos has no occurrence before the k body in the original listing).
 * note (2026-10-05, final push G2L5, rounds 2 and 3): 16 more real compiles, all DIFF, none better than 5 B.  `u16 j`, `s16 j`
 *   (94/93 B); rx and rz as one expression each with both products (836 B); `long j` with `int pr` at function scope
 *   (18 B), with pr assigned at object level (1794 B), with `u16`/`s16`/`unsigned short` flag (11 B), plus opt_lifetimes
 *   or scheduling off (9 B); head chain through a named `int id = pose.id` (723 B); second rotation rz before rx (652 B);
 *   `Z * cos` operand order (5 B, same).  Also off: opt_unroll_loops, opt_vectorize_loops, opt_findoffsets (5 B).  mwcc
 *   SpillCode.c: spill cost is use count times block weight; earlier lanes' extra-use diagnostics did not move the pair, so
 *   slot order is not cost-driven.  Twin arm9 func_02014D2C re-read: no k-body pr rotation, nothing to borrow.
 * note (pass 2 2026-10-06 P2L09): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Slots low to high of the triple j*8 / cos(pr) / pr (flag 0x3C in all rows unless said):
 *   - `#pragma opt_strength_reduction off`: cos 30, pr 34, j*8 38 (6 B), the same as `long j`.  So strength
 *     reduction is what ranks j*8 below cos.  Under SR off: pose.rot for pr everywhere, pr at j-body or function
 *     scope (3 positions), u16 pr with an int/u32 `pi = pr >> 4` index, `(pr = pose.rot) + sub.rot`: SR-off row
 *     (6 to 7 B); int or u32 pr: cos 30, j*8 34 (correct), flag 38, pr 3C (9 to 10 B); pose.rot in ang only:
 *     pr 30, cos 34, j*8 38 (8 B).  SR off plus opt_loop_invariants off: 1501 B; plus opt_lifetimes off: SR-off row.
 *   - SR on, pose.rot spelled in ang only (pr kept for s2 and both cos reads): pr 30, j*8 34 (correct), cos 38,
 *     5 B.  In that form, same 5 B and same slots: ang before `pr = pose.rot`, pr declared at function scope,
 *     j-body scope or first in the k body, pr assigned right before s2, SinA/CosA(u16) inlines on pr.  Back to
 *     the base order (5 B): int pr, an int `pi = pr >> 4` or `pi = pose.rot >> 4` index, SinA/CosA(pose.rot).
 *     u32 pr 6 B; plus long j 8 B.  pose.rot in rz cos only 653 B, rx cos only 505 B, both cos or s2 only 10 B.
 *   - j*8 written as `(char *)ents + (j << 3)` at all three uses: base slots, 6 B (add operand byte); at the head
 *     only or the k loop only: 1040 B (CSE lost).  opt_loop_invariants plus opt_lifetimes off: 5 B (base).
 *   Four orders of the triple are reachable (j8<cos<pr, cos<pr<j8, pr<j8<cos, cos<j8 with pr above flag); the
 *   original cos<j8<pr<flag was not produced.
 * note (pass 3 2026-10-06 P3L04): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   New regime: the second-rotation cos stored in the first-rotation `c` with `rz += FxMul(X * s2 + Z * c, psy)`
 *   (operand order Z * c removes lane 152's extra copy): 7 B, j*8 0x34 and pr 0x38 now correct, but the c web
 *   takes 0x2C and b*0x14 moves to 0x30 (original b*0x14 0x2C, cos 0x30).  In that regime, same 7 B: s also
 *   reused for s2, s or fx reused for cos, int/u32 b, the assignment inside the rx argument, opt_loop_invariants
 *   off.  Worse: `c * X` (18 B), plus pose.rot in ang (13 B), plus SR off (13 B), plus opt_lifetimes off (546 B),
 *   c at function scope (684 B), c and s2 moved above the X/Z reads (851 B), CosA/SinA(u16) inlines (14 B).
 *   Same 5 B base slots: s reused for s2 only; an int idx index local for s2 only; RotX/RotZ inlines reading the
 *   table; a named TabEnt *e for the k-loop reads; rx/rz as a local struct; c assigned from one read with the other
 *   read inline (either order); opt_strength_reduction_strict on.  Worse: idx local in some cos reads only
 *   (508 B / 9 B), a const s16 *sc pair pointer for one cos read (502/508 B), named c2 with Z * c2 at three
 *   declaration places (14/23/64 B), separate x1/z1/x2/z2 running locals (898 B); SR off plus an `int id = j`
 *   alias at the head or in the k loop gives the SR-off row (6 B).  Reading: a reused variable's second web ranks
 *   below every optimizer temp, a first named web ranks in the named band, so cos in the original is a temp made
 *   after the SR-created j*8 web and before b*0x14; no source form found that delays the cos CSE that way.
 * note (pass 4 2026-10-06 P4L03): residue unchanged at 5 bytes; the body is unchanged.  40 real compiles.
 *   Same 5 B: RotA/RotB inlines with cos as a parameter and `Z * c`; a `const s16 *sc` pair pointer with
 *   `Z * sc[1]` (with or without s2); `s16 sc[2]` with `Z * sc[1]`; rx/rz as `int r[2]` (const or non-const
 *   table); `register` on pr or j.  Long-j row (6 B, flag 3C, j*8 38, pr 34, cos 30): u16 pr reused at
 *   function scope for either G3 angle; s2 read above the X/Z reads (77 B, same slots); the head .h read as
 *   a byte offset `j * 8 + 6` or `(j << 3) + 6` (merged under long j); `u16 pr = 0;` initialisers.  Long j
 *   plus int pr with `pr >>= 4`: 9 B (pr 3C, flag 38); with u16 pr: 10 B (pr 3C, lsrs).  Long j plus int pr
 *   reused for the obj+0xFC G3 angle: 18 B (pr 0x48).  `int sc[2]` for s2/cos: 14 B (the array-to-register
 *   web takes 0x3C above flag).  Worse: `pr / 16` (15 B all reads, 656 B rz only), a {s, c} struct copied
 *   from the table (576 B), one cos read as a char* byte offset (495/504 B: the table load is never merged
 *   after CSE0), opt_propagation off (1898 B), opt_common_subs off (1438 B).  Reading (research in the lane
 *   folder): the global table load is merged only by the first CSE, so cos is always numbered before the SR
 *   j*8 web; without SR on j, j*8 is numbered at the j-loop head, before the k-top pr.  The original order
 *   (flag, pr, j*8, cos) needs one of the two moved, and no source form found does that.
 * note (pass 5 2026-10-06 P5L02): residue unchanged at 5 bytes; the body is unchanged.  41 real compiles.
 *   New forms, none better: `int b` reused as the Part byte offset (`b *= sizeof(Part)`) with the cos stored in the
 *   first-rotation c (or s, fx): instructions identical, 7 B, j*8 and pr right but b*0x14 30 above the c web 2C (both
 *   are second webs and rank by def position, so b*0x14 at the k top always ranks above the cos); declaration order
 *   of b and c in that form: same or 593/684 B.  A local struct {int s, c} for s2/cos: 14 B (promoted, cos 3C above
 *   flag).  Function-scope `s16 sn, cs` shared with the object-level G3 rotation, cs reused for the k-loop cos: 5 B
 *   base slots (narrow reuse is transparent); as int: 23 B (decl slot 0x48); a j-body `int n` node index reused for
 *   the cos: 23 B; the function-scope int ox reused: 821 B.  Same 5 B: a `u16 pr2 = pr` (or int) copy for the rz
 *   cos read (value numbering sees through it), a k-loop `const s16 *tab` for all table reads, pose.rot spelled
 *   everywhere, a named s16 c2, the break as a goto, pr first assigned at the object-level G3 angle.  Named jo
 *   (head or k loop): 7 B or 1040 B.  Strength reduction off or long j in the reuse forms: 13 B (J P B C order).
 *   Reading (research in scratchpad wD9r/p5_P5L02): every measured order fits one birth-phase ranking (decl webs and
 *   promoted aggregates, then code-order webs flag/pr/cos with the head j*8 first when not strength reduced, then
 *   strength-reduced j*8, then load-deletion temps, then b*0x14, then second webs of reused ints).  The original
 *   needs j*8 between pr and cos, which no tested source form produces.
 * symbols:
 * note (pass 6 2026-10-06 P6L02): residue unchanged at 5 bytes; the body is unchanged.  New method: mwccarm traced
 *   under a debugger (tools in scratchpad wD9r/p6_P6L02).  Measured: spill slots follow the creation order of the
 *   compiler temps ("@N" names, lower N = higher slot).  The temps are made by IRO_CommonSubs, which runs twice here;
 *   each run names its temps in IR program order.  Ours: the (int)pr temp and cos(pr) are made by the first run, j*8
 *   only by the second run (at the j-loop head), b*0x14 later in the second run.  With long j the first run names
 *   j*8 at the head (above pr).  The original order needs cos(pr) to become common only in the second run (its two
 *   reads must differ at the first CSE and become equal through the copy/expression propagation that runs between
 *   the two CSE runs), or j*8 named in the first run between the s2 read and the rz cos read.  No such form found:
 *   a pr2 copy is removed before the first run (5 B), a second pr = pose.rot reloads pose (653 B).  The same 5 B with
 *   dsi 1.1 to 1.6sp2; the hidden opt_* pragmas tested have no effect.
 *   func_0207D7C4 0x0207D7C4 arm
 *   func_0207B67C 0x0207B67C arm
 *   func_02082B60 0x02082B60 arm
 *   func_0207ADE8 0x0207ADE8 arm
 *   func_0207B5C0 0x0207B5C0 arm
 *   func_0207BE14 0x0207BE14 arm
 *   func_0207C768 0x0207C768 arm
 *   func_0207D8FC 0x0207D8FC arm
 *   func_0207D888 0x0207D888 arm
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B51C 0x0207B51C arm
 *   func_0207CA00 0x0207CA00 arm
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _ll_mul 0x0209C054 arm
 *   func_021F660C 0x021F660C thumb ov112
 *   func_021F65EC 0x021F65EC thumb ov112
 *   func_021F5EDC 0x021F5EDC thumb ov112
 *   d_02148D8C 0x02148D8C data
 *   d_02148D98 0x02148D98 data
 *   d_02148DA4 0x02148DA4 data
 *   d_021F8310 0x021F8310 data ov112
 *   d_021F831C 0x021F831C data ov112
 *   d_021F8304 0x021F8304 data ov112
 *   d_02148B98 0x02148B98 data
 *   d_020A1B38 0x020A1B38 data
 *   d_02148B54 0x02148B54 data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;
typedef long long      s64;
#define REG(a) (*(volatile u32 *)(a))

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 id;
    u16 rot;
    int sx;
    int sy;
    s16 dx;
    s16 dz;
} Pose;

typedef struct {
    u32 f0, f4, f8, fC, f10, f14, f18, f1C, f20, f24, f28, f2C;
    u8 parts[8];
} Ent;

typedef struct {
    u32 f0;
    u32 f4;
    int x;
    int z;
    u32 f10;
} Part;

typedef struct {
    u16 f0;
    s16 x;
    s16 z;
    u16 h;
} TabEnt;

typedef struct {
    u16 count;
    u16 pad;
    TabEnt *ents;
} Tab;

typedef struct {
    int w;
    int z;
    Vec pos;
    int x2;
    int y2;
    int z2;
    Vec scale;
    Vec v100;
    u16 rot;
    u16 ang;
} CB;

typedef struct { int m[12]; } Mtx43;
typedef struct { int m[16]; } Mtx44;
typedef struct { int m[9]; } Mtx33;

extern const s16 d_020A1B38[];
extern const Vec d_02148D8C, d_02148D98, d_02148DA4;
extern const Vec d_021F8310, d_021F831C, d_021F8304;
extern const Mtx43 d_02148B98;
extern const Mtx44 d_02148B54;

extern void func_0207D7C4(const Vec *a, const Vec *b, const Vec *c, int d, void *e);
extern void func_0207B67C(const Mtx43 *a, Mtx43 *m);
extern void func_02082B60(Mtx43 *a, Mtx33 *b);
extern void func_0207ADE8(Mtx33 *a, Mtx44 *b);
extern void func_0207B5C0(const Mtx43 *src, Mtx44 *dst);
extern void func_0207BE14(const Mtx44 *a, const Mtx44 *b, Mtx44 *ab);
extern int func_0207C768(int a, int b);
extern void func_0207D8FC(Mtx44 *m);
extern void func_0207D888(int s, int c);
extern void func_0207AF38(Mtx33 *m, int s, int c);
extern void func_0207B51C(void *v, Mtx33 *m, void *out);
extern void func_0207CA00(void *a, void *b, void *c);
extern void func_021F660C(Vec *p, void *m, Vec *out, int *w);
extern void func_021F65EC(void);
extern void func_021F5EDC(char *obj, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, Pose *q, Pose *r,
                          int j, int flag, int *w, int h);

typedef struct { u32 b0 : 1; u32 rest : 31; } Bits;
typedef struct { u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 rest : 29; } Bits3;
static inline int FxMul(s64 a, s64 b)
{
    return (int)((a * b + 0x800) >> 12);
}
static inline int RoundF(int v)
{
    return (int)(v > 0 ? (float)(v << 12) + 0.5f : (float)(v << 12) - 0.5f);
}

typedef struct { u16 id; u16 pad; s16 dx; s16 dz; } PoseSrc;
static inline void LoadPose(Pose *r, char *src, int one)
{
    switch ((u16)*(u32 *)(*(char **)(src + 0x1c) + 4)) {
    case 0: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = 0;
        r->dz = 0;
        break;
    }
    case 1:
        *r = ***(Pose ***)src;
        break;
    case 2: {
        const PoseSrc *s = **(PoseSrc ***)src;
        r->id = s->id;
        r->rot = 0;
        r->sx = one;
        r->sy = one;
        r->dx = s->dx;
        r->dz = s->dz;
        break;
    }
    }
}

typedef struct { u32 addr; u32 f04; u32 f08; u32 s; u32 t; u32 fmt; u32 f18; u32 pltt0; } TexInfo;
typedef enum { GX_TEXFMT_NONE = 0, GX_TEXFMT_PLTT4 = 2 } GXTexFmt;
typedef enum { GX_TEXGEN_NONE = 0, GX_TEXGEN_TEXCOORD = 1 } GXTexGen;
typedef enum { GX_TEXSIZE_S8 = 0 } GXTexSizeS;
typedef enum { GX_TEXSIZE_T8 = 0 } GXTexSizeT;
typedef enum { GX_TEXREPEAT_NONE = 0, GX_TEXREPEAT_ST = 3 } GXTexRepeat;
typedef enum { GX_TEXFLIP_NONE = 0, GX_TEXFLIP_ST = 3 } GXTexFlip;
typedef enum { GX_TEXPLTTCOLOR0_USE = 0, GX_TEXPLTTCOLOR0_TRNS = 1 } GXTexPlttColor0;
static inline void G3_TexImageParam(GXTexFmt texFmt, GXTexGen texGen, GXTexSizeS s, GXTexSizeT t, GXTexRepeat repeat, GXTexFlip flip, GXTexPlttColor0 pltt0, u32 addr)
{
    REG(0x040004A8) = (u32)((addr >> 3) | (texFmt << 26) | (texGen << 30) | (s << 20) |
                                  (t << 23) | (repeat << 16) | (flip << 18) | (pltt0 << 29));
}
static inline void VEC_Set(Vec *a, int x, int y, int z)
{
    a->x = x;
    a->y = y;
    a->z = z;
}
static inline void G3_Translate(int x, int y, int z)
{
    REG(0x04000470) = (u32)x;
    REG(0x04000470) = (u32)y;
    REG(0x04000470) = (u32)z;
}
static inline void G3_Scale(int x, int y, int z)
{
    REG(0x0400046C) = (u32)x;
    REG(0x0400046C) = (u32)y;
    REG(0x0400046C) = (u32)z;
}
void func_021F56BC(int *p, void (*arg)(u8, Vec *, u32))
{
    Pose pose;
    Pose sub;
    Vec pos;
    Mtx44 m3;
    Mtx43 m1;
    Mtx33 m2;
    Mtx44 m4;
    Mtx44 proj;
    Mtx33 m5;
    CB cb;
    Ent *ent;
    TexInfo *attr;
    int i, j;
    char **srcs;
    u8 k;
    char *obj;
    char *ctrl;
    int ox, oy;
    u8 flag;

    REG(0x04000444) = 0;
    REG(0x04000440) = 0;
    REG(0x0400044C) = 0;
    REG(0x04000440) = 3;
    REG(0x04000454) = 0;
    REG(0x04000440) = 2;
    if ((((Bits *)&p[2])->b0) == 0)
        func_0207D7C4(&d_02148D8C, &d_02148D98, &d_02148DA4, 1, 0);
    else
        func_0207D7C4(&d_021F8310, &d_021F831C, &d_021F8304, 1, 0);
    func_0207B67C(&d_02148B98, &m1);
    func_02082B60(&m1, &m2);
    func_0207ADE8(&m2, &m3);

    for (i = 0; i < p[0]; i++) {
        if (((char **)p[1])[i] == 0 || ((Bits3 *)(((char **)p[1])[i] + 0xEC))->b2)
            continue;
        REG(0x04000444) = 0;
        obj = ((char **)p[1])[i];
        attr = (TexInfo *)(obj + 0x90);
        ctrl = obj + 0x28;
        srcs = (char **)(obj + 0x68);
        cb.z = 0;
        LoadPose(&pose, ctrl, 0x1000);
        pos.x = *(int *)(obj + 0xC8);
        pos.y = *(int *)(obj + 0xCC);
        pos.z = *(int *)(obj + 0xD0);
        if ((((Bits *)&p[2])->b0) == 0) {
            ox = pose.dx << 8;
            oy = -pose.dz << 8;
        } else {
            proj.m[0] = 0x80000;
            proj.m[1] = 0;
            proj.m[2] = 0;
            proj.m[3] = 0x80000;
            proj.m[4] = 0;
            proj.m[5] = 0x60000;
            proj.m[6] = 0;
            proj.m[7] = (int)0xFFFA0000;
            proj.m[8] = 0;
            proj.m[9] = 0;
            proj.m[10] = (int)0xFFFFF000;
            proj.m[11] = 0x1000;
            proj.m[12] = 0;
            proj.m[13] = 0;
            proj.m[14] = 0;
            proj.m[15] = (int)0xFFFFF000;
            func_0207B5C0(&d_02148B98, &m4);
            func_0207BE14(&m4, &d_02148B54, &m4);
            func_021F660C(&pos, &m4, &pos, &cb.w);
            pos.x = func_0207C768(pos.x, cb.w);
            pos.y = func_0207C768(pos.y, cb.w);
            func_021F660C(&pos, &proj, &pos, &cb.w);
            ox = RoundF(pose.dx);
            oy = RoundF(-pose.dz);
        }
        pos.z = *(int *)(obj + 0xD0);
        flag = 0;
        if (*(int *)(obj + 0xD4) < 0)
            flag++;
        G3_Translate(pos.x, pos.y, pos.z);
        if ((((Bits *)&p[2])->b0) == 0)
            func_0207D8FC(&m3);
        G3_Translate(ox, oy, 0);
        {
            u16 a = (flag & 1) ? 0x10000 - pose.rot : pose.rot;
            func_0207D888(-d_020A1B38[(a >> 4) * 2], d_020A1B38[(a >> 4) * 2 + 1]);
        }

        {
            int sy = FxMul(pose.sy, *(int *)(obj + 0xD8));
            int sx = FxMul(pose.sx, *(int *)(obj + 0xD4));
            G3_Scale(sx, sy, 0x1000);
        }
        {
            u16 a = *(u16 *)(obj + 0xFC);
            func_0207AF38(&m5, -d_020A1B38[(a >> 4) * 2], d_020A1B38[(a >> 4) * 2 + 1]);
            func_0207B51C(obj + 0x100, &m5, obj + 0x10C);
            func_0207CA00(obj + 0x100, obj + 0x10C, obj + 0x10C);
            *(int *)(obj + 0x10C) = func_0207C768(*(int *)(obj + 0x10C), *(int *)(obj + 0xD4));
            *(int *)(obj + 0x110) = func_0207C768(*(int *)(obj + 0x110), *(int *)(obj + 0xD8));
        }
        REG(0x0400044C) = 0x1D;
        func_021F65EC();
        {
            G3_TexImageParam(attr->fmt, GX_TEXGEN_TEXCOORD, attr->s, attr->t, GX_TEXREPEAT_ST, GX_TEXFLIP_ST, attr->pltt0, attr->addr);
        }
        for (j = 0; j < (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].count; j++) {
            char *src;
            src = *srcs + (((*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].h & 0xFF00) >> 8) * 0x5C;
            LoadPose(&sub, src, 0x1000);
            ent = (Ent *)(*(char **)(obj + 0x20) + 4 + sub.id * 0x38);
            if (ent->f20 != 0) {
                if (((Bits *)(obj + 0xEC))->b0)
                    func_021F5EDC(obj, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                  ent->f2C + ent->f24, &sub, &pose, j, ((Bits *)&p[2])->b0, &cb.z, flag);
                else
                    func_021F5EDC(obj, ent->f18, ent->f1C, ent->f20, ent->f24, ent->f28,
                                  ent->f2C, &sub, &pose, j, ((Bits *)&p[2])->b0, &cb.z, flag);
            }
            func_021F5EDC(obj, ent->f0, ent->f4, ent->f8, ent->fC, ent->f10, ent->f14,
                          &sub, &pose, j, ((Bits *)&p[2])->b0, &cb.z, flag);
            for (k = 0; k < 8; k++) {
                u8 b = ent->parts[k];
                int ang, fx, fz, c, s, X, Z, s2, rx, rz;
                u16 pr;
                s64 psx, psy;
                if (b == 0xFF)
                    break;
                pr = pose.rot;
                ang = (u16)(pr + sub.rot);
                fx = (*(Part **)(obj + 0x24))[b].x;
                fz = (*(Part **)(obj + 0x24))[b].z;
                s = d_020A1B38[(ang >> 4) * 2];
                c = d_020A1B38[(ang >> 4) * 2 + 1];
                psx = pose.sx;
                psy = pose.sy;
                rx = FxMul(fx * c - fz * s, FxMul(psx, sub.sx));
                rz = FxMul(fx * s + fz * c, FxMul(psy, sub.sy));
                X = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].x;
                X += pose.dx;
                Z = (*(Tab **)(*(char **)(obj + 0x6C) + 4))[pose.id].ents[j].z;
                Z += pose.dz;
                s2 = d_020A1B38[(pr >> 4) * 2];
                rx += FxMul(X * d_020A1B38[(pr >> 4) * 2 + 1] - Z * s2, psx);
                rz += FxMul(X * s2 + d_020A1B38[(pr >> 4) * 2 + 1] * Z, psy);
                rx += RoundF(sub.dx);
                rz += RoundF(sub.dz);
                cb.pos = pos;
                cb.pos.y = -cb.pos.y;
                cb.x2 = FxMul(rx, *(int *)(obj + 0xD4) / 16);
                cb.y2 = FxMul(rz, *(int *)(obj + 0xD8) / 16);
                cb.z2 = cb.z;
                cb.v100 = *(Vec *)(obj + 0x100);
                cb.rot = *(u16 *)(obj + 0xFC);
                cb.scale = *(Vec *)(obj + 0xD4);
                cb.ang = (u16)(ang + ((*(Part **)(obj + 0x24))[b].f10 << 11));
                arg((u8)(*(Part **)(obj + 0x24))[b].f4, &cb.pos, *(u32 *)(obj + 0xF8));
                if ((*(Part **)(obj + 0x24))[b].f4 == 5) {
                    VEC_Set((Vec *)(obj + 0x100), cb.x2, cb.y2, 0);
                }
            }
        }
        REG(0x04000448) = 1;
    }
    REG(0x04000448) = 1;
}
