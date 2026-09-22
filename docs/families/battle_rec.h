/*
 * docs/families/battle_rec.h -- shared declarations for the battle_rec.c
 * family (battle recording / replay save records), 0x0200B3DC..0x0200C4E8
 * in the ARM9 image.  Edges are fuzzy by a function or two at both ends.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  It is the adjudicated
 * union of the declarations the family's byte-exact sources already carry,
 * written down once so a new attempt on an open function starts from the
 * settled shape instead of re-deriving it.
 *
 * Derived from the 48 matched sources found with
 *   grep -l "address:  0x0200B[3-9A-F]\|address:  0x0200C[0-4]" src/matched/*.c
 * Each declaration names the matched function that evidences it.
 */

#ifndef BATTLE_REC_H
#define BATTLE_REC_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE RECORD OBJECT.  The three nested pieces are settled and their sizes
 * close exactly against the allocation:
 *
 *     0x80                 the header block
 *     + 0x44  struct QRec  the per-battle queue record
 *     + ...   struct RecC4 the replay payload
 *
 * struct QRec's own size is 0x44, which is what makes unkC4 land at
 * 0x80 + 0x44 = 0xC4 -- the offset the struct is named for, and the
 * arithmetic that confirms the header is exactly 0x80 and not merely
 * padded to it.
 * ------------------------------------------------------------------ */

struct QRec {                   /* 0x44 bytes                             */
    u16 unk00[0x0C];            /* +0x00                                  */
    u8  unk18[0x0C];            /* +0x18                                  */
    u16 unk24;                  /* +0x24                                  */
    u16 unk26;                  /* +0x26                                  */
    u16 unk28;                  /* +0x28                                  */
    u8  unk2A;                  /* +0x2A                                  */
    u8  unk2B;                  /* +0x2B                                  */
    u8  unk2C[0x0C];            /* +0x2C                                  */
    u8  unk38[8];               /* +0x38                                  */
    u16 unk40;                  /* +0x40                                  */
    u16 unk42;                  /* +0x42                                  */
};

/*
 * struct RecC4 -- TWO SPELLINGS IN THE MATCHED SET, AND THEY DISAGREE.
 * Recorded honestly rather than merged, because the difference is real:
 *
 *   spelling A   u8 unk0000[0x17D8]; u16 unk17D8, unk17DA, unk17DC, unk17DE;
 *   spelling B   u8 unk0000[0x17DC]; u16 unk17DC; u8 unk17DE[2];
 *
 * They agree on the total size (0x17E0) and on unk17DC being a halfword.
 * They differ on whether +0x17D8 and +0x17DA are two separate halfwords or
 * part of the opaque head.  Spelling A is preferred here because a file
 * that names a field has at least looked at it, while spelling B's longer
 * array only means its own file never touched those four bytes -- but NO
 * matched file yet loads +0x17D8 or +0x17DA, so neither spelling is
 * actually constrained by an instruction.  Per the adjudication rule a
 * name does not constrain a field; treat +0x17D8..+0x17DB as open.
 */
struct RecC4 {
    u8  unk0000[0x17D8];
    u16 unk17D8;                /* OPEN: no matched file loads it         */
    u16 unk17DA;                /* OPEN: no matched file loads it         */
    u16 unk17DC;                /* both spellings agree this is a halfword */
    u16 unk17DE;
};

struct BattleRec {
    u8  unk00[0x80];            /* +0x0000  the header block              */
    struct QRec  unk80;         /* +0x0080  0x44 bytes                    */
    struct RecC4 unkC4;         /* +0x00C4  the replay payload            */
};

/* ------------------------------------------------------------------ *
 * THE 32-ENTRY LIST, cleared as a unit.
 *
 * func_0200B37C clears it: `header = -1` then 32 zeroed entries.  The -1
 * sentinel in the header word (not 0) is what distinguishes "empty" from
 * "entry 0", and func_0200B394 returns `entries` -- the array, not the
 * struct -- which is what fixes the header at exactly one word before it.
 * Two matched files spell the same object at two widths; both are below
 * because each is what its own file compiles against.
 * ------------------------------------------------------------------ */
struct Struct_0200B37C {
    int header;                 /* +0x00  set to -1, never 0              */
    int entries[32];            /* +0x04                                  */
};

struct Rec94 {                  /* the same object with a 0x10-byte tail  */
    s32 unk00;                  /* +0x00  the same -1 header              */
    s32 unk04[32];              /* +0x04                                  */
    u8  unk84[0x10];            /* +0x84                                  */
};

/* ------------------------------------------------------------------ *
 * HELPER PROTOTYPES.  Parameter widths matter: a helper's parameter
 * declared u16 instead of u32 changes the CALLER's masking.  Each spelling
 * below is the one its matched caller compiles against.
 * ------------------------------------------------------------------ */

/* Construction and teardown. */
extern struct BattleRec *func_0200B3DC(u32 heap);
extern void  func_0200B448(void *p);
extern void  func_0200B37C(struct Struct_0200B37C *p);
extern s32  *func_0200B394(struct Rec94 *p, s32 value);
extern void  func_0200BA44(struct RecC4 *p);

/* The record/replay path. */
extern void  func_0200B7D8(void *h, struct QRec *q, const struct RecC4 *src,
                           u32 mode, u32 e);
extern void  func_0200B900(void *a, u32 b, u32 c, u32 d);
extern void  func_0200B908(void *a, u32 b, u32 c);
extern u32   func_0200B888(void *a, void *b);
extern u32   func_0200B8AC(void *a, void *b);

/* The save-slot bridge.  func_0200725C and func_020072CC are the two
 * outside entry points this family is reached through. */
extern struct BattleRec *func_020073D8(void *save, u32 id, u32 c);
extern u32   func_0200725C(void *save, u32 id, u32 heap);
extern u32   func_020072CC(void *save, u32 id, u32 heap, void *buf, u32 size);
extern void  func_02007324(void *h, u32 c, u16 e, void *p, u32 size);
extern void  func_0200734C(void *h, u32 c);

/* Checksums over a byte range.  Both return u16 and take a byte size; the
 * u16 return is what forces the callers' truncation at the comparison. */
extern u16   func_0203F1FC(const void *src, u32 size);
extern u32   func_0203F2FC(const void *src, u32 size);

/* Mon / list accessors, outside the family. */
extern u32   func_02017E88(void *e, u32 a, u32 b);
extern u32   func_0201AA18(void *list);
extern void *func_02012EBC(void *a);
extern void  func_02012E4C(void *a, u32 c);
extern u32   func_02012E7C(void *a, u32 c);

/* SDK. */
extern void  MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void  MI_CpuFill8(void *dest, u8 value, u32 size);
extern u16   GX_GetBankForLCDC(void);

/* ------------------------------------------------------------------ *
 * GLOBALS
 * ------------------------------------------------------------------ */
extern struct BattleRec *gObj_0214616C;     /* the singleton record.  One
                                             * matched file declares it as
                                             * `struct ObjC4 *` instead;
                                             * same address, same object,
                                             * a narrower view of it       */
extern const u16 func_0200B784_Table[];     /* rodata selector tables, both
                                             * attested as data            */
extern const u16 func_0200B98C_Table[];
extern const char func_0200B3DC_File[];     /* the "battle_rec.c" __FILE__
                                             * anchor                      */

#endif /* BATTLE_REC_H */
