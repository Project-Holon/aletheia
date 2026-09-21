/*
 * field_sound_system.h -- shared declarations for the field_sound_system.c
 * family, 0x02028844..0x02029EB4 in the Black ARM9 image.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file and nothing in
 * src/matched or src/pending is edited to use it.  It is the derived
 * ground truth: every field, width, signedness and prototype below is
 * read out of an EXACT source under src/matched, and each entry names the
 * matched function that evidences it.  Where two matched files disagree
 * on a name for the same offset, the offset is what is attested and the
 * name is this file's own.
 *
 * Derived 2026-09-21 from the 112 byte-exact members of the family.
 */

#ifndef FIELD_SOUND_SYSTEM_H
#define FIELD_SOUND_SYSTEM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * struct Cmd -- one queue entry, stride 12.
 *
 * The stride is fixed by func_02028D7C (EXACT), which computes
 * `base + 0x28 + idx * 12`, and by func_02028CD4 (EXACT), which clears
 * `*(u32 *)(p + 0x28 + i * 12)` for ten iterations.  The field layout
 * inside the entry is evidenced by func_02028D8C and func_02028E0C
 * (both EXACT), which spell the same struct.
 * ------------------------------------------------------------------ */
struct Cmd {
    u32 unk00;      /* +0x00  func_02028D8C: the class word; func_02028E48
                     *        loads it through func_02028D8C()->unk00 and
                     *        uses it as a table row index, so it is u32
                     *        and non-negative in practice. */
    u32 unk04;      /* +0x04  func_02028E0C */
    u16 unk08;      /* +0x08  func_02028E0C */
    u16 unk0A;      /* +0x0a  func_02028E0C */
};

/* ------------------------------------------------------------------ *
 * struct Sys -- the field sound system object, 0xb8 bytes.
 *
 * The total size is fixed by func_02028844 (EXACT), which allocates
 * 0xb8 bytes through func_02030734.  Offsets below are each attributed.
 * The family's matched files each declare only the prefix they touch
 * (pad_00[0x20], pad_00[0x28], pad[0xac], pad_00[0xa4] ...); this is the
 * union of those views, and every one of them is consistent with it.
 * ------------------------------------------------------------------ */
struct Sys {
    u32        unk00;       /* +0x00  func_02028CD4 stores the desc word here */
    u32        unk04;       /* +0x04  func_02028CD4 zeroes it.  This is the
                             *        field func_02028FD0 reads as its row
                             *        index (`ldr r0, [r0, #4]`). */
    u32        unk08;       /* +0x08  func_02028CD4, func_020293D8 */
    u32        unk0C;       /* +0x0c  func_02028CD4 */
    u32        unk10;       /* +0x10  func_02028CD4 */
    u32        unk14;       /* +0x14  func_02028CD4 */
    u16        unk18;       /* +0x18  func_02028CD4 zeroes it as a halfword;
                             *        func_02028F60 stores a u16 argument. */
    u16        unk1A;       /* +0x1a  func_02028CD4; func_02028F30 and
                             *        func_02028F48 store a u16 argument. */
    u32        unk1C;       /* +0x1c  the latched class.  func_02028F30 stores
                             *        2, func_02028F48 stores 3, func_02028F60
                             *        stores 4 (all EXACT, all full u32
                             *        stores).  func_02028E48 reads it and
                             *        uses it as a permission-table row.
                             *        Also the switch selector in
                             *        func_02028FE0 and func_02029040. */
    u32        pending;     /* +0x20  func_02028D2C spins on it; func_020293D8
                             *        treats the same offset as a SIGNED
                             *        counter (`if (p->f20 <= 0) return;` then
                             *        decrements), so it is s32 there.  The
                             *        signed read is the stronger evidence:
                             *        prefer s32 when writing new C. */
    u32        unk24;       /* +0x24  func_02028CD4 zeroes it; func_020293D8
                             *        declares it u32. */
    struct Cmd queue[10];   /* +0x28  func_02028D7C (stride 12),
                             *        func_02028CD4 (ten iterations),
                             *        func_02028D8C (indexes it). */
    u8         tail;        /* +0xa0  func_02028D7C reads it as a u8 index;
                             *        func_02028D8C names it the read cursor;
                             *        func_02028CD4 zeroes it as a byte. */
    u8         head;        /* +0xa1  func_02028D8C: the write cursor, used as
                             *        `(head + 9) % 10`; func_02028CD4 zeroes
                             *        it as a byte. */
    u16        pad_A2;      /* +0xa2  no matched function touches it */
    void      *unkA4;       /* +0xa4  func_02028844 stores func_02028760()'s
                             *        result; func_02028A14 passes it to
                             *        func_0202878C. */
    void      *unkA8;       /* +0xa8  func_02028844 stores func_02029F14()'s
                             *        result; func_02028A14 passes it to
                             *        func_02029F4C. */
    u32        pad_AC;      /* +0xac  see `slot` below -- the same bytes */
    u32        pad_B0;      /* +0xb0  see `owner` below -- the same bytes */
    u32        unkB4;       /* +0xb4  the claim mask.  func_02028BA0 ORs into
                             *        it, func_02028BDC tests and clears bits
                             *        in it, func_02028CD4 zeroes it.  Always
                             *        a full u32. */
};

/*
 * The +0xac..+0xb3 window is TWO u16[2] tables, not four scalars.  This is
 * the family's one real layout subtlety and func_02028B50's header records
 * why: spelled as two independent `u16 *` locals the compiler recomputes the
 * second address and the frame loses two bytes; as two adjacent u16[2]
 * fields of one struct both accesses share the scaled index register.
 *
 *   u16 slot[2];    +0xac  func_02028B18 compares s->slot[i] against an id;
 *                          func_02028CD4 stores 0xffff into both cells;
 *                          func_02028BA0 and func_02028BDC test for 0xffff.
 *   u16 owner[2];   +0xb0  func_02028B18 stores the owner id into it;
 *                          func_02028B50 clears it to 0xffff alongside slot.
 *
 * The loop bound of TWO is fixed by func_02028B18, func_02028BA0 and
 * func_02028CD4 independently (all EXACT).
 *
 * Both tables are past the Thumb halfword immediate's reach of 62, so every
 * access recomputes `base + index*2` and then adds 0xac or 0xb0 as a separate
 * `adds` -- see docs/idioms/thumb-immediate-reach-costs-an-adds.md.  This is
 * an encoding artefact, never evidence of a second pointer.
 */
struct SysSlots {
    u8  pad[0xac];
    u16 slot[2];    /* +0xac */
    u16 owner[2];   /* +0xb0 */
    u32 mask;       /* +0xb4 */
};

/* ------------------------------------------------------------------ *
 * Global data objects.
 *
 * Every one of these is a `pool` row in layout/data_objects.txt whose ONLY
 * referring pool word image-wide is the one inside the single function that
 * uses it.  A lone reference never contributes its own start, so none of
 * them can be attested by `literal` or by sole-ref/data, and each caps its
 * function at MATCH.  The addresses are recorded here so a later agent does
 * not re-derive them.
 * ------------------------------------------------------------------ */

/* 0x0209FDD0 -- 0x26 halfwords.  Sole referrer: the pool word at 0x02028C4C,
 * inside func_02028C30.  Membership table: func_02028C30 returns 1 when its
 * u32 argument equals any entry. */
extern const u16 sTable_0209FDD0[0x26];

/* 0x0209FD90 -- permission matrix, 8 bytes per row, indexed [class][kind].
 * Sole referrer: the pool word at 0x02028E7C, inside func_02028E48.  The
 * word at 0x0209FD90 is itself zero, so nothing distinguishes the table's
 * start from the run of zeros before it either. */
extern const u8 g_0209FD90[][8];

/* 0x0209FE1C -- the same shape, 8 bytes per row, indexed by Sys.unk04.
 * Sole referrer: the pool word at 0x02028FDC, inside func_02028FD0. */
extern const u8 g_flagTable_0209FE1C[];

/* 0x0209FE94 / 0x0209FE98 -- two views of ONE 8-byte-stride record array of
 * eight entries, read by func_02029E74:
 *   +0x00  u16  key passed to func_020142E8
 *   +0x02  u16  the id the caller matches against
 *   +0x04  u32  the value returned on a hit
 * Sole referrers: the pool words at 0x02029EAC and 0x02029EB0, both inside
 * func_02029E74.  Declaring it as one `struct { u16 a, b; u32 c; } [8]` at
 * 0x0209FE94 does not help: the original loads the two bases from two
 * separate pool words, so the C has to name two objects. */
extern const u8 g_0209FE94[];
extern const u8 g_0209FE98[];

/* __FILE__ anchor for this translation unit, used by func_02028844's
 * allocation call (func_02030734(heap, 0xb8, 1, g_020A7590, 331)).  This is
 * the anchor the family's address range is inferred from. */
extern const char g_020A7590[];

/* ------------------------------------------------------------------ *
 * In-family helper prototypes, with the exact parameter types the matched
 * callers use.  Each line names the matched file it is read from.
 * ------------------------------------------------------------------ */

extern struct Sys  *func_02028844(void *desc, u32 heap);      /* func_02028844 */
extern void         func_02028A14(struct Sys *s);             /* func_02028A14 */
extern void         func_02028ACC(struct Sys *s, u32 id);     /* func_02028ACC */
extern void         func_02028B18(struct Sys *s, u32 id, u32 who); /* func_02028B18 */
extern void         func_02028B50(u8 *p, int id);             /* func_02028B50 */
extern void         func_02028BA0(u8 *o, u32 mask);           /* func_02028BA0 */
extern void         func_02028BDC(u8 *p, u32 mask);           /* func_020293D8 calls it (struct T *, u32) */
extern int          func_02028C30(u32 v);                     /* src/pending/func_02028C30.c */
extern void         func_02028CD4(struct Sys *s, void *desc); /* func_02028CD4 */
extern void         func_02028D2C(struct Sys *s, void *desc); /* func_02028D2C */
extern void        *func_02028D7C(void *obj);                 /* func_02028D7C */
extern struct Cmd  *func_02028D8C(struct Sys *s);             /* func_02028D8C */
extern u32          func_02028DB8(struct Sys *s);             /* func_02028DB8 */
extern void         func_02028E0C(struct Sys *s, struct Cmd *cmd); /* func_02028E0C */
extern u32          func_02028E48(struct Sys *s, u32 kind);   /* func_02028E0C declares it */
extern void         func_02028EAC(int a, int b);              /* func_02028D54 */
extern void         func_02028F30(u8 *p, u32 a);              /* func_02028F30 */
extern void         func_02028F48(u8 *p, u32 a);              /* func_02028F48 */
extern void         func_02028F60(u8 *p, u32 a, u32 b);       /* func_02028F60 */

/*
 * func_02028FD0 -- NOTE THE SIGNATURE.  Its callers (func_02028D54,
 * func_02028F30, func_02028F48, func_02028F60, all EXACT) declare it
 * `int func_02028FD0(u8 *p, u32 kind)` and pass the Sys pointer first.
 * But the body is `ldr r0,[r0,#4]; lsls r2,r0,#3; ldr r0,[pc,#4];
 * adds r0,r0,r2; ldrb r0,[r1,r0]` -- the SECOND argument is the base of
 * the byte load and the table address is the OFFSET register.  So the
 * reproducing C has to spell it `a1[(u32)table + p->unk04 * 8]`, which is
 * what src/pending/func_02028FD0.c does.  The caller-side prototype and the
 * body-side spelling are both correct; they are different views of the same
 * register-offset load.
 */
extern u32          func_02028FD0(void *p, u8 *a1);           /* src/pending/func_02028FD0.c */

extern void         func_02028FE0(struct Sys *p);             /* func_02028FE0 */
extern void         func_02029040(struct Sys *p);             /* func_02029040 */
extern void         func_02029344(struct Sys *p, u32 v);      /* func_02028FE0, func_02029040 */
extern void         func_02029354(struct Sys *p);             /* func_02029040 */
extern void         func_02029364(struct Sys *p);             /* func_02028FE0 */
extern void         func_02029374(struct Sys *p);             /* func_02028FE0 */
extern void         func_0202938C(struct Sys *p);             /* func_02029040 */
extern void         func_020293D8(struct Sys *p);             /* func_020293D8 */
extern void         func_0202945C(void);                      /* func_02028FE0 */
extern u32          func_02029E74(u32 a0, u16 a1);            /* src/pending/func_02029E74.c */

/* ------------------------------------------------------------------ *
 * Out-of-family callees the members reference, with the ISA each matched
 * symbols: block declares.  All thumb unless marked.
 * ------------------------------------------------------------------ */
extern void  func_020061E4(u32 id);                /* func_02028ACC */
extern void  func_020061F0(u32 id, u32 who);       /* func_02028ACC */
extern void  func_020061F8(u32 v);                 /* func_02028BA0, func_02028B50 */
extern u32   func_02006148(int id);                /* func_02028B50, func_02028ACC */
extern void  func_020062BC(u32 slot, u32 who);     /* func_02028B18 */
extern void  func_02005D28(void);                  /* func_02028D2C */
extern void  func_02005DE4(u32 v);                 /* func_020293D8 */
extern void  func_02005E9C(void);                  /* func_020293D8 */
extern void *func_02030734(u32 heap, u32 size, u32 clear,
                           const char *file, u32 line);  /* func_02028844 */
extern u32   func_0201296C(u32 a0);                /* src/pending/func_02029E74.c */
extern u32   func_020142E8(u32 a0, u32 a1);        /* src/pending/func_02029E74.c */

/* Overlay ov021 -- both need the `ov021` region hint as a fourth token on
 * the symbols: line, or more than one labelled candidate is refused rather
 * than guessed at (func_02028ACC, func_02028B18, func_02028B50). */
extern u32   func_021D21C0(u32 id);
extern u32   func_021D21E0(u32 id);

/* mwccarm runtime, ARM.  Declare `arm` in symbols:. */
extern s32   _s32_div_f(s32 a, s32 b);             /* func_02028D8C, func_02028900 */

#endif /* FIELD_SOUND_SYSTEM_H */
