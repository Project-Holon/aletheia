/*
 * docs/families/touchpanel.h -- shared declarations for the touchpanel.c
 * family (0x020357E0..0x02035ECC in the ARM9 image, the touch-panel input
 * subsystem; the __FILE__ anchor the constructors pass is g_020A798C).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT, and the matched
 * function that evidences each field is named in the comment beside it.
 * Where the matched sources disagree on the spelling of a parameter type
 * (they were written by different lanes), the spelling recorded here is the
 * one the byte evidence actually constrains; a parameter that is only ever
 * passed a register-width value and never dereferenced is left u32.
 *
 * NOTE ON EXTENT.  The span is whole ARM code (the 0x02035000..0x02038000
 * block is ARM throughout, not Thumb).  Its three layers:
 *   - 0x020357E0        the constructor: allocates the 0x7c-byte work
 *                       object, brings TP up, installs the calibration and
 *                       publishes the object at g_021469C4.
 *   - 0x02035750..0x020357C0, 0x02035E54..0x02035ECC
 *                       the accessor/setter band over that object: a kind
 *                       byte at +0x3D selects between two parallel
 *                       halfword quads (+0x5C.. and +0x64..).
 *   - 0x02035A70..0x02035BBC, 0x02035C38..0x02035E18
 *                       the hit-test band (circle and rectangle tests over
 *                       a packed 4-byte record table) and the link-layer
 *                       open/close pair with its no-context wrappers.
 * The accessors at 0x0203575x sit just below the nominal family start but
 * are the same object's API and are quoted here, since every function in
 * the range calls them.
 */

#ifndef TOUCHPANEL_H
#define TOUCHPANEL_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * The touch-panel work object: 0x7c bytes.  The size is evidenced twice
 * by sub_020357E0, which passes 0x7c both to the allocator and to the
 * MI_CpuFill8 that clears it.  The published singleton is g_021469C4.
 * ------------------------------------------------------------------ */
struct TpWork {
    u8  pad00[0x0c];    /* +0x00  nothing matched touches these */
    u8  buf[0x4c];      /* +0x0C  unit_02035D5C: sub_02035E18 hands this
                         *        address to func_0208AC0C as the 9-byte
                         *        transfer buffer */
    u16 handle;         /* +0x58  sub_020357E0 zeroes it before TP_Init;
                         *        unit_02035D5C guards on it being non-zero
                         *        and passes it to func_0208AD14 */
    u16 state;          /* +0x5A  sub_020357E0 zeroes it; unit_02035D5C
                         *        drives it 0 <-> 1 for down/up */
    u16 x0;             /* +0x5C  func_02035760 reads it when kind != 0x1E;
                         *        func_02035E84 writes it from its 2nd arg */
    u16 y0;             /* +0x5E  func_02035780 / func_02035E84 (3rd arg) */
    u16 x1;             /* +0x60  func_020357C0 reads it when kind != 0x1E */
    u16 y1;             /* +0x62  func_020357A0 reads it when kind != 0x1E */
    u16 cx0;            /* +0x64  func_02035760 when kind == 0x1E;
                         *        func_02035E84 writes it from its 4th arg;
                         *        sub_02035E54 zeroes it */
    u16 cy0;            /* +0x66  func_02035780 when kind == 0x1E;
                         *        func_02035E84 (5th, stack, arg) */
    u16 cx1;            /* +0x68  func_020357C0 when kind == 0x1E;
                         *        func_02035EB0 writes it */
    u16 cy1;            /* +0x6A  func_020357A0 when kind == 0x1E;
                         *        func_02035ECC writes it */
    u16 unk6c;          /* +0x6C  func_02035EB0 writes it; sub_02035E54
                         *        zeroes it */
    u16 unk6e;          /* +0x6E  func_02035ECC writes it; sub_02035E54 */
    u16 unk70;          /* +0x70  sub_02035E54 zeroes it */
    u16 unk72;          /* +0x72  sub_02035E54 zeroes it */
    u8  pad74;          /* +0x74 */
    u8  mode;           /* +0x75  sub_020357E0 stores 4; unit_02035D5C's
                         *        sub_02035E18 passes it to func_0208AC0C */
    u8  blink;          /* +0x76  sub_020357E0 zeroes it */
};

/* The "kind" discriminator lives in the CALLER's context object, not in
 * TpWork: func_02035760 and its three siblings test p->unk3D on the
 * argument and read the halfwords out of func_02035750(p).  0x1E selects
 * the +0x64 quad, anything else the +0x5C quad. */
struct TpCtx {
    u8 pad00[0x3D];
    u8 kind;            /* +0x3D  == 0x1E in func_02035760/780/7A0/7C0 */
};
#define TP_KIND_ALT 0x1E

/* ------------------------------------------------------------------ *
 * The hit-test record: four packed bytes, walked as an array indexed by
 * `i` with `ldrb r0, [r7, r4, lsl #2]` (func_02035ADC).  Byte 0 is the
 * shape tag and terminator; 0xFF ends the table, 0xFD skips the entry,
 * 0xFE selects the rectangle test, anything else the circle test.
 * ------------------------------------------------------------------ */
struct TpHit {
    u8 tag;             /* +0x00  func_02035ADC: 0xFF end, 0xFD skip,
                         *        0xFE rect, else circle */
    u8 b1;              /* +0x01  func_02035A70: circle centre x;
                         *        func_02035AA4: rect high bound (b axis) */
    u8 b2;              /* +0x02  func_02035A70: circle centre y;
                         *        func_02035AA4: rect low bound (a axis) */
    u8 b3;              /* +0x03  func_02035A70: radius (smulbb, so <=16
                         *        bits, and u8 is what produces smulbb);
                         *        func_02035AA4: rect high bound (a axis) */
};

/* ------------------------------------------------------------------ *
 * Accessors over the singleton object.  func_02035750 is the resolver
 * every other function in the band calls first; it ignores its argument
 * and returns the object published at 0x021469C4 (EXACT in
 * src/matched/func_02035750.c, which spells it with four int parameters
 * and a literal load).
 * ------------------------------------------------------------------ */
extern struct TpWork *func_02035750(void *ctx);

extern u16  func_02035760(struct TpCtx *p);   /* +0x64 / +0x5C */
extern u16  func_02035780(struct TpCtx *p);   /* +0x66 / +0x5E */
extern u16  func_020357A0(struct TpCtx *p);   /* +0x6A / +0x62 */
extern u16  func_020357C0(struct TpCtx *p);   /* +0x68 / +0x60 */

/* Setters.  func_02035E84's fifth argument is a stack argument (the
 * `ldrh r1, [sp, #0x10]` after push {r4,r5,r6,lr}). */
extern void func_02035E84(void *p, u16 a, u16 b, u16 c, u16 d);
extern void func_02035EB0(void *p, u16 a, u16 b);   /* +0x60, +0x68 */
extern void func_02035ECC(void *p, u16 a, u16 b);   /* +0x62, +0x6A */
extern void sub_02035E54(struct TpWork *p);         /* zeroes +0x64..+0x72 */

/* ------------------------------------------------------------------ *
 * The hit tests.  Both take the record pointer in a1; both are EXACT and
 * their parameter widths are fixed by their own bytes: func_02035A70's
 * coordinates are signed ints (full 32-bit mul/mla on the differences),
 * func_02035AA4's are unsigned (the one-sided range test compiles to the
 * conditional LS chain only with unsigned operands).
 * ------------------------------------------------------------------ */
extern u32 func_02035A70(u8 *p, s32 x, s32 y);   /* circle: dx^2+dy^2 < r^2 */
extern u32 func_02035AA4(u8 *p, u32 a, u32 b);   /* rectangle */

/* The table walk itself.  Returns the index of the first record that the
 * point hits, or -1.  Callers: func_02035B58, func_02035BBC and
 * sub_02035D40 (unit_02035C70), which is why the second and third
 * arguments are register-width in some spellings and u16 in others; the
 * bytes only constrain them to be passed in r1/r2 unmodified. */
extern int func_02035ADC(u8 *table, u32 x, u32 y);

/* Wrappers around func_02035ADC: fetch the current point from the
 * context, then walk the table.  func_02035B58 gates on func_020357A0,
 * func_02035BBC on func_020357C0; both return -1 when the gate is 0. */
extern int func_02035B58(u32 ctx, u32 table);
extern int func_02035BBC(void *ctx, void *table);

/* ------------------------------------------------------------------ *
 * Construction and the singleton.
 * ------------------------------------------------------------------ */
extern void *sub_020357E0(u32 heapId);   /* the 0x7c-byte constructor */
extern void *func_02035EE8(u32 heapId);  /* a 0x4c-byte sibling object,
                                          * anchor g_020A799C, f40=8 f44=0xf */

/* The context resolver used by every "no context argument" wrapper in the
 * block (unit_02035C70, unit_02035D5C, sub_02035C60, sub_02035C38). */
extern struct TpCtx *func_02035224(void);

/* ------------------------------------------------------------------ *
 * Externals the family depends on.
 * ------------------------------------------------------------------ */
extern void *func_02030734(u32 heap, u32 size, u32 flags,
                           const char *file, u32 line);  /* sub_020357E0 */
extern void  MI_CpuFill8(void *dst, u8 val, u32 size);   /* 0x02082BCC */

extern void TP_Init(void);                      /* 0x0208A924 */
extern int  TP_GetUserInfo(u16 *info);          /* 0x0208A998, answers 1 */
extern void TP_SetCalibrateParam(u16 *info);    /* 0x0208AA2C */

/* Link layer, unit_02035D5C. */
extern void func_0208AC0C(u32 a, u32 b, void *buf, u32 len);
extern void func_0208AD14(u32 handle);
extern void func_0208B220(u32 slot);
extern u32  func_0208B238(u32 slot);

/* ------------------------------------------------------------------ *
 * Pinned data.  Both anchors are __FILE__-class: declare them as arrays
 * pinned by address in the symbols: block, never as a literal __FILE__
 * (docs/idioms/file-string-is-an-abs32-into-the-string-area.md).
 * ------------------------------------------------------------------ */
extern const char str_020A798C[];   /* sub_020357E0's anchor, line 0x83 */
extern const u8   g_020A799C[];     /* func_02035EE8's anchor, line 0x44 */
extern void      *g_021469C4;       /* the published TpWork singleton */

/* The firmware default calibration sub_020357E0 installs when
 * TP_GetUserInfo does not answer 1: 0x2ae, 0x58c, 0xe25, 0x1208.  0x58c is
 * materialised as 0x510 + 0x7c because the size constant is still live. */
#define TP_CAL_DEFAULT_X0 0x02ae
#define TP_CAL_DEFAULT_Y0 0x058c
#define TP_CAL_DEFAULT_X1 0x0e25
#define TP_CAL_DEFAULT_Y1 0x1208

#endif /* TOUCHPANEL_H */
