/*
 * file:     net_state_p29.c
 * unit:     yes
 * function: func_0203A85C, func_0203A958, func_0203AA94, func_0203ABC0, func_0203ACAC, func_0203AD74, func_0203AD8C, func_0203AE20, func_0203AEEC, func_0203AF40
 * address:  0x0203A85C
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
 *   func_020399A8  0x020399A8  arm
 *   func_0203A770  0x0203A770  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   d_021469D8     0x021469D8  data
 *   g_021469D8     0x021469D8  data
 *   func_0203A81C  0x0203A81C  arm
 *   func_02034714  0x02034714  arm
 *   sNet3730       0x020A7AF8  data
 *   sNet3733       0x020A7B20  data
 *   sNet3734       0x020A7B50  data
 *   g_020A7AF8     0x020A7AF8  data
 *   g_020A7B78     0x020A7B78  data
 *   func_0203D798  0x0203D798  arm
 *   func_020395EC  0x020395EC  arm
 *   func_02038C18  0x02038C18  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   g_021469DC     0x021469DC  data
 *   g_020A7BA8     0x020A7BA8  data
 *   g_020A7BB4     0x020A7BB4  data
 *   func_02030734  0x02030734  arm
 *   func_0203A494  0x0203A494  arm
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
 *   func_02037D78  0x02037D78  arm
 *   func_0203D650  0x0203D650  arm
 *   unk_0203C00C   0x0203C00C  arm
 */
#include "../../matched/include/Obj01629.h"
#include "../../matched/include/Obj01823.h"
#include "../../matched/include/Obj04116.h"

struct Entry;
struct RTCDate;
struct RTCTime;
struct NetState;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
    u16 unk0C;
    u16 unk0E;
    u16 unk10;
    u8  unk12;
} Ent0203A85C;

typedef struct {
    u8          unk000[0xb8];
    Ent0203A85C ent[9];
} Obj0203A85C;

typedef struct {
    u8 lo : 4;
    u8 hi : 4;
} Status;

struct NetState {
    void *unk0;
    void *unk4;
    void *unk8;
    unsigned char pad[0x46 - 0xC];
    u16 unk46;
};

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct Date { u32 year; u32 mon; u32 day; u32 wday; };

struct Time { u32 hour; u32 min; u32 sec; };

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

extern void func_0203A770(u32 a, u32 b, int c, u32 d, u32 e, u32 f);
extern struct Entry *func_020399A8(void);
extern void MI_CpuCopy8(void *dst, const void *src, u32 size);
extern u32 func_0203A81C(u32 a0, u32 a1, u32 a2);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void *func_0203D798(void);
extern int func_020395EC(struct Entry *a);
extern int func_02038C18(u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void  func_0203A494(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
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
extern void func_02037D78(void);
extern u32  func_0203D650(void);
void func_0203A85C(int a0, u32 a1, void *a2, int a3, volatile int a4);
void func_0203A958(int a0, int a1, const u8 *a2, int a3, int a4);
u32 func_0203AA94(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
u32 func_0203ABC0(void);
void func_0203ACAC(void);
void func_0203AD74(struct NetState *s, void *p, u16 v);
void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
void func_0203AD8C(u32 a0);
void func_0203AE20(MATHRandContext64 *o);
void func_0203AEEC(u8 *p);
void func_0203AF40(struct Rec *p);
extern Obj0203A85C *d_021469D8;
extern u8 *g_021469D8;
extern char sNet3730[];
extern char sNet3733[];
extern char sNet3734[];
extern char  g_020A7AF8[];
extern char  g_020A7B78[];
extern u8  *g_021469DC;
extern char g_020A7BA8[];
extern char g_020A7BB4[];
extern u32 g_02FFFC3C;




/*
 * One slot of a network table: index 0xff aliases to slot 8, the incoming
 * tag must match func_020399A8(), and the entry is swept copy-then-count.
 * The global pointer at 0x021469D8 is re-read after every call, so the C
 * dereferences it afresh in each statement rather than keeping a local.
 *
 * The fifth parameter is volatile: every use re-reads its incoming stack
 * slot (ldr r1,[sp,#0x20] after the tag call, ldr r0,[sp,#0x20] again for
 * func_0203A770) instead of living in a callee-saved register, which is what
 * keeps the saved set at r4-r8 rather than adding sb.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A85C.c \
 *       --func func_0203A85C --addr 0x0203A85C --cc 1.1p1
 */
void func_0203A85C(int a0, u32 a1, void *a2, int a3, volatile int a4)
{
    int idx = a0;

    if (a0 == 0xff) {
        idx = 8;
    }
    if (a4 != (u32)func_020399A8()) {
        return;
    }
    if (d_021469D8->ent[idx].unk12 == 0) {
        return;
    }
    if (d_021469D8->ent[idx].unk04 != 0) {
        MI_CpuCopy8(a2,
                    (void *)(d_021469D8->ent[idx].unk04
                             + d_021469D8->ent[idx].unk0C
                                   * d_021469D8->ent[idx].unk0A),
                    a1);
    }
    d_021469D8->ent[idx].unk0C++;
    if (d_021469D8->ent[idx].unk0C != d_021469D8->ent[idx].unk0E) {
        return;
    }
    if (d_021469D8->ent[idx].unk04 != 0) {
        func_0203A770(a0, d_021469D8->ent[idx].unk10,
                      d_021469D8->ent[idx].unk08, d_021469D8->ent[idx].unk00,
                      d_021469D8->ent[idx].unk04, a4);
    }
    d_021469D8->ent[idx].unk12 = 0;
}



/*
 * net_command.c: register the command record a2 in slot a0 (0xff -> 8) of
 * the 0x14-stride table at g_021469D8 + 0xb8, asserting the slot was free
 * (line 0x1ff) and that func_0203A81C accepted it (line 0x203).
 *
 * Closed from docs/notes/pkt_0203A958.c.txt (39 bytes out) by the same
 * lever as func_0203A020 in net_handle.c: the record parameter is
 * `const u8 *a2`, which lets the `*(u32 *)a2` load hoist above the in-use
 * strb and the five halfword copies interleave as the image has them.
 * The permuter's old `tmp` local for the +6 halfword is then unneeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A958.c  *       --func func_0203A958 --addr 0x0203A958 --arm --cc 1.1p1
 */
void func_0203A958(int a0, int a1, const u8 *a2, int a3, int a4)
{
  int i;
  u16 v0, v2, v8, v6;
  i = a0;
  if (a0 == 0xff)
    i = 8;
  if (a4 != (int)func_020399A8())
    return;
  if (func_0203A81C(*((u16 *) (a2 + 6)), a0, *((u32 *) a2)) == 0)
    return;
  if ((*((u8 *) ((g_021469D8 + (i * 0x14)) + 0xca))) != 0)
    func_02034714(sNet3730, 0x1ff, sNet3733);
  *((u8 *) ((g_021469D8 + (i * 0x14)) + 0xca)) = 1;
  {
    u32 w = *((u32 *) a2);
    *((u32 *) ((g_021469D8 + (i * 0x14)) + 0xb8)) = w;
    *((u32 *) ((g_021469D8 + (i * 0x14)) + 0xbc)) = func_0203A81C(*((u16 *) (a2 + 6)), a0, w);
  }
  if ((*((u32 *) ((g_021469D8 + (i * 0x14)) + 0xbc))) == 0)
    func_02034714(sNet3730, 0x203, sNet3734);
  v0 = *((u16 *) (a2 + 6));
  v2 = *((u16 *) (a2 + 8));
  v8 = *((u16 *) (a2 + 0xa));
  v6 = *((u16 *) (a2 + 4));
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc0)) = v0;
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc2)) = v2;
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc8)) = v8;
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc6)) = v6;
  *((u16 *) ((g_021469D8 + (i * 0x14)) + 0xc4)) = 0;
}




/*
 * The net_command.c command-queue trio, 0x0203AA94..0x0203AD6C, folded into
 * one translation unit: the enqueue (func_0203AA94), the header pump
 * (func_0203ABC0) and the chunk pump (func_0203ACAC).  All three walk the
 * same five 0x18-byte slot table at g_021469D8 and share the 4-bit status
 * nibble pair at record +0x17 / table +0x57.  Filed as a unit because the
 * three are individually EXACT and reproduce the range with its pools.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AA94.c \
 *       --addr 0x0203AA94 --arm
 */
u32 func_0203AA94(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    u8 *cfg;
    u8 *t;
    u8 *st57;
    u8 *s;
    int i;
    int mtu;
    Status *sc;
    Status *st;

    cfg = func_0203D798();
    t = g_021469D8;
    st57 = t + 0x57;
    for (i = 0; i < 5; i++) {
        sc = (Status *)&st57[i * 0x18];
        if (sc->hi)
            continue;
        if (sc->lo == 0)
            break;
    }
    if (i == 5)
        return 0;

    s = t + 0x40 + i * 0x18;
    ((struct Obj01629 *)s)->f4 = a3;
    mtu = cfg[0x61] - 0xc;
    if (mtu <= 0)
        func_02034714(g_020A7AF8, 0x22b, g_020A7B78);
    ((struct Obj01629 *)s)->fE = cfg[0x61] - 0xc;
    ((struct Obj01629 *)s)->f14 = a3 / ((struct Obj01629 *)s)->fE;
    ((struct Obj01629 *)s)->f10 = a3 % ((struct Obj01629 *)s)->fE;
    if (((struct Obj01629 *)s)->f10 != 0)
        ((struct Obj01629 *)s)->f14 = ((struct Obj01629 *)s)->f14 + 1;
    ((struct Obj01629 *)s)->f12 = 0;
    ((struct Obj01629 *)s)->fC = a2;
    s[0x16] = a1;
    ((struct Obj01629 *)s)->f8 = a4;
    ((struct Obj01629 *)s)->f0 = func_020395EC((void *)a0);
    st = (Status *)(s + 0x17);
    st->hi = 1;
    return st->hi;
}




u32 func_0203ABC0(void)
{
    u16 hdr[6];
    u8 *s;
    Status *st;
    u8 *t;
    int i;

    t = g_021469D8 + 0x40;
    for (i = 0; i < 5; i++) {
        s = t + i * 0x18;
        st = (Status *)(s + 0x17);
        if (st->hi) {
            hdr[2] = ((struct Obj04116 *)s)->f14;
            *(u32 *)&hdr[0] = ((struct Obj04116 *)s)->f4;
            hdr[3] = ((struct Obj04116 *)s)->fC;
            hdr[4] = ((struct Obj04116 *)s)->fE;
            hdr[5] = s[0x16];
            st->lo = func_02038C18(0xd, (u32)hdr, 0xc, 1,
                                   ((struct Obj04116 *)s)->f0, s[0x16], 0);
            st->hi = 1 - st->lo;
            return st->lo;
        }
    }
    return 0;
}




void func_0203ACAC(void)
{
    int i;
    u32 n;
    u32 c;
    u32 base;
    u8 *t;
    u8 *s;

    t = g_021469D8;
    for (i = 0; i < 5; i++) {
        if ((u32)(t[i * 0x18 + 0x57] << 0x1c) >> 0x1c) {
            s = t + 0x40 + i * 0x18;
            c = ((struct Obj01823 *)s)->f12;
            n = ((struct Obj01823 *)s)->fE;
            base = ((struct Obj01823 *)s)->f8 + n * c;
            if (c + 1 == ((struct Obj01823 *)s)->f14)
                n = ((struct Obj01823 *)s)->f10;
            if (func_02038C18(0xc, base, n, 1,
                              ((struct Obj01823 *)s)->f0, s[0x16], 1) != 0)
                ((struct Obj01823 *)s)->f12 = ((struct Obj01823 *)s)->f12 + 1;
            if (((struct Obj01823 *)s)->f12 == ((struct Obj01823 *)s)->f14)
                s[0x17] = s[0x17] & ~0xf;
            return;
        }
    }
    func_0203ABC0();
}



/*
 * Setter and its tail-call export in net_state.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AD74.c \
 *       --addr 0x0203AD74 --arm --cc 1.1p1
 */
void func_0203AD74(struct NetState *s, void *p, u16 v)
{
    s->unk8 = p;
    s->unk46 = v;
}


void func_0203AD80(struct NetState *s, void *p, u16 v, int line)
{
    func_0203AD74(s, p, v);
}



/*
 * One-shot constructor: the singleton must still be NULL (otherwise
 * func_02034714(__FILE__, 0xb8, __FILE__)), 0x64 bytes are allocated with
 * the debug allocator, a halfword 0x32 and a byte 1 are set at +0x46 and
 * +0x4c, the embedded object at +0xc is initialised, and the 5-argument
 * delegate func_0203A494 is called with four zeros.
 *
 * The fields are written through the global every time -- the second and
 * third uses reload `[r1]` (`ldr r0, [r1]` twice after the store) while the
 * first reuses the allocator's return value in r0 -- which is what
 * `g_021469DC->f46 = ...` spells and what a local pointer would not.
 *
 * Parked at MATCH, blocking class: label.  The only unresolved relocation is
 * the call at +0x68
 *   +0068 PC24 func_0203AE20 -> unresolved: 0203AE20 (arm, from header) has
 *                                            no witness outside
 *                                            0203AD8C..0203AE20
 * -- the callee 0x0203AE20 sits at the very end of this function's listing
 * extent and this call is its only branch anywhere in the image, so the
 * `label` class has no outside witness.  It graduates for free, with no
 * change to this C, as soon as src/matched/ holds a func_0203AE20 entry:
 * the `matched` class then witnesses the site.  func_0203AE20 itself is
 * chain-capped on 0x0203F0A8 (see docs/notes/func_0203F0A8.c.txt), which is
 * why the pair is parked rather than finished here.
 */
void func_0203AD8C(u32 a0)
{
    if (g_021469DC != 0) {
        func_02034714(g_020A7BA8, 0xb8, g_020A7BB4);
    }
    g_021469DC = (u8 *)func_02030734(a0, 0x64, 1, g_020A7BA8, 0xb9);
    *(u16 *)(g_021469DC + 0x46) = 0x32;
    *(u8 *)(g_021469DC + 0x4c) = 1;
    func_0203AE20((MATHRandContext64 *)(g_021469DC + 0xc));
    func_0203A494(0, 0, 0, 0, a0);
}



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
