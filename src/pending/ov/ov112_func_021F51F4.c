/*
 * function: func_021F51F4
 * address: 0x021F51F4
 * packet: pkt_ov112_021F51F4
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * 2026-10-05 (wave D5 lane 02): ov112 0x021F546C is a different function from the ov194 one (a 172-byte slot
 * writer: mode >= 7 copies an input record into slot mode-7, modes 4 and 5 write four words). Parked as
 * src/pending/ov/ov112_func_021F546C.c, DIFF. Still blocks this MATCH.
 * 2026-10-05 (wD4 lane16): re-checked, bytes identical; MATCH only because func_021F546C (ov112) has no EXACT witness (ov194 has a pending file at the same address, 9 overlays overlap). Needs the callback matched in ov112.
 * blocker: callback ov112 021F546C has no outside witness; final retry exhausted in docs/notes/pkt_ov112_021F546C.c.txt (170 vs 172 bytes).
 * 2026-10-05 (wave D6 lane 01): bytes still identical; still blocked by ov112 021F546C (DIFF 170/172).
 * 2026-10-05 (wave D7 lane 01): still MATCH, blocked by ov112 021F546C, now DIFF 172/172 with 27 bytes
 *   (two register-order residues, see that file).
 * symbols:
 *   func_021F546C 0x021F546C thumb ov112
 *   func_021F56BC 0x021F56BC thumb ov112
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021F546C(u32,void *,void *);
extern void func_021F56BC(void *,void (*)(u32,void *,void *));
void func_021F51F4(void **p) { func_021F56BC(p[1],func_021F546C); }
