/*
 * file:     gf_standard.c
 * unit:     yes
 * function: GF_STANDARD_Init, GF_STANDARD_CompareBytes, GF_STANDARD_GetStringLength, GF_STANDARD_CompareString, GF_STANDARD_RandSeed, GF_STANDARD_Rand, GF_STANDARD_SetupCalc, GF_STANDARD_CalcHash, GF_STANDARD_Checksum, GF_STANDARD_Shuffle, GF_STANDARD_ShuffleEx, GF_STANDARD_RandLcg, GF_STANDARD_Reset, GF_STANDARD_Setup, GF_STANDARD_Task, GF_STANDARD_GetRtc, GF_STANDARD_CopyCachedRtc, GF_STANDARD_SetField00, GF_STANDARD_SetField00_F4E4, GF_STANDARD_GetTime, GF_STANDARD_SetupRtc, GF_STANDARD_SetupRtc_F540, GF_STANDARD_Get_F5FC, GF_STANDARD_SinDeg, GF_STANDARD_Get_F684, GF_STANDARD_Sin, GF_STANDARD_DegToAngle, GF_STANDARD_CalcAngle, GF_STANDARD_SetupCalc_F7C4
 * address:  0x0203EF5C
 * region:   arm9
 * compiler: dsi/1.2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Cut from bg_sys.c by tools/splitfile.py.
 *
 * symbols:
 *   g_021469F8     0x021469F8  data
 *   g_020A7E4C     0x020A7E4C  data
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   MATHi_CRC16InitTable  0x020819B8  arm
 *   MATH_CalcCRC16CCITT  0x02081B8C  arm
 *   sub_02088168   0x02088168  arm
 *   sub_020813D8   0x020813D8  arm
 *   sub_0208142C   0x0208142C  arm
 *   sub_020814C0   0x020814C0  arm
 *   sub_02082D44   0x02082D44  arm
 *   g_021469FC     0x021469FC  data
 *   g_02146A0C     0x02146A0C  data
 *   g_02146A1C     0x02146A1C  data
 *   tbl_020A08B6   0x020A08B6  data a2
 *   FX_SinCosTable_   0x020A1B38  data
 *   MI_CpuFill8  0x02082BCC  arm
 *   RTC_Init  0x02088788  arm
 *   RTC_ConvertDateToDay  0x02088F58  arm
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_GetDateTimeAsync  0x02088944  arm
 */
#include "gf_standard_shared_types.h"

struct MATHCRC16Table;

struct RTCDate;

struct RTCTime;

struct Mt {
    u32 mt[624];
    s32 mti;
    u32 mag01[2];
    u8  unk_9cc[0x200];
};

typedef long long          s64;

typedef unsigned long long u64;

typedef s32 fx32;

struct VecFx32 { fx32 x; fx32 y; fx32 z; };

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

struct RtcDateSigned {
    s32 year;
    u32 month;
    s32 day;
    s32 week;
};

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);

extern void MATHi_CRC16InitTable(struct MATHCRC16Table *table, u16 poly);

extern int STD_CompareString(const char *s1, const char *s2);

extern u16 MATH_CalcCRC16CCITT(struct MATHCRC16Table *table, void *data, u32 dataLength);

extern void sub_02088168(u32 *buffer);

extern void sub_020813D8(void *p);

extern void sub_0208142C(void *ctx, void *buf, u32 n);

extern void sub_020814C0(void *ctx, void *out);

extern void sub_02082D44(void *in, void *out, u32 n);

extern void RTC_Init(void);

extern void MI_CpuFill8(void *dst, u32 value, u32 size);

extern u32  RTC_GetDateTimeAsync(struct RtcDate *date, struct RtcTime *time,
                          void (*done)(u32, struct RtcRequest *),
                          struct RtcRequest *arg);

extern long long RTC_ConvertDateTimeToSecond(struct RTCDate *date, struct RTCTime *time);

extern s32 RTC_ConvertDateToDay(struct RTCDate *date);

extern void VEC_Subtract(const struct VecFx32 *a, const struct VecFx32 *b,
                         struct VecFx32 *out);

extern void VEC_Normalize(const struct VecFx32 *a, struct VecFx32 *out);

extern fx32 VEC_DotProduct(const struct VecFx32 *a, const struct VecFx32 *b);

void GF_STANDARD_Init(u32 heapId);

s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);

u32 GF_STANDARD_GetStringLength(const u8 *s);

int GF_STANDARD_CompareString(const char *s1, const char *s2);

void GF_STANDARD_RandSeed(u32 seed);

u32 GF_STANDARD_Rand(void);

u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len);

void GF_STANDARD_CalcHash(struct Lcg64 *out);

u32 GF_STANDARD_Checksum(const u8 *p, u32 len);

void GF_STANDARD_Shuffle(u16 *p, u32 size, u32 seed);

void GF_STANDARD_ShuffleEx(void *p, unsigned int size, unsigned int seed);

u16 GF_STANDARD_RandLcg(u32 *seed);

void GF_STANDARD_Reset(void);

void GF_STANDARD_Setup(void);

void GF_STANDARD_Task(u32 result, struct RtcRequest *req);

void GF_STANDARD_GetRtc(struct RtcRequest *req);

void GF_STANDARD_CopyCachedRtc(struct RtcDate *date, struct RtcTime *time);

void GF_STANDARD_SetField00(struct RtcTime *time);

void GF_STANDARD_SetField00_F4E4(struct RtcDate *date);

u32 GF_STANDARD_GetTime(void);

void GF_STANDARD_SetupRtc(void);

s32 GF_STANDARD_SetupRtc_F540(struct RtcDateSigned *d);

int GF_STANDARD_Get_F5FC(u32 x);

short GF_STANDARD_SinDeg(u32 x);

short GF_STANDARD_Get_F684(unsigned short x);

short GF_STANDARD_Sin(s32 x);

u16 GF_STANDARD_DegToAngle(int x);

int GF_STANDARD_CalcAngle(int a0, int a1, int a2, int a3, int a4, int a5, int a6);

s32 GF_STANDARD_SetupCalc_F7C4(s32 ax, s32 ay, s32 bx, s32 by, s32 cx, s32 cy);

extern struct Mt *g_021469F8;

extern char g_020A7E4C[];

extern u16 tbl_020A08B6[];

extern short FX_SinCosTable_[];

extern struct Block g_021469FC;

extern struct RtcDate g_02146A0C;

extern struct RtcTime g_02146A1C;

/*
 * TU: gf_standard.c.  The allocation site string at 0x020A7E4C reads
 * "gf_standard.c" and this is its only reference in the image, so the
 * Mersenne Twister block (0x0203EF5C onwards) is that translation unit;
 * bg_sys.c starts further down at 0x0203F8F4, whose site string is the
 * "bg_sys.c" at 0x020A7E5C.
 *
 * Constructor for the random-number state: 0xbcc bytes holding mt[624], the
 * generator index (set to 625, "exhausted"), a spare word and the constant
 * 0x9908b0df, then a 0x200-byte buffer at +0x9cc that MATHi_CRC16InitTable
 * initialises.  The allocation tag 49 stays live in r5 afterwards and both
 * later constants are derived from it with a single `add`, which is why
 * neither 625 nor 4129 costs a pool word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Init.c \
 *       --func GF_STANDARD_Init --addr 0x0203EF5C --cc 1.1p1 --arm
 */
void GF_STANDARD_Init(u32 heapId)
{
    g_021469F8 = GFL_HEAP_Alloc(heapId, 0xbcc, 0, g_020A7E4C, 49);
    g_021469F8->mti = 625;
    g_021469F8->mag01[0] = 0;
    g_021469F8->mag01[1] = 0x9908b0df;
    MATHi_CRC16InitTable((struct MATHCRC16Table *)g_021469F8->unk_9cc, 4129);
}

/*
 * memcmp over unsigned bytes.  The count is tested and decremented in one
 * expression (`n-- != 0`), which is what puts the `sub r2, r2, #1` between
 * the `cmp` and the branch at the head and again in the loop's tail.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_CompareBytes.c \
 *       --func GF_STANDARD_CompareBytes --addr 0x0203EFC8 --cc 1.1p1 --arm
 */
s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n)
{
    while (n-- != 0) {
        if (*a != *b) {
            return *a - *b;
        }
        a++;
        b++;
    }
    return 0;
}

/*
 * Byte-counting strlen over an unsigned char string.  The loop is written
 * as an unconditional one with the test and the return inside it, which is
 * why the original has a plain `b` back to the head and a dead `bx lr`
 * after it for the path that falls off the end.
 *
 * EXACT*, not EXACT: the inferred extent runs to 0x0203F034 because the
 * follower at 0x0203F028 has no label.  It is a twelve-byte ARM long-branch
 * veneer (ldr ip, [pc]; bx ip; .word 0x0208CD94), not a byte difference,
 * and wants seeding into layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_GetStringLength.c \
 *       --func GF_STANDARD_GetStringLength --addr 0x0203F004 --cc 1.1p1 --arm
 */
u32 GF_STANDARD_GetStringLength(const u8 *s)
{
    u32 n = 0;

    while (1) {
        if (*s == 0) {
            return n;
        }
        s++;
        n++;
    }
}

int GF_STANDARD_CompareString(const char *s1, const char *s2)
{
    return STD_CompareString(s1, s2);
}

/*
 * Mersenne Twister (MT19937) seeding: 624 words at offset 0 of the block
 * behind 0x021469F8, with the generator index at +0x9c0.  Every step
 * re-reads both the global pointer and the index out of memory, so the
 * index is a real field and not a local; the multiply-accumulate is one
 * `mla` because the index is the addend.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_RandSeed.c \
 *       --func GF_STANDARD_RandSeed --addr 0x0203F034 --cc 1.1p1 --arm
 */
void GF_STANDARD_RandSeed(u32 seed)
{
    g_021469F8->mt[0] = seed;
    for (g_021469F8->mti = 1; g_021469F8->mti < 624;
         g_021469F8->mti++) {
        u32 prev = g_021469F8->mt[g_021469F8->mti - 1];

        g_021469F8->mt[g_021469F8->mti] =
            (prev ^ (prev >> 30)) * 0x6c078965 + g_021469F8->mti;
    }
}

u32 GF_STANDARD_Rand(void)
{
    u32 y;

    if (g_021469F8->mti >= 624) {
        int kk;

        if (g_021469F8->mti == 625) {
            GF_STANDARD_RandSeed(5489);
        }

        for (kk = 0; kk < 227; kk++) {
            y = (g_021469F8->mt[kk] & 0x80000000)
                | (g_021469F8->mt[kk + 1] & 0x7fffffff);
            g_021469F8->mt[kk] = g_021469F8->mt[kk + 397] ^ (y >> 1)
                ^ g_021469F8->mag01[y & 1];
        }

        for (; kk < 623; kk++) {
            y = (g_021469F8->mt[kk] & 0x80000000)
                | (g_021469F8->mt[kk + 1] & 0x7fffffff);
            g_021469F8->mt[kk] = g_021469F8->mt[kk - 227] ^ (y >> 1)
                ^ g_021469F8->mag01[y & 1];
        }

        y = (g_021469F8->mt[623] & 0x80000000)
            | (g_021469F8->mt[0] & 0x7fffffff);
        g_021469F8->mt[623] = g_021469F8->mt[396] ^ (y >> 1)
            ^ g_021469F8->mag01[y & 1];

        g_021469F8->mti = 0;
    }

    y = g_021469F8->mt[g_021469F8->mti++];

    y ^= (y >> 11);
    y ^= (y << 7) & 0x9d2c5680;
    y ^= (y << 15) & 0xefc60000;
    y ^= (y >> 18);

    return y;
}

/*
 * TU: gf_standard.c.
 *
 * Push bytes into the 0x200-byte buffer at +0x9cc of the random-number
 * block.  A length below two is padded out to two by duplicating the first
 * byte through a two-byte stack buffer.  0x9cc is out of reach of a single
 * ARM immediate, so the base is always two `add`s (+0x1cc then +0x800).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_SetupCalc.c \
 *       --func GF_STANDARD_SetupCalc --addr 0x0203F1FC --cc 1.1p1 --arm
 */
u16 GF_STANDARD_SetupCalc(const u8 *src, u32 len)
{
    if (len < 2) {
        u8 pair[2];

        pair[0] = src[0];
        pair[1] = src[0];
        return MATH_CalcCRC16CCITT((struct MATHCRC16Table *)g_021469F8->unk_9cc, pair, 2);
    } else {
        return MATH_CalcCRC16CCITT((struct MATHCRC16Table *)g_021469F8->unk_9cc, (void *)src, len);
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
void GF_STANDARD_CalcHash(struct Lcg64 *out)
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
    out->x = *(unsigned long long *)a;
    out->mul = 0x5D588B656C078965ULL;
    out->add = 0x269EC3;
}

/*
 * Additive byte checksum.  The accumulator is declared before the index, so
 * it takes r3 and the index is rematerialised from it with `mov ip, r3`
 * rather than a second `mov #0`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Checksum.c \
 *       --func GF_STANDARD_Checksum --addr 0x0203F2FC --cc 1.1p1 --arm
 */
u32 GF_STANDARD_Checksum(const u8 *p, u32 len)
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
 * GF_STANDARD_RandLcg has exactly one caller image-wide, this one, so its only
 * route to a witness is its own manifest entry in this same shard; the
 * first `manifest --verify` after adding both files leaves this one at
 * MATCH* and the second promotes it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Shuffle.c \
 *       --func GF_STANDARD_Shuffle --addr 0x0203F328 --cc 1.1p1 --arm
 */
void GF_STANDARD_Shuffle(u16 *p, u32 size, u32 seed)
{
    u32 i;
    u32 n = size >> 1;

    for (i = 0; i < n; i++) {
        p[i] ^= GF_STANDARD_RandLcg(&seed);
    }
}

void GF_STANDARD_ShuffleEx(void *p, unsigned int size, unsigned int seed){ GF_STANDARD_Shuffle(p, size, seed); }

/*
 * The standard 32-bit LCG (multiplier 0x41c64e6d, increment 0x6073) over a
 * caller-supplied seed word, returning the top halfword.  0x6073 is not an
 * ARM rotated immediate, so the increment is two `add`s; the `lsl`/`lsr`
 * pair after the first `lsr` is the u16 return type's truncation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_RandLcg.c \
 *       --func GF_STANDARD_RandLcg --addr 0x0203F388 --cc 1.1p1 --arm
 */
u16 GF_STANDARD_RandLcg(u32 *seed)
{
    u32 v = *seed * 0x41c64e6d + 0x6073;

    *seed = v;
    return (u16)(v >> 16);
}

/*
 * Reset of the 0x48-byte block at 0x021469FC: zero it wholesale, then write
 * its first three words explicitly (the redundant stores are in the source;
 * the memset has already cleared them) and hand it to GF_STANDARD_GetRtc.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Reset.c \
 *       --func GF_STANDARD_Reset --addr 0x0203F3B4 --cc 1.1p1 --arm
 */
void GF_STANDARD_Reset(void)
{
    RTC_Init();
    MI_CpuFill8(&g_021469FC, 0, 0x48);
    g_021469FC.unk_00 = 0;
    g_021469FC.unk_04 = 0;
    g_021469FC.unk_08 = 0;
    GF_STANDARD_GetRtc((struct RtcRequest *)(&g_021469FC));
}

/*
 * TU: gf_standard.c.
 *
 * Per-frame tick on the block at 0x021469FC: while +0x04 is clear, count
 * frames in +0x08 and every eleventh one reset the counter and run
 * GF_STANDARD_GetRtc.  The `ble` says +0x08 is signed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Setup.c \
 *       --func GF_STANDARD_Setup --addr 0x0203F3F0 --cc 1.1p1 --arm
 */
void GF_STANDARD_Setup(void)
{
    if (g_021469FC.unk_04 != 0) {
        return;
    }
    g_021469FC.unk_08++;
    if (g_021469FC.unk_08 <= 10) {
        return;
    }
    g_021469FC.unk_08 = 0;
    GF_STANDARD_GetRtc((struct RtcRequest *)(&g_021469FC));
}

/*
 * TU: gf_standard.c.
 *
 * Completion callback for the asynchronous RTC read started by
 * GF_STANDARD_GetRtc: publish the result code, mark the block busy, promote the
 * staging date and time at +0x2c/+0x3c into the live copies at +0x10/+0x20,
 * then clear the busy flag.  Both promotions are whole-structure
 * assignments, so each is one inlined ldm/stm pair.
 *
 * Its address reaches the image only as the pool word at 0x0203F498 inside
 * GF_STANDARD_GetRtc, never as a branch target, so this file's manifest entry is
 * the only thing that can attest that relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_Task.c \
 *       --func GF_STANDARD_Task --addr 0x0203F42C --cc 1.1p1 --arm
 */
void GF_STANDARD_Task(u32 result, struct RtcRequest *req)
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
 * +0x2c/+0x3c, with GF_STANDARD_Task as the completion callback and the block
 * itself as its argument.  The busy flag at +0x04 is raised before the call
 * and the request's return code is parked in +0x0c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_GetRtc.c \
 *       --func GF_STANDARD_GetRtc --addr 0x0203F46C --cc 1.1p1 --arm
 */
void GF_STANDARD_GetRtc(struct RtcRequest *req)
{
    req->unk_04 = 1;
    req->result = RTC_GetDateTimeAsync(&req->stagedDate, &req->stagedTime,
                                GF_STANDARD_Task, req);
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
 *   python tools/match.py one --src src/matched/GF_STANDARD_CopyCachedRtc.c \
 *       --func GF_STANDARD_CopyCachedRtc --addr 0x0203F49C --cc 1.1p1 --arm
 */
void GF_STANDARD_CopyCachedRtc(struct RtcDate *date, struct RtcTime *time)
{
    *date = g_02146A0C;
    *time = g_02146A1C;
}

/*
 * TU: gf_standard.c.  Copy the cached RTC time out; three words, so one
 * ldm/stm pair and no frame at all.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_SetField00.c \
 *       --func GF_STANDARD_SetField00 --addr 0x0203F4CC --cc 1.1p1 --arm
 */
void GF_STANDARD_SetField00(struct RtcTime *time)
{
    *time = g_02146A1C;
}

/*
 * TU: gf_standard.c.  Copy the cached RTC date out; four words, one ldm/stm
 * pair, no frame.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_SetField00_F4E4.c \
 *       --func GF_STANDARD_SetField00_F4E4 --addr 0x0203F4E4 --cc 1.1p1 --arm
 */
void GF_STANDARD_SetField00_F4E4(struct RtcDate *date)
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
 *   python tools/match.py one --src src/matched/GF_STANDARD_GetTime.c \
 *       --func GF_STANDARD_GetTime --addr 0x0203F4FC --cc 1.1p1 --arm
 */
u32 GF_STANDARD_GetTime(void)
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
 *   python tools/match.py one --src src/matched/GF_STANDARD_SetupRtc.c \
 *       --func GF_STANDARD_SetupRtc --addr 0x0203F524 --cc 1.1p1 --arm
 */
void GF_STANDARD_SetupRtc(void)
{
    RTC_ConvertDateTimeToSecond((struct RTCDate *)(&g_02146A0C), (struct RTCTime *)(&g_02146A1C));
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
 * stack temp with month and day forced to 1 and runs RTC_ConvertDateToDay over
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
 *   python tools/match.py one --src src/pending/GF_STANDARD_SetupRtc_F540.c \
 *       --func GF_STANDARD_SetupRtc_F540 --addr 0x0203F540 --cc 1.1p1 --arm
 */
s32 GF_STANDARD_SetupRtc_F540(struct RtcDateSigned *d)
{
    struct RtcDateSigned t;
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
    RTC_ConvertDateToDay((struct RTCDate *)(&t));
    RTC_ConvertDateToDay((struct RTCDate *)d);
    return n;
}

/*
 * Fixed-point sine lookup without the mod: angles of 360 or more return 0; otherwise the same table index as GF_STANDARD_Get_F684 (4096-entry table at 0x020A1B38, even halfword).
 */
int GF_STANDARD_Get_F5FC(u32 x)
{
    if (x >= 360) {
        return 0;
    }
    return FX_SinCosTable_[2 * ((((s32)x * 0xFFFF) / 360) >> 4)];
}

/*
 * Twin of GF_STANDARD_Get_F5FC at table index 2 * i + 1 (cosine entry); angles of 360 or more return 0.
 */
short GF_STANDARD_SinDeg(u32 x)
{
    if (x >= 360) {
        return 0;
    }
    return FX_SinCosTable_[2 * ((((s32)x * 0xFFFF) / 360) >> 4) + 1];
}

/*
 * Fixed-point sine lookup: 4096-entry table at 0x020A1B38 (a flat signed
 * halfword array of interleaved pairs), indexed by (x mod 360) scaled to
 * 0xFFFF with the quotient taken against 360 again and shifted right by 4.
 * GF_STANDARD_Sin is the identical twin at index `2 * i + 1`.
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
short GF_STANDARD_Get_F684(unsigned short x)
{
    return FX_SinCosTable_[2 * ((((x % 360) * 0xFFFF) / 360) >> 4)];
}

/*
 * The odd-halfword twin of GF_STANDARD_Get_F684: same signed `x % 360`, same
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
short GF_STANDARD_Sin(s32 x)
{
    return FX_SinCosTable_[2 * ((((x % 360) * 0xFFFF) / 360) >> 4) + 1];
}

/*
 * Unlabelled ARM leaf (no lr save) that scales x by 0xFFFF and divides by
 * 360: floor(x * 65535 / 360) for x < 360, else 0.  The unsigned guard
 * gives `movhs`, and mwcc emits the signed /360 magic (0xB60B60B7) because
 * the guard proves the product positive.  It is the witness that unblocks
 * the thumb caller BEACON_DETAIL_CalcDistance.
 */
u16 GF_STANDARD_DegToAngle(int x)
{
    if ((u32)x >= 0x168)
        return 0;
    return (u16)(x * 0xFFFF / 0x168);
}

/*
 * Blocked at MATCH on the `label`/`matched` classes: every concrete byte of
 * the body reproduces, but the PC24 at +0x18 to GF_STANDARD_SetupCalc_F7C4 has one
 * branch reference image-wide, this call, so the site has no witness outside
 * 0203F768..0203F7C4.  Filing 0x0203F7C4 as an EXACT manifest entry promotes
 * this file with no change to the C.
 *
 * The six-argument forwarder: the two stacked arguments are copied down into
 * the outgoing frame and the seventh is the divisor, a 20.12 fixed-point
 * product of itself with 0x323d rounded up by 0x800 and shifted down twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/GF_STANDARD_CalcAngle.c \
 *       --func GF_STANDARD_CalcAngle --addr 0x0203F768 --cc 1.1p1 --arm
 */
int GF_STANDARD_CalcAngle(int a0, int a1, int a2, int a3, int a4, int a5, int a6)
{
    int v = GF_STANDARD_SetupCalc_F7C4(a0, a1, a2, a3, a4, a5);
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
 * of docs/notes/GF_STANDARD_SetupCalc_F7C4.c.txt by one change: the value tested for the
 * sign is the SUM OF ALL THREE COMPONENTS of f = (0, 0, cross_z),
 *     cross = f.x + f.y + f.z;
 * not `f.z + a.z`.  The image's `add r2, r7, #0` is f.x + f.y (the zero
 * forwarded from the two stores), started early in the gap between the two
 * FX_Mul-style products, which is what interleaves the second product's
 * loads with the first one's normalisation.  The two `static inline`
 * helpers from the note are still load-bearing.
 */
s32 GF_STANDARD_SetupCalc_F7C4(s32 ax, s32 ay, s32 bx, s32 by, s32 cx, s32 cy)
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
