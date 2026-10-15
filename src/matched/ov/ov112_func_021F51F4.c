/*
 * function: MUSICAL_MCSS_DrawRenderObj
 * address: 0x021F51F4
 * packet: pkt_ov112_021F51F4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wave D5 lane 02): ov112 0x021F546C is a different function from the ov194 one (a 172-byte slot
 * writer: mode >= 7 copies an input record into slot mode-7, modes 4 and 5 write four words). Parked as
 * src/pending/ov/ov112_func_021F546C.c, DIFF. Still blocks this MATCH.
 * 2026-10-05 (wD4 lane16): re-checked, bytes identical; MATCH only because MUSICAL_MCSS_SetMatrix (ov112) has no EXACT witness (ov194 has a pending file at the same address, 9 overlays overlap). Needs the callback matched in ov112.
 * blocker: callback ov112 021F546C has no outside witness; final retry exhausted in docs/notes/pkt_ov112_021F546C.c.txt (170 vs 172 bytes).
 * 2026-10-05 (wave D6 lane 01): bytes still identical; still blocked by ov112 021F546C (DIFF 170/172).
 * 2026-10-05 (wave D7 lane 01): still MATCH, blocked by ov112 021F546C, now DIFF 172/172 with 27 bytes
 *   (two register-order residues, see that file).
 * 2026-10-05 (wave D8 lane 01): bytes still identical, still blocked by ov112 021F546C. Finding for
 *   that draft (not in this lane, so not edited): dropping const from the input pointer
 *   (`Input *in`) fixes its residue (b), the modes 4/5 y-before-x load order; with the y local kept
 *   it is 172/172 with 5 bytes left, only the slot multiply colours (original idx r4 and product
 *   r1, ours idx r1 and product r4). No change to that from: no idx local, mode -= 7, unsigned idx,
 *   idx declared at function scope, an else-if chain, a void * parameter cast to Big *, an inline
 *   SetSlot(p, idx, in), enabled stored last; a byte-offset form loses the copy shape.
 * 2026-10-05 (D9 lane 02): still blocked by ov112 021F546C. Tried one more reading there: `Slot *s = &p->slots[mode - 7]` instead of the idx local (worse, 128 bytes differ).
 * 2026-10-05 (D9r lane 45): bytes still identical; still blocked by ov112 021F546C, now DIFF 172/172 with
 *   5 bytes (only the slot multiply colours), see that file.
 * 2026-10-05 (D9r lane 74): bytes still identical; still blocked by ov112 021F546C (DIFF, 5 bytes, slot
 *   multiply colours; new tries listed in that file).
 * 2026-10-05 (D9r lane 94): bytes still identical; still blocked by ov112 021F546C (DIFF, 5 bytes, slot multiply
 *   colours; three more tries listed in that file).
 * 2026-10-05 (D9r lane 121): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes,
 *   same slot multiply colours; new tries listed in that file).
 * 2026-10-05 (D9r lane 144): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes;
 *   new tries listed in that file).
 * 2026-10-05 (D9r lane 155): bytes still identical (re-checked); still blocked by ov112 021F546C (DIFF, 5 bytes;
 *   new finding and tries listed in that file).
 * 2026-10-05 (D9r lane 171): bytes still identical (re-checked, MATCH, the MUSICAL_MCSS_SetMatrix ABS32 word has no
 *   witness); still blocked by ov112 021F546C (DIFF, 5 bytes; tries listed in that file).
 * 2026-10-05 (D9r lane 195): ov112 021F546C is now EXACT (src/matched/ov/ov112_func_021F546C.c, compound product form).
 *   This MATCH should resolve once the integrator regenerates the witness index (the tool still reads the old
 *   manifest: "no witness outside"). Re-run match.py one after the regenerate and file as EXACT.
 * symbols:
 *   MUSICAL_MCSS_SetMatrix 0x021F546C thumb ov112
 *   MUSICAL_MCSS_DrawMC 0x021F56BC thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void MUSICAL_MCSS_SetMatrix(u32,void *,void *);
extern void MUSICAL_MCSS_DrawMC(void *,void (*)(u32,void *,void *));
void MUSICAL_MCSS_DrawRenderObj(void **p) { MUSICAL_MCSS_DrawMC(p[1],MUSICAL_MCSS_SetMatrix); }
