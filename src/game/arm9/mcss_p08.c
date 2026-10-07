/*
 * file:     mcss_p08.c
 * unit:     yes
 * function: func_0201747C, func_02017528, func_02017550, func_0201756C, func_02017588, func_02017600, func_0201761C, func_020178D8, func_02017900, func_02017988, func_020179B8, func_02017A20, func_02017B24, func_02017B4C, func_02017BC8, func_02017C50
 * address:  0x0201747C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_020185C4  0x020185C4  thumb
 *   func_02019A50  0x02019A50  thumb
 *   func_02017588  0x02017588  thumb
 *   func_02017528  0x02017528  thumb
 *   func_02017550  0x02017550  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 *   func_02017E64  0x02017E64  thumb
 *   func_02017ED8  0x02017ED8  thumb
 *   func_02045F5C  0x02045F5C  arm
 *   func_02018584  0x02018584  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_02019C7C  0x02019C7C  thumb
 *   func_02017F08  0x02017F08  thumb
 *   func_02017FB0  0x02017FB0  thumb
 *   g0209DF0C      0x0209DF0C  data  a1
 *   gMsgBank       0x020A7370  data
 *   gNameBuf       0x021462F0  data
 *   g0209DF08      0x0209DF08  data  a1
 *   - 0x020A7370 is gMsgBank (a pointer, dereferenced), 0x021462F0 is
 *   func_02017CC8  0x02017CC8  thumb
 *   g_020A7370     0x020A7370  data
 *   g_021462F0     0x021462F0  data
 *   func_02017E1C  0x02017E1C  thumb
 *   func_020181F4  0x020181F4  thumb
 *   sMoveTbl       0x0209E298  data  a2
 *   func_0202F1B4  0x0202F1B4  thumb
 */
struct Sav;
struct Mon_1;
struct MsgData;
struct Personal;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

/* the header plus the masked block area: 0x22 words, whose eight-byte
 * ldm/stm step and 0x11 trip count are what the copy loop below proves */
struct Mon_0 { u32 w[0x22]; };

struct Sav {
    u32 unk00;
    u16 unk04;
    u16 unk06;
    u8  unk08[0x80];
    u8  unk88[0x54];
};

typedef unsigned long long u64;

struct Mon_1 {
    u32 unk00;
    u8  pad04[0x84];
    u8  unk88[0x54];
};

typedef signed short s16;

typedef signed char s8;

struct MoveTbl { u16 v[6]; };

extern u32 func_02017DBC(struct Sav *p);
extern u32 func_02017DE4(struct Sav *p, u32 f);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern void  func_02017E40(void *p, u32 id, u32 v);
extern void *func_020173F0(u16 species, u16 level, u32 otId, u32 a3, u32 heap);
extern void *func_02008F08(int a0);
extern u32 func_020307B0(void *p);
extern void  func_020185C4(void *p);
extern void MIi_CpuClearFast(u32 value, void *dest, u32 size);
extern void func_02019A50(u16 *p, u32 size, u32 seed);
extern void func_02017588(struct Mon_1 *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017528(struct Sav *p);
extern void func_02017550(struct Sav *p);
extern void *func_02019C54(u32 a, u32 b);
extern u32   func_020056EC(u32 a);
extern u32   func_0203F0A8(void);
extern void  func_02017E64(void *obj, u32 id, u32 val);
extern u32   func_02017ED8(u32 a, u32 b);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32   func_02018584(u16 a, u16 b, u16 c);
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern u32   func_02019C7C(void *a);
extern u8 func_02017F08(void *p);
extern u32 func_02017FB0(void *p);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
void func_02017600(void *obj, u16 species, u16 level, u64 id);
void func_0201761C(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd);
void func_020178D8(void *p, u32 a);
void func_0201756C(void *obj, u16 species, u16 level, u64 id);
extern void func_02017CC8(void *a0, void *a1, void *a2);
extern u32  func_02017E1C(void *p, u32 id, u32 v);
extern void func_020181F4(void *p, u16 move, u32 slot);
u32 func_02017900(void *a0, u32 a1);
u32 func_02017988(void *p, u32 a);
int func_020179B8(int a0, int a1);
u32 func_02017A20(void *p, u32 idx, u32 val);
void func_02017B24(void *p, u32 a, u32 b, u32 c);
extern void func_0202F1B4(u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 sub_02017E1C(void *p, u32 id, u32 v);
extern void sub_02017E40(void *p, u32 id, u32 v);
u32 func_02017B4C(void *a0, u32 a1, u32 a2, u32 a3);
void func_02017BC8(u8 *p, u32 i);
void func_02017C50(int a0, int a1, int a2);
extern u8   g0209DF0C;
extern void *gMsgBank;
extern u16  gNameBuf[];
extern u8   g0209DF08;
extern void *g_020A7370;
extern u8    g_021462F0[];
extern const struct MoveTbl sMoveTbl;






/*
 * "Clone this Pokemon into a fresh allocation on heap `heap`."
 *
 * It takes the block lock (func_02017DBC), reads species (id 0x05), level
 * (id 0x9E) and OT id (id 0x07) -- all three through the block-lock getter
 * func_02017E88, and species and level truncated to u16 at the assignment,
 * which is what the two `lsls #0x10 / lsrs #0x10` pairs at +0x18 and +0x26
 * are -- builds a fresh record with func_020173F0(species, level, otId, 0,
 * heap), releases the lock, copies the WHOLE 0x88-word record over the fresh
 * one, then zeroes the three party-area ids the clone must not inherit
 * (0x9D, 0xA0 current HP, 0xA1 max HP), attaches a fresh mail block and
 * recomputes the stats.
 *
 * THE ONE LEVER, and the whole residue of the first draft:
 *
 *   THE RECORD COPY IS A STRUCT ASSIGNMENT, NOT A HAND-WRITTEN WORD LOOP.
 *
 * The original's copy is
 *
 *     020174C8  adds r3, r4, #0
 *     020174CA  movs r2, #0x11
 *     020174CC  ldm r5!, {r0, r1}
 *     020174CE  stm r3!, {r0, r1}
 *     020174D0  subs r2, r2, #1
 *     020174D2  bne #0x20174cc
 *
 * i.e. 0x11 iterations of an eight-byte ldm/stm pair, which is exactly
 * docs/idioms/big-struct-assignment-is-an-ldm-stm-loop.md: above the unroll
 * threshold mwcc turns a whole-struct assignment into a counted ldm/stm loop
 * whose step is the struct's alignment.  Writing the same copy as an explicit
 * `d[0] = s[0]; d[1] = s[1]; s += 2; d += 2;` loop compiles to four separate
 * `ldr`/`str` plus two pointer bumps -- eight bytes longer and the whole tail
 * shifted (the first draft was 180 bytes against 172, with everything up to
 * +0x4C already byte-identical).  Only the aggregate assignment reaches it.
 *
 * The copy is 0x22 words = 0x88 bytes, NOT the record's full 0xDC: it copies
 * the plaintext header and the 0x80-byte masked block area and stops at the
 * party area, which is what the three explicit zeroes that follow then
 * rebuild.  That is why `struct Mon` here is declared as 0x22 words and not
 * as docs/families/poke_tool.h's full record -- the declared size IS the
 * evidence, since it is what sets the loop's trip count to 0x11.
 *
 * The heap tag handed to func_02008F08 is `(heap & 0x7fff) | 0x8000`: the pool
 * word at 0x02017524 is 0x00007FFF and the original derives the OR mask from
 * it with `adds r0, r0, #1` rather than pooling 0x8000 separately
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Nothing here is version specific: 0x05, 0x07, 0x9D, 0x9E, 0xA0, 0xA1 and
 * 0xA7 are all field selectors.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/func_0201747C.c \
 *       --func func_0201747C --addr 0x0201747C --cc 1.1p1 --thumb
 */
void *func_0201747C(struct Mon_0 *p, u32 heap)
{
    u32 t = func_02017DBC((struct Sav *)p);
    u16 species = (u16)func_02017E88(p, 5, 0);
    u16 level = (u16)func_02017E88(p, 0x9e, 0);
    u32 otId = func_02017E88(p, 7, 0);
    void *q = func_020173F0(species, level, otId, 0, heap);
    void *m;

    func_02017DE4((struct Sav *)p, t);

    *(struct Mon_0 *)q = *p;

    func_02017E40(q, 0x9d, 0);
    func_02017E40(q, 0xa0, 0);
    func_02017E40(q, 0xa1, 0);
    m = func_02008F08((u16)((heap & 0x7fff) | 0x8000));
    func_02017E40(q, 0xa7, (u32)m);
    func_020307B0(m);
    func_020185C4(q);
    return q;
}


/*
 * The two clears of the 0xDC byte record src/matched/unit_02017D30.c and
 * src/matched/unit_02018D10.c work on: func_02017528 wipes the whole of it and
 * re-masks both areas, func_02017550 wipes only the first 0x88 bytes and
 * re-masks the 0x80 byte one.  The masking calls are what say the record's
 * seed word and checksum halfword survive a clear in the caller's copy: the
 * value handed to func_02019A50 is read back out of the object *after*
 * MIi_CpuClearFast has zeroed it, so both areas are masked with zero and the
 * call is the identity.
 *
 * The range stops at 0x0201756C.  That function and its twin at 0x02017600
 * are five argument entry points to eight argument workers, passing
 * 0xFFFFFFFF, 0 and 0xFFFFFFFF for the three arguments they do not take, and
 * neither reproduces: the original spends a third callee-saved register on
 * the incoming fifth argument and stores it into the outgoing frame last,
 * after all three constants, while every forwarding spelling tried loads it
 * first and reuses one register for it and for the zero.  Eighteen bytes, all
 * of them register numbers and store order.
 */
void func_02017528(struct Sav *p)
{
    MIi_CpuClearFast(0, p, sizeof(struct Sav));
    func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
    func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
}

void func_02017550(struct Sav *p)
{
    MIi_CpuClearFast(0, p, 0x88);
    func_02019A50((u16 *)p->unk08, 0x80, p->unk06);
}



/*
 * Forwarder: func_02017588(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000) -- random IVs, random personality.  Wave 11,
 * 2026-09-23: the u64 `id` straddles r3 and the first stack word; declaring
 * it u64 is the whole fix for the 18-byte prologue residue (push {r4,r5,r6}
 * and the late `ldr r6,[sp,#0x20]`).
 */
void func_0201756C(void *obj, u16 species, u16 level, u64 id)
{
    func_02017588(obj, species, level, id, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}



/*
 * Build a full party record: clear it (func_02017528), initialise the block
 * area (func_0201761C), mask the party area with seed 0 then with the PID,
 * write the level (id 0x9E) through the party-lock setter, attach a fresh
 * mail block (tag 0x8000, id 0xA7, then freed), and refresh the stats
 * (func_020185C4).  Wave 11, 2026-09-23.  EXACT* only because the listing
 * extent includes the two alignment bytes at 0x020175FE.
 */
void func_02017588(struct Mon_1 *p, u16 species, u16 level, u64 id, u32 pow, u64 rnd)
{
    void *mail;

    func_02017528((struct Sav *)p);
    func_0201761C(p, species, level, id, pow, rnd);
    func_02019A50((u16 *)p->unk88, 0x54, 0);
    func_02019A50((u16 *)p->unk88, 0x54, p->unk00);
    func_02017E40(p, 0x9e, level);
    mail = func_02008F08(0x8000);
    func_02017E40(p, 0xa7, (u32)mail);
    func_020307B0(mail);
    func_020185C4(p);
}


/*
 * Forwarder: func_0201761C(obj, species, level, id, 0xFFFFFFFF,
 * 0xFFFFFFFF00000000).  Twin of func_0201756C; wave 11, 2026-09-23, closed
 * by the u64 `id` parameter.
 */
void func_02017600(void *obj, u16 species, u16 level, u64 id)
{
    func_0201761C(obj, species, level, id, 0xFFFFFFFF, 0xFFFFFFFF00000000ULL);
}


/*
 * Initialise a record's block area: species, level, a 64-bit trainer id and
 * a 64-bit personality with two sentinel values each, and packed IVs (or
 * 0xFFFFFFFF for six fresh draws).  Wave 11, 2026-09-23.  The levers
 * that closed it after 2026-09-21's 612-against-700 DIFF:
 *   - the 4th parameter is a u64 `id` straddling r3 and the first stack
 *     word; the 7th is a u64 `rnd`.  Sentinels: id == ~0 (draw a fresh one),
 *     id == 0xFFFFFFFF00000000 (search for a non-shiny id: the
 *     func_02017ED8 retry loop, `id = (u32)(rnd + 1)` then
 *     `id = (id + 1) & 0xFFFFFFFF`); rnd == 0xFFFFFFFF00000000 (draw),
 *     rnd == 0xFFFFFFFF00000001 (take id).  Callers 0x0201756C/0x02017600
 *     pass pow = -1, rnd = 0xFFFFFFFF00000000.
 *   - the IV draws are `(u64)func_0203F0A8() * 32 >> 32`
 *     (docs/idioms/random-below-n-is-a-64-bit-multiply-high.md).
 *   - func_02017550 takes `obj` (it is unit_02017528.c's area clear).  The
 *     last ten prologue bytes (r1 vs r0 as the scratch for the stack-param
 *     home rewrite) came from that alone: r0 must survive to the call.
 *     The permuter (hill 800 + anneal 1000, --types) could not move them.
 *   - 0x020A7370 is gMsgBank (a pointer, dereferenced), 0x021462F0 is
 *     gNameBuf (passed by address), as docs/families/poke_tool.h says.
 */
void func_0201761C(void *obj, u16 species, u16 level, u64 id, u32 pow, u64 rnd)
{
    void *rec;
    u32 flag;
    u32 v;

    func_02017550(obj);
    flag = func_02017DBC(obj);
    rec = func_02019C54(species, 0);

    if (rnd == 0xFFFFFFFF00000000ULL) {
        rnd = func_020056EC(0);
        func_0203F0A8();
    } else if (rnd == 0xFFFFFFFF00000001ULL) {
        rnd = id;
    }
    func_02017E64(obj, 0, (u32)rnd);

    if (id == 0xFFFFFFFFFFFFFFFFULL) {
        id = func_020056EC(0);
    } else if (id == 0xFFFFFFFF00000000ULL) {
        id = (u32)(rnd + 1);
        while (func_02017ED8((u32)id, (u32)rnd)) {
            id = (id + 1) & 0xFFFFFFFF;
        }
    }
    func_02017E64(obj, 7, (u32)id);
    func_02017E64(obj, 0xc, g0209DF0C);
    func_02017E64(obj, 5, species);
    func_02045F5C(gMsgBank, species, gNameBuf, 0x20);
    func_02017E64(obj, 0x74, (u32)gNameBuf);
    func_02017E64(obj, 8, func_02018584(species, 0, level));
    func_02017E64(obj, 9, func_0201AE1C(rec, 0x16));
    func_02017E64(obj, 0x99, level);
    func_02017E64(obj, 0x77, g0209DF08);
    func_02017E64(obj, 0x98, 4);

    if (pow == 0xFFFFFFFF) {
        func_02017E64(obj, 0x46, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x47, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x48, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x4a, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x4b, (u32)(((u64)func_0203F0A8() * 32) >> 32));
        func_02017E64(obj, 0x49, (u32)(((u64)func_0203F0A8() * 32) >> 32));
    } else {
        func_02017E64(obj, 0x46, (u8)(pow & 0x1f));
        func_02017E64(obj, 0x47, (u8)((pow >> 5) & 0x1f));
        func_02017E64(obj, 0x48, (u8)((pow >> 10) & 0x1f));
        func_02017E64(obj, 0x4a, (u8)((pow >> 15) & 0x1f));
        func_02017E64(obj, 0x4b, (u8)((pow >> 20) & 0x1f));
        func_02017E64(obj, 0x49, (u8)((pow >> 25) & 0x1f));
    }

    v = 0x1a;
    if (func_02019C7C(rec) == 2 && (rnd & 0x10000) != 0) {
        v = 0x1b;
    }
    func_02017E64(obj, 0xa, func_0201AE1C(rec, v));
    func_02017E64(obj, 0x6e, func_02017F08(obj));
    func_02017E64(obj, 0x70, func_020056EC(0x19));
    func_02017FB0(obj);
    func_02017DE4(obj, flag);
}


/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_020178D8.c \
 *       --func func_020178D8 --addr 0x020178D8 --cc 1.1p1 --thumb
 */
void func_020178D8(void *p, u32 a)
{
    u8 v = (u8)func_02017D30(p);

    func_02017900(p, a);
    func_020185C4(p);
    func_02017D70(p, v);
}



/*
 * poke_tool.c: "change this record's species to a1".  It takes the block
 * lock, reads the current species (id 5) and does nothing at all when it
 * already matches.  Otherwise it touches id 0x6F for its side effect, reads
 * the "nickname is not the default" bit (id 0x75), writes the new species,
 * refreshes the two derived type fields through func_02017C50 and
 * func_02017CC8, and -- only when the nickname was still the default -- also
 * renders the new species' name into the shared buffer at 0x021462F0 and
 * stores it back as id 0x74.  Then it releases the lock.
 *
 * The id 0x75 guard is what makes this correct game behaviour: a record the
 * player has renamed keeps its nickname across a species change, and one that
 * never was renamed follows the species.  func_02019ABC (unit_02019ABC.c) is
 * what sets that bit, and func_02018E34 reads it back as id 0x75.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/func_02017900.diff.c.txt records this as a DIFF and its skeleton
 * is correct in every structural respect -- the guard, the nested 0x75 test,
 * the call order.  Only the extern declarations are wrong, and in exactly the
 * same way as its sibling src/matched/func_02017B4C.c, which the same note
 * file pairs it with.
 *
 * The note declares the accessors narrow (`u8 func_02017DBC`, `u16
 * func_02017E88`).  With the callee declared narrow the compiler emits no
 * truncation at all and then spills the live values to the frame.  The
 * original truncates at the ASSIGNMENT with a `lsls`/`lsrs` pair and keeps
 * both narrowed values in callee-saved registers.  That shape needs the
 * callee declared returning a full word and the LOCAL declared narrow, so the
 * cast belongs to the source rather than to the callee.  Declaring
 * func_02017DBC and func_02017E88 u32 and keeping `u8 v` / `u16 w` is the
 * entire fix; the body is the note's, unchanged.
 *
 * This is docs/families/poke_tool.h's adjudication rule: a truncation at the
 * call constrains the callee's width, a truncation at the assignment
 * constrains the local's.  Every other matched file in the family
 * (unit_02017E64.c, unit_0201854C.c, unit_02018430.c) already declares
 * func_02017E88 returning u32, so the note's spelling was the outlier.
 *
 * The third argument of func_02017E64 is a plain u32, not a `void *`: ids 5
 * and 0x74 take an integer and a buffer address respectively, and spelling
 * the parameter as a pointer is a claim the bytes do not make.
 *
 * Nothing here is version specific: 5, 0x6F, 0x74 and 0x75 are field
 * selectors and 0x20 is a halfword count.  g_020A7370 and g_021462F0 are
 * globals, so their addresses are build properties and must be re-derived
 * for a White build rather than copied.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017900.c \
 *       --func func_02017900 --addr 0x02017900 --cc 1.1p1 --thumb
 */
u32 func_02017900(void *a0, u32 a1)
{
    u8  v = (u8)func_02017DBC(a0);
    u16 w = (u16)func_02017E88(a0, 5, 0);

    if (w != a1) {
        u32 x;

        func_02017E88(a0, 0x6f, 0);
        x = func_02017E88(a0, 0x75, 0);
        func_02017E64(a0, 5, a1);
        func_02017C50((int)a0, a1, w);
        func_02017CC8(a0, (void *)a1, (void *)w);
        if (x == 0) {
            func_02045F5C(g_020A7370, a1, (u16 *)g_021462F0, 0x20);
            func_02017E64(a0, 0x74, (u32)g_021462F0);
        }
    }
    return func_02017DE4(a0, v);
}



/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017988.c \
 *       --func func_02017988 --addr 0x02017988 --cc 1.1p1 --thumb
 */
u32 func_02017988(void *p, u32 a)
{
    u8 v = (u8)func_02017D30(p);
    u32 r = func_020179B8((int)p, a);

    if (r == 1) {
        func_020185C4(p);
    }
    func_02017D70(p, v);
    return r;
}



/*
 * A "select and apply" pair, structurally the sibling of func_02017900.
 * The value at selector 5 is compared against a1; when they already agree
 * nothing but the +0x18 restore happens.  Otherwise the old selection is read
 * back out of selector 0x6f into r4 (the local that was 0, which is why the
 * clearing write passes r4 and not a literal 0) and the new value is written
 * with selector 0x6f before the two geometry calls run with it.
 *
 * The `cmp` operand order is the tell: `(u16)func_02017E88(...)` only reaches
 * cmp's left slot because it was first bound to a named local (`t`), see
 * docs/idioms/cmp-operand-order-names-the-temporary.md.  Comparing the call
 * result directly emits `cmp a1, r0` and differs by one byte.
 *
 * EXACT*: the compared extent ran into the follower's four-byte pad, which is
 * identical in both objects.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020179B8.c \
 *       --func func_020179B8 --addr 0x020179B8 --cc 1.1p1 --thumb
 */
int func_020179B8(int a0, int a1)
{
    int r4 = 0;
    int r7 = (unsigned char)func_02017DBC((struct Sav *)a0);
    int t = (unsigned short)func_02017E88((void *)a0, 0x6f, 0);

    if (t != a1) {
        func_02017E88((void *)a0, 0x6f, r4);
        r4 = (unsigned short)func_02017E88((void *)a0, 5, r4);
        func_02017E64((void *)a0, 0x6f, a1);
        func_02017C50(a0, r4, r4);
        func_02017CC8((void *)a0, (void *)r4, (void *)r4);
        r4 = 1;
    }
    func_02017DE4((struct Sav *)a0, r7);
    return r4;
}



/*
 * Species check (id 5 == 0x1DF), then teach the move tbl[idx] from a
 * six-entry u16 table {0, 0x13B, 0x38, 0x3B, 0x193, 0x1B5} at 0x0209E298:
 * any slot already holding one of tbl[1..5] is overwritten (first hit) or
 * deleted (func_02017BC8, then the slot is re-examined), else the first
 * empty slot, else slot `val`; slot 0 empty gets move 0x54; finally
 * func_02017988(p, idx).  Wave 11, 2026-09-23.
 *
 * The straight-line six ldrh/strh copy with TWO `add rN, sp, #8` is a
 * 12-byte, 2-aligned aggregate copy scoped AFTER the guard: in the original
 * very likely a local initializer `u16 tbl[6] = {...}` inside a block (that
 * spelling is byte-identical but its anonymous rodata symbol cannot be named
 * in `symbols:`), written here as the equivalent struct copy from a named
 * extern so the relocation resolves (sole-ref).  Also load-bearing: `v` and
 * `val` are u32, so the (u16)/(u8) truncations land at the func_020181F4
 * calls; `k` is unsigned (`blo`), `i` signed (`blt`); `r != 0 && r ==
 * tbl.v[k]` is the inner test.
 */
u32 func_02017A20(void *p, u32 idx, u32 val)
{
    u32 v;
    int i;
    u32 k;

    if (func_02017E1C(p, 5, 0) != 0x1df)
        return 0;
    {
    struct MoveTbl tbl = sMoveTbl;
    v = tbl.v[idx];
    for (i = 0; i < 4; i++) {
        u32 r = func_02017E1C(p, i + 0x36, 0);

        for (k = 1; k < 6; k++) {
            if (r != 0 && r == tbl.v[k]) {
                if (v != 0) {
                    func_020181F4(p, v, (u8)i);
                    v = 0;
                } else {
                    func_02017BC8(p, i);
                    i--;
                }
                break;
            }
        }
    }
    }
    if (v != 0) {
        for (i = 0; i < 4; i++) {
            if (func_02017E1C(p, i + 0x36, 0) == 0) {
                func_020181F4(p, v, (u8)i);
                break;
            }
        }
        if (i == 4)
            func_020181F4(p, v, (u8)val);
    }
    if (func_02017E1C(p, 0x36, 0) == 0)
        func_020181F4(p, 0x54, (u8)0);
    func_02017988(p, (u16)idx);
    return 1;
}



/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02017B24.c \
 *       --func func_02017B24 --addr 0x02017B24 --cc 1.1p1 --thumb
 */
void func_02017B24(void *p, u32 a, u32 b, u32 c)
{
    u8 v = (u8)func_02017D30(p);

    func_02017B4C(p, a, b, c);
    func_02017D70(p, v);
}



/*
 * poke_tool.c: the "reset this record to a fresh hatched state" writer.  It
 * takes the block lock, reads the species (id 5) and the form (id 0x6F, for
 * its side effect only -- the result is discarded, which is why the call is a
 * statement), clears the egg flag (id 0x4C), stores 0x78 into id 9, renders
 * the species name into the shared 0x20 halfword buffer at 0x021462F0 and
 * writes it back as the nickname (id 0x74), then hands the record and the
 * three caller arguments to func_0202F1B4 before releasing the lock.
 *
 * WHAT WAS WRONG IN THE EARLIER NOTE, AND WHAT CLOSED IT
 * -----------------------------------------------------
 * docs/notes/func_02017B4C.diff.c.txt records this function as a 104-byte
 * DIFF at 120 bytes against 124, and that source is four bytes short with the
 * whole body misaligned.  The note's skeleton is correct; only two
 * declarations are wrong, and they are the whole difference.
 *
 * The note declares the two accessor externs as returning narrow types --
 * `u8 func_02017DBC(...)` and `u16 func_02017E88(...)` -- and assigns their
 * results to same-width locals.  With the callee declared narrow the compiler
 * believes the value is already truncated, emits no shift pair, and then has
 * nothing cheap to keep the value in, so it spills BOTH to the frame
 * (`str r0, [sp, #4]` / `str r0, [sp, #8]`) and burns the two argument
 * registers r6 and r7 on a1 and a2 instead.
 *
 * The original does the opposite: it truncates at the ASSIGNMENT
 * (`lsls r0, r0, #0x18` / `lsrs r7, r0, #0x18` for the u8 and
 * `lsls r0, r0, #0x10` / `lsrs r6, r0, #0x10` for the u16) and keeps both
 * narrowed values live in r7 and r6, which frees the frame slots for a1 and
 * a2 (`str r1, [sp, #4]` / `str r2, [sp, #8]`).  That shape only compiles
 * when the CALLEE is declared to return a full word and the LOCAL is declared
 * narrow, so the cast is the source's own and not the callee's.  Declaring
 * both externs u32 and both locals u8/u16 is the entire fix; nothing else in
 * the note's body changed.
 *
 * This is the same adjudication rule docs/families/poke_tool.h states: a
 * truncation emitted at the call constrains the callee's parameter width,
 * while a truncation emitted at the assignment constrains the local's.  Here
 * it is the assignment, so the accessors stay u32 -- which also agrees with
 * every other matched file in the family (unit_02017E64.c, unit_0201854C.c,
 * unit_02018430.c all declare func_02017E88 returning u32).
 *
 * The third argument of func_02017E64 is a plain u32 and not a pointer: the
 * note spells it `void *` and passes `(void *)0x78`, which compiles the same
 * here but is a claim the bytes do not support, since id 9 is a byte field.
 *
 * Nothing here is version specific: 5, 9, 0x4C, 0x6F and 0x74 are field
 * selectors and 0x20 is a halfword count.  g_020A7370 and g_021462F0 are
 * globals, so their addresses are build properties.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017B4C.c \
 *       --func func_02017B4C --addr 0x02017B4C --cc 1.1p1 --thumb
 */
u32 func_02017B4C(void *a0, u32 a1, u32 a2, u32 a3)
{
    u8  v = (u8)func_02017DBC(a0);
    u16 w = (u16)func_02017E88(a0, 5, 0);

    func_02017E88(a0, 0x6f, 0);
    func_02017E64(a0, 0x4c, 0);
    func_02017E64(a0, 9, 0x78);
    func_02045F5C(g_020A7370, w, (u16 *)g_021462F0, 0x20);
    func_02017E64(a0, 0x74, (u32)g_021462F0);
    func_0202F1B4((u32)a0, 2, a1, a2, a3);
    return func_02017DE4(a0, v);
}



/*
 * Three "rows" of a dialog/UI record: for each row index below 3, read the
 * three fields at +0x37/+0x3B/+0x3F and write the copies back at
 * +0x36/+0x3A/+0x3E (the field before each), then clear the three
 * single-byte fields at 0x39/0x3D/0x41.
 *
 * The loop counter is the function's own second parameter -- there is no
 * initialiser, the entry test is `cmp r4, #3 / bhs` straight off the
 * argument, and the back edge is `cmp r4, #3 / blo`, so the source is
 * `for (; i < 3; i++)` over an unsigned i, not a local counter.
 *
 * The u16/u8 shift pairs are the destination widths of the three temporaries
 * (`lsls #16 / lsrs #16` versus `lsls #24 / lsrs #24` for a u8), which is
 * what fixes the return type of sub_02017E1C as wider than both.  The first
 * temporary is live across the other two reads and spills to the `push`
 * home area (`str r0, [sp]` / `ldr r2, [sp]`), which is why r3 is in the
 * push list without being read anywhere.
 *
 * EXACT*: the listing extent runs to 136 bytes because the follower at
 * 0x02017C50 saves no lr and carries no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017BC8.c \
 *       --func func_02017BC8 --addr 0x02017BC8 --cc 1.1p1 --thumb
 */
void func_02017BC8(u8 *p, u32 i)
{
    for (; i < 3; i++) {
        u16 a = sub_02017E1C(p, i + 0x37, 0);
        u8  b = sub_02017E1C(p, i + 0x3b, 0);
        u8  c = sub_02017E1C(p, i + 0x3f, 0);

        sub_02017E40(p, i + 0x36, a);
        sub_02017E40(p, i + 0x3a, b);
        sub_02017E40(p, i + 0x3e, c);
    }
    sub_02017E40(p, 0x39, 0);
    sub_02017E40(p, 0x3d, 0);
    sub_02017E40(p, 0x41, 0);
}


/*
 * Picks one of three record types and writes selector 0xa.  `mask` is a
 * bit test against the byte returned by selector 0, and which bit it is
 * depends on selector 0x77: below 0x14 the mask is bit 0, at or above it the
 * mask is bit 16.  The comparison against 0x14 is *unsigned* in the original
 * (`bhs`, not `bge`), so func_02017E88 must be declared returning an unsigned
 * type - an `int` declaration emits `bge` and costs four bytes.
 *
 * Declaration order is load bearing: `r6` (the 0x1a/0x1b/0x1c selector) is
 * declared first and takes the higher register, `mask` second and takes the
 * lower one.  Reversing them keeps the same instruction count but swaps r4
 * and r6 in nine places.
 *
 * EXACT*: the extent runs into the follower's four-byte pad.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02017C50.c \
 *       --func func_02017C50 --addr 0x02017C50 --cc 1.1p1 --thumb
 */
void func_02017C50(int a0, int a1, int a2)
{
    int v = (int)func_02019C54(a1, (unsigned short)func_02017E88((void *)a0, 0x6f, 0));
    int r7 = func_02017E88((void *)a0, 0, 0);
    int r6 = 0x1a;
    u32 mask = 1 << 16;

    if (func_02017E88((void *)a0, 0x77, 0) < 0x14) {
        mask = 1;
    }
    if (func_02017E88((void *)a0, 0x71, 0) != 0) {
        r6 = 0x1c;
    } else if (func_02019C7C((void *)v) == 2 && (r7 & mask) != 0) {
        r6 = 0x1b;
    }
    func_02017E64((void *)a0, 0xa, func_0201AE1C((const struct Personal *)v, r6));
}
