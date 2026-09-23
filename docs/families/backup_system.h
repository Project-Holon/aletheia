/*
 * docs/families/backup_system.h -- shared declarations for the
 * backup_system.c / savedata.c family (0x020316C8..0x020334E8 in the ARM9
 * image; the __FILE__ anchor at 0x020A7848 reads "backup_system.c" and is
 * loaded by func_020316C8 (pool word at 0x02031744, line 0xdf),
 * func_0203174C (lines 0x10e/0x125/0x131/0x154-0x3e), func_020319F0 (line
 * 0x1e8) and func_02032688 (per docs/notes/pkt_02031FE0.c.txt)).  Several
 * matched sources further down the range (0x02032930 onward) label
 * themselves "savedata.c" in their header comments; they share the exact
 * same struct and the same global at 0x02146994/g_02146994, so this file
 * treats backup_system.c and savedata.c as one family rather than splitting
 * the header.  Edges are fuzzy: 0x02031FE0/0x02032688 (the verifier) and
 * 0x02032CD0 (the 1220-byte state-machine dispatcher, EXACT since
 * 2026-09-23) are read but not all matched -- see docs/notes/pkt_02031FE0.c.txt, pkt_02032CD0.c.txt and
 * pkt_02031C30.c.txt -- and are recorded here only where a matched caller's
 * evidence reaches into them (return values, field offsets).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT, and the matched
 * function that evidences each field or parameter is named in the comment
 * beside it.  Where two matched sources spell the same field differently
 * (they were written by different lanes), the spelling recorded here is the
 * one the byte evidence actually constrains, and the conflict is noted.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef BACKUP_SYSTEM_H
#define BACKUP_SYSTEM_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * struct SaveBackup -- the ONE object the whole family operates on.
 *
 * There is exactly one live instance, allocated by func_020316C8 and kept
 * at the module global (spelled g_02146994 by the constructor lane,
 * unk_02146994 by the savedata.c lane -- same address, same object; this
 * header keeps both extern spellings below since both are how the matched
 * sources declare it).  func_020316C8 allocates 0x210 bytes total: the
 * first 4 bytes are a sequence/CRC-table word written by func_02033534,
 * then 0x1100 - 0xdf of the body is memset by func_020819B8, then three
 * trailing fields at +0x204 (heap id), +0x208 (device handle) and +0x20C
 * (a halfword sub_020331D0 hands to func_0203386C) are set explicitly.
 * This 0x210-byte block is the OUTER container; struct SaveBackup below is
 * the inner backup-record object whose own base is the SAME pointer
 * (offset 0 of the container), evidenced by func_0203174C building a 0x154-
 * byte record at that same base with fields f00.. f140 whose offsets equal
 * this struct's unk10.. unk144, i.e. the constructor's `f00` family (named
 * f00/f04/f08/f0c/f1c/f1d/f24/f28/f2c/f30/f34/f138/f13c/f140 in
 * src/matched/func_0203174C.c) and the savedata.c lane's `unk` family
 * (named unk10/unk14/unk18/unk19/unk1c/unk28/unk2c/unk30/unk34/unk140 in
 * src/matched/sub_02032970.c, sub_020331A4.c, sub_020328E0.c and others)
 * are THE SAME FIELDS at the SAME OFFSETS.  FIELD-SPELLING CONFLICT: the
 * constructor lane's offsets are all 0x10 LOWER than the savedata.c lane's
 * (f00 vs unk10, f04 vs unk14, ... f34 vs unk34, f140 vs unk140).  The byte
 * evidence resolves this: func_0203174C allocates the record at
 * func_02030734(heap, 0x154, ...) and immediately fills what IT calls f00
 * from in->f08 -- i.e. func_0203174C's own struct `In` (the 5-argument
 * packed constructor input) is a SEPARATE, smaller object whose fields are
 * copied into the record starting 0x10 bytes into the record's true layout
 * (there is a 0x10-byte gap in func_0203174C's own `Blk` struct, `pad10`
 * running 0x10..0x1c... but the real gap the constructor never names is
 * 0x00..0x10, filled by func_02033908/func_02033BF8/the manager linkage
 * touched by the CALLERS of this record, not by func_0203174C itself).
 * Because the savedata.c lane's unk10.. spelling is corroborated by SEVEN
 * independent matched files (sub_02032970, sub_020331A4, sub_020328E0,
 * sub_02033200, sub_020332A4, sub_02032C84, sub_02032BF8, sub_02032930,
 * sub_02033264, sub_02032A9C) against func_0203174C's single file, THIS
 * HEADER USES THE unk10-BASED OFFSETS as the struct's canonical layout and
 * treats func_0203174C's f00..f34 as a documentation alias for unk10..unk34
 * shifted by -0x10 (see the comment on each field below).
 * ------------------------------------------------------------------ */
struct SaveBackup {
    u8   pad00[0x10];      /* +0x00  untouched by any matched source in this
                            *        family; func_0203174C's own record
                            *        pointer starts here but its named
                            *        fields (f00 == this struct's unk10)
                            *        begin 0x10 bytes in. */
    u32  unk10;             /* +0x10  the generation being written.
                             *        func_0203174C's f00 = in->f08.
                             *        sub_02032970 stores the pre-bump
                             *        generation here; sub_020331A4 and
                             *        sub_020331D0 copy it back into unk28
                             *        on write completion. */
    u32  unk14;             /* +0x14  func_0203174C's f04 = in->f0c.
                             *        sub_02032970 clears it when opening a
                             *        new generation. */
    u8   unk18;             /* +0x18  the STATE BYTE the 12-case dispatcher
                             *        at 0x02032CD0 switches on (see
                             *        docs/notes/pkt_02032CD0.c.txt).
                             *        func_0203174C's f1c is the SAME field
                             *        shifted (-0x10): f1c is written 0 by
                             *        the constructor.  sub_02032970 clears
                             *        it when opening a generation. */
    u8   unk19;             /* +0x19  func_0203174C's f1d: the "allocated a
                             *        scratch buffer, must free it" flag (0
                             *        when a caller-supplied buffer `c` was
                             *        passed to func_0203174C, 1 when the
                             *        constructor allocated its own).
                             *        sub_02032970 clears it when opening a
                             *        generation. */
    u8   pad1A[2];
    u8   unk1C;             /* +0x1C  the FAILURE byte: sub_020331A4 sets it
                             *        to 1 on any write-completion result
                             *        other than 3. */
    u8   pad1D[11];
    u32  unk28;             /* +0x28  the RUNNING GENERATION COUNTER.
                             *        func_0203174C's f24 is initialised to
                             *        0.  sub_02032970 reads it, stores the
                             *        pre-increment value into unk10 (the
                             *        "generation this write carries") and
                             *        writes back gen+1.  sub_020331A4 and
                             *        sub_020331D0 roll it back to unk10 on
                             *        a successful (result == 3) or
                             *        unconditional completion. */
    u8   pad2C_gap[4];
    u32  unk2C;             /* +0x2C  POINTER to the record/size table
                             *        (func_02033B68/func_02033BAC/
                             *        func_020332FC/sub_020332FC all index
                             *        through it).  func_0203174C's f2c is
                             *        the return of func_02033908(heap,
                             *        in->f00, in->f04, b->f08, 0x10, 4,
                             *        f140) -- i.e. the table is BUILT by
                             *        the constructor from the caller's
                             *        record list (`in->f00`, count
                             *        `in->f04`). */
    u32  unk30;             /* +0x30  the BACKUP AREA'S base/length driver.
                             *        func_02031EAC(p, sel) reads *this*
                             *        field (its own p[0]) and unk34's
                             *        table analog (p[1]) and answers one or
                             *        the other depending on `sel` and
                             *        whether the two agree -- see
                             *        "the length accessor" below.
                             *        func_0203174C's f08 = in->f10. */
    u32  unk34;             /* +0x34  the STAGING BUFFER pointer (`buf`
                             *        parameter of func_02031E7C,
                             *        func_02032930's `p->unk34 + (area-1)`,
                             *        sub_020332A4's `buf`).
                             *        func_0203174C's f0c = in->f14. */
    u8   pad38[0x108];
    u32  unk140;            /* +0x140  the TRAILING BLOCK LENGTH: the CRC
                             *         window size in func_02031E7C, the
                             *         write length in sub_02032C84.
                             *         func_0203174C's f130 == in->f04-
                             *         derived rounding (`f140 = in->f04*2`,
                             *         +2 if odd) is the SAME field: the
                             *         constructor computes the initial
                             *         value savedata.c later reads. */
    u8   pad144[8];
    u32  unk144;            /* +0x144  func_02031E68's whole return value
                             *         (`*(int*)(ptr+0x144)`); read-only in
                             *         this family's matched sources. */
};                          /* size unknown past +0x148; func_0203174C's
                            * container additionally carries f138 (scratch
                            * buffer pointer, == unk138) and f13c (its
                            * rounded size, == unk13c) immediately before
                            * unk140, both allocated by func_0203174C at
                            * lines 0x125/0x131 and read by no OTHER matched
                            * file in this family, so they are left as an
                            * unnamed gap in `pad38` above rather than
                            * guessed into named fields. */

/* struct SaveMain -- the CONTAINER header at the front of the SAME 0x210-
 * byte allocation as struct SaveBackup (offset 0 of one is offset 0 of the
 * other; SaveBackup's own body begins at its own +0x10, which is why every
 * matched file that reaches +0x204/+0x208/+0x20C declares its OWN struct
 * ending exactly there rather than reusing SaveBackup -- kept separate here
 * for the same reason). */
struct SaveMain {
    u8   pad000[0x204];
    u32  unk204;            /* +0x204  the HEAP ID.  func_020316C8:
                             *         *(u32*)(g_02146994+0x204) = a1.
                             *         func_020334E8 and sub_02032A9C read
                             *         it as the flash-read handle. */
    u32  unk208;            /* +0x208  the DEVICE/FLASH HANDLE.
                             *         func_020316C8: *(u32*)(g_02146994+
                             *         0x208) = a2.  func_020319F0 reads it
                             *         as the erase target; sub_02032BF8,
                             *         sub_02033200, sub_02032C84,
                             *         sub_02032930, sub_020328E0 all pass
                             *         it as the flash-write handle. */
    u16  unk20C;            /* +0x20C  a halfword sub_020331D0 hands to
                             *         func_0203386C (`add r0,r0,#0x200;
                             *         ldrh r0,[r0,#0xc]` -- the Thumb-era
                             *         load reach through the pool base,
                             *         per docs/idioms/pool-base-for-a-far-
                             *         field-is-the-symbol-offset-masked-by-
                             *         the-load-reach.md). */
};

/* struct CrcTable -- the CRC-16/CCITT table object, ALSO reached through
 * the same 0x02146994 global but read as a SEPARATE small-header shape by
 * func_02031E7C and sub_020332A4 (`pad000[4]; crcTable[1]` -- the table
 * itself is inline data starting at +4, consumed by MATH_CalcCRC16CCITT and
 * never sized past its first byte in the matched sources). */
struct CrcTable {
    u8 pad000[4];
    u8 crcTable[1];         /* +0x04  MATH_CalcCRC16CCITT's table argument;
                             *        func_02031E7C, sub_020332A4. */
};

/* struct Job -- func_020319F0's own erase-job parameter, distinct from
 * SaveBackup (it is caller-owned, not the module global). */
struct Job {
    u32 f00;                /* +0x00  destination base (flash offset). */
    u32 f04;                /* +0x04  a second length; if (f00 != f04)
                             *        triggers an extra func_02033200(job,2)
                             *        pass before the fill (func_020319F0). */
    u32 f08;                /* +0x08  total length, drives the erase loop's
                             *        page count. */
    u8  pad_0c[0x10];
    u8  f1c;                /* +0x1c  cleared to 0 at the end of
                             *        func_020319F0 (mirrors SaveBackup's
                             *        unk18-family state byte pattern but on
                             *        the job object). */
};

/* struct Blk_In -- func_0203174C's 5-word constructor-input record (the
 * `in` parameter).  Only fields the matched source reads are named. */
struct Blk_In {
    u32 f00;                /* +0x00  passed through to func_02033908 as
                             *        the record list. */
    u32 f04;                /* +0x04  record count; also the source of the
                             *        f140/f13c size roundings. */
    u32 f08;                /* +0x08  copied into the record's unk10
                             *        (generation seed). */
    u32 f0c;                /* +0x0c  copied into the record's unk14. */
    u32 f10;                /* +0x10  copied into the record's unk30 (area
                             *        base/length driver). */
    u32 f14;                /* +0x14  copied into the record's unk34
                             *        (staging buffer). */
};

/* ------------------------------------------------------------------ *
 * THE STATE BYTE AT SaveBackup::unk18 -- state-machine values.
 *
 * The 12-case dispatcher at 0x02032CD0 (docs/notes/pkt_02032CD0.c.txt) and
 * its caller func_02031C30 (docs/notes/pkt_02031C30.c.txt, a 6-arm dispatch
 * on the SAME byte at +0x1e of a DIFFERENT, smaller "q" object that the
 * matched files in this family do not reach) both switch on a byte in this
 * family's records.  Only the values the MATCHED sources evidence are
 * recorded as constants; the rest are read-only observations from the
 * notes, kept as comments rather than #defines since no matched .c proves
 * them for SaveBackup::unk18 specifically.
 * ------------------------------------------------------------------ */
#define SAVE_BACKUP_RESULT_CONTINUE  0   /* func_02032688's `pair[0]`: keep
                                          * walking the record loop
                                          * (docs/notes/pkt_02031FE0.c.txt). */
#define SAVE_BACKUP_RESULT_ACCEPT    1   /* `pair[0] == 1`: accept path,
                                          * returns 3 (running-check
                                          * disagreement per
                                          * func_02031EF8's own convention). */
#define SAVE_BACKUP_RESULT_FORCED    2   /* `pair[0] == 2`: forced mismatch
                                          * (length/sequence disagreement,
                                          * func_02031EF8's convention). */

#define SAVE_STEP_MORE     0   /* sub_02032A9C / func_02032A9C's shared step
                                * protocol: 0 = call again (budget not yet
                                * crossed). */
#define SAVE_STEP_FAIL     1   /* 1 = read or write failure. */
#define SAVE_STEP_DONE     2   /* 2 = record exhausted; drop this record's
                                * contribution when returned from the
                                * accounting walk (sub_020329AC). */

#define SAVE_WRITE_OK      3   /* sub_020331A4 / sub_020331D0's completion
                                * result: 3 = success, generation is kept;
                                * any other value raises SaveBackup::unk1C. */

/* ------------------------------------------------------------------ *
 * Constants.
 * ------------------------------------------------------------------ */
#define SAVE_RECORD_SIZE        0x154   /* func_0203174C's allocation size
                                         * for one backup record (b in that
                                         * file). */
#define SAVE_CONTAINER_SIZE     0x210   /* func_020316C8's allocation size
                                         * for the whole module object. */
#define SAVE_ERASE_PAGE_SIZE    0x1000  /* func_020319F0's scratch page and
                                         * device page size. */
#define SAVE_CHUNK_SIZE         0x100   /* sub_02032A9C's per-iteration
                                         * Flash read chunk. */
#define SAVE_STEP_BUDGET        0x800   /* sub_02032A9C's running byte
                                         * budget before a step must yield
                                         * (answers SAVE_STEP_MORE with
                                         * progress written back). */
#define SAVE_FOOTER_SIZE        0x10    /* sub_02033200's footer-blank
                                         * length; sub_020328E0's footer
                                         * write length is one byte short of
                                         * it, 0xF, matching the trailing
                                         * CRC halfword's own byte. */

extern struct SaveMain  *g_02146994;      /* 0x02146994, data: also
                                           * declared `unk_02146994` by the
                                           * savedata.c lane (same address,
                                           * same object -- see struct
                                           * SaveBackup's header comment). */
extern struct SaveMain  *unk_02146994;    /* 0x02146994, data: savedata.c
                                           * lane's spelling of the same
                                           * global. */

extern const char str_020A7848[];   /* "backup_system.c", the __FILE__
                                     * (func_020316C8, func_0203174C,
                                     * func_020319F0). */
extern const char str_020A7858[];   /* func_0203174C's first assert
                                     * message. */
extern const char str_020A7868[];   /* func_0203174C's second assert
                                     * message. */

/* ------------------------------------------------------------------ *
 * Prototypes, in address order.  Parameter types are the ones the byte
 * evidence constrains; a parameter written `u32 aN` is one the function
 * receives and does not use.
 * ------------------------------------------------------------------ */

/* 0x020316C8  one-time module bring-up: allocate the 0x210-byte container,
 * zero it, memset the body, stash the heap id and device handle, seed the
 * sequence word from func_02033534. */
void func_020316C8(u32 heap, u32 heap_id, u32 device_handle);

/* 0x0203174C  the save-block constructor: allocate one SAVE_RECORD_SIZE
 * record from `in`, build its record table through func_02033908, and
 * dispatch to func_020319C0 (teardown-and-commit path, e==1) or
 * func_02033410(b,1) (any other e). */
struct SaveBackup *func_0203174C(const struct Blk_In *in, u32 heap, u32 c,
                                 u32 d, u32 e);

/* 0x0203192C  one-line forwarder to func_0203174C with c=0, d=0, e=1. */
u32 func_0203192C(void *a, void *b);

/* 0x0203195C  four-store teardown: release unk2C (the record table)
 * through func_020339B4, release unk138 unconditionally, release unk34
 * only when unk19 (formerly f1d) reads 1, then release the record itself.
 * EXACT* -- the inferred extent runs into the unlabelled leaf follower at
 * 0x02031994. */
void func_0203195C(u8 *p);

/* 0x02031994  leaf follower of func_0203195C, no prologue: two-field
 * getter, out[0] = *(p+0x30), returns *(p+0x34) (i.e. unk30/unk34). */
u32 func_02031994(u8 *p, u32 *out);

/* 0x020319A4  func_02033B68(p->unk2C) + p->unk34 -- resolves a staging
 * buffer address relative to the record table base. */
u32 func_020319A4(u8 *p);

/* 0x020319C0  commit path: forward (unk34, unk2C) to func_020339D0, then
 * func_02033410(p, 1). */
void func_020319C0(u8 *p);

/* 0x020319F0  erase the whole backup device in SAVE_ERASE_PAGE_SIZE pages;
 * allocates a scratch page, fills it 0xFF, writes it over every page named
 * by job->f08 at job->f00, clears job->f1c, drops the busy flag. */
int func_020319F0(struct Job *job, u32 heap);

/* 0x02031AE0  dispatch one state-machine step (manager-table variant): if
 * the manager global's front object is unarmed, report 4; otherwise call
 * func_02031FE0 or func_02032688 depending on whether o->f00 == o->f04,
 * and translate the result (1/2 stamp o->f1c = 1). */
int func_02031AE0(struct { u32 f00; u32 f04; u8 pad08[0x14]; u8 f1c; } *o,
                  u32 a1);

/* 0x02031B8C  conditionally open a new generation: if the manager global is
 * non-null, call func_02032970(p, 1). */
void func_02031B8C(u8 *p);

/* 0x02031BB4  verifier gate: return 3 if the global is null; otherwise call
 * func_02032CD0(a0, &v) and, for any result other than 0 or 1, report the
 * result through func_020331A4(a0, r, 1). */
int func_02031BB4(u32 a0);

/* 0x02031C04  forwards to func_020331D0 (unconditional generation-rollback
 * completion). */
void func_02031C04(void);

/* 0x02031C10  arm two footer flags: write `v` at a+0x20, then a[0x1e]=0,
 * a[0x1f]=2, b[0x1e]=0, b[0x1f]=2 (two footer/state pairs, same shape as
 * the state-machine's f1e/f1f byte pair func_02031C30 dispatches on -- see
 * docs/notes/pkt_02031C30.c.txt). */
void func_02031C10(u8 *a, u8 *b, u32 v);

/* 0x02031DC0  dispatch one state-machine step (engine-pointer variant, the
 * `Obj02031DC0`-shaped twin of func_02031AE0): a null engine (*g_02146994
 * used AS A u32* here, not as struct SaveMain*) reports 4; the object's
 * f00/f04 pick func_02031FE0 or func_02032688, with a hard 1 passed as
 * their flag argument (vs func_02031AE0's 0); same 1/2/3/0/4 status
 * translation.  EXACT*: inferred extent runs into the unlabelled follower
 * at 0x02031E68. */
int func_02031DC0(struct { u32 f00; u32 f04; u8 pad08[0x14]; u8 f1c; } *a0,
                  u32 a1, u32 a2);

/* 0x02031E68  unlabelled follower of func_02031DC0: return *(int*)(ptr +
 * 0x144), i.e. SaveBackup::unk144. */
int func_02031E68(const char *ptr);

/* 0x02031E7C  CRC-16/CCITT of one backup record's trailing block: table is
 * unk_02146994's inline crcTable (+4), data runs from
 * buf + (p->unk30 - SAVE_FOOTER_SIZE - p->unk140) for p->unk140 bytes. */
u16 func_02031E7C(struct SaveBackup *p, u8 *buf);

/* 0x02031EAC  the length accessor: reports p[1] (unk34's table analogue)
 * when p[0] == p[1]; otherwise reports p[1] only when sel == 2, else p[0].
 * Two-argument prototype is the one two-argument caller (sub_02033200)
 * proves against; some callers pass only p and rely on the leftover
 * argument. */
u32 func_02031EAC(u32 *p, u32 sel);

/* 0x02031EC  0x02031ECC -- halfword-table getter: *(p+52) + ((*(p+48) -
 * SAVE_FOOTER_SIZE) - *(p+320)), i.e. an offset computed from unk34,
 * unk30 and a +320(0x140) field peer. */
int func_02031ECC(int p0, int p1, int p2, int p3);

/* 0x02031EE8  footer-descriptor accessor: p1 + (*(p0+48) - SAVE_FOOTER_
 * SIZE), i.e. buf + (unk30 - 0x10). */
int func_02031EE8(int p0, int p1, int p2, int p3);

/* 0x02031EF8  verify one copy of a backup area against its footer
 * descriptor (from func_02031EE8): 2 if the length (+4) or sequence number
 * (+8, unk0C) disagree, 1 if the running CRC (+0xE, via func_02031E7C)
 * disagrees, 0 if both agree.  Third parameter is dead in the body but kept
 * for prototype parity with sub_02031F9C. */
u32 func_02031EF8(void *p, void *buf, u32 sel);

/* 0x02031F94  p[10] = v, i.e. SaveBackup's word at +0x28 (unk28,
 * "the running generation counter"), written by index rather than by
 * struct field in this lane. */
void func_02031F94(int *p, int v);

/* 0x02031F9C  fill a two-word record descriptor `out`: out[0] =
 * func_02031EF8(p, buf, sel) (verification answer), out[1] = the footer
 * descriptor's first word (via func_02031EE8). */
void func_02031F9C(u32 *out, void *p, void *buf, u32 sel);

/* 0x02031FE0 / 0x02032688  see the DIFF entry further down (2026-09-23). */

/* 0x02032930  the one-byte twin of sub_020328E0: writes the SINGLE trailing
 * byte of a record's footer without refreshing the CRC first. */
void sub_02032930(struct SaveBackup *p);

/* 0x02032970  open a new backup generation: clear unk18/unk14/unk19/unk144,
 * remember the outgoing generation in unk10, bump unk28, and raise the busy
 * flag via func_02034F84 when flag == 1. */
void sub_02032970(struct SaveBackup *p, u32 flag);

/* 0x02032A9C  one resumable step of a record copy out of Flash into the
 * 0x38 staging area, SAVE_CHUNK_SIZE bytes at a time, yielding at
 * SAVE_STEP_BUDGET accumulated bytes.  Returns SAVE_STEP_DONE/_FAIL/_MORE. */
u32 sub_02032A9C(struct SaveBackup *p, u32 id, u32 mode, u32 *pa, u32 *pb,
                 u32 *pc, u32 *pd);

/* 0x02032BF8  commit one record of a backup generation: refresh its CRC
 * (sub_020332A4), file it in the halfword table func_02031ECC owns, and
 * write the record (payload + 4 trailing bytes) to its Flash offset. */
void sub_02032BF8(struct SaveBackup *p, u32 id, u32 x);

/* 0x02032C84  write the trailing SAVE-record block: length unk140,
 * destination unk140 bytes back from the end of the area, source from
 * func_02031ECC. */
void sub_02032C84(struct SaveBackup *p);

/* 0x02032CD0  EXACT 2026-09-23 (src/matched/func_02032CD0.c).  The save
 * WRITE state machine, one step per call, switching on the byte at +0x18:
 *   0-1 pump non-resident records through sub_02032A9C (its 7th argument is
 *       a yield flag; the resumable-copy progress lives at +0x148/+0x14C/
 *       +0x150 and the record cursor at +0x14), 2-4 start each marked
 *       record's write (sub_02032BF8(p, id, mark, p->f19)) and poll it,
 *       summing sizes into +0x144, 5-6 trailing block, 7-8 footer (answers 1),
 *       9-10 footer byte, then either swap marks (sub_0203335C) and restart at
 *       2 with *out = 1, or finish (func_020333F8) and answer 2.
 * The write handle is a u16 at g_02146994+0x20C (SaveMain::unk20C) and every
 * poll is func_020337B8(unk20C, &status, unk208).  A failed poll answers 3
 * (2 once +0x19, the copy counter, is non-zero). */
int func_02032CD0(struct SaveBackup *p, u32 *out);

/* 0x02031C30  EXACT 2026-09-23.  Drives TWO save records (q, p -- the same
 * type) through func_02032CD0 on q's byte +0x1E, with +0x1F as p's result
 * byte and +0x20 a pointer that receives p's +0x28 generation. */
int func_02031C30(struct SaveBackup *q, struct SaveBackup *p);

/* 0x02031F54  DIFF (16 bytes, scheduling).  Writes the footer
 *   struct Footer { u32 gen; u32 size; u32 id; u16 pad; u16 crc; };
 * at func_02031EE8(p, buf): gen = +0x28, size = +0x30, id = +0x0C,
 * crc = func_02031E7C(p, buf).  The struct-typed footer gets the registers
 * right (the byte-offset spelling does not). */

/* 0x02031FE0 / 0x02032688  DIFF, both size-exact (42 and 10 bytes), best
 * sources in docs/notes/pkt_02031FE0.c.txt.  0x02031FE0 is the full load:
 * read BOTH copies (func_020335E8 with func_02031EAC(self, 1) into +0x34 and
 * (self, 2) into a heap block), repair a failed read from the other copy,
 * check both footers (func_02031F9C x2), pick the newer good copy, walk every
 * record against both, mark 0/1/2 via func_0203331C, copy good records back
 * and commit the generation (func_02031F94).  0x02032688 is the one-copy
 * variant.  +0x34 is a u8 * (the staging buffer). */

/* 0x020329AC  walk every record of the save table, reporting nominal size
 * and size-actually-accounted-for through two out-parameters; records not
 * yet resident (func_020332FC == 0) are pumped through sub_02032A9C until
 * it stops answering SAVE_STEP_MORE. */
void sub_020329AC(struct SaveBackup *p, u32 *total, u32 *nominal);

/* 0x02033200  blank the SAVE_FOOTER_SIZE-byte footer of a backup record
 * with an all-0xFF block. */
void sub_02033200(struct SaveBackup *p, u32 id);

/* 0x02033264  bump the halfword counter at the head of one staging-buffer
 * record and answer the new value (read back from the store, not the
 * incremented register). */
u16 sub_02033264(struct SaveBackup *p, u32 id);

/* 0x020331A4  backup-write completion callback: on result == SAVE_WRITE_OK
 * roll unk28 back to unk10; otherwise raise unk1C.  Drops the busy flag via
 * func_02034FB8 when flag == 1. */
void sub_020331A4(struct SaveBackup *p, u32 result, u32 flag);

/* 0x020331D0  the unconditional twin of sub_020331A4: always roll unk28
 * back to unk10, hand SaveMain::unk20C to func_0203386C, and always drop
 * the busy flag. PARKED AT MATCH (one open `bl` site, no outside witness),
 * kept for completeness since its C is fully known. */
void sub_020331D0(struct SaveBackup *p);

/* 0x020332A4  recompute the CRC-16/CCITT of one record in the staging
 * buffer and store it in the halfword following the record; returns the
 * stored value read back. */
u16 sub_020332A4(struct SaveBackup *p, u32 id);

/* 0x020332FC  packed 2-bit-per-slot getter: bit position (idx&0xf)*2 of
 * word idx>>4 of the array at object offset 0x138 (a whole matched
 * translation unit; the companion setter at 0x0203331C is its immediate
 * successor in the same file and NOT itself matched). */
u32 sub_020332FC(struct { char pad[0x138]; u32 *slots; } *p, u32 idx);

/* 0x02033478  forward (a0,a1,a2, the device handle at *(u32*)(0x02146994)
 * +0x208) to func_020335AC. */
void func_02033478(int a0, int a1, int a2, int a3);

/* 0x020333F8  forward (0, *(a0+312), *(a0+316), a3) to func_02082A7C. */
void func_020333F8(int a0, int a1, int a2, int a3);

/* 0x020334E8  compose a Flash read: n = func_02031EAC(p, c+1), m =
 * func_02033B68(p->unk2C-analogue, b), then func_020335E8(n+m, d, e,
 * g_02146994->unk204). */
void func_020334E8(u8 *p, u32 b, u32 c, u32 d, u32 e);

#endif /* BACKUP_SYSTEM_H */
