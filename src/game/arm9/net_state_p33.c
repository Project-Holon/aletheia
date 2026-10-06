/*
 * file:     net_state_p33.c
 * unit:     yes
 * function: func_0203AE20, func_0203AEEC, func_0203AF40
 * address:  0x0203AE20
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_GetMacAddress  0x02087C6C  arm
 *   func_020889C0     0x020889C0  arm
 *   func_0203F034     0x0203F034  arm
 *   func_0203F0A8     0x0203F0A8  arm
 *   g_02FFFC3C        0x02FFFC3C  data
 *   func_0203D788  0x0203D788  arm
 *   func_0203A53C  0x0203A53C  arm
 *   func_020370C8  0x020370C8  arm
 *   func_02037B08  0x02037B08  arm
 *   func_020307B0  0x020307B0  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02037D78  0x02037D78  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0203AD80  0x0203AD80  arm
 *   unk_0203C00C   0x0203C00C  arm
 *   g_021469DC     0x021469DC  data
 */
struct RTCDate;
struct RTCTime;
struct NetState;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct Date { u32 year; u32 mon; u32 day; u32 wday; };

struct Time { u32 hour; u32 min; u32 sec; };

typedef unsigned short u16;

struct Vt {
    u8  pad_00[4];
    void (*f04)(u16 key, void *obj, u32 zero, u32 arg);
};

struct Obj {
    u8         pad_00[0x340];
    struct Vt *f340;
    u8         pad_344[8];
    u32        f34c;
};

struct Cur {
    u8  pad_00[0x56];
    u16 f56;
    u8  pad_58[0xd];
    u8  f65;
};

struct Rec {
    u8  pad_00[0x2c];
    void (*f2c)(u32 a);
};

extern void OS_GetMacAddress(u8 *p);
extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);
extern void func_0203F034(u32 seed);
extern u32 func_0203F0A8(void);
extern void *func_0203D788(void);
extern void  func_0203A53C(void);
extern void  func_020370C8(void);
extern void  func_02037B08(void);
extern u32 func_020307B0(void *p);
extern void unk_0203C00C(void);
extern void *func_0203D798(void);
extern void func_02037D78(void);
extern u32  func_0203D650(void);
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
void func_0203AE20(MATHRandContext64 *o);
void func_0203AEEC(u8 *p);
extern u32 g_02FFFC3C;
extern u32  g_021469DC;


static inline void MATH_InitRand64(MATHRandContext64 *context, u64 seed)
{
    context->x = seed;
    context->mul = 0x5d588b656c078965ULL;
    context->add = 0x269ec3ULL;
}


/*
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203AE20.c  *       --func func_0203AE20 --addr 0x0203AE20 --cc 1.1p1 --arm
 *
 * net_state.c RNG seeder.  Mixes the MAC with the RTC date/time and the
 * system word 0x02FFFC3C, seeds func_0203F034, draws two words into one
 * u64 seed, and initialises a NitroSDK MATHRandContext64 with the SDK's
 * own MATH_InitRand64 inline (x = seed, mul 0x5D588B656C078965, add
 * 0x269EC3).  Wave 14 closed the 8-byte tail tie of
 * docs/notes/pkt_0203AE20.c.txt: +0x08..+0x14 are two u64 members, not
 * four u32 words, so the constants are stored as u64 pairs.
 */
void func_0203AE20(MATHRandContext64 *o)
{
  struct Date d;
  struct Time t;
  u8 mac[6];
  u32 seed;
  OS_GetMacAddress(mac);
  func_020889C0((struct RTCDate *)(&d), (struct RTCTime *)(&t));
  seed = ((d.year + ((d.day * (d.mon << 8)) << 16)) + (t.hour << 16)) + ((t.min + t.sec) << 24);
  seed = seed + (mac[5] + ((mac[3] << 16) + (mac[4] << 8)));
  seed = seed + g_02FFFC3C;
  func_0203F034(seed);
  {
    u32 hi = func_0203F0A8();
    MATH_InitRand64(o, (((u64) hi) << 32) + func_0203F0A8());
  }
}


/*
 * Shuts the network down when the transport's +0x74 virtual answers non-zero:
 * tears the tables down, saves the completion callback out of +0x28, drops
 * the context and finally calls the saved callback.  The callback load is
 * scheduled before func_020307B0 rather than after it and the context is
 * zeroed after that call too - the store-landing-after-the-next-call shape,
 * so the C keeps the callback in a local across the call.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203AEEC.c \
 *       --func func_0203AEEC --addr 0x0203AEEC --cc 1.1p1 --arm
 */
void func_0203AEEC(u8 *p)
{
    void (*f)(void);

    if (((u32 (*)(void))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x74))() == 0)
        return;
    func_0203A53C();
    func_020370C8();
    func_02037B08();
    f = (void (*)(void))*(u32 *)(*(u32 *)((char *)(0x21469DC)) + 0x28);
    func_020307B0((void *)*(u32 *)((char *)(0x21469DC)));
    *(u32 *)((char *)(0x21469DC)) = 0;
    if (f != 0)
        f();
}


/*
 * Closes docs/notes/pkt_0203AF40.c.txt, which parked this at "DIFF, 10
 * concrete bytes" with an r4/r5 end-to-end swap and additionally predicted a
 * MATCH ceiling.  BOTH of those conclusions were wrong.
 *
 * 1. The r4/r5 swap was an artefact of that attempt's declaration order, not
 *    the real residue.  Declaring the two call results in source order
 *    (`s = func_0203D788()` then `c = func_0203D798()`) puts them in r5/r0
 *    exactly as the image does and the swap never appears.  That left a
 *    2-byte residue at +0x54/+0x58, not 10.
 *
 * 2. THE 2-BYTE RESIDUE: the image reloads the +0x2C callback into r1 and
 *    does `blx r1`, where the obvious C reloads into r0.  The tell is the
 *    `bl func_0203D650` immediately before it whose result looks discarded.
 *    It is not discarded -- it is the callback's ARGUMENT.  Spelling the
 *    field `void (*f2c)(u32)` and writing `p->f2c(func_0203D650())` pins r0
 *    to the argument, so the function pointer has to land in r1.  EXACT.
 *    This is the same shape src/pending/func_0203B52C.c documents for its
 *    own callback ("takes func_0203D650's return value in r0, which is why
 *    the function pointer is loaded into r1") -- a family idiom, not a
 *    one-off.
 *
 * 3. The note's MATCH-ceiling claim ("0x0203C00C is a data address with no
 *    outside witness") is also wrong: 0x0203C00C has TWENTY pool words
 *    image-wide (layout/data_objects.txt line 207 lists six plus twelve
 *    more) and resolves `literal x20, e.g. 0203B5CC`.  All 7 relocation
 *    sites resolve and the file is EXACT, not MATCH.
 *
 * The permuter was run before the hand fix and found nothing: --mode hill
 * --budget 800 (120 singles tried) and --mode anneal --budget 900 (900
 * compiles in 84s) both stayed flat at asm=10 bytes-out=2.  The lever is a
 * change to a function-pointer's SIGNATURE (arity), which is outside the
 * mutation table -- the same class of miss the permuter.md field reports
 * record for `cnt = *p++` and `int weight`.
 */
void func_0203AF40(struct Rec *p)
{
    struct Obj *s = func_0203D788();
    struct Cur *c = func_0203D798();

    if (c->f65 != 1 && c->f65 != 2)
        s->f340->f04(c->f56, s, 0, s->f34c);
    func_02037D78();
    if (p->f2c != 0) {
        p->f2c(func_0203D650());
        p->f2c = 0;
    }
    func_0203AD80((struct NetState *)g_021469DC, (void *)unk_0203C00C, 0, 0x12f);
}
