/*
 * function: func_02026608
 * address:  0x02026608
 * packet:   pkt_02026504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent runs 164 bytes because the follower at
 * 0x0202667E is an unlabelled leaf (`movs r0, r0` / `bx lr`) that saves
 * nothing, so `disasm.py` never labels it.  Byte coverage ends at +0x76.
 *
 * symbols:
 *   func_02082BCC 0x02082BCC  arm
 *
 * Counted eight-entry bank: pop the next live 12-byte record at
 * base + base[0x48] * 12, publish it as the caller's 0x10-byte snapshot,
 * clear its live flag and advance the cursor with a wrap at six.
 *
 * The publish order is not the source order: the whole-word load of +0x04
 * lands before the `out[8] = 0` store, so the C has to store the word first
 * and the byte second to let the scheduler hoist the load into the store's
 * shadow.  Written with `out[8] = 0` first, the compiled order flips and
 * nine bytes differ.
 */
#include "../include/Obj04054.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02082BCC(void *dst, int val, int size);

typedef struct {
    u16 h0;      /* +0x00 */
    u8  unk2;    /* +0x02 */
    u8  live : 1;   /* +0x03 bit 0 */
    u8  f1 : 1;     /* +0x03 bit 1 */
    u8  f2 : 1;     /* +0x03 bit 2 */
    u32 w4;      /* +0x04 */
    u32 w8;      /* +0x08 */
} Rec;

int func_02026608(u8 *p, u8 *out)
{
    u8 *base = p + 0x3c;
    Rec *r = (Rec *)(base + base[0x48] * 12);

    if (r->live == 0) {
        return 0;
    }
    func_02082BCC(out, 0, 0x10);
    ((struct Obj04054 *)out)->f0 = r->w4;
    out[8] = 0;
    out[0xa] = r->f1;
    ((struct Obj04054 *)out)->f4 = r->w8;
    out[9] = 1;
    out[0xb] = r->f2;
    ((struct Obj04054 *)out)->fC = r->h0;
    r->live = 0;
    base[0x48] = base[0x48] + 1;
    if (base[0x48] >= 6) {
        base[0x48] = 0;
    }
    return 1;
}
