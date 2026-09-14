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
 * evidence.  It still is after wave 7; see below for what that wave closed and
 * what it ruled out.
 *
 * Wave 6 attempt, for the record, so that nobody re-derives it.  The ten bytes
 * are the three `str value; adds #k; str value + k` pairs at [sp], [sp+8] and
 * [sp+0xC]: the original stores each id twice, once with the bare slot number
 * and once with the offset added, and reloads it from the stack at every use.
 * Three models were compiled against it.  A local `u32 v[4]` and a local
 * four-word struct are both folded completely (every intermediate store dead,
 * 122 bytes, the frame down to 8).  Declaring the four slots `volatile`
 * reproduces the double stores exactly, so the stores really are the shape of
 * a store that may not be eliminated, but it also forces a reload *between*
 * the store and the `adds`, which the original does not have, and the function
 * comes out 136 bytes.
 *
 * Wave 7 settled the double stores and did not settle the reload.  The stores
 * are not an aggregate and not `volatile`: they are what two ordinary
 * statements over one spilled scalar produce when the second one recomputes
 * from the *source* value rather than from the variable,
 *
 *     d = slot;
 *     d = slot + 0x36;        <- both stores survive, no reload between them
 *
 * against `d = slot; d = d + 0x36;` and against `d = slot + 0x36;`, which both
 * fold to one store and 122 bytes.  mwccarm does not dead-store-eliminate a
 * write to a local that has a stack home, and with the addend applied to
 * `slot` rather than to `d` there is no read of `d` to force a reload.  That
 * takes the function from 111 concrete bytes wrong to ten, at the right size,
 * with the whole body from 0x02018310 down byte for byte right, and it needs
 * no aggregate and no escape at all.  The source that does it is
 *
 *     void func_020182A8(void *p, u16 move, u32 slot)
 *     {
 *         u32 b; u32 d; u32 c; u32 v = 0; u32 pp;
 *
 *         d = slot;  d = slot + 0x36;
 *         if (func_02017E88(p, d, 0) != 0) { b = 1; } else { b = 0; }
 *         c = slot;  c = slot + 0x3A;
 *         pp = (u8)func_02017E88(p, c, 0);
 *         func_02017E64(p, d, move);
 *         slot = slot + 0x3E;
 *         func_02017E64(p, slot, 0);
 *         if (move != 0) {
 *             v = func_0201C158(move, 0);
 *             if (b != 0) {
 *                 if (v <= pp) { pp = v; }
 *                 v = (u8)pp;
 *             }
 *         }
 *         func_02017E64(p, c, v);
 *     }
 *
 * and the declaration order of the four locals is load bearing twice over: b,
 * d, c puts the flag at sp+4, the move id at sp+0xC and the pp id at sp+8, and
 * `v` before `pp` is what puts the running pp value in r5 and the new one in
 * r4 (the other order is nine more bytes wrong with identical control flow).
 * The generalisable half of this is
 * docs/idioms/a-dead-store-to-a-spilled-local-survives-when-the-second-assignment-recomputes.md.
 *
 * What is left is one instruction and it is the same one wave 6 named: the
 * original's first use of the slot number is `str r2, [sp]` / `adds r7, r1, #0`
 * / `ldr r1, [sp]`, a spill of the parameter followed immediately by a reload,
 * where every source shape tried here emits `adds r1, r2, #0` and copies the
 * register it already has.  Same instruction count, same size, six halfwords
 * permuted.  Wave 7 ruled out, each measured rather than reasoned about:
 *
 *   - the slot number as a member of a local aggregate, one-word struct,
 *     two-word struct, `u32[1]`, `u32[2]`: all folded, still a copy;
 *   - the aggregate reached through a pointer local (`u32 *q = ids;`), which
 *     is the "address escapes invisibly" theory: two bytes longer and the copy
 *     is still there;
 *   - `volatile` on each of the four slots independently, all sixteen
 *     combinations: every one forces reloads the original does not have and
 *     none is closer than 100 bytes;
 *   - `volatile` on the parameter itself: 125 bytes wrong;
 *   - the slot number as a by-value `struct` or `union` parameter, which is
 *     the one construct that really does give a parameter a stack home: 132
 *     bytes and 70 wrong, because the home is then read for every use;
 *   - assigning to the parameter (`slot = slot + 0x3E;`) against computing the
 *     third id inline: byte-identical, so the image does not say which.
 *
 * So the reload is not an escape, not a qualifier and not an aggregate; on
 * present evidence it is an allocator decision this front end makes for a
 * reason no source shape in the space above reaches. The next thing to try is
 * not another spelling of this function: it is to find a second function in
 * the image with the same `str rN, [sp]` / `ldr rN, [sp]` pair over a
 * parameter and match that one, where the surrounding code may be simple
 * enough to isolate the trigger.
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

