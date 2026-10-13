/*
 * file:     net_state.c
 * unit:     yes
 * function: func_0203AD74, func_0203AD80, func_0203AD8C, func_0203AE20, func_0203AEEC, func_0203AF40, func_0203AFCC, func_0203B018, func_0203B01C, func_0203B038, func_0203B084, func_0203B0C4, func_0203B16C, func_0203B170, func_0203B1B0, func_0203B1D8, func_0203B224, func_0203B228, func_0203B22C, func_0203B258, func_0203B2A8, func_0203B2D0, func_0203B2FC, func_0203B344, func_0203B390, func_0203B448, func_0203B48C, func_0203B4DC, func_0203B52C, func_0203B5D4, func_0203B688, func_0203B6B4, func_0203B6EC, func_0203B758, func_0203B794, func_0203B7F8, func_0203B868, func_0203B90C, func_0203B950, func_0203B9D4, func_0203BA98, func_0203BBB0, func_0203BC58, func_0203BCE0, func_0203BD30, func_0203BDEC, func_0203BE5C, func_0203BEAC, func_0203BEC8, func_0203BF4C, func_0203BF9C, func_0203BFF0, func_0203C00C, func_0203C010, func_0203C044, func_0203C05C, func_0203C060, func_0203C064, func_0203C068, func_0203C0B4, func_0203C0DC, func_0203C0F4, func_0203C238, func_0203C2B0, func_0203C304, func_0203C35C, func_0203C3B4, func_0203C3EC, func_0203C464, func_0203C494, func_0203C554, func_0203C5C8, func_0203C5EC, func_0203C600, func_0203C628, func_0203C65C, func_0203C710, func_0203C774, func_0203C7E0, func_0203C864, func_0203C8A8, func_0203C8E8, func_0203C900, func_0203C934, func_0203C938, func_0203C968, func_0203C990, func_0203C9AC, func_0203CA04, func_0203CA98, func_0203CADC, func_0203CB00
 * address:  0x0203AD74
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from net_state.c at 0x0203AD74 (__FILE__ anchor boundary).
 *
 * symbols:
 *   func_02030734            0x02030734  arm
 *   MI_CpuFill8              0x02082BCC  arm
 *   func_02039548            0x02039548  arm
 *   func_02034714            0x02034714  arm
 *   MI_CpuCopy8              0x02082D44  arm
 *   func_020307B0            0x020307B0  arm
 *   func_02039338            0x02039338  arm
 *   func_020393A8            0x020393A8  arm
 *   func_020393D0            0x020393D0  arm
 *   func_020399A8            0x020399A8  arm
 *   func_02039594            0x02039594  arm
 *   func_0203996C            0x0203996C  arm
 *   _pNetState               0x021469DC  data
 *   func_020395E0            0x020395E0  arm
 *   OS_GetMacAddress         0x02087C6C  arm
 *   _FileName                0x020A7BA8  data
 *   _AssertNetStateNull      0x020A7BB4  data
 *   func_020889C0            0x020889C0  arm
 *   func_0203F034            0x0203F034  arm
 *   func_0203F0A8            0x0203F0A8  arm
 *   _VBlankCount             0x02FFFC3C  data
 *   func_02034F84            0x02034F84  arm
 *   _AssertMacAlign          0x020A7BC8  data
 *   func_02039578            0x02039578  arm
 *   func_02039560            0x02039560  arm
 *   _AssertNetTypeWifi       0x020A7BEC  data
 *   _AssertNetState          0x020A7C70  data
 *   _AssertWifiBattleError   0x020A7C7C  data
 *   func_020370C8            0x020370C8  arm
 *   func_0203CEAC            0x0203CEAC  arm
 *   func_0203D3A8            0x0203D3A8  arm
 *   func_0203D650            0x0203D650  arm
 *   func_0203D700            0x0203D700  arm
 *   func_0203D788            0x0203D788  arm
 *   func_0203D798            0x0203D798  arm
 *   func_0203DA4C            0x0203DA4C  arm
 */

struct NetStateWork;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

#include "net_types.h"
typedef signed int     s32;

typedef signed char   s8;

typedef unsigned long long u64;

typedef struct {
    u64 x;
    u64 mul;
    u64 add;
} MATHRandContext64;

struct NetStateWork {
    u32  pad00[2];
    void (*state)(struct NetStateWork *s);
    MATHRandContext64 random;
    u32  pad24;
    void (*exitCallback)(void);
    void (*initCallback)(u32 a);
    u32  errorInfo[4];
    u8   aMacAddress[6];
    u16  timer;
    s8   loginTarget;
    u8   pad49;
    u8   disconnectFinal;
    u8   matchDisconnect;
    u8   parentRetry;
    u8   errorMode;
    u8   wifiErrorCode;
    u8   autoExit;
    u8   loginOption;
    u8   exitRequested;
    u8   pad52;
    u8   changeoverHasMac;
    u8   pad54[2];
    u8   changeoverMode;
    u8   changeoverMac[6];
    u8   pad5D[7];
};

struct RTCDate { u32 year; u32 month; u32 day; u32 week; };

struct RTCTime { u32 hour; u32 minute; u32 second; };

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern void  MI_CpuFill8(void *dst, u8 val, u32 size);

extern void func_02039548(void);

extern void func_02034714(const char *expr, u32 line, const char *file);

extern void MI_CpuCopy8(const void *src, void *dst, u32 size);

extern u32 func_020307B0(void *p);

extern u16 func_02039338(void);

extern int   func_020393A8(void);

extern int  func_020393D0(void);

extern GFLNetHandle *func_020399A8(void);

extern int    func_02039594(void);

extern GFLNetHandle *func_0203996C(s32 idx);

extern int func_020395E0(int slot);

extern void OS_GetMacAddress(u8 *);

extern int func_020889C0(struct RTCDate *date, struct RTCTime *time);

extern void func_0203F034(u32 seed);

extern u32 func_0203F0A8(void);

extern void func_0203C00C(void);

extern void func_02034F84(u32 a);

extern void func_020394DC(u8 v);

extern int func_020351A0(u32 v);

extern void func_0203516C(u32 a);

extern void func_02039578(void);

extern void func_02039560(void);

void func_020370C8(void);

int func_02037288(u32 a0, u32 heap, u32 c);

int func_02037700(u32 a0, u32 a1);

u32 func_0203778C(u32 p);

u32 func_020377B8(u8 arg0);

u32 func_02037894(u8 a0, u16 a1, u32 a2, u32 a3);

u32 func_02037928(u32 a0, u16 a1);

int func_020379C8(u32 p);

u32 func_02037A6C(u32 a0, u32 a1, u16 a2, u32 a3);

void func_02037B08(void);

void func_02037D78(void);

int func_020392EC(void);

u16 func_02039338(void);

int func_020393A8(void);

int func_020393D0(void);

void func_020394DC(u8 v);

void func_02039548(void);

void func_02039560(void);

void func_02039578(void);

int func_02039594(void);

int func_020395E0(int slot);

void func_02039834(GFLNetSession *unused);

void func_020398B4(GFLNetSession *unused);

GFLNetHandle *func_0203996C(s32 idx);

GFLNetHandle *func_020399A8(void);

u32 func_020399B8(GFLNetHandle *handle);

int func_020399EC(void);

int func_02039ACC(void);

void func_0203A494(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);

void func_0203A53C(void);

void func_0203AD74(struct NetStateWork *work, void *state, u32 timer);

void func_0203AD80(struct NetStateWork *work, void *state, u32 timer, int line);

void func_0203AD8C(u32 heapId);

void func_0203AE20(MATHRandContext64 *context);

void func_0203AEEC(struct NetStateWork *work);

void func_0203AF40(struct NetStateWork *work);

void func_0203AFCC(void *heapId, u32 initCallback);

void func_0203B018(void);

void func_0203B01C(void);

void func_0203B038(struct NetStateWork *work);

void func_0203B084(void);

void func_0203B0C4(int mac, int anyParent);

void func_0203B16C(void);

void func_0203B170(void);

void func_0203B1B0(void);

u32 func_0203B1D8(void);

void func_0203B224(void);

void func_0203B228(void);

int func_0203B22C(void);

void func_0203B258(void);

void func_0203B2A8(int heapId);

void func_0203B2D0(u32 unused);

u32 func_0203B2FC(struct NetStateWork *work);

u32 func_0203B344(struct NetStateWork *work);

void func_0203B390(struct NetStateWork *work);

void func_0203B448(void);

void func_0203B48C(void);

void func_0203B4DC(void);

void func_0203B52C(struct NetStateWork *work);

void func_0203B5D4(struct NetStateWork *work);

void func_0203B688(struct NetStateWork *work);

int func_0203B6B4(void);

void func_0203B6EC(struct NetStateWork *work);

void func_0203B758(void);

void func_0203B794(struct NetStateWork *work);

void func_0203B7F8(struct NetStateWork *work);

void func_0203B868(struct NetStateWork *work);

void func_0203B90C(void);

void func_0203B950(struct NetStateWork *work);

void func_0203B9D4(struct NetStateWork *work);

void func_0203BA98(u16 unusedArg, u32 initCallback, u8 hasMac);

void func_0203BBB0(struct NetStateWork *work);

void func_0203BC58(u8 mode, u8 hasMac, const void *mac);

void func_0203BCE0(struct NetStateWork *work);

void func_0203BD30(u32 mode, u32 hasMac, u8 *mac);

void func_0203BDEC(void);

void func_0203BE5C(u32 netID, u32 size, u32 data, u32 work, u32 handle);

u32 func_0203BEAC(void);

void func_0203BEC8(struct NetStateWork *work);

void func_0203BF4C(void);

void func_0203BF9C(u32 exitCallback);

void func_0203BFF0(void);

void func_0203C00C(void);

void func_0203C010(void);

GFLNetSession *func_0203C044(int netID, int size, u8 *data, int work);

void func_0203C05C(void);

void func_0203C060(void);

void func_0203C064(void);

void func_0203C068(void);

void func_0203C0B4(void);

void func_0203C0DC(struct NetStateWork *work, u32 errorCode);

void func_0203C0F4(struct NetStateWork *work);

void func_0203C238(struct NetStateWork *work);

int func_0203C2B0(int loginTarget);

u32 func_0203C304(void);

u32 func_0203C35C(void);

void func_0203C3B4(void);

int func_0203C3EC(void);

void func_0203C464(void);

void func_0203C494(struct NetStateWork *work);

void func_0203C554(u32 hasMatch);

void func_0203C5C8(void);

int func_0203C5EC(void);

int func_0203C600(void);

int func_0203C628(void);

void func_0203C65C(struct NetStateWork *work);

void func_0203C710(void);

void func_0203C774(u32 exitCallback);

void func_0203C7E0(struct NetStateWork *work);

void func_0203C864(void);

void func_0203C8A8(void);

void func_0203C8E8(u8 autoExit);

void func_0203C900(u8 option);

void func_0203C934(void);

u32 func_0203C938(u8 mode);

void func_0203C968(void);

u32 func_0203C990(void);

void func_0203C9AC(int errorCode, u32 errorArg1, u32 errorArg2, u32 errorArg3);

void func_0203CA04(void);

u32 func_0203CA98(void);

void func_0203CADC(void);

int func_0203CB00(void);

int func_0203CEAC(void (*a0)(u32));

int func_0203D3A8(GFLNetHandle *a, u32 b, u32 c, const void *d);

u32 func_0203D650(void);

void func_0203D700(void);

GFLNetSession *func_0203D788(void);

GFLNetSession *func_0203D798(void);

int func_0203DA4C(void);

extern struct NetStateWork *_pNetState;

extern const char _FileName[];

extern const char _AssertNetStateNull[];

extern u32 _VBlankCount;

extern const char _AssertMacAlign[];

extern const char _AssertNetTypeWifi[];

extern const char _AssertNetState[];

extern const char _AssertWifiBattleError[];


/*
 * Setter and its tail-call export in net_state.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203AD74.c \
 *       --addr 0x0203AD74 --arm --cc 1.1p1
 */
void func_0203AD74(struct NetStateWork *work, void *state, u32 timer)
{
    work->state = state;
    work->timer = timer;
}





























void func_0203AD80(struct NetStateWork *work, void *state, u32 timer, int line)
{
    func_0203AD74(work, state, timer);
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
 * `_pNetState->f46 = ...` spells and what a local pointer would not.
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
void func_0203AD8C(u32 heapId)
{
    if (_pNetState != 0) {
        func_02034714(_FileName, 0xb8, _AssertNetStateNull);
    }
    _pNetState = func_02030734(heapId, 0x64, 1, _FileName, 0xb9);
    _pNetState->timer = 0x32;
    _pNetState->parentRetry = 1;
    func_0203AE20(&_pNetState->random);
    func_0203A494(0, 0, 0, 0, heapId);
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
void func_0203AE20(MATHRandContext64 *context)
{
  struct RTCDate date;
  struct RTCTime time;
  u8 mac[6];
  u32 seed;
  OS_GetMacAddress(mac);
  func_020889C0(&date, &time);
  seed = ((date.year + ((date.day * (date.month << 8)) << 16)) + (time.hour << 16)) + ((time.minute + time.second) << 24);
  seed = seed + (mac[5] + ((mac[3] << 16) + (mac[4] << 8)));
  seed = seed + _VBlankCount;
  func_0203F034(seed);
  {
    u32 randHigh = func_0203F0A8();
    MATH_InitRand64(context, (((u64) randHigh) << 32) + func_0203F0A8());
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
void func_0203AEEC(struct NetStateWork *work)
{
    void (*exitCallback)(void);

    if (func_0203D788()->ops->getParentChannel() == 0)
        return;
    func_0203A53C();
    func_020370C8();
    func_02037B08();
    exitCallback = _pNetState->exitCallback;
    func_020307B0(_pNetState);
    _pNetState = 0;
    if (exitCallback != 0)
        exitCallback();
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
 *    field `void (*f2c)(u32)` and writing `p->f2C(func_0203D650())` pins r0
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
void func_0203AF40(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();
    GFLNetSession *pNetIni = func_0203D798();

    if (pNetIni->init.bNetType != 1 && pNetIni->init.bNetType != 2)
        session->ops->connectToParent(pNetIni->init.heapId, session, 0, session->userArg);
    func_02037D78();
    if (work->initCallback != 0) {
        work->initCallback(func_0203D650());
        work->initCallback = 0;
    }
    func_0203AD80(_pNetState, (void *)func_0203C00C, 0, 0x12f);
}

























void func_0203AFCC(void *heapId, u32 initCallback)
{
    func_02034F84(4);
    func_0203AD8C((u32)heapId);
    _pNetState->initCallback = (void (*)(u32))initCallback;
    func_0203AD80(_pNetState, (void *)func_0203AF40, 0, 0x13F);
}






























/*
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203B018.c \
 *       --addr 0x0203B018 --arm
 *
 * net_state.c.  func_0203B018 is the 4-byte `bx lr` no-op that
 * func_0203B038 hands to func_02037A6C as its completion callback (the
 * pool word at 0x0203B080 is its only referrer).  func_0203B01C is the
 * unlabelled leaf that bumps the state record's +0x46 countdown by 0x3C;
 * func_0203B390 names it through a pool word.  Filing both here gives the
 * `matched` class a witness for each (docs/families/net_state.h, THE REPORT
 * TAG RULE, "the two genuine exceptions").
 *
 * Integrator: seed 0x0203B01C arm (member of this unit, no label).
 */
void func_0203B018(void)
{
}






























void func_0203B01C(void)
{
    _pNetState->timer += 0x3c;
}






























/*
 *           resolved.  Adding the symbols: block (it had none) let
 *           0x0203B01C resolve as `literal x8, e.g. 0203B43C`; previously it
 *           reported "no address for '(void *)func_0203B01C'".  The ONE remaining
 *           site is 0x0203B018.
 * PARKED AT MATCH.  Every concrete byte is right (76 of 76) and the file is
 * the right size; the one open site is the ABS32 to 0x0203B018, the bare
 * `bx lr` filler word that sits between func_0203AFCC's literal pool and the
 * unlabelled leaf at 0x0203B01C.  That address has no label (a prologue that
 * saves no `lr` is never auto-labelled) and the word appears in exactly one
 * literal pool image-wide - this function's own - so neither `label` nor
 * `literal` can attest it.
 *           referenced by exactly ONE word image-wide, the pool word at
 *           0x0203B080 (grep of asm/ finds it in main.s and the four unit
 *           listings, all the same address), and 0x0203B080 lies inside this
 *           function's own compared range 0203B038..0203B084.  `label`
 *           refuses (a `bx lr` saves no lr so disasm.py never labels it),
 *           `literal` refuses (no second occurrence outside the range) and
 *           `sole-ref/code` refuses (not a traced function start).  Blocking
 *           class: none available, own-pool-only code.  It would unstick if a
 *           future EXACT entry covered 0x0203B018 itself, but that address is
 *           outside pkt_0203B038's range (0x0203B038..0x0203B084).
 *
 * Both 0x0203B018 and 0x0203B01C must be declared in the symbols: block:
 * written as plain integer literals the pair folds into one pool word plus a
 * `sub r1, r4, #4`, which is four bytes short of the original's two words.
 * 0x0203B01C resolves as `literal x10`; only the no-op word does not.
 *
 * The call's completion callback is the leaf at 0x0203B01C (bumps the +0x46
 * halfword by 0x3C); the report's identifier is the no-op at 0x0203B018.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203B038.c \
 *       --func func_0203B038 --addr 0x0203B038 --cc 1.1p1 --arm
 */
void func_0203B038(struct NetStateWork *work)
{
    if (func_02037A6C(0, (u32)work->aMacAddress, 0x200, (u32)(void *)func_0203B01C) != 0)
        func_0203AD80(_pNetState, (void *)func_0203B018, 0xA, 0x169);
}





























/*
 * Starts a 0x200-byte transfer over channel 1 and reports at line 0x17C
 * (380) when it answers zero.  The report site names func_0203B038, the
 * sibling entry that put the read in flight.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B084.c \
 *       --func func_0203B084 --addr 0x0203B084 --cc 1.1p1 --arm
 */
void func_0203B084(void)
{
    func_0203D798();
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80(_pNetState, (void *)func_0203B038, 0, (int)0x17C);
}





























void func_0203B0C4(int mac, int anyParent)
{
    if ((int)_pNetState->aMacAddress & 1) {
        func_02034714(_FileName, 395, _AssertMacAlign);
    }
    if (mac != 0) {
        MI_CpuCopy8((void *)mac, _pNetState->aMacAddress, 6);
    }
    if (anyParent != 0) {
        func_0203AD80(_pNetState, (void *)func_0203B084, 0, 400);
    } else {
        func_0203AD80(_pNetState, (void *)func_0203B038, 0, 403);
    }
}





























void func_0203B16C(void)
{
}






























/*
 * The same 0x200-byte channel-1 start as func_0203B084 with no context
 * refresh, reporting at line 0x1AE (430).  0x1AE is not ARM-encodable, so the
 * constant is materialised off the 0x200 argument register as
 * `sub r3, r4, #0x52`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B170.c \
 *       --func func_0203B170 --addr 0x0203B170 --cc 1.1p1 --arm
 */
void func_0203B170(void)
{
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80(_pNetState, (void *)func_0203B16C, 0, 0x1AE);
}






























/*
 * Tail-call wrapper over func_0203AD80 (the object at 0x021469DC, the
 * callback func_0203B170, 0, 0x1BC).  An unlabelled ARM leaf, filed as the
 * witness chain for func_0203D010 (state 10 of func_0203DC70).
 */
void func_0203B1B0(void)
{
    func_0203AD80(_pNetState, func_0203B170, 0, 0x1BC);
}




























u32 func_0203B1D8(void)
{
    struct NetStateWork *work = _pNetState;

    if (work == 0)
        return 1;
    if (work->state != 0)
        work->state(work);
    if (_pNetState == 0)
        return 1;
    func_0203C934();
    return 0;
}




























void func_0203B224(void)
{
}




























void func_0203B228(void)
{
}



























int func_0203B22C(void)
{
    func_0203AD80(_pNetState, func_0203B224, 0, 0x1f4);
    return 1;
}



























/*
 * Starts a 0x200-entry transfer over channel 1 and reports through
 * func_0203AD80 at line 517 when the start call answers zero.  The line comes
 * out as `add r3, r4, #5` because r4 already holds the 0x200 argument, the
 * same constant-rematerialisation the consecutive-`__LINE__` idiom records.
 *
 * Both callback addresses (0x0203B22C and 0x0203B228, the two `bx lr` filler
 * words in the pool of func_0203B1D8) are declared as symbols: written as
 * plain integer literals this compiler folds the pair into one pool word plus
 * a `sub r1, r4, #4`, which is four bytes short of the original's two pool
 * words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B258.c \
 *       --func func_0203B258 --addr 0x0203B258 --cc 1.1p1 --arm
 */
void func_0203B258(void)
{
    func_0203D798();
    if (func_02037894(1, 0x200, 1, (u32)(void *)func_0203B22C) != 0)
        func_0203AD80(_pNetState, (void *)func_0203B228, 0, 0x205);
}


























void func_0203B2A8(int heapId)
{
    func_0203AD80(_pNetState, (void *)func_0203B228, 0, 0x214);
}



























void func_0203B2D0(u32 unused)
{
    func_0203AD80(_pNetState, func_0203B258, 0, 0x222);
}



























u32 func_0203B2FC(struct NetStateWork *work)
{
    u32 randHigh;
    u64 randNext = work->random.mul * work->random.x + work->random.add;
    work->random.x = randNext;
    randHigh = (u32)(randNext >> 32);
    return (u32)(((u64)randHigh * 40) >> 32) + 0x3c;
}



























u32 func_0203B344(struct NetStateWork *work)
{
    u32 randHigh;
    u64 randNext = work->random.mul * work->random.x + work->random.add;
    work->random.x = randNext;
    randHigh = (u32)(randNext >> 32);
    return (u32)(((u64)randHigh * 32) >> 32) + 0xb4;
}



























/*
 * Closes the residue docs/notes/pkt_0203B390.c.txt recorded ("DIFF, one
 * instruction": `mov r0, #1` hoisted above the `beq` in the original but
 * left inside the alt block in every spelling that note tried).  The note
 * was looking at the wrong constant.  What the original hoists is not the
 * `1`, it is the 0x200 -- `mov r4, #0x200` at +0x24, before the compare
 * chain -- and r4 then serves FOUR uses: the length argument of
 * func_02037A6C, the second argument of func_02037928 on the alt path, and
 * the base of both line numbers (`add r3, r4, #0x45` = 0x245 and
 * `add r3, r4, #0x4a` = 0x24A).  Binding it to ONE local `u32 n = 0x200;`
 * declared before the guards gives it a live range that spans both arms,
 * which is what pins it in r4 and frees r0 for the literal `1` to be
 * materialised in the pre-branch block.  The note's experiment of making
 * `one` a local was the right technique applied to the wrong value.
 *
 * EXACT on the first compile with that change; no permuter search needed.
 */
void func_0203B390(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();
    u32 scanParam = 0x200;

    if (session->ops->getLinkLevel() == 0)
        return;
    if (work->changeoverHasMac == 0 || work->changeoverMode == 1)
        goto alt;

    if (func_02037A6C(1, (u32)work->changeoverMac, scanParam, (u32)func_0203B01C) == 0)
        return;
    func_0203AD80(_pNetState, (void *)func_0203B950, func_0203B2FC(work), scanParam + 0x45);
    return;

alt:
    if (func_02037928(1, scanParam) == 0)
        return;
    func_0203AD80(_pNetState, (void *)func_0203B950, func_0203B344(work), scanParam + 0x4a);
}




























/*
 * Reports at line 0x25D (605) when the transport's +0x78 virtual answers
 * non-zero.  The condition is the negated guard - the `pop` is on the equal
 * arm - so the C is the report inside a `!= 0` if, not a return.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B448.c \
 *       --func func_0203B448 --addr 0x0203B448 --cc 1.1p1 --arm
 */
void func_0203B448(void)
{
    if (func_0203D788()->ops->getLinkLevel() != 0)
        func_0203AD80(_pNetState, (void *)func_0203B390, 0, (int)0x25D);
}




























/*
 * The same +0x10 virtual call as func_0203B4DC, reporting at line 0x265
 * (613).  Both the first call argument and the reported line derive from the
 * single 1 that the function materialises, which is what makes the line come
 * out as `add r3, r5, #0x264`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B48C.c \
 *       --func func_0203B48C --addr 0x0203B48C --cc 1.1p1 --arm
 */
void func_0203B48C(void)
{
    if (func_0203D788()->ops->setBeaconInterval(1, 0) != 0)
        func_0203AD80(_pNetState, (void *)func_0203B448, 0, 0x265);
}




























/*
 * Calls the transport's +0x10 virtual with (1, 0) and reports at line 0x282
 * (642) when it answers non-zero.  The zero argument and the report's third
 * argument are the same `mov r4, #0` local, which is what puts the two
 * together in one register.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B4DC.c \
 *       --func func_0203B4DC --addr 0x0203B4DC --cc 1.1p1 --arm
 */
void func_0203B4DC(void)
{
    if (func_0203D788()->ops->setBeaconInterval(1, 0) != 0)
        func_0203AD80(_pNetState, (void *)func_0203B390, 0, (int)0x282);
}



























/*
 * Wave 14: the "unresolvable" second tag site was a misread.  The pool word
 * at 0x0203B5CC (+0xA0) is 0x0203C00C (bytes 0c c0 03 02), not 0x0203B40C;
 * 0x0203C00C is the same tag func_0203AF40 passes and resolves `literal`.
 * The first tag, 0x0203B4DC, resolves `matched` (src/matched/func_0203B4DC.c).
 * The callback takes func_0203D650's result in r0, which is why the
 * function pointer is loaded into r1 (docs/families/net_state.h, THE
 * CALLBACK ARITY RULE).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B52C.c \
 *       --func func_0203B52C --addr 0x0203B52C --cc 1.1p1 --arm
 */
void func_0203B52C(struct NetStateWork *work)
{
    func_0203D798();
    if (func_020393D0() != 0)
        return;
    if (func_020393A8() == 0) {
        func_0203AD80(_pNetState, (void *)func_0203B4DC, 0, 0x297);
        return;
    }
    if (func_020399EC() == 0)
        return;
    if (func_02039ACC() == 0)
        return;
    if (work->initCallback != 0) {
        work->initCallback(func_0203D650());
        work->initCallback = 0;
    }
    func_0203AD80(_pNetState, (void *)func_0203C00C, 0, 0x2a6);
}
























void func_0203B5D4(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();

    if (func_020393A8() != 0) {
        func_0203B2A8(func_0203D798()->init.heapId);
        func_0203D700();
        func_0203AD80(_pNetState, (void *)func_0203B52C, 0, 0x2c1);
        return;
    }
    if (work->changeoverMode == 1)
        return;
    if (session->ops->getScanCount(0) == 0)
        return;
    if (work->timer != 0) {
        work->timer--;
        return;
    }
    func_0203AD80(_pNetState, (void *)func_0203B48C, 0, 0x2d3);
}
























void func_0203B688(struct NetStateWork *work)
{
    func_0203AD80(_pNetState, (void *)func_0203B5D4, func_0203B344(work), 0x2e0);
}
























int func_0203B6B4(void)
{
    func_0203AD80(_pNetState, (void *)func_0203B5D4, func_0203B344(_pNetState), 0x2E6);
    return 1;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B6EC.c \
 *       --func func_0203B6EC --addr 0x0203B6EC --cc 1.1p1 --arm
 */
void func_0203B6EC(struct NetStateWork *work)
{
    if (func_0203D788()->ops->getLinkLevel() == 0)
        return;
    if (func_02037894(0, 0x200, 0, (u32)func_0203B6B4) == 0)
        return;

    work->parentRetry = 0;
    func_0203AD80(_pNetState, (void *)func_0203B688, 0x1E, 0x2FC);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B758.c \
 *       --func func_0203B758 --addr 0x0203B758 --cc 1.1p1 --arm
 */
void func_0203B758(void)
{
    func_0203D798();
    if (func_02039ACC() == 0)
        return;

    func_0203AD80(_pNetState, (void *)func_0203B794, 0, 0x30E);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B794.c \
 *       --func func_0203B794 --addr 0x0203B794 --cc 1.1p1 --arm
 */
void func_0203B794(struct NetStateWork *work)
{
    GFLNetSession *pNetIni = func_0203D798();

    if (func_020399B8(func_020399A8()) == 0)
        return;

    if (work->initCallback != 0) {
        work->initCallback(func_0203D650());
        work->initCallback = 0;
    }

    func_0203AD80(_pNetState, (void *)func_0203C00C, 0, 0x325);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B7F8.c \
 *       --func func_0203B7F8 --addr 0x0203B7F8 --cc 1.1p1 --arm
 */
void func_0203B7F8(struct NetStateWork *work)
{
    func_0203D798();

    func_0203996C(0xFF);
    func_020399A8();
    if (func_020399EC() < 2)
        return;

    func_02039338();

    if (work->initCallback != 0) {
        work->initCallback(func_0203D650());
        work->initCallback = 0;
    }

    func_0203AD80(_pNetState, (void *)func_0203C00C, 0, 0x33F);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B868.c \
 *       --func func_0203B868 --addr 0x0203B868 --cc 1.1p1 --arm
 */
void func_0203B868(struct NetStateWork *work)
{
    func_0203D798();

    if (func_0203D788()->ops->getGgid() != 1)
        return;
    if (func_02039ACC() == 0)
        return;

    if (func_0203DA4C() == 1) {
        func_0203AD80(_pNetState, (void *)func_0203B7F8, 0, 0x354);
        return;
    }

    if (work->initCallback != 0) {
        work->initCallback(func_0203D650());
        work->initCallback = 0;
    }

    func_0203AD80(_pNetState, (void *)func_0203C00C, 0, 0x35B);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B90C.c \
 *       --func func_0203B90C --addr 0x0203B90C --cc 1.1p1 --arm
 */
void func_0203B90C(void)
{
    if (func_0203D788()->ops->getLinkLevel() == 0)
        return;

    func_0203AD80(_pNetState, (void *)func_0203B6EC, 0, 0x371);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B950.c \
 *       --func func_0203B950 --addr 0x0203B950 --cc 1.1p1 --arm
 */
void func_0203B950(struct NetStateWork *work)
{
    if (func_02039338() != 0) {
        func_0203AD80(_pNetState, (void *)func_0203B758, 0, 0x383);
        return;
    }

    if (work->changeoverMode == 2)
        return;

    if (work->timer != 0) {
        work->timer--;
        return;
    }

    func_0203AD80(_pNetState, (void *)func_0203BCE0, 0, 0x390);
    func_0203BCE0(work);
}
























/*
 * A frame's 64-bit accumulator advanced by a 64-bit multiply: the pair at
 * +0x0c (little-endian u64) is multiplied by the pair at +0x14, the pair at
 * +0x1c is added in, both halves are stored back, and the new high half is
 * re-scaled by 30/2^32 into the u16 countdown at +0x46.
 *
 * Two spellings are load-bearing.  The multiply has to be written `y * x`
 * with x at +0x0c and y at +0x14: the other order loads +0x0c first and
 * swaps two `ldr`s.  And the addend has to stay inline in the multiply's own
 * statement (`r = y * x + *(u64 *)(p + 0x1c);`) with the low half stored by
 * a single 64-bit store: with a named addend and two u32 stores mwcc puts
 * the sum's low half in `ip` and the high half in `r2`, a five-instruction
 * difference in register choice alone.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B9D4.c \
 *       --func func_0203B9D4 --addr 0x0203B9D4 --cc 1.1p1 --arm
 */
void func_0203B9D4(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();
    u64 seedState, multiplier, nextState;

    if (session->ops->getTgid() == 1) {
        session->ops->forceReset();
        func_0203AD80(_pNetState, (void *)func_0203B868, 0, 0x3A5);
        return;
    }

    if (work->timer != 0) {
        work->timer = work->timer - 1;
        return;
    }

    seedState = work->random.x;
    multiplier = work->random.mul;
    nextState = multiplier * seedState + work->random.add;

    work->timer = (u16)((u32)(((u64)(u32)(nextState >> 32) * 30) >> 32) + 15);
    work->random.x = nextState;

    session->ops->stop(0);
}
























void func_0203BA98(u16 unusedArg, u32 initCallback, u8 hasMac)
{
    GFLNetSession *pNetIni = func_0203D798();
    struct NetStateWork *work;
    u64 seedState, multiplier, nextState;
    u32 delay = 30;

    func_0203D788();
    func_0203BC58(0, hasMac, 0);

    if (pNetIni->init.bNetType == 3 || pNetIni->init.bNetType == 4) {
        func_020377B8(0);
        _pNetState->initCallback = (void (*)(u32))initCallback;
        work = _pNetState;
        seedState = work->random.x;
        multiplier = work->random.mul;
        nextState = multiplier * seedState + work->random.add;
        work->random.x = nextState;
        func_0203AD80(work, (void *)func_0203B9D4, (u32)(((u64)(u32)(nextState >> 32) * delay) >> 32), delay + 0x3A8);
    } else {
        work = _pNetState;
        if (work->changeoverHasMac != 0 && work->changeoverMode != 1) {
            func_02037A6C(1, (u32)work->changeoverMac, 0x200, (u32)func_0203B01C);
        } else {
            func_02037928(1, 0x200);
        }
        _pNetState->initCallback = (void (*)(u32))initCallback;
        work = _pNetState;
        func_0203AD80(work, (void *)func_0203B950, delay, delay + 0x3B4);
    }
}

























/*
 * Two presets that differ only in the state byte they match and the handler
 * they advertise.  Each test is a conjunction of the state byte and the
 * eight-byte pointer stored beside it, and the first arm also refuses when
 * the vtable's +0x10 hook answers zero.
 *
 * The four code addresses are declared as the functions they are: written as
 * integer literals the front end folds two nearby ones into one pool word plus
 * a `sub`, which is four bytes shorter than the original.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BBB0.c \
 *       --func func_0203BBB0 --addr 0x0203BBB0 --cc 1.1p1 --arm
 */
void func_0203BBB0(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();
    struct NetStateWork *netState;

    netState = _pNetState;
    if (netState->changeoverMode == 2 && netState->state == func_0203B950) {
        if (session->ops->setBeaconInterval(1, 0) != 0) {
            func_0203AD80(_pNetState, ((void *)func_0203B90C), 0, 0x3E0);
        }
    }

    netState = _pNetState;
    if (netState->changeoverMode == 1 && netState->state == func_0203B5D4) {
        func_0203AD80(netState, ((void *)func_0203B48C), 0, 0x3E9);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BC58.c \
 *       --func func_0203BC58 --addr 0x0203BC58 --cc 1.1p1 --arm
 */
void func_0203BC58(u8 mode, u8 hasMac, const void *mac)
{
    func_0203D788();
    _pNetState->changeoverHasMac = hasMac;
    _pNetState->changeoverMode = mode;

    if (mac != 0) {
        MI_CpuCopy8(mac, _pNetState->changeoverMac, 6);
    } else {
        MI_CpuFill8(_pNetState->changeoverMac, 0xFF, 6);
    }

    func_0203AD80(_pNetState, (void *)func_0203BBB0, 0, 0x406);
    func_0203BBB0(_pNetState);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BCE0.c \
 *       --func func_0203BCE0 --addr 0x0203BCE0 --cc 1.1p1 --arm
 */
void func_0203BCE0(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();

    if (session->ops->setBeaconInterval(1, 0) == 0)
        return;

    func_0203AD80(_pNetState, (void *)func_0203B90C, 0, 0x411);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BD30.c \
 *       --func func_0203BD30 --addr 0x0203BD30 --cc 1.1p1 --arm
 */
void func_0203BD30(u32 mode, u32 hasMac, u8 *mac)
{
    func_0203D788();

    _pNetState->changeoverHasMac = (u8)hasMac;
    _pNetState->changeoverMode = (u8)mode;

    if (mac != 0)
        MI_CpuCopy8(mac, _pNetState->changeoverMac, 6);
    else
        MI_CpuFill8(_pNetState->changeoverMac, 0xFF, 6);

    if (_pNetState->changeoverMode == 2)
        func_0203AD80(_pNetState, (void *)func_0203B48C, 0, 0x430);

    if (_pNetState->changeoverMode == 1) {
        func_0203AD80(_pNetState, (void *)func_0203BCE0, 0, 0x438);
        func_0203BCE0(_pNetState);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BDEC.c \
 *       --func func_0203BDEC --addr 0x0203BDEC --cc 1.1p1 --arm
 */
void func_0203BDEC(void)
{
    GFLNetSession *pNetIni = func_0203D798();
    GFLNetSession *session = func_0203D788();

    if ((u8)(pNetIni->init.bNetType + 0xFD) <= 1) {
        if (session->ops->getTgid() != 0)
            return;
        func_0203CEAC(0);
    } else {
        GFLNetSession *rssiSession = func_0203D788();

        if ((rssiSession->ops->getRssi() & 0xFFFE) != 0)
            return;
        func_0203CEAC(0);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BE5C.c \
 *       --func func_0203BE5C --addr 0x0203BE5C --cc 1.1p1 --arm
 */
void func_0203BE5C(u32 netID, u32 size, u32 data, u32 work, u32 handle)
{
    func_0203D3A8((void *)handle, 2, 0, 0);

    if (func_02039338() != 0)
        return;

    func_0203AD80(_pNetState, (void *)func_0203BDEC, 0, 0x46C);
}


























/*
 * "If the state is non-zero, park the card interface."  The result of the
 * test is kept in a local and returned, so the zero path is the `popeq` that
 * gives back r0 == 0 and the busy path returns whatever func_0203CEAC leaves
 * in r0 - no second `mov r0, #0` anywhere.
 *
 * The local is load-bearing: spelling it `if (func_02039338() == 0) return 0;
 * return func_0203CEAC(0);` hoists the `mov r0, #0` that sets up the call's
 * argument above the conditional return and lands two instructions late.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BEAC.c \
 *       --func func_0203BEAC --addr 0x0203BEAC --cc 1.1p1 --arm
 */
u32 func_0203BEAC(void)
{
    u32 result;

    result = func_02039338();
    if (result != 0)
        result = func_0203CEAC(0);
    return result;
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BEC8.c \
 *       --func func_0203BEC8 --addr 0x0203BEC8 --cc 1.1p1 --arm
 */
void func_0203BEC8(struct NetStateWork *work)
{
    GFLNetSession *session;

    func_0203D798();
    session = func_0203D788();

    if (session->ops->getLinkLevel() != 0) {
        if (session->ops->setParentMask(0) == 0)
            return;
        func_0203AEEC(work);
        return;
    }

    if (session->ops->getRunState() != 0)
        return;
    if (session->ops->setParentMask(0) == 0)
        return;
    func_0203AEEC(work);
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203BF4C.c \
 *       --func func_0203BF4C --addr 0x0203BF4C --cc 1.1p1 --arm
 */
void func_0203BF4C(void)
{
    GFLNetSession *session = func_0203D788();

    if (session->ops->setBeaconInterval(1, 0) == 0)
        return;

    func_0203AD80(_pNetState, (void *)func_0203BEC8, 0, 0x4A4);
}


























/*
 * 116 bytes, three functions: the setter, the 28-byte leaf that clears the
 * same flag, and the four-byte `bx lr` stub the card task is handed as a
 * callback (src/pending/func_0203C010.c passes it at 0x0203C00C).
 *
 * The two leaves carry no label in the generated listing - neither saves `lr`
 * - so this range used to stop at 0x0203BF9C with an `EXACT*`, the inferred
 * extent running on to the next labelled function at 0x0203C010.  Writing
 * them as the unit's own functions is what closes the range.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203BF9C.c \
 *       --addr 0x0203BF9C --arm --cc 1.1p1
 */
void func_0203BF9C(u32 exitCallback)
{
    struct NetStateWork *work = _pNetState;

    if (work != 0 && work->exitRequested != 0)
        return;

    work->exitCallback = (void (*)(void))exitCallback;
    _pNetState->exitRequested = 1;
    func_0203AD80(_pNetState, ((void *)func_0203BF4C), 5, 0x4B7);
}


























void func_0203BFF0(void)
{
    if (_pNetState != 0)
        _pNetState->exitRequested = 0;
}


























void func_0203C00C(void)
{
}























/*
 * PROMOTED FROM src/pending/ AT THE END OF WAVE 4 LANE 0x02038000..0x02040000.
 * It was parked at MATCH with every concrete byte right, held there only by
 * the `bl` to 0x020379C8, which nothing outside this range witnessed.  That
 * address has since been matched, so the site now resolves on the `matched`
 * class and the whole 52 bytes are EXACT with no change to the C at all.
 *
 * The callback stub this file passes, 0x0203C00C, is matched as well now, as
 * the last function of src/matched/unit_0203BF9C.c.
 *
 * Allocates 0x200 bytes, then starts the card task on the object at
 * 0x021469DC with the four-byte `bx lr` stub at 0x0203C00C as its callback and
 * 0x4DA (1242) as the fourth argument - the source file/line pair of an assert
 * style entry point.  The stub is a real 4-byte ARM function in the listing, so
 * its address is declared as the function it is and passed as a function
 * pointer; the pool word for it is attested by a dozen other pools elsewhere
 * in the image, and unk_021469DC likewise.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203C010.c \
 *       --func func_0203C010 --addr 0x0203C010 --cc 1.1p1 --arm
 */
void func_0203C010(void)
{
    func_020379C8(0x200);
    func_0203AD80(_pNetState, func_0203C00C, 0, 0x4DA);
}























GFLNetSession *func_0203C044(int netID, int size, u8 *data, int work)
{
    GFLNetSession *pNetIni = func_0203D798();

    pNetIni->init.bMPMode = *data;
    return pNetIni;
}






















/*
 * Empty callback (a lone bx lr), one of three adjacent stubs at
 * 0x0203C05C/60/64 whose addresses func_0203C0F4, func_0203C3EC,
 * func_0203C494 and func_0203C7E0 pass or compare as handler pointers.
 */
void func_0203C05C(void)
{
}






















void func_0203C060(void)
{
}






















void func_0203C064(void)
{
}























/*
 * Calls the virtual at +0xC of the object at *(net context + 0x340) with a
 * zero argument and reports through func_0203AD80 when it answers a negative
 * result.  The `mov r4, #0` local is what feeds both the call's r0 and the
 * report's r2, hence its placement; the `popge` is the `>= 0` half of the
 * signed comparison.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C068.c  *       --func func_0203C068 --addr 0x0203C068 --cc 1.1p1 --arm
 */
void func_0203C068(void)
{
    if (func_0203D788()->ops->requestDisconnect(0) < 0)
        func_0203AD80(_pNetState, (void *)func_0203C05C, 0, (int)0x52C);
}






















void func_0203C0B4(void)
{
    GFLNetSession *session = func_0203D788();
    func_020394DC(1);
    session->ops->requestDisconnect(0);
}























/*
 * Stores one byte at +0x4E, negating it first unless it is 1005 or 1006.  The
 * threshold is written `v - 1005 > 1`, and 1005 is not encodable as an ARM
 * immediate in a `sub`, so mwcc builds it the other way round: `mvn r2, #1004`
 * is -1005 and one `add` finishes the subtraction.  The comparison is
 * unsigned (`rsbhi`), and the negation is `rsb r1, r1, #0`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C0DC.c \
 *       --func func_0203C0DC --addr 0x0203C0DC --cc 1.1p1 --arm
 */
void func_0203C0DC(struct NetStateWork *work, u32 errorCode)
{
    if (errorCode - 1005 > 1)
        errorCode = -errorCode;
    work->wifiErrorCode = (u8)errorCode;
}






















void func_0203C0F4(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();
    GFLNetModeOps *ops = session->ops;
    s32 result = ops->requestDisconnect(0);

    if (result == 1000) {
        func_0203AD80(_pNetState, (void *)func_0203C0B4, 0, 1403);
        return;
    }

    ops = session->ops;
    if (ops->getTgid() != 0) {
        func_0203AD80(_pNetState, (void *)func_0203C0B4, 0, 1407);
        return;
    }

    if (result == 1007) {
        return;
    }

    if (result == 1001) {
        func_0203AD80(_pNetState, (void *)func_0203C060, 0, 1413);
        return;
    }

    if (result == 1002) {
        func_0203AD80(_pNetState, (void *)func_0203C064, 0, 1416);
        return;
    }

    if (result >= 10) {
        func_0203AD80(_pNetState, (void *)func_0203C064, 0, 1420);
        return;
    }

    if (result >= 0) {
        return;
    }

    func_0203C0DC(work, result);
    func_0203AD80(_pNetState, (void *)func_0203C05C, 0, 1424);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C238.c \
 *       --func func_0203C238 --addr 0x0203C238 --cc 1.1p1 --arm
 */
void func_0203C238(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();
    GFLNetSession *pNetIni = func_0203D798();

    if (session->ops->sendPacket(work->loginTarget, pNetIni->init.maxConnectNum, 0) != 0)
        return;

    func_02037D78();
    func_020398B4(session);
    func_02039834(session);
    func_0203AD80(_pNetState, (void *)func_0203C0F4, 0, 0x5AC);
}
























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C2B0.c \
 *       --func func_0203C2B0 --addr 0x0203C2B0 --cc 1.1p1 --arm
 */
int func_0203C2B0(int loginTarget)
{
    if (loginTarget != -1) {
        if (func_0203778C((u32)loginTarget) == 0)
            return 0;
    }

    _pNetState->loginTarget = loginTarget;
    func_0203AD80(_pNetState, (void *)func_0203C238, 0, 0x5C4);
    return 1;
}


























/*
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5D9, returning success.  The twin at 0x0203C35C is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C304.c  *       --func func_0203C304 --addr 0x0203C304 --cc 1.1p1 --arm
 */
u32 func_0203C304(void)
{
    GFLNetSession *session = func_0203D788();

    _pNetState->loginTarget = -2;
    func_02037D78();
    func_020398B4(session);
    func_02039834(session);
    func_0203AD80(_pNetState, (void *)func_0203C0F4, 0, (int)0x5D9);
    return 1;
}


























/*
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5FD, returning success.  The twin at 0x0203C304 is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C35C.c  *       --func func_0203C35C --addr 0x0203C35C --cc 1.1p1 --arm
 */
u32 func_0203C35C(void)
{
    GFLNetSession *session = func_0203D788();

    _pNetState->loginTarget = -2;
    func_02037D78();
    func_020398B4(session);
    func_02039834(session);
    func_0203AD80(_pNetState, (void *)func_0203C0F4, 0, (int)0x5FD);
    return 1;
}


























void func_0203C3B4(void)
{
    _pNetState->loginTarget = -1;
    func_0203AD80(_pNetState, (void *)func_0203C238, 0, 0x60d);
}

























/*
 * Unlabelled ARM leaf (saves no register, so disasm.py gives it no func_
 * label): a channel-id classifier that reads the pointer at _pNetState, then
 * the u32 at +8 of the record, and maps five distinct table addresses to
 * 0/1/3/4/5 (anything else returns 2).
 *
 * The five constants sit in their own pool words at 0x0203C450..0x0203C460
 * and are each loaded with `ldr` from pc, so they are link-time absolute
 * (R_ARM_ABS32) values that the compiler cannot fold against one another.
 * They are spelled as the addresses of the matched arm9 functions that live
 * at those addresses, taken as integers, so each becomes its own relocation
 * and no `sub`/constant-fold is possible.
 */
int func_0203C3EC(void)
{
    void *curState = _pNetState->state;

    if (curState == func_0203C0F4) {
        return 0;
    }
    if (curState == func_0203C0B4) {
        return 1;
    }
    if (curState == func_0203C068) {
        return 3;
    }
    if (curState == func_0203C060) {
        return 4;
    }
    if (curState == func_0203C064) {
        return 5;
    }
    return 2;
}
























void func_0203C464(void)
{
    func_0203D788();
    func_0203AD80(_pNetState, (void *)func_0203C0F4, 0, 0x637);
}


























/*
 * The other half of the connect/disconnect pair whose partner is
 * src/matched/func_0203C554.c: it turns the state byte at +0x4B into the
 * vtable's +0x54 hook, then either starts the link layer or, when the +0x0C
 * hook reports a negative result, files line 0x655.
 *
 * `v` is materialised as 0 before the first call and raised to 1 by
 * `moveq` on the state byte's own compare, so the hook's first argument
 * shares a register with the loop's zero rather than being rematerialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C494.c \
 *       --func func_0203C494 --addr 0x0203C494 --cc 1.1p1 --arm
 */
void func_0203C494(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();
    u32 sendMask = 0;

    func_020394DC(0);

    if (work->matchDisconnect == 0)
        sendMask = 1;

    if (session->ops->sendPacketMask(sendMask, 0) != 0) {
        func_02037D78();
        func_020398B4(session);
        func_02039834(session);
        func_0203AD80(_pNetState, (void *)func_0203C464, 0, 0x64F);
    } else if (session->ops->requestDisconnect(0) < 0) {
        func_0203AD80(_pNetState, (void *)func_0203C05C, 0, 0x655);
    }
}


























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C554.c \
 *       --func func_0203C554 --addr 0x0203C554 --cc 1.1p1 --arm
 */
void func_0203C554(u32 hasMatch)
{
    struct NetStateWork *work = _pNetState;

    if (work == 0)
        return;

    if (hasMatch != 0) {
        if (func_02039338() == 0)
            _pNetState->matchDisconnect = 0;
        else
            _pNetState->matchDisconnect = 1;
    } else {
        work->matchDisconnect = 0;
    }

    func_0203AD80(_pNetState, (void *)func_0203C494, 0, 0x671);
    func_0203C494(_pNetState);
}


























/*
 * Arms the sequence: the slot call with a literal 1, then the same 1 into the
 * object's byte at +0x4A.  The 1 lives in r4 across the call, which is why the
 * function pushes r4 at all.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C5C8.c \
 *       --func func_0203C5C8 --addr 0x0203C5C8 --cc 1.1p1 --arm
 */
void func_0203C5C8(void)
{
    func_0203C554(1);
    _pNetState->disconnectFinal = 1;
}


























/*
 * Unlabelled ARM leaf: byte at +0x4a of the card task object.
 */
int func_0203C5EC(void)
{
    return _pNetState->disconnectFinal;
}

























/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4.
 */
int func_0203C600(void)
{
    return _pNetState->state == (void *)func_0203C0F4;
}

























/*
 * Unlabelled ARM predicate: the callback at +8 of the card task object is func_0203C0F4 or func_0203C464.
 */
int func_0203C628(void)
{
    void *curState = _pNetState->state;
    return curState == (void *)func_0203C0F4 || curState == (void *)func_0203C464;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C65C.c \
 *       --func func_0203C65C --addr 0x0203C65C --cc 1.1p1 --arm
 */
void func_0203C65C(struct NetStateWork *work)
{
    GFLNetSession *session;

    func_0203D798();
    session = func_0203D788();

    session->ops->requestDisconnect(1);

    if (session->ops->getLinkLevel() != 0) {
        session->ops->setParentMask(0);
        func_0203AEEC(work);
        return;
    }

    if (session->ops->getRunState() == 0) {
        session->ops->setParentMask(0);
        func_0203AEEC(work);
        return;
    }

    if (session->ops->getParentChannel() == 0)
        return;

    session->ops->setParentMask(0);
    func_0203AEEC(work);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C710.c \
 *       --func func_0203C710 --addr 0x0203C710 --cc 1.1p1 --arm
 */
void func_0203C710(void)
{
    GFLNetSession *session = func_0203D788();

    session->ops->requestDisconnect(0);
    if (session->ops->setBeaconInterval(1, 0) == 0)
        return;

    func_0203AD80(_pNetState, (void *)func_0203C65C, 0, 0x702);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C774.c \
 *       --func func_0203C774 --addr 0x0203C774 --cc 1.1p1 --arm
 */
void func_0203C774(u32 exitCallback)
{
    GFLNetSession *session;

    if (_pNetState == 0)
        return;

    session = func_0203D788();
    func_020351A0(1);
    _pNetState->exitCallback = (void (*)(void))exitCallback;
    session->ops->sendPacketMask(1, 0);

    func_0203AD80(_pNetState, (void *)func_0203C710, 5, 0x719);
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C7E0.c \
 *       --func func_0203C7E0 --addr 0x0203C7E0 --cc 1.1p1 --arm
 */
void func_0203C7E0(struct NetStateWork *work)
{
    GFLNetSession *session = func_0203D788();
    int result = session->ops->requestDisconnect(0);

    if (result < 0) {
        func_0203C0DC(work, (u32)result);
        func_0203AD80(_pNetState, (void *)func_0203C05C, 0, 0x72E);
    } else if (result > 0) {
        func_0203AD80(_pNetState, (void *)func_0203C464, 0, 0x737);
    }
}

























/*
 * Promoted from src/pending/ on lane 1.  Every concrete byte is right; the one
 * open site was the `bl` to 0x02037700, whose only branch anywhere in the
 * image is this one, so `label` had no outside witness.  With
 * src/matched/func_02037700.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C864.c \
 *       --func func_0203C864 --addr 0x0203C864 --cc 1.1p1 --arm
 */
void func_0203C864(void)
{
    GFLNetSession *pNetIni = func_0203D798();

    if (func_02037700(0x200, pNetIni->init.heapId) == 0)
        return;

    func_0203AD80(_pNetState, (void *)func_0203C7E0, 0, 0x74A);
}

























/*
 * 140 bytes, three functions.  The middle one, 0x0203C8E8, is a 16-byte leaf
 * that saves nothing and so carries no label in the generated listing; the
 * per-function file for 0x0203C8A8 therefore reported an `EXACT*`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0203C8A8.c \
 *       --addr 0x0203C8A8 --arm --cc 1.1p1
 */
void func_0203C8A8(void)
{
    if (func_020392EC() != 0)
        return;

    func_0203D798();
    func_0203516C(1);
    func_0203AD80(_pNetState, (void *)func_0203C864, 0, 0x760);
}

























void func_0203C8E8(u8 autoExit)
{
    if (_pNetState != 0)
        _pNetState->autoExit = autoExit;
}

























void func_0203C900(u8 option)
{
    GFLNetSession *session = func_0203D788();

    if (_pNetState != 0)
        _pNetState->loginOption = option;

    session->ops->setPowerSave(option);
}
























void func_0203C934(void){ }

























/*
 * Opens the state: with no live object the answer is 0, otherwise the mode
 * byte at +0x4D is written, the two setup calls run and the answer is 1.
 * src/matched/func_0203C968.c is the matching close.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C938.c \
 *       --func func_0203C938 --addr 0x0203C938 --cc 1.1p1 --arm
 */
u32 func_0203C938(u8 mode)
{
    struct NetStateWork *work;

    work = _pNetState;
    if (work == 0)
        return 0;
    work->errorMode = mode;
    func_02039548();
    func_02039578();
    return 1;
}

























/*
 * Closes the state src/matched/func_0203C938.c opens: clears the mode byte and
 * runs the teardown call.  With no live object it is a bare `popeq`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C968.c \
 *       --func func_0203C968 --addr 0x0203C968 --cc 1.1p1 --arm
 */
void func_0203C968(void)
{
    struct NetStateWork *work;

    work = _pNetState;
    if (work == 0)
        return;
    work->errorMode = 0;
    func_02039560();
}

























/*
 * The mode byte src/matched/func_0203C938.c writes, read back - 0 when there
 * is no object.  Both loads are conditional, so the function is two
 * instructions plus the two pool words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C990.c \
 *       --func func_0203C990 --addr 0x0203C990 --cc 1.1p1 --arm
 */
u32 func_0203C990(void)
{
    struct NetStateWork *work;

    work = _pNetState;
    return work ? work->errorMode : 0;
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C9AC.c \
 *       --func func_0203C9AC --addr 0x0203C9AC --cc 1.1p1 --arm
 */
void func_0203C9AC(int errorCode, u32 errorArg1, u32 errorArg2, u32 errorArg3)
{
    if (_pNetState == 0)
        return;

    if ((u32)(errorCode - 0x3ED) > 1)
        errorCode = -errorCode;

    _pNetState->errorInfo[0] = errorCode;
    _pNetState->errorInfo[1] = errorArg1;
    _pNetState->errorInfo[2] = errorArg2;
    _pNetState->errorInfo[3] = errorArg3;

    if (errorArg3 != 0)
        func_02039548();
}

























/*
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CA04.c \
 *       --func func_0203CA04 --addr 0x0203CA04 --cc 1.1p1 --arm
 */
void func_0203CA04(void)
{
    GFLNetSession *pNetIni;
    u32 isWifiType;

    if (_pNetState == 0)
        return;

    pNetIni = func_0203D798();

    isWifiType = 0;
    if ((u8)(pNetIni->init.bNetType + 0xFF) <= 5) {
        if (((1 << (u8)(pNetIni->init.bNetType + 0xFF)) & 0x23) != 0)
            isWifiType = 1;
    }

    if (isWifiType == 0)
        func_02034714(_FileName, 0x8B7, _AssertNetTypeWifi);

    _pNetState->errorInfo[0] = 0;
    _pNetState->errorInfo[1] = 0;
    _pNetState->errorInfo[2] = 0;
    _pNetState->errorInfo[3] = 0;
}






















/*
 * Returns the object's work area at +0x30, reporting through func_02034714
 * with the source file at 0x020A7BA8 and line 0x8CA (2250) when the object has
 * not been created - the report is not fatal, the address of the null object's
 * field is still what comes back.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203CA98.c \
 *       --func func_0203CA98 --addr 0x0203CA98 --cc 1.1p1 --arm
 */
u32 func_0203CA98(void)
{
    if (_pNetState == 0)
        func_02034714(_FileName, 0x8CA, _AssertNetState);
    return (u32)_pNetState->errorInfo;
}






















/*
 * Unlabelled ARM assert thunk: tail call func_02034714(_FileName, 0x8D8, _AssertWifiBattleError), the fall-through failure path after func_0203CA98.
 */
void func_0203CADC(void)
{
    func_02034714(_FileName, 0x8D8, _AssertWifiBattleError);
}






















/*
 * Unlabelled ARM predicate: the card task object exists and its callback at +8 is func_0203CADC.
 * MATCH only because 0x0203CADC (func_0203CADC.c, EXACT) is not yet a labelled
 * function start: the pool word has no outside witness until the seed lands.
 */
int func_0203CB00(void)
{
    struct NetStateWork *work = _pNetState;
    if (work != 0 && work->state == (void *)func_0203CADC) {
        return 1;
    }
    return 0;
}
