/*
 * file:     bsubway_savedata_p02.c
 * unit:     yes
 * function: func_0200E18C, func_0200E1A8, func_0200E27C, func_0200E2BC, func_0200E368, func_0200E370, func_0200E394, func_0200E3A0, func_0200E3A4, func_0200E3E8
 * address:  0x0200E18C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0209DE90     0x0209DE90  data
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E0E8  0x0200E0E8  thumb
 *   func_0200E124  0x0200E124  thumb
 *   func_0200E024  0x0200E024  thumb
 *   g_0200E278_Off 0x00000848  data
 *   _s32_div_f  0x0209C0A4  arm
 *   func_02030734     0x02030734  arm
 *   func_020307B0     0x020307B0  arm
 *   func_02007248     0x02007248  thumb
 *   memcmp            0x0203EFC8  arm
 *   sFile_020A720C    0x020A720C  data
 *   func_02167380  0x02167380  thumb  ov010
 *   func_02167358  0x02167358  thumb  ov010
 */
struct Slot;
struct Sub020071CCCtrl;
typedef unsigned char u8;

typedef unsigned int  u32;

typedef unsigned short u16;

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

typedef signed int     s32;

typedef struct {
    u32 lo  : 11;
    u32 mid : 12;
    u32 hi  : 6;
    u32 top : 3;
} Key;

extern void func_0200E06C(char *p);
extern void func_0200E124(u32 *p, u32 a);
extern void func_0200E024(void *obj);
extern u32 func_0200E0E8(const struct Slot *obj, int idx);
extern int _s32_div_f(int a, int b);
extern void *func_02030734(u32 heap, u32 size, int flag, const char *file, u16 line);
extern u32 func_020307B0(void *p);
extern u32   func_02007248(void *a, u32 b, u32 c, void *d, u32 e);
extern int   memcmp(const void *a, const void *b, u32 n);
extern void func_02082BCC(void *p, u32 v, u32 size);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u8 func_02167380(u32 id);
extern u8 func_02167358(u32 id);
void func_0200E18C(u32 *p, u32 a);
void func_0200E1A8(void *p, u16 a1, u16 a2, u8 a3, u8 a4, u8 a5, u32 kind);
void func_0200E27C(u8 *obj, int idx);
u32 func_0200E2BC(void *a0, u32 *a1, void *heap, u32 mode);
int func_0200E368(void);
void func_0200E370(u8 *p);
void *func_0200E394(void *a0);
void *func_0200E3A0(void *a);
u32 sub_0200E3A4(const u8 *bits, int id);
void sub_0200E3E8(u8 *bits, int id, u32 value);
extern const struct Rec g_0209DE90[];
extern char  sFile_020A720C[];



/*
 * Runs func_0200E06C, then func_0200E124, then the initialiser.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E18C.c \
 *       --func func_0200E18C --addr 0x0200E18C --thumb --cc 1.1p1
 */
void func_0200E18C(u32 *p, u32 a)
{
    func_0200E06C((char *)p);
    func_0200E124((u32 *)p, a);
    func_0200E024(p);
}




/*
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




/*
 * Slot-index arithmetic for the 0x84A/u8 table at +0x849: the byte written is
 * `(idx - 0x32) / 0x3c - 1` clamped to 6, and the three guards answer for
 * 0xffff, below 0xaa and above 0x212.  The divide is SIGNED (`_s32_div_f` at
 * 0x0209C0A4) while the two range tests are UNSIGNED, so the index parameter is
 * an `int` and the guards cast it to u32; spelling the parameter u32 instead
 * moves the divide to `_u32_div_f` and loses the site.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E27C.c \
 *       --func func_0200E27C --addr 0x0200E27C --cc 1.1p1 --thumb
 */
void func_0200E27C(u8 *obj, int idx)
{
    u8 v = (idx - 0x32) / 0x3c - 1;

    if (idx == 0xffff) {
        return;
    }
    if ((u32)idx < 0xaa) {
        return;
    }
    if ((u32)idx > 0x212) {
        return;
    }
    if (v > 6) {
        v = 6;
    }
    obj[0x849] = v;
}




u32 func_0200E2BC(void *a0, u32 *a1, void *heap, u32 mode)
{
    u32 *buf;
    Key *key = (Key *)a1;
    u32 found = 0;
    s32 i;
    s32 j;

    buf = func_02030734((u32)heap, 0x850, 1, sFile_020A720C, 0x1ac);
    for (i = 0; i < 2; i++) {
        if (func_02007248(a0, 0x3d, i, buf, 0x850) == 1) {
            func_0200E06C((char *)buf);
            for (j = 0; j < 530; j++) {
                if (mode == 1) {
                    if (key->lo != ((Key *)buf)[j].lo) continue;
                    if (key->hi != ((Key *)buf)[j].hi) continue;
                    found = 1;
                    break;
                } else {
                    if (memcmp(&buf[j], a1, 4) != 0) continue;
                    found = 1;
                    break;
                }
            }
        }
        if (found == 1) break;
    }
    func_020307B0(buf);
    return found;
}


int func_0200E368(void)
{
    return 0xa1 * 4;
}



/*
 * Zeroes 0x284 bytes and sets the three trailing descriptor bytes.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E370.c \
 *       --func func_0200E370 --addr 0x0200E370 --thumb --cc 1.1p1
 */
void func_0200E370(u8 *p)
{
    func_02082BCC(p, 0, 0x284);
    p[0x280] = 0;
    p[0x281] = 8;
    p[0x282] = 0x1d;
}


void *func_0200E394(void *a0)
{
    return func_020071CC(a0, 0x3f);
}



/*
 * Returns the argument plus 0xd2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0200E3A0.c \
 *       --func func_0200E3A0 --addr 0x0200E3A0 --thumb --cc 1.1p1
 */
void *func_0200E3A0(void *a)
{
    return (u8 *)a + 0xd2;
}



/*
 * note:     wave 16: promoted.  0x02167380 and 0x02167358 are unlabelled ov010
 *           leaves matched in src/matched/func_02167380.c and func_02167358.c
 *           (ov010/pkt_02167358); both attest as `matched, overlay`.
 */
u32 sub_0200E3A4(const u8 *bits, int id)
{
    u32 bit  = func_02167380(id);
    u32 n    = func_02167358(id);
    u32 byte = bit >> 3;
    u32 b    = bit & 7;
    u32 out  = 0;
    u32 i    = 0;

    while (n != 0) {
        out |= (u32)((bits[byte] >> b) & 1) << i;
        if (++b > 7) {
            byte++;
            b = 0;
        }
        i++;
        n--;
    }
    return out;
}



/*
 * note:     wave 16: promoted.  0x02167380 and 0x02167358 are unlabelled ov010
 *           leaves matched in src/matched/func_02167380.c and func_02167358.c
 *           (ov010/pkt_02167358); both attest as `matched, overlay`.
 *
 * near miss resolved (wave 4, permuter): the note's 88-byte version was a
 * six-register permutation away. Two spellings closed it, neither of which
 * the permuter's mutation set can reach (both change the emitted
 * instruction kinds, not the allocation):
 *   - the clear mask is (u8)(0xFFu ^ (1u << b)), which emits
 *     `movs r6,#0xff; eors r6,r7`; the ~ spelling emits a single `mvns`
 *     and is the whole 2-byte size gap.
 *   - inside the wrap test, `byte++` must precede `b = 0`; the reverse
 *     order emits `movs #0` before the `adds` and shifts the allocation.
 */
void sub_0200E3E8(u8 *bits, int id, u32 value)
{
    u32 bit = func_02167380(id);
    u32 n   = func_02167358(id);
    u32 byte = bit >> 3;
    u32 b    = bit & 7;

    while (n != 0) {
        bits[byte] &= (u8)(0xFFu ^ (1u << b));
        bits[byte] |= (u8)((value & 1) << b);
        b++;
        if (b > 7) {
            byte++;
            b = 0;
        }
        value >>= 1;
        n--;
    }
}
