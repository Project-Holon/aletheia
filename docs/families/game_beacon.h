/*
 * docs/families/game_beacon.h -- shared declarations for the game_beacon.c
 * family (0x020266E0..0x020274C8 in the ARM9 image), the wireless BEACON
 * subsystem: the per-frame ring of received beacon records, the beacon the
 * console itself broadcasts, and the small event queue that publishes
 * beacon changes to the rest of the game.
 *
 * The family's __FILE__ anchor is 0x020A74C0, the string argument
 * func_020266E0 passes to the allocator at line 0x5a
 * (src/matched/func_020266E0.c).
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration
 * below is derived from a file in src/matched that is EXACT, and the
 * matched function that evidences each field or parameter is named in the
 * comment beside it.  Where two matched sources spell the same field
 * differently (they were written by different lanes), the spelling
 * recorded here is the one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout; the
 * beacon payload sizes below are content constants and are exactly the
 * kind of thing that may differ between the two versions.
 */

#ifndef GAME_BEACON_H
#define GAME_BEACON_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE ONE GLOBAL.
 *
 * g_GameBeacon (0x02146940) is a single pointer to a 0xBB4-byte block
 * allocated on the caller's heap by func_020266E0 and released by the
 * same function's func_02034714 call on a re-init.  Fifty-six literal
 * pools across the ARM9 image name it; every function in this family
 * reaches its state through it and nothing else.
 *
 * Two spellings of the same pointer appear in src/matched, because the
 * block is addressed two ways:
 *   - `char *` / `u8 *` plus a byte offset (func_020267BC, func_0202735C,
 *     func_020270E0, func_02026CA0), used for the tail fields past 0xBA4;
 *   - `struct GameBeacon *` (func_02027198, func_02027060), used for the
 *     0x60-byte header object that starts at +4.
 * Both are the same address; the struct form is the one the original
 * source almost certainly used, since func_0202715C only reproduces its
 * two-step `adds r0, r4, #4` / `adds r0, #0x5e` when the inner object is
 * a real nested struct member (src/matched/func_0202715C.c).
 *
 * IT IS RE-READ ACROSS EVERY CALL.  src/matched/unit_020271F8.c only
 * reproduces its twelve functions when the global is declared
 * `void * const volatile`: the compiler otherwise proves the callee never
 * writes it and keeps one load live across the pair of calls.  See
 * docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md.
 * ------------------------------------------------------------------ */
extern struct GameBeacon *g_GameBeacon;             /* 0x02146940 */

/* ------------------------------------------------------------------ *
 * THE BLOCK LAYOUT, 0xBB4 bytes.
 *
 *   +0x0000  u32                     a handle/pointer; func_02026728 and
 *                                    func_020267BC test and write it, and
 *                                    func_02027198 passes it to
 *                                    func_02012EBC as `g->f00`
 *   +0x0004  BeaconRec  own          the console's OWN beacon record, the
 *                                    0x60-byte object every trampoline of
 *                                    unit_020271F8.c writes through
 *                                    (func_0202735C passes `g + 4`)
 *   +0x0064  BeaconRec  slot[30]     the 30-entry receive ring; stride is
 *                                    0x60 and the first entry starts at
 *                                    +0x64 (func_02026728's loop over
 *                                    i*0x60+0x64 and i*0x60+0xC0, and
 *                                    func_02026A60's i*0x60 scans)
 *   +0x0BA4  u32        live_mask    one bit per ring slot; func_02026CA0
 *                                    scans it for the next live index and
 *                                    func_02026CE0 clears a bit
 *   +0x0BA8  u32        count        bumped by func_02026A60 on an insert
 *   +0x0BAC  s8         lo           ring cursor low  (func_0202685C,
 *                                    func_02026A60)
 *   +0x0BAD  s8         hi           ring cursor high; func_020266E0
 *                                    initialises it to -1 and func_0202685C
 *                                    advances it with a wrap at 30
 *   +0x0BAF  u8         flag         a one-shot flag: func_020270E0 reads
 *                                    it and clears it in the same call
 *   +0x0BB0  u16        last_mode    func_02026728 compares func_0200864C()
 *                                    against it and publishes a change
 *
 * The 30 in `slot[30]` and the 0x60 stride are the two content constants
 * most likely to differ in White; the 0x1e bound is spelled as a literal
 * in func_02026728, func_02026CA0 and func_02026A60 alike.
 * ------------------------------------------------------------------ */
#define BEACON_SLOT_COUNT   30      /* 0x1e: func_02026728, func_02026CA0,
                                     * func_02026A60 */
#define BEACON_REC_SIZE     0x60    /* func_02026728, func_02026A60 */
#define BEACON_BLOCK_SIZE   0xBB4   /* func_020266E0's allocation size */
#define BEACON_SLOT_BASE    0x64    /* offset of slot[0] */

/* ------------------------------------------------------------------ *
 * BeaconRec, the 0x60-byte record.
 *
 * Almost every field is a BITFIELD, and the field widths are read
 * directly off the mask pool words rather than guessed:
 * src/matched/func_02026FB8.c decodes them as
 *
 *     0xFC00FFFF  ->  +0x0C bits 16..25, a 10-bit field
 *     0x03FFFFFF  ->  +0x0C bits 26..31, a  6-bit field
 *     0xFFFE0000  ->  +0x08 bits  0..16, a 17-bit field
 *     0x0001FFFF  ->  +0x04 bits  0..16, a 17-bit field
 *     0xFFC1FFFF  ->  +0x08 bits 17..21, a  5-bit field
 *
 * with the single shared pool word 0x03FFFFFF serving three masks through
 * shifts: reading the three as separate constants splits one word into
 * three and loses the layout.  func_0202737C (src/matched/func_0202737C.c)
 * confirms the +0x04 bits 17..26 10-bit field and the +0x08 top-10 field
 * from the other direction.
 * ------------------------------------------------------------------ */
struct BeaconRec {
    u32 f00;                        /* func_02026FB8 */

    u32 id      : 17;               /* +0x04 bits  0..16; func_02026FB8's
                                     * `o->f04 = func_0200C1DC(a)` */
    u32 mode    : 10;               /* +0x04 bits 17..26; func_0202737C
                                     * writes `(a1 & 0x3ff) << 17` under
                                     * the mask 0xF801FFFF */
    u32 f04hi   : 5;                /* +0x04 bits 27..31 */

    u32 peer    : 17;               /* +0x08 bits  0..16; func_02026FB8's
                                     * `o->f08 = func_0200C1C4(a)` */
    u32 seq     : 5;                /* +0x08 bits 17..21, incremented in
                                     * place by func_02026FB8 */
    u32 f08hi   : 10;               /* +0x08 bits 22..31; func_0202737C
                                     * writes func_02166C7C(a2) << 22 */

    u32 f0clo   : 16;               /* +0x0C bits  0..15 */
    u32 trainer : 10;               /* +0x0C bits 16..25; func_02026FB8's
                                     * `o->f0c = func_0200864C(b)` */
    u32 f0chi   : 6;                /* +0x0C bits 26..31; func_02026FB8's
                                     * `o->f0chi = func_02008650(b)` */

    u16 f10;                        /* +0x10; func_02026A60 compares the
                                     * request's f10 against slot+0x74,
                                     * which is slot[i] + 0x10 */
    u8  pad12[0x20 - 0x12];
    u16 vec[8];                     /* +0x20; func_02027198 fills eight
                                     * halfwords from func_0200C1F4 and
                                     * stops early on a match against
                                     * func_02045A98's answer */
    u8  pad30[0x48 - 0x30];
    u16 state;                      /* +0x48; func_0202744C sets its LOW
                                     * BYTE to 5 and leaves the high byte
                                     * alone -- write the mask as ~0xffu,
                                     * not 0xff00 (see that file) */
    u8  pad4A[0x5C - 0x4A];
    s16 timer;                      /* +0x5C; func_02026824 increments it
                                     * and clears it on overflow */
    u8  dirty;                      /* +0x5E; func_02026FB8, func_02027198
                                     * and func_0202715C all set it to 1 */
    u8  pad5F[0x60 - 0x5F];
};

/* The 0x60-byte header object at +4 of the block is a BeaconRec too: the
 * event queue writes the event id to its +0x30 and the argument(s) to
 * +0x32 / +0x34 (src/matched/unit_020271F8.c), which fall inside the
 * pad30..state gap above.  Spelled as its own view: */
struct BeaconEvent {
    u8  pad00[0x30];
    u16 id;                         /* +0x30; one of the six event ids */
    u16 arg0;                       /* +0x32 */
    u16 arg1[10];                   /* +0x34; func_020270AC writes up to
                                     * ten halfwords here */
};

/* ------------------------------------------------------------------ *
 * THE EVENT IDS.
 *
 * src/matched/unit_020271F8.c is six checker/trampoline pairs, one per id.
 * Every checker asks func_02027060(id) whether the id outranks the object's
 * current mode, and only then writes the event and dispatches it.
 * ------------------------------------------------------------------ */
#define BEACON_EVT_0E   0x0E        /* sub_020271F8, one u16 at +0x32 */
#define BEACON_EVT_0F   0x0F        /* sub_02027230, one u16 at +0x32 */
#define BEACON_EVT_10   0x10        /* sub_02027268, a vector at +0x34 */
#define BEACON_EVT_11   0x11        /* sub_020272A4, both */
#define BEACON_EVT_14   0x14        /* sub_020272EC, one u16 at +0x34 */
#define BEACON_EVT_23   0x23        /* sub_02027324, one u16 at +0x34 */

/* The three mode-change ids func_02026728 forwards to sub_020272EC when
 * func_0200864C()'s answer changes: */
#define BEACON_MODE_0A  0x0A
#define BEACON_MODE_1E  0x1E
#define BEACON_MODE_32  0x32
#define BEACON_MODE_64  0x64

/* ------------------------------------------------------------------ *
 * THE PRIORITY TABLE, 0x0209FC20.
 *
 * A word-stride table indexed by event id.  Two matched functions read it
 * with two different accessors, which pins the layout:
 *   - func_02026824 reads `data_0209FC20[n] >> 8` as a frame-count bound;
 *   - func_02027060 reads `(u8)g_0209FC20[i]` -- the LOW BYTE of the same
 *     word -- as the priority of id `i`, and answers whether the incoming
 *     id's priority is at least that of the object's current mode at +0x34
 *     of the block's header object.
 * So each word is (frames << 8) | priority.
 *
 * 0x0209FC04 is a separate 14-entry u16 table of ids; func_0202708C scans
 * it linearly and answers 1 on a hit.
 * ------------------------------------------------------------------ */
extern const u32 g_BeaconPriority[];   /* 0x0209FC20 */
extern const u16 g_BeaconIdList[14];   /* 0x0209FC04; func_0202708C's bound */

/* ------------------------------------------------------------------ *
 * PROTOTYPES, with the exact parameter types the byte evidence fixes.
 * Each line names the src/matched file that is EXACT for it.
 * ------------------------------------------------------------------ */

/* Lifecycle -------------------------------------------------------- */
void func_020266E0(u32 heap);               /* func_020266E0.c: allocate */
void func_020267BC(u32 a0);                 /* func_020267BC.c */
void func_020267FC(void);                   /* func_020267FC.c */
void func_02026728(void);                   /* func_02026728.c: per-frame */

/* The three sub_02026504 wrappers; each is its own translation unit so
 * the other two's calls attest this one's (see sub_020266AC.c). */
void sub_020266AC(u32 a, u32 b, u32 c);     /* appends 0x27 / 0x26 */
void sub_020266C0(u32 a, u32 b, u32 c);     /* appends 0x1e / 0x1d */
void sub_020266D4(u32 a, u32 b);            /* appends 0x1f */
extern void sub_02026504(u32 a, u32 b, u32 c, u16 d);   /* 0x02026504 */

/* The receive ring ------------------------------------------------- */
int  func_02026608(u8 *p, u8 *out);         /* func_02026608.c: pop one */
void func_02026824(struct BeaconRec *o);    /* func_02026824.c: age one */
int  func_02026CA0(int *p);                 /* func_02026CA0.c: next live
                                             * index, or 30 */
void func_02026CE0(u32 n);                  /* src/pending: clear bit n --
                                             * MATCH only, see below */

/* The own beacon and the event queue ------------------------------- */
void func_02026FB8(struct BeaconRec *o);    /* func_02026FB8.c: refresh */
u32  func_02027060(u32 id);                 /* func_02027060.c: priority
                                             * gate; `(u8)tbl[id] >=
                                             * (u8)tbl[cur]` */
void func_0202708C(u16 v);                  /* func_0202708C.c: id lookup */
void func_020270AC(void *vec, u16 *dest);   /* sub_020270AC.c */
u8   func_020270E0(void);                   /* sub_020270E0.c: take flag */
void func_02027100(const void *src);        /* sub_02027100.c */
void func_0202715C(u32 a0);                 /* func_0202715C.c */
void func_02027198(void);                   /* func_02027198.c */
void func_0202735C(u32 a0, u32 a1);         /* func_0202735C.c */
void func_0202737C(u32 *p, u32 a1, u32 a2); /* func_0202737C.c */
void func_0202744C(struct BeaconRec *o);    /* func_0202744C.c: mark 5 */
void func_020274B4(u32 a0);                 /* src/pending: MATCH only */
void func_020274C8(void);                   /* src/pending: MATCH only */

/* The six event checkers and their trampolines, unit_020271F8.c ---- */
void sub_020271F8(u16 value);
void sub_02027230(u16 value);
void sub_02027268(u16 value);
void sub_020272A4(u16 a, u16 b);
void sub_020272EC(u16 value);
void sub_02027324(u16 value);

/* ------------------------------------------------------------------ *
 * STILL OPEN IN THIS FAMILY, as of 2026-09-23 (wave 12).
 *
 * Nothing is DIFF any more.  Two functions are byte-exact but MATCH-capped
 * in src/pending for lack of an outside witness:
 *   func_0202685C  the ring insert (516/516 bytes).  Its four
 *                  `bl 0x02167394` sites are the only references to that
 *                  overlay address anywhere; ov009 and ov010 both cover it
 *                  and neither labels a function there.
 *   func_020274C8  the pool word 0x000000E7 is an absolute overlay-id
 *                  symbol (ov231) that appears in no other pool.  A
 *                  constant 0xE7 would be `movs`, so it cannot be spelled
 *                  away.
 *
 * Closed in wave 12: func_02026CE0 (its "no witness" park had misread the
 * pool word: it is g_GameBeacon, 0x02146940, not 0x02021440),
 * func_02026A60, func_02026D88, func_02027060, func_02027460, and the
 * unlabelled leaves sub_02026D04, sub_02026D48 and unit_02026BFC
 * (sub_02026BFC/C1C/C30/C78/C8C).
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * WAVE 12 FINDINGS (2026-09-23), each from an EXACT file.
 *
 * BeaconRec, beyond the struct above (src/matched/func_02026D88.c, the
 * own-beacon builder):
 *   +0x00  NOT a u32: four bytes.  +0 = 0xff, +1 / +2 from 0x0200856C /
 *          0x02008570, +3 split as u8 bitfields { lo : 7 (= 0x30);
 *          hi : 1 (from 0x02008550) } -- strb/ldrb, never a word RMW.
 *   +0x04  bits 27..31 (f04hi) are written 2.
 *   +0x0C  is 6:3:3:4:10:6: bits 0..5 = 0x15, 6..8 from 0x02008554 (minus
 *          8 when +3.hi is set), 9..11 from 0x0200C224, 12..15 the DS
 *          owner's favoriteColor (OS_GetOwnerInfo), then trainer, f0chi.
 *   +0x12  u16[7], filled from 0x020084F4 like +0x20 is from 0x0200C1F4,
 *          both stopping early on func_02045A98's answer.
 *   +0x30  u16, cleared last.
 *   +0x48  u16 bitfields { lo : 8; a : 3; b : 5; } then u16 +0x4A, +0x4C:
 *          func_02027460 copies four halfwords of a {u16 a,b,c,d} there
 *          (func_020274B4's argument is that 8-byte struct's address).
 *   +0x50  ten bytes, MI_CpuCopy8 from the 0x0200E394/0x0200E3A0 chain.
 *   +0x5C  u16, zeroed on insert (func_0202685C, func_02026A60).
 *
 * Block tail: +0xBAE is an s8 FILL COUNT (func_0202685C bumps it below 30;
 * sub_02026BFC bounds an index by it); +0xBAF is the flag func_0202685C
 * sets when an item grant lands.
 *
 * The priority table 0x0209FC20 is a word of BITFIELDS:
 *     struct { u32 prio : 8; u32 frames : 24; }
 * `(u8)tbl[i]` on a u32 array ties the lsrs order to the cmp order and is
 * 4 bytes out forever; the bitfield read closes func_02027060.
 *
 * func_02026A60's ring walk is plain C: `if (lo <= hi)` one loop, `else`
 * lo..29 then 0..hi, each hit `hit = 1; break;` -- the compiler does the
 * selective cross-jump the older goto spelling imitated.
 *
 * A pointer local to the own record (`struct BeaconRec *o = &g->own;`) is
 * what produces the two-step `adds r,r0,#4; adds r,#0x48` at every access
 * (func_02027460, func_0202715C); a held `g` folds it to one `adds`.
 *
 * Prototypes proved in wave 12:
 *   void  func_02026CE0(u32 n);                 clear live bit n
 *   int   sub_02026D04(const BeaconRec *r);     set live bit of r's id slot
 *   u16   sub_02026D48(u16 id);                 +0x5C of the live slot with id
 *   void *sub_02026BFC(u8 *blk, int n);         slot n if n < fill count
 *   void *sub_02026C1C(int n);                  sub_02026BFC(g_GameBeacon, n)
 *   void *sub_02026C30(u8 *blk, int n);         n records back from hi
 *   void *sub_02026C78(int n);                  sub_02026C30(g_GameBeacon, n)
 *   u32   sub_02026C8C(void);                   +0xBA8 insert count
 *   void  func_02026D88(BeaconRec *o, void *sys);
 *   u32   func_02027060(u32 id);                prio(id) >= prio(cur)
 *   void  func_02027460(void *own, const u16 src[4]);
 *   void  func_0202685C(u8 *blk, BeaconRec *r); (MATCH, see above)
 * ------------------------------------------------------------------ */

/* ------------------------------------------------------------------ *
 * WAVE 13 (2026-09-23): both MATCH parks re-verified unchanged.
 *   func_0202685C  the four `bl 0x02167394` targets are an UNLABELLED
 *                  Thumb leaf in ov010 (0x02167394: cmp r0,#0x1d; bls;
 *                  movs r0,#0; bx lr; ldr r1,=0x02171F3C; ldrb r0,[r1,r0];
 *                  bx lr -- a bounded byte-table lookup over the 30 ring
 *                  ids).  In ov009 the same address is mid-function ARM
 *                  code.  A `symbols:` hint `ov010` alone does not resolve
 *                  it: the address needs a function_starts seed in ov010
 *                  (integrator), then the region-hinted site can attest.
 *   func_020274C8  0xE7 is an absolute overlay-id symbol with one pool
 *                  word image-wide; still permanent.
 * ------------------------------------------------------------------ */
#endif /* GAME_BEACON_H */
