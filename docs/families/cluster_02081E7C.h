/*
 * docs/families/cluster_02081E7C.h -- shared declarations for the
 * pseudo-family pkt_02081E7C (0x02081E7C, 0x02082F48, 0x02082F90 in the ARM9
 * image).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Declarations are from EXACT files in src/matched (named beside them)
 * or marked NOT BYTE-ATTESTED.  Black-image addresses.
 *
 * WHAT IT IS.  Not one subsystem: two TwlSDK libraries that the address
 * grouping put together.  Identified from the callers and from
 * layout/symbols_sdk.json (libmatch), not from names in the image.
 *
 *   func_02081E7C  SHA-1 compression function, TwlSDK libmath    EXACT (asm)
 *                  (dgt_sha1 family; sits after qsort.o's MATH_QSort, whose
 *                  648 bytes end at 0x02081E6C, and before libmi's
 *                  MI_InitWramManager at 0x02082198)
 *   0x02082F48     NOT A FUNCTION: MI_CpuCopy aligned kernel      SDK bytes
 *   0x02082F90     NOT A FUNCTION: MI_CpuCopy shift-8 kernel      SDK bytes
 *
 * STATUS (wave 11, 2026-09-23): the one real function is EXACT; the other two
 * rows are library interior, see docs/families/cluster_02083028.h for the
 * MI_CpuCopy proof (shared with that family).
 *
 * FRONT END.  Irrelevant: every row here is hand-written ARM.  func_02081E7C
 * is an `asm` function and is byte-identical under 1.1p1 and ../2.0/sp2.
 *
 * RECOGNITION RULE (new, wave 11).  A body that uses ROR (bare or as a
 * shifter operand), pushes ip, or loads a constant with a NEGATIVE pc offset
 * is not compiler output; if its caller is a libmatch-identified SDK
 * function, it is an SDK asm function and is written as a CodeWarrior
 * `asm` body (stmfd/ldmfd for push/pop, ldmia/stmia spelled out, `mov rd,
 * rm, ror #n` for ror, r9-r12 for sb/sl/fp/ip, `@label:` local labels).
 * Explicit pc-relative offsets assemble verbatim and carry no relocation.
 */

#ifndef CLUSTER_02081E7C_H
#define CLUSTER_02081E7C_H

typedef unsigned char u8;
typedef unsigned int  u32;

/* The context the block function works on.  PROVEN by func_02081E7C (EXACT):
 * `ldm fp, {r4-r8}` / the five-way add-and-`stm` tail read and write h[0..4]
 * at +0x00, and `add r8, fp, #0x14` is the message block.  The block is read
 * as big-endian words (the three-instruction ror byte swap). */
typedef struct Sha1BlockCtx {
    u32 h[5];           /* +0x00 */
    u8  block[64];      /* +0x14 */
} Sha1BlockCtx;

extern void func_02081E7C(Sha1BlockCtx *ctx);                 /* EXACT, asm */

/* The round constants: a 16-byte object at 0x02081E6C, immediately BEFORE the
 * entry, reached only by the four `ldr ip, [pc, #-n]` in func_02081E7C.
 * NOT BYTE-ATTESTED as its own object (it is data, not in any shard). */
extern const u32 d_02081E6C[4];  /* 5A827999 6ED9EBA1 8F1BBCDC CA62C1D6 */

/* Callers (SDK, layout/symbols_sdk.json):
 *   MATHi_SHA1ProcessBlockForOverlay  0x020812E0  bl func_02081E7C at 0x020812FC
 *   MATHi_SetOverlayTableMode         0x0208139C  pool word 0x020813D4 = &func  */

#endif /* CLUSTER_02081E7C_H */
