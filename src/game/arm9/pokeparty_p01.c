/*
 * file:     pokeparty_p01.c
 * unit:     yes
 * function: func_02019A50, func_02019A7C, func_02019A9C, func_02019ABC, func_02019B04, func_02019B44, func_02019B58, func_02019B64, func_02019B94, func_02019BA4
 * address:  0x02019A50
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
 *   gMsgBank   0x020A7370  data
 *   gNameBuf   0x021462F0  data
 *   _s32_div_f           0x0209C0A4  arm
 *   func_02019B04_Table  0x0209E324  data
 *   func_02048F4C  0x02048F4C  arm
 *   gWordBuf       0x02146398  data
 */
struct MsgData;
typedef unsigned short u16;

typedef unsigned int   u32;

struct Mon {
    u32 unk00;
};

struct BlockA {
    u16 species;
};

typedef signed char    s8;

extern void *func_02019C38(struct Mon *p, u32 pid, u32 n);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern u32 func_0201F448(const u16 *a, const u16 *b);
extern void *func_020185F0(void);
extern u32   func_02017E88(void *p, u32 id, u32 v);
extern void  func_02017E64(void *p, u32 id, u32 v);
extern void  func_02048F4C(void *a, u32 b, u32 c);
void func_02019A50(u16 *p, u32 size, u32 seed);
u16 func_02019A7C(u32 *s);
u16 func_02019A9C(const u16 *p, u32 size);
u32 func_02019B04(u32 a, u32 b, u32 n);
s8 func_02019B44(u32 a, u32 n);
void func_02019B58(void *p);
void func_02019B64(void *p);
void func_02019B94(u32 a, void *b);
u32 func_02019BA4(u32 a, u32 i);
u32 func_02019BBC(u32 item);
extern void *gMsgBank;
extern u16   gNameBuf[];
extern const s8 func_02019B04_Table[][5];
extern u32   gWordBuf[];


/*
 * The three primitives the whole save record in this region is protected
 * with.  func_02019A7C is one step of the linear congruential generator
 * `s = s * 0x41C64E6D + 0x6073` returning the middle halfword of the new
 * state, func_02019A50 XOR masks a byte range with that stream halfword by
 * halfword, and func_02019A9C is the plain halfword sum used as the checksum.
 *
 * func_02019A50 opens `push {r0, r1, r2, r3}` and closes `pop {r3}` /
 * `add sp, #0x10` / `bx r3`, which is what taking the address of a register
 * parameter costs on this front end; see
 * docs/idioms/address-of-a-register-parameter-is-a-push-of-all-four.md.  The
 * seed is passed by value and updated in place through that home slot, so a
 * caller's seed is never modified, which is what lets func_02018D34 mask the
 * same area twice with the same seed to undo itself.
 *
 * func_02019A7C carries no label in the generated listing.
 */
void func_02019A50(u16 *p, u32 size, u32 seed)
{
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        u32 *s = &seed;

        do {
            p[i] ^= func_02019A7C(s);
            i++;
        } while (i < n);
    }
}


u16 func_02019A7C(u32 *s)
{
    *s = *s * 0x41C64E6D + 0x6073;
    return (u16)(*s >> 16);
}


u16 func_02019A9C(const u16 *p, u32 size)
{
    u16 sum = 0;
    u32 i = 0;
    u32 n = size >> 1;

    if (n != 0) {
        do {
            sum = (u16)(sum + p[i]);
            i++;
        } while (i < n);
    }
    return sum;
}


/*
 * "Is the name in substruct C still the species' default name": it renders the
 * species name for substruct A's species id into the shared 0x20 halfword
 * buffer at 0x021462F0 and compares it with substruct C's own name, returning
 * 1 when they are equal.  func_02019388 (src/matched/sub_02019388.c) calls it
 * from ids 0x73 and 0x74 and stores the result in substruct B +0x10 bit 31,
 * which is the bit func_02018E34 reads back as id 0x75.  Those two calls are
 * the only references to this address in the image.
 *
 * The result local is declared before the two substruct fetches, which is what
 * puts `movs r5, #0` in front of the first call rather than after the second.
 *
 * The message bank at 0x020A7370 is a global pointer, so its address is a
 * build property and has to be re-derived for a White build rather than
 * copied; the 0x20 is a halfword count and the species id is data, so nothing
 * else here is version specific.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019ABC.c \
 *       --addr 0x02019ABC --thumb
 */
u32 func_02019ABC(struct Mon *p)
{
    u32 r = 0;
    struct BlockA *a = (struct BlockA *)func_02019C38(p, p->unk00, 0);
    void *c = func_02019C38(p, p->unk00, 2);

    func_02045F5C(gMsgBank, a->species, gNameBuf, 0x20);
    if (func_0201F448(gNameBuf, c) == 0) {
        r = 1;
    }
    return r;
}


/*
 * Scales b by a per (a, n) table entry of -1, 0 or 1; the multipliers are
 * 0x5A and 0x6E, which are 90 and 110 percent. Both arms are written out in
 * full and the compiler cross jumps their common muls/truncate/divide tail
 * into one block that the missing default branches past, which is
 * docs/idioms/switch-arms-tail-merge.md; hoisting the multiplication out of
 * the switch puts the default branch to that block instead of past it and
 * costs eight bytes.
 *
 * The table at 0x0209E324 is witnessed by the pool word of the neighbouring
 * leaf sub_02019B44.c (seeded via layout/function_starts.txt), and this
 * file's own pool word witnesses it for that one: the unit_02005DF8 /
 * unit_02005E30 pairwise treatment.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B04.c \
 *       --addr 0x02019B04 --thumb
 */
u32 func_02019B04(u32 a, u32 b, u32 n)
{
    s8 v;

    if (n >= 6) {
        return b;
    }
    v = func_02019B04_Table[a][n - 1];
    switch (v) {
    case 1:
        b = (u16)((u16)(b * 0x6E) / 100);
        break;
    case -1:
        b = (u16)((u16)(b * 0x5A) / 100);
        break;
    }
    return b;
}


/*
 * The unlabelled leaf whose pool word is the second image-wide reference to
 * the table at 0x0209E324; traced via layout/function_starts.txt. Its pool
 * word witnesses the table for unit_02019B04.c and vice versa.
 *
 * Verified with
 *   python tools/match.py one --src src/matched/sub_02019B44.c \
 *       --func func_02019B44 --addr 0x02019B44
 */
s8 func_02019B44(u32 a, u32 n)
{
    return func_02019B04_Table[a][n - 1];
}


/*
 *           func_02019BBC
 *
 * The first five of the seven functions between func_02019ABC and the cache
 * helper at 0x02019C54.  The range stops at 0x02019C38 on purpose: the two
 * functions after it, func_02019C38 and func_02019C54, each reach a data
 * object through a pool word that is the object's only reference in the whole
 * image (0x0209E3A4 at 0x02019C50 and 0x02146274 at 0x02019C78), so the
 * `literal` class has no outside witness for either and both cap at MATCH
 * however they are written.  Cutting in front of them leaves these five
 * clean.
 *
 * func_02019B58 reaches func_020185F0, which src/matched/unit_020185F0.c
 * proves is an empty `bx lr`, and then calls func_02019B64 with whatever r0
 * holds, with no register saved across the first call.  That only compiles
 * from a declaration in which func_020185F0 returns a value, so this unit
 * declares it `void *func_020185F0(void)` and passes the result straight on;
 * declaring it `void` the way unit_020185F0.c does forces a callee-saved
 * register and a four byte longer prologue.  The two declarations disagree,
 * and the image cannot say which one the original header carried, because an
 * empty function's return value is unobservable.
 *
 * func_02019B94 is docs/idioms/tail-call-is-a-pool-word-and-bx.md: it permutes
 * three arguments into an ARM callee at 0x02048F4C and has no prologue at all.
 *
 * func_02019BBC is the plate-to-type table of ids 0xAE and 0xAF of
 * func_02018E34: sixteen consecutive item ids from 0x12A map to sixteen type
 * ids and everything else to 0.  The switch value arrives as a pool word
 * rather than a `subs` immediate only because 0x12A does not fit the eight bit
 * form, so it is an ordinary constant and not the linker symbol of
 * docs/idioms/a-pooled-small-constant-argument-is-a-linker-symbol.md.
 *
 * VERSION SENSITIVITY: func_02019BBC's sixteen case labels are item ids and
 * its sixteen results are type ids, and func_02019B64 passes id 5 (species)
 * and id 0x74 (the name) of the record.  None of them is a version flag and
 * there is no exclusive-species table here, but the item ids 0x12A..0x139 are
 * content numbering and are the values to re-read first for a White build.
 *
 * Verified with
 *   python tools/match.py tu --src src/matched/unit_02019B58.c \
 *       --addr 0x02019B58 --thumb
 */
void func_02019B58(void *p)
{
    func_02019B64(func_020185F0());
}


void func_02019B64(void *p)
{
    u32 s = func_02017E88(p, 5, 0);

    func_02045F5C(gMsgBank, s, gNameBuf, 0x20);
    func_02017E64(p, 0x74, (u32)gNameBuf);
}


void func_02019B94(u32 a, void *b)
{
    func_02048F4C(b, 0x11, a);
}


u32 func_02019BA4(u32 a, u32 i)
{
    func_02019B94(a, gWordBuf);
    return gWordBuf[i];
}


u32 func_02019BBC(u32 item)
{
    switch (item) {
    case 0x12A: return 9;
    case 0x12B: return 10;
    case 0x12C: return 12;
    case 0x12D: return 11;
    case 0x12E: return 14;
    case 0x12F: return 1;
    case 0x130: return 3;
    case 0x131: return 4;
    case 0x132: return 2;
    case 0x133: return 13;
    case 0x134: return 6;
    case 0x135: return 5;
    case 0x136: return 7;
    case 0x137: return 15;
    case 0x138: return 16;
    case 0x139: return 8;
    }
    return 0;
}
