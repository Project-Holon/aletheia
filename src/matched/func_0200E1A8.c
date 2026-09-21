/*
 * function: func_0200E1A8
 * address:  0x0200E1A8
 * packet:   pkt_0200E1A8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0209DE90     0x0209DE90  data
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E0E8  0x0200E0E8  thumb
 *   func_0200E124  0x0200E124  thumb
 *   func_0200E024  0x0200E024  thumb
 *   func_0200E27C  0x0200E27C  thumb
 *   g_0200E278_Off 0x00000848  data
 *
 * The record writer of the same two-field table object func_0200E124 walks:
 * it appends (or overwrites) one 32-bit packed record in the ring at
 * obj[slot] and then runs the checksum refresh at func_0200E024.
 *
 * The record is six unsigned bitfields in one u32, laid out 11 / 10 / 2 /
 * 6 / 3 from bit 0; the pool masks 0xFFFFF800, 0xFFE007FF, 0xFF9FFFFF,
 * 0xE07FFFFF and 0x1FFFFFFF are the complement of each field in turn, which
 * is what a plain unsigned bitfield store compiles to.  The three `str
 * r2, [r0]` in the middle of the sequence are the statement boundaries: the
 * first three fields fold into one store, the fourth and the fifth each get
 * their own.
 *
 * g_0209DE90 is the { u16 a; u16 b; } record table of
 * src/matched/func_0200E124.c; this function reads BOTH fields of the same
 * row (a into the stack slot at sp+0xC, b into r7), so the two pool words
 * 0x0209DE90 and 0x0209DE92 are one symbol at two field offsets, not two
 * symbols.  See docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * The parameter widths are the whole of the codegen here, not a guess: the
 * spill order in the prologue (`str r1, [sp]` and `str r2, [sp, #4]` BEFORE
 * `ldr r4, [sp, #0x30]`, with `str r3, [sp, #8]` after it) only comes out
 * right when a1/a2 are u16 and a3 is u8.  Every wider spelling tried --
 * (u32,u32,u32), (u32,u32,u8), (u16,u16,u32), (int,int,int) -- reproduces
 * all 212 bytes but swaps those two instruction pairs, three or four bytes
 * wrong in the first ten.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E1A8.c \
 *       --func func_0200E1A8 --addr 0x0200E1A8 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec {
    u16 a;
    u16 b;
};

struct Entry {
    u32 f0  : 11;
    u32 f11 : 10;
    u32 f21 : 2;
    u32 f23 : 6;
    u32 f29 : 3;
};

extern struct Rec g_0209DE90[];

extern void func_0200E06C(void *p);
extern u32  func_0200E0E8(void *p, u32 kind);
extern void func_0200E124(void *p, u32 cap);
extern void func_0200E024(void *p);
extern void func_0200E27C(void *p, u16 slot);

void func_0200E1A8(void *p, u16 a1, u16 a2, u8 a3, u8 a4, u8 a5, u32 kind)
{
    struct Entry *e;
    u32 lim, cap, slot;
    u32 k;

    func_0200E06C(p);
    k = kind;
    cap = g_0209DE90[k].a;
    lim = g_0209DE90[k].b;
    slot = func_0200E0E8(p, k);
    if (slot == 0xFFFF) {
        func_0200E124(p, cap);
        e = (struct Entry *)((u32 *)p + (lim - 1));
    } else {
        e = (struct Entry *)((u32 *)p + slot);
    }

    e->f0 = a1;
    e->f11 = a2;
    e->f21 = a3;
    e->f23 = a4;
    e->f29 = a5;

    if (k == 2) {
        if (((u8 *)p)[0x848] < 1)
            ((u8 *)p)[0x848]++;
    } else if (k == 3) {
        func_0200E27C(p, (u16)slot);
    }
    func_0200E024(p);
}
