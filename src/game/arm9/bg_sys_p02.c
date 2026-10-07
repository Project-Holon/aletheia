/*
 * file:     bg_sys_p02.c
 * unit:     yes
 * function: func_0203F1FC, func_0203F258, func_0203F2FC, func_0203F328, func_0203F37C, func_0203F388, func_0203F3B4, func_0203F3F0, func_0203F42C, func_0203F46C, func_0203F49C, func_0203F4CC, func_0203F4E4, func_0203F4FC, func_0203F524, func_0203F540, func_0203F5FC, func_0203F63C, func_0203F684, func_0203F6D8, func_0203F734, func_0203F768, func_0203F7C4, func_0203F8F4, func_0203F9B4, func_0203FA08, func_0203FAF0, func_0203FB44, func_0203FC28, func_0203FC6C, func_0203FCA0, sub_020403F4, func_0204044C, func_0204047C, sub_02040588, sub_02040618, sub_020407E8, sub_02040804
 * address:  0x0203F1FC
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand from the verified parts of tools/restructure.py.
 *
 * symbols:
 *   g_021469F8     0x021469F8  data
 *   func_02081B8C  0x02081B8C  arm
 *   sub_02088168   0x02088168  arm
 *   sub_020813D8   0x020813D8  arm
 *   sub_0208142C   0x0208142C  arm
 *   sub_020814C0   0x020814C0  arm
 *   sub_02082D44   0x02082D44  arm
 *   g_021469FC     0x021469FC  data
 *   g_02146A0C     0x02146A0C  data
 *   g_02146A1C     0x02146A1C  data
 *   g_02146A44     0x02146A44  data
 *   g_020A7E5C     0x020A7E5C  data
 *   tbl_020A08B6   0x020A08B6  data a2
 *   tbl_020A1B38   0x020A1B38  data
 *   func_020403F4  0x020403F4  arm
 *   func_02033C9C  0x02033C9C  arm
 *   func_020307B0  0x020307B0  arm
 *   func_020416B8  0x020416B8  arm
 *   func_02033CC0  0x02033CC0  arm
 *   func_02033F64  0x02033F64  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_020341F0  0x020341F0  arm
 *   sub_020416B8   0x020416B8  arm
 *   func_0203422C  0x0203422C  arm
 *   func_0207D4B0  0x0207D4B0  arm
 *   func_0207D518  0x0207D518  arm
 *   func_0204349C  0x0204349C  arm
 *   func_02043558  0x02043558  arm
 *   func_020434CC  0x020434CC  arm
 *   func_02043588  0x02043588  arm
 *   sub_02030734   0x02030734  arm
 *   sub_02043094   0x02043094  arm
 *   sub_020307B0   0x020307B0  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02042360  0x02042360  arm
 *   func_020423D4  0x020423D4  arm
 *   func_0203D814  0x0203D814  arm
 *   g_BgConfig     0x02146A44  data
 */
#include "../../matched/include/Obj16002.h"

struct MATHCRC16Table;
struct RTCDate;
struct RTCTime;
struct AreaMan;
struct Obj;
typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef signed int         s32;
typedef short              s16;
typedef long long          s64;
typedef unsigned long long u64;

typedef s32 fx32;

struct VecFx32 { fx32 x; fx32 y; fx32 z; };

struct Mt {
    u32 mt[624];
    s32 index;
    u32 unk_9c4;
    u32 unk_9c8;
    u8  unk_9cc[0x200];
};

struct Lcg64 {
    u64 x;
    u64 mul;
    u64 add;
};

struct Block {
    u32 unk_00;
    u32 unk_04;
    s32 unk_08;
    u8  pad_0c[0x3c];
};

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
};

struct RtcRequest {
    u32            unk_00;
    u32            unk_04;
    s32            unk_08;
    u32            result;
    struct RtcDate date;
    struct RtcTime time;
    struct RtcDate stagedDate;
    struct RtcTime stagedTime;
};

struct RtcDate_0203F540 {
    s32 year;
    u32 month;
    s32 day;
    s32 week;
};

#define REG_DISPCNT (*(volatile u32 *)0x04000000)

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgVramReq {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct Bg {
    void *buf;
    u32   bufSize;
    u32   unk_08;
    u32   scrollX;
    u32   scrollY;
    u8    type;
    u8    unk_15;
    u8    unk_16;
    u8    unk_17;
    u16   unk_18;
    u16   unk_1a;
    u32   unk_1c;
    u32   unk_20;
    u32   unk_24;
    u32   unk_28;
};

struct BgSys {
    u16       heapId;
    u16       unk_02;
    u16       unk_04;
    u16       unk_06;
    struct Bg bgs[8];
    void     *unk_168;
    void     *unk_16c;
    u32       unk_170[8];
    u32       unk_190[8];
    u32       unk_1b0[8];
};

extern u16 func_02081B8C(struct MATHCRC16Table *table, void *data, u32 dataLength);
extern void sub_02088168(u32 *buffer);
extern void sub_020813D8(void *p);
extern void sub_0208142C(void *ctx, void *buf, u32 n);
extern void sub_020814C0(void *ctx, void *out);
extern void sub_02082D44(void *in, void *out, u32 n);
extern void func_02088788(void);
extern void func_02082BCC(void *dst, u32 value, u32 size);
extern u32  func_02088944(struct RtcDate *date, struct RtcTime *time,
                          void (*done)(u32, struct RtcRequest *),
                          struct RtcRequest *arg);
extern long long func_02089004(struct RTCDate *date, struct RTCTime *time);
extern s32 func_02088F58(struct RTCDate *date);
extern int _s32_div_f(int n, int d);
extern void VEC_Subtract(const struct VecFx32 *a, const struct VecFx32 *b,
                         struct VecFx32 *out);
extern void VEC_Normalize(const struct VecFx32 *a, struct VecFx32 *out);
extern fx32 VEC_DotProduct(const struct VecFx32 *a, const struct VecFx32 *b);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern u32 func_020307B0(void *p);
extern struct AreaMan *func_02033C00(u32 size, u32 heap);
extern u32 func_02033C9C(void *a);
extern s32 func_02033CC0(struct AreaMan *p, u32 start, u32 limit, u32 len);
extern u32 func_02033F64(u32 arena, u32 a, u32 b, u32 c);
extern s32 func_020341F0(struct AreaMan *p, u32 start, u32 len);
extern void func_0203422C(struct AreaMan *p, u32 start, s32 len);
extern u8 func_020416B8(int channel);
extern u32 func_0207D4B0(u32 a, u32 b, u32 c);
extern u32 func_0207D518(u32 a);
extern void func_0204349C(void);
extern void func_02043558(void);
extern void func_020434CC(u32 handle);
extern void func_02043588(u32 handle);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040618(u32 bgId, u32 which, u32 value);
extern int func_02042218(int a0, int a1);
extern void func_020423D4(u32 bgId);
extern void func_02042360(struct Obj *p, u32 op, u32 value);
extern void func_02042FF8(u32 bgId, u32 offset, u32 size);
extern void func_02082A48(u32 value, void *dest, u32 size);
extern void func_0203D814(u32 x, u32 y);
extern void sub_02043094(u32 index, u32 zero, u32 cookie);
extern int func_0203F7C4(int a0, int a1, int a2, int a3, int a4, int a5);
void func_0203F42C(u32 result, struct RtcRequest *req);
void func_0203F46C(struct RtcRequest *req);
u16 func_0203F1FC(const u8 *src, u32 len);
u32 func_0203F2FC(const u8 *p, u32 len);
void func_0203F328(u16 *p, u32 size, u32 seed);
void func_0203F37C(void *p, unsigned int size, unsigned int seed);
u16 func_0203F388(u32 *seed);
void func_0203F3B4(void);
void func_0203F3F0(void);
u32 func_0203F4FC(void);
void func_0203F524(void);
int func_0203F5FC(u32 x);
s16 func_0203F63C(u32 x);
short func_0203F684(unsigned short x);
s16 func_0203F6D8(s32 x);
u16 func_0203F734(int x);
int func_0203F768(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
void func_0203F8F4(u16 heapId);
void sub_020403F4(u32 i);
void func_0204044C(u32 mode);
void sub_02040588(unsigned char which, unsigned char enable);
void sub_02040618(u32 layer, u32 a, u32 b);
extern u16 tbl_020A08B6[];
extern s16 tbl_020A1B38[];
extern struct Block g_021469FC;
extern struct Mt *g_021469F8;
extern struct RtcDate g_02146A0C;
extern struct RtcTime g_02146A1C;
extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];

/*
 * TU: gf_standard.c.
 *
 * Push bytes into the 0x200-byte buffer at +0x9cc of the random-number
 * block.  A length below two is padded out to two by duplicating the first
 * byte through a two-byte stack buffer.  0x9cc is out of reach of a single
 * ARM immediate, so the base is always two `add`s (+0x1cc then +0x800).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F1FC.c \
 *       --func func_0203F1FC --addr 0x0203F1FC --cc 1.1p1 --arm
 */
u16 func_0203F1FC(const u8 *src, u32 len)
{
    if (len < 2) {
        u8 pair[2];

        pair[0] = src[0];
        pair[1] = src[0];
        return func_02081B8C((struct MATHCRC16Table *)g_021469F8->unk_9cc, pair, 2);
    } else {
        return func_02081B8C((struct MATHCRC16Table *)g_021469F8->unk_9cc, (void *)src, len);
    }
}


/*
 * gf_standard.c: seed a 64-bit LCG from a hash of fresh entropy
 * (docs/families/gf_standard.h).  The output record is THREE u64s, not six
 * u32s: { x, mul = 0x5D588B656C078965, add = 0x269EC3 }, the standard
 * 64-bit LCG constants.  Written as four u32 stores the constants are
 * coloured r1/r0 instead of r0/r1 (the 8-byte residue of
 * docs/notes/pkt_0203F258.c.txt); written as two u64 stores the compiler
 * pairs each low/high half and it is byte-exact.  Reached only as a
 * function pointer (pool word 0x020056CC).
 */
void func_0203F258(struct Lcg64 *out)
{
    u8 a[8];
    u8 c[0x20];
    u8 b[0x14];
    u8 d[0x60];

    sub_02088168((u32 *)c);
    sub_020813D8(d);
    sub_0208142C(d, b, 0x14);
    sub_0208142C(d, c, 0x20);
    sub_020814C0(d, b);
    sub_02082D44(b, a, 8);
    out->x = ((struct Obj16002 *)a)->f0;
    out->mul = 0x5D588B656C078965ULL;
    out->add = 0x269EC3;
}


/*
 * Additive byte checksum.  The accumulator is declared before the index, so
 * it takes r3 and the index is rematerialised from it with `mov ip, r3`
 * rather than a second `mov #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F2FC.c \
 *       --func func_0203F2FC --addr 0x0203F2FC --cc 1.1p1 --arm
 */
u32 func_0203F2FC(const u8 *p, u32 len)
{
    u32 sum = 0;
    u32 i;

    for (i = 0; i < len; i++) {
        sum += p[i];
    }
    return sum;
}


/*
 * TU: gf_standard.c.
 *
 * XOR a halfword buffer against the LCG stream seeded by the third
 * argument.  The function really starts at 0x0203F328, not at the
 * 0x0203F32C that disasm.py labels: the first word is `push {r0,r1,r2,r3}`,
 * the home area that taking `&seed` forces, and the matching `add sp, sp,
 * #0x10` is what makes the epilogue pop lr and then `bx lr` instead of
 * popping pc.  `seed` lives at sp+0x20 once both pushes are done.
 *
 * EXACT*, not EXACT: disasm.py labels 0x0203F32C, so the inferred extent
 * for 0x0203F328 is the single `push {r0,r1,r2,r3}` word; the real function
 * is 0x0203F328-0x0203F37C.  0x0203F328 wants seeding into
 * layout/function_starts.txt and 0x0203F32C wants removing from it.
 *
 * func_0203F388 has exactly one caller image-wide, this one, so its only
 * route to a witness is its own manifest entry in this same shard; the
 * first `manifest --verify` after adding both files leaves this one at
 * MATCH* and the second promotes it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F328.c \
 *       --func func_0203F328 --addr 0x0203F328 --cc 1.1p1 --arm
 */
void func_0203F328(u16 *p, u32 size, u32 seed)
{
    u32 i;
    u32 n = size >> 1;

    for (i = 0; i < n; i++) {
        p[i] ^= func_0203F388(&seed);
    }
}

void func_0203F37C(void *p, unsigned int size, unsigned int seed){ func_0203F328(p, size, seed); }


/*
 * The standard 32-bit LCG (multiplier 0x41c64e6d, increment 0x6073) over a
 * caller-supplied seed word, returning the top halfword.  0x6073 is not an
 * ARM rotated immediate, so the increment is two `add`s; the `lsl`/`lsr`
 * pair after the first `lsr` is the u16 return type's truncation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F388.c \
 *       --func func_0203F388 --addr 0x0203F388 --cc 1.1p1 --arm
 */
u16 func_0203F388(u32 *seed)
{
    u32 v = *seed * 0x41c64e6d + 0x6073;

    *seed = v;
    return (u16)(v >> 16);
}


/*
 * Reset of the 0x48-byte block at 0x021469FC: zero it wholesale, then write
 * its first three words explicitly (the redundant stores are in the source;
 * the memset has already cleared them) and hand it to func_0203F46C.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F3B4.c \
 *       --func func_0203F3B4 --addr 0x0203F3B4 --cc 1.1p1 --arm
 */
void func_0203F3B4(void)
{
    func_02088788();
    func_02082BCC(&g_021469FC, 0, 0x48);
    g_021469FC.unk_00 = 0;
    g_021469FC.unk_04 = 0;
    g_021469FC.unk_08 = 0;
    func_0203F46C((struct RtcRequest *)(&g_021469FC));
}


/*
 * TU: gf_standard.c.
 *
 * Per-frame tick on the block at 0x021469FC: while +0x04 is clear, count
 * frames in +0x08 and every eleventh one reset the counter and run
 * func_0203F46C.  The `ble` says +0x08 is signed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F3F0.c \
 *       --func func_0203F3F0 --addr 0x0203F3F0 --cc 1.1p1 --arm
 */
void func_0203F3F0(void)
{
    if (g_021469FC.unk_04 != 0) {
        return;
    }
    g_021469FC.unk_08++;
    if (g_021469FC.unk_08 <= 10) {
        return;
    }
    g_021469FC.unk_08 = 0;
    func_0203F46C((struct RtcRequest *)(&g_021469FC));
}


/*
 * TU: gf_standard.c.
 *
 * Completion callback for the asynchronous RTC read started by
 * func_0203F46C: publish the result code, mark the block busy, promote the
 * staging date and time at +0x2c/+0x3c into the live copies at +0x10/+0x20,
 * then clear the busy flag.  Both promotions are whole-structure
 * assignments, so each is one inlined ldm/stm pair.
 *
 * Its address reaches the image only as the pool word at 0x0203F498 inside
 * func_0203F46C, never as a branch target, so this file's manifest entry is
 * the only thing that can attest that relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F42C.c \
 *       --func func_0203F42C --addr 0x0203F42C --cc 1.1p1 --arm
 */
void func_0203F42C(u32 result, struct RtcRequest *req)
{
    req->result = result;
    req->unk_00 = 1;
    req->date = req->stagedDate;
    req->time = req->stagedTime;
    req->unk_04 = 0;
}


/*
 * TU: gf_standard.c.
 *
 * Start an asynchronous RTC read into the staging date and time at
 * +0x2c/+0x3c, with func_0203F42C as the completion callback and the block
 * itself as its argument.  The busy flag at +0x04 is raised before the call
 * and the request's return code is parked in +0x0c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F46C.c \
 *       --func func_0203F46C --addr 0x0203F46C --cc 1.1p1 --arm
 */
void func_0203F46C(struct RtcRequest *req)
{
    req->unk_04 = 1;
    req->result = func_02088944(&req->stagedDate, &req->stagedTime,
                                func_0203F42C, req);
}


/*
 * TU: gf_standard.c.
 *
 * Copy the cached RTC date and time out to the caller.  Both are whole
 * structure assignments, four words and three words, so each becomes one
 * inlined ldm/stm pair and the two out pointers have to be parked in lr and
 * ip because the copies want r0-r3.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F49C.c \
 *       --func func_0203F49C --addr 0x0203F49C --cc 1.1p1 --arm
 */
void func_0203F49C(struct RtcDate *date, struct RtcTime *time)
{
    *date = g_02146A0C;
    *time = g_02146A1C;
}


/*
 * TU: gf_standard.c.  Copy the cached RTC time out; three words, so one
 * ldm/stm pair and no frame at all.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F4CC.c \
 *       --func func_0203F4CC --addr 0x0203F4CC --cc 1.1p1 --arm
 */
void func_0203F4CC(struct RtcTime *time)
{
    *time = g_02146A1C;
}


/*
 * TU: gf_standard.c.  Copy the cached RTC date out; four words, one ldm/stm
 * pair, no frame.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F4E4.c \
 *       --func func_0203F4E4 --addr 0x0203F4E4 --cc 1.1p1 --arm
 */
void func_0203F4E4(struct RtcDate *date)
{
    *date = g_02146A0C;
}


/*
 * Seconds since midnight out of the three-word global at 0x02146A1C: the
 * minutes and hours are the first two members of the source's struct and
 * come out of one `ldm`.  The sum is spelled minutes-before-hours -
 * `m * 60 + h * 3600` - and that order is what makes the hours term the
 * `mul` and the minutes term the `mla`, with the seconds member added last.
 * Subtracting only the ordering from the swapped spelling costs the `ldm`
 * and the paired multiply and adds a pool word.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F4FC.c \
 *       --func func_0203F4FC --addr 0x0203F4FC --cc 1.1p1 --arm
 */
u32 func_0203F4FC(void)
{
    u32 *p = (u32 *)(0x2146A1C);

    return p[1] * 60 + p[0] * 3600 + p[2];
}


/*
 * TU: gf_standard.c.
 *
 * Refresh the cached RTC date and time: a tail call, so the callee's
 * address is a third pool word and the transfer is `bx ip`, and another
 * unlabelled leaf because nothing is pushed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F524.c \
 *       --func func_0203F524 --addr 0x0203F524 --cc 1.1p1 --arm
 */
void func_0203F524(void)
{
    func_02089004((struct RTCDate *)(&g_02146A0C), (struct RTCTime *)(&g_02146A1C));
}


/*
 * Blocking class: NONE AVAILABLE.  Every concrete byte of the body and of
 * the pool reproduces (MATCH*, 0 concrete bytes out).  The one unresolved
 * site is the ABS32 at +0xB4 naming the cumulative-days table at
 * 0x020A08B6, and it cannot be attested by any of the eight classes:
 *
 *   - `literal` / `label`: the pool word at 0x0203F5F4 is the ONLY reference
 *     to 0x020A08B6 anywhere in the image (layout/data_objects.txt line 475
 *     lists three referrers, but all three are the same 0x0203F5F4 word seen
 *     through three alternative unit cuts of the same listing), and it lies
 *     inside the compared range.  --suggest-split confirms: "witnesses image
 *     wide: 1, of them inside this range: 1", best partition 0 pieces.
 *   - every `sole-ref` sub-kind: 0x020A08B6 is HALFWORD aligned.
 *     `in_data_section()` in tools/match.py works at word granularity and
 *     returns False for it (it returns True for 0x020A08B4 and 0x020A08B8),
 *     so guard (a) of sole-ref/data and sole-ref/self both refuse before
 *     the ROM-word check is ever reached.  Rebasing the declaration to the
 *     4-aligned 0x020A08B4 and indexing [month + 1] is not a way out: it
 *     would put a different word in the pool and break the byte match, and
 *     guard (b) of sole-ref/self correctly refuses the claim because the
 *     ROM word at the site names 0x020A08B6, not 0x020A08B4.
 *
 * This promotes to EXACT with no change to the C the moment anything else
 * in the image is found to reference 0x020A08B6, or once a halfword-aligned
 * data start is recognised by the layout.
 *
 * WHAT IT IS.  Day-of-year from an RtcDate: the cumulative days before the
 * month out of the halfword table, plus the day, plus one if the month is
 * March or later and the year is a leap year.  It then copies the date to a
 * stack temp with month and day forced to 1 and runs func_02088F58 over
 * that temp and over the caller's date (the normalise/weekday pass), and
 * returns the day-of-year.
 *
 * Two typing details are load-bearing:
 *
 *   - `month` is UNSIGNED.  The guard at +0x28 is `blo`, not `blt`; with a
 *     signed `month` the whole function is otherwise identical and exactly
 *     one byte differs.
 *   - `year` is SIGNED.  All three divisions (by 4, 100 and 400) are the
 *     signed shapes: the `lsr ip, r0, #0x1f` sign words, the
 *     `rsb/adds ... ror #30` pair for %4, and the 0x51EB851F magic reused at
 *     `asr #5` for /100 and `asr #7` for /400.
 *
 * The leap test is ONE expression, `(y%4==0 && y%100!=0) || y%400==0`; note
 * the %4 failure path branches INTO the %400 test rather than around it,
 * which is the shared-exit tail-merge the disjunction gives.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203F540.c \
 *       --func func_0203F540 --addr 0x0203F540 --cc 1.1p1 --arm
 */
s32 func_0203F540(struct RtcDate_0203F540 *d)
{
    struct RtcDate_0203F540 t;
    s32 n = d->day + tbl_020A08B6[d->month];

    if (d->month >= 3) {
        if ((d->year % 4 == 0 && d->year % 100 != 0)
            || d->year % 400 == 0) {
            n++;
        }
    }

    t = *d;
    t.month = 1;
    t.day = 1;
    func_02088F58((struct RTCDate *)(&t));
    func_02088F58((struct RTCDate *)d);
    return n;
}


/*
 * Fixed-point sine lookup without the mod: angles of 360 or more return 0; otherwise the same table index as func_0203F684 (4096-entry table at 0x020A1B38, even halfword).
 */
int func_0203F5FC(u32 x)
{
    if (x >= 360) {
        return 0;
    }
    return tbl_020A1B38[2 * ((((s32)x * 0xFFFF) / 360) >> 4)];
}


/*
 * Twin of func_0203F5FC at table index 2 * i + 1 (cosine entry); angles of 360 or more return 0.
 */
s16 func_0203F63C(u32 x)
{
    if (x >= 360) {
        return 0;
    }
    return tbl_020A1B38[2 * ((((s32)x * 0xFFFF) / 360) >> 4) + 1];
}


short func_0203F684(unsigned short x);
s16 func_0203F6D8(s32 x);
u16 func_0203F734(int x);
int func_0203F768(int a0, int a1, int a2, int a3, int a4, int a5, int a6);
void func_0203F8F4(u16 heapId);
extern s16 tbl_020A1B38[];
extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];


/*
 * Fixed-point sine lookup: 4096-entry table at 0x020A1B38 (a flat signed
 * halfword array of interleaved pairs), indexed by (x mod 360) scaled to
 * 0xFFFF with the quotient taken against 360 again and shifted right by 4.
 * func_0203F6D8 is the identical twin at index `2 * i + 1`.
 *
 * Two details are load-bearing and cost real time:
 *
 *   - the argument is `int`, not `unsigned`.  The original opens with
 *     `lsr r1, r0, #0x1f` (the sign word) and closes the magic multiply with
 *     `add lr, r1, lr, asr #8` - the signed division shape.  The unsigned
 *     spelling compiles to `umull` against a different magic (0x6C16C16D)
 *     and is a whole-function diff.
 *   - the trailing scale is the shift `>> 4`, not a division by 16.  `/ 16`
 *     compiles to an exactness-corrected sequence (`asr r0, r2, #3` plus
 *     `add r0, r2, r0, lsr #28`), four instructions longer than the
 *     original's single `asr r1, r2, #4`.
 *
 * The 0xB60BB7 word in the pool is the compiler's own magic for /360 in the
 * `+x, asr #8` form - it is not a source-level constant and cannot be
 * matched by writing the constant out.  The table pointer resolves as
 * `literal` (x113).
 *
 * Addresses are Black-image addresses.
 */
short func_0203F684(unsigned short x)
{
    return tbl_020A1B38[2 * ((((x % 360) * 0xFFFF) / 360) >> 4)];
}


/*
 * The odd-halfword twin of func_0203F684: same signed `x % 360`, same
 * fixed-point multiply by 0xFFFF against the same 360, same `>> 4`, but the
 * table index is `2 * i + 1` instead of `2 * i`.  That difference shows up as
 * `lsl r0, r0, #1 / add r1, r0, #1 / lsl r1, r1, #1` before the `ldrsh`,
 * which is the shape of an index into a flat signed-halfword array, not of a
 * struct field access.
 *
 * EXACT*: every byte compares equal; the extent runs long only because the
 * follower is unlabelled (the listing's 144-byte extent covers this body,
 * the shared pool and the next function).  The table pointer resolves as
 * `literal` (x113).
 *
 * Addresses are Black-image addresses.
 */
s16 func_0203F6D8(s32 x)
{
    return tbl_020A1B38[2 * ((((x % 360) * 0xFFFF) / 360) >> 4) + 1];
}


/*
 * Unlabelled ARM leaf (no lr save) that scales x by 0xFFFF and divides by
 * 360: floor(x * 65535 / 360) for x < 360, else 0.  The unsigned guard
 * gives `movhs`, and mwcc emits the signed /360 magic (0xB60B60B7) because
 * the guard proves the product positive.  It is the witness that unblocks
 * the thumb caller func_02185D64.
 */
u16 func_0203F734(int x)
{
    if ((u32)x >= 0x168)
        return 0;
    return (u16)(x * 0xFFFF / 0x168);
}


/*
 * Blocked at MATCH on the `label`/`matched` classes: every concrete byte of
 * the body reproduces, but the PC24 at +0x18 to func_0203F7C4 has one
 * branch reference image-wide, this call, so the site has no witness outside
 * 0203F768..0203F7C4.  Filing 0x0203F7C4 as an EXACT manifest entry promotes
 * this file with no change to the C.
 *
 * The six-argument forwarder: the two stacked arguments are copied down into
 * the outgoing frame and the seventh is the divisor, a 20.12 fixed-point
 * product of itself with 0x323d rounded up by 0x800 and shifted down twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203F768.c \
 *       --func func_0203F768 --addr 0x0203F768 --cc 1.1p1 --arm
 */
int func_0203F768(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int v = func_0203F7C4(a0, a1, a2, a3, a4, a5);
    int d = (int)(((s64)(a6 << 13) * 0x323d + 0x800) >> 12);

    return (v << 16) / (d >> 12);
}


static inline fx32 mulfx(fx32 p, fx32 q)
{
    return (fx32)(((s64)p * q + 0x800) >> 12);
}


static inline fx32 cross2(const struct VecFx32 *p, const struct VecFx32 *q)
{
    fx32 px = p->x;
    fx32 py = p->y;

    return mulfx(px, q->y) - mulfx(q->x, py);
}

/*
 * gf_standard.c: signed distance from point C to the line through A and B,
 * six plain-integer coordinates shifted into 20.12 on entry
 * (docs/families/gf_standard.h).  Closed from the 304-byte / 55-out source
 * of docs/notes/func_0203F7C4.c.txt by one change: the value tested for the
 * sign is the SUM OF ALL THREE COMPONENTS of f = (0, 0, cross_z),
 *     cross = f.x + f.y + f.z;
 * not `f.z + a.z`.  The image's `add r2, r7, #0` is f.x + f.y (the zero
 * forwarded from the two stores), started early in the gap between the two
 * FX_Mul-style products, which is what interleaves the second product's
 * loads with the first one's normalisation.  The two `static inline`
 * helpers from the note are still load-bearing.
 */
s32 func_0203F7C4(s32 ax, s32 ay, s32 bx, s32 by, s32 cx, s32 cy)
{
    struct VecFx32 a;
    struct VecFx32 b;
    struct VecFx32 d;
    struct VecFx32 f;
    struct VecFx32 c;
    fx32 cross;
    fx32 dist;
    s32  sign;

    a.x = ax << 12;  a.y = ay << 12;  a.z = 0;
    b.x = bx << 12;  b.y = by << 12;  b.z = 0;
    c.x = cx << 12;  c.y = cy << 12;  c.z = 0;

    VEC_Subtract(&a, &c, &a);
    VEC_Subtract(&b, &c, &b);

    f.x = 0;
    d.x = a.y;
    f.y = 0;
    d.y = a.x;
    d.z = 0;

    f.z = cross2(&a, &b);
    cross = f.x + f.y + f.z;

    VEC_Normalize(&d, &d);
    VEC_Subtract(&b, &a, &f);
    dist = VEC_DotProduct(&d, &f) >> 12;
    if (dist < 0) {
        dist = -dist;
    }
    if (cross <= 0) {
        sign = -1;
        dist = dist * sign;
    }
    return dist;
}


/*
 * TU: bg_sys.c.
 *
 * Constructor for the background system: one 0x1d0-byte allocation, zeroed,
 * with two 0x1000-byte scratch buffers and three parallel eight-entry
 * tables at +0x170, +0x190 and +0x1b0.  Every access after the first goes
 * through a fresh load of the global, because each call in between may
 * write it; only the `func_02082BCC` argument is forwarded from the
 * allocator's return value, since nothing has been called since the store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F8F4.c \
 *       --func func_0203F8F4 --addr 0x0203F8F4 --cc 1.1p1 --arm
 */
void func_0203F8F4(u16 heapId)
{
    s32 i;

    g_02146A44 = sub_02030734(heapId, 0x1d0, 0, g_020A7E5C, 134);
    func_02082BCC(g_02146A44, 0, 0x1d0);
    g_02146A44->heapId = heapId;
    g_02146A44->unk_04 = 0;
    g_02146A44->unk_06 = 0;
    g_02146A44->unk_168 = func_02033C00(0x1000, heapId);
    g_02146A44->unk_16c = func_02033C00(0x1000, heapId);

    for (i = 0; i < 8; i++) {
        g_02146A44->unk_170[i] = 0;
        g_02146A44->unk_190[i] = 0;
        g_02146A44->unk_1b0[i] = 0;
    }
}


/*
 * TU: bg_sys.c.
 *
 * Teardown of the background system: free the eight layers one at a time,
 * release the two buffers at +0x168 and +0x16c, free the block itself and
 * null the global.  The counter is a u8, which is what turns `i++` into the
 * `add`/`and #0xff` pair; r4 is recycled from the counter to the global's
 * address once the loop is over, and the global is re-read through it after
 * every call because the callees may write it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F9B4.c \
 *       --func func_0203F9B4 --addr 0x0203F9B4 --cc 1.1p1 --arm
 */
void func_0203F9B4(void)
{
    u8 i;

    for (i = 0; i < 8; i++) {
        func_020403F4(i);
    }
    func_02033C9C(g_02146A44->unk_168);
    func_02033C9C(g_02146A44->unk_16c);
    func_020307B0(g_02146A44);
    g_02146A44 = 0;
}


/*
 * Allocate a run of tiles for a layer in its arena, bottom-up (top == 0,
 * func_02033CC0) or top-down (func_02033F64), and return the tile index of
 * the run relative to the layer's tile base, or -1.  Closed in wave 11:
 * the arena base is selected into a local BEFORE the direction test, the
 * round-up flag is `f = (size % t != 0)` (remainder taken first, then the
 * quotient), and the tile stride `t` is an int local (tools/permuter.py,
 * type:l(t:u32->int)); every divide stays unsigned because each dividend
 * is u32.
 */
u32 func_0203FA08(u32 layer, u32 size, u32 top)
{
    int t = func_020416B8(layer & 0xff);
    struct BgSys *g = g_02146A44;
    u32 d1 = g->unk_170[layer] / t;
    u32 d2 = g->unk_1b0[layer] / t;
    u32 f;
    u32 n, r, base;

    f = (size % t != 0);
    n = size / t;
    base = (layer < 4) ? (u32)g->unk_168 : (u32)g->unk_16c;
    if (top == 0)
        r = func_02033CC0((struct AreaMan *)base, d1, d2, n + f);
    else
        r = func_02033F64(base, d1 + d2 - 1, d2, n + f);
    if (r == 0xFFFFFFFF)
        return 0xFFFFFFFF;
    return (r * t - g_02146A44->unk_170[layer]) / t;
}


u32 func_0203FAF0(u32 a, u32 b, u32 c)
{
    u32 d = func_020416B8(a & 0xff);

    d = g_02146A44->unk_170[a] / d;
    return func_020341F0((struct AreaMan *)((a < 4) ? g_02146A44->unk_168 : g_02146A44->unk_16c),
                  d + b, c);
}


/*
 * TU: bg_sys.c.
 *
 * Release half of the pair whose reserve half is sub_02042FF8: same arena
 * selection by layer index (0-3 at +0x168, 4-7 at +0x16c, anything else a
 * no-op) and the same round-up of a byte length to arena units, but the unit
 * here is the layer's own tile stride from sub_020416B8 rather than the
 * constant 32, so both the bias and the round-up are real divisions.
 *
 * Codegen note: the biased start index must be written back into the
 * `offset` parameter rather than into a fresh local.  A fresh local is
 * coalesced onto a different callee-saved register and shuffles the whole
 * r5/r6/r7 assignment (14 bytes wrong, same instructions); see
 * docs/idioms/reassigning-a-parameter-keeps-its-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203FB44.c \
 *       --func func_0203FB44 --addr 0x0203FB44 --cc 1.1p1 --arm
 */
void func_0203FB44(u32 layer, u32 offset, u32 size)
{
    u32           unit = func_020416B8((u8)layer);
    struct BgSys *p    = g_02146A44;

    offset = (p->unk_170[layer] + offset * unit) / unit;

    switch (layer) {
    case 0:
    case 1:
    case 2:
    case 3:
        func_0203422C(p->unk_168, offset,
                      ((size % unit) ? 1 : 0) + size / unit);
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        func_0203422C(p->unk_16c, offset,
                      ((size % unit) ? 1 : 0) + size / unit);
        break;
    }
}


/*
 * TU: bg_sys.c (the initialiser at 0x0203FCA0 is the next function up).
 *
 * Bring the display back up from a saved four-word config block, then clear
 * REG_DISPCNT's two mode fields.  The two clears are separate read-modify-
 * writes in the original, each reloading through the base kept in r1, so
 * they are two statements in the source and not one masked store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203FC28.c \
 *       --func func_0203FC28 --addr 0x0203FC28 --cc 1.1p1 --arm
 */
void func_0203FC28(struct DispConfig *cfg)
{
    func_0207D4B0(cfg->unk_00, cfg->unk_04, cfg->unk_0c);
    func_0207D518(cfg->unk_08);
    REG_DISPCNT &= ~0x38000000;
    REG_DISPCNT &= ~0x07000000;
    func_0204349C();
    func_02043558();
}


/*
 * bg_sys.c, the two-way forwarder that sits immediately above
 * func_0203FCA0.  Both arms are a single nested call whose result is
 * handed straight on and then dropped, so the function is void and
 * needs no callee-saved register: `push {r3, lr}` is the eight-byte
 * stack alignment pad, not a saved argument.
 *
 * The `ldm r2, {r0, r1}` in the first arm is two adjacent fields loaded
 * as two consecutive arguments, not a struct copy; writing the two
 * field reads as separate arguments to the same call is what folds them
 * into the load-multiple.
 */
void func_0203FC6C(const struct BgVramReq *req, u32 which)
{
    if (which == 0) {
        func_020434CC(func_0207D4B0(req->unk_00, req->unk_04, req->unk_0c));
    } else {
        func_02043588(func_0207D518(req->unk_08));
    }
}


#define REG16(a) (*(volatile u16 *)(a))

#define REG_BG0CNT_A  0x04000008
#define REG_BG1CNT_A  0x0400000A
#define REG_BG2CNT_A  0x0400000C
#define REG_BG3CNT_A  0x0400000E
#define REG_BG0CNT_B  0x04001008
#define REG_BG1CNT_B  0x0400100A
#define REG_BG2CNT_B  0x0400100C
#define REG_BG3CNT_B  0x0400100E

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

/* TwlSDK nitro/gx/gx_bgcnt.h parameter types; only the type matters here */
typedef enum { SS0 = 0 } GXBGScrSizeText;
typedef enum { SA0 = 0 } GXBGScrSizeAffine;
typedef enum { CM0 = 0 } GXBGColorMode;
typedef enum { SB0 = 0 } GXBGScrBase;
typedef enum { CB0 = 0 } GXBGCharBase;
typedef enum { EP0 = 0 } GXBGExtPltt;
typedef enum { AO0 = 0 } GXBGAreaOver;
typedef int BOOL;
static inline void G2_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG0CNT_A) = (u16)((REG16(REG_BG0CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2_SetBG0Priority(int priority)
{
    REG16(REG_BG0CNT_A) = (u16)((REG16(REG_BG0CNT_A) & ~3) | (priority << 0));
}
static inline void G2_BG0Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG0CNT_A) |= 0x40;
    } else {
        REG16(REG_BG0CNT_A) &= ~0x40;
    }
}
static inline void G2_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG1CNT_A) = (u16)((REG16(REG_BG1CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2_SetBG1Priority(int priority)
{
    REG16(REG_BG1CNT_A) = (u16)((REG16(REG_BG1CNT_A) & ~3) | (priority << 0));
}
static inline void G2_BG1Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG1CNT_A) |= 0x40;
    } else {
        REG16(REG_BG1CNT_A) &= ~0x40;
    }
}
static inline void G2_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
static inline void G2_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}
static inline void G2_SetBG2ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG2Priority(int priority)
{
    REG16(REG_BG2CNT_A) = (u16)((REG16(REG_BG2CNT_A) & ~3) | (priority << 0));
}
static inline void G2_BG2Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG2CNT_A) |= 0x40;
    } else {
        REG16(REG_BG2CNT_A) &= ~0x40;
    }
}
static inline void G2_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
static inline void G2_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}
static inline void G2_SetBG3ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}
static inline void G2_SetBG3Priority(int priority)
{
    REG16(REG_BG3CNT_A) = (u16)((REG16(REG_BG3CNT_A) & ~3) | (priority << 0));
}
static inline void G2_BG3Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG3CNT_A) |= 0x40;
    } else {
        REG16(REG_BG3CNT_A) &= ~0x40;
    }
}
static inline void G2S_SetBG0Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG0CNT_B) = (u16)((REG16(REG_BG0CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2S_SetBG0Priority(int priority)
{
    REG16(REG_BG0CNT_B) = (u16)((REG16(REG_BG0CNT_B) & ~3) | (priority << 0));
}
static inline void G2S_BG0Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG0CNT_B) |= 0x40;
    } else {
        REG16(REG_BG0CNT_B) &= ~0x40;
    }
}
static inline void G2S_SetBG1Control(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase, GXBGExtPltt bgExtPltt)
{
    REG16(REG_BG1CNT_B) = (u16)((REG16(REG_BG1CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2) | (bgExtPltt << 13));
}
static inline void G2S_SetBG1Priority(int priority)
{
    REG16(REG_BG1CNT_B) = (u16)((REG16(REG_BG1CNT_B) & ~3) | (priority << 0));
}
static inline void G2S_BG1Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG1CNT_B) |= 0x40;
    } else {
        REG16(REG_BG1CNT_B) &= ~0x40;
    }
}
static inline void G2S_SetBG2ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
static inline void G2S_SetBG2ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}
static inline void G2S_SetBG2ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG2Priority(int priority)
{
    REG16(REG_BG2CNT_B) = (u16)((REG16(REG_BG2CNT_B) & ~3) | (priority << 0));
}
static inline void G2S_BG2Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG2CNT_B) |= 0x40;
    } else {
        REG16(REG_BG2CNT_B) &= ~0x40;
    }
}
static inline void G2S_SetBG3ControlText(GXBGScrSizeText screenSize, GXBGColorMode colorMode, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (colorMode << 7) | (screenBase << 8) | (charBase << 2));
}
static inline void G2S_SetBG3ControlAffine(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (screenBase << 8) | (charBase << 2) | (areaOver << 13));
}
static inline void G2S_SetBG3ControlType2(GXBGScrSizeAffine screenSize, GXBGAreaOver areaOver, GXBGScrBase screenBase, GXBGCharBase charBase)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & 0x43) | (screenSize << 14) | (charBase << 2) | (screenBase << 8) | (areaOver << 13));
}
static inline void G2S_SetBG3Priority(int priority)
{
    REG16(REG_BG3CNT_B) = (u16)((REG16(REG_BG3CNT_B) & ~3) | (priority << 0));
}
static inline void G2S_BG3Mosaic(BOOL enable)
{
    if (enable) {
        REG16(REG_BG3CNT_B) |= 0x40;
    } else {
        REG16(REG_BG3CNT_B) &= ~0x40;
    }
}
/*
 * bg_sys.c: initialise one BG layer from its template.  Program BGxCNT of
 * layer bgId (0..3 main, 4..7 sub) through the TwlSDK gx_bgcnt.h inline
 * setters (text layers 0/1/4/5 always; 2/3/6/7 by type: text, affine, or the
 * game's type-2 form, whose OR order is charBase before screenBase and which
 * carries no 0x80 ext-mode bit, so it is not G2_SetBG2Control256x16Pltt),
 * then priority and mosaic, then the layer record in g_02146A44.
 *
 * Closed in wave 16 by the SDK-inline lever with the SDK's ENUM parameter
 * types (GXBGScrSizeText, GXBGColorMode, GXBGScrBase, GXBGCharBase,
 * GXBGExtPltt, GXBGAreaOver).  The same inlines with int parameters give
 * 1860 bytes, 1171 out (the type-0 store cross-jumped into the shared tail);
 * see docs/notes/func_0203FCA0.c.txt for the earlier record.
 */
void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type)
{
    u32 ss = func_02042218(tmpl->unk_10, type);

    switch (bgId) {
    case 0:
        G2_SetBG0Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2_SetBG0Priority(tmpl->unk_19);
        G2_BG0Mosaic(tmpl->unk_1c);
        break;
    case 1:
        G2_SetBG1Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2_SetBG1Priority(tmpl->unk_19);
        G2_BG1Mosaic(tmpl->unk_1c);
        break;
    case 2:
        switch (type) {
        case 0:
        default:
            G2_SetBG2ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2_SetBG2ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2_SetBG2ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2_SetBG2Priority(tmpl->unk_19);
        G2_BG2Mosaic(tmpl->unk_1c);
        break;
    case 3:
        switch (type) {
        case 0:
        default:
            G2_SetBG3ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2_SetBG3ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2_SetBG3ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2_SetBG3Priority(tmpl->unk_19);
        G2_BG3Mosaic(tmpl->unk_1c);
        break;
    case 4:
        G2S_SetBG0Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2S_SetBG0Priority(tmpl->unk_19);
        G2S_BG0Mosaic(tmpl->unk_1c);
        break;
    case 5:
        G2S_SetBG1Control(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13, tmpl->unk_18);
        G2S_SetBG1Priority(tmpl->unk_19);
        G2S_BG1Mosaic(tmpl->unk_1c);
        break;
    case 6:
        switch (type) {
        case 0:
        default:
            G2S_SetBG2ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2S_SetBG2ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2S_SetBG2ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2S_SetBG2Priority(tmpl->unk_19);
        G2S_BG2Mosaic(tmpl->unk_1c);
        break;
    case 7:
        switch (type) {
        case 0:
        default:
            G2S_SetBG3ControlText(ss, tmpl->unk_11, tmpl->unk_12, tmpl->unk_13);
            break;
        case 1:
            G2S_SetBG3ControlAffine(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        case 2:
            G2S_SetBG3ControlType2(ss, tmpl->unk_1a, tmpl->unk_12, tmpl->unk_13);
            break;
        }
        G2S_SetBG3Priority(tmpl->unk_19);
        G2S_BG3Mosaic(tmpl->unk_1c);
        break;
    }

    g_02146A44->bgs[bgId].unk_18 = 0;
    g_02146A44->bgs[bgId].unk_1c = 0x1000;
    g_02146A44->bgs[bgId].unk_20 = 0x1000;
    g_02146A44->bgs[bgId].unk_24 = 0;
    g_02146A44->bgs[bgId].unk_28 = 0;

    if (tmpl->bufSize != 0) {
        g_02146A44->bgs[bgId].buf = sub_02030734(g_02146A44->heapId,
                                                 tmpl->bufSize, 0,
                                                 g_020A7E5C, 0x231);
        func_02082A48(0, g_02146A44->bgs[bgId].buf, tmpl->bufSize);
        g_02146A44->bgs[bgId].bufSize = tmpl->bufSize;
        g_02146A44->bgs[bgId].unk_08 = tmpl->unk_0c;
    } else {
        g_02146A44->bgs[bgId].buf = 0;
        g_02146A44->bgs[bgId].bufSize = 0;
        g_02146A44->bgs[bgId].unk_08 = 0;
    }

    g_02146A44->bgs[bgId].unk_15 = tmpl->unk_10;
    g_02146A44->bgs[bgId].type = (u8)type;
    g_02146A44->bgs[bgId].unk_16 = tmpl->unk_11;

    if (type == 0 && tmpl->unk_11 == 0) {
        g_02146A44->bgs[bgId].unk_17 = 0x20;
    } else {
        g_02146A44->bgs[bgId].unk_17 = 0x40;
    }

    func_02040618(bgId, 0, tmpl->unk_00);
    func_02040618(bgId, 3, tmpl->unk_04);
    func_020423D4(bgId);

    g_02146A44->unk_170[bgId] = tmpl->unk_13 << 14;
    g_02146A44->unk_190[bgId] = tmpl->unk_12 << 11;
    g_02146A44->unk_1b0[bgId] = tmpl->unk_14;

    func_02042FF8(bgId, 0, tmpl->bufSize);
}



/*
 * Release the payload of one entry of the 0x2c-byte table hanging off the
 * singleton pointer at 0x02146A44: if the pointer at +8 is set,
 * unregister it through sub_02043094 (passing the slot index and the
 * cookie at +0xc), free it, and NULL the slot.
 *
 * The slot index arrives in r0 and is never moved, so it is still there
 * as sub_02043094's first argument after the multiply.  The zero used for
 * sub_02043094's second argument and for the final store is materialised
 * once in r6 and shared
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 * Everything after the first call re-reads the global and re-indexes,
 * because the calls may store to it.
 *
 * Byte-correct, capped at MATCH: sub_02043094 is called from this one
 * site and nowhere else in the image, so its PC24 has no outside witness
 * of any class.  --suggest-split cannot help, the site is inside the one
 * function.  It unsticks when 0x02043094 is itself decompiled to EXACT
 * or a second caller turns up in an overlay.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_020403F4.c \
 *       --func sub_020403F4 --addr 0x020403F4 --cc 1.1p1 --arm
 */
void sub_020403F4(u32 i)
{
    if (g_02146A44->bgs[i].buf == 0) {
        return;
    }
    sub_02043094(i, 0, g_02146A44->bgs[i].bufSize);
    func_020307B0(g_02146A44->bgs[i].buf);
    g_02146A44->bgs[i].buf = 0;
}


/*
 * Set the two low bits of DISPCNT (0x04000008) to the incoming mode, after
 * asking func_020434DC for the display to be brought up in mode 1.  The
 * register is a cast constant, not a relocation: its address is the pool
 * word at the end of this function.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204044C.c \
 *       --func func_0204044C --addr 0x0204044C --cc 1.1p1 --arm
 */
void func_0204044C(u32 mode)
{
    func_020434DC(1, 1);
    *(volatile u16 *)0x04000008 =
        (*(volatile u16 *)0x04000008 & ~3) | mode;
}


/*
 * Unlabelled ARM leaf: a two-to-four entry register write-back.  idx 0..7
 * selects one of eight volatile 16-bit MMIO registers (two banks of four,
 * 0x04000008..0x0400000E and 0x04001008..0x0400100E); each case clears the
 * low two bits of the register and ORs in the low bits of val.  idx > 7 is a
 * no-op (`bx lr` / `pop {r3,pc}` in the follower).
 *
 * The constants are absolute hardware addresses, so they are plain pool words
 * with no relocation.
 */
void func_0204047C(int idx, unsigned short val)
{
    volatile unsigned short *p;

    switch (idx) {
    case 0:
        p = (volatile unsigned short *)0x04000008;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 1:
        p = (volatile unsigned short *)0x0400000A;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 2:
        p = (volatile unsigned short *)0x0400000C;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 3:
        p = (volatile unsigned short *)0x0400000E;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 4:
        p = (volatile unsigned short *)0x04001008;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 5:
        p = (volatile unsigned short *)0x0400100A;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 6:
        p = (volatile unsigned short *)0x0400100C;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    case 7:
        p = (volatile unsigned short *)0x0400100E;
        *p = (unsigned short)((*p & ~3) | val);
        break;
    }
}


/*
 * Eight-way dispatch turning a small selector into a one-hot plane mask for
 * one of the two 2D engines: selectors 0..3 go to the engine-A visible-plane
 * toggle at func_020434DC with masks 1/2/4/8 and selectors 4..7 to the
 * engine-B toggle at func_02043598 with the same four.  The on/off flag is
 * the second parameter and is forwarded untouched in r1, which is why no
 * argument setup other than the mask appears in any arm.  The ARM form
 * of the dense switch is `cmp #7` plus `addls pc, pc, r0, lsl #2` over a
 * run of eight branches, with the out-of-range case falling straight into
 * the epilogue.
 */
void sub_02040588(unsigned char which, unsigned char enable)
{
    switch (which) {
    case 0:
        func_020434DC(1, enable);
        break;
    case 1:
        func_020434DC(2, enable);
        break;
    case 2:
        func_020434DC(4, enable);
        break;
    case 3:
        func_020434DC(8, enable);
        break;
    case 4:
        func_02043598(1, enable);
        break;
    case 5:
        func_02043598(2, enable);
        break;
    case 6:
        func_02043598(4, enable);
        break;
    case 7:
        func_02043598(8, enable);
        break;
    }
}


#define W(a) (*(volatile u32 *)(a))


/*
 * The per-layer scroll register flush.  Closed in wave 11 by two facts:
 * func_0203D814 takes the layer's scroll pair (x, y) as its two arguments
 * (the case-1 arm keeps r0/r1 live across the register write for the call,
 * as in func_02041B94), and scrollX is read before scrollY.  The star is the
 * unlabelled follower sub_020407E8 (already EXACT in unit_020407E8.c); the
 * true extent is 464 bytes, ending at 0x020407E8.
 */
void sub_02040618(u32 layer, u32 a, u32 b)
{
    u32 mask = 0x1ff;
    u32 hmask = mask << 16;
    u32 x, y;

    func_02042360((struct Obj *)(&g_02146A44->bgs[layer]), a, b);

    x = g_02146A44->bgs[layer].scrollX;
    y = g_02146A44->bgs[layer].scrollY;

    switch (layer) {
    case 0:
        W(0x04000010) = (x & mask) | (hmask & (y << 16));
        break;
    case 1:
        W(0x04000014) = (x & mask) | (hmask & (y << 16));
        func_0203D814(x, y);
        break;
    case 2:
        if (g_02146A44->bgs[2].type == 0) {
            W(0x04000018) = (x & mask) | (hmask & (y << 16));
        } else {
            func_020423D4(2);
        }
        break;
    case 3:
        if (g_02146A44->bgs[3].type == 0) {
            W(0x0400001c) = (x & mask) | (hmask & (y << 16));
        } else {
            func_020423D4(3);
        }
        break;
    case 4:
        W(0x04001010) = (x & mask) | (hmask & (y << 16));
        break;
    case 5:
        W(0x04001014) = (x & mask) | (hmask & (y << 16));
        break;
    case 6:
        if (g_02146A44->bgs[6].type == 0) {
            W(0x04001018) = (x & mask) | (hmask & (y << 16));
        } else {
            func_020423D4(6);
        }
        break;
    case 7:
        if (g_02146A44->bgs[7].type == 0) {
            W(0x0400101c) = (x & mask) | (hmask & (y << 16));
        } else {
            func_020423D4(7);
        }
        break;
    }
}


/*
 * The two scroll-register accessors for the BG configuration table, both of
 * them leaf functions that save nothing and therefore carry no `func_` label
 * in the listing at all: they print as an anonymous run of `.word`s between
 * the literal pool of sub_02040618 and the next labelled function at
 * 0x02040820 (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 * They were found by sweeping the address range, not by reading labels.
 *
 * Both index the same 0x2C-byte per-layer record hanging off the single
 * pointer at 0x02146A44, and return the horizontal (+0x14) and vertical
 * (+0x18) scroll values that sub_02040618 flushes to the hardware.  The
 * `mla r1, r0, r1, r2` is the array subscript: 0x2C is not a shift, so the
 * scale is a real multiply folded into the base add.
 *
 * Kept as one unit rather than two files because the pair is contiguous and
 * the whole 56-byte range, both literal pools included, reproduces exactly.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020407E8.c \
 *       --addr 0x020407E8 --arm --cc 1.1p1
 */
u32 sub_020407E8(u32 layer)
{
    return g_02146A44->bgs[layer].scrollX;
}

u32 sub_02040804(u32 layer)
{
    return g_02146A44->bgs[layer].scrollY;
}
