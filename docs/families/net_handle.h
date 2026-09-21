/*
 * docs/families/net_handle.h -- shared declarations for the net_handle.c
 * family (0x020395EC..0x0203A458 in the ARM9 image; the __FILE__ anchor at
 * 0x020A7A68 reads "net_handle.c" and is loaded by func_020395EC line 0x6E,
 * func_02039834 lines 0xE3/0xE5, func_02039764 line 0xC7, func_020398B4
 * line 0x100, func_02039D94 line 0x29A, func_0203A28C line 0x391,
 * func_0203A2F0 line 0x3AB, func_0203A338 line 0x3BE and func_0203A388
 * lines 0x3D1/0x3D8).  Edges are fuzzy by a function or two at both ends:
 * 0x02039548..0x020395E0 ahead of it is link-state flag poking that shares
 * the same globals, and the packet's tail past 0x0203A458 is the lazy-init
 * wrapper func_0203A494.
 *
 * REFERENCE DOCUMENT ONLY.  Nothing includes this file; it is not part of
 * any translation unit and match.py never sees it.  Every declaration below
 * is derived from a file in src/matched that is EXACT, and the matched
 * function that evidences each field or parameter is named in the comment
 * beside it.  Where two matched sources spell the same field differently
 * (they were written by different lanes), the spelling recorded here is the
 * one the byte evidence actually constrains.
 *
 * Addresses are Black-image addresses throughout (docs/AGENT-BRIEF.md
 * section 8).  Nothing here encodes a guess about the White layout.
 */

#ifndef NET_HANDLE_H
#define NET_HANDLE_H

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

/* ------------------------------------------------------------------ *
 * THE NINE-ENTRY SLOT TABLE.
 *
 * Everything in this family is addressed through one table of NINE
 * 0x50-byte entries: eight peers, indices 0..7, plus the OWN slot, index
 * 8, which every caller spells as the sentinel 0xFF rather than as 8.
 * sub_0203996C is the one resolver (src/matched/sub_0203996C.c): it takes
 * func_0203D788()'s record, bounds-checks the index against NINE and
 * scales with an `mla` because 0x50 is not a shift pair, and answers
 * &table[8] for the 0xFF spelling through a separate constant add.
 *
 * The table lives at +0x70 of that record and ends at +0x340, which is
 * 0x70 + 9 * 0x50 exactly (sub_02039338 reads +0x340; see the comment in
 * src/matched/sub_0203996C.c).
 *
 * 0xFF IS THE SENTINEL EVERYWHERE, in three distinct roles: the own-slot
 * index (sub_0203996C, func_02039764, func_020398B4), the "no such slot"
 * answer of the reverse lookup (func_020395EC returns it when nothing
 * matches, and src/matched/func_02039C3C.c and unit_02039C68.c both test
 * for it), and the "unresolved" value parked in a record's slot byte
 * (func_02039C3C stores 0xFF at +0x48, func_02039764 stores it into the
 * whole +0x44/+0x46 key).  sub_020395E0 clamps any index of 8 or more to
 * 0xFF, which is the conversion between the two spellings.
 * ------------------------------------------------------------------ */
#define NET_SLOT_COUNT      8       /* peers; func_02039658, func_02039764,
                                     * func_020398B4, func_02039CD8 and
                                     * func_0203A458 all stop at 8 */
#define NET_TABLE_COUNT     9       /* peers + own; sub_0203996C's bound,
                                     * func_0203A388's bound, and the loop
                                     * bound in func_02039D94's second and
                                     * third phases */
#define NET_SLOT_OWN        0xFF    /* the own-slot index spelling */
#define NET_SLOT_NONE       0xFF    /* func_020395EC's "not found" */
#define NET_ENTRY_SIZE      0x50    /* sub_0203996C's stride; also the
                                     * wipe length in func_02039658 and
                                     * func_02039764 */
#define NET_RESOURCE_SIZE   0x10    /* the per-slot record; the wipe length
                                     * in func_0203971C and func_02039658,
                                     * and the allocation size in
                                     * func_02039764 */

/* ------------------------------------------------------------------ *
 * struct NetEntry -- one 0x50-byte table entry.
 *
 * Only the fields the matched sources actually touch are named; the gaps
 * are padding of the size the byte evidence forces and nothing more.  The
 * entry is ZEROED WHOLESALE (func_02082BCC(e, 0, 0x50)) by both
 * func_02039658 and func_02039764, which is why almost every field has a
 * defined zero state.
 * ------------------------------------------------------------------ */
struct NetEntry {
    void *obj;              /* +0x00  the entry's own heap object.
                             *        func_02039658 releases it through
                             *        func_020307B0 and nulls it before
                             *        the wipe; func_0203A388 treats the
                             *        same word as the payload buffer and
                             *        frees the old one before allocating
                             *        a new one. */
    u32   len;              /* +0x04  the payload length, published
                             *        TOGETHER with obj: func_0203A388's
                             *        `stm r5, {r1, r7}` writes both words
                             *        in one instruction, which is what
                             *        says they are adjacent. */
    void *slot[8];          /* +0x08  eight resource records of
                             *        NET_RESOURCE_SIZE bytes each.  Only
                             *        the OWN entry owns them:
                             *        func_02039764 allocates all eight
                             *        for index 0xFF and leaves a peer's
                             *        array null, and func_020398B4
                             *        releases exactly the own entry's
                             *        eight at teardown.  func_02039658
                             *        stashes and restores the array
                             *        across its wipe, so a reset keeps
                             *        the resources and only clears state.
                             *        func_02039CD8 and func_0203A458
                             *        index the same array. */
    u8    pad_28[4];        /* +0x28 */
    u8    armed[16];        /* +0x2C  eight two-byte pairs, one per slot:
                             *        the even byte is the slot id and the
                             *        odd byte (+0x2D + 2*i) the armed
                             *        flag.  func_02039A2C writes the pair
                             *        (`q[0x2c] = a; q[0x2d] = 1`) and
                             *        func_02039A5C retires it, passing
                             *        &pair to func_0203D3A8 and clearing
                             *        the flag on acceptance. */
    u8    pad_3C[2];        /* +0x3C */
    u16   pending;          /* +0x3E  cleared by func_0203971C and
                             *        func_02039658 whenever the slot's
                             *        mask is re-keyed; func_02039CD8
                             *        treats its own +0x3E as the sweep
                             *        key and zeroes it on success. */
    u16   mask;             /* +0x40  THE 16-BIT SLOT MASK, one bit per
                             *        peer.  func_0203A28C is the write
                             *        half and func_0203A2F0 the read
                             *        half; func_02039658 and
                             *        func_0203971C clear a bit out of it
                             *        through func_0203A28C, and
                             *        func_02039D94's fourth phase sets
                             *        one.  It is a u16 and not a u32:
                             *        every store is bracketed by an
                             *        `lsl #0x10` / `lsr #16` pair. */
    u8    pad_42[2];        /* +0x42 */
    u16   key_lo;           /* +0x44  the packed key's low half.
                             *        sub_02039CA0 and sub_02039CB4 match
                             *        against it; func_02039C2C copies a
                             *        message tag straight into it;
                             *        func_02039764 sets it to 0xFFFF. */
    u16   key_hi;           /* +0x46  the high half.  Always assembled as
                             *        `lo + (hi << 8)` from two separate
                             *        arguments rather than passed whole
                             *        (sub_02039C68, sub_02039CB4,
                             *        func_0203A424, func_02039C3C), and
                             *        func_02039D94's third phase passes
                             *        &key_hi to func_0203D3A8. */
    u8    slot_id;          /* +0x48  the resolved slot, or 0xFF while
                             *        unresolved.  func_02039C3C and
                             *        sub_02039C68 store the sentinel;
                             *        func_0203A424 stores a caller's
                             *        value. */
    u8    remote;           /* +0x49  IS THIS NOT THE OWN LINK?  Zero for
                             *        the own link, one otherwise, built
                             *        from func_020395EC(p) == 0xFF.  The
                             *        `moveq r0,#0` / `movne r0,#1` ORDER
                             *        is the source order of the arms, so
                             *        it has to be written as an explicit
                             *        if/else with the `== 0xFF` arm first
                             *        (func_02039C3C, sub_02039C68,
                             *        func_0203A424).  func_02039D94's
                             *        third phase clears it once the
                             *        record has been delivered. */
    u8    state;            /* +0x4A  THE SLOT STATE MACHINE.  Known
                             *        values: 0 and 1 are stepped up by
                             *        func_02039ACC (`if (f < 2) f + 1`),
                             *        2 is the "ready to announce" state
                             *        that re-arms the table through
                             *        func_0203D3A8 with a 3-byte payload,
                             *        5 is "peer acknowledged"
                             *        (func_020399B8's predicate, and
                             *        func_0203A150 stores it both on the
                             *        own-link path and into the sender's
                             *        entry), and 7 is the repair state
                             *        func_0203A118 pushes a mismatched
                             *        slot into. */
    u8    pad_4B[3];        /* +0x4B */
    u8    dirty;            /* +0x4E  set to 1 by func_0203A020 when the
                             *        installer's table base does not
                             *        match the own entry, and tested for
                             *        exactly 1 (then cleared) by
                             *        func_02039D94's tail. */
    u8    pad_4F;           /* +0x4F */
};                          /*  = 0x50 bytes */

/* ------------------------------------------------------------------ *
 * struct NetOwner -- func_0203D788()'s / func_0203D798()'s record.
 *
 * The two getters answer the same object at different offsets in
 * different callers' eyes; only the fields this family reads are named.
 * sub_0203996C uses func_0203D788, everything else uses func_0203D798.
 * ------------------------------------------------------------------ */
struct NetOwner {
    u8   pad_00[0x10];
    u32 (*get_b)(void);     /* +0x10  second callback; func_02039D94's tail
                             *        requires BOTH to be non-null and
                             *        calls get_a first, get_b second. */
    u32 (*get_a)(void);     /* +0x14  first callback.  Its result is
                             *        narrowed to u16 AT THE CALL SITE of
                             *        func_0203D3A8, not at the
                             *        assignment. */
    u8   pad_18[0x4C];
    u8   f64;               /* +0x64  sub_02039594 reads the session
                             *        record's +0x64 as an override. */
    u8   f65;               /* +0x65  func_02039D94's tail returns early
                             *        when this reads 4. */
    u8   pad_66;
    u8   id_byte;           /* +0x67  the local id, byte form.
                             *        func_02039ACC copies it into its
                             *        3-byte payload; func_0203A150 and
                             *        func_0203A020 compare a message's
                             *        id against it. */
    u8   pad_68[6];
    u16  id_word;           /* +0x6E  the local id, halfword form.  It IS
                             *        a halfword: func_0203A020 reads it
                             *        with `ldrh`.  func_0203A150 prefers
                             *        it over id_byte whenever it is
                             *        non-zero. */
    u8   pad_70[0x2D2];
    u8   f342;              /* +0x342 */
    u8   pad_343[0xF];
    u8   f352;              /* +0x352  func_0203A118's guard: clear means
                             *         only push a slot to state 7 if it
                             *         is not already 5. */
};

/* The heap id every allocation in this family draws from lives at +0x56 of
 * func_0203D798()'s record and is a HALFWORD (`ldrh r0, [r4, #0x56]` in
 * func_02039764, func_02039834 and func_0203A388).  It is reached at a
 * different base than the fields above in those three callers, so it is
 * left out of struct NetOwner rather than guessed into it. */

/* ------------------------------------------------------------------ *
 * struct NetMsg -- the wire message the table handlers receive.
 *
 * EVERY HANDLER IN THIS FAMILY HAS THE SAME FIVE-PARAMETER SHAPE: four
 * register arguments, of which only the third (the message) is generally
 * used, plus the RECEIVER ON THE CALLER'S STACK as a fifth.  Evidenced by
 * func_02039B5C, func_02039C2C, func_0203A150, func_0203A27C,
 * func_0203A388 and func_0203A020, every one of which reads its receiver
 * from [sp, #0x18] or [sp, #0x20] depending on its own push -- i.e. from
 * ABOVE its own frame.  Writing one of them with four parameters makes
 * the compiler keep the receiver in a callee-saved register and costs an
 * extra push, a spill slot and 12 to 16 bytes; that misreading is what
 * docs/notes/pkt_0203A388.c.txt and the first half of
 * docs/notes/pkt_02039D94.c.txt both recorded as a "register colouring"
 * residue.
 * ------------------------------------------------------------------ */
struct NetMsg {
    u16  tag;               /* +0x00  func_02039C2C copies it to the
                             *        receiver's +0x44; func_02039B5C
                             *        votes with it. */
    u8   mask;              /* +0x02  func_02039B5C's vote mask. */
    u8   pad_03[3];
    u8   mac[6];            /* +0x06  func_0203A150 compares it against
                             *        OS_GetMacAddress; func_0203A020
                             *        copies the first 6 bytes of the key
                             *        into the resource record's +6. */
    u8   id;                /* +0x0C  the sender's slot id.
                             *        func_0203A150 resolves the sender's
                             *        entry with it; func_0203A020 mirrors
                             *        it to the record's +0xC. */
    u8   f0D;               /* +0x0D */
    u8   f0E;               /* +0x0E */
    u8   f0F;               /* +0x0F */
};

/* struct NetResource -- the NET_RESOURCE_SIZE record a slot pointer names.
 * func_0203A020 is the one writer of its interior. */
struct NetResource {
    u8   pad_00[6];
    u8   key[6];            /* +0x06  MI_CpuCopy8'd from the message. */
    u8   key0;              /* +0x0C  mirror of key[0]. */
    u8   in_use;            /* +0x0D  func_0203A020 refuses a record that
                             *        already has it set and then sets it;
                             *        func_02039CD8 and func_0203A458
                             *        both skip a record whose flag is
                             *        clear. */
    u8   id_lo;             /* +0x0E  func_0203A458 broadcasts a byte to
                             *        this and id_hi together. */
    u8   id_hi;             /* +0x0F */
};

/* ------------------------------------------------------------------ *
 * struct NetVotes -- the module global at 0x021469D4.
 *
 * Three parallel eight-element arrays hanging off ONE pointer, which is
 * what func_02039B5C's re-read of the global after every store proves
 * (every callee there is an ordinary extern, so nothing may be cached).
 * The same global is the module handle func_02039834 allocates and
 * func_020398B4 frees, and func_02039D94's second phase walks it with a
 * stride of 1 for the flag bytes and a stride of 2 for the argument it
 * hands func_0203D4D0.
 * ------------------------------------------------------------------ */
struct NetVotes {
    u16 tag[8];             /* +0x00 */
    u8  mask[8];            /* +0x10  func_02039D94 also reads +0x10 + i
                             *        as a per-entry byte. */
    u8  ready[8];           /* +0x18  func_02039B5C raises the voter's
                             *        flag once every slot agrees;
                             *        func_02039D94 clears an entry's flag
                             *        after func_0203D4D0 accepts it, and
                             *        asserts (line 0x29A) if +0x10 reads
                             *        zero at that point. */
};

extern struct NetVotes *g_021469D4;   /* 0x021469D4, data */
extern void            *g_021469D8;   /* 0x021469D8, data: the 0x22C-byte
                                       * context func_0203A494 lazily
                                       * allocates. */
extern struct LinkState *unk_021469D0; /* 0x021469D0, data: the link-state
                                        * flags sub_02039548 and friends
                                        * poke. */

/* ------------------------------------------------------------------ *
 * Strings, all in the packed area after the "net_handle.c" anchor.
 * They resolve through `literal` (0x020A7A68, which many pools name) or
 * `sole-ref`/`string`; 0x020A7A78 has NO witness at all outside
 * func_020395EC's own range, which is what caps
 * src/matched/func_020395EC.c's one open site.
 * ------------------------------------------------------------------ */
extern const char file_020A7A68[];    /* "net_handle.c", the __FILE__ */
extern const char msg_020A7A78[];     /* func_020395EC, line 0x6E */
extern const char msg_020A7A7C[];     /* func_02039834, line 0xE3 */
extern const char msg_020A7A88[];     /* func_020398B4, line 0x100 */
extern const char msg_020A7A94[];     /* func_02039D94, line 0x29A */
extern const char msg_020A7AB0[];     /* func_0203A28C line 0x391,
                                       * func_0203A2F0 line 0x3AB,
                                       * func_0203A338 line 0x3BE */
extern const char msg_020A7ACC[];     /* func_0203A388, line 0x3D1 */

/* ------------------------------------------------------------------ *
 * Prototypes, in address order.  Parameter types are the ones the byte
 * evidence constrains; a parameter written `u32 aN` is one the function
 * receives and does not use (the handler shape above).
 * ------------------------------------------------------------------ */

/* 0x020395E0  clamp an index to the sentinel: >= 8 becomes 0xFF. */
int   sub_020395E0(int slot);

/* 0x020395EC  reverse lookup: which slot index holds `a`?  Answers
 * NET_SLOT_OWN for the own link, the index for a peer, and reports at
 * line 0x6E (then returns -1) when nothing matches. */
int   func_020395EC(u32 a);

/* 0x02039658  reset one entry, KEEPING its eight resource pointers.  The
 * stack buffer that stashes them holds NINE pointers and uses eight; the
 * ninth is what takes the frame to 0x24 and drops the r3 home slot. */
void  func_02039658(struct NetEntry *e, u32 idx);

/* 0x0203971C  clear a slot's pending key and zero the indexed resource. */
void  func_0203971C(struct NetEntry *e, u32 idx);

/* 0x02039764  (re)initialise one entry AND RETURN IT.  Both callers
 * discard the result, so only the trailing `mov r0, <callee-saved>`
 * before the epilogue attests it.  The own slot reallocates its eight
 * resources (line 0xC7); a peer does not. */
struct NetEntry *func_02039764(u32 idx);

/* 0x02039834  module bring-up: reset all nine entries, assert that the
 * module handle is NOT already live (line 0xE3), allocate it (line 0xE5). */
void  func_02039834(void);

/* 0x020398B4  module teardown, the exact twin: reset all nine entries,
 * release the own entry's eight resources, assert the handle IS live
 * (line 0x100), free it. */
void  func_020398B4(void);

/* 0x0203996C  the resolver.  0xFF names entry 8. */
struct NetEntry *sub_0203996C(s32 idx);

/* 0x020399A8  two-call shutdown forwarder, both results discarded. */
void  sub_020399A8(void);

/* 0x020399B8  null-tolerant predicate: is the entry's state exactly 5? */
u32   func_020399B8(struct NetEntry *e);

/* 0x020399EC  how many of the eight peers answer func_020399B8?  The
 * counter is assigned 0 in BOTH arms of the null guard, never at its
 * declaration. */
int   func_020399EC(void);

/* 0x02039A2C  arm slot `a`: write the id/flag pair at +0x2C + 2*a. */
void  func_02039A2C(int a);

/* 0x02039A5C  retire every armed pair.  The LAST store's byte offset is a
 * named local and the other two are not; that is what colours the entry
 * r4 and the counter r5. */
void  func_02039A5C(void);

/* 0x02039ACC  step the own record's state: 2 announces a 3-byte payload,
 * below 2 steps up by one, anything else is left alone. */
int   func_02039ACC(void);

/* 0x02039B5C  record one peer's vote and raise the ready flag when the
 * last one lands.  Five parameters, receiver on the stack. */
void  func_02039B5C(u32 slot, u32 a1, struct NetMsg *msg, u32 a3, u32 link);

/* 0x02039C2C  handler: copy the message tag to the receiver's +0x44. */
void  func_02039C2C(u32 a0, u32 a1, struct NetMsg *msg, u32 a3,
                    struct NetEntry *e);

/* 0x02039C3C  arm one pending vote: tag at +0x46, 0xFF at +0x48, the
 * remote flag at +0x49. */
void  func_02039C3C(struct NetEntry *e, u16 tag);

/* 0x02039C68 / 0x02039CA0 / 0x02039CB4  the key setter and its two
 * matchers; sub_02039CA0 is an unlabelled leaf and only reproduces inside
 * the unit file. */
void  sub_02039C68(struct NetEntry *e, u32 lo, u32 hi);
u32   sub_02039CA0(struct NetEntry *e, u32 key);
u32   sub_02039CB4(struct NetEntry *e, u32 lo, u32 hi);

/* 0x02039CD8  sweep the eight resources, tearing down each in-use one
 * whose mask bit is clear through an EIGHT-argument delegate; a failure
 * aborts the sweep with 0. */
int   func_02039CD8(struct NetEntry *e);

/* 0x02039D94  the family's tick, five phases plus a callback tail.  NOT
 * matched: 652/652 bytes, 14 concrete out; see
 * docs/notes/pkt_02039D94.c.txt. */
void  func_02039D94(void);

/* 0x0203A020  stage-two record installer.  NOT matched: 248/248 bytes, 11
 * concrete out; see docs/notes/pkt_02039D94.c.txt.  Five parameters. */
void  func_0203A020(u32 idx, u32 a1, struct NetMsg *msg, u32 a3,
                    struct NetEntry *base);

/* 0x0203A118  conditional state repair: push a slot to state 7. */
void  func_0203A118(struct NetEntry *e);

/* 0x0203A150  the main message handler: id checks against the local id,
 * a MAC comparison, then state 5 and the owner's callback. */
void  func_0203A150(int a0, int a1, struct NetMsg *msg, int a3,
                    struct NetEntry *e);

/* 0x0203A27C  handler forwarding the message's first byte to
 * func_0203A338.  Twelve bytes: one `ldrb` and a pool-word tail call. */
void  func_0203A27C(u32 a0, u32 a1, u8 *msg, u32 a3, u32 a4);

/* 0x0203A28C  SET OR CLEAR one bit of the 16-bit mask (line 0x391).  The
 * clear arm's narrowing has to be spelled on the whole assignment, not as
 * a compound `&=`, or the compile is 8 bytes short. */
u16   func_0203A28C(u16 mask, u32 idx, u32 set);

/* 0x0203A2F0  TEST one bit of the mask (line 0x3AB).  The mask is
 * truncated to a BYTE before the `tst`, unlike the write half. */
u32   func_0203A2F0(u32 mask, u32 idx);

/* 0x0203A338  push a slot's identity into both halves of the table
 * (line 0x3BE). */
void  func_0203A338(u32 id);

/* 0x0203A388  install a payload into slot `id` (lines 0x3D1, 0x3D8).
 * FIVE parameters; the slot bound is SIGNED; the allocator's name
 * argument is file_020A7A68, not the assert's message. */
void  func_0203A388(int id, u32 len, const void *src, u32 a3,
                    struct NetEntry *e);

/* 0x0203A424  the five-argument twin of sub_02039C68. */
void  func_0203A424(struct NetEntry *e, int lo, int hi, int slot);

/* 0x0203A458  broadcast a byte to id_lo/id_hi of all NINE entries'
 * resources, skipping the ones whose in_use flag is clear. */
void  func_0203A458(struct NetEntry *e, u32 v);

/* 0x0203A494  lazy-init wrapper for the 0x22C-byte context at
 * g_021469D8 (line 0x96). */
void  func_0203A494(u32 a0, u32 a1, u32 a2, u32 a3);

#endif /* NET_HANDLE_H */
