/*
 * function: GAMESYSTEM_ProcInit
 * address:  0x02011D9C
 * packet:   pkt_02011D9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * promoted: wave 21 lane T, EXACT (match.py one, 25 of 25 relocations)
 *           once the ov230d token let the probe targets resolve
 *
 * symbols:
 *   ov230_id       0x000000E6  data
 *   _GameSystemGlobal     0x02146248  data
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188354  0x02188354  arm  ov230d
 *   func_02188390  0x02188390  arm  ov230d
 *   func_0215FA00  0x0215FA00  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 *   GAMESYSTEM_CallIfSet  0x02011D28  thumb
 *   GAMESYSTEM_LeakHeapPenalty  0x02011D40  thumb
 *   GAMESYSTEM_ProbeHeapCreate  0x02011D60  thumb
 *   GAMESYSTEM_LeakHeapPenaltyRepeat  0x02011D7C  thumb
 *   GAMESYSTEM_GetWorkSize  0x02011F24  thumb
 *   GAMESYSTEM_Setup  0x02011FB8  thumb
 *   GAMESYSTEM_SetEvent  0x02012108  thumb
 *
 * ica_anime.c: scene bring-up.  Loads overlay 230, runs three checksum
 * probes over this family's own code (GAMESYSTEM_CallIfSet to GAMESYSTEM_LeakHeapPenalty,
 * GAMESYSTEM_ProbeHeapCreate, GAMESYSTEM_LeakHeapPenaltyRepeat; each result compared with the complement of
 * the end address), creates three heaps through func_0203064C, allocates
 * the work block and publishes it to _GameSystemGlobal, then, when the probe
 * results do not add up to a multiple of 0x12AF, runs a func_0200C258-counted
 * loop of GAMESYSTEM_LeakHeapPenalty.
 *
 * Byte-correct: 272 of 272 bytes, 0 concrete bytes out (match.py one,
 * dsi/1.1p1, 2026-09-24 wave 21 lane H).  The lever that closed it after
 * eight waves at 8 out: the probes' shared start address is held in a u32
 * local (`start = (u32)GAMESYSTEM_CallIfSet;`) and cast back at each call
 * (docs/idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md).
 * The local's web spans the second heap call, so the argument 4 there is
 * rematerialised (`movs r2,#4 ... movs r1,#4; lsls r2,r2,#14`) instead of
 * being common-subexpression-eliminated into r1, which is what the image
 * does; the single-call shape `off = 0; if (flag == 0) off = 0x191;` is the
 * right control flow once that holds.
 *
 * Probe targets (wave 21 lanes H2 and T): 0x021882A0, 0x02188354 and
 * 0x02188390 are slots 0, 3 and 4 of the six ARM thunk slots ov230's first
 * static initialiser (func_02188408) decrypts in place when this function
 * loads the overlay.  The ROM bytes there are ciphertext, so ov230's ROM
 * listing never labels them; tools/ovcrypt.py replays ov230's own
 * decryptor (every range checked to be a clean ARM function ending in a
 * return) and asm/ov230d/ov230d.s lists the result.  With the `ov230d`
 * token on the three symbols: lines they resolve as sole-ref/code against
 * that listing: 25 of 25 sites (ov230_id as overlay_id, func_0215FA00
 * sole-ref/code with the ov010 hint).
 */

#include "../include/G_G02146248.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;
typedef signed char s8;
typedef signed short s16;

extern u32   GAMESYSTEM_GetWorkSize(void);
extern u8 ov230_id[];
extern int func_02034AC4(int id);
extern u32   func_021882A0(void (*a)(void), void (*b)(void), u32 c);
extern u32   func_02188354(void (*a)(void), void (*b)(void), u32 c);
extern u32   func_02188390(void (*a)(void), void (*b)(void), u32 c);
//P
extern void  func_02034A5C(s32 id);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  func_02082BCC(void *p, u32 v, u32 size);
extern struct G02146248 _GameSystemGlobal;
struct Blk34;
struct Ctx;
struct IcaAnime;
extern void GAMESYSTEM_Setup(struct IcaAnime *p, u16 id, u32 a2);
extern u32   func_0215FA00(void *p, u32 a);
extern void GAMESYSTEM_SetEvent(struct Ctx *p, u32 v);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012F08(int *p);
extern u32 func_0200C258(struct Blk34 *p);
extern void  GAMESYSTEM_LeakHeapPenalty(void);
extern u32 GAMESYSTEM_CallIfSet(u32 (*fn)(void));
extern void  GAMESYSTEM_ProbeHeapCreate(void);
extern void  GAMESYSTEM_LeakHeapPenaltyRepeat(void);

extern void func_0203064C(u32 a, u32 b, u32 c);

u32 GAMESYSTEM_ProcInit(void *a0, u32 a1, u32 a2)
{
    u32 size;
    u32 base;
    u32 flag;
    u32 off;
    void *p;
    s32 n;
    s32 i;
    u32 start;

    size = GAMESYSTEM_GetWorkSize();
    start = (u32)GAMESYSTEM_CallIfSet;
    base = 0xc35ffb;
    func_02034AC4((int)ov230_id);
    flag = 0;
    if (func_021882A0((void (*)(void))start, GAMESYSTEM_LeakHeapPenalty, 0) == ~(u32)GAMESYSTEM_LeakHeapPenalty)
        flag = 1;
    base += flag * 0x47;
    func_0203064C(1, 3, 0xa << 12);
    flag = 1;
    if (func_02188354((void (*)(void))start, GAMESYSTEM_ProbeHeapCreate, 0) != ~(u32)GAMESYSTEM_ProbeHeapCreate)
        flag = 0;
    off = 0;
    if (flag == 0)
        off = 0x191;
    func_0203064C(1, 4, 4 << 14);
    func_02188390((void (*)(void))start, GAMESYSTEM_LeakHeapPenaltyRepeat, 0);
    func_0203064C(9, 5, 5 << 10);
    func_02034A5C((s32)ov230_id);
    p = func_0203159C(a0, size, 3);
    func_02082BCC(p, 0, size);
    (*(void * *)&_GameSystemGlobal) = p;
    GAMESYSTEM_Setup(p, 3, a2);
    GAMESYSTEM_SetEvent(p, func_0215FA00(p, a2));
    if ((base + off) % 0x12af != 0) {
        n = func_0200C258(func_02012F08(func_020120F4(p)));
        for (i = 0; i < n; i++)
            GAMESYSTEM_LeakHeapPenalty();
    }
    return 1;
}
