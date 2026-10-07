/*
 * function: func_02046300
 * address:  0x02046300
 * packet:   pkt_020461F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Expand one 8-byte record of the loaded module table into eight words and
 * store the record's flag byte next to them.
 *
 * g_02146A58 is the module record src/pending/func_020461F4.c allocates:
 * its `data` field points at a header whose first two words are byte
 * offsets, the first to the record array, the second to the flag bytes.
 * `idx` selects one 8-byte record of that array; its eight bytes are each
 * run through func_0204638C and the results are merged with the two masks
 * at +04/+08 of the record before being written out as eight words.
 *
 * Shape notes (each cost real bytes):
 *  - The head offsets are spelled `idx * 32 / 4`.  That literal
 *    multiply-then-divide is what makes mwcc emit the four-instruction
 *    `lsl #5 / asr #1 / add lsr #30 / add asr #2` signed-scale sequence
 *    the original shows; the algebraically identical `idx * 8` compiles to
 *    a single `lsl #3` and reallocates the whole function.
 *  - `~v` has to be spelled `v ^ 0xFFFFFFFF`: with the `~` operator the
 *    compiler rematerialises `mvn r1, r0` inside the loop, but the mask
 *    form is strength-reduced to one `mvn r4, #0` hoisted above it plus an
 *    `eor`, which is what the original does.
 *  - The flag store groups its sum as `t = hdr + hdr[1]; t[idx]`.  Writing
 *    the same sum as one subscript expression associates the other way and
 *    emits `add r0, r0, sl` / `ldrb r0, [r1, r0]` instead of
 *    `add r0, r1, r0` / `ldrb r0, [sl, r0]` -- two bytes of diff, but no
 *    other spacing reproduces the register pair.
 *  - The record pointer is re-derived from the global at the tail (six
 *    instructions) rather than kept in a register: the loop calls out, so
 *    the cached `data` cannot legally survive, and binding it to a local
 *    loses the second pool load.
 *
 * symbols:
 *   g_02146A58         0x02146A58  data
 *   func_0204638C      0x0204638C  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046300.c \
 *       --func func_02046300 --addr 0x02046300 --cc 1.1p1 --arm
 */

#include "../include/G_Rec02046300.h"

typedef unsigned char u8;
typedef unsigned int u32;

extern struct Rec02046300 *g_02146A58;
extern u32 func_0204638C(u32 b);

void func_02046300(int idx, u8 *out)
{
    u8 *p = (u8 *)g_02146A58->data + ((u32 *)g_02146A58->data)[0]
            + idx * 32 / 4;
    u32 m0 = g_02146A58->unk04;
    u32 m1 = g_02146A58->unk08;
    u32 *q = (u32 *)out;
    u8 *t;
    int i;

    for (i = 0; i < 8; i++) {
        u32 v = func_0204638C(*p++);
        u32 nv = v ^ 0xFFFFFFFF;
        *q++ = (m0 & v) | (m1 & nv);
    }

    t = (u8 *)g_02146A58->data + ((u32 *)g_02146A58->data)[1];
    out[0x20] = t[idx];
}
