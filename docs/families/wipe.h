/*
 * docs/families/wipe.h -- shared declarations for the wipe.c family,
 * 0x0202271C..0x02022AC4 in the ARM9 image (edges fuzzy by a function).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never
 * sees it.  Written 2026-09-23 (wave 15 tail lane) from the byte-exact
 * sources func_02022758.c, func_02022790.c, func_020227CC.c,
 * func_02022940.c, unit_0202290C.c, func_020229A4.c, func_02022A44.c.
 */

#ifndef WIPE_H
#define WIPE_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;

/* The per-wipe object the four setup steps take (only the touched fields). */
struct T {
    u8  pad00[0xc];
    u32 f0c;          /* nonzero: skip setup, call func_0202390C(p) instead */
    u8  pad10[0x14];
    u16 f24;          /* passed to func_020222A8 */
    u8  pad26[2];
    u32 f28;          /* 1 for 0x0202271C/0x02022790, 0 for the other two */
    u32 f2c;
};

/* The wipe state at 0x020A73D0.  Each setup step stores a rodata table
 * address into one slot and passes that slot's address on. */
struct G {
    u32 f00;          /* 0x0202271C, table 0x0209F570 */
    u8  pad04[0xc];
    u32 f10;          /* 0x02022758, table 0x0209F56C */
    u8  pad14[0xc];
    u32 f20;          /* 0x02022790, table 0x0209F574 */
    u32 pad24;
    u32 f28;          /* 0x020227CC, table 0x0209F568 */
};
extern struct G g_020A73D0;

/* 0x0209F568..0x0209F574 are four rodata WORDS (0xC0, 0xC000, 0x1C000,
 * 0x100C0), not ARM functions.  Declare them `data`; each is then attested
 * sole-ref/self.  Declared `arm` they have no witness at all. */
extern const u32 d_0209F568[], d_0209F56C[], d_0209F570[], d_0209F574[];

extern void func_020222A8(u32 v);
extern void func_020238B4(struct T *p, void *slot);
extern void func_0202390C(struct T *p);

/* Four-channel fade helpers. */
struct Quad { s32 a, b, c, d; };
extern s32  func_0202290C(s32 a, s32 b, s32 c);   /* ((b - a) << 7, c) -> 0x0209C0A4; returns its value */
extern void func_0202291C(struct Quad *dst, struct Quad *src);
extern void func_02022940(struct Quad *cur, struct Quad *end, struct Quad *step,
                          const u8 *from, const u8 *to, s32 frames);

/* Open residue: 0x0202271C is the f00 slot, where the store address and the
 * passed address coincide; 1.1p1 CSEs them into r5 (9 bytes), sp2/sp2p2
 * reload but share one pool word where the image has two (1 byte). */

#endif /* WIPE_H */
