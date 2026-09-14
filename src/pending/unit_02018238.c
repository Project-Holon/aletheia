/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * address:  0x02018238..0x020182A0, 104 bytes, two functions
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right
 *
 * "Put this move in the first empty slot": it walks ids 0x36..0x39 and returns
 * 0xFFFF when no slot was touched, the move when one was filled, and 0xFFFE
 * when the move was already known.  func_02018238 in front of it is an eight
 * byte docs/idioms/tail-call-is-a-pool-word-and-bx.md thunk.  Its sibling at
 * 0x02018094 is the same function over func_020181FC instead of func_020182A8.
 *
 * Why it is capped: func_020182A8 is reached from exactly two places, the call
 * at 0x02018270 inside func_02018240 and the pool word of the eight byte thunk
 * at 0x020182A0.  A pool word is not a branch, so the `label` class sees only
 * the in-range call and there is no outside witness; and pulling func_020182A8
 * into the range needs func_020182A8 itself to reproduce, which it does not
 * yet: the best source shape found is 128 bytes, the right size, with ten
 * bytes of the prologue wrong.  In the original `slot + 0x36` reloads the
 * parameter out of its spill slot (`str r2, [sp]` is the first instruction
 * after the frame is opened, then `ldr r1, [sp]`), while every spelling tried
 * here uses the incoming r2 for the first of the three index computations and
 * spills it one instruction later; the remaining 118 bytes of the function are
 * identical.  That is the whole of the gap, and it is codegen rather than
 * evidence.
 *
 * The loop counter is signed (`blt`), unlike the otherwise identical loop in
 * func_020181A0, which is `blo`.
 *
 * Verified with
 *   python tools/match.py tu --src src/pending/unit_02018238.c  *       --addr 0x02018238 --thumb
 *
 * The `matched` class does not reach it: func_020182A8 is not matched, which is
 * the same fact from the other side, since what it would take to match it is the
 * ten bytes of prologue described above.
 *
 * symbols:
 *   func_020182A8  0x020182A8  thumb
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_02017DBC(void *p);
extern u32  func_02017DE4(void *p, u32 f);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void func_02017E64(void *p, u32 id, u32 v);
extern u32  func_0201C158(u16 move, u8 ppUp);

u32  func_02018240(void *p, u16 move);
extern void func_020182A8(void *p, u16 move, u32 slot);

u32 func_02018238(void *p, u16 move)
{
    return func_02018240(p, move);
}

u32 func_02018240(void *p, u16 move)
{
    u32 r = 0xFFFF;
    u32 t = func_02017DBC(p);
    int i;

    for (i = 0; i < 4; i++) {
        u32 m = (u16)func_02017E88(p, 0x36 + i, 0);

        if (m == 0) {
            func_020182A8(p, move, (u8)i);
            r = move;
            break;
        }
        if (m == move) {
            r = 0xFFFE;
            break;
        }
    }
    func_02017DE4(p, t);
    return r;
}

