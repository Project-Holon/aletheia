/*
 * file:     net_state_p04.c
 * unit:     yes
 * function: func_020363B8, func_020363D4, func_020363F0, func_0203640C, func_02036428, func_020364D4, func_02036500, func_02036540
 * address:  0x020363B8
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
 *   func_02036640  0x02036640  arm
 *   func_02039548  0x02039548  arm
 *   func_02034714  0x02034714  arm
 *   func_02036624  0x02036624  arm
 *   file_020A79A4  0x020A79A4  data
 *   str_020A79B4   0x020A79B4  data
 *   func_02036568  0x02036568  arm
 *   file_020A79C0    0x020A79C0  data
 */
#include "../../matched/include/Obj11344.h"
#include "../../matched/include/Obj11345.h"
#include "../../matched/include/Obj11346.h"
#include "../../matched/include/Obj01465.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

struct Rec {
    u32 unk0;
    u32 unk4;
    u8  pad8[4];
    u16 unkC;
    u16 unkE;
};

typedef struct {
    u8   *buf;
    int   size;
    u32   pad8;
    short head;
    volatile short tail;
} NetRingBuff;

extern int func_02036640(char *p);
extern void func_02039548(void);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern int func_02036624(void *p, int v);
void func_02036428(NetRingBuff *r, const u8 *src, int len);
extern int func_02036568(void *p, unsigned char *dst, int len, int max);
int func_020363B8(int a0, int a1, int a2);
int func_020363D4(int a0, int a1, int a2);
int func_020363F0(int a0, int a1, int a2);
int func_020364D4(char *p, unsigned char *dst, int len, int max);
u32 func_02036500(u32 a);
u32 func_02036540(u32 a);
extern const char file_020A79A4[];
extern const char str_020A79B4[];
extern const char file_020A79C0[];



int func_020363B8(int a0, int a1, int a2){ int t0; t0 = func_0203521C((int)a0); ((struct Obj11344 *)((char *)(t0)))->f28 = (int)a2; ((struct Obj11344 *)((char *)(t0)))->f1C = (int)a1; return t0; }



int func_020363D4(int a0, int a1, int a2){ int t0; t0 = func_0203521C((int)a0); ((struct Obj11345 *)((char *)(t0)))->f24 = (int)a2; ((struct Obj11345 *)((char *)(t0)))->f18 = (int)a1; return t0; }



int func_020363F0(int a0, int a1, int a2){ int t0; t0 = func_0203521C((int)a0); ((struct Obj11346 *)((char *)(t0)))->f2C = (int)a2; ((struct Obj11346 *)((char *)(t0)))->f20 = (int)a1; return t0; }



/*
 * Initialises a small record: the two leading words get the first two
 * arguments, and the two halfwords at +0x0C and +0x0E are cleared.  The
 * second argument is declared `s16` and that is visible in the code: the
 * compiler sign-extends it with an `lsl #16` / `asr #16` pair before the
 * two-word `stmia`, which is the only way a narrowed parameter reaches a
 * 32-bit store.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203640C.c \
 *       --func func_0203640C --addr 0x0203640C --cc 1.1p1 --arm
 */
void func_0203640C(struct Rec *p, u32 a, int b)
{
    p->unk0 = a;
    p->unk4 = (short)b;
    p->unkC = 0;
    p->unkE = 0;
}


/*
 * net_ring_buff.c's write: refuse (func_02039548) unless the free space
 * (func_02036640) exceeds len, then copy len bytes in at the +0xE write
 * cursor modulo the capacity (func_02036624), asserting src != NULL at line
 * 0x44 each byte, and store the wrapped cursor back.  The write cursor is
 * declared volatile: the loop bound re-reads it every pass and the first
 * read happens twice, exactly as the image does (the same re-read shape the
 * matched func_020365E8 spells with volatile casts).
 */
void func_02036428(NetRingBuff *r, const u8 *src, int len)
{
    int i;
    int k;

    if (func_02036640((char *)r) <= len) {
        func_02039548();
        return;
    }
    k = 0;
    for (i = r->tail; i < r->tail + len; i++) {
        if (src == 0) {
            func_02034714(file_020A79A4, 0x44, str_020A79B4);
        }
        r->buf[func_02036624(r, i)] = src[k];
        k++;
    }
    r->tail = (short)func_02036624(r, i);
}


/*
 * Blocked: the PC24 at +0008 to 0x02036568 has no witness of any class and no
 * manifest entry is possible this pass: 0x02036568 is a 128-byte ARM function
 * whose C is byte-correct except an eight-instruction schedule permutation of
 * its loop tail (seven spellings measured, all identical) - a DIFF, see
 * docs/notes/pkt_02036568.c.txt.  The second site (func_02036624) resolves as
 * `matched`.  Every concrete byte here reproduces.
 */
int func_020364D4(char *p, unsigned char *dst, int len, int max)
{
    int d = func_02036568(p, dst, len, max);
    ((struct Obj01465 *)p)->fC = (short)func_02036624(p, ((struct Obj01465 *)p)->fC + d);
    return d;
}



/*
 * PARKED AT MATCH.  Every concrete byte is right; the one open site is the
 * second pool word, file_020A79C0, whose only literal pool in the whole image
 * is this function's own, at 0x0203653C and therefore inside the compared
 * range.  The `string` class cannot stand in for it either: 0x020A79C0 holds
 * the one-character string "0" (the listing shows `.word 0x00000030` there,
 * preceded by the terminator of "pDataArea"), and attest_string() requires at
 * least four printable characters before the NUL, so the address is refused by
 * rule 2.  It closes the day the same string address is referenced from a pool
 * outside this range, or the rule's four-character floor is revisited for
 * one-character strings.  The three other sites resolve: func_020364D4 and
 * func_02034714 as `label`, file_020A79A4 as `literal`.
 */
u32 func_02036500(u32 a)
{
    u8 b;

    if (func_020364D4((char *)a, &b, 1, 1) == 1)
        return b;
    func_02034714(file_020A79A4, 0x6C, file_020A79C0);
    return 0;
}



/*
 * Packs two bytes read through src/matched/func_02036500.c into one halfword,
 * high byte first.  The same call is made twice with the same argument.
 *
 * The shape that reproduces the original is `hi = (u16)(call << 8);` - the
 * `u16` narrowing folded into the shift, which mwcc encodes as `lsl r4, r0,
 * #24` (`(x << 8) mod 2^16` starts its life as `x << 24`) with the companion
 * half of the pair spent as the *shift operand* of the `orr`, `orr r0, r0, r4,
 * lsr #16`.  Spelling the mask as a value first - `hi = (u8)call;` or
 * `(u8)hi << 8` - makes mwcc emit `and r4, r0, #0xFF` followed by
 * `orr r0, r0, r4, lsl #8` instead: the same two instructions, the same
 * result, different bytes.  This is the unequal-shift-pair tell of
 * docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md
 * one level up: with the mask inline mwcc picks the AND form, so the mask has
 * to be on the narrowed *variable*, not on the shifted expression.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02036540.c \
 *       --func func_02036540 --addr 0x02036540 --cc 1.1p1 --arm
 */
u32 func_02036540(u32 a)
{
    u16 hi;
    u32 lo;

    hi = (u16)(func_02036500(a) << 8);
    lo = func_02036500(a);
    return (u16)(hi | lo);
}
