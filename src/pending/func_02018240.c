/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * function: func_02018240
 * address:  0x02018240
 * packet:   pkt_02018240
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH, every concrete byte right (96 of 96 compiled, 96 of 96 original)
 *
 * blocker:  020182A8 (thumb, label) -- the only branch to it in the image is
 *           this function's own call at +0x30, so the `label` class has no
 *           outside witness.  func_020182A8 is one of this packet's own
 *           `state=new` rows and it is a codegen near miss, not an evidence
 *           wall: its best source is 128 bytes, the right size, with ten bytes
 *           of prologue wrong (the parameter's `str r2, [sp]` / `ldr r1, [sp]`
 *           pair, which this front end emits as `adds r1, r2, #0`).  See
 *           docs/notes/pkt_02018240.c.txt and
 *           docs/idioms/a-dead-store-to-a-spilled-local-survives-when-the-second-assignment-recomputes.md.
 *           The 8-byte Thumb thunk at 0x020182A0 names the same address from
 *           its pool word, but a pool word is not a branch and the harness's
 *           pool index does not carry it (probed: `pool_words[0x020182A9]` is
 *           empty), so `literal` cannot carry the site either.  This file
 *           turns EXACT with no edit the moment 0x020182A8 is reproduced.
 *
 * symbols:
 *   func_02017DBC  0x02017DBC  thumb
 *   func_02017DE4  0x02017DE4  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_020182A8  0x020182A8  thumb
 *
 * "Put this move in the first empty slot": walks ids 0x36..0x39 and returns
 * 0xFFFF when no slot was touched, the move when one was filled, and 0xFFFE
 * when the move was already known.  The loop counter is signed (`blt`), unlike
 * the otherwise identical loop in func_020181A0, which is `blo`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02018240.c \
 *       --func func_02018240 --addr 0x02018240 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_02017DBC(void *p);
extern u32  func_02017DE4(void *p, u32 f);
extern u32  func_02017E88(void *p, u32 id, u32 v);
extern void func_020182A8(void *p, u16 move, u32 slot);

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
