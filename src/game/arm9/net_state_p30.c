/*
 * file:     net_state_p30.c
 * unit:     yes
 * function: func_0203A27C, func_0203A28C, func_0203A2F0, func_0203A338, func_0203A388, func_0203A424, func_0203A458, func_0203A494
 * address:  0x0203A27C
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
 *   func_02034714  0x02034714  arm
 *   file_020A7A68  0x020A7A68  data
 *   file_020A7AB0  0x020A7AB0  data
 *   func_0203996C  0x0203996C  arm
 *   func_02039658  0x02039658  arm
 *   func_0203971C  0x0203971C  arm
 *   func_020395EC  0x020395EC  arm
 *   func_0203D798  0x0203D798  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02030734  0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   file_020A7ACC  0x020A7ACC  data
 *   g_021469D8     0x021469D8  data
 *   g_020A7AE8     0x020A7AE8  data
 *   g_020A7AF8     0x020A7AF8  data
 *   func_0203A574  0x0203A574  arm
 */
#include "../../matched/include/Obj15954.h"
#include "../../matched/include/Obj06942.h"

struct Entry;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

typedef signed int     s32;

struct Slot {
    void *buf;
    u32   len;
};

extern void func_02034714(const char *file, u32 line, const char *msg);
extern struct Entry *func_0203996C(s32 idx);
extern void func_02039658(struct Entry *e, u32 idx);
extern void func_0203971C(unsigned char *a, u32 b);
extern int func_020395EC(struct Entry *a);
extern void *func_0203D798(void);
extern u32 func_020307B0(void *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
extern void  func_0203A574(u32 a0, u32 a1, u32 a2, u32 a3);
void func_0203A27C(u32 a0, u32 a1, u8 *msg, u32 a3, u32 a4);
u16 func_0203A28C(u16 mask, u32 idx, u32 set);
u32 func_0203A2F0(u32 a0, u32 a1);
void func_0203A338(u32 a0);
void func_0203A388(int id, u32 len, const void *src, u32 a3, void *obj);
void func_0203A424(char *p, int a, int b, int c);
void func_0203A458(u8 *a0, u32 a1);
void func_0203A494(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
extern const char file_020A7A68[];
extern const char file_020A7AB0[];
extern const char file_020A7ACC[];
extern u8   *g_021469D8;
extern u8    g_020A7AE8[];
extern char  g_020A7AF8[];



/*
 * A message-table handler that forwards to func_0203A338 with the message's
 * first byte as its only argument.  The five-argument table shape puts the
 * message pointer in r2, so the whole body is `ldrb r0,[r2]` followed by the
 * tail call, which one section per function forces to be a pool word and a
 * `bx ip` rather than a displacement branch
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The remaining
 * parameters are leftovers and are not passed
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A27C.c \
 *       --func func_0203A27C --addr 0x0203A27C --cc 1.1p1 --arm
 */
void func_0203A27C(u32 a0, u32 a1, u8 *msg, u32 a3, u32 a4)
{
    func_0203A338(*msg);
}



/*
 * Set or clear one bit of the 16-bit slot mask, reporting at line 0x391 (913)
 * when the bit index is the 0xFF sentinel.  This is the write half of
 * func_0203A2F0's read (line 0x3AB), sharing its file/message pair.
 *
 * The mask is a u16 throughout, which is what the `lsl #0x10` / `lsr #16`
 * pairs around every store of it are: `1 << idx` is built in a word, narrowed
 * to 16 bits for the OR, and the complement for the clear arm is narrowed
 * THREE times: `~` widens back to int, the AND is done in int, and the result
 * is narrowed once more on the way to the variable.  Writing the clear arm as
 * the compound `mask &= (u16)~(u16)(1 << idx)` is 8 bytes short (one
 * `lsl`/`lsr` pair missing); the narrowing has to be spelled on the whole
 * assignment, `mask = (u16)((u16)mask & (u16)~(u16)(1 << idx))`.  The
 * set arm is the `orrne` and the clear arm the `mvneq` chain, so the source
 * polarity is `set != 0` first (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A28C.c \
 *       --func func_0203A28C --addr 0x0203A28C --cc 1.1p1 --arm
 */
u16 func_0203A28C(u16 mask, u32 idx, u32 set)
{
    if (idx == 0xFF)
        func_02034714(file_020A7A68, 0x391, file_020A7AB0);

    if (set != 0)
        mask |= (u16)(1 << idx);
    else
        mask = (u16)((u16)mask & (u16)~(u16)(1 << idx));

    return mask;
}



/*
 * Tests one bit of a channel mask, the 0xFF argument being a non-fatal
 * report at line 0x3AB (939).  The mask is truncated to a byte before the
 * `tst`, which is the `(u8)` cast in the shift expression, and the result is
 * materialised as 1/0 in r0 rather than left as the `tst` flags.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A2F0.c \
 *       --func func_0203A2F0 --addr 0x0203A2F0 --cc 1.1p1 --arm
 */
u32 func_0203A2F0(u32 a0, u32 a1)
{
    if (a1 == 0xFF)
        func_02034714(file_020A7A68, 0x3AB, file_020A7AB0);
    return (a0 & (u8)(1 << a1)) != 0;
}



/*
 * Promoted from src/pending/ on lane 1: every concrete byte is right (80 of
 * 80).  The one open site was the `bl` to 0x0203971C, whose only branch site
 * image-wide is this one, so `label` had no outside witness.  With
 * src/matched/func_0203971C.c filed EXACT the site resolves through the
 * `matched` class and the file prints EXACT with no change to its C.
 *
 * Pushes a slot's identity into both halves of the table, reporting at line
 * 0x3BE (958) when the identity is the 0xFF sentinel.  Each half is
 * `record(func_0203996C(selector), id)` with the selector's result already in
 * r0, so the second call's first argument is the first call's return value
 * and no local is needed to hold it.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A338.c \
 *       --func func_0203A338 --addr 0x0203A338 --cc 1.1p1 --arm
 */
void func_0203A338(u32 a0)
{
    if (a0 == 0xFF)
        func_02034714(file_020A7A68, 0x3BE, file_020A7AB0);
    func_02039658(func_0203996C(a0), a0);
    func_0203971C((unsigned char *)func_0203996C(0xFF), a0);
}



/*
 * Install a payload into slot `id`: bail out when the receiver is the own
 * link (func_020395EC returning 0xFF), report at line 0x3D1 (977) when the
 * slot index is out of range, free whatever the slot already holds, allocate
 * `len` bytes out of the heap named by the record's +0x56 halfword (line
 * 0x3D8), publish the buffer and its length together, and copy the payload
 * in.
 *
 * THIS FUNCTION TAKES FIVE PARAMETERS, NOT FOUR.  That is the whole of what
 * docs/notes/pkt_0203A388.c.txt diagnosed as a register-colouring residue.
 * The prologue is `push {r3, r4, r5, r6, r7, lr}`, six registers and so 0x18
 * bytes of frame, which makes the `ldr r0, [sp, #0x18]` at +0x18 a read
 * ABOVE the frame -- the caller's fifth argument -- and not the r3 home slot
 * the note read it as.  r3 is a dead fourth argument, the table-handler shape
 * this family uses throughout (func_0203A150, func_02039B5C, func_0203A27C).
 * Written with four parameters the compiler has to keep the receiver in a
 * register across func_0203D798, which costs r8, an extra callee-saved and a
 * spill slot: 172 bytes against 156.  With the fifth parameter the body is
 * size-exact and two bytes out, both of them trivial:
 *
 *   - the slot bound is SIGNED (`int id`, `id >= 9`).  The image's `blt`
 *     becomes `blo` the moment the index is unsigned.
 *   - the allocator's name argument is the file string 0x020A7A68, the same
 *     word the assert's first argument uses, NOT the message 0x020A7ACC.
 *     Both are pool words at nearly the same displacement, so the wrong one
 *     costs exactly one byte of `ldr` offset.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A388.c \
 *       --func func_0203A388 --addr 0x0203A388 --cc 1.1p1 --arm
 */
void func_0203A388(int id, u32 len, const void *src, u32 a3, void *obj)
{
    u8 *g;
    struct Slot *s;

    g = func_0203D798();
    if (func_020395EC(obj) == 0xff)
        return;
    if (id >= 9)
        func_02034714(file_020A7A68, 0x3D1, file_020A7ACC);
    s = (struct Slot *)func_0203996C(id);
    if (s->buf != 0)
        func_020307B0(s->buf);
    s->buf = func_02030734(((struct Obj15954 *)g)->f56, len, 1, file_020A7A68, 0x3D8);
    s->len = len;
    MI_CpuCopy8(src, s->buf, len);
}


void func_0203A424(char *p, int a, int b, int c)
{
    if (p == 0)
        return;
    ((struct Obj06942 *)p)->f46 = (unsigned short)(a + (b << 8));
    p[0x48] = (char)c;
    if (func_020395EC((struct Entry *)p) == 0xff)
        p[0x49] = 0;
    else
        p[0x49] = 1;
}



/*
 * Broadcasts a byte value to the +0xE and +0xF bytes of all nine channel
 * records at ((u32 *)arg0)[i + 2], skipping the ones whose +0xD flag is
 * clear.  The argument truncation is written at both stores and the compiler
 * hoists the single `and r1, r1, #0xff` out of the loop into the argument
 * register itself, after the loop counter has been initialised.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A458.c \
 *       --func func_0203A458 --addr 0x0203A458 --cc 1.1p1 --arm
 */
void func_0203A458(u8 *a0, u32 a1)
{
    int i;

    if (a0 == 0)
        return;
    for (i = 0; i < 9; i++) {
        u8 *q = *(u8 **)(a0 + (i << 2) + 8);

        if (q != 0 && q[0xD] != 0) {
            q[0xE] = (u8)a1;
            q[0xF] = (u8)a1;
        }
    }
}



/*
 * Lazy-init wrapper: the 0x22c-byte context at g_021469D8 is allocated on
 * first use with the debug allocator (heap 0, size 0x22c, flags 1, line
 * 0x96), the delegate func_0203A574 is called, arg3 is published at +8 of
 * the state object in g_020A7AE8, and the 8-byte run at +0x220 plus the byte
 * at +0x228 are cleared.
 *
 * The clearing loop reloads g_021469D8 from memory on every iteration
 * (`ldr r1, [r0]` sits inside the back edge), which is what a global
 * POINTER read in a loop body compiles to when nothing in the loop proves it
 * cannot change -- writing `u8 *p = g_021469D8;` first would hoist the load
 * and change three instructions.  The loop counter is initialised before the
 * `str r5, [r0, #8]` store (`mov r3, #0` at +0x60), and the byte index is
 * added to the reloaded pointer rather than to a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A494.c \
 *       --func func_0203A494 --addr 0x0203A494 --cc 1.1p1 --arm
 */
void func_0203A494(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    int i;

    if (g_021469D8 == 0) {
        g_021469D8 = (u8 *)func_02030734(0, 0x22c, 1, g_020A7AF8, 0x96);
    }
    func_0203A574(a0, a1, a2, a3);
    *(u32 *)(g_020A7AE8 + 8) = a3;
    for (i = 0; i < 8; i++) {
        g_021469D8[0x220 + i] = 0;
    }
    g_021469D8[0x228] = 0;
}
