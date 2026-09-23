/*
 * docs/families/iss_switch.h -- the iss_switch.c family, around
 * 0x0202C590..0x0202CB00 in the ARM9 image (__FILE__ anchor 0x020A7780 at
 * 0x0202C5A8; iss_switch_sys.c and iss_switch_set.c sit just below it).
 *
 * REFERENCE DOCUMENT ONLY; nothing includes it.  Written 2026-09-23 (wave 15
 * tail lane) from src/matched/func_0202C860.c and src/pending/func_0202C794.c
 * plus the matched C8B8/C934/C970/C9B4/CA0C/CA3C members.
 *
 * Both open members are reason-code probes on a sound id (u16):
 *   0x0202C794: four probes (func_0215E6A8, func_0202C8B8, func_0202C934,
 *     func_0202C970), each returning a u8 code or the sentinel 0xffff (one
 *     pool word held in a callee-saved register); fallback through
 *     func_0202C824(ctx) to func_021647E8 or func_02013C10.
 *   0x0202C860: range check that must wrap in 32 bits, `(u32)(r - 6) > 1`.
 *
 * Overlay callees (evidence): func_0215E6A8, func_0215E6F8 resolve; 0x021647E8
 * is an unlabelled `ldr r3, [pc, #0]; bx r3` thunk in ov010 (.word
 * 0x47184B00), and ov009 covers the same address with ARM code, so it needs a
 * seeded ov010 start before 0x0202C794 can leave MATCH.
 */

#ifndef ISS_SWITCH_H
#define ISS_SWITCH_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020120F4(void);
extern u32 func_0201297C(void);
extern u32 func_0215E6A8(u32 a, u16 id);        /* ov010 */
extern u32 func_0202C8B8(void *a, u32 ctx, u32 id);
extern u32 func_0202C934(void *a, u32 ctx, u32 id);
extern u32 func_0202C970(void *a, u32 ctx, u32 id);
extern u32 func_0202C824(u32 ctx);
extern u32 func_021647E8(u32 a, u16 id);        /* ov010 thunk, unlabelled */
extern u32 func_02013C10(u16 id);

#endif /* ISS_SWITCH_H */
