/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x020271F8
 * packet:   pkt_020271F8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020271F8, sub_02027220, sub_02027230, sub_02027258,
 *           sub_02027268, sub_02027290, sub_020272A4, sub_020272D0,
 *           sub_020272EC, sub_02027314, sub_02027324, sub_0202734C
 *
 * symbols:
 *   g_System        0x02146940  data
 *   sub_02027060    0x02027060  thumb
 *   sub_02026FB8    0x02026FB8  thumb
 *   func_020270AC   0x020270AC  thumb
 *   func_0202744C   0x0202744C  thumb
 *
 * Six checker/trampoline pairs, one per numeric event id (0xe, 0xf, 0x10,
 * 0x11, 0x14, 0x23), all working the same event-queue object obtained as
 * `g_System + 4`. Every checker has the same shape: ask
 * `sub_02027060(id)` (a priority gate against the object's current mode,
 * not itself in this packet) whether the id is allowed to run right now,
 * and if so, forward the caller's argument(s) into the queue object
 * through the matching trampoline and then hand the queue object to
 * `sub_02026FB8` (the dispatcher, also outside this packet). The queue
 * object is re-read from `g_System` between the trampoline call and the
 * dispatch call rather than kept in a register, because the compiler
 * cannot see across those two calls that the global does not change: this
 * is only reproduced by declaring `g_System` `volatile`, which is exactly
 * the case docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md
 * records.
 *
 * The trampolines write the event id to +0x30 of the queue object and, in
 * four of the six (0xe, 0xf, 0x14, 0x23), a single 16-bit argument to
 * +0x32 or +0x34 before tail-calling the shared `func_0202744C`, which
 * marks the object "pending" independently of which id was just set. The
 * 0x10 trampoline instead tail-calls `func_020270AC(value, dst+0x34)`
 * directly, skipping `func_0202744C`; sub_020272A4/sub_020272D0 (id 0x11)
 * takes two arguments and does both: it stores the first at +0x32,
 * forwards the second to `func_020270AC(b, dst+0x34)`, and then also
 * calls `func_0202744C`. `func_020270AC` and `sub_02026FB8` are themselves
 * open in this packet's neighbour pkt_02026250, so they are left as
 * unresolved externs here and attest through the whole-image `label`
 * class, since both are called from more places than just this unit.
 *
 * All twelve functions, 356 bytes, one contiguous run with no gap: the
 * trampoline of one pair ends exactly where the checker of the next
 * begins. 31 of 31 relocations resolve (`local` for the intra-file calls,
 * `label` for sub_02027060/sub_02026FB8/func_020270AC/func_0202744C, and
 * `literal` for g_System, which is loaded from the pool at least 26 times
 * elsewhere in the ARM9 image).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_020271F8.c \
 *       --addr 0x020271F8 --thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u32 sub_02027060(u32 id);
extern void * const volatile g_System;
extern void sub_02026FB8(void *queue);
extern void func_020270AC(u16 value, void *dst);
extern void func_0202744C(void *dst);

static void sub_02027220(void *dst, u16 value);

void sub_020271F8(u16 value)
{
    if (sub_02027060(0xe)) {
        void *queue = (char *)g_System + 4;
        sub_02027220(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}

static void sub_02027220(void *dst, u16 value)
{
    *(u16 *)((char *)dst + 0x30) = 0xe;
    *(u16 *)((char *)dst + 0x32) = value;
    func_0202744C(dst);
}

static void sub_02027258(void *dst, u16 value);

void sub_02027230(u16 value)
{
    if (sub_02027060(0xf)) {
        void *queue = (char *)g_System + 4;
        sub_02027258(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}

static void sub_02027258(void *dst, u16 value)
{
    *(u16 *)((char *)dst + 0x30) = 0xf;
    *(u16 *)((char *)dst + 0x32) = value;
    func_0202744C(dst);
}

static void sub_02027290(void *dst, u16 value);

void sub_02027268(u16 value)
{
    if (sub_02027060(0x10)) {
        void *queue = (char *)g_System + 4;
        sub_02027290(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}

static void sub_02027290(void *dst, u16 value)
{
    *(u16 *)((char *)dst + 0x30) = 0x10;
    func_020270AC(value, (char *)dst + 0x34);
}

static void sub_020272D0(void *dst, u16 a, u16 b);

void sub_020272A4(u16 a, u16 b)
{
    if (sub_02027060(0x11)) {
        void *queue = (char *)g_System + 4;
        sub_020272D0(queue, a, b);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}

static void sub_020272D0(void *dst, u16 a, u16 b)
{
    *(u16 *)((char *)dst + 0x30) = 0x11;
    *(u16 *)((char *)dst + 0x32) = a;
    func_020270AC(b, (char *)dst + 0x34);
    func_0202744C(dst);
}

static void sub_02027314(void *dst, u16 value);

void sub_020272EC(u16 value)
{
    if (sub_02027060(0x14)) {
        void *queue = (char *)g_System + 4;
        sub_02027314(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}

static void sub_02027314(void *dst, u16 value)
{
    *(u16 *)((char *)dst + 0x30) = 0x14;
    *(u16 *)((char *)dst + 0x34) = value;
    func_0202744C(dst);
}

static void sub_0202734C(void *dst, u16 value);

void sub_02027324(u16 value)
{
    if (sub_02027060(0x23)) {
        void *queue = (char *)g_System + 4;
        sub_0202734C(queue, value);
        queue = (char *)g_System + 4;
        sub_02026FB8(queue);
    }
}

static void sub_0202734C(void *dst, u16 value)
{
    *(u16 *)((char *)dst + 0x30) = 0x23;
    *(u16 *)((char *)dst + 0x34) = value;
    func_0202744C(dst);
}
