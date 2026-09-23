/*
 * docs/families/areaman.h -- shared declarations for the areaman.c family
 * (0x02033C00..0x02034520 in the ARM9 image; the __FILE__ anchor at
 * 0x020A7958 reads "areaman.c" and is loaded by sub_02033C00, line 0x94).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; match.py never sees
 * it.  Every declaration is derived from a src/matched file that is EXACT,
 * named beside what it evidences.  Written wave 13 from the 17 matched
 * siblings.  Open at the time of writing: func_0203422C (clear a bit range,
 * size-exact, 17 bytes of register rotation) and sub_020343C0 (set a bit
 * range, size-exact, 71 bytes) -- see docs/notes/pkt_0203422C.c.txt and
 * docs/notes/sub_020343C0.c.txt.
 *
 * ISA: ARM throughout.  Compiler: dsi/1.1p1 for every matched member.
 *
 * WHAT THE FAMILY IS.  An AREA MANAGER: a bitmap allocator over `unk00`
 * units, one bit per unit, bit 7 of each byte is the LOWEST unit (the run
 * masks are top-aligned).  Allocation scans forward (sub_02033CFC for runs
 * under 8, sub_02033E30 for 8 and over, dispatched by sub_02033CC0) or
 * backward (sub_02033FB0 / sub_020340D0, dispatched by sub_02033F64) using
 * three 256-entry run-length tables, then marks the run with sub_020343C0.
 * func_0203422C releases a run.  func_02034508 / func_020344C8 are a debug
 * dump that only runs when `unk08` is set; its per-byte hook func_020344C4 is
 * an empty function in this build.
 */

#ifndef AREAMAN_H
#define AREAMAN_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * struct AreaMan -- allocated by sub_02033C00 as nbytes + 0x10.
 * ------------------------------------------------------------------ */
struct AreaMan {
    u16 unk00;      /* 0x00  unit count (bits).  sub_02033CC0 and
                     *       sub_020343C0 bound `start + len` by it (ldrh)   */
    u16 unk02;      /* 0x02  bitmap size in bytes, rounded up to 4
                     *       (sub_02033C00); func_020344C8 walks this many  */
    u32 *guard;     /* 0x04  -> the word just past the bitmap, which holds
                     *       0x573C765A (sub_02033C00)                      */
    u32 unk08;      /* 0x08  debug-dump enable; func_02034508 and
                     *       sub_020343C0's failure path test it            */
    u8  bits[1];    /* 0x0C  the bitmap, bit 7 = lowest unit                */
};

/* ------------------------------------------------------------------ *
 * Tables (rodata).
 * ------------------------------------------------------------------ */
extern const u8 Areaman_RunMask[];  /* 0x020A048C, 9 bytes, top n bits set:
                                     * 00 80 C0 E0 F0 F8 FC FE FF.
                                     * sub_020342F8, sub_02034348,
                                     * sub_02034394; RunMask[0] == 0 is why
                                     * func_0203422C's closing clear needs no
                                     * `if (tail)`.                          */
extern const u8 Areaman_TailMask[]; /* 0x020A0495, low n bits set (the two
                                     * open functions; attested `literal`)   */
extern const u8 g_RunLenHead[256];  /* 0x020A04A0  free run at the top (bit 7
                                     * side) of a byte value                 */
extern const u8 g_RunLenTail[256];  /* 0x020A05A0  free run at the bottom    */
extern const u8 g_RunLenAny[256];   /* 0x020A06A0  longest free run anywhere */
extern const char sub_02033C00_File[]; /* 0x020A7958 "areaman.c"            */

/* ------------------------------------------------------------------ *
 * Prototypes, address order, with the widths the matched files fixed.
 * `start` / `pos` are bit indices.  Scanners return the bit index or -1.
 * ------------------------------------------------------------------ */
struct AreaMan *sub_02033C00(u32 size, u32 heap);  /* create               */
u32 sub_02033C9C(u32 a, u32 b, u32 c, u32 d);      /* free: forwards to
                                                      func_020307B0        */
s32 sub_02033CA8(struct AreaMan *p, u32 len);      /* alloc anywhere       */
s32 sub_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_02033CFC(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_02033E30(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_02033F64(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_02033FB0(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_020340D0(struct AreaMan *p, u32 start, u32 limit, u32 len);
s32 sub_020341F0(struct AreaMan *p, u32 start, u32 len); /* reserve exact  */
void func_0203422C(struct AreaMan *p, u32 start, s32 len);
                    /* release a run (OPEN).  VOID, and it calls
                     * func_02034394 with THREE arguments (q, bit, len): the
                     * len in r2 is a real argument, not a leftover.  With
                     * those two prototypes and `(u8)~mask` on both clears
                     * the body is size-exact (the older note's
                     * func_02034394(q, bit) / s32 return spelling was 8
                     * bytes short).  `start` u32, `len` s32.              */
s32 sub_020342F8(u32 bits, u32 start, u32 len);    /* first free run in a
                                                      byte, scanning down  */
s32 sub_02034348(u32 bits, u32 start, u32 len);    /* same, scanning up    */
void sub_02034394(u8 *q, u32 start, u32 len);      /* clear a run inside
                                                      one byte             */
s32 sub_020343C0(struct AreaMan *p, s32 start, u32 len);
                    /* mark a run (OPEN).  `start` SIGNED (the %8 and /8
                     * quartets), returns 0 when any bit is already set (and
                     * dumps mask and byte through func_020344C4 when unk08),
                     * 1 on success.                                        */
void sub_020344C4(void);                           /* empty hook; callers
                                                      pass it one u8       */
void func_020344C8(struct AreaMan *p);             /* dump every bitmap
                                                      byte when unk08      */
void sub_02034508(struct AreaMan *p);              /* callers pass
                                                      (p, pos, len, line);
                                                      only p is read       */

#endif /* AREAMAN_H */
