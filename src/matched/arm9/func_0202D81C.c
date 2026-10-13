/*
 * function: func_0202D81C
 * address:  0x0202D81C
 * packet:   pkt_0202D7D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Issues a request through func_0204A6C8 built from a by-value tail struct
 * in the caller's frame (five words plus a u16 key at +0x14) and the
 * context func_0202D060()/func_0202D064() pair; when a1 is the sentinel
 * 0x147 it additionally runs the same tail through POKEGRA_LoadCharData with the
 * address of a local out-slot, hands that slot's word to func_0204A9D0
 * alongside the request handle, and releases POKEGRA_LoadCharData's result through
 * func_020307B0. The request handle is returned either way.
 *
 * Three things the C has to say exactly, all found this session (the
 * earlier DIFF is docs/notes/func_0202D81C.c.txt):
 *   - the tail parameter must be `volatile`. Without it the front end
 *     re-homes the register arguments into the frame, grows `sub sp` from
 *     0x18 to 0x28 and 89 bytes differ.
 *   - the key sits at +0x14 of the tail, not +0x10: the struct carries five
 *     u32 words (s0..s4) ahead of it, and s4 is func_0204A6C8's own stack
 *     argument read from [sp,#0x40].
 *   - `k` and `v` must be separate named locals read in that order just
 *     before the func_0204A6C8 call. Passing `t.key`/`t.s4` inline (in
 *     either order, with or without a cast away from volatile, and with the
 *     stack arg typed u16) schedules `ldr r3,[sp,#0x40]` after the
 *     `movs r2,#1`/`str r0,[sp]` pair instead of before it: the last 6 bytes
 *     of the DIFF, and the only thing that moves them.
 *
 * The out-slot at sp+0x14 is real: POKEGRA_LoadCharData reads `*a0` three times and
 * never stores through it, so the `ldr r1,[sp,#0x14]` after the call reads
 * back an uninitialised local. That is what the original does; the note's
 * open question about a hidden write inside POKEGRA_LoadCharData is resolved as
 * "there is none, and the C does not need one".
 * symbols:
 *   func_0202D060   0x0202D060  thumb
 *   func_0202D064   0x0202D064  thumb
 *   POKEGRA_LoadCharData   0x0202D760  thumb
 *   func_0204A6C8   0x0204A6C8  arm
 *   func_0204A9D0   0x0204A9D0  arm
 *   func_020307B0   0x020307B0  arm
 */
typedef unsigned short u16;
typedef unsigned int   u32;

struct Tail { u32 s0; u32 s1; u32 s2; u32 s3; u32 s4; u16 key; u16 pad; };

typedef signed int     s32;
extern int func_0202D060(void);
extern s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
struct Sub0204A9D0;
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern void *POKEGRA_LoadCharData(u32 *out, u32 a1, u32 a2, u32 a3, u32 s0, u32 s1, u32 s2, u32 s3, volatile u16 s4);
extern void func_0204A9D0(int a, struct Sub0204A9D0 *b);
extern u32 func_020307B0(void *p);

u32 func_0202D81C(u32 a0, u32 a1, u32 a2, u32 a3, volatile struct Tail t)
{
    u32 r;
    u32 h;
    u32 x;
    u32 k;
    u32 v;
    void *slot;

    x = func_0202D064(func_0202D060(), a1, a2, a3, t.s0, t.s1, t.s2);
    k = t.key;
    v = t.s4;
    h = func_0204A6C8((void *)a0, x, 1, v, k);
    if (a1 == 0x147) {
        r = (u32)POKEGRA_LoadCharData((u32 *)(&slot), a1, a2, a3, t.s0, t.s1, t.s2, t.s3, t.key);
        func_0204A9D0(h, (struct Sub0204A9D0 *)((u32)slot));
        func_020307B0((void *)r);
    }
    return h;
}
